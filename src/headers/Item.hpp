#ifndef __VALUE__
#define __VALUE__

class Item {

    private:

    unsigned int size;

    bool is_taken;

    public:

    Item();

    Item(unsigned int size);

    unsigned int get_size() const;

    bool get_is_taken();

    void set_is_taken(bool taken);
};

#endif