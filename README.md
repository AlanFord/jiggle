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
Summaries (better than mine) of the necessary steps can be found [here](http://www.planetpointy.co.uk/custom-teensy-2-0-joystick/) and [here](https://forum.pjrc.com/threads/29405-Teensyduino-USB-Mouse-Only-profilePitou).  Virtually all of the work is modifying the Teensyduino environment to accommodate a new USB configuration.  If you are happy with an emulator that combines a mouse+keyboard+joystick, stop here and compile with that option in the stock Teensyduino software.  The work performed here is an attempt to get to an "only a mouse" configuration.

### Setting Up

- Download and run the Arduino Installer (not required on a Mac) 
- Download and install the [Teensyduino](https://www.pjrc.com/teensy/teensyduino.html) software from PJRC. 
- Find the Teensy configuration files.  On a Mac use the Finder to go to Applications, find Teensyduino, right click and choose "Show Package Contents".  Work down the folders to find "Contents\Java\hardware\teensy\avr\".
- Copy in the files located in the jiggle repository.  You will be updating the file "boards.txt" as well as a number of files in "cores\teensy\".  You will also be adding a new directory called "cores\usb_mouse_hid\".
- Run Teensyduino, set the Board menu item to "Teensy 2.0" and set the USB Type menu item to "Mouse".  If "Mouse" doesn't show up as a USB Type option, check that you installed the "boards.txt" file in the proper location.
- Compile the jiggle code and upload to the board.

- Disconnect from the USB port, reconnect.

- A flash on the Teensy LED every 10 seconds shows the Jiggle is working!
