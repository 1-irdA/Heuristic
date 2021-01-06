#ifndef __ITEM__
#define __ITEM__

class Item {

    private:

    unsigned int size;

    public:

    Item();

    Item(unsigned int size);

    unsigned int get_size() const;
};

#endif