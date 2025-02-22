//
// Ezekiel Turnbough
// ADD YOUR NAME
//


#include "NPC.hpp"
#include <iostream>
#include <string>
#include <vector>

NPC::NPC(const std::string& n, const std::string& d)
{
    SetName(n);
    SetDescription(d);
}

std::string NPC::GetMessage()
{
    if (message_list.size() <= 0) {
        return "";
    }
    std::string message = message_list.at(message_number);
    message_number+= 1; if (message_number >= message_list.size()) message_number = 0;
    return message;
}

std::ostream & operator <<(std::ostream & output, const NPC & npc)
{
    output << npc.GetName() << "\n";
    return output;
}

void NPC::SetMessage(const std::string &m) {
    message_list.push_back(m);
}