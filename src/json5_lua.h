#ifndef __JSON5_LUA_H__
#define __JSON5_LUA_H__

#include "olua.hpp"
#include "json5cpp.h"

namespace luajson5 {
    struct ParseConfig {
        // The maximum parse depth, to avoid unbounded recursion.
        int maxDepth = 100;
    };

    struct SerializeConfig {
        // Whether or not to add a trailing ',' after the last element
        // of an object/array.
        bool trailingCommas = true;

        // The string used for each level of nesting.
        // Set to 0 to avoid whitespace completely.
        int indent = 4;
    };
    
    class json5 {
    public:
        static Json::Value parse(const std::string& str) {
            return parse(str, {});
        }

        static Json::Value parse(const std::string& str, const ParseConfig& conf) {
            Json::Value val;
            std::string err;
            std::istringstream istr(str);
            Json5::ParseConfig jsonconf;
            jsonconf.maxDepth = conf.maxDepth;
            if (!Json5::parse(istr, val, &err, jsonconf)) {
                throw std::runtime_error(err);
            }
            return val;
        }

        static std::string stringify(const Json::Value& val) {
            return stringify(val, {});
        }

        static std::string stringify(const Json::Value& val, const SerializeConfig& conf) {
            std::ostringstream ostr;
            Json5::SerializeConfig jsonconf;
            std::string indent;
            while(indent.size() < conf.indent) {
                indent += " ";
            }
            jsonconf.trailingCommas = conf.trailingCommas;
            jsonconf.indent = indent.size() > 0 ? indent.c_str() : nullptr;
            Json5::serialize(ostr, val, jsonconf);
            return ostr.str();
        }
    };
}

static void push_value(lua_State* L, const Json::Value& val) {
    if (val.isNull()) {
        lua_pushnil(L);
    } else if (val.isBool()) {
        olua_pushbool(L, val.asBool());
    } else if (val.isInt()) {
        olua_pushinteger(L, val.asInt());
    } else if (val.isDouble()) {
        olua_pushnumber(L, val.asDouble());
    } else if (val.isString()) {
        olua_pushstring(L, val.asCString());
    } else if (val.isArray()) {
        lua_createtable(L, val.size(), 0);
        for (Json::ArrayIndex i = 0; i < val.size(); i++) {
            push_value(L, val[i]);
            lua_rawseti(L, -2, i + 1);
        }
    } else if (val.isObject()) {
        lua_createtable(L, 0, val.size());
        for (Json::Value::const_iterator it = val.begin(); it != val.end(); ++it) {
            push_value(L, *it);
            lua_setfield(L, -2, it.key().asCString());
        }
    }
}

static inline int olua_push_Json_Value(lua_State* L, const Json::Value& val) {
    push_value(L, val);
    return 1;
}

static void check_value(lua_State* L, int idx, Json::Value* val) {
    idx = lua_absindex(L, idx);
    if (lua_isnil(L, idx)) {
        *val = Json::Value::null;
    } else if (olua_isbool(L, idx)) {
        *val = Json::Value(lua_toboolean(L, idx));
    } else if (olua_isinteger(L, idx)) {
        *val = Json::Value((int64_t)olua_tointeger(L, idx));
    } else if (olua_isnumber(L, idx)) {
        *val = Json::Value(olua_tonumber(L, idx));
    } else if (olua_isstring(L, idx)) {
        *val = Json::Value(olua_tostring(L, idx));
    } else if (olua_istable(L, idx)) {
        int count = 0;
        lua_pushnil(L);
        while (lua_next(L, idx)) {
            count++;
            lua_pop(L, 1);
        }

        if (count == lua_rawlen(L, idx)) {
            *val = Json::Value(Json::arrayValue);
            for (int i = 1; i <= lua_rawlen(L, idx); i++) {
                Json::Value v;
                lua_rawgeti(L, idx, i);
                check_value(L, -1, &v);
                val->append(v);
                lua_pop(L, 1);
            }
        } else {
            *val = Json::Value(Json::objectValue);
            lua_pushnil(L);
            while (lua_next(L, idx)) {
                std::string key = olua_tostring(L, -2);
                Json::Value v;
                check_value(L, -1, &v);
                (*val)[key] = v;
                lua_pop(L, 1);
            }
        }
    } else {
        throw std::runtime_error("invalid value");
    }
}

static inline void olua_check_Json_Value(lua_State* L, int idx, Json::Value* val) {
    check_value(L, idx, val);
}

#endif