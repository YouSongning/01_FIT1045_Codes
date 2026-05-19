#include "splashkit.h"
#include "splashkit-arrays.h"
#include "utilities.h"

// Constants:
const int NO_CHOICE = -1; // Returned from find_product() function if no choice was available


// Enums:
enum menu_option
{
    ADD_PRODUCT = 1,
    DELETE_PRODUCT = 2,
    UPDATE_PRODUCT = 3,
    SELL_PRODUCT = 4,
    PRINT_STATUS = 5,
    LIST_PRODUCTS = 6,
    QUIT = 7
};

enum update_product_option
{
    UPDATE_NAME = 1,
    UPDATE_COST_PRICE = 2,
    UPDATE_SALE_PRICE = 3,
    UPDATE_STOCK = 4,
    UPDATE_QUIT = 5
};


// Structs:
/**
 * A single product in the database.
 *
 * @field name       The name of the product
 * @field cost_price The price the product is purchased for
 * @field sale_price The price the product is sold at
 * @field stock      The quantity of the product currently in stock
 */
struct product_data
{
    string name;
    double cost_price;
    double sale_price;
    int stock;
};

/**
 * The store that contains all the products
 *
 * @field products      The array of product records
 * @field total_sales   The total amount sold (in dollars)
 * @field total_profits The total amount of profit (in dollars)
 */
struct store_data
{
    dynamic_array<product_data> products;
    double total_sales;
    double total_profits;
};


// Functions:
// read_product() function here
/**
 * Read product details from the user
 *
 * @return the completed product record
 */
product_data read_product()
{
    product_data result;

    result.name = read_string("Enter product name: ");
    result.cost_price = read_double("Enter cost price: ");
    result.sale_price = read_double("Enter sale price: ");
    result.stock = read_integer("Enter stock amount: ");

    return result;
}

// print_product() function here
/**
 * Print the details of a product
 *
 * @param product the product to print
 */
void print_product(const product_data &product)
{
    write_line("Product Name: " + product.name);
    write_line("Cost Price: $" + to_string(product.cost_price, 2));
    write_line("Sale Price: $" + to_string(product.sale_price, 2));
    write_line("Stock: " + to_string(product.stock));
}

// add_product() function here
/**
* Read in a product from the user, and add it to the store.
*
* @param store The store_data to modify
*/
void add_product(store_data &store)
{
    product_data product = read_product();

    add(store.products, product);

    write_line("Product '" + product.name + "' added to store.");
}

// list_products() function here
/**
* Lists the products added to the store.
*
* @param store The store_data to list from
*/
void list_products(const store_data &store)
{
    for(int i = 0; i < length(store.products); i ++)
    {
        write(to_string(i + 1) + ".");
        print_product(store.products[i]);
    }

    write_line("There are a total of " + to_string(length(store.products)) + " products.");
}

// find_product() function here
/**
* Utility function for searching the store and selecting an index.
*
* @param store The store_data to search
* @return      The index of the product selected, or NO_CHOICE in the case of no selection
*/
int find_product(const store_data &store)
{
    if (length(store.products) == 0)
    {
        write_line("No products added yet.");
        return NO_CHOICE;
    }

    string search_text = read_string("Enter text to search for: ");
    bool found_product = false;

    for (int i = 0; i < length(store.products); i++)
    {
        if (contains(store.products[i].name, search_text))
        {
            write_line(to_string(i + 1) + ". " + store.products[i].name);
            found_product = true;
        }
    }

    if (!found_product)
    {
        write_line("No matching products.");
        return NO_CHOICE;
    }

    int index = read_integer_range("Select a product: ", 1, length(store.products)) - 1;

    if (!contains(store.products[index].name, search_text))
    {
        write_line("Invalid selection.");
        return NO_CHOICE;
    }

    return index;
}

// sell_product() function here
/**
* Allows the user to select a product and sell a number of units
*
* @param store The store_data to modify
*/
void sell_product(store_data &store)
{
    int index = find_product(store);
    if (index == NO_CHOICE)
        return;

    // Prevent sale when there is no stock available
    if (store.products[index].stock == 0)
    {
        write_line("No stock available for this product.");
        return;
    }

    int units = read_integer_range("Enter number of units sold: ", 0, store.products[index].stock);

    double sale_total = store.products[index].sale_price * units;
    double cost_total = store.products[index].cost_price * units;
    double profit_total = sale_total - cost_total;

    store.products[index].stock -= units;
    store.total_sales += sale_total;
    store.total_profits += profit_total;

    write_line("Sold " + to_string(units) + " units");
    write_line("Revenue: $" + to_string(sale_total, 2) + ", Profit: $" + to_string(profit_total, 2));
}

