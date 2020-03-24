/*------------------------------------------------------------------------------
################################################################################
###                                   Receiver                               ###
################################################################################
------------------------------------------------------------------------------*/
#include "heltec.h"
#include "Node.hpp"
#include "Receiver_Node.hpp"
#define BAND    433E6
vector<uint8_t> id;
vector<float> rssi;
int i=0;
int j;
uint8_t IDE;
vector<uint8_t> detected;
Node this_node(0x05,0x00);//Create a Node with ID :5 and type of message :0
Receiver_Node receiver(this_node);//Create a receiver, using a node created
void setup()
{
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
  LoRa.setSpreadingFactor(7);
}

void loop()
{
  int packetSize = LoRa.parsePacket();
  if (packetSize)
  {
    //Serial.print("Paquete recibido: ");
    while (LoRa.available())
    {
      byte t_message = LoRa.read();
      //Serial.print("tipo de mensaje ");
      //Serial.print(t_message);
      IDE = LoRa.read();
      //Serial.print(" del identificador ");
      //Serial.println(IDE);

    }
    //Serial.print("RSSI: ");
    float rssi_receiver = LoRa.packetRssi();
    //Serial.print(rssi_receiver);
    //Serial.print("  ");
    //Serial.print(" SNR: ");
    float SNR = LoRa.packetSnr();
    //Serial.println(SNR);
    id.push_back(IDE);//It storages an ID in a list
    rssi.push_back(rssi_receiver);//It storages a RSSI in a list
    if(i==20) // Only make this action for 20 messages
    {
      receiver.SetIDList(id); // Setting ID list in the receiver
      receiver.SetRSSIList(rssi);// Setting RSSI list in the receiver
      receiver.Discard(); //Calling to the algorithm "discard"
      detected=receiver.GetID_detected();
      for(j=0;j<detected.size();j++)
      {
        cout<<detected.at(i);
      }
      id.clear();
      rssi.clear();
      i=0;
    }
    i++;
  }
}
