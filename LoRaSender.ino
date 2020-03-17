#include "heltec.h"
//#include "Header.h"
#define BAND    433E6  //you can set band here directly,e.g. 868E6,915E6

int i;
byte t_message = 0x00;
byte IDE = 0x01;

void setup() 
{
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
  LoRa.setSpreadingFactor(7);  
}

void loop() 
{
  for(i=0; i<1000; i++)
  {
      Serial.print("Mensaje de identificacion: ");
      Serial.println(i+1);
      LoRa.beginPacket();
      LoRa.setTxPower(14,RF_PACONFIG_PASELECT_PABOOST);
      LoRa.write(t_message);
      LoRa.write(IDE);
      LoRa.endPacket();  
  }
  delay(20000);

}
