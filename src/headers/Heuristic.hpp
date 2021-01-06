#ifndef __HEURISTIC__
#define __HEURISTIC__

#include "Box.hpp"
#include <vector>

class Heuristic {

    private:

    int algorithm;

    int box_size;

    std::vector<Box> boxes_container;

    std::vector<int> items_container;

    void first_fit();

    void best_fit();

    void display();

    void descending_order();

    void choose_algo();

    int get_better_item(int current_box);

    void remove_at(int index);

    public:

    Heuristic(int algorithm, int box_size, std::vector<int> values_size);

    void launch();
};

#endif