#ifndef __FF__
#define _FF_

#include <vector>
#include "Box.hpp"
#include "Item.hpp"

class Heuristic {

    private:

    int algorithm;

    int box_size;

    size_t nb_taken;

    std::vector<Box> boxes_container;

    std::vector<Item> items_container;

    void first_fit();

    void best_fit();

    void display();

    void descending_order();

    void choose_algo();

    void put_max_value(Box& box);

    void put_next(int current_box);

    void through_and_check(int box_index, size_t nb_placed);

    public:

    Heuristic(int algorithm, int box_size, std::vector<int> values_size);

    void launch();
};

#endif