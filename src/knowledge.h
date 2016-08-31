#ifndef KNOWLEDGE_H
#define KNOWLEDGE_H

#include <string>
#include <fstream>
#include <vector>
#include <map>

using WordArr = std::array<std::vector<std::string>, 3>;
using WordTypeMap = std::map<std::string, size_t>;

namespace database
{
    class word_data // data about tokens and words class interpretator
    {
    public:
        void load_data(std::string&& filename); // load data from file db
        bool ok();
        WordArr get();
        WordTypeMap map();
        
    private:
        std::fstream fin;
        
        
        WordArr data; // contains reserved words
        WordTypeMap word_types; // tempory for internal use
        std::map<std::string, std::string> content_answ;
    };
}

#endif /* KNOWLEDGE_H */

