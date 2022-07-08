/*
 * matrix.c
 *
 * Created: 30.03.2022 09:45:39
 *  Author: Jonathan Hengstermann
 */

#include <asf.h>

#include "matrix.h"

#include "system_time.h"

#define DEBOUNCE_TIME	35

#define PIN_SIG_0	PIN_PA15
#define PIN_SIG_1	PIN_PA12
#define PIN_SIG_2	PIN_PA06
#define PIN_SIG_3	PIN_PA05
#define PIN_SIG_4	PIN_PB03
#define PIN_SIG_5	PIN_PB02

#define PIN_READ_00 PIN_PA07
#define PIN_READ_01 PIN_PA09
#define PIN_READ_02 PIN_PA08
#define PIN_READ_03 PIN_PA10
#define PIN_READ_04 PIN_PA11
#define PIN_READ_05 PIN_PB15
#define PIN_READ_06 PIN_PB14
#define PIN_READ_07 PIN_PB13
#define PIN_READ_08 PIN_PB12
#define PIN_READ_09 PIN_PA14
#define PIN_READ_10 PIN_PA13

bool keysEqual(matrix_key a, matrix_key b) {
	if (a.x_pos == b.x_pos && a.y_pos == b.y_pos) {
		return true;
	}
	
	return false;
}

//////////////////////////////////////////////////////////////////////////


bool buttons_unbounced[MATRIX_X][MATRIX_Y];
bool buttons_debounced[MATRIX_X][MATRIX_Y];

// vars for debouncing
uint32_t lastUpdateTime[MATRIX_X][MATRIX_Y];


void matrix_setup(void)  {
	struct port_config config_port_pin;
	port_get_config_defaults(&config_port_pin);
		
	// Output pins
	config_port_pin.direction = PORT_PIN_DIR_INPUT;
	port_pin_set_config(PIN_SIG_0, &config_port_pin);
	port_pin_set_config(PIN_SIG_1, &config_port_pin);
	port_pin_set_config(PIN_SIG_2, &config_port_pin);
	port_pin_set_config(PIN_SIG_3, &config_port_pin);
	port_pin_set_config(PIN_SIG_4, &config_port_pin);
	port_pin_set_config(PIN_SIG_5, &config_port_pin);
		
	// Output pins
	config_port_pin.direction = PORT_PIN_DIR_OUTPUT;
	port_pin_set_config(PIN_READ_00, &config_port_pin);
	port_pin_set_config(PIN_READ_01, &config_port_pin);
	port_pin_set_config(PIN_READ_02, &config_port_pin);
	port_pin_set_config(PIN_READ_03, &config_port_pin);
	port_pin_set_config(PIN_READ_04, &config_port_pin);
	port_pin_set_config(PIN_READ_05, &config_port_pin);
	port_pin_set_config(PIN_READ_06, &config_port_pin);
	port_pin_set_config(PIN_READ_07, &config_port_pin);
	port_pin_set_config(PIN_READ_08, &config_port_pin);
	port_pin_set_config(PIN_READ_09, &config_port_pin);
	port_pin_set_config(PIN_READ_10, &config_port_pin);
	port_pin_set_output_level(PIN_READ_00, true);
	port_pin_set_output_level(PIN_READ_01, true);
	port_pin_set_output_level(PIN_READ_02, true);
	port_pin_set_output_level(PIN_READ_03, true);
	port_pin_set_output_level(PIN_READ_04, true);
	port_pin_set_output_level(PIN_READ_05, true);
	port_pin_set_output_level(PIN_READ_06, true);
	port_pin_set_output_level(PIN_READ_07, true);
	port_pin_set_output_level(PIN_READ_08, true);
	port_pin_set_output_level(PIN_READ_09, true);
	port_pin_set_output_level(PIN_READ_10, true);
		
	for (int i = 0; i<MATRIX_X; i++) {
		for (int j = 0; j<MATRIX_Y; j++) {
			buttons_unbounced[i][j] = false;
			buttons_debounced[i][j]	= false;
			lastUpdateTime[i][j]	= 0;
		}	
	}
}

static void read_line(uint8_t signal_pin, uint8_t arrayIndex) {
	port_pin_set_output_level(signal_pin, false);
	
	buttons_unbounced[arrayIndex][0]	= !port_pin_get_input_level(PIN_SIG_0);
	buttons_unbounced[arrayIndex][1]	= !port_pin_get_input_level(PIN_SIG_1);
	buttons_unbounced[arrayIndex][2]	= !port_pin_get_input_level(PIN_SIG_2);
	buttons_unbounced[arrayIndex][3]	= !port_pin_get_input_level(PIN_SIG_3);
	buttons_unbounced[arrayIndex][4]	= !port_pin_get_input_level(PIN_SIG_4);
	buttons_unbounced[arrayIndex][5]	= !port_pin_get_input_level(PIN_SIG_5);
	
	port_pin_set_output_level(signal_pin, true);
}



static void debounceBtn(uint x, uint y) {
	if (millis() - DEBOUNCE_TIME < lastUpdateTime[x][y]) {
		return;
	}
	
	if (buttons_unbounced[x][y] != buttons_debounced[x][y]) {
		buttons_debounced[x][y] = buttons_unbounced[x][y];
		lastUpdateTime[x][y] = millis();
	}
	
	
	// test solution
	// buttons_debounced[x][y] = buttons_unbounced[x][y];
}

void matrix_update_states(void) {
	read_line(PIN_READ_00, 0);
	read_line(PIN_READ_01, 1);
	read_line(PIN_READ_02, 2);
	read_line(PIN_READ_03, 3);
	read_line(PIN_READ_04, 4);
	read_line(PIN_READ_05, 5);
	read_line(PIN_READ_06, 6);
	read_line(PIN_READ_07, 7);
	read_line(PIN_READ_08, 8);
	read_line(PIN_READ_09, 9);
	read_line(PIN_READ_10, 10);
	
	
	for (int i = 0; i < MATRIX_X; i++) {
		for (int j = 0; j < MATRIX_Y; j++) {
			debounceBtn(i, j);
		}
	}	
}

bool matrix_get_state(matrix_key key, bool debounced) {
	if (key.x_pos >= MATRIX_X || key.y_pos>= MATRIX_Y) {
		return false;
	}
	
	if (debounced) {
		return buttons_debounced[key.x_pos][key.y_pos];
	}
	else {
		return buttons_unbounced[key.x_pos][key.y_pos];
	}
}