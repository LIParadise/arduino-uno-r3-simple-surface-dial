/*
 Copyright (c) 2014-2015 NicoHood
 See the readme for credit to other people.

 Serial HID-Bridge USB
 Select HoodLoader16u2 as board.

 After upload make sure the 16u2 sketch runs, not the HoodLoader2 bootloader.
 This example will type any serial data via keyboard.
*/

#include "HID-Project.h"

static const int pinLight = 5;
static const unsigned long bootFlashSerialTime = 200;

void setup() {
   // Start the Serial1 which is connected with the IO MCU.
   // Make sure both baud rates are the same
   // you can go up to 2000000 for very fast data transmission.
   Serial1.begin(115200);

   // Start the USB Serial for debugging
   Serial.begin(115200);

   // When flashing new firmware, flash buffer
   static unsigned long bootupTime = millis();
   static unsigned long okayTime = bootupTime + bootFlashSerialTime;
   while(millis() != okayTime){
      Serial1.read();
   }

   // SurfaceDial
   SurfaceDial.begin();

   pinMode(pinLight, OUTPUT);
}

void loop() {
   // Check if any Serial data from the IO MCU was received
   if (Serial1.available() > 0) {
      byte data = Serial1.read();

      if (data & (char)0x01) {
         SurfaceDial.press();
         digitalWrite(pinLight, HIGH);
      } else {
         SurfaceDial.release();
         digitalWrite(pinLight, LOW);
      }

      if (data & (char)0x02) {
         SurfaceDial.rotate(10);
      } else if (data & (char)0x04) {
         SurfaceDial.rotate(-10);
      }
   }
}
