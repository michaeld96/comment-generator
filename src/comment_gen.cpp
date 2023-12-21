#include "comment_gen.hpp"
void Comment::set_width(int in_width)
{
    width = in_width;
    for (int i = 0; i < width; ++i) {   
        border_width.push_back('*');
    }   
}

int Comment::get_width() const
{
    return width;
}

void Comment::print() const 
{
    // printing border.
    for (auto itr = border_width.begin(); itr != border_width.end(); ++itr) {
        std::cout << *itr;
    }
    std::cout << "\n";
}

void Comment::read_data(const std::string file)
{
    std::ifstream _file(file);
    if (_file) {
        // use stringstream to read the file.
        std::stringstream buffer;
        buffer << _file.rdbuf();

        // convert the stringstream into a string.
        std::string unparsed_input = buffer.str();
        std::cout << unparsed_input << "\n";
    }
    else {
        std::cerr << "Error opening " << file << "\n";
    }

}

// Test output
/************************************************
 * Today is December 20th, and I am programming *
 * at 11:45PM. It was a good day as I drank a   *
 * coffee. Mint mocha, my favorite.             *
 * *********************************************/