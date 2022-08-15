/*
 * APP.h
 *
 *  Created on: Jun 16, 2022
 *      Author: Masoud
 */

#ifndef INC_APP_H_
#define INC_APP_H_

#include "main.h"

#include <stdbool.h>

// MENU ----------------------------------------------
#define MENU_LIST_LEN 4
#define MENU_OPTION_PER_PAGE 2

extern char MENU_LIST[MENU_LIST_LEN][16];

int _menuDisplayPointer;
int _menuChoice;

void APP_init(void);

void APP_menuInit(void);
void APP_lcdMenuUpdate(void);
void APP_menuNextOption(void);
void APP_menuSelectOption(void);

// END MENU --------------------------------------------

// UART ------------------------------------
extern UART_HandleTypeDef huart1;
#define APP_UART &huart1

extern char _rx[1];
extern bool _rxFlag;

void APP_UARTInit(void);
void APP_UARTMenuSelect(void);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

// END UART --------------------------------

// DAC & Timer ------------------------------------------
extern int _DACPointer;
extern TIM_HandleTypeDef htim3;
extern DAC_HandleTypeDef hdac;

#define APP_Timer &htim3
#define APP_DAC &hdac

void APP_waveInit(void);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
// END DAC & Timer --------------------------------------

#endif /* INC_APP_H_ */
