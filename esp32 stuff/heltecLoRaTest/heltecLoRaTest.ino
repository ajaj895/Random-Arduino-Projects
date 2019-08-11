/*
 * This is a test program for my new heltec LoRa V2 board.
 */

#include "Arduino.h"
#include "heltec.h" //for the board itself

#define BAND 9144E5 //this is the setable frequency, this is actually 914 MHZ (914,000,000 hz)

int counter = 0;//a sent packet counter
String packet; //used for sending data 

void logo(){//borrowed from the LoRa32 Factory test
  Heltec.display -> clear();
  Heltec.display -> drawString(0,10,"Hello world!");
}
void setup() {
  // put your setup code here, to run once:
  Heltec.begin(true,true,true,true,BAND);
  /*
   * The previous command explination goes as follows:
   * first bool is a display enable boolean
   * second bool is a LoRa enable boolean
   * third bool is a Serial enable boolean
   * fourth bool is a LoRa use PABOOST ? enable boolean
   * the last variable is the LoRa frequency
   */

   logo();
   delay(300);
   Heltec.display -> clear();
}

void send()//also borrowed from the factory test
{
    LoRa.beginPacket();
    LoRa.print("This is a long message that will test the speed and bandwidth of the LoRa frequency and bandwidth.");
    LoRa.print(counter++);
    LoRa.endPacket();
}
void displayLoRa(){//inspired by the factory test
  Heltec.display -> drawString(0, 50, "Packets sent: " + (String)(counter+1));//look into this, this should be on the bottom of the screen
  Heltec.display -> drawString(0, 20, "LoRa Frequency: " + (String)BAND);//drawstring needs a pointer, -> creates a pointer
  Heltec.display -> display();
  delay(100);
  Heltec.display -> clear();
}
void loop() {
  // put your main code here, to run repeatedly:
  displayLoRa();
  send();
  delay(30000);//30 seconds;
  
}
