#include "../headers/Utils.hpp"
#include <iostream>
#include <vector>

/**
 * @brief Display values in vector
 * @param to_display vector with values to display
 */
void Utils::display(std::vector<int> to_display) {
    std::cout << "\nItems : " << std::endl;
    for (int item : to_display) {
        std::cout << item << " ";            
    }
    std::cout << std::endl;
}