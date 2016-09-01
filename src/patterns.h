#ifndef PATTERNS_H
#define PATTERNS_H

#include <map>
#include <vector>
#include <string>
#include <memory>
#include "tokens.h"

using token_pattern = std::vector<std::string>; // вектор шаблонных токенов
using pattern = std::map<std::string, token_pattern>; // шаблоны - токены
using recogn_pair = std::pair<std::string, token_pattern>;  // результат 


namespace patterns
{
    class recognizer
    {
    public:
        
        recognizer();
        
        recogn_pair recognize(std::shared_ptr<machine::tokens> &ref_token);
    
    private:
        pattern pattern_map; // карта паттернов
    };
}

#endif /* PATTERNS_H */

