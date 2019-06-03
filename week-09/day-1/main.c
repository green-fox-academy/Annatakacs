#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef gpio_adc_pin;
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_channel_config;
GPIO_InitTypeDef PA15_LED_config;
TIM_HandleTypeDef timer_handle_PWM;
TIM_HandleTypeDef timer_handle_FREQ;
TIM_OC_InitTypeDef pwm_config;
UART_HandleTypeDef uart_handle;
GPIO_InitTypeDef user_button_handle;

#define UART_PUTCHAR int __io_putchar(int ch)

static void SystemClock_Config(void);
void Error_Handler(void);

typedef enum {
	BRIGHTNESS,
	FREQUENCY
} mode_t;

mode_t mode = BRIGHTNESS;

volatile uint8_t last_data = 0;
volatile uint8_t freq = 5;
volatile uint8_t state = 0;
volatile uint8_t counter = 0;

void init_user_button(void)
{
    /* enable the GPIOI clock */
    __HAL_RCC_GPIOI_CLK_ENABLE();

    user_button_handle.Pin = GPIO_PIN_11;
    user_button_handle.Pull = GPIO_NOPULL;	// the user button has a built-in resistor
    user_button_handle.Speed = GPIO_SPEED_FAST;
    user_button_handle.Mode = GPIO_MODE_IT_RISING;
    HAL_GPIO_Init(GPIOI, &user_button_handle);

    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 3, 0);

    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

void init_uart()
{
    __HAL_RCC_USART1_CLK_ENABLE();

    uart_handle.Instance = USART1;
    uart_handle.Init.BaudRate = 115200;
    uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
    uart_handle.Init.StopBits = UART_STOPBITS_1;
    uart_handle.Init.Parity = UART_PARITY_NONE;
    uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uart_handle.Init.Mode = UART_MODE_TX_RX;

    BSP_COM_Init(COM1, &uart_handle);
}

void init_timer()
{
    __HAL_RCC_TIM2_CLK_ENABLE();

    timer_handle_PWM.Instance = TIM2;
    timer_handle_PWM.Init.Prescaler = 108 - 1;
    timer_handle_PWM.Init.Period = 100 - 1;
    timer_handle_PWM.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer_handle_PWM.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_PWM_Init(&timer_handle_PWM);
}


void init_timer_frequency(void)
{
    __HAL_RCC_TIM3_CLK_ENABLE();

    timer_handle_FREQ.Instance = TIM3;
    timer_handle_FREQ.Init.Prescaler = 10800 - 1; // 108000000/54000=2000 -> speed of 1 count-up: 1/2000 sec = 0.5 ms
    timer_handle_FREQ.Init.Period = 1000 - 1; // 2000 x 0.5 ms = 1 second period
    timer_handle_FREQ.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer_handle_FREQ.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_Base_Init(&timer_handle_FREQ);

    HAL_NVIC_SetPriority(TIM3_IRQn, 2, 0);

    HAL_NVIC_EnableIRQ(TIM3_IRQn);
}


void init_PWM()
{
    pwm_config.Pulse = 50;
    pwm_config.OCMode = TIM_OCMODE_PWM1;
    pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
    pwm_config.OCFastMode = TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&timer_handle_PWM, &pwm_config, TIM_CHANNEL_1);
}

void init_LED()
{
    __HAL_RCC_GPIOA_CLK_ENABLE();

    PA15_LED_config.Pin = GPIO_PIN_15;
    PA15_LED_config.Mode = GPIO_MODE_AF_PP;
    PA15_LED_config.Pull = GPIO_NOPULL;
    PA15_LED_config.Speed = GPIO_SPEED_HIGH;
    PA15_LED_config.Alternate = GPIO_AF1_TIM2;  /* we need this alternate function to use TIM2 in OC mode */

    HAL_GPIO_Init(GPIOA, &PA15_LED_config);
}

void init_adc()
{
    /* configuring A0 pin as analog input */
    __HAL_RCC_GPIOA_CLK_ENABLE();
	/* there is no need for setting the Alternate datafield like other peripherals*/
    gpio_adc_pin.Mode = GPIO_MODE_ANALOG;
    gpio_adc_pin.Pin = GPIO_PIN_0;
    gpio_adc_pin.Speed = GPIO_SPEED_FAST;
    gpio_adc_pin.Pull = GPIO_NOPULL;

    HAL_GPIO_Init(GPIOA, &gpio_adc_pin);

    /* configuring ADC3, as it is the only ADC wired out to the headers */
    __HAL_RCC_ADC3_CLK_ENABLE();
    adc_handle.Instance = ADC3;
    adc_handle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
    adc_handle.Init.Resolution = ADC_RESOLUTION_12B;

    /* these 5 settings are closely related */
    adc_handle.Init.ScanConvMode = DISABLE;
    adc_handle.Init.ContinuousConvMode = DISABLE;
    adc_handle.Init.DiscontinuousConvMode = DISABLE;
    adc_handle.Init.EOCSelection = ADC_EOC_SEQ_CONV;
    adc_handle.Init.NbrOfDiscConversion = 1;

    HAL_ADC_Init(&adc_handle);

    /* configuring a channel belonging to ADC3 */
    adc_channel_config.Channel = ADC_CHANNEL_0;
    adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;

    HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_config);
}
int main(void)
{
    HAL_Init();
    SystemClock_Config();

    init_uart();
    init_adc();
    init_LED();
    init_timer();
    init_timer_frequency();
    init_PWM();
    init_user_button();

    HAL_TIM_Base_Start_IT(&timer_handle_FREQ);

    HAL_TIM_PWM_Start(&timer_handle_PWM, TIM_CHANNEL_1);

    int adc_val;
    float percent;

    while (1) {
        HAL_ADC_Start(&adc_handle);
        if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK) {
            adc_val = HAL_ADC_GetValue(&adc_handle);
            percent = (adc_val / 4095.0) * 100;

            if (mode == BRIGHTNESS && state) {
                __HAL_TIM_SET_COMPARE(&timer_handle_PWM, TIM_CHANNEL_1, percent);
            } else if (mode == FREQUENCY && state){
                __HAL_TIM_SET_COMPARE(&timer_handle_PWM, TIM_CHANNEL_1, last_data);
               freq = 20 - percent / 5;
            }
        }
    }
}

void EXTI15_10_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (mode == BRIGHTNESS) {
    	mode = FREQUENCY;
    	last_data = (HAL_ADC_GetValue(&adc_handle) / 4095.0) * 100;
    } else if (mode == FREQUENCY) {
    	mode = BRIGHTNESS;
    }
}


void TIM3_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&timer_handle_FREQ);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM3) {
    	counter++;
    	if (counter >= freq){
    	      counter = 0;
    	      state = !state;
    	    }

    	    if (!state){
    	      __HAL_TIM_SET_COMPARE(&timer_handle_PWM, TIM_CHANNEL_1, 0);
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

UART_PUTCHAR
{
    HAL_UART_Transmit(&uart_handle, (uint8_t*)&ch, 1, 0xFFFF);
    return ch;
}
