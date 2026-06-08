#include "splashkit.h"
#include "dynamic-array-ai.hpp"

// Helper function to run a test and print the result
void test(bool condition, string test_name)
{
    if (condition)
    {
        write_line("[PASS] " + test_name);
    }
    else
    {
        write_line("[FAIL] " + test_name);
    }
}

// Basic Add: test if length is correct, get is correct, operator[] is correct
void test_add()
{
    dynamic_array<int> arr;

    arr.add(10);
    arr.add(20);
    arr.add(30);

    test(arr.length() == 3, "Length increases after add");

    test(arr[0] == 10, "First value stored correctly");

    test(arr[1] == 20, "Second value stored correctly");

    test(arr[2] == 30, "Third value stored correctly");
}

// Expansion: test the capacity doubles when full, length is preserved, data is preserved
void test_expand()
{
    dynamic_array<int> arr;

    int initial_capacity = arr.capacity();

    for (int i = 0; i < 11; i++)
    {
        arr.add(i);
    }

    test(arr.capacity() == initial_capacity * 2, "Capacity doubles when full");

    test(arr.length() == 11, "Length preserved after expansion");

    test(arr[10] == 10, "Data preserved after expansion");
}

// Remove: test the length decreases, element before removed index preserved, elements shifted correctly
void test_remove()
{
    dynamic_array<int> arr;

    arr.add(1);
    arr.add(2);
    arr.add(3);

    arr.remove(1);

    test(arr.length() == 2, "Length decreases after remove");

    test(arr[0] == 1, "Element before removed index preserved");

    test(arr[1] == 3, "Elements shifted correctly");
}

// Invalid Index: test the get function throws an exception when the index is out of bounds.
// Also test operator[] throws an exception for invalid index.
void test_invalid_index()
{
    dynamic_array<int> arr;

    bool exception_thrown = false;

    try
    {
        arr.get(0);
    }
    catch (...)
    {
        exception_thrown = true;
    }

    test(exception_thrown, "Invalid index throws exception");
}

// Copy Constructor: test that the copy constructor creates a deep copy of the array. Modifying the copy should not affect the original.
void test_copy_constructor()
{
    dynamic_array<int> arr;

    arr.add(10);
    arr.add(20);

    dynamic_array<int> copy = arr;

    copy[0] = 99;

    test(arr[0] == 10, "Original unchanged after copy");

    test(copy[0] == 99, "Copied array modified independently");
}

// Assignment Operator: test that the assignment operator creates a deep copy of the array. Modifying the assigned array should not affect the original.
void test_assignment()
{
    dynamic_array<int> arr1;

    arr1.add(1);
    arr1.add(2);

    dynamic_array<int> arr2;

    arr2 = arr1;

    arr2[0] = 50;

    test(arr1[0] == 1, "Assignment performs deep copy");

    test(arr2[0] == 50, "Assigned array modified independently");
}

// Test with a different type (string): test that the dynamic array works with types other than int.
void test_string()
{
    dynamic_array<string> arr;

    arr.add("Alice");
    arr.add("Bob");

    test(arr.length() == 2,
         "String array stores elements");

    test(arr[0] == "Alice",
         "First string stored correctly");

    test(arr[1] == "Bob",
         "Second string stored correctly");
}

int main()
{
    write_line("=== Dynamic Array Tests ===");

    test_add();

    test_expand();

    test_remove();

    test_invalid_index();

    test_copy_constructor();

    test_assignment();

    test_string();

    write_line("=== Tests Complete ===");

    return 0;
}