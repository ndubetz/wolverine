#include "wolverine.h"
#include <avr/io.h>

void (*setup_yellow_led)(void) = setup_yellow_led_impl;

void setup_yellow_led_impl()
{
    DDRD = _BV(DDD3);
}

void yellow_led_on(void)
{
    PORTD = _BV(PORTD3);
}

void wolverine_setup(void) 
{
    setup_yellow_led();
}

void wolverine_loop(void) {}
