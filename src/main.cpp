#include <iostream>
#include <vector>
#include "headers/Heuristic.hpp"

int main() {

    const int STOP = 0;
    int boxes_size;
    int value;
    int algo;

    std::vector<int> values;

    std::cout << "Bin packing\n\n";

    std::cout << "Boxes size : ";
    std::cin >> boxes_size;

    std::cout << "Int values to be placed (0 to stop) : \n";

    do {
        std::cout << "> ";
        std::cin >> value;

        if (value != STOP) {
            values.push_back(value);
        }
    } while (value != STOP);

    std::cout << "\nChoose heuristics (1, 2, 3, 4) : ";
    std::cout << "\n(1) First-Fit \n(2) Decreasing First-Fit\n";
    std::cout << "(3) Best-Fit \n(4) Decreasing Best-Fit\n> ";
    std::cin >> algo;

    Heuristic heuristic = Heuristic(algo, boxes_size, values);
    heuristic.launch();

    return 0;
}