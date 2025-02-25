//
// Ezekiel Turnbough
// ADD YOUR NAME
//

#ifndef NPC_HPP
#define NPC_HPP

#include <string>
#include <vector>
#include <iostream>

class NPC
{
private:
    std::string name;
    std::string description;
    int message_number = 0;
    std::vector<std::string> message_list;
public:
    NPC(const std::string& n, const std::string& d);

    friend std::ostream & operator <<(std::ostream & output, const NPC & npc);

    std::string GetName() const {return name;}
    std::string GetDescription() const {return description;}
    std::string GetMessage();
    void SetMessage(const std::string& m);

};



#endif //NPC_HPP
