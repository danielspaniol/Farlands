set(PROJECT_TEST_SRC
    prelude.test.cpp
)

include(GoogleTest)
enable_testing()

add_executable(${PROJECT_TESTS_NAME} ${PROJECT_TEST_SRC})
target_link_libraries(${PROJECT_TESTS_NAME} ${PROJECT_LIB_NAME} gtest_main)
gtest_discover_tests(${PROJECT_TESTS_NAME})