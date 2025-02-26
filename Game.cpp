//
// Ezekiel Turnbough
// Add your name
//

#include <ctime>
#include "Game.hpp"
#include <iostream>
#include <iomanip>


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

//Used ChatGPT to help with the descriptions, separating the elements into regions and connecting the regions.
void Game::CreateWorld() {
    // ====================== MACKINAC HALL ======================
    Location kirkhoff_center("Kirkhoff Upstairs", "The student union. There are restaurants, "
                                                  "a store, and places to congregate.");

    NPC barista("Barista", "A friendly barista who makes excellent coffee.");
    barista.SetMessage("Welcome to the coffee shop! What can I get for you?");
    barista.SetMessage("We're running a special on pumpkin spice lattes today!");
    barista.SetMessage("Long line today, huh? Everyone wants their caffeine fix.");
    kirkhoff_center.add_npc(barista);

    Item burrito("Burrito", "A warm, stuffed burrito with beans, rice, and meat.", 330, 2.7);
    Item coffee("Coffee", "A hot cup of strong, black coffee.", 50, 0.25);
    kirkhoff_center.add_item(burrito);
    kirkhoff_center.add_item(coffee);

    // ====================== MACKINAC HALL ======================
    Location mackinac_hall("Mackinac Hall", "A large academic building filled with classrooms and offices.");

    NPC teacher("Teacher", "A professor who loves teaching computer science.");
    teacher.SetMessage("Remember to submit your homework before midnight!");
    teacher.SetMessage("Coding is like magic, but with logic.");
    teacher.SetMessage("Need help with your project? Office hours are on Tuesdays.");
    mackinac_hall.add_npc(teacher);

    Item apple("Apple", "A fresh, crisp apple.", 100, 1.5);
    mackinac_hall.add_item(apple);

    // ====================== REC CENTER ======================
    Location rec_center("Rec Center", "The campus fitness center, where students can work out.");

    NPC athlete("Athlete", "A student who spends most of their time training in the gym.");
    athlete.SetMessage("Gotta keep pushing! Gains don’t come easy.");
    athlete.SetMessage("Hydration is key. Always drink plenty of water.");
    athlete.SetMessage("I benched 225 today! How about you?");
    rec_center.add_npc(athlete);

    Item weight("Dumbbell", "A heavy dumbbell used for strength training.", 0, 10);
    rec_center.add_item(weight);

    // ====================== BLUE CONNECTION ======================
    Location blue_connection("Blue Connection", "A dining area with various food options.");

    Item chicken("Grilled Chicken", "A well-seasoned grilled chicken breast.", 220, 3.5);
    Item chips("Chips", "A bag of salty, crunchy potato chips.", 320, 0.5);
    blue_connection.add_item(chicken);
    blue_connection.add_item(chips);

    // ====================== KLEINER ======================
    Location kleiner("Kleiner", "A smaller dining hall and study space.");

    Item book("Textbook", "A heavy textbook full of knowledge.", 0, 8.5);
    kleiner.add_item(book);

    // ====================== CALDER HALL ======================
    Location calder_hall("Calder Hall", "A residential hall for students.");

    NPC janitor("Janitor", "A hardworking staff member who keeps the dorms clean.");
    janitor.SetMessage("Please don’t leave your trash in the hallways.");
    janitor.SetMessage("I’ve been here for 20 years, and I’ve seen it all.");
    janitor.SetMessage("Some students don’t appreciate the work we do.");
    calder_hall.add_npc(janitor);

    // ====================== MANITOU HALL ======================
    Location manitou_hall("Manitou Hall", "An academic building home to many lecture halls.");

    Item computer("Laptop", "A high-end laptop used for coding and assignments.", 0, 24.5);
    manitou_hall.add_item(computer);

    // ====================== FRESH ======================
    Location fresh("Fresh", "A dining location offering fresh and healthy meal options.");

    NPC chef("Chef", "An expert in making delicious and healthy meals.");
    chef.SetMessage("Today’s special is grilled salmon with steamed veggies.");
    chef.SetMessage("Good food fuels the brain—eat well, study hard!");
    chef.SetMessage("If you don’t like what’s on the menu, there’s always cereal.");
    fresh.add_npc(chef);

    Item omelette("Omelette", "A freshly cooked omelette filled with vegetables and cheese.", 110, 2.5);
    Item cake("Cake", "A sweet chocolate cake slice.", 350, 0.25);
    fresh.add_item(omelette);
    fresh.add_item(cake);

    // ====================== LOCATION CONNECTIONS ======================
    kirkhoff_center.add_location("south", &calder_hall);
    kirkhoff_center.add_location("east", &blue_connection);
    kirkhoff_center.add_location("west", &mackinac_hall);
    kirkhoff_center.add_location("north", &rec_center);

    mackinac_hall.add_location("east", &kirkhoff_center);
    mackinac_hall.add_location("north", &manitou_hall);

    rec_center.add_location("south", &kirkhoff_center);

    blue_connection.add_location("west", &kirkhoff_center);
    blue_connection.add_location("north", &fresh);

    fresh.add_location("south", &blue_connection);

    kleiner.add_location("west", &mackinac_hall);

    calder_hall.add_location("north", &kirkhoff_center);

    manitou_hall.add_location("south", &mackinac_hall);
}


void Game::Start() {

}

//splits a given string into a vector of strings seperated by spaces
std::vector < std::string > Split(std::string text) {
    std::vector < std::string > sentence_split;
    std::stringstream word_stream(text);
    std::string replacement_string = "";
    while (getline(word_stream, replacement_string, ' ')) {
        // reads through the word stream and places the words seperated by spaces into a vector with a space at the end
        sentence_split.push_back(replacement_string + ' ');
    }
    sentence_split.at(sentence_split.size() - 1).pop_back();
    // removes the final space of the vector
    return sentence_split;
}