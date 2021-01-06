/**
 * @file Input.cpp
 * @author Adrien GARROUSTE - 1irda.alwaysdata.net
 * @brief Check user input
 * @version 0.1
 * @date 2021-01-06
 * @copyright No copyright no right
 */
#include <iostream>
#include <limits>
#include <vector>
#include "../headers/Input.hpp"

/**
 * @brief Min size for boxes and items
 */
const int MIN_SIZE = 0;

/**
 * @brief Check user input for box size
 * @return int a valid box size
 */
int Input::secure_box_size() {

    int boxes_size;

    while (!(std::cin >> boxes_size) || boxes_size <= MIN_SIZE) {
        if (std::cin.fail()) {
            std::cout << "Error !" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cout << "Error ! Box size must be greater than " << MIN_SIZE << std::endl;
        }
        std::cout << "> ";
    }

    return boxes_size;
}

/**
 * @brief Check user input for item size
 * @param max_size box size
 * @return int a valid item size
 */
int Input::secure_item_size(int max_size) {

    int item_size;

    while (!(std::cin >> item_size) || item_size < MIN_SIZE || item_size > max_size) {
        if (std::cin.fail()) {
            std::cout << "Error !" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (item_size <= MIN_SIZE) {
            std::cout << "Error ! Item must be greater than " << MIN_SIZE << std::endl;
        } else {
            std::cout << "Error ! Item must be lower than " << max_size << std::endl;
        }
        std::cout << "> ";
    }

    return item_size;
}

/**
 * @brief Input items size while size != 0
 * @param max_size box size
 * @return std::vector<int> dynamic array with items size
 */
std::vector<int> Input::secure_items(int max_size) {

    std::vector<int> items_size;
    int size;

    do {
        std::cout << "> ";
        size = Input::secure_item_size(max_size);
        if (size != 0) {
            items_size.push_back(size);
        }
    } while (size != MIN_SIZE);

    return items_size;
}

/**
 * @brief Check user input when he chose algorithm
 * @return int chosen algorithm
 */
int Input::secure_algo() {

    int algo;

    while (!(std::cin >> algo) || algo < 1 || algo > 4) {
        if (std::cin.fail()) {
            std::cout << "Error !" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cout << "Error ! Value must be 1, 2, 3 or 4." << std::endl;
        }
        std::cout << "> ";
    }

    return algo;
}