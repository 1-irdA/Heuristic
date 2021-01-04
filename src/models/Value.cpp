/**
 * @file Value.cpp
 * @author Adrien GARROUSTE - 1irda.alwaysdata.net
 * @brief Class who represent a value to put in box
 * @version 0.1
 * @date 2021-01-04
 * @copyright CNo copyright no right
 */

#include "../headers/Value.hpp"

/**
 * @brief Construct a new value object
 * @param size the space it takes up in the box
 */
Value::Value(unsigned int size)
{
    this->size = size;
    this->is_taken = false;
}

/**
 * @brief Return the space it takes up in the box
 * @return unsigned int size
 */
unsigned int Value::get_size() const
{
    return this->size;
}

/**
 * @brief Set the value if is taken of not
 * @return true if this object is in a box
 * @return false else
 */
bool Value::get_is_taken() {
    return this->is_taken;
}

/**
 * @brief Set is taken attribute
 * @param taken true of false
 */
void Value::set_is_taken(bool taken) {
    this->is_taken = taken;
}