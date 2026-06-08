#ifndef LINKED_LISTS_HPP
#define LINKED_LISTS_HPP

#include "splashkit.h"

/**
 * A node is a class that contains a pointer to the next node,
 * and a data value.
 *
 * @tparam T The type of the data that will be stored in the node.
 * @field next A pointer to the next node in the list.
 * @field data The data that is stored in the node.
 */
template <typename T>
class node
{
public:
    node *next;
    T data;

    node()
    {
        write_line("Node Created");
    }

    ~node()
    {
        write_line("Node Deleted");
    }
};

/**
 * A linked list is a class that contains a pointer to the
 * first node, and the last node of the list.
 *
 * @tparam T The type of the data that will be stored in the list.
 * @field first A pointer to the first node in the list.
 * @field last A pointer to the last node in the list.
 */
template <typename T>
class linked_list
{
public:
    node<T> *first;
    node<T> *last;

    linked_list()
    {
        first = nullptr;
        last = nullptr;
    }

    // adding nodes
    /**
     * Add a new node to the end of the list.
     *
     * @param data The data to store in the new node.
     */
    node<T> *add_node(T data)
    {
        node<T> *new_node = new node<T>();

        new_node->data = data;
        new_node->next = nullptr;
        if (first == nullptr)
        {
            first = new_node;
            last = new_node;
        }
        else
        {
            last->next = new_node;
            last = new_node;
        }

        return new_node;
    }

    // find previous node
    /**
     * Finds and returns the node previous to `target_node`.
     *
     * @param target_node The target node to find the previous node for.
     */
    node<T> *find_previous_node(node<T> *target_node)
    {
        if (target_node == first)
            return nullptr;

        node<T> *current = first;
        while (current != nullptr)
        {
            if (current->next == target_node)
            {
                return current;
            }

            // move to the next node
            current = current->next;
        }

        // If we couldn't find it...probably best to throw an exception
        throw string("find_previous_node search failed: node not in list.");
    }

    // clear all nodes
    /**
     * Clear a linked list by deleting all nodes.
     */
    void clear()
    {
        node<T> *current = first;
        while (current != nullptr)
        {
            // take a copy of the next node's pointer _before_ deleting current
            node<T> *next = current->next;

            delete current;

            current = next;
        }
        // Reset the first and last
        first = nullptr;
        last = nullptr;
    }

    // destructor
    ~linked_list()
    {
        clear();
    }

    // remove specific node
    /**
     * Remove the indicated node from the list.
     *
     * @param del_node The node to remove from the list.
     */
    void remove(node<T> *del_node)
    {
        node<T> *previous_node = nullptr;

        // Check if we are removing the first node.
        if (first == del_node)
        {
            // Set first to the 2nd node, if it exists
            first = del_node->next;
            // If it is the first node, then
            // previous_node is already the correct value.
            // I'll assign it anyway for clariy.
            previous_node = nullptr;
        }
        else
        {
            // Find the previous node
            previous_node = find_previous_node(del_node);

            // Make its connection skip over `del_node`
            previous_node->next = del_node->next;
        }

        // Similarly, check for removing the last node
        if (last == del_node)
        {
            last = previous_node;
        }

        // Delete the node from memory
        delete del_node;
    }

    node<T> *prepend(T data)
    {
        node<T> *new_node = new node<T>();

        new_node->data = data;

        new_node->next = first;

        first = new_node;

        if (last == nullptr)
        {
            last = new_node;
        }

        return new_node;
    }

    node<T> *insert_after(node<T> *target_node, T data)
    {
        node<T> *new_node = new node<T>();

        new_node->data = data;

        new_node->next = target_node->next;

        target_node->next = new_node;

        if (target_node == last)
        {
            last = new_node;
        }

        return new_node;
    }

    node<T> *insert_before(node<T> *target_node, T data)
    {
        if (target_node == first)
        {
            return prepend(data);
        }

        node<T> *previous_node = find_previous_node(target_node);

        node<T> *new_node = new node<T>();

        new_node->data = data;

        new_node->next = target_node;

        previous_node->next = new_node;

        return new_node;
    }
};

#endif