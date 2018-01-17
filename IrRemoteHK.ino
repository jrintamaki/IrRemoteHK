#include <IRremote.h>
#include "HK3480NEC.h" //List of commands available
IRsend irsend;

const int speakerInPin = A0;

int speakerValue = 0;
int speakerOffTime = 2000;
//int tempValue = 0;

void checkSpeakers() { 
/*Checks are spekers playing sound.  
After enough consencutive 0 signals will turn receiver off.
*/
  if (0 == analogRead(speakerInPin)) {
    speakerValue++;
    Serial.print(speakerValue);
    Serial.print("\n");

    if (speakerValue > speakerOffTime) {
      irsend.sendNEC(POWER_OFF, 32);
      speakerValue = 0;
    }

  }
  else
    speakerValue = 0;
}
void checkInput(int pin, long source){
  int tempValue = 0;
  for (int i=1; i<100;i++){
    tempValue += analogRead(pin);
    
  }
  Serial.print(tempValue);
  Serial.print("\n");
  if (tempValue / 100> 1){
    Serial.print(source);
    irsend.sendNEC(source, 32);
  }
}
void setup()
{
  Serial.begin(9600);
}

void loop() {
  checkInput(A1, VIDEO2);
  checkSpeakers();
  
   //irsend.sendNEC(VOL_UP, 32); //Sends command to receiver
  //delay(5000); //5 second delay between next command
}
