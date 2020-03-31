#include <avr/io.h>
#include <util/delay.h>

#include "wolverine.h"

void (*set_led)(bool) = set_led_impl;

void wolverine_setup(void) {
    DDRD |= _BV(DDD2);
}

void wolverine_loop(void) {
    set_led(true);
    set_led(false);
}

void set_led_impl(bool on_off) {
    _delay_ms(500);
    if(on_off){
        PORTD |= _BV(BLUE_LED);
    }
    else{
        PORTD &= ~_BV(BLUE_LED);
    }
}