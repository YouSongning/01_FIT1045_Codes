#include "splashkit.h"
#include "guess-that-number.h"

const int MAX_NUMBER = 100;
const int MAX_GUESSES = 7;

// function prototypes
bool perform_guess(int guess_number, int target);
void play_game();

// main
int main()
{

    bool again;

    do
    {
        play_game();

        write_line();
        print_line(50);

        again = read_boolean("Do you want to play again [Y/n]? ");

    } while (again);

    write_line("\nBye - enjoy the rest of your day!");
    return 0;
}

// perform_guess function
bool perform_guess(int guess_number, int target)
{
    int guess;

    guess = read_integer("Guess " + to_string(guess_number) + ": ");

    if (target < guess)
    {
        write_line("The number is less than " + to_string(guess));
    }
    else if (target > guess)
    {
        write_line("The number is larger than " + to_string(guess));
    }
    else
    {
        write_line("Well done ... the number was " + to_string(guess));
    }

    return guess == target;
}

// play_game procedure
void play_game()
{
    int my_number, guess_number;
    bool got_it;

    my_number = rnd(1, MAX_NUMBER);
    guess_number = 0; // Keep track of the number of guesses

    write_line("I am thinking of a number between 1 and " + to_string(MAX_NUMBER) + "\n");

    do
    {
        guess_number++;
        got_it = perform_guess(guess_number, my_number);
    } while (guess_number < MAX_GUESSES && !got_it);

    if (!got_it)
    {
        write_line("You ran out of guesses ... the number was " + to_string(my_number) + "\n");
    }
}