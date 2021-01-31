#ifndef USBserial_h_
#define USBserial_h_

#include <inttypes.h>


#define MOUSE_LEFT 1
#define MOUSE_MIDDLE 4
#define MOUSE_RIGHT 2
#define MOUSE_BACK 8
#define MOUSE_FORWARD 16
#define MOUSE_ALL (MOUSE_LEFT | MOUSE_RIGHT | MOUSE_MIDDLE | MOUSE_BACK | MOUSE_FORWARD)

class usb_mouse_class
{
	public:
	void begin(void) { }
	void end(void) { }
	void move(int8_t x, int8_t y, int8_t wheel=0, int8_t horiz=0);
	void click(uint8_t b = MOUSE_LEFT);
	void scroll(int8_t wheel, int8_t horiz=0);
	void set_buttons(uint8_t left, uint8_t middle=0, uint8_t right=0, uint8_t back=0, uint8_t forward=0);
	void press(uint8_t b = MOUSE_LEFT);
	void release(uint8_t b = MOUSE_LEFT);
	bool isPressed(uint8_t b = MOUSE_ALL);
};

extern usb_mouse_class Mouse;



#endif


