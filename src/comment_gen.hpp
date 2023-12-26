#include "libraries.hpp"

class Comment
{
    private:
    int width;
    int _bottom_width;
    int _height;
    std::vector<char> _top_border;
    std::vector<char> _bottom_border;
    std::string unparsed_input;
    std::vector<std::vector<char> > body;

    public:
    /* constructors */
    Comment() : width(49), _height(0), _bottom_width(49) {}
    Comment(int in_width) : width(in_width), _bottom_width(in_width) {}
    
    /* functions */
    void set_width(int in_width);
    void set_height(int in_height);
    int get_width() const;
    void print() const;
    void read_data(std::string file);
    void format_paragraph(/*std::string data*/);

    // TODO: Need to change.
    void run();

};