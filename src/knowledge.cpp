#include "global.h"

bool database::word_data::ok()
{
    return !this->fin.fail();
}


/*
!ASK_WORD
where
why
what
how
!TOBE_WORD
am
is
are
!MODAL_WORD
I
ME
WE
YOU
HE
YOUR
THEY
THERE
HERE
!WORD_END
 */

WordArr database::word_data::get()
{
    return this->data;
}

WordTypeMap database::word_data::map()
{
    return this->word_types;
}

void database::word_data::load_data(std::string &&str)
{
    global::debug dbg(global::dbg);
    
    dbg.output("database::word_data loader");
    dbg.output(std::string("Reading file: ") + str);
    
    this->word_types.insert(std::pair<std::string, size_t>("!ASK_WORD", 0));
    this->word_types.insert(std::pair<std::string, size_t>("!TOBE_WORD", 1));
    this->word_types.insert(std::pair<std::string, size_t>("!MODAL_WORD", 2));
    this->word_types.insert(std::pair<std::string, size_t>("!WORD_END", 3));
    
    this->fin = std::fstream(str, std::fstream::in);
    
    if (!this->fin.fail())
    {        
        std::string line;
        size_t index = 0;
        while(!this->fin.eof())
        {
            std::getline(fin, line);
            auto it_value = this->word_types.find(line);
            if (it_value != this->word_types.end())
            {
                index = it_value->second;
                dbg.output(std::string("Reached ") + it_value->first);
                if (index == 3)
                {
                    dbg.output("database::load_data reached WORD_END");
                    
                    if (global::dbg)
                    {
                        int i = 0;
                        for(auto arr_it : this->data)
                        {
                            std::cout << i << ": ";
                            i++;
                            for(auto vect_it : arr_it)
                            {
                                dbg.output(vect_it);
                            }
                            std::cout << std::endl;
                        }
                    }
                    break;
                }
            } else
                this->data[index].emplace_back(line);
        }
        this->fin.close();
    } else
    {
        dbg.output("database:load_data cant load file");
        throw std::runtime_error(str + std::string(" failbit when open"));
    }
}