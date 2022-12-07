/*
 * keyboard.c
 *
 * Created: 30.03.2022 12:28:17
 *  Author: Jonathan Hengstermann
 */ 

#include  <asf.h>
#include "keyboard.h"

#include "matrix.h"

/************************************************************************/
/* variables for keys from button matrix                                */
/************************************************************************/

static struct matrix_key keys[MATRIX_Y][MATRIX_X] = {
	{
		{ .x_pos = 0, .y_pos = 0, .normal = HID_ESCAPE, .mod_fn = HID_TILDE},
		{ .x_pos = 1, .y_pos = 0, .normal = HID_1, .mod_fn = HID_F1},
		{ .x_pos = 2, .y_pos = 0, .normal = HID_2, .mod_fn = HID_F2},
		{ .x_pos = 3, .y_pos = 0, .normal = HID_3, .mod_fn = HID_F3},
		{ .x_pos = 4, .y_pos = 0, .normal = HID_4, .mod_fn = HID_F4},
		{ .x_pos = 5, .y_pos = 0, .normal = HID_5, .mod_fn = HID_F5},
		{ .x_pos = 6, .y_pos = 0, .normal = HID_6, .mod_fn = HID_F6},
		{ .x_pos = 7, .y_pos = 0, .normal = HID_7, .mod_fn = HID_F7},
		{ .x_pos = 8, .y_pos = 0, .normal = HID_8, .mod_fn = HID_F8},
		{ .x_pos = 9, .y_pos = 0, .normal = HID_9, .mod_fn = HID_F9},
		{ .x_pos = 10, .y_pos = 0, .normal = HID_0, .mod_fn = HID_F10},
		{ .x_pos = 11, .y_pos = 0, .normal = HID_DELETE, .mod_fn = -1}
	},
	{
		{ .x_pos = 0, .y_pos = 1, .normal = HID_TAB, .mod_fn = -1},
		{ .x_pos = 1, .y_pos = 1, .normal = HID_Q, .mod_fn = HID_F11},
		{ .x_pos = 2, .y_pos = 1, .normal = HID_W, .mod_fn = HID_F12},
		{ .x_pos = 3, .y_pos = 1, .normal = HID_E, .mod_fn = -1},
		{ .x_pos = 4, .y_pos = 1, .normal = HID_R, .mod_fn = -1},
		{ .x_pos = 5, .y_pos = 1, .normal = HID_T, .mod_fn = -1},
		{ .x_pos = 6, .y_pos = 1, .normal = HID_Y, .mod_fn = -1},
		{ .x_pos = 7, .y_pos = 1, .normal = HID_U, .mod_fn = HID_OPEN_BRACKET},
		{ .x_pos = 8, .y_pos = 1, .normal = HID_I, .mod_fn = -1},
		{ .x_pos = 9, .y_pos = 1, .normal = HID_O, .mod_fn = HID_COLON},
		{ .x_pos = 10, .y_pos = 1, .normal = HID_P, .mod_fn = -1},
		{ .x_pos = 11, .y_pos = 1, .normal = HID_UNDERSCORE, .mod_fn = -1}
	},
	{
		{ .x_pos = 0, .y_pos = 2, .normal = -1, .mod_fn = -1},			// - unused
		{ .x_pos = 1, .y_pos = 2, .normal = HID_A, .mod_fn = HID_QUOTE},
		{ .x_pos = 2, .y_pos = 2, .normal = HID_S, .mod_fn = -1},
		{ .x_pos = 3, .y_pos = 2, .normal = HID_D, .mod_fn = -1},
		{ .x_pos = 4, .y_pos = 2, .normal = HID_F, .mod_fn = -1},
		{ .x_pos = 5, .y_pos = 2, .normal = HID_G, .mod_fn = -1},
		{ .x_pos = 6, .y_pos = 2, .normal = HID_H, .mod_fn = -1},
		{ .x_pos = 7, .y_pos = 2, .normal = HID_J, .mod_fn = -1},
		{ .x_pos = 8, .y_pos = 2, .normal = HID_K, .mod_fn = -1},
		{ .x_pos = 9, .y_pos = 2, .normal = HID_L, .mod_fn = -1},
		{ .x_pos = 10, .y_pos = 2, .normal = HID_BACKSLASH, .mod_fn = HID_PLUS},
		{ .x_pos = 11, .y_pos = 2, .normal = HID_BACKSPACE, .mod_fn = -1}
	},
	{
		{ .x_pos = 0, .y_pos = 3, .normal = -1, .mod_fn = -1},			// - unused
		{ .x_pos = 1, .y_pos = 3, .normal = HID_Z, .mod_fn = -1},
		{ .x_pos = 2, .y_pos = 3, .normal = HID_X, .mod_fn = -1},
		{ .x_pos = 3, .y_pos = 3, .normal = HID_C, .mod_fn = -1},
		{ .x_pos = 4, .y_pos = 3, .normal = HID_V, .mod_fn = -1},
		{ .x_pos = 5, .y_pos = 3, .normal = HID_B, .mod_fn = -1},
		{ .x_pos = 6, .y_pos = 3, .normal = HID_N, .mod_fn = -1},
		{ .x_pos = 7, .y_pos = 3, .normal = HID_M, .mod_fn = -1},
		{ .x_pos = 8, .y_pos = 3, .normal = HID_COMMA, .mod_fn = -1},
		{ .x_pos = 9, .y_pos = 3, .normal = HID_DOT, .mod_fn = -1},
		{ .x_pos = 10, .y_pos = 3, .normal = HID_UP, .mod_fn = HID_PAGEUP},
		{ .x_pos = 11, .y_pos = 3, .normal = HID_ENTER, .mod_fn = -1}
	},
	{
		{ .x_pos = 0, .y_pos = 4, .normal = -1, .mod_fn = -1},			// - unused
		{ .x_pos = 1, .y_pos = 4, .normal = -1, .mod_fn = -1},			// - unused
		{ .x_pos = 2, .y_pos = 4, .normal = -1, .mod_fn = -1},			// - unused
		{ .x_pos = 3, .y_pos = 4, .normal = -1, .mod_fn = -1},			// - unused
		{ .x_pos = 4, .y_pos = 4, .normal = HID_SPACEBAR, .mod_fn = -1},
		{ .x_pos = 5, .y_pos = 4, .normal = -1, .mod_fn = -1},			// - unused
		{ .x_pos = 6, .y_pos = 4, .normal = -1, .mod_fn = -1},			// - unused
		{ .x_pos = 7, .y_pos = 4, .normal = HID_CLOSE_BRACKET, .mod_fn = -1},
		{ .x_pos = 8, .y_pos = 4, .normal = HID_SLASH, .mod_fn = -1},
		{ .x_pos = 9, .y_pos = 4, .normal = HID_LEFT, .mod_fn = -1},
		{ .x_pos = 10, .y_pos = 4, .normal = HID_DOWN, .mod_fn = HID_PAGEDOWN},
		{ .x_pos = 11, .y_pos = 4, .normal = HID_RIGHT, .mod_fn = -1}
	}
};

