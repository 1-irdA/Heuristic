#include "../headers/Value.hpp"

Value::Value(unsigned int size)
{
    this->size = size;
    this->is_taken = false;
}

unsigned int Value::get_size() const
{
    return this->size;
}

bool Value::get_is_taken() {
    return this->is_taken;
}

void Value::set_is_taken(bool taken) {
    this->is_taken = taken;
}