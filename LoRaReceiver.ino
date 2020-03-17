y#include "heltec.h"
#define BAND    433E6 
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
      byte IDE = LoRa.read();
      //Serial.print(" del identificador ");
      //Serial.println(IDE);
      
    }
    //Serial.print("RSSI: ");
    float RSSI = LoRa.packetRssi();
    Serial.print(RSSI);
    Serial.print("  ");
    //Serial.print(" SNR: ");
    float SNR = LoRa.packetSnr();
    Serial.println(SNR);
  }
}
