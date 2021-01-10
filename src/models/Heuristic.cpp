/**
 * @file Heuristic.cpp
 * @author Adrien GARROUSTE - 1irda.alwaysdata.net
 * @brief Class to launch heuristic method 
 * @version 0.1
 * @date 2021-01-04
 * @copyright No copyright no right
 */
#include "../headers/Box.hpp"
#include "../headers/Heuristic.hpp"
#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

/**
 * @brief Construct a new heuristic object
 * @param algorithm algorithm choosed by user
 * @param box_size size of all boxes
 * @param values_size all size of values to put in boxes
 */
Heuristic::Heuristic(int algorithm, int box_size, std::vector<int> values_size) {

    this->algorithm = algorithm;
    this->box_size = box_size;

    for (int size : values_size) {
        if (size > box_size) {
            throw std::runtime_error("Error ! Item can't be greater than box size.\n");
        }
        this->items_container.push_back(size);    
    }
}

/**
 * @brief First fit algorithm
 */
void Heuristic::first_fit() {

    int current_box = 0;

    while(!this->items_container.empty()) {

        this->boxes_container.push_back(Box(this->box_size));

        for (size_t current_item = 0; current_item < this->items_container.size() 
            && this->boxes_container[current_box].get_capacity() > 0; current_item++) {

            if (this->items_container[current_item] <= this->boxes_container[current_box].get_capacity()) {
                this->boxes_container[current_box].put(this->items_container[current_item]);
                this->items_container.erase(this->items_container.begin() + current_item);
                // don't jump an item
                current_item--;
            } 
        }

        current_box++;
    }
}

/**
 * @brief Best fit algorithm
 */
void Heuristic::best_fit() {

    int remaining_capacity;
    int best_remaining_capacity;
    int best_box = -1;
    int remaining_zero = -1;
    int nb_box = 0;
    
    // Add a box and an element and remove the added element
    this->boxes_container.push_back(Box(this->box_size));
    this->boxes_container[nb_box].put(this->items_container[0]);
    this->remove_at(0);

    while(!this->items_container.empty()) {

        best_remaining_capacity = std::numeric_limits<int>::max();
        best_box = -1;
        remaining_zero = -1;
        
        for (size_t current_box = 0; 
            current_box < this->boxes_container.size() 
            && remaining_zero == -1;
            current_box++) {

            if (this->items_container[0] <= this->boxes_container[current_box].get_capacity()) {

                remaining_capacity = this->boxes_container[current_box].get_capacity() - this->items_container[0];

                if (remaining_capacity == 0) {
                    remaining_zero = current_box;
                } else if (remaining_capacity < best_remaining_capacity) {
                    best_remaining_capacity = remaining_capacity;
                    best_box = current_box;
                }
            } 
        }

        if (remaining_zero != -1) {
            this->boxes_container[remaining_zero].put(this->items_container[0]);
        } else if (best_box != -1 ) {
            this->boxes_container[best_box].put(this->items_container[0]);
        } else {
            nb_box++;
            this->boxes_container.push_back(Box(this->box_size));
            this->boxes_container[nb_box].put(this->items_container[0]);   
        }
        this->remove_at(0);   
    }
}

/**
 * @brief Remove item at specified index
 * @param index index of item to remove
 */
void Heuristic::remove_at(int index) {
    if (index >= 0 && this->items_container.size() > 0) {
        this->items_container.erase(this->items_container.begin() + index);
    }
}

/**
 * @brief Sort vector in descending order
 */
void Heuristic::descending_order() {
    std::sort(this->items_container.begin(), 
            this->items_container.end(), 
            [](const int &a, const int &b) -> bool { return a > b; });
}

/**
 * @brief Display results
 */
void Heuristic::display() const {

    std::cout << "Number of boxes used : " << this->boxes_container.size() << std::endl;

    for (size_t i = 0; i < this->boxes_container.size(); i++) {
        std::cout << "Box n°" << i + 1 << " : ";
        this->boxes_container[i].display_content();
    }
}

/**
 * @brief Choose algo to launch
 */
void Heuristic::choose_algo() {

    switch (this->algorithm) 
    {
        // FF
        case 1: 
        {
            this->first_fit();
            break;
        }
        // FFD
        case 2: 
        {
            this->descending_order();
            this->first_fit();
            break;
        }
        // BF
        case 3: 
        {
            this->best_fit();
            break;
        }
        // BFD
        case 4: 
        {
            this->descending_order();
            this->best_fit();
            break;
        }
        // Not exist
        default:
        {
            std::cout << "Error ! Incorrect algorithm." << std::endl;
        }
    }
}

/**
 * @brief Get the number of used boxes
 * @return size_t number of used boxes
 */
size_t Heuristic::get_nb_used_boxes() const {
    return this->boxes_container.size();
}

/**
 * @brief Launch heuristic method
 */
void Heuristic::launch() {
    this->choose_algo();
}