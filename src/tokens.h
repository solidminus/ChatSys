#ifndef TOKENS_H
#define TOKENS_H

#include <vector>
#include <string>

namespace machine
{
    class tokens
    {
    public:
        
        void emplace_back(const char *str); // wrapper for std::vector::emplace_back()
        std::vector<std::string> token_vector;
    };
}

#endif /* TOKENS_H */

