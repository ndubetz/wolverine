#include <stdint.h>
#include <stdbool.h>

#include "unity_fixture.h"

#include "wolverine.h"
#include "fff.h"

#include <avr/io.h>

uint8_t DDRD;
uint8_t PORTD;

DEFINE_FFF_GLOBALS;

FAKE_VOID_FUNC(setup_yellow_led_mock);

TEST_GROUP(LED);

TEST_SETUP(LED) {
    DDRD = 0;
    setup_yellow_led = setup_yellow_led_mock;
}

TEST_TEAR_DOWN(LED) {
    setup_yellow_led = setup_yellow_led_impl;
}

TEST(LED, set_yellow_is_called_one_time_when_setup_loop_is_called) {

    wolverine_setup();
    
    TEST_ASSERT_EQUAL( 1, setup_yellow_led_mock_fake.call_count );
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

TEST(LED, wolverine_loop_calls_yellow_led_on) {
    TEST_ASSERT_TRUE_MESSAGE(false, "You should implement this test.");
}


TEST_GROUP_RUNNER(LED) {
    // RUN_TEST_CASE(LED, fancy_test_name_here);
    RUN_TEST_CASE(LED, set_yellow_is_called_one_time_when_setup_loop_is_called);
    RUN_TEST_CASE(LED, setup_yellow_sets_ddrd_portd3_high);
    RUN_TEST_CASE(LED, yellow_led_is_turned_on);
    RUN_TEST_CASE(LED, wolverine_loop_calls_yellow_led_on);
}