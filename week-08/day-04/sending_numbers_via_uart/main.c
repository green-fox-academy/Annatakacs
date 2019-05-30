#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

I2C_HandleTypeDef I2C_handle;
GPIO_InitTypeDef SCL_SDA_config;
UART_HandleTypeDef uart_handle;

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

const uint8_t digits[10][8] = {
		{ 0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e },	//0
		{ 0x04, 0x06, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0e },	//1
		{ 0x0e, 0x11, 0x10, 0x10, 0x08, 0x04, 0x02, 0x1f },	//2
		{ 0x0e, 0x11, 0x10, 0x0c, 0x10, 0x10, 0x11, 0x0e },	//3
		{ 0x10, 0x18, 0x14, 0x12, 0x11, 0x1f, 0x10, 0x10 },	//4
		{ 0x1f, 0x01, 0x01, 0x0f, 0x10, 0x10, 0x11, 0x0e },	//5
		{ 0x0e, 0x11, 0x01, 0x0f, 0x11, 0x11, 0x11, 0x0e },	//6
		{ 0x1f, 0x10, 0x10, 0x08, 0x04, 0x02, 0x02, 0x02 },	//7
		{ 0x0e, 0x11, 0x11, 0x0e, 0x11, 0x11, 0x11, 0x0e },	//8
		{ 0x0e, 0x11, 0x11, 0x11, 0x1e, 0x10, 0x11, 0x0e }	//9
};

volatile uint8_t number = '0';

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

int main (void)
{
	HAL_Init();
	SystemClock_Config();

	init_i2c();
	dot_matrix_init();
	init_uart();

	HAL_UART_Receive_IT(&uart_handle, &number, 1);

	while(1) {
		for (int i = 0; i < 8; i++) {
				HAL_I2C_Mem_Write(&I2C_handle, LED_MATRIX_ADDRESS, i * 2, I2C_MEMADD_SIZE_8BIT, &digits[number - '0'][i], 1, 100);
			}

	}
}

void USART1_IRQHandler()
{
    HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{
		HAL_UART_Receive_IT(&uart_handle, &number, 1);

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
