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
}

/**
 * @brief Construct a new Item object
 * @param size the space it takes up in the box
 */
Item::Item(unsigned int size) {
    this->size = size;
}

/**
 * @brief Return the space it takes up in the box
 * @return unsigned int size
 */
unsigned int Item::get_size() const {
    return this->size;
}