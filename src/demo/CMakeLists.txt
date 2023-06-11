set(subproject nge3_app)

add_library(
  ${subproject}-lib 

  ./IntroScene.cpp
  ./DebugScene.cpp

  ./Pong/PongScene.cpp
  ./Pong/Ball.cpp
  ./Pong/Paddle.cpp

  ./Graph/GraphScene.cpp

  ./Topdown/TitleScene/TitleScene.cpp
)

target_compile_features(
  ${subproject}-lib 
  PRIVATE cxx_std_20
)

target_compile_options(
  ${subproject}-lib
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
  >)

target_include_directories(
  ${subproject}-lib
  PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(
  ${subproject}-lib 
  nge3
)

add_executable(
  ${subproject}-demo 
  ./main.cpp
)

target_compile_features(
  ${subproject}-demo  
  PRIVATE cxx_std_20
)

target_include_directories(
  ${subproject}-demo
  PUBLIC ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
  ${subproject}-demo  
  ngsdl 
  nge3 
  ${subproject}-lib
)

add_custom_command(
  TARGET ${subproject}-demo 
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} ARGS -E copy_directory ${CMAKE_SOURCE_DIR}/resources
          $<TARGET_FILE_DIR:${subproject}-demo>/resources
)

unset(subproject)