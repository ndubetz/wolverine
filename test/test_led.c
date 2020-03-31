#include <stdint.h>
#include "unity_fixture.h"

#include "wolverine.h"
#include "avr/io.h"
#include "fff.h"

uint8_t DDRD = 0;
uint8_t PORTD = 0;

DEFINE_FFF_GLOBALS;

FAKE_VOID_FUNC(_delay_ms, double);
FAKE_VOID_FUNC(set_led_mock, bool);

TEST_GROUP(LED);

TEST_SETUP(LED) {
    DDRD = 0;
    PORTD = 0;
    RESET_FAKE(_delay_ms);
    RESET_FAKE(set_led_mock);
}

TEST_TEAR_DOWN(LED) {}

TEST(LED, setup_sets_led_port_to_output) {
    uint8_t expected = _BV(DDD2);

    wolverine_setup();

    TEST_ASSERT_EQUAL_UINT8(expected, DDRD);
}

TEST(LED, loop_sets_blue_led_low){
    PORTD |= _BV(PORTD2);

    set_led(false);

    TEST_ASSERT_EQUAL_UINT8(0, PORTD & _BV(PORTD2));
}

TEST(LED, set_led_calls_delay_ms_for_half_second) {
    set_led(false);

    TEST_ASSERT_EQUAL_INT(500, _delay_ms_fake.arg0_val);
}

TEST(LED, set_led_on_calls_delay_ms_for_half_second_and_sets_blue_led_high) {
    set_led(true);

    TEST_ASSERT_EQUAL_UINT8(_BV(BLUE_LED), PORTD & _BV(BLUE_LED));

    TEST_ASSERT_EQUAL_INT(500, _delay_ms_fake.arg0_val);
}

TEST(LED, wolverine_loop_calls_set_led_twice_with_true_and_false) {
    set_led = set_led_mock;

    wolverine_loop();

    TEST_ASSERT_EQUAL_INT(2, set_led_mock_fake.call_count);
    TEST_ASSERT_TRUE(set_led_mock_fake.arg0_history[0]);
    TEST_ASSERT_FALSE(set_led_mock_fake.arg0_history[1]);
}

TEST_GROUP_RUNNER(LED) {
    RUN_TEST_CASE(LED, setup_sets_led_port_to_output);
    RUN_TEST_CASE(LED, loop_sets_blue_led_low);
    RUN_TEST_CASE(LED, set_led_calls_delay_ms_for_half_second);
    RUN_TEST_CASE(LED, set_led_on_calls_delay_ms_for_half_second_and_sets_blue_led_high);
    RUN_TEST_CASE(LED, wolverine_loop_calls_set_led_twice_with_true_and_false);
}

