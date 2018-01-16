#include <IRremote.h>
#include "HK3480NEC.h" //List of commands available
IRsend irsend;

void setup()
{
}

void loop() {
  irsend.sendNEC(VOL_UP, 32); //Sends command to receiver
  delay(5000); //5 second delay between next command
}
