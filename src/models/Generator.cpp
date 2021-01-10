#include "../headers/Generator.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

/**
 * @brief Generate random numbers and return them in dynamic array
 * @param nb_items number of items to generate
 * @param max max item possible
 * @return std::vector<int> dynamic array with integers
 */
std::vector<int> Generator::generate_items(int nb_items, int max) {

    // Use random
    std::srand(std::time(nullptr));
    std::vector<int> items;

    for (int i = 0; i < nb_items; i++) {
        int item = (rand() % max) + 1;
        items.push_back(item);
    }

    return items;
}