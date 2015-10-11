# qduinoEdge
A multi-mode blinky project inspired by the Kickstarter project "Vega Edge", instead
using the Qduino.

Based on original code from http://www.vegalite.com/pages/nerds

Notable modifications:
* Refactored button logic: easier to add new modes, debounce, long click instead of double click.
* Many new modes: binary counting, gray code counting, johnson counting, battery level display.
* Neopixels: can use any number of NeoPixels.

How To:
Wire a button to "buttonPin" (to ground) and a NeoPixel strip to "neoPin". Set "numLeds" to the 
number of LEDs in the NeoPixel strip. Binary counting gets wonky over 16 pixels. Most things look
good with multiples of three, although any number is fine in most modes. A small, 500mAh li-poly
battery and the Qduino should fit just fine in an Altoids "Smalls" tin, with the NeoPixel and
button through holes in the tin.

Hold the button closed for ~1sec to wake up. Click to cycle through modes.
