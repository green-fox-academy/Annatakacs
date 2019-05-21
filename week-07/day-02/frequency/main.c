/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

int main(void)
{
   HAL_Init();

   BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

   BSP_LED_Init(LED1);

   int counter = 1;

   int i = 1;

   while (1) {
	   if (counter < 16) {
		   if (counter % 3 == 0) {
			   i *= 2;
		   }
		   BSP_LED_On(LED1);
		   HAL_Delay(1000/i);
		   BSP_LED_Off(LED1);
		   HAL_Delay(1000/i);
		   counter++;
	   } else if (counter < 32){
		   if (counter % 3 == 0) {
			   i /= 2;
		   }
		   BSP_LED_On(LED1);
		   HAL_Delay(1000/i);
		   BSP_LED_Off(LED1);
		   HAL_Delay(1000/i);
		   counter++;
	   } else {
		   counter = 1;
	   }
   }
}
