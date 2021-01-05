#ifndef __VALUE__
#define __VALUE__

class Item {

    private:

    unsigned int size;

    public:

    Item();

    Item(unsigned int size);

    unsigned int get_size() const;
};

#endif