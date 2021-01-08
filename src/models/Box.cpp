/**
 * @file Box.cpp
 * @author Adrien GARROUSTE - 1irda.alwaysdata.net
 * @brief Represent a box to put item inside
 * @version 0.1
 * @date 2021-01-06
 * @copyright No copyright no right
 */
#include "../headers/Box.hpp"
#include <iostream>

/**
 * @brief Construct a box object 
 * @param capacity box capacity
 */
Box::Box(int capacity) {
    this->capacity = capacity;
}

/**
 * @brief Add an item in box
 * @param to_add item to add
 */
void Box::put(const int &to_add) {
    if (to_add <= this->capacity && to_add > 0) {
        this->container.push_back(to_add);
        this->capacity -= to_add;
    }
}

/**
 * @brief Display box content
 */
void Box::display_content() const {

    int total = 0;

    for (int item : this->container) {
        std::cout << item << " "; 
        total += item;
    }
    std::cout << " => Total : " << total << std::endl;
}

/**
 * @brief Return box capacity
 * @return int capacity
 */
int Box::get_capacity() const {
    return this->capacity;
}