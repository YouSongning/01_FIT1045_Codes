#include "splashkit.h"

/*
@param guess_number the sequence number of the guess, this should start at 1
@param target the number the user is aiming to guess

@return true if the user guesses the number, otherwise false.
*/

const int MAX_NUMBER = 100;
const int MAX_GUESSES = 7;


// print_line procedure
void print_line(int length)
{
    int i = 0;

    while (i < length)
    {
        write("-");
        i++;
    }

    write_line("\n");
}





// read_string function
string read_string(string prompt)
{
    write(prompt);
    return read_line();
}


// read_integer function
int read_integer(string prompt)
{
    string input = read_string(prompt);
    while (!is_integer(input))
    {
        write_line("Please enter a whole number.");
        input = read_string(prompt); 
    }
    return to_integer(input);
}


// read_integer_range function
int read_integer_range(string prompt, int low, int high)
{
    // if low > high， swap
    if (low > high)
    {
        int temp = low;
        low = high;
        high = temp;
    }

    string input = read_string(prompt);

    // first validation：integer
    while (!is_integer(input))
    {
        write_line("Please enter a whole number.");
        input = read_string(prompt);
    }

    int value = to_integer(input);

    // second validation：scope
    while (value < low || value > high)
    {
        write_line("Please enter a value between " + to_string(low) 
                   + " and " + to_string(high) + ".");
        
        input = read_string(prompt);
        while (!is_integer(input))
        {
            write_line("Please enter a whole number.");
            input = read_string(prompt);
        }
        value = to_integer(input);
    }

    return value;
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



//play_game procedure
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
        got_it = perform_guess(guess_number, my_number) ;
    } while (guess_number < MAX_GUESSES && !got_it);

    if (!got_it)
    {
        write_line("You ran out of guesses ... the number was " + to_string(my_number) + "\n");
    }
}











