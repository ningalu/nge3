add_executable(
    unit_tests
    ./TempTest.cpp
)

target_link_libraries(unit_tests gtest::gtest)