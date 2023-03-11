#ifndef     __LED_ENTITY_H__
#define     __LED_ENTITY_H__
#include <stdio.h>
#include <stdlib.h>

#define     led_num     1

typedef struct _led led;
struct _led
{
    uint8_t led_port;
    uint8_t led_pin;
    uint8_t led_status;
};

led *led_stat;



#endif
