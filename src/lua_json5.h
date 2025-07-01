//
// AUTO GENERATED, DO NOT MODIFY!
//
#ifndef __AUTO_GEN_LUA_JSON5_H__
#define __AUTO_GEN_LUA_JSON5_H__

#include "olua.hpp"
#include "json5_lua.h"

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_json5(lua_State *L);
OLUA_END_DECLS

// luajson5::ParseConfig
OLUA_LIB bool olua_is_table(lua_State *L, int idx, luajson5::ParseConfig *);
OLUA_LIB void olua_check_table(lua_State *L, int idx, luajson5::ParseConfig *value);

// luajson5::SerializeConfig
OLUA_LIB bool olua_is_table(lua_State *L, int idx, luajson5::SerializeConfig *);
OLUA_LIB void olua_check_table(lua_State *L, int idx, luajson5::SerializeConfig *value);

#endif