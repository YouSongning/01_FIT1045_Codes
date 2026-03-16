#include "splashkit.h"

const string IMAGE_NAME = "tree";

int main()
{
    double rotation, scale_x, scale_y;

    string user_input;

    bitmap tree;

    write("Enter rotation degrees: ");
    user_input = read_line();
    rotation = to_double(user_input);

    write("Enter amount to scale x dimension: ");
    user_input = read_line();
    scale_x = to_double(user_input);

    write("Enter amount to scale y dimension: ");
    user_input = read_line();
    scale_y = to_double(user_input);


    open_window("Image Drawing", 500, 300);

    // Load the image
    tree = load_bitmap(IMAGE_NAME, "tree.png");

    draw_bitmap(tree, 10, 20);
    draw_bitmap(IMAGE_NAME, 220, 20, option_rotate_bmp(rotation, option_scale_bmp(scale_x, scale_y)));

    refresh_screen();
    delay(5000);
}