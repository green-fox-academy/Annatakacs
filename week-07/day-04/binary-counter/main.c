#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef led_pin;


void init_led_pin(void)
{
	__HAL_RCC_GPIOF_CLK_ENABLE();

	led_pin.Pin = ( GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8 | GPIO_PIN_7 );
	led_pin.Mode = GPIO_MODE_OUTPUT_PP;
	led_pin.Pull = GPIO_NOPULL;
	led_pin.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOF, &led_pin);
}

int main(void)
{
    HAL_Init();

    init_led_pin();

    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);

    int counter = 0;

    while (1) {
    	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, counter % 2);
    	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, (counter >> 1) % 2);
    	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, (counter >> 2) % 2);
    	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, (counter >> 3) % 2);

    	HAL_Delay(500);

    	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
    	counter = (counter + 1) % 16;
    }
}

