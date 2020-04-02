#include <stdint.h>
#include "unity_fixture.h"

#include "wolverine.h"
#include "fff.h"

DEFINE_FFF_GLOBALS;

TEST_GROUP(LED);

TEST_SETUP(LED) {}

TEST_TEAR_DOWN(LED) {}

TEST_GROUP_RUNNER(LED) {
    // RUN_TEST_CASE(LED, fancy_test_name_here);
}