set(TESTPROJECT test-${PROJECT_NAME})
file(GLOB TEST_SRC "*.c")

add_executable(${TESTPROJECT}
    ${TEST_SRC}
    ../src/wolverine.c
)

add_dependencies(${TESTPROJECT}
    unity
)