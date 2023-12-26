#include "comment_gen.hpp"

using std::cout;

// Helper functions.
void begin_sentence(std::vector<char> &sent)
{
    sent.push_back('*');
    sent.push_back(' ');
}

void end_sentence(std::vector<char> &sent)
{
    sent.push_back(' ');
    sent.push_back('*');
}

void top_border(std::vector<char> &sent, int comment_width)
{
    sent.push_back('/');
    for (int i = 0; i < comment_width; ++i) 
    {   
        sent.push_back('*');
    }   
}

void bottom_border(std::vector<char> &sent, int comment_width)
{
    // bottom border.
    for (int i = 0; i < comment_width; ++i)
    {
        sent.push_back('*');
    }
    sent.push_back('/');
}

void Comment::set_width(int in_width)
{
    width = in_width;
    // top border.
    // _top_border.push_back('/');
    // for (int i = 0; i < width; ++i) 
    // {   
    //     _top_border.push_back('*');
    // }   

    // // bottom border.
    // for (int i = 0; i < width; ++i)
    // {
    //     _bottom_border.push_back('*');
    // }
    // _bottom_border.push_back('/');
}

void Comment::set_height(int in_height)
{
    _height = in_height;
}

int Comment::get_width() const
{
    return width;
}

void Comment::print() const 
{
    // Iterate over the outer vector
    for (const auto& line : body)
    {
        // Iterate over the inner vector
        for (char ch : line)
        {
            cout << ch;
        }
        cout << "\n";
    }
    cout << "\n";
}


// void Comment::print() const 
// {
//     // top border
//     for (size_t i = 0; i < _height; ++i)
//     {
//         for(size_t j = 0; j < width; ++j)
//         {
//             cout << body[i][j];
//         }
//         cout << "\n";
//     }
//     cout << "\n";
// }

void Comment::read_data(const std::string file)
{
    std::ifstream _file(file);
    if (_file) 
    {
        // use stringstream to read the file.
        std::stringstream buffer;
        buffer << _file.rdbuf();

        // convert the stringstream into a string.
        std::string _unparsed_input = buffer.str();
        unparsed_input = _unparsed_input;
        std::cout << unparsed_input << "\n";
    }
    else 
    {
        std::cerr << "Error opening " << file << "\n";
    }
}

void Comment::format_paragraph(/*std::string data*/)
{
    // 4 char spots taken by space and star on both side.
    // body - 4 = line width.
    unsigned body_width_counter = 0;


    // insert top border.
    // TODO: Need to think generalize this
    body.resize(5); // insuring that there is something.
    unsigned int line = 0;
    top_border(body[line], width);
    line++;

    body[line].push_back('*');
    body[line].push_back(' ');
    
    // populate paragraph body.
    for (auto itr = unparsed_input.begin(); itr != unparsed_input.end(); ++itr)
    {
        body[line].push_back(*itr);
        body_width_counter++;
        if (body_width_counter > width - 4)
        {
            body[line].push_back(' ');
            body[line].push_back('*');
            body_width_counter = 0;
            line++;
            body.push_back(std::vector<char>());  // Add a new empty vector for the next line
            body[line].push_back('*');
            body[line].push_back(' ');
        }
    }

    if (body_width_counter < width - 4)
    {
        for (size_t i = body_width_counter; i < width - 2; ++i)
        {
            body[line].push_back(' ');
        }
        body[line].push_back('*');
    }
    line++;

    // insert bottom border.
    bottom_border(body[line], width);
    line++;

    set_height(line);
    // body[0].push_back()
}

void Comment::run()
{
    format_paragraph();
    print();
}
// Test output
/************************************************
 * Today is December 20th, and I am programming *
 * at 11:45PM. It was a good day as I drank a   *
 * coffee. Mint mocha, my favorite.             *
 * *********************************************/