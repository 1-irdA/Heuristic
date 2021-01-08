#ifndef __BOX__
#define __BOX__

#include <vector>

class Box {

    private:

    int capacity;

    std::vector<int> container;    

    public:

    Box(int capacity);

    void put(const int &item);

    int get_capacity() const;

    void display_content() const;
};

#endif