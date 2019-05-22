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

int main(void) {

	HAL_Init();

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN; /* GPIOI clock enable */

	// Init user led (PF10)
	GPIOF->MODER |= (GPIO_MODER_MODER10_0); /* configure PI1 in output mode */
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_10); /* ensure push pull mode selected default */
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR10); /* ensure maximum speed setting (even though it is unnecessary) */
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR10); /* ensure all pull up pull down resistors are disabled */

	// Init user led (PF10)
	GPIOF->MODER |= (GPIO_MODER_MODER9_0); /* configure PI1 in output mode */
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_9); /* ensure push pull mode selected default */
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR9); /* ensure maximum speed setting (even though it is unnecessary) */
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR9); /* ensure all pull up pull down resistors are disabled */


	// Init user led (PF10)
	GPIOF->MODER |= (GPIO_MODER_MODER8_0); /* configure PI1 in output mode */
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_8); /* ensure push pull mode selected default */
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR8); /* ensure maximum speed setting (even though it is unnecessary) */
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR8); /* ensure all pull up pull down resistors are disabled */


	// Init user led (PF10)
	GPIOF->MODER |= (GPIO_MODER_MODER7_0); /* configure PI1 in output mode */
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_7); /* ensure push pull mode selected default */
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR7); /* ensure maximum speed setting (even though it is unnecessary) */
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR7); /* ensure all pull up pull down resistors are disabled */

	while (1) {
		int a = 10;
		for	(int i = 0; i < 7; i++) {
		uint32_t red_led = (1 << a);
		GPIOF->BSRR = red_led;
		HAL_Delay(70);
		GPIOF->BSRR = red_led << 16;
			if (a > 7 && i < 4) {
				a -= 1;
			} else {
					a += 1;
				}
			}
		}
}


