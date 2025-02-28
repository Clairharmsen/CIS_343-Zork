//
// Ezekiel Turnbough
// Clair Harmsen
//

#include <ctime>
#include "Game.hpp"
#include <iostream>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <string>


Game::Game(){
    commands = SetupCommands();
    CreateWorld();
    playing = true;
    current_location = RandomLocation();
}

void Strip(std::string &word) {
    if (word.at(word.size() - 1) == ' ') {
        word.erase(word.end() - 1);
    }
}

//Used ChatGPT to help with the show time part
void Game::ShowHelp() {
    std::time_t now = std::time(nullptr);
    std::tm* local_time = std::localtime(&now);

    std::cout << "\nCurrent time: " << std::put_time(local_time, "%I:%M:%S %p") << std::endl;

    std::cout << "======Help Menu======\n";
    std::cout << "Goal of the game:\n You need to bring 500 calories of edible food\n" <<
    "to the elf in the woods behind campus. Once the elf has 500 calories of edible food it will save campus\n" <<
    "You may only carry 30 pounds at a time\n";

    std::cout << "You may use the following commands:\n";

    for (const auto& command : commands){
        std::cout << command.first << "\n";
    }
}

//Clair
void Game::Go(std::vector<std::string> target) {
    if (target.empty()){
      std::cout << "Where would you like to go?\n";
      return;
    }

    std::string direction = target[0];

    if (player_weight > 30){
      std::cout << "You cannot move when you are carrying more than 30 pounds\n";
      return;
    }

    std::map<std::string, Location*> neighbors = current_location->get_locations();

    if (neighbors.find(direction) != neighbors.end()){
      current_location =  neighbors[direction];

      current_location->set_visited();

      std::cout << "You are now at: " << *current_location << "\n";
    }
    else {
      std::cout << "You cannot move in that direction\n";
      }
}


//Clair
void Game::Meet(std::vector<std::string> target) {
  std::vector<NPC> npcs = current_location->get_npcs();

  if(npcs.empty()){
    std::cout << "There is no one else here\n";
  return;}

  std::cout << "You see the following person\n";
  for (const auto& npc : npcs){
    std::cout << npc.GetName() << " - " << npc.GetDescription() << "\n";
  }
}

void Game::Give(std::vector<std::string> target) {
    auto it = std::find_if(items.begin(), items.end(),
        [&](const Item& item) { return item.GetName() == target[0]; });

    if (it != items.end()){
        if (it->GetCalories() > 0) {
            calories_needed -= it->GetCalories();
            player_weight -= it->GetCalories();
            std::cout << "The elf ate the " << it->GetName() << "\n";
            std::cout << "The elf needs " << calories_needed << "more calories\n";
            items.erase(it);
        }
        else {
            std::cout << "That item is not edible\n";
            std::cout << "The elf got angry and sent you to a different place.\n";
            current_location = RandomLocation();
        }
    }
    else {
        std::cout << "You don't have that item\n";
    }
}




void Game::Look(std::vector<std::string> target) {
    std::cout << "You are currently at: " << *current_location << std::endl;
    std::vector<NPC> npcs = current_location->get_npcs();
    std::vector<Item> items = current_location->get_items();

    if(npcs.empty()){
        std::cout << "You are alone.\n";
        return;}

    std::cout << "You see the following people\n";
    for (const auto& npc : npcs){
        std::cout << npc.GetName() << "\n";
    }

    if(items.empty()){
        std::cout << "The room has no items to grab.\n";
        return;}

    std::cout << "You see the following items\n";
    for (const auto& it : items){
        std::cout << it.GetName() << "\n";
    }

    const std::map<std::string, Location*>& neighbors = current_location->get_locations();

    std::cout << "You can go in the following directions:\n";
    for (const auto& entry : neighbors) {
        std::string direction = entry.first;

        // Check if location has been visited before
        if (entry.second->get_visited()) {
            std::cout << "- " << direction << " (" << entry.first << ")\n";
        } else {
            std::cout << "- " << direction << "\n";
        }
    }
}

