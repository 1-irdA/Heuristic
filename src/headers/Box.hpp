#ifndef __BOX__
#define __BOX__

#include "Item.hpp"
#include <vector>

class Box {

    private:

    unsigned int capacity;

    std::vector<Item> container;    

    public:

    Box(unsigned int capacity);

    void put(Item &value);

    unsigned int get_capacity();

    void display_content();
};

#endif