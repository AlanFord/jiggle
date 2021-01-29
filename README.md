# jiggle - The automated USB mouse

## Introduction

Do you really hate the way password-locked screen savers on school/office computers always pop up at 
inconvenient times?  Do you have to periodically jiggle the mouse or press a key to keep the screen 
saver at bay?  Jiggle is here to solve your problem!

This is a modern update of a project I built years ago and, over time, lost the source code.  The 
project is based on a Teensy 2.0, an 8-bit microcontroller available 
from [PJRC](https://www.pjrc.com/store/teensy.html).  The original software was written in C, while 
this updated version uses an Arduino-style source for ease of compilation and loading.

The Teensy emulates a USB mouse, periodically moving an infinitesimal amount right and then left.  
The motion every 10 seconds or so is small enough that you won't notice it on the screen,
but it will keep the screen saver at bay.  It can be used along with
your normal mouse or trackpad (most, if not all, computers will gladly accept input from two mice).

## Building the Software

- Download and run the Arduino Installer (not required on a Mac) 
- Download and install the [Teensyduino](https://www.pjrc.com/teensy/teensyduino.html) software from PJRC.  
Teensduino allows you to program the Teensy with the Arduino
programming environment.
- Run Teensyduino, set the Board menu item to "Teensy 2.0" and set the USB Type menu item to "Raw HID".
- Compile the code and upload to the board.

- Disconnect from the USB port, reconnect.

- A flash on the Teensy LED every 10 seconds shows the Jiggle is working!