void Game::Quit(std::vector<std::string> target) {
    std::cout << "Thanks for playing!\n";
    playing = false;
}

void Game::Take(std::vector<std::string> target) {
    if (target.empty()) {
        std::cout << "Take what?\n";
        return;
    }

    std::string item_name = target[0]; // Assumes the item name is a single word
    Strip(item_name);

    // Get a reference to the location's item list
    std::vector<Item>& items_list = current_location->get_items();

    // Loop through the items in the current location
    for (auto it = items_list.begin(); it != items_list.end(); ++it) {
        if (it->GetName() == item_name) {
            // Add item to player's inventory
            items.push_back(*it);
            player_weight += it->GetWeight();

            // Remove item from the location's inventory
            items_list.erase(it);

            std::cout << "You picked up the " << item_name << ".\n";
            return;
        }
    }
}
//Clair
void Game::ShowItem(std::vector<std::string> target) {
    std::cout << "You are carrying the following items:\n";

    if (items.empty()) {
        std::cout << "You have no items\n";
        return;
    }
    for (const auto& item : items) {
        std::cout << item.GetName() << ", weight: " << item.GetWeight() << "\n";
    }

    float total_weight = 0;
    for (const auto& item : items) {
        total_weight += item.GetWeight();
    }
    std::cout << "Total weight you are carrying is: " << total_weight << "\n";
}

void Game::Drop(std::vector<std::string> target){
    if (items.empty()) {
        std::cout << "You have no items to drop. \n";
        return;
    }

    if (target.empty()) {  // Check if an item name was provided
        std::cout << "Drop what?\n";
        return;
    }

    std::string item_name = target[0]; // Assumes the item name is a single word
    Strip(item_name);

    // Get a reference to the location's item list
    std::vector<Item>& items_list = current_location->get_items();

    // Loop through the items you currently have
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->GetName() == item_name) {
            // Remove item to player's inventory
            player_weight -= it->GetWeight();
            current_location->add_item(*it);

            // Remove item from the location's inventory
            items.erase(it);

            std::cout << "You dropped the " << item_name << " at " << current_location << ".\n";
            return;
        }
    }
}


// Used ChatGPT to help with the show commands function
std::map<std::string, std::function<void(std::vector<std::string>)>> Game::SetupCommands() {
    std::map<std::string, std::function<void(std::vector<std::string>)>> all_commands;
    all_commands["help"] = [this](std::vector<std::string> args) { ShowHelp(); };
    all_commands["meet"] = [this](std::vector<std::string> args) { Meet(args); };
    all_commands["take"] = [this](std::vector<std::string> args) { Take(args); };
    all_commands["give"] = [this](std::vector<std::string> args) { Give(args); };
    all_commands["go"] = [this](std::vector<std::string> args) { Go(args); };
    all_commands["look"] = [this](std::vector<std::string> args) { Look(args); };
    all_commands["quit"] = [this](std::vector<std::string> args) { Quit(args); };
    all_commands["eat"] = [this](std::vector<std::string> args) { Eat(args); };
    all_commands["show"] = [this](std::vector<std::string> args) { ShowItem(args); };
    all_commands["drop"] = [this](std::vector<std::string> args) { Drop(args); };
    return all_commands;
}

//Used Chatgpt to help with random seeding logic
Location* Game::RandomLocation() {
  static bool seeded = false;
  if (!seeded){
    std::srand(std::time(nullptr));
    seeded = true;
  }
    int random_index = std::rand() % locations.size();
    return &locations[random_index];
}

