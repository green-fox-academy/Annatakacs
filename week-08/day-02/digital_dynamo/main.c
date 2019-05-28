#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

static void SystemClock_Config(void);
void Error_Handler(void);

GPIO_InitTypeDef PA15_LED_config;
GPIO_InitTypeDef user_button_handle;
TIM_HandleTypeDef timer_handle;
TIM_HandleTypeDef timer_handle_it;
TIM_OC_InitTypeDef pwm_config;

volatile uint32_t duty_cycle = 0;

void init_user_button(void)
{

    __HAL_RCC_GPIOI_CLK_ENABLE();

    user_button_handle.Pin = GPIO_PIN_11;
    user_button_handle.Pull = GPIO_NOPULL;
    user_button_handle.Speed = GPIO_SPEED_FAST;
    user_button_handle.Mode = GPIO_MODE_IT_RISING;
    HAL_GPIO_Init(GPIOI, &user_button_handle);

    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);

    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_led_pin(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();

	PA15_LED_config.Pin = GPIO_PIN_15;
	PA15_LED_config.Mode = GPIO_MODE_AF_PP;
	PA15_LED_config.Pull = GPIO_NOPULL;
	PA15_LED_config.Speed = GPIO_SPEED_HIGH;
	PA15_LED_config.Alternate = GPIO_AF1_TIM2;

	HAL_GPIO_Init(GPIOA, &PA15_LED_config);
}

void init_timer(void)
{
    __HAL_RCC_TIM2_CLK_ENABLE();

    timer_handle.Instance = TIM2;
    timer_handle.Init.Prescaler = 108 - 1;
    timer_handle.Init.Period = 100 - 1;
    timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_PWM_Init(&timer_handle);
}

void init_timer_it(void)
{
    __HAL_RCC_TIM3_CLK_ENABLE();

    timer_handle_it.Instance = TIM3;
    timer_handle_it.Init.Prescaler = 5400 - 1;;
    timer_handle_it.Init.Period = 2500 - 1;
    timer_handle_it.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer_handle_it.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_Base_Init(&timer_handle_it);

    HAL_NVIC_SetPriority(TIM3_IRQn, 2, 0);

    HAL_NVIC_EnableIRQ(TIM3_IRQn);

}

void init_PWM()
{
    pwm_config.Pulse = 50;
    pwm_config.OCMode = TIM_OCMODE_PWM1;
    pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
    pwm_config.OCFastMode = TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&timer_handle, &pwm_config, TIM_CHANNEL_1);
}


int main(void)
{
	HAL_Init();

	init_user_button();
	init_led_pin();
	init_timer();
	init_timer_it();
	init_PWM();

	HAL_TIM_Base_Start_IT(&timer_handle_it);

	HAL_TIM_PWM_Start(&timer_handle, TIM_CHANNEL_1);

	while(1) {
		__HAL_TIM_SET_COMPARE(&timer_handle, TIM_CHANNEL_1, duty_cycle);
	}
}

void EXTI15_10_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (duty_cycle < 100) {
		duty_cycle += 10;
	}
}

void TIM3_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&timer_handle_it);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM3) {
    	if (duty_cycle > 0) {
    		duty_cycle -= 5;
    	} else {
    		duty_cycle = 0;
    	}
    }
}

void Error_Handler(void)
{
}

void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct =
	{ 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct =
	{ 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}
