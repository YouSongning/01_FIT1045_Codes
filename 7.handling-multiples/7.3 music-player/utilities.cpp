#include "splashkit.h"

// read_string() function
string read_string(string prompt)
{
    write(prompt);
    return read_line();
}

// read_integer() function
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

// read_integer_range() function
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
        write_line("Please enter a value between " + to_string(low) + " and " + to_string(high) + ".");

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

// read_double() function
double read_double(string prompt)
{
    string input = read_string(prompt);

    while (!is_double(input))
    {
        write_line("Please enter a number.");
        input = read_string(prompt);
    }

    return to_double(input);
}

// read_double_range() function
double read_double_range(string prompt, double low, double high)
{
    // if low > high, swap
    if (low > high)
    {
        double temp = low;
        low = high;
        high = temp;
    }

    string input = read_string(prompt);

    // first validation: double
    while (!is_double(input))
    {
        write_line("Please enter a number.");
        input = read_string(prompt);
    }

    double value = to_double(input);

    // second validation: range
    while (value < low || value > high)
    {
        write_line("Please enter a value between " + to_string(low) + " and " + to_string(high) + ".");

        input = read_string(prompt);

        while (!is_double(input))
        {
            write_line("Please enter a number.");
            input = read_string(prompt);
        }

        value = to_double(input);
    }

    return value;
}

// read_boolean() function
bool read_boolean(string prompt)
{
    string input = read_string(prompt);

    while (
        input != "y" && input != "Y" &&
        input != "n" && input != "N")
    {
        write_line("Please enter y or n.");
        input = read_string(prompt);
    }

    return (input == "y" || input == "Y");
}