//Used ChatGPT to help with the finding item in inventory loop
void Game::Eat(std::vector<std::string> target) {
    std::string input;
    std::cout << "What item would you like to eat?";
    std::getline(std::cin, input);

    auto it = std::find_if(items.begin(), items.end(),
        [&](const Item& item) { return item.GetName() == input; });

    if (it != items.end()){
        if (it->GetCalories() > 0) {
            std::cout << "You ate the " << it->GetName() << "\n";
            items.erase(it);
            }
        else {
            std::cout << "That item is not edible\n";}
            }
    else {
            std::cout << "You don't have that item\n";
    }
}


//Used ChatGPT to help with the descriptions, separating the elements into regions and connecting the regions.
//Descriptions were proofread for accuracy.
void Game::CreateWorld() {
    // ====================== MACKINAC HALL ======================
    Location kirkhoff_center("Kirkhoff Center", "The student union. There are restaurants, "
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
    Location mackinac_hall("Mackinac Hall", "A large academic building "
                                            "filled with classrooms and offices.");

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
    Location blue_connection("Blue Connection", "A dining area helpful for late night snacks.");

    Item chicken("Grilled Chicken", "A well-seasoned grilled chicken breast.", 420, 5.5);
    Item chips("Chips", "A bag of salty, crunchy potato chips.", 320, 0.5);
    blue_connection.add_item(chicken);
    blue_connection.add_item(chips);

    // ====================== KLEINER ======================
    Location kleiner("Kleiner", "A smaller dining hall and study space.");

    Item book("Textbook", "A heavy textbook full of knowledge.", 0, 8.5);
    kleiner.add_item(book);

    // ====================== CALDER HALL ======================
    Location calder_hall("Calder Hall", "A residential hall for students.");

    NPC janitor("Janitor", "A hardworking staff member who keeps the campus clean.");
    janitor.SetMessage("Please don’t leave your trash in the hallways.");
    janitor.SetMessage("I’ve been here for 20 years, and I’ve seen it all.");
    janitor.SetMessage("Some students don’t appreciate the work we do.");
    calder_hall.add_npc(janitor);

    // ====================== MANITOU HALL ======================
    Location manitou_hall("Manitou Hall", "An academic building with a large computer lab.");

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

    locations.push_back(kirkhoff_center);
    locations.push_back(mackinac_hall);
    locations.push_back(rec_center);
    locations.push_back(blue_connection);
    locations.push_back(kleiner);
    locations.push_back(calder_hall);
    locations.push_back(manitou_hall);
    locations.push_back(fresh);
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

void Game::Play() {
    std::cout << "Welcome to Grand Valley's Zork Experience" << std::endl;
    std::cout << "Your goal is to gather enough food to feed an elf in need." << std::endl;
    std::cout << "You have 10 turns to do so" << std::endl;
    std::cout << "You must explore the campus and gather 500 calories worth of food to help the elf" << std::endl;
    int num_turns = 10;

    while (playing) {
        std::cout << "You are currently at: " << *current_location << std::endl;
        std::cout << "What is your command? " << std::endl;
        std::string input;

        std::getline(std::cin, input);

        // Split input into words
        std::vector<std::string> tokens = Split(input);

        // Ensure input is not empty
        if (tokens.empty()) {
            std::cout << "Invalid input. Please enter a command.\n";
            continue;
        }

        // Extract command and target
        std::string command = tokens[0];
        Strip(command);
        tokens.erase(tokens.begin()); // Remove first word
        std::string target;
        for (int i = 0; i < tokens.size(); i++) {
            target += tokens[i];
        }
        //std::string target = std::accumulate(tokens); // Join remaining words into a string

        // Execute command if found
        if (commands.find(command) != commands.end()) {
            commands[command](tokens);
            num_turns--;
        } else {
            std::cout << "Unknown command: " << command << "\n";
        }

        if (num_turns <= 0) {
            playing = false;
        }
    }

    // ========================= Game End Conditions =========================
    if (calories_needed <= 0) {
        std::cout << "Congratulations! You ate enough food and won the game!\n";
        playing = false;

    } else {
        std::cout << "You didn't consume enough calories. Game over.\n";
        playing = false;
    }
}

