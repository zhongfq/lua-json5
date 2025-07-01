---@format disable

package.path = "./?.lua;./?/init.lua;" .. package.path

require "olua"

olua.AUTO_GEN_PROP = false
olua.ENABLE_EXCEPTION = true

-------------------------------------------------------------------------------
--- clang compile options
-------------------------------------------------------------------------------
clang {
    "-DOLUA_DEBUG",
    "-std=c++17",
    "-I./olua",
    "-I./lua",
    "-I./src",
    "-I./json5cpp",
    "-I./jsoncpp/include",
}

module "json5"

output_dir "src"

api_dir "addons/json5"

headers [[
#include "olua.hpp"
#include "json5_lua.h"
]]

entry "luajson5::json5"

typedef "Json::Value"

typeconf "luajson5::ParseConfig"
    .from_table "true"
    .var("newlinesAsCommas")
        .attr("@optional")
typeconf "luajson5::SerializeConfig"
    .from_table "true"
typeconf "luajson5::json5"