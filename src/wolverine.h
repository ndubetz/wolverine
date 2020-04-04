#ifndef WOLVERINE_H
#define WOLVERINE_H


extern void (*setup_yellow_led)(void);

void setup_yellow_led_impl();

void wolverine_setup(void);
void wolverine_loop(void);

#endif