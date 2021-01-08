#include "../headers/Generator.hpp"
#include "../headers/Heuristic.hpp"
#include "../headers/TestHeuristic.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>

/**
 * @brief Number of items to put in boxes
 */
const int NB_ITEMS = 1000;

/**
 * @brief Available heuristic algorithms
 */
std::map<int, std::string> fixture_algorithms = {
    { 1, "FF" }, { 2, "FFD"}, { 3, "BF" }, { 4, "BFD" }
};

/**
 * @brief Boxes size to test
 */
const std::vector<int> fixture_boxes = {
    10, 15, 24, 32, 44, 50, 78, 88, 95, 124, 138,
    153, 158, 179, 210, 235, 378, 426, 541, 612,
    743, 789, 841, 941, 1111, 1203, 1500    
}; 

/**
 * @brief Test heuristics methods 
 * FF, FFD, BF, BFD
 */
void TestHeuristic::test() {

    clock_t begin_algo;
    clock_t begin_tests = clock();
    clock_t end_algo;
    clock_t end_tests;

    std::cout << "\nNumber of objects to be placed in each box size : " << NB_ITEMS << "\n" << std::endl;

    for (std::map<int, std::string>::iterator it = fixture_algorithms.begin(); 
            it != fixture_algorithms.end(); 
            it++) {

        std::cout << "\n********** Algorithm : " << it->second << " **********\n" << std::endl;
        begin_algo = clock();

        for (int box_size : fixture_boxes) {

            std::cout << "boxes size : " << box_size << ", ";

            std::vector<int> items = Generator::generate_items(NB_ITEMS, box_size);

            Heuristic heuristic = Heuristic(it->first, box_size, items);
            heuristic.launch();

            std::cout << "used boxes : " << heuristic.get_nb_used_boxes() << std::endl;
        }

        end_algo = clock();
        std::cout << "Duration of " << it->second << " algorithm : " 
            << double(end_algo - begin_algo) / CLOCKS_PER_SEC << " seconds" << std::endl;
    }

    end_tests = clock();
    std::cout << "Tests duration : " << double(end_tests - begin_tests) / CLOCKS_PER_SEC << " seconds" << std::endl;
}

