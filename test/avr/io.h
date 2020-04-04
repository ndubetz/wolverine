#ifndef AVR_IO_H
#define AVR_IO_H

#include <stdint.h>

#define _BV(bit) (1 << (bit))

extern uint8_t DDRD;
#define DDD0 0
#define DDD1 1
#define DDD2 2
#define DDD3 3
#define DDD4 4
#define DDD5 5
#define DDD6 6
#define DDD7 7

extern uint8_t PORTD;
#define PORTD0 0
#define PORTD1 1
#define PORTD2 2
#define PORTD3 3
#define PORTD4 4
#define PORTD5 5
#define PORTD6 6
#define PORTD7 7

#endif