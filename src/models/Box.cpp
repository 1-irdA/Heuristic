#include <iostream>
#include "../headers/Box.hpp"

Box::Box(unsigned int capacity) {
    this->capacity = capacity;
}

void Box::put(Item &to_add)
{
    if (!to_add.get_is_taken() && to_add.get_size() <= this->capacity) {
        this->container.push_back(to_add);
        to_add.set_is_taken(true);
        this->capacity -= to_add.get_size();
    }
}

void Box::display_content() {

    int total = 0;

    for (Item value : this->container) {
        std::cout << value.get_size() << " "; 
        total += value.get_size();
    }
    std::cout << " => Total : " << total << std::endl;
}

unsigned int Box::get_capacity() {
    return this->capacity;
}