/************************************************************************/
/* Defines for special keys                                             */
/************************************************************************/
#define PIN_CAPS	PIN_PA06
#define PIN_CNTRL	PIN_PA04
#define PIN_SHIFT   PIN_PA05
#define PIN_ALT		PIN_PB07
#define PIN_ALT_GR  PIN_PB02
#define PIN_SUP     PIN_PB08
#define PIN_FN      PIN_PB03

#define PIN_LED_FN  PIN_PB01

#define KEY_HOLD_DOWN 300

static volatile bool main_b_kbd_enable = false;

/************************************************************************/
/* Send signal (up / down) via USB to PC								*/
/************************************************************************/
static bool usb_set_kbd_key(uint8_t key, bool down) {
	if (!main_b_kbd_enable) {
		return false;
	}
	
	if (down) {
		udi_hid_kbd_down(key);
	}
	else {
		udi_hid_kbd_up(key);
	}
	
	return true;
}
static bool usb_set_kbd_modifier(uint8_t key, bool down) {
	if (!main_b_kbd_enable) {
		return false;
	}
	
	if (down) {
		udi_hid_kbd_modifier_down(key);
	}
	else {
		udi_hid_kbd_modifier_up(key);
	}
	
	return true;
}

/************************************************************************/
/* Getter for "local" interpreted modifier keys							*/
/************************************************************************/
static bool read_special_key_press(uint8_t key) {
	return !port_pin_get_input_level(key);
}

/************************************************************************/
/* Handle current press-state of the keys								*/
/************************************************************************/
bool matrix_key_pressed[MATRIX_X][MATRIX_Y];
static bool get_matrix_key_pressed(matrix_key key) {
	return matrix_key_pressed[key.x_pos][key.y_pos];
}

static void set_matrix_key_pressed(matrix_key key, bool isPressed) {
	matrix_key_pressed[key.x_pos][key.y_pos] = isPressed;
}

