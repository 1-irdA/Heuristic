#ifndef __BOX__
#define __BOX__

#include "Value.hpp"
#include <vector>

class Box {

    private:

    unsigned int capacity;

    std::vector<Value> container;    

    public:

    Box(unsigned int capacity);

    void put(Value &value);

    unsigned int get_capacity();

    void display_content();
};

#endif