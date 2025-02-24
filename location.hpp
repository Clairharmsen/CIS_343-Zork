\//Clair Harmsen
//Add your name

#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "Item.hpp"
#include "NPC.hpp"

class Location{
    public:
    Location(const std::string& name, const std::string& desc);

    std::string GetName() const {return name;}
    std::string GetDesc() const {return desc;}

    void SetName(std::string n) {name = n;}
    void SetDesc(std::string d) {desc = d;}

    friend std::ostream & operator <<(std::ostream & output, const Location& loc);

    std::map<std::string, Location*> get_locations() const;
    void add_location(const std::string& direction, Location* location);

    void add_npc(const NPC& npc);
    std::vector<NPC> get_npcs() const;

    void add_item(const Item& item);
    std::vector<Item> get_items() const;

    void set_visited();

    bool get_visited() const;


    private:
    std::string name = "";
    std::string desc = "";
    bool visited = false;

    std::map<std::string, Location*> neighbors;
    std::vector<NPC> npcs;
    std::vector<Item> items;



};


#endif
