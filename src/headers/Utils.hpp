#include <array>
#include <string>
#include <vector>

/**
 * @brief Utils class
 */
class Utils {

    private:

    static std::vector<std::string> split(std::string to_split, char delimiter);

    public:

    static void file_write(std::string to_write);
    
    static void display(const std::vector<int> to_display);

    static void find_better(int box_size, std::vector<std::string> &to_examine);

    static void display_report(std::array<int, 4> nb_boxes);
};