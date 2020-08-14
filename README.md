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

```
MIT License

Copyright (c) 2020 LIParadise

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
