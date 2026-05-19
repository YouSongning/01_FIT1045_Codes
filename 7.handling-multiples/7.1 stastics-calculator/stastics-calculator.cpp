#include "splashkit.h"
#include "splashkit-arrays.h"
#include "utilities.h"

// Add populate_array() here
/**
 * Populate the array with values entered by the user
 *
 * @param data the array of values (passed by reference)
 */
void populate_array(dynamic_array<double> &data)
{
    int size = read_integer("How many values do you want to enter? ");
    if (size < 0)
    {
        size = 0;
    }

    // Populate each element - up to size
    for (int i = 0; i < size; i++)
    {
        add(data, read_double("Enter value: "));
    }
}

// Add print() function here
/**
 * Output the values in the array
 *
 * @param data the array of values
 */
void print(const dynamic_array<double> &data)
{
    for (int i = 0; i < length(data); i++)
    {
        write_line(to_string(i) + ": " + to_string(data[i], 2));
    }
}

// Add sum here
/**
 * Calculate the sum of the values in the array
 *
 * @param data the array of values
 * @return the sum of the values
 */
double sum(const dynamic_array<double> &data)
{
    int i;
    double result = 0;

    for (i = 0; i < length(data); i++)
    {
        result += data[i];
    }

    return result;
}

// Add mean here
/**
 * Calculate the mean of the values in the array
 *
 * @param data the array of values
 * @returns the mean of the values
 */
double mean(const dynamic_array<double> &data)
{
    if (length(data) > 0)
    {
        return sum(data) / length(data);
    }
    else
    {
        return 0;
    }
}

// find the max value in the array
/**
 * Calculate the largest value in the array
 *
 * @param data the array of values
 * @returns the largest value, or 0 if there are no values
 */
double max(const dynamic_array<double> &data)
{
    // Ensure there is data
    if (length(data) == 0)
        return 0;

    // Assume the first value is the largest
    double result = data[0];

    // Check the rest of the values
    for (int i = 1; i < length(data); i++)
    {
        if (data[i] > result)
        {
            result = data[i];
        }
    }

    return result;
}

// Add a value to the array
/**
 * Add a value to the array
 *
 * @param data the array of values
 */
void add_data(dynamic_array<double> &data)
{
    double value = read_double("Enter a value to add: ");
    add(data, value);
}

// Remove a value from the array
/**
 * Remove a value from the array
 *
 * @param data the array of values
 */
void remove_value(dynamic_array<double> &data)
{
    print(data);

    int index = read_integer("Enter the index of the value to remove: ");

    if (index >= 0 && index < length(data))
    {
        remove(data, index);
    }
    else
    {
        write_line("Sorry, that is not a valid index.");
    }
}

// Add print_menu() function here
/**
 * Print the menu of options
 */
void print_menu()
{
    write_line("\nMenu");
    write_line("1. Add a value");
    write_line("2. Remove a value");
    write_line("3. Print the values");
    write_line("4. Calculate stats");
    write_line("5. Quit");
}

int main()
{
    dynamic_array<double> data;
    int option;

    populate_array(data);

    print_menu();
    option = read_integer_range("Enter an option: ", 1, 5);

    while (option != 5)
    {
        switch (option)
        {
        case 1:
            add_data(data);
            break;
        case 2:
            remove_value(data);
            break;
        case 3:
            write_line("\nYou entered...\n");
            print(data);
            break;
        case 4:
            write_line("\nCalculating statistics...\n");

            write_line("Sum:        " + to_string(sum(data), 2));
            write_line("Mean:       " + to_string(mean(data), 2));
            write_line("Max:        " + to_string(max(data), 2));
            break;
        }
        read_string("Press Enter to continue...");

        print_menu();
        option = read_integer_range("Enter an option: ", 1, 5);
    }

    write_line("Goodbye!");

    return 0;
}