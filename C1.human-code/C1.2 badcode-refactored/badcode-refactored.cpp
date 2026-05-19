#include <splashkit.h>

// *Using constants for screen and game settings and name meaningfully
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int PLAYER_RADIUS = 25;
const int PLAYER_SPEED = 3;
const int FLY_RADIUS = 3;
const string GAME_TIMER = "GameTimer";

int main()
{
    // *set the spider in the center of the screen
    int player_x = SCREEN_WIDTH / 2;
    int player_y = SCREEN_HEIGHT / 2;

    int fly_x = rnd(SCREEN_WIDTH);
    int fly_y = rnd(SCREEN_HEIGHT);
    bool fly_appeared = false;

    // *Set a random time for the fly to show up (between 1000 and 3000 ticks)
    int appear_at_time = 1000 + rnd(2000);
    
    open_window("Fly Catch", SCREEN_WIDTH, SCREEN_HEIGHT);
    create_timer(GAME_TIMER);
    start_timer(GAME_TIMER);

    // *Main game loop
    while (!quit_requested())
    {
        // *Handle player input for movement
        if (key_down(RIGHT_KEY) && (player_x + PLAYER_RADIUS < SCREEN_WIDTH))
        {
            player_x += PLAYER_SPEED;
        }

        if (key_down(LEFT_KEY) && (player_x - PLAYER_RADIUS > 0))
        {
            player_x -= PLAYER_SPEED;
        }

        // *Logic for fly appearing after a certain time
        if (!fly_appeared && (timer_ticks(GAME_TIMER) > appear_at_time))
        {
            fly_appeared = true;
            fly_x = rnd(SCREEN_WIDTH);
            fly_y = rnd(SCREEN_HEIGHT);
        }

        // *Drawing the scene
        clear_screen(color_white());

        // *Draw the player (the "spider")
        fill_circle(color_black(), player_x, player_y, PLAYER_RADIUS);

        /// *Draw the fly only if it has appeared
        if (fly_appeared)
        {
            fill_circle(color_dark_green(), fly_x, fly_y, FLY_RADIUS);
        }

        refresh_screen(60);
        process_events();
    }

    return 0;
}