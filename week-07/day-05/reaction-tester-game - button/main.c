#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include <stdio.h>

GPIO_InitTypeDef user_button_handle;
RNG_HandleTypeDef random_number;

static void Error_Handler(void);
static void SystemClock_Config(void);

volatile uint32_t start_time;
volatile uint32_t reaction_time;

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

void LCD_init()
{
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
	BSP_LCD_SelectLayer(1);
	BSP_LCD_Clear(LCD_COLOR_WHITE);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font24);
	BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
}

void init_time_delay(void)
{
	__HAL_RCC_RNG_CLK_ENABLE();
	random_number.Instance = RNG;
	HAL_RNG_Init(&random_number);
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	LCD_init();
	init_user_button();
	init_time_delay();

	BSP_LCD_DisplayStringAt(50, 50, "Reaction test game:", LEFT_MODE);
	HAL_Delay(3000);
	BSP_LCD_Clear(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font20);
	BSP_LCD_DisplayStringAt(50, 50, "Push the button, when a", LEFT_MODE);
	BSP_LCD_DisplayStringAt(50, 100, "circle appears on the screen", LEFT_MODE);
	HAL_Delay(3000);
	BSP_LCD_Clear(LCD_COLOR_WHITE);

	int counter = 0;

	uint32_t time_delay = (HAL_RNG_GetRandomNumber(&random_number) % 10000);

	while (1) {
		while(counter < 1) {
			HAL_Delay(time_delay);
			BSP_LCD_SetTextColor(LCD_COLOR_RED);
			BSP_LCD_FillCircle(250, 150, 30);
			start_time = HAL_GetTick();
			HAL_Delay(20);
			BSP_LCD_Clear(LCD_COLOR_WHITE);
			HAL_Delay(2000);
			counter++;
			char charbuffer[40];
			sprintf(charbuffer, "Your reaction time is: %lu ms", reaction_time);
			BSP_LCD_DisplayStringAt(50, 100, (uint8_t *) charbuffer, LEFT_MODE);
		}
	}
}

void EXTI15_10_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	reaction_time = (HAL_GetTick() - start_time);

}


static void Error_Handler(void)
{

}

static void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct =
	{ 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct =
	{ 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
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
