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
/* const variables for keys from button matrix                          */
/************************************************************************/
 const matrix_key key_1      = { .x_pos = 0, .y_pos = 0 };
 const matrix_key key_2      = { .x_pos = 1, .y_pos = 0 };
 const matrix_key key_3      = { .x_pos = 2, .y_pos = 0 };
 const matrix_key key_4      = { .x_pos = 3, .y_pos = 0 };
 const matrix_key key_5      = { .x_pos = 4, .y_pos = 0 };
 const matrix_key key_6      = { .x_pos = 5, .y_pos = 0 };
 const matrix_key key_7      = { .x_pos = 6, .y_pos = 0 };
 const matrix_key key_8      = { .x_pos = 7, .y_pos = 0 };
 const matrix_key key_9      = { .x_pos = 8, .y_pos = 0 };
 const matrix_key key_0      = { .x_pos = 9, .y_pos = 0 };
 // const matrix_key key_    = { .x_pos = 10, .y_pos = 0 }; // - unused

 const matrix_key key_TAB    = { .x_pos = 0, .y_pos = 1 };
 const matrix_key key_Q      = { .x_pos = 1, .y_pos = 1 };
 const matrix_key key_W      = { .x_pos = 2, .y_pos = 1 };
 const matrix_key key_E      = { .x_pos = 3, .y_pos = 1 };
 const matrix_key key_R      = { .x_pos = 4, .y_pos = 1 };
 const matrix_key key_T      = { .x_pos = 5, .y_pos = 1 };
 const matrix_key key_Z      = { .x_pos = 6, .y_pos = 1 };
 const matrix_key key_U      = { .x_pos = 7, .y_pos = 1 };
 const matrix_key key_I      = { .x_pos = 8, .y_pos = 1 };
 const matrix_key key_O      = { .x_pos = 9, .y_pos = 1 };
 const matrix_key key_P      = { .x_pos = 10, .y_pos = 1 };

 const matrix_key key_CPSLCK = { .x_pos = 0, .y_pos = 2 };
 const matrix_key key_A      = { .x_pos = 1, .y_pos = 2 };
 const matrix_key key_S      = { .x_pos = 2, .y_pos = 2 };
 const matrix_key key_D      = { .x_pos = 3, .y_pos = 2 };
 const matrix_key key_F      = { .x_pos = 4, .y_pos = 2 };
 const matrix_key key_G      = { .x_pos = 5, .y_pos = 2 };
 const matrix_key key_H      = { .x_pos = 6, .y_pos = 2 };
 const matrix_key key_J      = { .x_pos = 7, .y_pos = 2 };
 const matrix_key key_K      = { .x_pos = 8, .y_pos = 2 };
 const matrix_key key_L      = { .x_pos = 9, .y_pos = 2 };
 // const matrix_key key_    = { .x_pos = 10, .y_pos = 2 }; // - unused

 // const matrix_key key_    = { .x_pos = 0, .y_pos = 3 }; // - unused
 const matrix_key key_Y      = { .x_pos = 1, .y_pos = 3 };
 const matrix_key key_X      = { .x_pos = 2, .y_pos = 3 };
 const matrix_key key_C      = { .x_pos = 3, .y_pos = 3 };
 const matrix_key key_V      = { .x_pos = 4, .y_pos = 3 };
 const matrix_key key_B      = { .x_pos = 5, .y_pos = 3 };
 const matrix_key key_N      = { .x_pos = 6, .y_pos = 3 };
 const matrix_key key_M      = { .x_pos = 7, .y_pos = 3 };
 const matrix_key key_COMMA  = { .x_pos = 8, .y_pos = 3 };
 const matrix_key key_DOT    = { .x_pos = 9, .y_pos = 3 };
 // const matrix_key key_    = { .x_pos = 10, .y_pos = 3 }; // - unused

 // const matrix_key key_    = { .x_pos = 0, .y_pos = 4 }; // - unused
 // const matrix_key key_    = { .x_pos = 1, .y_pos = 4 }; // - unused
 // const matrix_key key_    = { .x_pos = 2, .y_pos = 4 }; // - unused
 // const matrix_key key_    = { .x_pos = 3, .y_pos = 4 }; // - unused
 // const matrix_key key_    = { .x_pos = 4, .y_pos = 4 }; // - unused
 // const matrix_key key_    = { .x_pos = 5, .y_pos = 4 }; // - unused
 // const matrix_key key_    = { .x_pos = 6, .y_pos = 4 }; // - unused
 // const matrix_key key_    = { .x_pos = 7, .y_pos = 4 }; // - unused
 // const matrix_key key_    = { .x_pos = 8, .y_pos = 4 }; // - unused
 const matrix_key key_ENT    = { .x_pos = 9, .y_pos = 4 };
 // const matrix_key key_    = { .x_pos = 10, .y_pos = 4 }; // - unused

 // const matrix_key key_    = { .x_pos = 0, .y_pos = 5 }; // -unused
 const matrix_key key_QUEST	 = { .x_pos = 1, .y_pos = 5 };
 // const matrix_key key_    = { .x_pos = 2, .y_pos = 5 }; // - unused
 const matrix_key key_BCKSP	 = { .x_pos = 3, .y_pos = 5 };
 // const matrix_key key_    = { .x_pos = 4, .y_pos = 5 }; // - unused
 const matrix_key key_SPC    = { .x_pos = 5, .y_pos = 5 };
 const matrix_key key_LEFT	 = { .x_pos = 6, .y_pos = 5 };
 const matrix_key key_DOWN   = { .x_pos = 7, .y_pos = 5 };
 const matrix_key key_RIGHT  = { .x_pos = 8, .y_pos = 5 };
 const matrix_key key_UP     = { .x_pos = 9, .y_pos = 5 };
 // const matrix_key key_    = { .x_pos = 10, .y_pos = 5 } // - unused

