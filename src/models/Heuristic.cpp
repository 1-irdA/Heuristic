/**
 * @file Heuristic.cpp
 * @author Adrien GARROUSTE - 1irda.alwaysdata.net
 * @brief Class to launch heuristic method 
 * @version 0.1
 * @date 2021-01-04
 * @copyright No copyright no right
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "../headers/Heuristic.hpp"
#include "../headers/Box.hpp"
#include "../headers/Item.hpp"

/**
 * @brief Construct a new object
 * @param algorithm algorithm choosed by user
 * @param box_size size of all boxes
 * @param values_size all size of values to put in boxes
 */
Heuristic::Heuristic(int algorithm, int box_size, std::vector<int> values_size) {

    this->algorithm = algorithm;
    this->box_size = box_size;

    for (int size : values_size) {
        this->items_container.push_back(Item(size));    
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

            if (this->items_container[current_item].get_size() <= this->boxes_container[current_box].get_capacity()) {
                this->boxes_container[current_box].put(this->items_container[current_item]);
                this->items_container.erase(this->items_container.begin() + current_item);
                // don't jump an element
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

    unsigned int current_box = 0;
    int better_choice;

    while(!this->items_container.empty()) {

        this->boxes_container.push_back(Box(this->box_size));
        this->boxes_container[current_box].put(this->items_container[0]);
        this->items_container.erase(this->items_container.begin() + 0);

        for (size_t current_item = 0; current_item < this->items_container.size() 
            && this->boxes_container[current_box].get_capacity() > 0; current_item++) {

            better_choice = get_better_index(current_box);
            this->boxes_container[current_box].put(this->items_container[better_choice]);
            this->items_container.erase(this->items_container.begin() + better_choice);
        }

        current_box++;
    }
}

/**
 * @brief Get the index of the better choice to put in the current box
 * @param current_box current box to fill
 * @return int index of better item
 */
int Heuristic::get_better_index(int current_box) {

    int better_index = -1;
    unsigned int max = 0;
    int index;

    for (size_t current_item = 0; current_item < this->items_container.size() 
            && better_index == -1; 
            current_item++) {
        if (this->items_container[current_item].get_size() == this->boxes_container[current_box].get_capacity()) {
            better_index = current_item;
        } else if (this->items_container[current_item].get_size() > max 
            && this->items_container[current_item].get_size() <= this->boxes_container[current_box].get_capacity()) {
            max = this->items_container[current_item].get_size();
            index = current_item;
        }
    }

    if (better_index != -1) {
        index = better_index;
    }

    return index;
}

/**
 * @brief Sort vector in descending order
 */
void Heuristic::descending_order() {
    std::sort(this->items_container.begin(), 
            this->items_container.end(), 
            [](const Item &a, const Item &b) -> bool { return a.get_size() > b.get_size(); });
}

/**
 * @brief Display results
 */
void Heuristic::display() {

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
        case 1: 
        {
            this->first_fit();
            break;
        }
        
        case 2: 
        {
            this->descending_order();
            this->first_fit();
            break;
        }

        case 3: 
        {
            this->best_fit();
            break;
        }

        case 4: 
        {
            this->best_fit();
            this->first_fit();
            break;
        }
    }
}

/**
 * @brief Launch heuristic method
 */
void Heuristic::launch() {
    this->choose_algo();
    this->display();
}