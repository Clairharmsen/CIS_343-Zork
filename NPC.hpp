// Ezekiel Turnbough
// Clair Harmsen
// 2/21/2025
//


#ifndef NPC_HPP
#define NPC_HPP

#include <string>
#include <vector>
#include <iostream>

/**
 * This is the NPC Class.
 * It is responsible for creating and storing the information of NPCs
 */
class NPC
{
private:
    // Name of the NPC
    std::string name;
    // NPC's Description
    std::string description;
    // Current Message of the NPC
    int message_number = 0;
    // List of the NPCs Messages
    std::vector<std::string> message_list;
public:
    // NPC Constructor
    NPC(const std::string& n, const std::string& d);

    // NPC Overloaded Ostream Opperator
    friend std::ostream & operator <<(std::ostream & output, const NPC & npc);

    // Name Getter, returns NPC name
    std::string GetName() const {return name;}
    // Description Getter, returns NPC description
    std::string GetDescription() const {return description;}
    // Message Getter
    std::string GetMessage();
    // Message Setter
    void SetMessage(const std::string& m);

};



#endif //NPC_HPP
