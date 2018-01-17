#include <IRremote.h>
#include "HK3480NEC.h" //List of commands available
IRsend irsend;

const int speakerInPin = A0;

int speakerValue = 0;
int speakerOffTime = 20000;
int tempValue = 0;

void setup()
{
  Serial.begin(9600);
}

void loop() {
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
  //delay(50);
  //irsend.sendNEC(VOL_UP, 32); //Sends command to receiver
  //delay(5000); //5 second delay between next command
}
