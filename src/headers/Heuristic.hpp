#ifndef __FF__
#define _FF_

#include <vector>
#include "Box.hpp"
#include "Value.hpp"

class Heuristic {

    private:

    int algorithm;

    int box_size;

    std::vector<Box> boxes_container;

    std::vector<Value> values_container;

    void first_fit();

    void best_fit();

    void display();

    void descending_order();

    void choose_algo();

    public:

    Heuristic(int algorithm, int box_size, std::vector<int> values_size);

    void launch();
};

#endif