#include "splashkit.h"
#include "utilities.h"
#include "cheese-shop.h"

#include <format>
using std::format;

/**
 * The list of options in the main menu.
 *
 * @option EXIT_MAIN_MENU The option to exit the main menu.
 * @option ADD_CHEESE_MENU The option to add a cheese.
 * @option EDIT_CHEESE_MENU The option to edit a cheese.
 * @option PRINT_STOCK_LIST_MENU The option to print the stock list.
 */
enum main_menu_option
{
    EXIT_MAIN_MENU,
    ADD_CHEESE_MENU,
    EDIT_CHEESE_MENU,
    DELETE_CHEESE_MENU,
    PRINT_STOCK_LIST_MENU,

    CREATE_ORDER_MENU,
    ADD_CHEESE_TO_ORDER_MENU,
    EDIT_ORDER_ITEM_MENU,
    REMOVE_ORDER_ITEM_MENU,
    FULFILL_ORDER_MENU,
    PRINT_ORDERS_MENU
};

/**
 * Output the cheese data to the terminal - on a single line.
 *
 * @param cheese the cheese data to output
 */
void print_cheese(const cheese_data &cheese, bool with_full_details)
{
    write_line(cheese_to_string(cheese, with_full_details));
}

/**
 * Read data from the user and populate and return the cheese
 * data to the caller.
 *
 * @return cheese_data populated with the data read from the user
 */
cheese_data read_cheese()
{
    cheese_data result;

    result.name = read_string("Enter cheese name: ");
    result.weight = read_double("Enter weight in stock (kg): ");
    result.price_per_kg = read_integer("Enter price per kg (cents): ");

    return result;
}

/**
 * Allow the user to edit the passed in cheese.
 *
 * @param cheese a reference to the cheese to be updated.
 */
void edit_cheese(cheese_data &cheese)
{
    write_line("Editing cheese: " + cheese_to_string(cheese, true));

    if (read_integer_range("Do you want to edit the name? (1 for yes, 0 for no): ", 0, 1) == 1)
    {
        cheese.name = read_string("Enter new cheese name: ");
    }
    if (read_integer_range("Do you want to edit the weight? (1 for yes, 0 for no): ", 0, 1) == 1)
    {
        cheese.weight = read_double("Enter new weight in stock (kg): ");
    }
    if (read_integer_range("Do you want to edit the price? (1 for yes, 0 for no): ", 0, 1) == 1)
    {
        cheese.price_per_kg = read_integer("Enter new price per kg (cents): ");
    }
}

/**
 * Output these cheeses - optionally with the index.
 *
 * @param cheeses the details to output
 * @param with_ids true if an index (1 based) should be included in the output
 */
void print_cheese_list(const dynamic_array<cheese_data> &cheeses, bool with_ids)
{
    for (int i = 0; i < cheeses.length(); i++)
    {
        cheese_data cheese = cheeses[i];
        if (with_ids)
        {
            write(format("{}: ", i + 1));
        }
        print_cheese(cheese, true);
    }
}

/**
 * Ask the user to select a cheese from the supplied list. This returns the
 * index of the chosen cheese, or -1 if none are selected.
 *
 * @param cheeses the cheese to output
 * @return int the index of the chosen cheese or -1 if none
 */
int select_cheese(const dynamic_array<cheese_data> &cheeses)
{
    if (cheeses.length() == 0)
    {
        write_line("No cheese in stock.");
        return -1;
    }

    write_line("0: Select none");

    print_cheese_list(cheeses, true);

    return read_integer_range("Select cheese (0 - " + to_string(cheeses.length()) + "): ", 0, cheeses.length()) - 1;
}

/**
 * Perform the steps needed to add a cheese to the shop.
 *
 * @param shop the shop where the cheese is to be added.
 */
void handle_add_cheese(shop_data &shop)
{
    cheese_data new_cheese = read_cheese();

    add_cheese(shop, new_cheese);
}

/**
 * Perform the steps to allow the user to edit a cheese in the shop.
 *
 * @param shop the shop with the cheese to be edited
 */
void handle_edit_cheese(shop_data &shop)
{
    int index = select_cheese(shop.cheeses);

    if (index == -1)
        return;

    edit_cheese(shop.cheeses[index]);
}

/**
 * Handle deleting a cheese from the shop.
 *
 * Allows the user to select a cheese and removes it
 * from the shop if a valid selection is made.
 *
 * @param shop the shop data
 */
void handle_delete_cheese(shop_data &shop)
{
    int index = select_cheese(shop.cheeses);

    if (index == -1)
    {
        return;
    }

    delete_cheese(shop, index);
}

