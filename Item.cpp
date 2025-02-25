//
// Ezekiel Turnbough
// ADD YOUR NAME
//
#include "Item.hpp"

#include <iostream>
#include <string>


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

std::ostream & operator <<(std::ostream & output, const Item & item)
{
    output << item.GetName() << " (" << item.GetCalories() << " calories) - " << item.GetWeight() << " lb - " << item.GetDescription() << "\n";
    return output;
}


