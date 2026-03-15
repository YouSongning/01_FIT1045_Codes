#include "splashkit.h"

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;

int main()
{   
    /*--------------------------------------
| Water bottle shape...
|
| BOTTLE_LEFT_X     BOTTLE_RIGHT_X
|        |             |
|        v             v
|          ___________
|         /           \
|   ^    |      x      | <-- x = BOTTLE_CENTER_X
|   |    |\___________/|       + BOTTLE_TOP_Y
|   |    |             |
|   |    | ___________ |
|   |    |/           \|
|   |    |             | <-- water_y
|   |    |\___________/| ^
|   |    | ___________ | | water_height
|   |    |/           \| v
|   v    |             | <-- BOTTLE_BASE_Y
|         \___________/
| BOTTLE_HEIGHT
|         <-----x-----> BOTTLE_RADIUS
|        BOTTLE_DIAMETER
--------------------------------------*/

    const int BOTTLE_RADIUS = 80;   
    const int BOTTLE_HEIGHT = 400;
    const int BOTTLE_DIAMETER = BOTTLE_RADIUS * 2;
    const int BOTTLE_CENTER_X = WINDOW_WIDTH / 2;
    const int BOTTLE_LEFT_X = BOTTLE_CENTER_X - BOTTLE_RADIUS;
    const int BOTTLE_RIGHT_X = BOTTLE_CENTER_X + BOTTLE_RADIUS;
    const int BOTTLE_BASE_Y = WINDOW_HEIGHT - BOTTLE_RADIUS - 5; // 5 pixel gap
    const int BOTTLE_TOP_Y = BOTTLE_BASE_Y - BOTTLE_HEIGHT;
    
    string line;
    int percent_full;

    write_line("Water Bottle Visualiser!");
    write_line();
    write_line("How full iss your bottle? (0-100)");
    write_line();
    write("Percent: ");
    line = read_line();

    // Convert the text entered to a double
    percent_full = to_integer(line);

    double water_height = BOTTLE_HEIGHT * (percent_full / 100.0);
    double water_y = BOTTLE_BASE_Y - water_height;

    open_window("Your Water Bottle", WINDOW_WIDTH, WINDOW_HEIGHT);
    clear_screen(COLOR_WHITE);

    // Draw the water
    // Circle at the top of the water
    fill_circle(COLOR_BLUE, BOTTLE_CENTER_X, water_y, BOTTLE_RADIUS);

    // Circle at the bottom of the bottle
    fill_circle(COLOR_BLUE, BOTTLE_CENTER_X, BOTTLE_BASE_Y, BOTTLE_RADIUS);
    draw_circle(COLOR_BLACK, BOTTLE_CENTER_X, BOTTLE_BASE_Y, BOTTLE_RADIUS);

    // Draw the rest of the water
    fill_rectangle(COLOR_BLUE, BOTTLE_LEFT_X, water_y, BOTTLE_DIAMETER, water_height);
    draw_circle(COLOR_BLACK, BOTTLE_CENTER_X, water_y, BOTTLE_RADIUS);

    // Outline bottle
    // Draw the left wall of the bottle
    draw_line(COLOR_BLACK, BOTTLE_LEFT_X, BOTTLE_BASE_Y, BOTTLE_LEFT_X, BOTTLE_TOP_Y);
    // Draw the right wall of the bottle
    draw_line(COLOR_BLACK, BOTTLE_RIGHT_X, BOTTLE_BASE_Y, BOTTLE_RIGHT_X, BOTTLE_TOP_Y);
    draw_circle(COLOR_BLACK, BOTTLE_CENTER_X, BOTTLE_TOP_Y, BOTTLE_RADIUS);

    refresh_screen();
    delay(5000);
}