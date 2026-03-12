#include "splashkit.h"

int main()
{
    open_window("My First GUI Program", 640, 480);

    clear_screen(COLOR_DARK_BLUE);
    draw_text("HI World! - using SplashKit shapes:", COLOR_SLATE_GRAY, 50, 50);

    refresh_screen();
    delay(400);

    // Draw the H
    fill_rectangle(COLOR_SLATE_GRAY, 50, 100, 20, 100);
    fill_rectangle(COLOR_SLATE_GRAY, 70, 140, 40, 20);
    fill_rectangle(COLOR_SLATE_GRAY, 110, 100, 20, 100);

    refresh_screen();
    delay(400);

    // Draw the I
    fill_rectangle(COLOR_WHEAT, 150, 100, 20, 100);

    refresh_screen();
    delay(700);

    // Draw the W
    fill_triangle(COLOR_SLATE_GRAY, 50, 250, 90, 370, 120, 250);
    fill_triangle(COLOR_SLATE_GRAY, 90, 250, 120, 370, 160, 250);
    fill_triangle(COLOR_DARK_BLUE, 70, 250, 90, 310, 110, 250);
    fill_triangle(COLOR_DARK_BLUE, 100, 250, 120, 310, 140, 250);
    fill_rectangle(COLOR_DARK_BLUE, 70, 350, 80, 30);

    refresh_screen();
    delay(400);

    // Draw the O
    fill_ellipse(COLOR_WHEAT, 170, 250, 80, 100);
    fill_ellipse(COLOR_DARK_BLUE, 190, 270, 40, 60);

    refresh_screen();
    delay(400);

    // Draw the R
    fill_triangle(COLOR_WHEAT, 270, 250, 270, 350, 340, 350);
    fill_triangle(COLOR_DARK_BLUE, 252, 250, 252, 350, 320, 350);
    fill_ellipse(COLOR_WHEAT, 252, 250, 80, 60);
    fill_ellipse(COLOR_DARK_BLUE, 270, 270, 40, 20);
    fill_rectangle(COLOR_DARK_BLUE, 252, 250, 20, 100);
    fill_rectangle(COLOR_WHEAT, 270, 250, 20, 100);

    refresh_screen();
    delay(400);

    // Draw the L
    fill_rectangle(COLOR_WHEAT, 360, 250, 20, 100);
    fill_rectangle(COLOR_WHEAT, 380, 330, 40, 20);

    refresh_screen();
    delay(400);

    // Draw the D
    fill_ellipse(COLOR_WHEAT, 420, 250, 100, 100);
    fill_ellipse(COLOR_DARK_BLUE, 440, 270, 60, 60);
    fill_rectangle(COLOR_DARK_BLUE, 420, 250, 30, 100);
    fill_rectangle(COLOR_WHEAT, 450, 250, 20, 101);

    refresh_screen();
    delay(400);

    // Draw the !
    fill_rectangle(COLOR_WHEAT, 550, 250, 20, 60);
    fill_circle(COLOR_WHEAT, 560, 340, 10);
    
    refresh_screen();
    delay(1000);
}