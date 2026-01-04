#include <stdio.h>

/* 结构体指针，模仿STM32标准库代码 */
typedef struct {
    int GPIO_PIN;
    int GPIO_SPEED;
} GPIO_InitTypeDef;

void GPIO_Init(GPIO_InitTypeDef *gpio); 

int main()
{
    GPIO_InitTypeDef GPIO_InitStruct;

    GPIO_InitStruct.GPIO_PIN = 12;
    GPIO_InitStruct.GPIO_SPEED = 500;

    GPIO_Init(&GPIO_InitStruct);

    return 0;
}

void GPIO_Init(GPIO_InitTypeDef *gpio)
{
    printf("Pin is %d.\nSpeed is %d.\n", gpio->GPIO_PIN, gpio->GPIO_SPEED);
}