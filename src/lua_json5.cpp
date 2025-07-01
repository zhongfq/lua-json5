//
// AUTO GENERATED, DO NOT MODIFY!
//
#include "lua_json5.h"

static int _olua_module_json5(lua_State *L);

OLUA_LIB void olua_check_table(lua_State *L, int idx, luajson5::ParseConfig *value)
{
    int arg1 = 0;       /** maxDepth */

    olua_getfield(L, idx, "maxDepth");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_integer(L, -1, &arg1);
        value->maxDepth = arg1;
    }
    lua_pop(L, 1);
}

OLUA_LIB bool olua_is_table(lua_State *L, int idx, luajson5::ParseConfig *)
{
    return olua_hasfield(L, idx, "maxDepth");
}


OLUA_LIB void olua_check_table(lua_State *L, int idx, luajson5::SerializeConfig *value)
{
    bool arg1 = false;       /** trailingCommas */
    int arg2 = 0;       /** indent */

    olua_getfield(L, idx, "trailingCommas");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_bool(L, -1, &arg1);
        value->trailingCommas = arg1;
    }
    lua_pop(L, 1);

    olua_getfield(L, idx, "indent");
    if (!olua_isnoneornil(L, -1)) {
        olua_check_integer(L, -1, &arg2);
        value->indent = arg2;
    }
    lua_pop(L, 1);
}

OLUA_LIB bool olua_is_table(lua_State *L, int idx, luajson5::SerializeConfig *)
{
    return olua_hasfield(L, idx, "indent") && olua_hasfield(L, idx, "trailingCommas");
}


static int _olua_fun_luajson5_ParseConfig___gc(lua_State *L)
{
    try {
        olua_startinvoke(L);
        auto self = (luajson5::ParseConfig *)olua_toobj(L, 1, "luajson5.ParseConfig");
        olua_postgc(L, self);
        olua_endinvoke(L);
        return 0;
    } catch (std::exception &e) {
        lua_pushfstring(L, "luajson5::ParseConfig::__gc(): %s", e.what());
        luaL_error(L, olua_tostring(L, -1));
        return 0;
    }
}

static int _olua_fun_luajson5_ParseConfig_maxDepth$1(lua_State *L)
{
    try {
        olua_startinvoke(L);

        luajson5::ParseConfig *self = nullptr;

        olua_to_object(L, 1, &self, "luajson5.ParseConfig");

        // @optional int maxDepth
        int ret = self->maxDepth;
        int num_ret = olua_push_integer(L, ret);

        olua_endinvoke(L);

        return num_ret;
    } catch (std::exception &e) {
        lua_pushfstring(L, "luajson5::ParseConfig::maxDepth(): %s", e.what());
        luaL_error(L, olua_tostring(L, -1));
        return 0;
    }
}

static int _olua_fun_luajson5_ParseConfig_maxDepth$2(lua_State *L)
{
    try {
        olua_startinvoke(L);

        luajson5::ParseConfig *self = nullptr;
        int arg1 = 0;       /** maxDepth */

        olua_to_object(L, 1, &self, "luajson5.ParseConfig");
        olua_check_integer(L, 2, &arg1);

        // int maxDepth
        self->maxDepth = arg1;

        olua_endinvoke(L);

        return 0;
    } catch (std::exception &e) {
        lua_pushfstring(L, "luajson5::ParseConfig::maxDepth(): %s", e.what());
        luaL_error(L, olua_tostring(L, -1));
        return 0;
    }
}

