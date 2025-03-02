//
// Ezekiel Turnbough
// Clair Harmsen
//

#ifndef ITEM_HPP
#define ITEM_HPP


#include <string>
#include <iostream>

/*
 * This is the Item class.
 * It is responsible for the creation of items and storing their data.
 */
class Item
{
    private:
    // Item name
    std::string name = "";
    // Item description
    std::string description = "";
    // Item Calories
        int calories = 0;
    //Item weight
        float weight = 0.f;
    public:
    // Item Constructor
        Item(const std::string& n, const std::string& d, int c, float w);
    // Item Output Operator
        friend std::ostream & operator <<(std::ostream & output, const Item & item1);

    // Name Getter, returns the name of the item
        std::string GetName() const {return name;}

    // Description Getter, returns the description of the item
        std::string GetDescription() const {return description;}

    // Calorie Getter, returns the number of calories an item is.
        int GetCalories() const {return calories;}
    // Weight Getter, returns the weight of an item.
        float GetWeight() const {return weight;}
};



#endif //ITEM_HPP
