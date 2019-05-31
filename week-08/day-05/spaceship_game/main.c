#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

I2C_HandleTypeDef I2C_handle;
GPIO_InitTypeDef SCL_SDA_config;
UART_HandleTypeDef uart_handle;
RNG_HandleTypeDef random_number;
TIM_HandleTypeDef timer_handle;

#define LED_MATRIX_ADDRESS  (0b1110000 << 1)

#define SYSTEM_SETUP_REGISTER 0x20
#define ROW_INT_SET_REGISTER 0xA0
#define DISPLAY_SETUP_REGISTER 0x80

#define NORMAL_MODE (1 << 0)
#define OUTPUT_MODE (0 << 0)
#define DISPLAY_ON_BLINK_OFF (1 << 0)

uint8_t normal_mode = (NORMAL_MODE | SYSTEM_SETUP_REGISTER);
uint8_t output_mode = (ROW_INT_SET_REGISTER | OUTPUT_MODE);
uint8_t display_on_blink_off = (DISPLAY_SETUP_REGISTER | DISPLAY_ON_BLINK_OFF);

static void SystemClock_Config(void);
static void Error_Handler(void);

const uint8_t starting_position = 0b10000011;
const uint8_t clear = 0b00000000;
volatile uint8_t number = 0;
volatile uint8_t input;
volatile uint8_t moving = 0b10000011;
volatile uint8_t random_position;
volatile int row = 16;

void dot_matrix_init()
{
	HAL_I2C_Master_Transmit(&I2C_handle, LED_MATRIX_ADDRESS, &normal_mode, 1, 100);
	HAL_I2C_Master_Transmit(&I2C_handle, LED_MATRIX_ADDRESS, &output_mode, 1, 100);
	HAL_I2C_Master_Transmit(&I2C_handle, LED_MATRIX_ADDRESS, &display_on_blink_off, 1, 100);
}

void init_i2c()
{
	__HAL_RCC_GPIOB_CLK_ENABLE();
	SCL_SDA_config.Pin         = GPIO_PIN_8 | GPIO_PIN_9;
	SCL_SDA_config.Pull        = GPIO_PULLUP;
	SCL_SDA_config.Mode        = GPIO_MODE_AF_OD;
	SCL_SDA_config.Alternate   = GPIO_AF4_I2C1;
	HAL_GPIO_Init(GPIOB, &SCL_SDA_config);

	__HAL_RCC_I2C1_CLK_ENABLE();

	I2C_handle.Instance             = I2C1;
	I2C_handle.Init.Timing          = 0x40912732;
	I2C_handle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;

	HAL_I2C_Init(&I2C_handle);
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

    HAL_NVIC_SetPriority(USART1_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);

}

void init_timer(void)
{
	 __HAL_RCC_TIM2_CLK_ENABLE();

	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 10800 - 1; // 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms
	timer_handle.Init.Period = 10000 - 1; // 10000 x 0.1 ms = 1 second period
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&timer_handle);

	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);

    HAL_NVIC_EnableIRQ(TIM2_IRQn);

}

void create_random_barrier(void)
{
	__HAL_RCC_RNG_CLK_ENABLE();
	random_number.Instance = RNG;
	HAL_RNG_Init(&random_number);

	uint32_t random_barrier = (HAL_RNG_GetRandomNumber(&random_number) % 7);
	if (random_barrier == 0) {
		random_position = 0b10000000;
	} else {
		random_position = (1 << random_barrier);
	}
	HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, row, I2C_MEMADD_SIZE_8BIT, &random_position, 1, 100);
}

void beginning_of_the_game()
{
	HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, 14, I2C_MEMADD_SIZE_8BIT, &clear, 1, 100);
	HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, 12, I2C_MEMADD_SIZE_8BIT, &clear, 1, 100);
	HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, 10, I2C_MEMADD_SIZE_8BIT, &clear, 1, 100);
	HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, 8, I2C_MEMADD_SIZE_8BIT, &clear, 1, 100);
	HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, 6, I2C_MEMADD_SIZE_8BIT, &clear, 1, 100);
	HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, 4, I2C_MEMADD_SIZE_8BIT, &clear, 1, 100);
	HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, 2, I2C_MEMADD_SIZE_8BIT, &clear, 1, 100);
	HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, 0, I2C_MEMADD_SIZE_8BIT, &starting_position, 1, 100);
}


int main (void)
{
	HAL_Init();
	SystemClock_Config();

	init_i2c();
	dot_matrix_init();
	init_uart();
	beginning_of_the_game();
	init_timer();
	create_random_barrier();

	HAL_TIM_Base_Start_IT(&timer_handle);
	HAL_UART_Receive_IT(&uart_handle, &input, 1);

	while(1) {

		HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, 0, I2C_MEMADD_SIZE_8BIT, &clear, 1, 100);
		HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, 0, I2C_MEMADD_SIZE_8BIT, &moving, 1, 100);

		if (row > 0) {
			HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, (row + 2), I2C_MEMADD_SIZE_8BIT, &clear, 1, 100);
			HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, row, I2C_MEMADD_SIZE_8BIT, &random_position, 1, 100);
		} else {
		    HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, 2, I2C_MEMADD_SIZE_8BIT, &clear, 1, 100);
		    HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, 0, I2C_MEMADD_SIZE_8BIT, &moving, 1, 100);
		    create_random_barrier();
		    row = 16;
		}
	}
}

void USART1_IRQHandler()
{
    HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{
	if (input == 'a' && number < 5) {
		moving = (starting_position << (number + 1)) | (1 << number);
		number++;
	}
	if (input == 'd' && number > 0) {
		number--;
		moving = (starting_position << (number + 1)) | (1 << number);
	} else if (input == 'd' && number == 0) {
		moving = starting_position;
	}
	HAL_UART_Receive_IT(&uart_handle, &input, 1);
}

void TIM2_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2) {
        if (row > 0) {
        	row -= 2;
        } else {
        	HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, 0, I2C_MEMADD_SIZE_8BIT, &clear, 1, 100);
        	HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, 0, I2C_MEMADD_SIZE_8BIT, &moving, 1, 100);
        }
    }

}

static void Error_Handler(void)
{
}

static void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

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

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    /**Activate the Over-Drive mode */
    if (HAL_PWREx_EnableOverDrive() != HAL_OK)
    {
        Error_Handler();
    }

    /**Initializes the CPU, AHB and APB busses clocks */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
    {
        Error_Handler();
    }
}
