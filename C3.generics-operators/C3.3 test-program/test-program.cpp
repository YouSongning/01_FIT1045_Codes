#include "splashkit.h"
#include "index-operators-overloading.hpp"

int main()
{
    bounded_array<string, 5> names;

    names.add("Alice");
    names.add("Bob");
    names.add("Charlie");

    write_line("Printing array:");

    for (int i = 0; i < names.length(); i++)
    {
        write_line(names[i]);
    }

    return 0;
}