static int _olua_fun_luajson5_ParseConfig_maxDepth(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @optional int maxDepth
        return _olua_fun_luajson5_ParseConfig_maxDepth$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "luajson5.ParseConfig")) && (olua_is_integer(L, 2))) {
            // int maxDepth
            return _olua_fun_luajson5_ParseConfig_maxDepth$2(L);
        // }
    }

    luaL_error(L, "method 'luajson5::ParseConfig::maxDepth' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_luajson5_ParseConfig(lua_State *L)
{
    oluacls_class<luajson5::ParseConfig>(L, "luajson5.ParseConfig");
    oluacls_func(L, "__gc", _olua_fun_luajson5_ParseConfig___gc);
    oluacls_prop(L, "maxDepth", _olua_fun_luajson5_ParseConfig_maxDepth, _olua_fun_luajson5_ParseConfig_maxDepth);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_luajson5_ParseConfig(lua_State *L)
{
    olua_require(L, ".olua.module.json5",  _olua_module_json5);
    if (!olua_getclass(L, "luajson5.ParseConfig")) {
        luaL_error(L, "class not found: luajson5::ParseConfig");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_luajson5_SerializeConfig___gc(lua_State *L)
{
    try {
        olua_startinvoke(L);
        auto self = (luajson5::SerializeConfig *)olua_toobj(L, 1, "luajson5.SerializeConfig");
        olua_postgc(L, self);
        olua_endinvoke(L);
        return 0;
    } catch (std::exception &e) {
        lua_pushfstring(L, "luajson5::SerializeConfig::__gc(): %s", e.what());
        luaL_error(L, olua_tostring(L, -1));
        return 0;
    }
}

static int _olua_fun_luajson5_SerializeConfig_indent$1(lua_State *L)
{
    try {
        olua_startinvoke(L);

        luajson5::SerializeConfig *self = nullptr;

        olua_to_object(L, 1, &self, "luajson5.SerializeConfig");

        // @optional int indent
        int ret = self->indent;
        int num_ret = olua_push_integer(L, ret);

        olua_endinvoke(L);

        return num_ret;
    } catch (std::exception &e) {
        lua_pushfstring(L, "luajson5::SerializeConfig::indent(): %s", e.what());
        luaL_error(L, olua_tostring(L, -1));
        return 0;
    }
}

static int _olua_fun_luajson5_SerializeConfig_indent$2(lua_State *L)
{
    try {
        olua_startinvoke(L);

        luajson5::SerializeConfig *self = nullptr;
        int arg1 = 0;       /** indent */

        olua_to_object(L, 1, &self, "luajson5.SerializeConfig");
        olua_check_integer(L, 2, &arg1);

        // int indent
        self->indent = arg1;

        olua_endinvoke(L);

        return 0;
    } catch (std::exception &e) {
        lua_pushfstring(L, "luajson5::SerializeConfig::indent(): %s", e.what());
        luaL_error(L, olua_tostring(L, -1));
        return 0;
    }
}

static int _olua_fun_luajson5_SerializeConfig_indent(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @optional int indent
        return _olua_fun_luajson5_SerializeConfig_indent$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "luajson5.SerializeConfig")) && (olua_is_integer(L, 2))) {
            // int indent
            return _olua_fun_luajson5_SerializeConfig_indent$2(L);
        // }
    }

    luaL_error(L, "method 'luajson5::SerializeConfig::indent' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_luajson5_SerializeConfig_trailingCommas$1(lua_State *L)
{
    try {
        olua_startinvoke(L);

        luajson5::SerializeConfig *self = nullptr;

        olua_to_object(L, 1, &self, "luajson5.SerializeConfig");

        // @optional bool trailingCommas
        bool ret = self->trailingCommas;
        int num_ret = olua_push_bool(L, ret);

        olua_endinvoke(L);

        return num_ret;
    } catch (std::exception &e) {
        lua_pushfstring(L, "luajson5::SerializeConfig::trailingCommas(): %s", e.what());
        luaL_error(L, olua_tostring(L, -1));
        return 0;
    }
}

static int _olua_fun_luajson5_SerializeConfig_trailingCommas$2(lua_State *L)
{
    try {
        olua_startinvoke(L);

        luajson5::SerializeConfig *self = nullptr;
        bool arg1 = false;       /** trailingCommas */

        olua_to_object(L, 1, &self, "luajson5.SerializeConfig");
        olua_check_bool(L, 2, &arg1);

        // bool trailingCommas
        self->trailingCommas = arg1;

        olua_endinvoke(L);

        return 0;
    } catch (std::exception &e) {
        lua_pushfstring(L, "luajson5::SerializeConfig::trailingCommas(): %s", e.what());
        luaL_error(L, olua_tostring(L, -1));
        return 0;
    }
}

static int _olua_fun_luajson5_SerializeConfig_trailingCommas(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // @optional bool trailingCommas
        return _olua_fun_luajson5_SerializeConfig_trailingCommas$1(L);
    }

    if (num_args == 2) {
        // if ((olua_is_object(L, 1, "luajson5.SerializeConfig")) && (olua_is_bool(L, 2))) {
            // bool trailingCommas
            return _olua_fun_luajson5_SerializeConfig_trailingCommas$2(L);
        // }
    }

    luaL_error(L, "method 'luajson5::SerializeConfig::trailingCommas' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_luajson5_SerializeConfig(lua_State *L)
{
    oluacls_class<luajson5::SerializeConfig>(L, "luajson5.SerializeConfig");
    oluacls_func(L, "__gc", _olua_fun_luajson5_SerializeConfig___gc);
    oluacls_prop(L, "trailingCommas", _olua_fun_luajson5_SerializeConfig_trailingCommas, _olua_fun_luajson5_SerializeConfig_trailingCommas);
    oluacls_prop(L, "indent", _olua_fun_luajson5_SerializeConfig_indent, _olua_fun_luajson5_SerializeConfig_indent);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_luajson5_SerializeConfig(lua_State *L)
{
    olua_require(L, ".olua.module.json5",  _olua_module_json5);
    if (!olua_getclass(L, "luajson5.SerializeConfig")) {
        luaL_error(L, "class not found: luajson5::SerializeConfig");
    }
    return 1;
}
OLUA_END_DECLS

static int _olua_fun_luajson5_json5___gc(lua_State *L)
{
    try {
        olua_startinvoke(L);
        auto self = (luajson5::json5 *)olua_toobj(L, 1, "luajson5.json5");
        olua_postgc(L, self);
        olua_endinvoke(L);
        return 0;
    } catch (std::exception &e) {
        lua_pushfstring(L, "luajson5::json5::__gc(): %s", e.what());
        luaL_error(L, olua_tostring(L, -1));
        return 0;
    }
}

static int _olua_fun_luajson5_json5_parse$1(lua_State *L)
{
    try {
        olua_startinvoke(L);

        std::string arg1;       /** str */

        olua_check_string(L, 1, &arg1);

        // static Json::Value parse(const std::string &str)
        Json::Value ret = luajson5::json5::parse(arg1);
        int num_ret = olua_push_Json_Value(L, ret);

        olua_endinvoke(L);

        return num_ret;
    } catch (std::exception &e) {
        lua_pushfstring(L, "luajson5::json5::parse(): %s", e.what());
        luaL_error(L, olua_tostring(L, -1));
        return 0;
    }
}

static int _olua_fun_luajson5_json5_parse$2(lua_State *L)
{
    try {
        olua_startinvoke(L);

        std::string arg1;       /** str */
        luajson5::ParseConfig *arg2;       /** conf */
        luajson5::ParseConfig arg2_from_table;       /** conf */

        olua_check_string(L, 1, &arg1);
        if (olua_istable(L, 2)) {
            olua_check_table(L, 2, &arg2_from_table);
            arg2 = &arg2_from_table;
        } else {
            olua_check_object(L, 2, &arg2, "luajson5.ParseConfig");
        }

        // static Json::Value parse(const std::string &str, const luajson5::ParseConfig &conf)
        Json::Value ret = luajson5::json5::parse(arg1, *arg2);
        int num_ret = olua_push_Json_Value(L, ret);

        olua_endinvoke(L);

        return num_ret;
    } catch (std::exception &e) {
        lua_pushfstring(L, "luajson5::json5::parse(): %s", e.what());
        luaL_error(L, olua_tostring(L, -1));
        return 0;
    }
}

static int _olua_fun_luajson5_json5_parse(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_string(L, 1))) {
            // static Json::Value parse(const std::string &str)
            return _olua_fun_luajson5_json5_parse$1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_string(L, 1)) && (olua_is_object(L, 2, "luajson5.ParseConfig") || olua_is_table(L, 2, (luajson5::ParseConfig *)nullptr))) {
            // static Json::Value parse(const std::string &str, const luajson5::ParseConfig &conf)
            return _olua_fun_luajson5_json5_parse$2(L);
        // }
    }

    luaL_error(L, "method 'luajson5::json5::parse' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_fun_luajson5_json5_stringify$1(lua_State *L)
{
    try {
        olua_startinvoke(L);

        Json::Value arg1;       /** val */

        olua_check_Json_Value(L, 1, &arg1);

        // static std::string stringify(const Json::Value &val)
        std::string ret = luajson5::json5::stringify(arg1);
        int num_ret = olua_push_string(L, ret);

        olua_endinvoke(L);

        return num_ret;
    } catch (std::exception &e) {
        lua_pushfstring(L, "luajson5::json5::stringify(): %s", e.what());
        luaL_error(L, olua_tostring(L, -1));
        return 0;
    }
}

static int _olua_fun_luajson5_json5_stringify$2(lua_State *L)
{
    try {
        olua_startinvoke(L);

        Json::Value arg1;       /** val */
        luajson5::SerializeConfig *arg2;       /** conf */
        luajson5::SerializeConfig arg2_from_table;       /** conf */

        olua_check_Json_Value(L, 1, &arg1);
        if (olua_istable(L, 2)) {
            olua_check_table(L, 2, &arg2_from_table);
            arg2 = &arg2_from_table;
        } else {
            olua_check_object(L, 2, &arg2, "luajson5.SerializeConfig");
        }

        // static std::string stringify(const Json::Value &val, const luajson5::SerializeConfig &conf)
        std::string ret = luajson5::json5::stringify(arg1, *arg2);
        int num_ret = olua_push_string(L, ret);

        olua_endinvoke(L);

        return num_ret;
    } catch (std::exception &e) {
        lua_pushfstring(L, "luajson5::json5::stringify(): %s", e.what());
        luaL_error(L, olua_tostring(L, -1));
        return 0;
    }
}

static int _olua_fun_luajson5_json5_stringify(lua_State *L)
{
    int num_args = lua_gettop(L);

    if (num_args == 1) {
        // if ((olua_is_Json_Value(L, 1))) {
            // static std::string stringify(const Json::Value &val)
            return _olua_fun_luajson5_json5_stringify$1(L);
        // }
    }

    if (num_args == 2) {
        // if ((olua_is_Json_Value(L, 1)) && (olua_is_object(L, 2, "luajson5.SerializeConfig") || olua_is_table(L, 2, (luajson5::SerializeConfig *)nullptr))) {
            // static std::string stringify(const Json::Value &val, const luajson5::SerializeConfig &conf)
            return _olua_fun_luajson5_json5_stringify$2(L);
        // }
    }

    luaL_error(L, "method 'luajson5::json5::stringify' not support '%d' arguments", num_args);

    return 0;
}

static int _olua_cls_luajson5_json5(lua_State *L)
{
    oluacls_class<luajson5::json5>(L, "luajson5.json5");
    oluacls_func(L, "__gc", _olua_fun_luajson5_json5___gc);
    oluacls_func(L, "parse", _olua_fun_luajson5_json5_parse);
    oluacls_func(L, "stringify", _olua_fun_luajson5_json5_stringify);

    return 1;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_luajson5_json5(lua_State *L)
{
    olua_require(L, ".olua.module.json5",  _olua_module_json5);
    if (!olua_getclass(L, "luajson5.json5")) {
        luaL_error(L, "class not found: luajson5::json5");
    }
    return 1;
}
OLUA_END_DECLS

int _olua_module_json5(lua_State *L)
{
    olua_require(L, "luajson5.ParseConfig", _olua_cls_luajson5_ParseConfig);
    olua_require(L, "luajson5.SerializeConfig", _olua_cls_luajson5_SerializeConfig);
    olua_require(L, "luajson5.json5", _olua_cls_luajson5_json5);

    return 0;
}

OLUA_BEGIN_DECLS
OLUA_LIB int luaopen_json5(lua_State *L)
{
    olua_require(L, ".olua.module.json5",  _olua_module_json5);

    if (olua_getclass(L, "luajson5.json5")) {
        return 1;
    }

    return 0;
}
OLUA_END_DECLS
