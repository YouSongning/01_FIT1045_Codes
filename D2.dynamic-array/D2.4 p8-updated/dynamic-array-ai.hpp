#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include "splashkit.h"

template <typename T>
class dynamic_array
{

    private:
        int size;
        int m_capacity;
        T *data;


    public:
        // Constructor
        dynamic_array()
        {
            size = 0;
            m_capacity = 10;
            data = new T[m_capacity];
        }

        // Copy Constructor (Deep Copy)
        dynamic_array(const dynamic_array &other)
        {
            size = other.size;
            m_capacity = other.m_capacity;

            data = new T[m_capacity];

            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }

        // Copy Assignment Operator (Deep Copy)
        dynamic_array &operator=(const dynamic_array &other)
        {
            if (this == &other)
            {
                return *this;
            }

            delete[] data;

            size = other.size;
            m_capacity = other.m_capacity;

            data = new T[m_capacity];

            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }

            return *this;
        }

        // Destructor
        ~dynamic_array()
        {
            delete[] data;
        }


        void expand()
        {
            m_capacity *= 2;

            T *new_data = new T[m_capacity];

            for (int i = 0; i < size; i++)
            {
                new_data[i] = data[i];
            }

            delete[] data;
            data = new_data;
        }


        void add(T value)
        {
            if (size >= m_capacity)
            {
                expand();
            }

            data[size] = value;
            size++;
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


        int length() const
        {
            return size;
        }

        int capacity() const
        {
            return m_capacity;
        }

        bool is_empty() const
        {
            return size == 0;
        }


        T &get(int index)
        {
            if (index < 0 || index >= size)
            {
                throw string("Accessed invalid array index " + to_string(index));
            }

            return data[index];
        }

        const T &get(int index) const
        {
            if (index < 0 || index >= size)
            {
                throw string("Accessed invalid array index " + to_string(index));
            }

            return data[index];
        }

        T &operator[](int index)
        {
            return get(index);
        }

        const T &operator[](int index) const
        {
            return get(index);
        }
    };

#endif