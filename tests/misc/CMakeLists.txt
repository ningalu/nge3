add_executable(
    misc_tests
    ./RectangleTests.cpp
    ./Rectangle_SDL_Rect_Interop.cpp
)
target_compile_features(
    misc_tests
    PRIVATE cxx_std_20
)
target_include_directories(
    misc_tests
    PUBLIC ${CMAKE_SOURCE_DIR}/include
)
target_compile_options(
    misc_tests
    PRIVATE $<$<CXX_COMPILER_ID:MSVC>:
            /W4
            /WX
            /external:anglebrackets 
            /external:W0
            # /fsanitize=address
        >
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:
            -lstdc++
            -Wall 
            -Wextra 
            -Wshadow 
            -Wnon-virtual-dtor 
            -pedantic
            -Werror
            -Wno-unknown-pragmas
            -Wno-unused-command-line-argument
        >
)

target_link_libraries(
    misc_tests
    gtest::gtest
    ngl-misc-lib
    SDL2::SDL2main
)
add_test(misc_tests misc_tests --exe $<TARGET_FILE:${CMAKE_SOURCE_DIR}/build/tests/Release/unit_tests.exe>)