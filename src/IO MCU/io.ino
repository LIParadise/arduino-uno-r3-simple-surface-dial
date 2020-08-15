/*
 Copyright (c) 2014-2015 NicoHood
 See the readme for credit to other people.

 Serial HID-Bridge IO
 Select Arduino Uno/Mega HID-Bridge as board.

 After upload make sure the 16u2 sketch runs, not the HoodLoader2 bootloader.
 This example will print random chars via serial to the USB MCU.
 If the USB MCU has the other bridge sketch uploaded
 it should type those chars via keyboard.
*/

static const int pinEncoder0 = 9;
static const int pinEncoder1 = 11;
static const int pinButton   = 12;

static volatile int previousEncoderValue = 0;
static volatile int encoderCounter = 0;

static const int encoderThresholdPositive = 1;
static const int encoderThresholdNegative = -1;

void setup() {
   // Start the Serial which is connected with the USB MCU.
   // Make sure both baud rates are the same
   // you can go up to 2000000 for very fast data transmission.
   Serial.begin(115200);
   pinMode(pinEncoder0, INPUT_PULLUP);
   pinMode(pinEncoder1, INPUT_PULLUP);
   pinMode(pinButton,   INPUT_PULLUP);
}

void changed() {
   int A = digitalRead(pinEncoder0);
   int B = digitalRead(pinEncoder1);

   int currentEncoderValue = (A << 1) | B;
   int combinedEncoderValue = (previousEncoderValue << 2) | currentEncoderValue;

   if (combinedEncoderValue == 0b0010 ||
       combinedEncoderValue == 0b1011 ||
       combinedEncoderValue == 0b1101 ||
       combinedEncoderValue == 0b0100) {
      encoderCounter++;
   }

   if (combinedEncoderValue == 0b0001 ||
       combinedEncoderValue == 0b0111 ||
       combinedEncoderValue == 0b1110 ||
       combinedEncoderValue == 0b1000) {
      encoderCounter--;
   }

   previousEncoderValue = currentEncoderValue;
}

void loop() {
   changed();

   byte data = 0x00;

   if(!digitalRead(pinButton)){
      data |= 0x01;
   }

   if(encoderCounter >= encoderThresholdPositive){
      data |= 0x02;
      encoderCounter = 0;
   }else if(encoderCounter <= encoderThresholdNegative) {
      data |= 0x04;
      encoderCounter = 0;
   }

   Serial.write(data);
   delay(5);
}
