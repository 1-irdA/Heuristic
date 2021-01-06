#ifndef __BOX__
#define __BOX__

#include <string>
#include <vector>
#include "Item.hpp"


class Box {

    private:

    unsigned int capacity;

    std::vector<Item> container;    

    public:

    Box(unsigned int capacity);

    void put(const Item &value);

    unsigned int get_capacity();

    void display_content();
};

#endif