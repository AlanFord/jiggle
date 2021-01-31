#ifndef usb_serial_h__
#define usb_serial_h__

#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif

/**************************************************************************
 *
 *  Configurable Options
 *
 **************************************************************************/

#define VENDOR_ID               0x16C0
#define PRODUCT_ID              0x0482
#define TRANSMIT_FLUSH_TIMEOUT  4   /* in milliseconds */
#define TRANSMIT_TIMEOUT        25   /* in milliseconds */


/**************************************************************************
 *
 *  Endpoint Buffer Configuration
 *
 **************************************************************************/

// 0: control				64
// 1: debug IN				64x2
// 2: debug OUT				32x2
// 3: keyboard IN			8x2
// 4: mouse IN			 	16x2
// 5: joystick IN			16x2
// 6: keyboard media IN			8x2

// Some operating systems, especially Windows, may cache USB device
// info.  Changes to the device name may not update on the same
// computer unless the vendor or product ID numbers change, or the
// "bcdDevice" revision code is increased.

#ifndef STR_PRODUCT
#define STR_PRODUCT             L"Teensy Mouse"
#endif

#define ENDPOINT0_SIZE          64

#define MOUSE_INTERFACE		1
#define MOUSE_ENDPOINT		1
#define MOUSE_SIZE		8
#define MOUSE_BUFFER		EP_DOUBLE_BUFFER
#define MOUSE_INTERVAL		8

#define NUM_ENDPOINTS		2
#define NUM_INTERFACE		1


// setup
void usb_init(void);			// initialize everything
void usb_shutdown(void);		// shut off USB

// variables
extern volatile uint8_t usb_configuration;
extern volatile uint8_t usb_suspended;
extern volatile uint8_t debug_flush_timer;
extern uint8_t mouse_buttons;



#ifdef __cplusplus
} // extern "C"
#endif

#endif
