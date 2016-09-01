#include "global.h"

patterns::recognizer::recognizer()
{
        
    this->pattern_map.emplace(std::make_pair(std::string("?NAME"), 
            token_pattern({
                std::string("!ASK_WORD:WHAT"),
                std::string("!TOBE_WORD:IS"),
                std::string("!MODAL_WORD:YOUR"),
                std::string("!CONTENT:NAME")                   
    })));
    
    
}

recogn_pair patterns::recognizer::recognize(std::shared_ptr<machine::tokens> &ref_token)
{
    
    global::debug dbg(global::dbg);
     
    bool incorrect = false;

    for(auto map_it : this->pattern_map)
    {
        dbg.output(std::string("recognizer: checking for ") + map_it.first +
                std::string(" pattern"));
        
        if (map_it.second.size() > ref_token->token_vector.size())
        {
                dbg.output(std::string("recognizer: this pattern bigger than ref_token"));
                continue;
        }
        
        int i = 0;
        
        incorrect = false;
        for(auto vect_it : map_it.second)
        {
            dbg.output(vect_it);
            
            if (vect_it != ref_token->token_vector.at(i++))
            {
                dbg.output(std::string("recognizer: incorrect pattern, skipping."));
                incorrect = true;
                break;
            }
        }
        if (!incorrect)
            return map_it; // Found pattern! Yahooooooooooooooooo))))
    }
    
    return std::make_pair(std::string("404"), token_pattern({""}));
}