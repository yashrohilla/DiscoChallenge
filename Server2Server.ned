//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

simple Txc1
{
    gates:
        input in;
        output out;
}

network PingPong
{
    submodules:
        ping: Txc1;
        pong: Txc1;
    connections:
        ping.out --> {  delay=1000ms;datarate=1Mbps;  } --> pong.in;
        ping.in <-- {  delay=exponential(1s);datarate=1Mbps;  } <-- pong.out;
}