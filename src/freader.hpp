//freader.hpp ~ loads a shader file and returns the code as plain text (std::string)
#pragma once
#include<string>
#include<fstream>

namespace utils {
    std::string readFile(const char* fileName) {
        std::ifstream f(fileName);
        std::string toRet;
        if(f) {
            std::ostringstream ss;
            ss << f.rdbuf();
            toRet = ss.str();
        }
        return toRet;
    }
}
