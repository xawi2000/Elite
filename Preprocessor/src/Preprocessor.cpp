#include "Preprocessor.h"

using namespace std;

Preprocessor::Preprocessor (const std::string& input, lua_State* L)
    : input(input) {
    this->L = L;
}

Preprocessor::~Preprocessor () {

}


const std::string& Preprocessor::genCode() {

    return code_string;
}

const std::string& Preprocessor::runCode() {
    lua_pushlightuserdata(L, this);
    lua_setfield(L, -1, "__preprocessor");

    return output;
}


int Preprocessor::add_const_str(
    std::string::iterator p, std::string::iterator q) {
    string str(p, q);

    lua_pushstring(L, str.c_str());
    return luaL_ref(L, LUA_REGISTRYINDEX);
}

static int loadStr(lua_State* L) {
    int id = lua_tonumber(L, -1);
    lua_rawgeti(L, LUA_REGISTRYINDEX, id);
    const char* str = lua_tostring(L, lua_tonumber(L, -1));
    lua_pop(L, 2);
    output += str;
}
