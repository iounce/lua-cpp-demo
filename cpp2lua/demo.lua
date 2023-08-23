api_version = "V1.0.0"

function say_hello()
    return "Hello Lua"
end

function show_message(index, msg)
    return string.format("index: %d, content: %s ", index, msg['content'])
end