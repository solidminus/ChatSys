#ifndef CORE_H
#define CORE_H

#include <memory>
#include "tokens.h"
#include <string>

namespace core
{
    class core
    {
    public:
    
        // build a token vector by input string
        std::shared_ptr<machine::tokens> lexer(std::string input_str);
        
        // reform input token to ouput token
        std::shared_ptr<machine::tokens> understand(
            std::shared_ptr<machine::tokens>); 
        
        // build output string from output token
        std::string build(std::shared_ptr<machine::tokens>);
        
    };
}

#endif /* CORE_H */

