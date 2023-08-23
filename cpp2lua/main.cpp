#include <iostream>
using namespace std;

extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

int main()
{
    lua_State *state = luaL_newstate();
    if (state == nullptr)
    {
        return 0;
    }

    luaL_openlibs(state);

    int ret = luaL_loadfile(state, "demo.lua");
    if (ret != LUA_OK)
    {
        cout << "load file error" << endl;
        return 0;
    }

    ret = lua_pcall(state, 0, 0, 0);
    if (ret != LUA_OK)
    {
        cout << "pcall error" << endl;
        return 0;
    }

    lua_getglobal(state, "api_version");
    string result = lua_tostring(state, -1);
    cout << result << endl;

    lua_getglobal(state, "say_hello");
    ret = lua_pcall(state, 0, 1, 0);
    if (ret != LUA_OK)
    {
        cout << "pcall error" << endl;
        return 0;
    }
    result = lua_tostring(state, -1);
    cout << result << endl;

    lua_getglobal(state, "show_message");
    // first param(int)
    lua_pushinteger(state, 100);
    // second param(table)
    lua_newtable(state);
    lua_pushstring(state, "content");
    lua_pushstring(state, "On duty");
    lua_settable(state, -3);

    ret = lua_pcall(state, 2, 1, 0);
    if (ret != LUA_OK)
    {
        cout << "pcall error" << endl;
        return 0;
    }
    result = lua_tostring(state, -1);
    cout << result << endl;

    lua_close(state);

    return 0;
}