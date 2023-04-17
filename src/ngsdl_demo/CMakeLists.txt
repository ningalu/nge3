set(subproject ngsdl_app)

add_executable(
  ${subproject}-demo 
  ./ngsdl_test_app.cpp
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
)

add_custom_command(
  TARGET ${subproject}-demo 
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} ARGS -E copy_directory ${CMAKE_SOURCE_DIR}/resources
          $<TARGET_FILE_DIR:${subproject}-demo>/resources
)

unset(subproject)