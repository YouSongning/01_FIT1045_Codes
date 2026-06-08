#include "splashkit.h"
#include "index-operators-overloading.hpp"

// convenience procedure for testing
void test_value(double value, double expected, string fail_message)
{
    if (value != expected)
    {
        write_line(to_string(value) + " != " + to_string(expected) + " | " + fail_message);
    }
}

int main()
{
    bounded_array<double, MAX_CAPACITY> numbers;

    write_line("Running tests - no output means no errors :)");
    write_line("===Tests Start===");

    test_value(numbers.length(), 0, "0 Length failed");

    numbers.add(7);
    test_value(numbers.get(0), 7, "1st Add or Get failed");

    numbers.add(3);
    test_value(numbers.get(1), 3, "2nd Add or Get failed");

    numbers.add(24);
    test_value(numbers.get(2), 24, "3rd Add or Get failed");

    numbers.get(2) = -8.5; // Change the 24 to -8.5
    test_value(numbers.get(2), -8.5, "Change value via Get failed");

    test_value(numbers.length(), 3, "3 Length failed");

    // test  capacity()
    test_value(numbers.capacity(), MAX_CAPACITY, "Capacity failed");

    // test operator[]
    test_value(numbers[0], 7, "Index operator read failed");

    numbers[0] = 100;
    test_value(numbers[0], 100, "Index operator write failed");

    // ===== Test a variety of exceptions ===== //

    // ------------ fill up the array to test capacity handling
    try
    {
        while (numbers.length() < MAX_CAPACITY)
        {
            numbers.add(0);
        }
    }
    catch (const string &str)
    {
        write_line("Add stopped adding elements before reaching capacity: " + str);
    }

    // ------------ test adding an element to a full array
    try
    {
        numbers.add(0);
        write_line("Add continued adding elements past max capacity");
    }
    catch (const string &str)
    {
        /* we expected an error, so this is success! So no output */
    }

    // ------------ test accessing negative indexes
    try
    {
        numbers.get(-4);
        write_line("Accessing index -4 didn't error!");
    }
    catch (const string &str)
    {
        /* we expected an error, so this is success! So no output */
    }

    // ------------ test accessing indexes larger than the maximum capacity
    try
    {
        numbers.get(MAX_CAPACITY);
        write_line("Accessing index MAX_CAPACITY didn't error!");
    }
    catch (const string &str)
    {
        /* we expected an error, so this is success! So no output */
    }

    try
    {
        numbers.remove(-1);
        write_line("Remove -1 didn't error!");
    }
    catch (const string &str)
    {
        /* we expected an error, so this is success! So no output */
    }

    // test remove()
    numbers.remove(1);
    test_value(numbers.length(), MAX_CAPACITY - 1, "3 Remove failed (length didn't decrease)");
    test_value(numbers.get(1), -8.5, "Remove failed (element didn't shift)");

    write_line("===Tests End===");
}