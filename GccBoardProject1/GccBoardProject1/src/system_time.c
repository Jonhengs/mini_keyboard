/*
 * system_time.c
 *
 * Created: 04.04.2022 17:49:24
 *  Author: Jonathan Hengstermann
 */ 

#include <asf.h>

#include "system_time.h"

volatile uint32_t millis_counter = 0;

// System interupt
void SysTick_Handler(void)
{
	millis_counter++;
}

void init_timing(void) {
	if (SysTick_Config( system_gclk_gen_get_hz(GCLK_GENERATOR_0) / 1000) )
	{
		while (1) {
			// error
		}
	}
}

uint32_t millis(void) {
	return millis_counter;
}

