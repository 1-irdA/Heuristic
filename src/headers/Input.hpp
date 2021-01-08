#ifndef __INPUT__
#define __INPUT__ 

#include <vector>

class Input {

    public:

    static int secure_input_size();

    static std::vector<int> secure_items(int max_size);

    static int secure_algo();
    
    static bool secure_choice();

    private:

    static int secure_item_size(int max_size);  
};

#endif