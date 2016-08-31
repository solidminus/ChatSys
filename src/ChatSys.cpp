#include "global.h"
#include <cstring>


int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "ChatSys [database] [options]" << std::endl;
        std::cout << " --debug  - print debug info " << std::endl;
        return 0;
    }
 
    if ((argc > 2) && (!strcmp(argv[2], "--debug")))
        global::dbg = true;
    
    core::core bot = core::core(std::string(argv[1]));
    
 
       
    std::string input, output;
    
    for(;;)
    {
        std::cout << "You: ";
        std::getline(std::cin, input);
        
        auto inp_tokens = bot.lexer(input); // parse input to tokens
        if (inp_tokens != nullptr)
        {
            // transform input tokens to output tokens
            auto outp_tokens =
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
