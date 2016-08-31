#include "global.h"




core::core::core(std::string filename)
{
    global::debug dbg(global::dbg);
    dbg.output("core entered");
    
    this->wd.load_data(std::move(filename));
}


std::shared_ptr<machine::tokens> core::core::lexer(std::string input_str)
{
    global::debug dbg(global::dbg);
    
    dbg.output("core::lexers() entered");    
      
    std::shared_ptr<machine::tokens> pTokens(new machine::tokens);
    
    WordArr arr = this->wd.get(); // gets an array of vector of Words
    WordTypeMap mp = this->wd.map(); // WordType - WordArr's index map
    
    mp.erase(std::string("!WORD_END"));
   
    std::shared_ptr<std::string> word;
    
    bool emplaced = false;
    
    
    
    for(auto pStr = input_str.begin(); pStr <= input_str.end(); pStr++)
    {
        auto pWord = pStr;
        
        
        while((pWord.base()[0] != ' ') && (pWord.base()[0] != '\0'))
        {
            pWord++;
        }
        
        word = std::make_shared<std::string>(pStr, pWord);
        
        pStr = pWord;
        emplaced = false;
        for(auto map_it : mp)
        {
            for(auto arr_it : arr.at(map_it.second))
            {
                if (arr_it == *word)
                {
                    pTokens->emplace_back((map_it.first + std::string(":") + arr_it).c_str());
                    emplaced = true;
                    break;
                    
                }
            }
            if (emplaced)
                break;
        }
        if (!emplaced)
            pTokens->emplace_back((std::string("!CONTENT:") + *word).c_str());

    }
    
    if (global::dbg)
    {
        for(auto in_v : pTokens->token_vector)
            std::cout << in_v << "->";
        std::cout << std::endl;
    }
    
    return pTokens; 
}

std::shared_ptr<machine::tokens> core::core::understand
        (std::shared_ptr<machine::tokens>)
{    
    
    global::debug dbg(global::dbg);
    
    dbg.output("core::understand() entered");    
    
    std::cout << "core::understand in develop" << std::endl;
    std::shared_ptr<machine::tokens> p(nullptr);
    return p;    
}

std::string core::core::build(std::shared_ptr<machine::tokens>)
{
    
    global::debug dbg(global::dbg);
    
    dbg.output("core::build() entered");    
    
    std::cout << "core::build in develop" << std::endl;
    return std::string("");
}