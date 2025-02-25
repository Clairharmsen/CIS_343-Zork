//Clair Harmsen
//Ezekiel Turnbough

#include "location.hpp"
#include "Item.hpp"
#include "NPC.hpp"

#include <string>
#include <iostream>
#include <vector>
#include <map>

Location::Location(const std::string & n, const std::string& d)
: name(n), desc(d), visited(false){}

const std::map<std::string, Location*>& Location::get_locations() const{
    return neighbors;
}

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

void Location::add_npc(const NPC & npc){
    npcs.push_back(npc);
}

const std::vector<NPC>& Location::get_npcs() const{
    return npcs;
}

void Location::add_item(const Item & item){
    items.push_back(item);
}

const std::vector<Item>& Location::get_items() const{
    return items;
}

void Location::set_visited(){
    visited = true;
}

bool Location::get_visited() const{
    return visited;
}

std::ostream & operator <<(std::ostream & output, const Location & location){

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
                for (const auto& item: location.get_items()) {
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