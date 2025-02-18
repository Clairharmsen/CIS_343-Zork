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
        Item(const std::string& n, const std::string& d, int c, float w);

        friend std::ostream & operator <<(std::ostream & output, const Item & item1);

        std::string GetName() const {return name;}
        std::string GetDescription() const {return description;}
        int GetCalories() const {return calories;}
        float GetWeight() const {return weight;}


        void SetName(const std::string& n)
        {
            if (n.size() <= 0) {
                throw std::invalid_argument("Item name cannot be empty");
            }
            name = n;
        }
        void SetDescription(const std::string& d) {
            if (d.size()<= 0) {
                throw std::invalid_argument("Item description cannot be empty");
            }
            description = d;
        }
        void SetCalories(int cal) {
            if ((0 > cal) or (cal > 1000)) {
                throw std::invalid_argument("Item calories out of range. Must be between 0 and 1000");
            }
            calories = cal;
        }
        void SetWeight(float w) {
            if ((0 > w) or (w > 500)){
                throw std::invalid_argument("Item weight out of range. Must be between 0 and 500");
            }
            weight = w;
        }
};



#endif //ITEM_HPP
