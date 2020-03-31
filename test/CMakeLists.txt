include_directories(../unity)
include_directories(../src)
include_directories(.)

set(TESTPROJECT test-${PROJECT_NAME})

file(GLOB TEST_SRC "*.c")

add_executable(${TESTPROJECT}
    ${TEST_SRC}
    ../src/wolverine.c
)
target_link_directories(${TESTPROJECT} PUBLIC ../unity)
target_link_libraries(${TESTPROJECT} PUBLIC unity)

add_dependencies(${TESTPROJECT}
    unity
)

add_test(led ${TESTPROJECT} COMMAND ./${TESTPROJECT})