#include "splashkit.h"
#include "utilities.h"

// Application Logic Function Declarations

// display_main_menu() procedure

// interact_menu() procedure

// draw_heading_line() procedure
void draw_heading_line(int length)
{
    write("+");
    print_repeated("-", length - 2, 0);
    write("+");
}

// draw_title() procedure
void draw_title(string text, int length)
{
    draw_heading_line(length);
    write_line();

    write("| " + text);
    print_repeated(" ", length - 4 - length_of(text), 0);
    write_line(" |");

    draw_heading_line(length);
    write_line();
}

void display_main_menu()
{
    draw_title("Main Menu", 26);
    write_line("1: Update goals\n2: Update behinds\n3: Print details\n4: Quit");
    draw_heading_line(26);
    write_line();
}

void interact_menu(string name, int &goal, int &behind, int &score)
{

    int option;
    string quit;
    bool finish = false;

    while (!finish)
    {

        display_main_menu();

        option = read_integer_range("Enter Option: ", 1, 4);
        write_line();

        switch (option)
        {
        case 1:
            write_line("Current goals: " + to_string(goal));
            goal = read_integer("Enter new goals: ");

            score = goal * 6 + behind;
            write_line("\nCurrent scores: " + to_string(score) + "\n");

            break;
        case 2:
            write_line("Current behinds: " + to_string(behind));
            behind = read_integer("Enter new behinds: ");

            score = goal * 6 + behind;
            write_line("\nCurrent scores: " + to_string(score) + "\n");

            break;
        case 3:
            write_line(name + ": ");
            write_line("    " + to_string(goal) + " Goals");
            write_line("    " + to_string(behind) + " Behinds");
            write_line("    " + to_string(score) + " Scores");
            write_line();

            break;
        case 4:
            if (read_boolean("Are you sure you want to quit? [Y/n]? "))
            {
                finish = true;
                write_line("\nBye!");
            }
            else
            {
                write_line();
            }

            break;
        }
    }
}

// Main Program
int main()
{
    string name;
    int goal, behind, score;

    draw_title("Score Calculator", 26);

    write_line("\nWelcome to the AFL score calculator!\n");

    name = read_string("Enter team name: ");

    goal = read_integer("Enter goals: ");

    behind = read_integer("Enter behinds: ");

    score = goal * 6 + behind;

    write_line("\ncurrent Score: " + to_string(score) + "\n");

    interact_menu(name, goal, behind, score);

    return 0;
}