// delete_product() function here
/**
* Allows the user to select a product and deletes it from the store.
*
* @param store The store_data to modify
*/
void delete_product(store_data &store)
{
    int index = find_product(store);
    if (index == NO_CHOICE)
        return;

    // Take a copy of the name before deleting it
    // After deleting it would be too late :)
    string name = store.products[index].name;

    remove(store.products, index);

    write_line("Deleted '" + name + "'");
}

// print_menu() function here
/**
 * Print the main menu options
 */
void print_main_menu()
{
    write_line("Main Menu");
    write_line("1. Add a new product");
    write_line("2. Delete a product");
    write_line("3. Update a product");
    write_line("4. Sell a product");
    write_line("5. Print status");
    write_line("6. List products");
    write_line("7. Quit");
}

// print_status() function here
/**
* Prints the store's status, including total sales,
* profits, value of current stock, and number of low stock products.
*
* @param store the store_data to summarize
*/
void print_status(const store_data &store)
{
    // Calculate value of stock and number of low stock products
    double stock_value = 0;
    int low_stock = 0;

    for (int i = 0; i < length(store.products); i++)
    {
        stock_value += store.products[i].cost_price * store.products[i].stock;

        if (store.products[i].stock < 10)
            low_stock++;
    }

    // Print report
    write_line("== Store Report ==");
    write_line("Total sales:     $"  + to_string(store.total_sales, 2));
    write_line("Total profit:    $"  + to_string(store.total_profits, 2));
    write_line("Products:        "   + to_string(length(store.products)));
    write_line("Stock value:     $"  + to_string(stock_value, 2));
    write_line("Low stock (<10): "   + to_string(low_stock));
}

// print_update_menu() function here
/**
* Print the update menu options
*/
void print_update_menu()
{
    write_line("Update Menu");
    write_line("1. Update name");
    write_line("2. Update cost price");
    write_line("3. Update sale price");
    write_line("4. Update number in stock");
    write_line("5. Quit update");
}

// update_product() function here
/**
* Interactively update an existing product.
*
* @param store The store to modify
*/
void update_product(store_data &store)
{
    int index = find_product(store);
    if (index == NO_CHOICE)
        return;

    update_product_option option;
    do
    {
        write_line("Current details:");
        print_product(store.products[index]);
        write_line("");
        print_update_menu();

        option = (update_product_option)read_integer_range("Enter an option: ", 1, 5);

        switch (option)
        {
        case UPDATE_NAME:
            store.products[index].name = read_string("Enter new name: ");
            write_line("Updated name.");
            break;
        case UPDATE_COST_PRICE:
            store.products[index].cost_price = read_double("Enter new cost price: ");
            write_line("Updated cost price.");
            break;
        case UPDATE_SALE_PRICE:
            store.products[index].sale_price = read_double("Enter new sale price: ");
            write_line("Updated sale price.");
            break;
        case UPDATE_STOCK:
            store.products[index].stock = read_integer("Enter new amount in stock: ");
            write_line("Updated amount of stock.");
            break;
        case UPDATE_QUIT:
            break;
        }
    } while (option != UPDATE_QUIT);
}

int main()
{
    store_data store = {};
    write_line("Welcome to the Product Database!");

    menu_option option;
    do 
    {
        print_main_menu();
        option = (menu_option)read_integer_range("Please choose an option: ", 1, 7);

        switch (option)
        {
            case ADD_PRODUCT:
                add_product(store);
                break;
            case DELETE_PRODUCT:
                delete_product(store);
                break;
            case UPDATE_PRODUCT:
                // To implement
                break;
            case SELL_PRODUCT:
                sell_product(store);
                break;
            case PRINT_STATUS:
                // To implement
                break;
            case LIST_PRODUCTS:
                list_products(store);
                break;
            case QUIT:
                break;
        }
    } while (option != QUIT);

    write_line("Thank you for your use!");

    return 0;

}