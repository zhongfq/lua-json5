cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(lua-openxlsx)

set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

add_subdirectory(lua)
add_subdirectory(jsoncpp)

add_library(luajson5 MODULE 
  src/json5_lua.cpp
  src/json5_lua.h
  olua/olua.h
  olua/olua.hpp
  olua/olua.c
)
set_target_properties(luajson5 PROPERTIES 
    PREFIX ""
    OUTPUT_NAME json5
)
target_include_directories(luajson5
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/olua
    ${CMAKE_CURRENT_SOURCE_DIR}/lua
)
if(APPLE)
    target_link_options(luajson5 PUBLIC -bundle -undefined dynamic_lookup)
elseif(WIN32)
    target_link_libraries(luajson5 liblua)
endif()
target_link_libraries(luajson5 PRIVATE jsoncpp_static)