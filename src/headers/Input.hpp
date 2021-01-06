#ifndef __INPUT__
#define __INPUT__ 

#include <vector>

class Input {

    public:

    static int secure_box_size();

    static std::vector<int> secure_items(int max_size);

    static int secure_algo();

    private:

    static int secure_item_size(int max_size);  
};

#endif