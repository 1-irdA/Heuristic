/**
 * @file main.cpp
 * @author Adrien GARROUSTE - 1irda.alwaysdata.net
 * @brief Main to launch program
 * @version 0.1
 * @date 2021-01-04
 * @copyright No copyright no right 
 */
#include "headers/Generator.hpp"
#include "headers/Heuristic.hpp"
#include "headers/Input.hpp"
#include "headers/TestHeuristic.hpp"
#include "headers/Utils.hpp"
#include <iostream>
#include <vector>

/**
 * @brief Method to launch program
 * @return int code returned by program
 */
int main() {

    int boxes_size;
    int algo;
    int nb_items;
    std::vector<int> items;

    std::cout << "Bin packing\n\n";

    std::cout << "Launch tests ? (Y / N) : ";
    if (Input::secure_choice()) {
        TestHeuristic::test();
    }

    std::cout << "Launch program ? (Y / N) : ";
    if (Input::secure_choice()) {

        // Clear console
        system("clear");

        do {
            // Input box size
            std::cout << "Boxes size : ";
            boxes_size = Input::secure_input_size();

            std::cout << "Input items (Y) or generate them (N) ? ";
            if (Input::secure_choice()) {
                // Input values to put in box
                std::cout << "Int values to be placed (0 to stop) : \n";
                items = Input::secure_items(boxes_size);
            } else {
                // Generate values to put in box
                std::cout << "How many objects to be placed do you want to generate ? ";
                nb_items = Input::secure_input_size();
                items = Generator::generate_items(nb_items, boxes_size);
                Utils::display(items);
            }   

            // Choose heuristic algorithm
            std::cout << "\nChoose heuristics (1, 2, 3, 4) : \n";
            std::cout << "(1) First-Fit \n(2) Decreasing First-Fit\n";
            std::cout << "(3) Best-Fit \n(4) Decreasing Best-Fit\n> ";
            algo = Input::secure_algo();

            // Launch heuristic algorithm
            Heuristic heuristic = Heuristic(algo, boxes_size, items);
            heuristic.launch();
            heuristic.display();

            std::cout << "\nContinue (Y / N) : ";
        } while (Input::secure_choice());
    }

    return 0;
}