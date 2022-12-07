/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to system_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <asf.h>
#include "conf_usb.h"

#include "system_time.h"
#include "keyboard.h"

#define EVER (;;)

#define PIN_LED_CAPS PIN_PB09

int main (void)
{
	irq_initialize_vectors();
	cpu_irq_enable();
		
	board_init();
	system_init();
	
	delay_init();
	
	init_timing();
	
	/* Insert application code here, after the board has been initialized. */
	keyboard_init();
	
	udc_start();
	
	// Setup Caps Lock LED
	struct port_config config_port_pin;
	port_get_config_defaults(&config_port_pin);
	config_port_pin.direction = PORT_PIN_DIR_OUTPUT;
	port_pin_set_config(PIN_LED_CAPS, &config_port_pin);
	port_pin_set_output_level(PIN_LED_CAPS, true);
	
	for EVER {
		 keyboard_update();
	}
	
}

bool main_kbd_enable(void)
{
	return keyboard_set_kbd_enabled();
}

void main_kbd_disable(void)
{
	keyboard_set_kbd_disabled();
}

void main_kbd_led_change(uint8_t report)
{
	if (report & HID_LED_CAPS_LOCK) {
		port_pin_set_output_level(PIN_LED_CAPS, false);
	}
	else
	{
		port_pin_set_output_level(PIN_LED_CAPS, true);
	}
}