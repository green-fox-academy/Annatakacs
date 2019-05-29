#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


UART_HandleTypeDef uart_handle;

volatile uint8_t buffer = 0;
volatile uint8_t *string = "Secret data \r\n";
volatile uint8_t *new_string;

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

    HAL_NVIC_SetPriority(USART1_IRQn, 8, 0);

    HAL_NVIC_EnableIRQ(USART1_IRQn);
}

int main(void)
{
	HAL_Init();
	init_uart();

	new_string = calloc (1, 1);

	HAL_UART_Receive_IT(&uart_handle, &buffer, 1);

	while(1) {
		HAL_UART_Transmit(&uart_handle, (uint8_t*) string, strlen(string), 0xFFFF);
		printf("%s\r\n", new_string);
		HAL_Delay(1000);
	}

	free(new_string);
}

void USART1_IRQHandler()
{
    HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{
    if (huart->Instance == USART1) {

    	uint32_t length = strlen(new_string);
    	new_string = (char *) realloc (new_string, length + 2);
    	new_string[length] = buffer;
    	new_string[length + 1] = '\0';

    	HAL_UART_Receive_IT(&uart_handle, &new_string, strlen(string));
    }
}

