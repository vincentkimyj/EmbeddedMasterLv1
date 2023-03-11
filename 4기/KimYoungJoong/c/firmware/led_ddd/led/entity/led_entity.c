#include <stdio.h>
#include <stdlib.h>

#include "led_entity.h"

void malloc_led_entitiy(void)
{
    led_stat = (led*)malloc(sizeof(led) * led_num);
}
