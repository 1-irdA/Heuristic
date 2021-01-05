/**
 * @file Item.cpp
 * @author Adrien GARROUSTE - 1irda.alwaysdata.net
 * @brief Class who represent a value to put in box
 * @version 0.1
 * @date 2021-01-04
 * @copyright CNo copyright no right
 */

#include "../headers/Item.hpp"

/**
 * @brief Default constructor
 */
Item::Item() {
    this->size = 0;
    this->is_taken = false;
}

/**
 * @brief Construct a new Item object
 * @param size the space it takes up in the box
 */
Item::Item(unsigned int size) {
    this->size = size;
    this->is_taken = false;
}

/**
 * @brief Return the space it takes up in the box
 * @return unsigned int size
 */
unsigned int Item::get_size() const {
    return this->size;
}

/**
 * @brief Set the taken attriubte
 * @return true if this object is in a box
 * @return false else
 */
bool Item::get_is_taken() {
    return this->is_taken;
}

/**
 * @brief Set is taken attribute
 * @param taken true of false
 */
void Item::set_is_taken(bool taken) {
    this->is_taken = taken;
}