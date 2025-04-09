/*
 * ui.c
 *
 *  Created on: Apr 8, 2025
 *      Author: ihsan
 */

/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "ui.h"
#include "use_printf.h"

/* PRIVATE FUNCTION DECLARATIONS */
static void _ui_print_data(const uint8_t data);
static void _ui_print_sweep_l_to_r(void);
static void _ui_print_sweep_r_to_l(void);
static void _ui_x_sweep(void);

static void _ui_reset(void);

/* PRINT MESSAGE */
void ui_print_message(const char *const p_message, const size_t len) {
	if (p_message == NULL) {
		printf("[ERR] No message provided to print.\r\n");
	} else {
		_ui_print_sweep_r_to_l();
		_ui_x_sweep();
		_ui_x_sweep();
		_ui_print_sweep_l_to_r();

		HAL_Delay(300);
		for (size_t i = 0; i < len; i++) {
			_ui_print_data(p_message[i]);
			HAL_Delay(UI_CHAR_DISPLAY_TIME);
		}
	}

}

/* PRINT A CHAR */

void _ui_print_data(const uint8_t data) {
	HAL_GPIO_WritePin(GPIOB, MSG_BIT_0_Pin, (data & (1 << 0)) ? 0 : 1);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_1_Pin, (data & (1 << 1)) ? 0 : 1);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_2_Pin, (data & (1 << 2)) ? 0 : 1);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_3_Pin, (data & (1 << 3)) ? 0 : 1);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_4_Pin, (data & (1 << 4)) ? 0 : 1);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_5_Pin, (data & (1 << 5)) ? 0 : 1);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_6_Pin, (data & (1 << 6)) ? 0 : 1);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_7_Pin, (data & (1 << 7)) ? 0 : 1);
}

/* Print sweep */
void _ui_print_sweep_r_to_l(void) {

	_ui_reset();

	HAL_GPIO_WritePin(GPIOB, MSG_BIT_0_Pin, GPIO_PIN_RESET);
	HAL_Delay(UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOB, MSG_BIT_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_1_Pin, GPIO_PIN_RESET);
	HAL_Delay(UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_2_Pin, GPIO_PIN_RESET);
	HAL_Delay(UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_3_Pin, GPIO_PIN_RESET);
	HAL_Delay(UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_4_Pin, GPIO_PIN_RESET);
	HAL_Delay(UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_5_Pin, GPIO_PIN_RESET);
	HAL_Delay(UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_6_Pin, GPIO_PIN_RESET);
	HAL_Delay(UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_6_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_7_Pin, GPIO_PIN_RESET);
	HAL_Delay(UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_7_Pin, GPIO_PIN_SET);

	_ui_reset();

}
void _ui_print_sweep_l_to_r(void) {

	_ui_reset();

	HAL_GPIO_WritePin(GPIOA, MSG_BIT_7_Pin, GPIO_PIN_RESET);
	HAL_Delay(UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_7_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_6_Pin, GPIO_PIN_RESET);
	HAL_Delay(UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_6_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_5_Pin, GPIO_PIN_RESET);
	HAL_Delay(UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_4_Pin, GPIO_PIN_RESET);
	HAL_Delay(UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_3_Pin, GPIO_PIN_RESET);
	HAL_Delay(UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_2_Pin, GPIO_PIN_RESET);
	HAL_Delay(UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_1_Pin, GPIO_PIN_RESET);
	HAL_Delay(UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, MSG_BIT_0_Pin, GPIO_PIN_RESET);
	HAL_Delay(UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOB, MSG_BIT_0_Pin, GPIO_PIN_SET);

	_ui_reset();

}

void _ui_x_sweep(void) {
	_ui_reset();

	HAL_GPIO_WritePin(GPIOA, MSG_BIT_7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, MSG_BIT_0_Pin, GPIO_PIN_RESET);
	HAL_Delay(2 * UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_7_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, MSG_BIT_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_1_Pin, GPIO_PIN_RESET);
	HAL_Delay(2 * UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_6_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_2_Pin, GPIO_PIN_RESET);
	HAL_Delay(2 * UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_4_Pin, GPIO_PIN_RESET);
	HAL_Delay(2 * UI_SWEEP_DELAY);
	HAL_Delay(2 * UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_2_Pin, GPIO_PIN_RESET);
	HAL_Delay(2 * UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_1_Pin, GPIO_PIN_RESET);
	HAL_Delay(2 * UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_6_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, MSG_BIT_0_Pin, GPIO_PIN_RESET);
	HAL_Delay(2 * UI_SWEEP_DELAY);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_7_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, MSG_BIT_0_Pin, GPIO_PIN_SET);

	_ui_reset();

}

/* Reset ui */
void _ui_reset(void) {
	HAL_GPIO_WritePin(GPIOB, MSG_BIT_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_4_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_6_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, MSG_BIT_7_Pin, GPIO_PIN_SET);
}
