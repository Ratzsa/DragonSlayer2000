#include "main.h"
#include <stdio.h>
#include <stdint.h>
#include "ssd1306.h"
#include "ssd1306_conf.h"
#include "ssd1306_fonts.h"
#include "ssd1306_tests.h"

void showData(uint8_t *controlData)
{
	while(1)
	{
		char dataText[5] = { 0 };
		ssd1306_Fill(Black);
		// HAL_UART_Receive(&huart1, &rxData, sizeof(rxData), 5);
		sprintf(dataText, "%d", *controlData);
		ssd1306_SetCursor(50, 10);
		ssd1306_WriteString("Test", Font_6x8, White);
		ssd1306_SetCursor(50, 30);
		ssd1306_WriteString(dataText, Font_6x8, White);

		ssd1306_UpdateScreen();
	}

}
