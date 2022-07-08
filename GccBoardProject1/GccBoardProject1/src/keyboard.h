/*
 * keyboard.h
 *
 * Created: 30.03.2022 12:28:38
 *  Author: Jonathan Hengstermann
 */ 


#ifndef KEYBOARD_H_
#define KEYBOARD_H_

void keyboard_init(void);
void keyboard_update(void);

// For testing
void keyboard_send(uint8_t key);

bool keyboard_set_kbd_enabled(void);
void keyboard_set_kbd_disabled(void);

#endif /* KEYBOARD_H_ */