/************************************************************************/
/* Defines for special keys                                             */
/************************************************************************/
#define PIN_SHIFT	PIN_PA04
#define PIN_SUP		PIN_PB06
#define PIN_FN		PIN_PB07
#define PIN_ALT		PIN_PB08
#define PIN_CTRL	PIN_PB09


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
/* special char interpretation                                          */
/************************************************************************/
static void interpret_special_key(
bool state,
uint8_t normal,
uint8_t fn,
uint8_t alt
) {
	if (state) {
		if (read_special_key_press(PIN_FN) && (fn != 0)) {
			usb_set_kbd_key(fn, state);
		}
		else if (read_special_key_press(PIN_ALT) && (alt != 0)) {
			usb_set_kbd_key(alt, state);
		}
		else {
			usb_set_kbd_key(normal, state);
		}
	}
	else { // release all keys assigned to this button
		usb_set_kbd_key(normal, state);
		if (fn != 0) {
			usb_set_kbd_key(fn, state);
		}
		if (alt != 0) {
			usb_set_kbd_key(alt, state);
		}
	}
}

/************************************************************************/
/* Update press states for keys											*/
/************************************************************************/
// matrix keys
static void press_matrix_keys(void);
//////////////////////////////////////////////////////////////////////////
// shift key
bool shift_key_pressed = false;
static void update_and_press_shift_key(void) {
	bool state = !port_pin_get_input_level(PIN_SHIFT);
	if (state != shift_key_pressed) {
		usb_set_kbd_modifier(HID_MODIFIER_LEFT_SHIFT, state);
		shift_key_pressed = state;
	}
}
// ctrl key
bool ctrl_key_pressed = false;
static void update_and_press_ctrl_key(void) {
	bool state = !port_pin_get_input_level(PIN_CTRL);
	if (state != ctrl_key_pressed) {
		usb_set_kbd_modifier(HID_MODIFIER_LEFT_CTRL, state);
		ctrl_key_pressed = state;
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


/************************************************************************/
/* Setup "special keys" gpio pins										*/
/************************************************************************/
static void setup_gpio_pins(void) {
	struct port_config config_port_pin;
	port_get_config_defaults(&config_port_pin);
	
	config_port_pin.direction = PORT_PIN_DIR_INPUT;
	port_pin_set_config(PIN_SHIFT,	&config_port_pin);
	port_pin_set_config(PIN_SUP,	&config_port_pin);
	port_pin_set_config(PIN_FN,		&config_port_pin);
	port_pin_set_config(PIN_ALT,	&config_port_pin);
	port_pin_set_config(PIN_CTRL,	&config_port_pin);
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
	
	matrix_update_states();

	update_and_press_shift_key();
	update_and_press_ctrl_key();
	update_and_press_sup_key();
	
	press_matrix_keys();
}

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
	
	// key_1
	state = matrix_get_state(key_1, true);
	if (state != get_matrix_key_pressed(key_1)) {
		interpret_special_key(state, HID_1, HID_F1, 0);
		set_matrix_key_pressed(key_1, state);
	}
	
	// key_2
	state = matrix_get_state(key_2, true);
	if (state != get_matrix_key_pressed(key_2)) {
		interpret_special_key(state, HID_2, HID_F2, 0);
		set_matrix_key_pressed(key_2, state);
	}
	
	// key_3
	state = matrix_get_state(key_3, true);
	if (state != get_matrix_key_pressed(key_3)) {
		interpret_special_key(state, HID_3, HID_F3, 0);
		set_matrix_key_pressed(key_3, state);
	}
	
	// key_4
	state = matrix_get_state(key_4, true);
	if (state != get_matrix_key_pressed(key_4)) {
		interpret_special_key(state, HID_4, HID_F4, 0);
		set_matrix_key_pressed(key_4, state);
	}
	
	// key_5
	state = matrix_get_state(key_5, true);
	if (state != get_matrix_key_pressed(key_5)) {
		interpret_special_key(state, HID_5, HID_F5, 0);
		set_matrix_key_pressed(key_5, state);
	}
	
	// key_6
	state = matrix_get_state(key_6, true);
	if (state != get_matrix_key_pressed(key_6)) {
		if (state) {
			if (read_special_key_press(PIN_FN)) {
				usb_set_kbd_key(HID_F6, state);
			}
			else if (read_special_key_press(PIN_ALT)) {
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_ALT, true);
				usb_set_kbd_key(HID_UNDERSCORE, true);
				delay_ms(KEY_HOLD_DOWN);
				usb_set_kbd_key(HID_UNDERSCORE, false);
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_ALT, false);
			}
			else {
				usb_set_kbd_key(HID_6, state);
			}
		}
		else { // release all keys assigned to this button
			usb_set_kbd_key(HID_6, state);
			usb_set_kbd_key(HID_F6, state);
		}
		set_matrix_key_pressed(key_6, state);
	}

	// key_7
	state = matrix_get_state(key_7, true);
	if (state != get_matrix_key_pressed(key_7)) {
		if (state) {
			if (read_special_key_press(PIN_FN)) {
				usb_set_kbd_key(HID_F7, state);
			}
			else if (read_special_key_press(PIN_ALT)) {
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_ALT, true);
				usb_set_kbd_key(HID_7, true);
				delay_ms(KEY_HOLD_DOWN);
				usb_set_kbd_key(HID_7, false);
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_ALT, false);
			}
			else {
				usb_set_kbd_key(HID_7, state);
			}
		}
		else { // release all keys assigned to this button
			usb_set_kbd_key(HID_7, state);
			usb_set_kbd_key(HID_F7, state);
		}
		set_matrix_key_pressed(key_7, state);
	}
	
	// key_8
	state = matrix_get_state(key_8, true);
	if (state != get_matrix_key_pressed(key_8)) {
		if (state) {
			if (read_special_key_press(PIN_FN)) {
				usb_set_kbd_key(HID_F8, state);
			}
			else if (read_special_key_press(PIN_ALT)) {
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_ALT, true);
				usb_set_kbd_key(HID_8, true);
				delay_ms(KEY_HOLD_DOWN);
				usb_set_kbd_key(HID_8, false);
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_ALT, false);
			}
			else {
				usb_set_kbd_key(HID_8, state);
			}
		}
		else { // release all keys assigned to this button
			usb_set_kbd_key(HID_8, state);
			usb_set_kbd_key(HID_F8, state);
		}
		set_matrix_key_pressed(key_8, state);
	}
	
	// key_9
	state = matrix_get_state(key_9, true);
	if (state != get_matrix_key_pressed(key_9)) {
		if (state) {
			if (read_special_key_press(PIN_FN)) {
				usb_set_kbd_key(HID_F9, state);
			}
			else if (read_special_key_press(PIN_ALT)) {
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_ALT, true);
				usb_set_kbd_key(HID_9, true);
				delay_ms(KEY_HOLD_DOWN);
				usb_set_kbd_key(HID_9, false);
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_ALT, false);
			}
			else {
				usb_set_kbd_key(HID_9, state);
			}
		}
		else { // release all keys assigned to this button
			usb_set_kbd_key(HID_9, state);
			usb_set_kbd_key(HID_F9, state);
		}
		set_matrix_key_pressed(key_9, state);
	}

	// key_0
	state = matrix_get_state(key_0, true);
	if (state != get_matrix_key_pressed(key_0)) {
		if (state) {
			if (read_special_key_press(PIN_FN)) {
				usb_set_kbd_key(HID_F10, state);
			}
			else if (read_special_key_press(PIN_ALT)) {
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_ALT, true);
				usb_set_kbd_key(HID_0, true);
				delay_ms(KEY_HOLD_DOWN);
				usb_set_kbd_key(HID_0, false);
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_ALT, false);
			}
			else {
				usb_set_kbd_key(HID_0, state);
			}
		}
		else { // release all keys assigned to this button
			usb_set_kbd_key(HID_0, state);
			usb_set_kbd_key(HID_F10, state);
		}
		set_matrix_key_pressed(key_0, state);
	}
	
	// key_TAB
	state = matrix_get_state(key_TAB, true);
	if (state != get_matrix_key_pressed(key_TAB)) {
		interpret_special_key(state, HID_TAB, 0, 0);
		set_matrix_key_pressed(key_TAB, state);
	}
	
	// key_Q
	state = matrix_get_state(key_Q, true);
	if (state != get_matrix_key_pressed(key_Q)) {
		if (state) {
			if (read_special_key_press(PIN_ALT)) {
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_ALT, true);
				usb_set_kbd_key(HID_Q, true);
				delay_ms(KEY_HOLD_DOWN);
				usb_set_kbd_key(HID_Q, false);
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_ALT, false);
			}
			else {
				usb_set_kbd_key(HID_Q, state);
			}
		}
		else { // release all keys assigned to this button
			usb_set_kbd_key(HID_Q, state);
		}
		set_matrix_key_pressed(key_Q, state);
	}

	// key_W
	state = matrix_get_state(key_W, true);
	if (state != get_matrix_key_pressed(key_W)) {
		interpret_special_key(state, HID_W, 0, 0);
		set_matrix_key_pressed(key_W, state);
	}
	
	// key_E
	state = matrix_get_state(key_E, true);
	if (state != get_matrix_key_pressed(key_E)) {
		if (state) {
			if (read_special_key_press(PIN_ALT)) {
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_ALT, true);
				usb_set_kbd_key(HID_E, true);
				delay_ms(KEY_HOLD_DOWN);
				usb_set_kbd_key(HID_E, false);
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_ALT, false);
			}
			else {
				usb_set_kbd_key(HID_E, state);
			}
		}
		else { // release all keys assigned to this button
			usb_set_kbd_key(HID_E, state);
		}
		set_matrix_key_pressed(key_E, state);
	}
	
	// key_R
	state = matrix_get_state(key_R, true);
	if (state != get_matrix_key_pressed(key_R)) {
		interpret_special_key(state, HID_R, 0, 0);
		set_matrix_key_pressed(key_R, state);
	}
	
	// key_T
	state = matrix_get_state(key_T, true);
	if (state != get_matrix_key_pressed(key_T)) {
		interpret_special_key(state, HID_T, 0, 0);
		set_matrix_key_pressed(key_T, state);
	}
	
	// key_Z
	state = matrix_get_state(key_Z, true);
	if (state != get_matrix_key_pressed(key_Z)) {
		interpret_special_key(state, HID_Y, 0, 0);
		set_matrix_key_pressed(key_Z, state);
	}
	
	// key_U
	state = matrix_get_state(key_U, true);
	if (state != get_matrix_key_pressed(key_U)) {
		interpret_special_key(state, HID_U, 0, HID_OPEN_BRACKET);
		set_matrix_key_pressed(key_U, state);
	}
	
	// key_I
	state = matrix_get_state(key_I, true);
	if (state != get_matrix_key_pressed(key_I)) {
		interpret_special_key(state, HID_I, 0, 0);
		set_matrix_key_pressed(key_I, state);
	}

	// key_O
	state = matrix_get_state(key_O, true);
	if (state != get_matrix_key_pressed(key_O)) {
		interpret_special_key(state, HID_O, 0, HID_CLOSE_BRACKET);
		set_matrix_key_pressed(key_O, state);
	}
	
	// key_P
	state = matrix_get_state(key_P, true);
	if (state != get_matrix_key_pressed(key_P)) {
		interpret_special_key(state, HID_P, 0, HID_BACKSLASH);
		set_matrix_key_pressed(key_P, state);
	}
	
	// key_CPSLCK
	state = matrix_get_state(key_CPSLCK, true);
	if (state != get_matrix_key_pressed(key_CPSLCK)) {
		interpret_special_key(state, HID_CAPS_LOCK, 0, 0);
		set_matrix_key_pressed(key_CPSLCK, state);
	}

	// key_A
	state = matrix_get_state(key_A, true);
	if (state != get_matrix_key_pressed(key_A)) {
		interpret_special_key(state, HID_A, 0, HID_QUOTE);
		set_matrix_key_pressed(key_A, state);
	}
	
	// key_S
	state = matrix_get_state(key_S, true);
	if (state != get_matrix_key_pressed(key_S)) {
		interpret_special_key(state, HID_S, 0, 0);
		set_matrix_key_pressed(key_S, state);
	}
	
	// key_D
	state = matrix_get_state(key_D, true);
	if (state != get_matrix_key_pressed(key_D)) {
		interpret_special_key(state, HID_D, 0, 0);
		set_matrix_key_pressed(key_D, state);
	}
	
	// key_F
	state = matrix_get_state(key_F, true);
	if (state != get_matrix_key_pressed(key_F)) {
		interpret_special_key(state, HID_F, 0, 0);
		set_matrix_key_pressed(key_F, state);
	}
	
	// key_G
	state = matrix_get_state(key_G, true);
	if (state != get_matrix_key_pressed(key_G)) {
		interpret_special_key(state, HID_G, 0, 0);
		set_matrix_key_pressed(key_G, state);
	}

	// key_H
	state = matrix_get_state(key_H, true);
	if (state != get_matrix_key_pressed(key_H)) {
		interpret_special_key(state, HID_H, 0, 0);
		set_matrix_key_pressed(key_H, state);
	}

	// key_J
	state = matrix_get_state(key_J, true);
	if (state != get_matrix_key_pressed(key_J)) {
		interpret_special_key(state, HID_J, 0, HID_CLOSE_BRACKET);
		set_matrix_key_pressed(key_J, state);
	}

	// key_K
	state = matrix_get_state(key_K, true);
	if (state != get_matrix_key_pressed(key_K)) {
		if (state) {
			if (read_special_key_press(PIN_ALT)) {
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_SHIFT, true);
				usb_set_kbd_key(HID_CLOSE_BRACKET, true);
				delay_ms(KEY_HOLD_DOWN);
				usb_set_kbd_key(HID_CLOSE_BRACKET, false);
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_SHIFT, false);
			}
			else {
				usb_set_kbd_key(HID_K, state);
			}
		}
		else { // release all keys assigned to this button
			usb_set_kbd_key(HID_K, state);
		}
		set_matrix_key_pressed(key_K, state);
	}

	// key_L
	state = matrix_get_state(key_L, true);
	if (state != get_matrix_key_pressed(key_L)) {
		if (state) {
			if (read_special_key_press(PIN_ALT)) {
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_SHIFT, true);
				usb_set_kbd_key(HID_BACKSLASH, true);
				delay_ms(KEY_HOLD_DOWN);
				usb_set_kbd_key(HID_BACKSLASH, false);
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_SHIFT, false);
			}
			else {
				usb_set_kbd_key(HID_L, state);
			}
		}
		else { // release all keys assigned to this button
			usb_set_kbd_key(HID_L, state);
		}
		set_matrix_key_pressed(key_L, state);
	}
	
	// key_Y
	state = matrix_get_state(key_Y, true);
	if (state != get_matrix_key_pressed(key_Y)) {
		interpret_special_key(state, HID_Z, 0, HID_TILDE);
		set_matrix_key_pressed(key_Y, state);
	}

	// key_X
	state = matrix_get_state(key_X, true);
	if (state != get_matrix_key_pressed(key_X)) {
		if (state) {
			if (read_special_key_press(PIN_ALT)) {
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_SHIFT, true);
				usb_set_kbd_key(HID_TILDE, true);
				delay_ms(KEY_HOLD_DOWN);
				usb_set_kbd_key(HID_TILDE, false);
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_SHIFT, false);
			}
			else {
				usb_set_kbd_key(HID_X, state);
			}
		}
		else { // release all keys assigned to this button
			usb_set_kbd_key(HID_X, state);
		}
		set_matrix_key_pressed(key_X, state);
	}
	
	// key_C
	state = matrix_get_state(key_C, true);
	if (state != get_matrix_key_pressed(key_C)) {
		if (state) {
			if (read_special_key_press(PIN_ALT)) {
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_ALT, true);
				usb_set_kbd_key(HID_TILDE, true);
				delay_ms(KEY_HOLD_DOWN);
				usb_set_kbd_key(HID_TILDE, false);
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_ALT, false);
			}
			else {
				usb_set_kbd_key(HID_C, state);
			}
		}
		else { // release all keys assigned to this button
			usb_set_kbd_key(HID_C, state);
		}
		set_matrix_key_pressed(key_C, state);
	}

	// key_V
	state = matrix_get_state(key_V, true);
	if (state != get_matrix_key_pressed(key_V)) {
		interpret_special_key(state, HID_V, 0, 0);
		set_matrix_key_pressed(key_V, state);
	}

	// key_B
	state = matrix_get_state(key_B, true);
	if (state != get_matrix_key_pressed(key_B)) {
		interpret_special_key(state, HID_B, 0, 0);
		set_matrix_key_pressed(key_B, state);
	}

	// key_N
	state = matrix_get_state(key_N, true);
	if (state != get_matrix_key_pressed(key_N)) {
		interpret_special_key(state, HID_N, 0, HID_SLASH);
		set_matrix_key_pressed(key_N, state);
	}
	
	// key_M
	state = matrix_get_state(key_M, true);
	if (state != get_matrix_key_pressed(key_M)) {
		if (state) {
			if (read_special_key_press(PIN_ALT)) {
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_SHIFT, true);
				usb_set_kbd_key(HID_SLASH, true);
				delay_ms(KEY_HOLD_DOWN);
				usb_set_kbd_key(HID_SLASH, false);
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_SHIFT, false);
			}
			else {
				usb_set_kbd_key(HID_M, state);
			}
		}
		else { // release all keys assigned to this button
			usb_set_kbd_key(HID_M, state);
		}
		set_matrix_key_pressed(key_M, state);
	}

	// key_COMMA
	state = matrix_get_state(key_COMMA, true);
	if (state != get_matrix_key_pressed(key_COMMA)) {
		interpret_special_key(state, HID_COMMA, 0, 0);
		set_matrix_key_pressed(key_COMMA, state);
	}

	// key_DOT
	state = matrix_get_state(key_DOT, true);
	if (state != get_matrix_key_pressed(key_DOT)) {
		interpret_special_key(state, HID_DOT, 0, 0);
		set_matrix_key_pressed(key_DOT, state);
	}

	// key_LEFT
	state = matrix_get_state(key_LEFT, true);
	if (state != get_matrix_key_pressed(key_LEFT)) {
		interpret_special_key(state, HID_LEFT, 0, 0);
		set_matrix_key_pressed(key_LEFT, state);
	}

	// key_RIGHT
	state = matrix_get_state(key_RIGHT, true);
	if (state != get_matrix_key_pressed(key_RIGHT)) {
		interpret_special_key(state, HID_RIGHT, HID_F12, 0);
		set_matrix_key_pressed(key_RIGHT, state);
	}

	// key_UP
	state = matrix_get_state(key_UP, true);
	if (state != get_matrix_key_pressed(key_UP)) {
		interpret_special_key(state, HID_UP, 0, HID_PAGEUP);
		set_matrix_key_pressed(key_UP, state);
	}

	// key_DOWN
	state = matrix_get_state(key_DOWN, true);
	if (state != get_matrix_key_pressed(key_DOWN)) {
		interpret_special_key(state, HID_DOWN, 0, HID_PAGEDOWN);
		set_matrix_key_pressed(key_DOWN, state);
	}

	// key_ENT
	state = matrix_get_state(key_ENT, true);
	if (state != get_matrix_key_pressed(key_ENT)) {
		interpret_special_key(state, HID_ENTER, 0, HID_F11);
		set_matrix_key_pressed(key_ENT, state);
	}

	// key_SPC
	state = matrix_get_state(key_SPC, true);
	if (state != get_matrix_key_pressed(key_SPC)) {
		interpret_special_key(state, HID_SPACEBAR, HID_ESCAPE, 0);
		set_matrix_key_pressed(key_SPC, state);
	}

	// key_BCKSP
	state = matrix_get_state(key_BCKSP, true);
	if (state != get_matrix_key_pressed(key_BCKSP)) {
		interpret_special_key(state, HID_BACKSPACE, HID_DELETE, 0);
		set_matrix_key_pressed(key_BCKSP, state);
	}
	
	// key_QUEST
	state = matrix_get_state(key_QUEST, true);
	if (state != get_matrix_key_pressed(key_QUEST)) {
		if (state) {
			if (read_special_key_press(PIN_FN)) {
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_SHIFT, true);
				usb_set_kbd_key(HID_PLUS, true);
				delay_ms(KEY_HOLD_DOWN);
				usb_set_kbd_key(HID_PLUS, false);
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_SHIFT, false);
			}
			else if (read_special_key_press(PIN_ALT)) {
				usb_set_kbd_key(HID_PLUS, true);
				delay_ms(KEY_HOLD_DOWN);
				usb_set_kbd_key(HID_PLUS, false);
			}
			else {
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_SHIFT, true);
				usb_set_kbd_key(HID_UNDERSCORE, true);
				delay_ms(KEY_HOLD_DOWN);
				usb_set_kbd_key(HID_UNDERSCORE, false);
				usb_set_kbd_modifier(HID_MODIFIER_RIGHT_SHIFT, false);
			}
		}
		set_matrix_key_pressed(key_QUEST, state);
	}
}