//
// Ezekiel Turnbough
// ADD YOUR NAME
// ADD YOUR NAME
//
#include "Item.hpp"

#include <iostream>
#include <string>


Item::Item(const std::string& n, const std::string& d, int c, float w)
{
    SetName(n);
    SetDescription(d);
    SetCalories(c);
    SetWeight(w);
}

std::ostream & operator <<(std::ostream & output, const Item & item)
{
    output << item.GetName() << " (" << item.GetCalories() << " calories) - " << item.GetWeight() << " lb - " << item.GetDescription() << "\n";
    return output;
}


int main()
{
    Item def("Banana", "The banana is a yellow fruit.", 50, 0.25);
    std::cout << def;
    return 0;
}
