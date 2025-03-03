//
// Ezekiel Turnbough
// Clair Harmsen
// 2/17/2025
//

#include "Item.hpp"

#include <iostream>
#include <string>

/**
 * Item Constructor
 * Takes a string for the name and description, an int for the calories, and a float for the weight
 * Throws exceptions for names and descriptions being empty.
 * Throws exceptions for calories and weight being out of range.
 * Creates an item with the given inputs.
 */
Item::Item(const std::string& n, const std::string& d, int c, float w)
{
    if (n.size() <= 0) {
        throw std::invalid_argument("Name cannot be empty");
    }
    if (d.size() <= 0) {
        throw std::invalid_argument("Description cannot be empty");
    }
    if (c < 0 || c > 1000) {
        throw std::invalid_argument("Calories must be between 0 and 1000");
    }

    if (w < 0 || w > 500) {
        throw std::invalid_argument("Weight must be between 0 and 500");
    }

    name = n;
    description = d;
    calories = c;
    weight = w;
}

/**
 * Item Overloaded Output Operator
 * @param output Ostream to store the output
 * @param item the item with the information to be sent to the output
 * @return An output stream formated with the item's information.
 */
std::ostream & operator <<(std::ostream & output, const Item & item)
{
    output << item.GetName() << " (" << item.GetCalories() << " calories) - " << item.GetWeight() << " lb - " << item.GetDescription() << "\n";
    return output;
}


