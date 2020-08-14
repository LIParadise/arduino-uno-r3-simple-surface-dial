# Surface Dial using Arduino UNO R3

A Surface Dial DIY

## Requirements/Prerequisites

- Arduino UNO R3
- Incremental Encoder
- Switch

Actually any board compliant with [HID-Project](https://github.com/NicoHood/HID/wiki) would do, with some minor modifications; this repo is specifically for Arduino UNO R3 with [HoodLoader2](https://github.com/NicoHood/HoodLoader2).

HoodLoader2 enable some interesting customization of the 2 onboard MCUs of Arduino UNO R3 (commonly 16u2 and 328p); this repo utilizes both, as a simple exercise.

## Installation

Follow instructions as specified in [HID-Project](https://github.com/NicoHood/HID/wiki).
Since this repo is for older boards like Arduino UNO R3, refer to [HoodLoader2](https://github.com/NicoHood/HoodLoader2) for how to configure the board.
After the board and Arduino IDE are configured, create and upload *2* sketches corresponding to the 2 MCUs, respectively.

## License and Copyright

This software is licensed under the MIT license. © LIParadise
