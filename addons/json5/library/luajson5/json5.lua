---AUTO GENERATED, DO NOT MODIFY!
---@meta luajson5.json5

---
---@class luajson5.json5 
local json5 = {}

---@return any
function json5:__gc() end

---@param str string
---@return any
---@overload fun(str: string, conf: luajson5.ParseConfig): any
function json5.parse(str) end

---@param val any
---@return string
---@overload fun(val: any, conf: luajson5.SerializeConfig): string
function json5.stringify(val) end

return json5