//Clair Harmsen
//Ezekiel Turnbough
// 2/23/2025


#include "location.hpp"
#include "Item.hpp"
#include "NPC.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <map>

/*
 * Location constructor
 * Takes string for name and description
 * has vectors for items and NPCs
 * has map for locations contaning locations and their neighbors
 * creates a location with the given inputs
*/

Location::Location(const std::string & n, const std::string& d)
: name(n), desc(d), visited(false){}

const std::map<std::string, Location*>& Location::get_locations() const{
    return neighbors;
}

// add location and raises errors if there is not location in that direction
// or location already exsists or there is no input
void Location::add_location(const std::string &dir, Location* location){
    if  (dir.empty()){
        throw std::invalid_argument("Please enter a direction");
    }
    if (neighbors.find(dir) != neighbors.end()){
        throw std::invalid_argument("Direction already exsists");
    }
    if (neighbors.find(dir) != neighbors.end()){
            throw std::invalid_argument("Invalid location");
    }
    neighbors[dir] = location;
}

/*adds a npc to a locations stored npcs
 *@param npc
 */
void Location::add_npc(const NPC & npc){
    npcs.push_back(npc);
}

/*
 *returns the npcs from a location
 */
const std::vector<NPC>& Location::get_npcs() const{
    return npcs;
}

/*
 *adds an item to a specific location
 *@param item
 */
void Location::add_item(const Item & item){
    items.push_back(item);
}

/*
 *returns item from a specific location
 */
std::vector<Item>& Location::get_items(){
    return items;
}

/*
 *sets a locations status to visited
 */
void Location::set_visited(){
    visited = true;
}

/*
 *returns the status of visited or not from a location
 *returns as a boolean value
 */
bool Location::get_visited() const{
    return visited;
}

/*
 *overloaded output operator
 *@param output Ostream to store the output
 * @param location with the info that is going to be outputted
 * returns an output stream of the locations information
 */
std::ostream & operator <<(std::ostream & output,  Location & location){

        output << location.GetName() << " - " << location.GetDesc() << "\n";
        output << "You see the following NPCs:\n";
        if (location.get_npcs().empty()) {
                output << " - None\n";
        }else {
                for (const auto& npc : location.get_npcs()) {
                        output << " - " << npc.GetName() << "\n";
                }
        }

        output << "You see the following items:\n";

        if (location.get_items().empty()) {
                output << " - None\n";
        } else {
                for (auto& item: location.get_items()) {
                        output << " - " << item.GetName() << " (" << item.GetCalories() << " calories) - " << item.GetWeight() << " lb - " << item.GetDescription() << "\n";
                }
        }

        output << "You can go in the following directions:\n";

        for (const auto& neighbor : location.get_locations()) {
                output << " - " << neighbor.first << " - " << neighbor.second->GetName();
                if (neighbor.second->get_visited()){
                        output << " (visited)";
                }
                output << "\n";
        }
        return output;

}


//Location.cpp