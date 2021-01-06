#ifndef __BOX__
#define __BOX__

#include <string>
#include <vector>

class Box {

    private:

    int capacity;

    std::vector<int> container;    

    public:

    Box(int capacity);

    void put(const int &item);

    int get_capacity();

    void display_content();
};

#endif