/**
 * Output the list of stock in the shop.
 *
 * @param shop the shop with the cheese to be output
 */
void print_stock_list(const shop_data &shop)
{
    if (shop.cheeses.length() == 0)
    {
        write_line("No cheese");
        return;
    }

    write_line();
    write_line("===================================");
    write_line("Cheese stock list:");
    write_line("===================================");

    for (int i = 0; i < shop.cheeses.length(); i++)
    {
        print_cheese(shop.cheeses[i], true);
    }

    write_line("===================================");
    write_line();
}

void print_orders(const shop_data &shop)
{
    write_line();
    write_line("Orders:");

    for (int i = 0; i < shop.orders.length(); i++)
    {
        write_line(to_string(i + 1) + ": " + shop.orders[i].customer_name);
    }
}

int select_order(const shop_data &shop)
{
    if (shop.orders.length() == 0)
    {
        write_line("No orders.");
        return -1;
    }

    for (int i = 0; i < shop.orders.length(); i++)
    {
        write_line(to_string(i + 1) + ": " + shop.orders[i].customer_name);
    }

    return read_integer_range("Select order (1-" + to_string(shop.orders.length()) + "): ", 1, shop.orders.length()) - 1;
}

void handle_create_order(shop_data &shop)
{
    string customer_name;

    customer_name = read_string("Enter customer name: ");

    shop.orders.add(new_order(customer_name));
}

void handle_add_cheese_to_order(shop_data &shop)
{
    int order_index = select_order(shop);

    if (order_index == -1)
    {
        return;
    }

    int cheese_index = select_cheese(shop.cheeses);

    if (cheese_index == -1)
    {
        return;
    }

    double weight = read_double("Enter weight: ");

    add_order_item(shop.orders[order_index], cheese_index, weight);
}

void handle_edit_order_item(shop_data &shop)
{
    int order_index = select_order(shop);

    if (order_index == -1)
    {
        return;
    }

    order_data &order = shop.orders[order_index];

    if (order.items.length() == 0)
    {
        return;
    }

    int item = read_integer_range("Select item: ", 1, order.items.length()) - 1;

    double weight = read_double("New weight: ");

    update_order_item(order, item, weight);
}

void handle_remove_order_item(shop_data &shop)
{
    int order_index = select_order(shop);

    if (order_index == -1)
    {
        return;
    }

    order_data &order = shop.orders[order_index];

    if (order.items.length() == 0)
    {
        return;
    }

    int item = read_integer_range("Select item: ", 1, order.items.length()) - 1;

    remove_order_item(order, item);
}

void handle_fulfill_order(shop_data &shop)
{
    int order_index = select_order(shop);

    if (order_index == -1)
    {
        return;
    }

    fulfill_order(shop, shop.orders[order_index]);
}

/**
 * Show the main menu and get the chosen option from the user.
 *
 * @return int the chosen option.
 */
main_menu_option read_main_menu_option()
{
    write_line("\n0. Exit");

    write_line("1. Add cheese");
    write_line("2. Edit cheese");
    write_line("3. Delete cheese");
    write_line("4. Print cheese list");

    write_line("5. Create order");
    write_line("6. Add cheese to order");
    write_line("7. Edit order item");
    write_line("8. Remove order item");
    write_line("9. Fulfill order");
    write_line("10. Print order menu");

    return (main_menu_option)read_integer_range("Select an option (0-10): ", 0, 10);
}

int main()
{
    shop_data shop;
    main_menu_option choice;

    do
    {
        choice = read_main_menu_option();

        switch (choice)
        {
        case EXIT_MAIN_MENU:
            write_line("Exiting...");
            break;

        case ADD_CHEESE_MENU:
            handle_add_cheese(shop);
            break;
        case EDIT_CHEESE_MENU:
            handle_edit_cheese(shop);
            break;
        case DELETE_CHEESE_MENU:
            handle_delete_cheese(shop);
            break;
        case PRINT_STOCK_LIST_MENU:
            print_stock_list(shop);
            break;

        case CREATE_ORDER_MENU:
            handle_create_order(shop);
            break;
        case ADD_CHEESE_TO_ORDER_MENU:
            handle_add_cheese_to_order(shop);
            break;
        case EDIT_ORDER_ITEM_MENU:
            handle_edit_order_item(shop);
            break;
        case REMOVE_ORDER_ITEM_MENU:
            handle_remove_order_item(shop);
            break;
        case FULFILL_ORDER_MENU:
            handle_fulfill_order(shop);
            break;
        case PRINT_ORDERS_MENU:
            print_orders(shop);
            break;
        }
    } while (choice != EXIT_MAIN_MENU);

    return 0;
}