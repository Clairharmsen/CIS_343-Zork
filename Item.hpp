//
// Ezekiel Turnbough
// ADD YOUR NAME
// ADD YOUR NAME
//

#ifndef ITEM_HPP
#define ITEM_HPP


#include <string>
#include <iostream>

class Item
{
    private:
        std::string name = "";
        std::string description = "";
        int calories = 0;
        float weight = 0.f;
    public:
        Item(std::string n, std::string d, int c, float w);

        friend std::ostream & operator <<(std::ostream & output, Item & item1);

        std::string GetName() const {return name;}
        std::string GetDescription() const {return description;}
        int GetCalories() const {return calories;}
        float GetWeight() const {return weight;}


        void SetName(std::string n) {name = n;}
        void SetDescription(std::string d) {description = d;}
        void SetCalories(int cal) {calories = cal;}
        void SetWeight(float w) {weight = w;}
};



#endif //ITEM_HPP
