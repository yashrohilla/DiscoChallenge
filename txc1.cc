/*
 * txc1.cc
 *
 *  Created on: 22 Nov 2017
 *      Author: Media
 */

#include <string.h>
#include <omnetpp.h>
#include <cpacket.h>

using namespace omnetpp;

class Txc1 : public cSimpleModule
{
protected:
  virtual void initialize() override;
  virtual void handleMessage(cMessage *msg) override;
  void setByteLength(int64_t);
};

class Txc2 : public cSimpleModule
{
protected:
  virtual void handleMessage(cMessage *msg) override;
  void setByteLength(int64_t);
};

Define_Module(Txc1);
Define_Module(Txc2);

void Txc1::initialize()
{
    if(strcmp("S1", getName()) == 0)
    {
        cPacket *data = new cPacket("datanew");
        data->setByteLength(524288);
        sendDelayed(data, 1.0, "out");
    }
}

void Txc1::handleMessage(cMessage *msg)
{

        cPacket *data = new cPacket("datafromS1toS2");
        data->setByteLength(524288);
        sendDelayed(data, 1.0, "out");
}

void Txc2::handleMessage(cMessage *msg)
{

        cPacket *data = new cPacket("datafromS2toS1");
        data->setByteLength(524288);
        sendDelayed(data, exponential(1), "out");
}
