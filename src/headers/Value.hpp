#ifndef __VALUE__
#define __VALUE__

class Value {

    private:

    unsigned int size;

    bool is_taken;

    public:

    Value(unsigned int size);

    unsigned int get_size() const;

    bool get_is_taken();

    void set_is_taken(bool taken);
};

#endif