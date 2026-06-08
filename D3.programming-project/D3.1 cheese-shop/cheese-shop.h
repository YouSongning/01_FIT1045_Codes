#include <splashkit.h>
#include <splashkit-arrays.h>
#include <string>

using std::string;

/**
 * Data about a cheese within an order or in stock.
 *
 * @field name The name of the cheese.
 * @field weight The weight of the cheese in stock (kg).
 * @field price_per_kg The price of the cheese per kg (cents).
 */
struct cheese_data
{
    string name;
    double weight;
    int price_per_kg;
};

/**
 * Data about an item in an order.
 */
struct order_item_data
{
    int cheese_index;
    double weight;
};

struct order_data
{
    string customer_name;
    dynamic_array<order_item_data> items;
};

/**
 * Data about the cheese shop - the stock on hand.
 *
 * @field cheeses The list of cheeses in stock.
 */
struct shop_data
{
    dynamic_array<cheese_data> cheeses;
    dynamic_array<order_data> orders;
};

/**
 * Initialise a cheese_data value - with parameters to initialise the name,
 * weight, and price_per_kg.
 *
 * @param name The name of the cheese. Defaults to an empty string.
 * @param weight The weight of the cheese in stock (kg). Defaults to 0.0.
 * @param price_per_kg The price of the cheese per kg (cents). Defaults to 0.
 */
cheese_data new_cheese(string name = "", double weight = 0.0, int price_per_kg = 0);

/**
 * Convert a cheese_data value to a string.
 *
 * @param cheese The cheese_data value to convert.
 * @param full_details If true, include full details of the cheese. Defaults to false.
 * @return string The string representation of the cheese_data value.
 */
string cheese_to_string(const cheese_data &cheese, bool full_details = false);

/**
 * Add a new cheese to the shop's cheese list.
 *
 * @param shop the shop's data
 * @param new_cheese the cheese to add
 */
void add_cheese(shop_data &shop, const cheese_data &new_cheese);

/**
 * Calculate the total cost of the cheese.
 *
 * The cost is returned in cents.
 *
 * @param cheese the cheese data
 * @return int the total cost of the cheese in cents
 */
int total_cost(const cheese_data &cheese);

/**
 * Reduce the weight of the cheese.
 *
 * Ignores negative values and ensures that the cheese weight
 * does not become negative. Returns the actual amount removed.
 *
 * @param cheese the cheese to reduce
 * @param amount the amount of weight to remove (kg)
 * @return double the actual weight removed
 */
double reduce_weight(cheese_data &cheese, double amount);

/**
 * Increase the weight of the cheese.
 *
 * Ignores negative values. Positive values are added to the
 * current cheese weight.
 *
 * @param cheese the cheese to increase
 * @param amount the amount of weight to add (kg)
 */
void increase_weight(cheese_data &cheese, double amount);

/**
 * Delete a cheese from the shop.
 *
 * @param shop the shop data
 * @param index the index of the cheese to delete
 */
void delete_cheese(shop_data &shop, int index);

order_data new_order(string customer_name = "");

/**
 * Add a cheese to an order.
 *
 * @param order the order
 * @param cheese_index the cheese being ordered
 * @param weight the amount ordered
 */
void add_order_item(order_data &order, int cheese_index, double weight);

/**
 * Update the weight of an item in an order.
 *
 * @param order the order
 * @param item_index the item to update
 * @param new_weight the new weight
 */
void update_order_item(order_data &order, int item_index, double new_weight);

/**
 * Remove an item from an order.
 *
 * @param order the order
 * @param item_index the item to remove
 */
void remove_order_item(order_data &order, int item_index);

/**
 * Fulfill an order and reduce stock levels.
 *
 * @param shop the shop data
 * @param order the order to fulfill
 */
void fulfill_order(shop_data &shop, const order_data &order);
