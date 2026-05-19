#include "splashkit.h"
#include "utilities.h"

class die
{
private:
    int value;

public:
    int sides;

    die()
    {
        sides = 6;
        value = 1;
    }

    die(int sides_)
    {
        sides = sides_;
        value = 1;
    }

    void roll()
    {
        value = rnd(sides) + 1;
    }

    int current_value()
    {
        return value;
    }

    void print()
    {
        write_line(to_string(sides) + " sides: value is " + to_string(value));
    }
};

enum menu_option
{
    ROLL_DIE = 1,
    NEW_DIE,
    QUIT
};

void display_menu()
{
    write_line();
    write_line("1: Roll die");
    write_line("2: Get new die");
    write_line("3: Quit");
}

int main()
{
    int sides;
    int option = 0;

    sides = read_integer("Sides: ");

    die current_die(sides);

    do
    {
        display_menu();

        option = read_integer_range("> ", 1, 3);

        switch (option)
        {
        case ROLL_DIE:
            current_die.roll();
            current_die.print();
            break;

        case NEW_DIE:
            sides = read_integer("Sides: ");
            current_die = die(sides);
            break;

        case QUIT:
            write_line("Goodbye!");
            break;
        }

    } while (option != QUIT);

    return 0;
}