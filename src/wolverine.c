#include "wolverine.h"
#include <avr/io.h>
#include <util/delay.h>

void (*setup_yellow_led)(void) = setup_yellow_led_impl;
void (*yellow_led_on)(void) = yellow_led_on_impl;
void (*yellow_led_off)(void) = yellow_led_off_impl;

void setup_yellow_led_impl()
{
    DDRD = _BV(DDD3);
}

void yellow_led_on_impl(void)
{
    PORTD = _BV(PORTD3);
}

void yellow_led_off_impl()
{
    PORTD = 0;
}

void wolverine_setup(void)
{
    setup_yellow_led();
}

void wolverine_loop(void)
{
    yellow_led_on();
    _delay_ms(1000);
    yellow_led_off();
    _delay_ms(1000);
}
