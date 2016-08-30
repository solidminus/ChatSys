#include "global.h"

int main()
{
    core::core bot;
    
    std::string input, output;
    
    for(;;)
    {
        std::cout << "You: ";
        std::getline(std::cin, input);
        
        auto inp_tokens = bot.lexer(input); // parse input to tokens
        if (inp_tokens != nullptr)
        {
            // transform input tokens to output tokens
            std::shared_ptr<machine::tokens> outp_tokens =
                    bot.understand(inp_tokens); 
            if (outp_tokens != nullptr)
            {
                // build string from output tokens
                output = bot.build(outp_tokens);
                if (!output.empty())
                    std::cout << "Bot: " << output.c_str() << std::endl;
                else
                    std::cerr << "from main.cpp: core::build error" <<
                            std::endl;
            } else
                std::cerr << "from main.cpp: core::understand error" <<
                        std::endl;
        } else
            std::cerr << "from main.cpp: core::lexer error" << std::endl;
        
        
        
    }
    
    return 0;
}
