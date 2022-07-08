/*
 * matrix.h
 *
 * Created: 30.03.2022 09:44:56
 *  Author: Jonathan Hengstermann
 */ 


#ifndef MATRIX_H_
#define MATRIX_H_

#define MATRIX_X	11
#define MATRIX_Y	6

typedef struct matrix_key {
	uint x_pos;
	uint y_pos;
} matrix_key;

bool keysEqual(matrix_key a, matrix_key b);

//////////////////////////////////////////////////////////////////////////

void matrix_setup(void);

void matrix_update_states(void);
bool matrix_get_state(matrix_key key, bool debounced);

#endif /* MATRIX_H_ */