#include "splashkit.h"

int main()
{
    write("Seven plus two is:");
    write_line(7 + 2);

    open_window("house drawing by Songning", 800, 600);

    load_font("main", "Roboto-Light.ttf");
    load_bitmap("pkc", "pikachu.png");
    load_sound_effect("hello", "Hello.ogg");

    clear_screen(COLOR_WHITE);

    fill_ellipse(COLOR_BRIGHT_GREEN, 0, 400, 800, 400);
    fill_rectangle(COLOR_GRAY, 300, 300, 200, 200);
    fill_triangle(COLOR_RED, 250, 300, 400, 150, 550, 300);

    // Drawing Text
    draw_text("Pikachu jumps out the house!", COLOR_BLACK, "main", 40, 140, 20);

    // Graphics Procedure
    draw_bitmap("pkc", 0, 0);

    refresh_screen();

    // Audio Procedure
    play_sound_effect("hello");
    delay(2500);

    play_sound_effect("hello", 2, 0.2f); // Play it twice, quietly
    delay(2500);

    delay(5000);
}