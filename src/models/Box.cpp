#include <iostream>
#include "../headers/Box.hpp"

Box::Box(unsigned int capacity) {
    this->capacity = capacity;
}

void Box::put(Value &to_add)
{
    this->container.push_back(to_add);
    to_add.set_is_taken(true);
    this->capacity -= to_add.get_size();
}

void Box::display_content() {

    for (Value value : this->container) {
        std::cout << value.get_size() << " "; 
    }
    std::cout << std::endl;
}

unsigned int Box::get_capacity() {
    return this->capacity;
}