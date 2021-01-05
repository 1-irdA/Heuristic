#ifndef __FF__
#define _FF_

#include <vector>
#include "Box.hpp"
#include "Item.hpp"

class Heuristic {

    private:

    int algorithm;

    int box_size;

    std::vector<Box> boxes_container;

    std::vector<Item> items_container;

    void first_fit();

    void best_fit();

    void display();

    void descending_order();

    void choose_algo();

    int get_better_index(int current_box);

    public:

    Heuristic(int algorithm, int box_size, std::vector<int> values_size);

    void launch();
};

#endif