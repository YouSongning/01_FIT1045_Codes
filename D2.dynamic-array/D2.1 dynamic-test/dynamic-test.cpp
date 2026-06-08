/* dynamic-test.cpp - from the field guide. written by You Songning */
#include <stdlib.h>
#include "splashkit.h"
#include "utilities.h"

int main()
{

    // Retain a pointer to the data we allocate on the heap
    double *data_ptr;
    // Remember the number of elements we allocate (nothing else will)
    int size;

    // Get the size of the array to create - and allocate space on heap
    size = read_integer("Enter the number of items to store: ");
    data_ptr = (double *) malloc(size * sizeof(double));

    // Check we could allocate the memory
    if (data_ptr == NULL)
    {
        write_line("Memory allocation failed");
        return 1;
    }

    // Populate the data - assigning values to each element of the array
    for (int i = 0; i < size; i++)
    {
        data_ptr[i] = read_double("Enter a number: ");
    }

    // Access the values
    for (int i = 0; i < size; i++)
    {
        write_line("Value at index " + to_string(i) + ": " + to_string(data_ptr[i]));
    }

    // Free the memory
    free(data_ptr);
    data_ptr = NULL;

    //todo: print the data

    //todo: free the memory

    return 0;
}