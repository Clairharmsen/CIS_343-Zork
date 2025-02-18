//
// Ezekiel Turnbough
// ADD YOUR NAME
// ADD YOUR NAME
//
#include "Item.hpp"

#include <iostream>
#include <string>


Item::Item(std::string n, std::string d, int c, float w)
{
    if (n.size() == 0)
    {
        std::cout << "Name must not be empty\n";
        return;
    }
    else
    {
        name = n;
    }

    if (d.size() == 0)
    {
        std::cout << "Description must not be empty\n";
        return;
    }
    else
    {
        description = d;
    }

    if ((c < 0) or (c > 1000))
    {
        std::cout << "Calories must be between 0 and 1000\n";
        return;
    }
    else
    {
        calories = c;
    }


    if ((w < 0) or (w > 500))
    {
        std::cout << "Weight must be between 0 and 500\n";
        return;
    }
    else
    {
        weight = w;
    }
}

std::ostream & operator <<(std::ostream & output, Item & item)
{
    if ((item.GetName().size() == 0) or (item.GetDescription().size() == 0) or ((0 > item.GetCalories())
    or (item.GetCalories() > 1000)) or ((item.GetWeight() < 0) or (item.GetWeight() > 500)))
    {
        output << "There is an error with one of the values.\n";
    }
    else
    {
        output << item.GetName() << " (" << item.GetCalories() << " calories) - " << item.GetWeight() << " lb - " << item.GetDescription() << "\n";
    }
    return output;
}


int main()
{
    Item def("Banana", "The banana is a yellow fruit.", 50, 0.25);
    std::cout << def;
    return 0;
}
