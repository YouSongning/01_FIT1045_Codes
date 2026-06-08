#include "splashkit.h"
#include "linked-lists.hpp"

void test_value(int value, int expected, string fail_message)
{
    if (value != expected)
    {
        write_line(to_string(value) + " != " + to_string(expected) + " | " + fail_message);
    }
}

int main()
{
    linked_list<int> list;

    write_line("Running tests - no output means no errors :)");
    write_line("=== Tests Start ===");

    // test for add_node()
    node<int> *first_node = list.add_node(2);

    test_value(list.first->data, 2, "First node data failed");
    test_value(first_node->data, 2, "Returned node failed");
    test_value(list.last->data, 2, "Last node failed");

    // test for add_node() with multiple nodes
    node<int> *node4 = list.add_node(4);
    node<int> *node8 = list.add_node(8);
    list.add_node(16); // now is 2 -> 4 -> 8 -> 16

    test_value(list.first->next->data, 4, "Second node failed");
    test_value(list.first->next->next->data, 8, "Third node failed");
    test_value(list.last->data, 16, "Last node after add failed");

    // test for prepend() and find_previous_node()
    list.find_previous_node(node4);
    node<int> *node1 = list.prepend(1); // should be 1 -> 2 -> 4 -> 8 -> 16

    test_value(list.first->data, 1, "Prepend first failed");
    test_value(node1->next->data, 2, "Prepend link failed");

    // test for insert_after()
    list.insert_after(node4, 6); // should be 1 -> 2 -> 4 -> 6 -> 8 -> 16

    test_value(node4->next->data, 6, "Insert after failed");
    test_value(node4->next->next->data, 8, "Insert after link failed");

    // test for insert_before()
    list.insert_before(node4, 3); // should be 1 -> 2 -> 3 -> 4 -> 6 -> 8 -> 16

    test_value(list.first->next->next->data, 3, "Insert before failed");

    // test for remove()
    list.remove(node8); // should be 1 -> 2 -> 3 -> 4 -> 6 -> 16

    test_value(node4->next->next->data, 16, "Remove failed");

    // test for clear()
    linked_list<int> clear_test;

    clear_test.add_node(10);
    clear_test.add_node(20);
    clear_test.add_node(30);

    clear_test.clear();

    if (clear_test.first != nullptr)
    {
        write_line("Clear failed - first not nullptr");
    }

    if (clear_test.last != nullptr)
    {
        write_line("Clear failed - last not nullptr");
    }

    // tesr for exception handling
    node<int> *fake = new node<int>();

    try
    {
        list.find_previous_node(fake);
        write_line("find_previous_node should have failed!");
    }
    catch (const string &str)
    {
        // success
    }

    delete fake;
    fake = nullptr;

    write_line("=== Tests End ===");

    return 0;
}