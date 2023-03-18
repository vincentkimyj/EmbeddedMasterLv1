#ifndef     __LED_ENTITY_H__
#define     __LED_ENTITY_H__
#include <stdio.h>
#include <stdlib.h>

#define     led_num     22
#define     ATMEGA328_GPIO_TOTAL_GPIO   22

enum pin_status {
LED_OFF = 0,
LED_ON = 1,
PIN_OHTER = 2
};

typedef struct _led led;
typedef struct _gpio gpio;

struct _led
{
    uint8_t led_status;
    gpio *gpio_vo;
};

struct _gpio
{
    uint8_t led_port;
    uint8_t led_pin;
};
led *led_stat;
gpio *gpio_vo;



#endif
