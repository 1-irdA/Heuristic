#include "../headers/Utils.hpp"
#include <array>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <vector>

/**
 * @brief Delimiter to split informations
 */
const char DELIMITER = ':';

/**
 * @brief Filename to put results
 */
const std::string FILENAME = "doc/results.txt";

/**
 * @brief Available algorithms
 */
const std::string ALGORITHMS_NAME[] = {
    "FF", "FFD", "BF", "BFD"
};

/**
 * @brief Display values in vector
 * @param to_display vector with values to display
 */
void Utils::display(const std::vector<int> to_display) {
    std::cout << "\nItems : " << std::endl;
    for (int item : to_display) {
        std::cout << item << " ";            
    }
    std::cout << std::endl;
}

/**
 * @brief Find the better algorithm
 * @param current_box_size size of box who contains items
 * @param to_examine results to examine
 * contains number of used boxes and execution time
 */
void Utils::find_better(int box_size, std::vector<std::string> &to_examine) {

    int min_boxes = std::numeric_limits<int>::max();
    double min_time = std::numeric_limits<int>::max();
    std::string algo_name;
    std::stringstream to_write;
    std::vector<std::string> to_analyse;

    for (size_t i = 0; i < to_examine.size(); i++) {

        // Split string in 3 elements
        to_analyse = Utils::split(to_examine[i], DELIMITER);

        if (std::stoi(to_analyse[1]) < min_boxes) {
            algo_name = to_analyse[0];
            min_boxes = std::stoi(to_analyse[1]);
            min_time = std::stod(to_analyse[2]);
        } else if (std::stoi(to_analyse[1]) == min_boxes && std::stod(to_analyse[2]) < min_time) {
            algo_name = to_analyse[0];
            min_boxes = std::stoi(to_analyse[1]);
            min_time = std::stod(to_analyse[2]);
        }
    }

    to_examine.clear();
    to_analyse.clear();

    
    to_write << "Boxes size : " << box_size << "\n"
            << "Algorithm : " << algo_name << "\n" 
            << "Boxes used : " << min_boxes << "\n"
            << "Execution time : " << min_time << " seconds\n" << std::endl; 

    Utils::file_write(to_write.str());
}

/**
 * @brief Write a string in file
 * @param to_write string to write
 */
void Utils::file_write(std::string to_write) {

    std::ofstream outfile;
    outfile.open(FILENAME, std::ios_base::app);

    outfile << to_write;
    
    outfile.close();
}

/**
 * @brief Split a string and return elements
 * @param to_split string to split
 * @param delimiter limit to split
 * @return std::vector<std::string> contains elements
 */
std::vector<std::string> Utils::split(std::string to_split, char delimiter) {
    
    std::string temp;
    std::stringstream ss { to_split };
    std::vector<std::string> elements;

    while (getline(ss, temp, delimiter))
    {
        elements.push_back(temp);
    }

    return elements;
}

/**
 * @brief Display algorithm report
 * @param nb_boxes Array with nb boxes used by algorithms
 */
void Utils::display_report(std::array<int, 4> nb_boxes) {

    std::cout << "\n********** Algorithms reports **********\n\n";

    // Report = algo / algo
    float ff_bf = (float) nb_boxes[0] / nb_boxes[2];
    float ff_ffd = (float) nb_boxes[0] / nb_boxes[1];
    float ff_bfd = (float) nb_boxes[0] / nb_boxes[3];
    float bf_ffd = (float) nb_boxes[2] / nb_boxes[1];
    float bf_bfd = (float) nb_boxes[2] / nb_boxes[3];
    float ffd_bfd = (float) nb_boxes[1] / nb_boxes[3];

    std::cout << "FF / BF = " + std::to_string(ff_bf) + "\n"
        + "FF / FFD = " + std::to_string(ff_ffd) + "\n"
        + "FF / BFD = " + std::to_string(ff_bfd) + "\n"
        + "BF / FFD = " + std::to_string(bf_ffd) + "\n"
        + "BF / BFD = " + std::to_string(bf_bfd) + "\n"
        + "FFD / BFD = " + std::to_string(ffd_bfd) + "\n\n";
}