//
// Ezekiel Turnbough
// Add your name
//

#include <ctime>
#include "Game.hpp"


Game::Game(){
    commands = SetupCommands();
    CreateWorld();
    playing = true;
    current_location = RandomLocation();
}

//Clair
void Game::ShowHelp() {
}

//Clair
void Game::Go(std::vector<std::string> target) {
}

//Clair
void Game::Talk(std::vector<std::string> target) {
}

void Game::Give(std::vector<std::string> target) {
}

void Game::Look(std::vector<std::string> target) {
}

//Clair
void Game::Quit(std::vector<std::string> target) {
}

void Game::Take(std::vector<std::string> target) {
}

//Clair
void Game::ShowItem(std::vector<std::string> target) {
}

// Used ChatGPT to help with the show commands function
std::map<std::string, std::function<void(std::vector<std::string>)>> Game::SetupCommands() {
    std::map<std::string, std::function<void(std::vector<std::string>)>> all_commands;
    all_commands["help"] = [this](std::vector<std::string> args) { ShowHelp(); };
    all_commands["talk"] = [this](std::vector<std::string> args) { Talk(args); };
    all_commands["take"] = [this](std::vector<std::string> args) { Take(args); };
    all_commands["give"] = [this](std::vector<std::string> args) { Give(args); };
    all_commands["go"] = [this](std::vector<std::string> args) { Go(args); };
    all_commands["look"] = [this](std::vector<std::string> args) { Look(args); };
    all_commands["quit"] = [this](std::vector<std::string> args) { Quit(args); };
    return all_commands;
}

//Clair
Location* Game::RandomLocation() {

}

void Game::CreateWorld() {

}

void Game::Start() {

}
