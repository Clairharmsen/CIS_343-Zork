// Clair Harmsen
// Ezekiel Turnbough
// 2/23/2025


#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "Item.hpp"
#include "NPC.hpp"

/*
 * This is the location class
 * It creates and stores locations names, descriptions and
 * a map of all the locations
 */

class Location{
    public:
    // location constructor
    Location(const std::string& name, const std::string& desc);
    // name getter that returns the name of the loc
    std::string GetName() const {return name;}
    // description getter than returns the desc of the loc
    std::string GetDesc() const {return desc;}

    //name setter
    void SetName(std::string n) {name = n;}
    //name getter
    void SetDesc(std::string d) {desc = d;}

    // location overloaded Ostream operator
    friend std::ostream & operator <<(std::ostream & output,  Location& loc);

    // map of all locations
    const std::map<std::string, Location*>& get_locations() const;

    //add location function
    void add_location(const std::string& direction, Location* location);

    // add npc function
    void add_npc(const NPC& npc);

    // vector of NPCS
    const std::vector<NPC>& get_npcs() const;

    // add item funtion
    void add_item(const Item& item);

    // vector of items
    std::vector<Item>& get_items() ;

    // visited function
    void set_visited();

    // get visited funtion that returns boolean
    bool get_visited() const;


    private:

    // name of location
    std::string name = "";

    // description of location
    std::string desc = "";

    // sets visited to false for all locations at the start of the game
    bool visited = false;

    // map of all locations and their neighbors
    std::map<std::string, Location*> neighbors;

    // vector of NPCs
    std::vector<NPC> npcs;

    // vector of items
    std::vector<Item> items;



};


#endif
