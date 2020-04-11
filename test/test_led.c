#include <stdint.h>
#include <stdbool.h>

#include "unity_fixture.h"

#include "wolverine.h"
#include "fff.h"

#include <avr/io.h>
#include <util/delay.h>

uint8_t DDRD;
uint8_t PORTD;

DEFINE_FFF_GLOBALS;

FAKE_VOID_FUNC(setup_yellow_led_mock);
FAKE_VOID_FUNC(yellow_led_on_mock);
FAKE_VOID_FUNC(_delay_ms, double);
FAKE_VOID_FUNC(yellow_led_off_mock);

TEST_GROUP(LED);

TEST_SETUP(LED)
{
    DDRD = 0;
    setup_yellow_led = setup_yellow_led_mock;
    RESET_FAKE(setup_yellow_led_mock);
    RESET_FAKE(yellow_led_on_mock);
    RESET_FAKE(_delay_ms);
    RESET_FAKE(yellow_led_off_mock);
    FFF_RESET_HISTORY();
}

TEST_TEAR_DOWN(LED)
{
    setup_yellow_led = setup_yellow_led_impl;
}

TEST(LED, set_yellow_is_called_one_time_when_setup_loop_is_called)
{

    wolverine_setup();

    TEST_ASSERT_EQUAL(1, setup_yellow_led_mock_fake.call_count);
}

TEST(LED, yellow_led_is_turned_on)
{
    yellow_led_on();

    TEST_ASSERT_EQUAL(_BV(PORTD3), PORTD & _BV(PORTD3));
}

TEST(LED, setup_yellow_sets_ddrd_portd3_high)
{
    setup_yellow_led_impl();

    TEST_ASSERT_EQUAL_UINT8(_BV(DDD3), DDRD & _BV(DDD3));
}

TEST(LED, wolverine_loop_calls_yellow_led_on)
{
    yellow_led_on = yellow_led_on_mock;

    wolverine_loop();
    yellow_led_on = yellow_led_on_impl;

    TEST_ASSERT_EQUAL_INT(1, yellow_led_on_mock_fake.call_count);
}

TEST(LED, yellow_led_turns_off)
{
    PORTD = 0xFF;
    yellow_led_off();

    TEST_ASSERT_EQUAL(0, PORTD & ~_BV(PORTD3));
}

TEST(LED, wolverine_loop_calls_delay_twice)
{
    wolverine_loop();

    TEST_ASSERT_EQUAL_INT(2, _delay_ms_fake.call_count);
}

TEST(LED, wolverine_loop_calls_yellow_led_off)
{
    yellow_led_off = yellow_led_off_mock;
    wolverine_loop();
    yellow_led_off = yellow_led_off_impl;

    TEST_ASSERT_EQUAL_INT(1, yellow_led_off_mock_fake.call_count);
}

TEST(LED, wolverine_loop_should_turn_led_on_then_delay_then_turn_led_off)
{
    yellow_led_off = yellow_led_off_mock;
    yellow_led_on = yellow_led_on_mock;

    wolverine_loop();

    TEST_ASSERT_EQUAL(fff.call_history[0], (void *)yellow_led_on_mock);
    TEST_ASSERT_EQUAL(fff.call_history[1], (void *)_delay_ms);
    TEST_ASSERT_EQUAL(fff.call_history[2], (void *)yellow_led_off);
    TEST_ASSERT_EQUAL(fff.call_history[3], (void *)_delay_ms);

    yellow_led_off = yellow_led_off_impl;
    yellow_led_on = yellow_led_on_impl;
}

TEST_GROUP_RUNNER(LED)
{
    // RUN_TEST_CASE(LED, fancy_test_name_here);
    RUN_TEST_CASE(LED, set_yellow_is_called_one_time_when_setup_loop_is_called);
    RUN_TEST_CASE(LED, setup_yellow_sets_ddrd_portd3_high);
    RUN_TEST_CASE(LED, yellow_led_is_turned_on);
    RUN_TEST_CASE(LED, wolverine_loop_calls_yellow_led_on);
    RUN_TEST_CASE(LED, yellow_led_turns_off);
    RUN_TEST_CASE(LED, wolverine_loop_calls_delay_twice);
    RUN_TEST_CASE(LED, wolverine_loop_calls_yellow_led_off);
    RUN_TEST_CASE(LED, wolverine_loop_should_turn_led_on_then_delay_then_turn_led_off);
}