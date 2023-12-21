#include "libraries.hpp"
#include "comment_gen.hpp"

void testing_border_length();
void test_reading_in_txt();

int main()
{
    test_reading_in_txt();
    return 0;
}

void testing_border_length()
{
    std::cout << "Testing Border Length\n";
    Comment test_comment;
    test_comment.set_width(20);
    test_comment.print();
}

void test_reading_in_txt()
{
    Comment* test_comment = new Comment();
    test_comment->read_data("../test-txts/one-short-sent.txt");
}
