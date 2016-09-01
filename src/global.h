#ifndef GLOBAL_H
#define GLOBAL_H


#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>

using WordArr = std::array<std::vector<std::string>, 3>;
using WordTypeMap = std::map<std::string, size_t>;
using token_pattern = std::vector<std::string>;
using pattern = std::map<std::string, token_pattern>;
using recogn_ret = std::pair<std::string, token_pattern>;

namespace global
{
    class debug
    {
    public:
        debug(bool dbg): in_debug(dbg){}
        void output(const std::string& str);
        
    private:
        bool in_debug;
    };
    
    extern bool dbg;
}

#include "knowledge.h"
#include "core.h"
#include "tokens.h"
#include "patterns.h"

#endif /* GLOBAL_H */

