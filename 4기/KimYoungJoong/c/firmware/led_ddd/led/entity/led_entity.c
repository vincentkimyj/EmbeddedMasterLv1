#include <stdio.h>
#include <stdlib.h>

#include "led_entity.h"



void led_init (uint8_t port, uint8_t pin, uint8_t command, uint8_t sub_order)
{

}

/*  pb 0~7
    pc 0~6
    pd 0~7
    total   8 + 8 + 7 = 22*/
void malloc_led_entitiy(void)
{
    led_stat = (led*)malloc(sizeof(led) * led_num);
    if(led_stat == NULL)
    {
        printf("led entity malloc fail\r\n");
    }

    gpio_vo = (gpio*)malloc(sizeof(gpio) * ATMEGA328_GPIO_TOTAL_GPIO);
    led_stat->gpio_vo = gpio_vo;
    if(led_stat == NULL)
    {
        printf("gpio entity malloc fail\r\n");
    }
}


