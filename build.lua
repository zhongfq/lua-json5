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
}

module "json5"

output_dir "src"

api_dir "addons/json5"

headers [[
#include "olua.hpp"
#include "json5_lua.h"
]]

entry "json5::json5"