/**
 * @file main.cpp
 * @author Adrien GARROUSTE - 1irda.alwaysdata.net
 * @brief Main to launch program
 * @version 0.1
 * @date 2021-01-04
 * @copyright No copyright no right 
 */
#include <iostream>
#include <vector>

#include "headers/Heuristic.hpp"
#include "headers/Input.hpp"

/**
 * @brief Method to launch program
 * @return int code returned by program
 */
int main() {

    int boxes_size;
    int algo;
    std::vector<int> items;

    std::cout << "Bin packing\n\n";

    std::cout << "Boxes size : ";
    boxes_size = Input::secure_box_size();

    std::cout << "Int values to be placed (0 to stop) : \n";
    items = Input::secure_items(boxes_size);

    std::cout << "\nChoose heuristics (1, 2, 3, 4) : ";
    std::cout << "\n(1) First-Fit \n(2) Decreasing First-Fit\n";
    std::cout << "(3) Best-Fit \n(4) Decreasing Best-Fit\n> ";
    algo = Input::secure_algo();

    Heuristic heuristic = Heuristic(algo, boxes_size, items);
    heuristic.launch();

    return 0;
}