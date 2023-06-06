add_executable(
    unit_tests

    ./PointTests.cpp
    ./ColorTests.cpp
    ./SurfaceTests.cpp
    
    ./Events/KeyModTests.cpp
)
target_compile_features(
    unit_tests
    PRIVATE cxx_std_20
)
target_include_directories(
    unit_tests
    PUBLIC ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(
    unit_tests
    gtest::gtest
    SDL2::SDL2main
    ngsdl
)
# add_test(unit_tests unit_tests --exe $<TARGET_FILE:${CMAKE_SOURCE_DIR}/build/tests/Release/unit_tests.exe>)