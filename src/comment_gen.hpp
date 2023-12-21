#include "libraries.hpp"

class Comment
{
    private:
    int width;
    int _height;
    std::vector<char> border_width;
    std::string unparsed_input;

    public:
    /* constructors */
    Comment() : width(0), _height(0) {}
    Comment(int in_width) : width(in_width) {}
    
    /* functions */
    void set_width(int in_width);
    int get_width() const;
    void print() const;
    void read_data(std::string file);

};