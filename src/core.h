#ifndef CORE_H
#define CORE_H

#include <memory>
#include "tokens.h"
#include <string>
#include "knowledge.h"

namespace core
{
    
  
    class core
    {
    public:
    
        core(std::string filename);
        
        /* build a token vector by input string
         example:
           WHERE ARE YOU FROM?
         * [0]:  !ASK_WORD:WHERE // ASK WORD TYPE: WHERE
         * [1]:  !TOBE_WORD:ARE // TO BE GLAGOL WORD TYPE: ARE
         * [2]:  !MODAL_WORD:YOU // MODAL WORD TYPE: YOU
         * [3]:  !CONTENT:FROM? // CONTENT OF SENTENCE: FROM?
        */
        std::shared_ptr<machine::tokens> lexer(std::string input_str);
        
        // reform input token to ouput token
        std::shared_ptr<machine::tokens> understand(
            std::shared_ptr<machine::tokens>& ref_tokens); 
        
        // build output string from output token
        std::string build(std::shared_ptr<machine::tokens>& ref_tokens);
        
        
        
    private:
        bool inited;
        database::word_data wd;
    };
}

#endif /* CORE_H */

