cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(lua-openxlsx)

set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

add_subdirectory(lua)
add_subdirectory(jsoncpp)

add_library(luajson5 MODULE 
  src/lua_json5.h
  src/lua_json5.cpp
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
    ${CMAKE_CURRENT_SOURCE_DIR}/json5cpp
)
if(APPLE)
    target_link_options(luajson5 PUBLIC -bundle -undefined dynamic_lookup)
elseif(WIN32)
    target_link_libraries(luajson5 liblua)
endif()
target_link_libraries(luajson5 jsoncpp_static)

add_executable(test_json5
  src/test.cpp
  src/lua_json5.h
  src/lua_json5.cpp
  src/json5_lua.h
  olua/olua.h
  olua/olua.hpp
  olua/olua.c
)
target_include_directories(test_json5
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/olua
    ${CMAKE_CURRENT_SOURCE_DIR}/lua
    ${CMAKE_CURRENT_SOURCE_DIR}/json5cpp
)
target_link_libraries(test_json5 liblua)
target_link_libraries(test_json5 jsoncpp_static)