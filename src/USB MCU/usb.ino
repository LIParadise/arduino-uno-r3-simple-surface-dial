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

void setup() {
   // Start the Serial1 which is connected with the IO MCU.
   // Make sure both baud rates are the same
   // you can go up to 2000000 for very fast data transmission.
   Serial1.begin(115200);

   // Sends a clean report to the host. This is important on any Arduino type.
   Keyboard.begin();

   // Start the USB Serial for debugging
   Serial.begin(115200);

   // SurfaceDial
   SurfaceDial.begin();

   pinMode(pinLight, OUTPUT);
}

void loop() {
   // Check if any Serial data from the IO MCU was received
   if (Serial1.available() > 0) {
      char buffer[2];
      Serial1.readBytes(buffer, 2);

      if (buffer[1]) {
         SurfaceDial.press();
         digitalWrite(pinLight, HIGH);
      } else {
         SurfaceDial.release();
         digitalWrite(pinLight, LOW);
      }

      if (buffer[0] == 1) {
         SurfaceDial.rotate(10);
      } else if (buffer[0] == 2) {
         SurfaceDial.rotate(-10);
      }
   }
}
