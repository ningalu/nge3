add_library(nge3)

target_compile_features(nge3 PRIVATE cxx_std_20)

target_include_directories(
  nge3
  PUBLIC ${CMAKE_SOURCE_DIR}/include/nge3/ngsdl
  PUBLIC ${CMAKE_SOURCE_DIR}/include/nge3/nge)

target_link_libraries(nge3 SDL2::SDL2main SDL2_image::SDL2_image
                      SDL2_ttf::SDL2_ttf)
