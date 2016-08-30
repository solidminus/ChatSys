#include "global.h"

std::shared_ptr<machine::tokens> core::core::lexer(std::string input_str)
{
    std::cout << "core::lexer in develop" << std::endl;
    std::shared_ptr<machine::tokens> p(nullptr);
    return p;
}

std::shared_ptr<machine::tokens> core::core::understand
        (std::shared_ptr<machine::tokens>)
{
    std::cout << "core::understand in develop" << std::endl;
    std::shared_ptr<machine::tokens> p(nullptr);
    return p;    
}

std::string core::core::build(std::shared_ptr<machine::tokens>)
{
    std::cout << "core::build in develop" << std::endl;
    return std::string("");
}