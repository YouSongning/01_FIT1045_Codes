#include "splashkit.h"

const int MAX_TARGET_RADIUS = 50;
const int MIN_TARGET_RADIUS = 10;

// Declare target_data struct here
struct target_data
{
    double x;
    double y;
    double radius;
};

// Declare reaction_game_data struct here (TODO)
/**
 * Represents the data of the reaction game, including the current target and the number of hits.
 */
struct reaction_game_data
{
    target_data target;
    int hits;
};

// Add new target here
target_data new_target(double x, double y, double radius)
{
    target_data result;
    result.x = x;
    result.y = y;
    result.radius = radius;
    return result;
}

// Add random target here
target_data random_target()
{
    int radius = rnd(MAX_TARGET_RADIUS - MIN_TARGET_RADIUS) + MIN_TARGET_RADIUS;

    return new_target(
        rnd(radius, screen_width() - radius),
        rnd(radius, screen_height() - radius),
        radius);
}

// Add draw target here
void draw_target(target_data target)
{
    fill_circle(COLOR_LIGHT_BLUE, target.x, target.y, target.radius);
}

// Add mouse over target here
bool mouse_over_target(target_data target)
{
    return point_in_circle(mouse_x(), mouse_y(), target.x, target.y, target.radius);
}

// Add new_reaction_game function here (TODO)
/**
 * @brief Creates a new reaction game with a random target and zero hits.
 * @return The newly created reaction game
 */

reaction_game_data new_reaction_game()
{
    reaction_game_data result;
    result.target = random_target();
    result.hits = 0;
    return result;
}


// Add game_average_time function here
/**
 * @brief Calculates the average time per hit in the reaction game.
 * @param game The reaction game data
 * @return The average time per hit
 */

int game_average_time(reaction_game_data game)
{
    if (game.hits == 0)
    {
        return current_ticks();
    }
    else
    {
        return current_ticks() / game.hits;
    }
}


// Add draw_game function here
/**
 * @brief Draws the game on the screen.
 * @param game The reaction game data to draw to the screen
 */

void draw_game(reaction_game_data game)
{
    clear_screen(COLOR_WHITE);
    draw_text("Hits: " + to_string(game.hits), COLOR_BLACK, 0, 0);
    draw_text("Average time: " + to_string(game_average_time(game)), COLOR_BLACK, 0, 10);
    // Draw the target
    draw_target(game.target);
    refresh_screen();
}


int main()
{
    open_window("Reaction Timer", 800, 600);

    // Create the game data
    reaction_game_data game = new_reaction_game();

    while (!quit_requested())
    {
        process_events();

        if (mouse_clicked(LEFT_BUTTON) && mouse_over_target(game.target))
        {
            game.target = random_target();
            game.hits++;
        }

        clear_screen(COLOR_WHITE);

        draw_game(game);
    }

    return 0;
}