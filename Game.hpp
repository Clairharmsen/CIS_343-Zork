//
// Ezekiel Turnbough
// Clair Harmsen
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

/**
 * This is the Game class
 * It is responsible for the information about the game.
 */
class Game {
private:
    // Function used to setup the commands
    std::map<std::string, std::function<void(std::vector<std::string>)>> SetupCommands();
    // Calories needed to win the game
    int calories_needed = 500;
    // Player's current weight
    int player_weight = 0;
    // Value indicating if the game is currently being played
    bool playing;
    // Current location in the game.
    Location* current_location;
    // The player's current items.
    std::vector<Item> items;
    // All the locations in the game.
    std::vector<Location> locations;

public:
    // Game Constructor
    Game();
    // Play function
    void Play();
    // All the possible commands to run
    std::map<std::string, std::function<void(std::vector<std::string>)>> commands;
    // Create World function
    void CreateWorld();
    // Show Help function
    void ShowHelp();
    // Go function
    void Go(std::vector<std::string> target);
    // Meet function
    void Meet(std::vector<std::string> target);
    // Give function
    void Give(std::vector<std::string> target);
    // Look function
    void Look(std::vector<std::string> target);
    // Quit function
    void Quit(std::vector<std::string> target);
    // Take function
    void Take(std::vector<std::string> target);
    // Show item function
    void ShowItem(std::vector<std::string> target);
    // Eat function
    void Eat(std::vector<std::string> target);
    // Drop function
    void Drop(std::vector<std::string> target);
    // Random location function
    Location* RandomLocation();
};



#endif //GAME_HPP
