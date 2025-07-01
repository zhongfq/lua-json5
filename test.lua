local json5 = require("json5")

local data = json5.stringify({hello = "world"}, {indent = 0, trailingCommas = false })

print(data)

local t = json5.parse('{hello: "world", a: 1, b:[1, {"d": 3.45, c: "4"}, [1, 2]]}')
print(t.hello, t.a, t.b, t.b[1], t.b[2].d, t.b[3][1])
print(json5.stringify(t, {indent = 0, trailingCommas = false}))