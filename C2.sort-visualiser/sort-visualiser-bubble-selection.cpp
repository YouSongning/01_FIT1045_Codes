#include "splashkit.h"
#include "utilities.h"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const int MIN_VALUE = 10;

const int ARRAY_SIZE = 100;
const int BAR_WIDTH = 8;
const int BAR_SPACING = 2;
const int TOP_MARGIN = 180;

string current_algorithm = "None";

void randomise_array(int data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        data[i] = rnd(SCREEN_HEIGHT - TOP_MARGIN - MIN_VALUE) + MIN_VALUE;
    }
}

void draw_array(int data[], int size, int current, int compare)
{
    for (int i = 0; i < size; i++)
    {
        color bar_color = COLOR_AQUAMARINE;

        // Highlight current compared values
        if (i == current)
        {
            bar_color = COLOR_RED;
        }
        else if (i == compare)
        {
            bar_color = COLOR_GREEN;
        }

        int height = data[i];

        int x = i * (BAR_WIDTH + BAR_SPACING);

        int y = SCREEN_HEIGHT - height;

        fill_rectangle(bar_color, x, y, BAR_WIDTH, height);
    }
}

void swap_values(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void redraw_screen(int data[], int current, int compare, string algorithm)
{
    clear_screen(COLOR_BLACK);

    draw_array(data, ARRAY_SIZE, current, compare);

    draw_text("NAME: YOU SONGNING - ID: 36707015", COLOR_WHITE, 20, 20);

    draw_text("Current Algorithm: " + algorithm, COLOR_YELLOW, 20, 170);

    draw_text("B - Bubble Sort", COLOR_WHITE, 20, 50);

    draw_text("S - Selection Sort", COLOR_WHITE, 20, 80);

    draw_text("R - Randomise", COLOR_WHITE, 20, 110);

    draw_text("ESC - Quit", COLOR_WHITE, 20, 140);

    refresh_screen(6000);
}

void bubble_sort_visual(int data[], int size)
{
    for (int i = 0; i < size - 1 && !quit_requested(); i++)
    {
        for (int j = 0; j < size - i - 1 && !quit_requested(); j++)
        {
            if (data[j] > data[j + 1])
            {
                swap_values(data[j], data[j + 1]);
            }

            process_events();

            redraw_screen(data, j, j + 1, current_algorithm);

            delay(1);
        }
    }
}

void selection_sort_visual(int data[], int size)
{
    for (int i = 0; i < size - 1 && !quit_requested(); i++)
    {
        int smallest_index = i;

        for (int j = i + 1; j < size && !quit_requested(); j++)
        {
            process_events();

            redraw_screen(data, smallest_index, j, current_algorithm);

            delay(1);

            if (data[j] < data[smallest_index])
            {
                smallest_index = j;
            }
        }

        if (smallest_index != i)
        {
            swap_values(data[i], data[smallest_index]);

            redraw_screen(data, i, smallest_index, current_algorithm);

            delay(1);
        }
    }
}

int main()
{
    open_window("YOU SONGNING - Sort Visualiser", SCREEN_WIDTH, SCREEN_HEIGHT);

    int data[ARRAY_SIZE];

    randomise_array(data, ARRAY_SIZE);

    while (!quit_requested())
    {
        process_events();

        if (key_typed(B_KEY))
        {
            current_algorithm = "Bubble Sort";
            bubble_sort_visual(data, ARRAY_SIZE);
        }

        if (key_typed(S_KEY))
        {
            current_algorithm = "Selection Sort";
            selection_sort_visual(data, ARRAY_SIZE);
        }

        if (key_typed(R_KEY))
        {
            current_algorithm = "None";
            randomise_array(data, ARRAY_SIZE);
        }

        if (key_typed(ESCAPE_KEY))
        {
            break;
        }

        redraw_screen(data, -1, -1, current_algorithm);
    }

    return 0;
}