#ifndef WOLVERINE_H
#define WOLVERINE_H

extern void (*setup_yellow_led)(void);
void setup_yellow_led_impl();

extern void (*yellow_led_on)(void);
void yellow_led_on_impl(void);

extern void (*yellow_led_off)(void);
void yellow_led_off_impl(void);

void wolverine_setup(void);
void wolverine_loop(void);

#endif