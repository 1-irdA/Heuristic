/**
 * @file Box.cpp
 * @author Adrien GARROUSTE - 1irda.alwaysdata.net
 * @brief Represent a box to put item inside
 * @version 0.1
 * @date 2021-01-06
 * @copyright No copyright no right
 */

#include <iostream>
#include "../headers/Box.hpp"

/**
 * @brief Construct a box object 
 * @param capacity box capacity
 */
Box::Box(unsigned int capacity) {
    this->capacity = capacity;
}

/**
 * @brief Add an item in box
 * @param to_add item to add
 */
void Box::put(const Item &to_add)
{
    if (to_add.get_size() <= this->capacity && to_add.get_size() > 0) {
        this->container.push_back(to_add);
        this->capacity -= to_add.get_size();
    }
}

/**
 * @brief Display box content
 */
void Box::display_content() {

    int total = 0;

    for (Item value : this->container) {
        std::cout << value.get_size() << " "; 
        total += value.get_size();
    }
    std::cout << " => Total : " << total << std::endl;
}

/**
 * @brief Return box capacity
 * @return unsigned int capacity
 */
unsigned int Box::get_capacity() {
    return this->capacity;
}