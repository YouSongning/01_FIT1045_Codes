#include "splashkit.h"
#include "guess-that-number.h"

// main
int main()
{

    play_game();

    string again = "";

    do
    {
        play_game();

        write_line();
        print_line(50);
        again = read_string("Do you want to play again [Y/n]? ");
    } while (again != "N" && again != "n");

    write_line("\nBye - enjoy the rest of your day!");
    return 0;
}