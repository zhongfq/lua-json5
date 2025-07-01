#include "json5cpp.h"

#include <iostream>
#include <string>

#include "olua.hpp"
#include "lua_json5.h"

static lua_State *olua_new()
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    return L;
}

static int olua_dofile(lua_State *L, const char *path)
{
    int status;
    if ((status = luaL_loadfile(L, path)) != LUA_OK) {
        printf("%s\n", lua_tostring(L, -1));
        return status;
    }
    lua_pushstring(L, path);
    return olua_pcall(L, 1, 0);
}

int main() {
    Json5::ParseConfig conf;
    conf.newlinesAsCommas = false;
    conf.maxDepth = 100;
    Json::Value val;
	std::string err;
    std::istringstream input("{hello: \"world\", a: 1}");
    // std::istringstream input("[\"hello\", 2]");
	if (!Json5::parse(input, val, &err, conf)) {
		std::cerr << "Could not parse stdin: " << err << '\n';
		return 1;
	}

	std::cout << val << '\n';

    int status = 0;
    lua_State *L = olua_new();
    olua_import(L, luaopen_json5);
    status = olua_dofile(L, "../test.lua");
    lua_close(L);

    return 0;
}