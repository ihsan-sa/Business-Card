/*
 * ui.h
 *
 *  Created on: Apr 8, 2025
 *      Author: ihsan
 */

#ifndef SRC_UI_H_
#define SRC_UI_H_

/* INCLUDES */
#include <stdint.h>

/* MACROS */
#define UI_CHAR_DISPLAY_TIME 900
#define UI_SWEEP_DELAY 20

/* PRINT MESSAGE */

void ui_print_message(const char *const p_message, const size_t len);

#endif /* SRC_UI_H_ */
