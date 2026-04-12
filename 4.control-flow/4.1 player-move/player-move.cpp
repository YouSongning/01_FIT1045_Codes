#include "splashkit.h"

const int PLAYER_RADIUS = 50;

int main()
{
    open_window("Circle Moving", 1280, 720);

    clear_screen(COLOR_WHITE);

    fill_circle(COLOR_TURQUOISE, 640, 360, PLAYER_RADIUS);

    refresh_screen(60);

    delay(5000);
}