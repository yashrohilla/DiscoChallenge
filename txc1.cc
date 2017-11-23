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

Define_Module(Txc1);


void Txc1::initialize()
{
    if(strcmp("ping", getName()) == 0) {
        cPacket *data = new cPacket("data");
        data->setByteLength(524288);
        send(data, "out");
    }
}

void Txc1::handleMessage(cMessage *msg)
{
    cPacket *data = new cPacket("data");
    data->setByteLength(524288);
    send(data, "out");
}
