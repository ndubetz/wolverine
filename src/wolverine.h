#ifndef WOLVERINE_H
#define WOLVERINE_H

#include <stdbool.h>

#define BLUE_LED PORTD2
#define YELLOW_LED PORTD3

void wolverine_setup(void);
void wolverine_loop(void);
extern void (*set_led)(bool on);
void set_led_impl(bool on);

#endif