/************************************************************************/
/* Update press states for keys											*/
/************************************************************************/
// matrix keys
static void press_matrix_keys(void);
//////////////////////////////////////////////////////////////////////////
// caps key
bool caps_key_pressed = false;
static void update_and_press_caps_key(void) {
	// TODO: update LED
	bool state = !port_pin_get_input_level(PIN_CAPS);
	if (state != caps_key_pressed) {
		//usb_set_kbd_modifier(0x82, state);
		usb_set_kbd_key(HID_CAPS_LOCK, state);
		caps_key_pressed = state;
	}
}
// cntrl key
bool cntrl_key_pressed = false;
static void update_and_press_cntrl_key(void) {
	bool state = !port_pin_get_input_level(PIN_CNTRL);
	if (state != cntrl_key_pressed) {
		usb_set_kbd_modifier(HID_MODIFIER_LEFT_CTRL, state);
		cntrl_key_pressed = state;
	}
}
// shift key
bool shift_key_pressed = false;
static void update_and_press_shift_key(void) {
	bool state = !port_pin_get_input_level(PIN_SHIFT);
	if (state != shift_key_pressed) {
		usb_set_kbd_modifier(HID_MODIFIER_LEFT_SHIFT, state);
		shift_key_pressed = state;
	}
}
// alt key
bool alt_key_pressed = false;
static void update_and_press_alt_key(void) {
	bool state = !port_pin_get_input_level(PIN_ALT);
	if (state != alt_key_pressed) {
		usb_set_kbd_modifier(HID_MODIFIER_RIGHT_ALT, state);
		alt_key_pressed = state;
	}
}
// altGr key
bool altGr_key_pressed = false;
static void update_and_press_altGr_key(void) {
	bool state = !port_pin_get_input_level(PIN_ALT_GR);
	if (state != altGr_key_pressed) {
		usb_set_kbd_modifier(HID_MODIFIER_RIGHT_ALT, state);
		altGr_key_pressed = state;
	}
}
// super key
bool super_key_pressed = false;
static void update_and_press_sup_key(void) {
	bool state = !port_pin_get_input_level(PIN_SUP);
	if (state != super_key_pressed) {
		usb_set_kbd_modifier(HID_MODIFIER_LEFT_UI, state);
		super_key_pressed = state;
	}
}

bool current_fn_led_state = true;
static void update_fn_led(void) {
	bool state =  port_pin_get_input_level(PIN_FN);
	if (current_fn_led_state != state) {
		port_pin_set_output_level(PIN_LED_FN, state);
		current_fn_led_state = state;
	}
}

/************************************************************************/
/* Setup "special keys" gpio pins										*/
/************************************************************************/
static void setup_gpio_pins(void) {
	struct port_config config_port_pin;
	port_get_config_defaults(&config_port_pin);
	
	config_port_pin.direction = PORT_PIN_DIR_INPUT;
	port_pin_set_config(PIN_CAPS,	&config_port_pin);
	port_pin_set_config(PIN_CNTRL,	&config_port_pin);
	port_pin_set_config(PIN_SHIFT,  &config_port_pin);
	port_pin_set_config(PIN_ALT,	&config_port_pin);
	port_pin_set_config(PIN_ALT_GR,	&config_port_pin);
	port_pin_set_config(PIN_SUP,	&config_port_pin);
	port_pin_set_config(PIN_FN, 	&config_port_pin);
	
	// Setup FN LED
	port_get_config_defaults(&config_port_pin);
	config_port_pin.direction = PORT_PIN_DIR_OUTPUT;
	port_pin_set_config(PIN_LED_FN, &config_port_pin);
	port_pin_set_output_level(PIN_LED_FN, true);
}

/************************************************************************/
/* Pupblic functions													*/
/************************************************************************/
/************************************************************************/
/* Init function														*/
/************************************************************************/
void keyboard_init(void) {
	matrix_setup();
	setup_gpio_pins();
}

/************************************************************************/
/* keyboard update function, periodically called						*/
/************************************************************************/
void keyboard_update(void) {
	update_fn_led();
	
	matrix_update_states();

	update_and_press_caps_key();
	update_and_press_cntrl_key();
	update_and_press_shift_key();
	update_and_press_alt_key();
	update_and_press_altGr_key();
	update_and_press_sup_key();
	
	press_matrix_keys();
}

// For testing
void keyboard_send(uint8_t key) {
	if (main_b_kbd_enable) {
		udi_hid_kbd_down(key);
		delay_ms(KEY_HOLD_DOWN);
		udi_hid_kbd_up(key);
	}
}

/************************************************************************/
/* Setter for main_b_kbd_enabled										*/
/************************************************************************/
bool keyboard_set_kbd_enabled(void) {
	main_b_kbd_enable = true;
	return true;
}
void keyboard_set_kbd_disabled(void) {
	main_b_kbd_enable = false;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

void press_matrix_keys(void) {
	bool state = false;
	
	for (uint x=0; x<MATRIX_X; x++) {
		for (uint y=0; y<MATRIX_Y; y++) {
			if (keys[y][x].normal < 0) {
				// unused
				continue;
			}
			state = matrix_get_state(keys[y][x], true);
			if (state != get_matrix_key_pressed(keys[y][x])) {
				if ((read_special_key_press(PIN_FN)) && (keys[y][x].mod_fn > 0)) {
					// FN modifier
					usb_set_kbd_key(keys[y][x].mod_fn, state);
				}
				else {
					// normal key
					usb_set_kbd_key(keys[y][x].normal, state);
				}
				set_matrix_key_pressed(keys[y][x], state);
			}
		}
	}
}