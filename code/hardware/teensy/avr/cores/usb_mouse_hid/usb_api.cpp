/* USB API for Teensy USB Development Board
 * http://www.pjrc.com/teensy/teensyduino.html
 * Copyright (c) 2008 PJRC.COM, LLC
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdint.h>
#include "usb_common.h"
#include "usb_private.h"
#include "usb_api.h"
#include "wiring.h"


void usb_mouse_class::move(int8_t x, int8_t y, int8_t wheel, int8_t horiz)
{
        uint8_t intr_state, timeout;

        if (!usb_configuration) return;
        if (x == -128) x = -127;
        if (y == -128) y = -127;
        if (wheel == -128) wheel = -127;
        if (horiz == -128) horiz = -127;
        intr_state = SREG;
        cli();
        UENUM = MOUSE_ENDPOINT;
        timeout = UDFNUML + 50;
        while (1) {
                // are we ready to transmit?
                if (UEINTX & (1<<RWAL)) break;
                SREG = intr_state;
                // has the USB gone offline?
                if (!usb_configuration) return;
                // have we waited too long?
                if (UDFNUML == timeout) return;
                // get ready to try checking again
                intr_state = SREG;
                cli();
                UENUM = MOUSE_ENDPOINT;
        }
        UEDATX = mouse_buttons;
        UEDATX = x;
        UEDATX = y;
        UEDATX = wheel;
        UEDATX = horiz;
        UEINTX = 0x3A;
        SREG = intr_state;
}

void usb_mouse_class::click(uint8_t b)
{
	mouse_buttons = b;
	move(0, 0);
	mouse_buttons = 0;
	move(0, 0);
}

void usb_mouse_class::scroll(int8_t wheel, int8_t horiz)
{
	move(0, 0, wheel, horiz);
}

void usb_mouse_class::set_buttons(uint8_t left, uint8_t middle, uint8_t right, uint8_t back, uint8_t forward)
{
        uint8_t mask=0;

        if (left) mask |= 1;
        if (middle) mask |= 4;
        if (right) mask |= 2;
        if (back) mask |= 8;
        if (forward) mask |= 16;
        mouse_buttons = mask;
        move(0, 0);
}

void usb_mouse_class::press(uint8_t b)
{
	uint8_t prev = mouse_buttons;
	mouse_buttons |= (b & 7);
	if (mouse_buttons != prev) move(0, 0);
}

void usb_mouse_class::release(uint8_t b)
{
	uint8_t prev = mouse_buttons;
	mouse_buttons &= ~(b & 7);
	if (mouse_buttons != prev) move(0, 0);
}

bool usb_mouse_class::isPressed(uint8_t b)
{
	return ((mouse_buttons & (b & 7)) != 0);
}






static volatile uint8_t prev_byte=0;




// Preinstantiate Objects //////////////////////////////////////////////////////

usb_mouse_class		Mouse = usb_mouse_class();

