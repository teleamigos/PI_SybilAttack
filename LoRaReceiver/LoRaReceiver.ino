#include "heltec.h"
#include "Node.hpp"
#include "Receiver_Node.hpp"
#define BAND    433E6 
vector<uint8_t> id;
vector<float> rssi;
int i=0;
uint8_t IDE;
Node this_node(0x05,0x00);
Receiver_Node receiver(this_node);
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
    id.push_back(IDE);
    rssi.push_back(rssi_receiver);
    if(i==20)
    {
      receiver.SetIDList(id);
      receiver.SetRSSIList(rssi);
      receiver.Discard();
      id.clear();
      rssi.clear();
      i=0;
    }
    i++;
  }
}
