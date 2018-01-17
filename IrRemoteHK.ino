#include <IRremote.h>
#include "HK3480NEC.h" //List of commands available
IRsend irsend;
const int speakerInPin = A0;

int speakerValue = 0;
int tempValue =0;
void setup(){
  Serial.begin(9600);
  
}

void loop() {
  //speakerValue =  analogRead(speakerInPin);
  //Serial.print("System ok\n");
  tempValue = 0;
  for (int i=1; i<10;i++){
    tempValue += analogRead(speakerInPin);
  }
  speakerValue = tempValue / 10;
  Serial.print("Speaker = ");
  Serial.print(speakerValue);
  Serial.print("\n");
  delay(100);
  //irsend.sendNEC(VOL_UP, 32); //Sends command to receiver
  //delay(5000); //5 second delay between next command
}
