#include "global.h"

bool global::dbg = false;

void global::debug::output(const std::string& str)
{
    if (this->in_debug)
        std::cout << str << std::endl;
}