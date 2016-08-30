#include "global.h"

void machine::tokens::emplace_back(const char *str)
{
    this->token_vector.emplace_back(str);
}

