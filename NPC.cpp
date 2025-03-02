//
// Ezekiel Turnbough
// Clair Harmsen
//


#include "NPC.hpp"
#include <iostream>
#include <string>
#include <vector>

/**
 * NPC Constructor
 * Creates an NPC with the given information.
 * @param n The name of the NPC cannot be empty
 * @param d The description of the NPC cannot be empty
 */
NPC::NPC(const std::string& n, const std::string& d)
{
    if (n.size() <= 0) {
        throw std::invalid_argument("NPC name cannot be empty");
    }
    name = n;
    if (d.size()<= 0) {
        throw std::invalid_argument("NPC description cannot be empty");
    }
    description = d;
}

/**
 * Gets the current message of the NPC
 * @return The NPC's message
 */
std::string NPC::GetMessage()
{
    // Returns empty string if the NPC doesn't have any messages.
    if (message_list.size() <= 0) {
        return "";
    }
    // Gets the message that the NPC is currently on
    std::string message = message_list.at(message_number);
    // Moves to the next message.
    // If the message is the last in the list, loop back to the beginning
    message_number+= 1; if (message_number >= message_list.size()) message_number = 0;
    // Return the message.
    return message;
}

/**
 * Overloaded output operator
 * @param output Ostream to store the output.
 * @param npc NPC with the information to be sent to the output
 * @return An output stream formatted with the NPCs information
 */
std::ostream & operator <<(std::ostream & output, const NPC & npc)
{
    output << npc.GetName() << "\n";
    return output;
}

/**
 * Sets a message in the message list
 * @param m message to be added to the message list.
 */
void NPC::SetMessage(const std::string &m) {
    message_list.push_back(m);
}