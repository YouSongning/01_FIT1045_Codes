#include "splashkit.h"
#include "utilities.h"
#include "cheese-shop.h"

#include <format>
using std::format;

cheese_data new_cheese(string name, double weight, int price_per_kg)
{
    cheese_data cheese;
    cheese.name = name;
    cheese.weight = weight;
    cheese.price_per_kg = price_per_kg;

    return cheese;
}


string cheese_to_string(const cheese_data &cheese, bool full_details)
{
    if (full_details)
    {
        return format(
        "{}: {:.2f} kg, ${:.2f}/kg, Total: ${:.2f}",
        cheese.name,
        cheese.weight,
        cheese.price_per_kg / 100.0,
        total_cost(cheese) / 100.0
        );
    }
    else
    {
        return cheese.name;
    }

    

}


void add_cheese(shop_data &shop, const cheese_data &new_cheese)
{
    shop.cheeses.add(new_cheese); // or equivalent using your dynamic array
}


int total_cost(const cheese_data &cheese)
{
    return cheese.weight * cheese.price_per_kg;
}


double reduce_weight(cheese_data &cheese, double amount)
{
    if (amount < 0)
    {
        return 0;
    }

    if (amount > cheese.weight)
    {
        double removed = cheese.weight;
        cheese.weight = 0;
        return removed;
    }

    cheese.weight -= amount;
    return amount;
}


void increase_weight(cheese_data &cheese, double amount)
{
    if (amount < 0)
        return;

    cheese.weight += amount;
}


void delete_cheese(shop_data &shop, int index)
{
    if (index < 0 || index >= shop.cheeses.length())
    {
        return;
    }

    shop.cheeses.remove_at(index);
}


order_data new_order(string customer_name)
{
    order_data result;

    result.customer_name = customer_name;

    return result;
}


void add_order_item(order_data &order, int cheese_index, double weight)
{
    order_item_data item;

    item.cheese_index = cheese_index;
    item.weight = weight;

    order.items.add(item);
}


void update_order_item(order_data &order, int item_index, double new_weight)
{
    if (new_weight < 0)
    {
        return;
    }

    order.items[item_index].weight = new_weight;
}


void remove_order_item(order_data &order, int item_index)
{
    if (item_index < 0 || item_index >= order.items.length())
    {
        return;
    }

    order.items.remove_at(item_index);
}


void fulfill_order(shop_data &shop, const order_data &order)
{
    for (int i = 0; i < order.items.length(); i++)
    {
        order_item_data item;

        item = order.items[i];

        reduce_weight(shop.cheeses[item.cheese_index], item.weight);
    }
}



