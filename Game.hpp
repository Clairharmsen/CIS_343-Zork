//
// Ezekiel Turnbough
// Add your name
//

#ifndef GAME_HPP
#define GAME_HPP

#include  <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include "NPC.hpp"
#include "location.hpp"
#include "Item.hpp"

class Game {
private:
    std::map<std::string, std::function<void(std::vector<std::string>)>> SetupCommands();
    int calories_needed = 500;
    int player_weight = 0;
    bool playing;
    Location* current_location;

public:
    Game();
    void Start();
    std::map<std::string, std::function<void(std::vector<std::string>)>> commands;
    void CreateWorld();

    void ShowHelp();
    void Go(std::vector<std::string> target);
    void Talk(std::vector<std::string> target);
    void Give(std::vector<std::string> target);
    void Look(std::vector<std::string> target);
    void Quit(std::vector<std::string> target);
    void Take(std::vector<std::string> target);
    void ShowItem(std::vector<std::string> target);
    Location* RandomLocation();



};



#endif //GAME_HPP
