#include "../headers/Generator.hpp"
#include "../headers/Heuristic.hpp"
#include "../headers/Utils.hpp"
#include "../headers/TestHeuristic.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>

/**
 * @brief Number of items to put in boxes
 */
const int NB_ITEMS = 4000;

/**
 * @brief Available heuristic algorithms
 */
std::map<int, std::string> fixture_algorithms = {
    { 1, "FF" }, { 2, "FFD"}, 
    { 3, "BF" }, { 4, "BFD" }
};

/**
 * @brief Boxes size to test
 */
const int FIXTURE_BOXES[] = {
    10, 15, 24, 32, 44, 50, 78, 88, 95, 124, 
    138, 153, 158, 179, 210, 235, 378, 426, 541, 612,
    743, 789, 841, 941, 1111, 1203, 1500, 1743, 1857, 2000,
    2124, 2268, 2356, 2410, 2480, 2675, 2798, 2875, 2950, 3000,
    3119, 3284, 3371, 3489, 3562, 3599, 3674, 3758, 3841, 4000
}; 

/**
 * @brief Test heuristics methods 
 * FF, FFD, BF, BFD
 */
void TestHeuristic::test() {

    // Count time
    clock_t begin_algo;
    clock_t end_algo;

    // Contains string to process to write better algo in file
    std::vector<std::string> box_time;

    // Items to put in boxes
    std::vector<int> items;

    // Result to process
    std::string res;

    // Algorithms report
    std::array<int, 4> nb_boxes = { 0 };

    std::cout << "\nNumber of objects to be placed in each box size : " << NB_ITEMS << "\n" << std::endl;
    Utils::file_write("******************** " 
                    + std::to_string(NB_ITEMS) 
                    + " items to place for each algorithm ********************\n\n");

    for (int box_size : FIXTURE_BOXES) {

        std::cout << "\n********** Boxes size : " << box_size << " **********\n\n";

        items = Generator::generate_items(NB_ITEMS, box_size);

        for (std::map<int, std::string>::iterator it = fixture_algorithms.begin(); 
            it != fixture_algorithms.end(); 
            it++) {

            std::cout << "Algorithm : " << it->second << ", ";
            
            Heuristic heuristic = Heuristic(it->first, box_size, items);
            begin_algo = clock();
            heuristic.launch();
            end_algo = clock();

            // Add in array to display report
            nb_boxes[it->first - 1] += heuristic.get_nb_used_boxes();

            std::cout << "used boxes : " << heuristic.get_nb_used_boxes() << ", ";
            std::cout << "algorithm duration : " 
                    << double(end_algo - begin_algo) / CLOCKS_PER_SEC << " seconds" << std::endl;

            // Algorithm name : Boxes : Time
            res = it->second + ":" + std::to_string(heuristic.get_nb_used_boxes()) + ":" 
                    + std::to_string(double(end_algo - begin_algo) / CLOCKS_PER_SEC) + "\n";

            // Add result in array to compare them after
            box_time.push_back(res);
        }

        // Search better algo and write result in a file
        Utils::find_better(box_size, box_time);
    }

    Utils::display_report(nb_boxes);
}