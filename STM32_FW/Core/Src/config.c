/*
 * config.c
 *
 *  Created on: Apr 10, 2025
 *      Author: ihsan
 */


/* INCLUDES */
#include <stdint.h>

/* PRIVATE VARIABLES */
uint8_t _debug_level = 0;

/* API */
uint8_t debug_level(void){
	return _debug_level;
}
