/**
 * @file Heuristic.cpp
 * @author Adrien GARROUSTE - 1irda.alwaysdata.net
 * @brief Class to launch heuristic method 
 * @version 0.1
 * @date 2021-01-04
 * @copyright No copyright no right
 */
#include <algorithm>
#include <iostream>
#include <vector>
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

    unsigned int current_box = 0;
    Item better_choice;

    while(!this->items_container.empty()) {

        this->boxes_container.push_back(Box(this->box_size));
        this->boxes_container[current_box].put(this->items_container[0]);
        this->remove_at(0);

        for (size_t current_item = 0; current_item < this->items_container.size()
            && this->boxes_container[current_box].get_capacity() > 0;
            current_item++) {

            better_choice = get_better_item(current_box);
            this->boxes_container[current_box].put(better_choice);
        }

        current_box++;
    }
}

/**
 * @brief Get the better index to add
 * @param current_box current box to fill
 * @return Item item with max size
 */
Item Heuristic::get_better_item(int current_box) {

    Item max;
    int i = 0;
    int index_max = -1;

    for (Item item : this->items_container) {

        if (item.get_size() > max.get_size() 
            && item.get_size() <= this->boxes_container[current_box].get_capacity()) {
            
            max = item;
            index_max = i;
        }
        i++;
    }

    this->remove_at(index_max);

    return max;
}

/**
 * @brief Remove item at specified index
 * @param index index of item to remove
 */
void Heuristic::remove_at(int index) {
    if (index >= 0) {
        this->items_container.erase(this->items_container.begin() + index);
    }
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