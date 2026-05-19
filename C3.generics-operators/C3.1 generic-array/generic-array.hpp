#ifndef GENERIC_ARRAY_HPP
#define GENERIC_ARRAY_HPP

#include "splashkit.h"

const int MAX_CAPACITY = 50;
          
template<typename T, int MAX_CAPACITY>
class bounded_array
{
    int size;
    T data[MAX_CAPACITY];

    public:
    bounded_array()
    {
        size = 0;
    }

    int length()
    {
        return size;
    }

    int capacity()
    {
        return MAX_CAPACITY;
    }

    void add(T value)
    {
        if (size >= MAX_CAPACITY )
        {
            throw string("Failed to add element - the array is full!");
        }

        data[size] = value;
        size ++;
    }

    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            throw string("Accessed invalid array index " + to_string(index));
        }
        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }

    T& get(int index)
    {
        if (index < 0 || index >= size)
        {
            throw string("Accessed invalid array index " + to_string(index));
        }
        return data[index];
    }
};

#endif