#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef user_button_handle;
GPIO_InitTypeDef led_pin;

void init_user_button(void)
{

    __HAL_RCC_GPIOI_CLK_ENABLE();

    user_button_handle.Pin = GPIO_PIN_11;
    user_button_handle.Pull = GPIO_NOPULL;
    user_button_handle.Speed = GPIO_SPEED_FAST;
    user_button_handle.Mode = GPIO_MODE_IT_RISING;
    HAL_GPIO_Init(GPIOI, &user_button_handle);

    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);

    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_led_pin(void)
{
	__HAL_RCC_GPIOF_CLK_ENABLE();

	led_pin.Pin = GPIO_PIN_10 | GPIO_PIN_9;
	led_pin.Mode = GPIO_MODE_OUTPUT_PP;
	led_pin.Pull = GPIO_NOPULL;
	led_pin.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOF, &led_pin);
}

int main(void)
{
    HAL_Init();

    init_user_button();
    init_led_pin();

    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);

    while (1) {

    }
}

void EXTI15_10_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
    HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
}
