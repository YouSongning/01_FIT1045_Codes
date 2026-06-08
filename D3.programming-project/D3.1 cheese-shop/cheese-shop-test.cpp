#include "catch_amalgamated.hpp"
#include "cheese-shop.h"

using Catch::Approx;

TEST_CASE("Cheese - Create new cheese with default values")
{
    cheese_data cheese;
    cheese = new_cheese();

    REQUIRE(cheese.name == "");
    REQUIRE(cheese.weight == 0.0);
    REQUIRE(cheese.price_per_kg == 0);
}

// Other cases to check passing in 1 or 2 arguments
TEST_CASE("Cheese - Provide name, weight, and price values for new cheese")
{
    cheese_data cheese;
    cheese = new_cheese("Cheddar", 1.5, 2000);

    REQUIRE(cheese.name == "Cheddar");
    REQUIRE(cheese.weight == Approx(1.5));
    REQUIRE(cheese.price_per_kg == 2000);
}


TEST_CASE("Cheese - Convert cheese data to string")
{
    cheese_data cheese;
    cheese = new_cheese("Cheddar", 1.5, 2000);

    // Test full details
    string result = cheese_to_string(cheese, true);
    string expected = "Cheddar: 1.50 kg, $20.00/kg, Total: $30.00";

    REQUIRE(result == expected);

    // Test without full details
    result = cheese_to_string(cheese, false);
    expected = "Cheddar";

    REQUIRE(result == expected);

    // Change the cheese details
    cheese = new_cheese("Camembert");

    result = cheese_to_string(cheese, false);
    expected = "Camembert";

    REQUIRE(result == expected);

    // Shows defaults - and 0s
    result = cheese_to_string(cheese, true);
    expected = "Camembert: 0.00 kg, $0.00/kg, Total: $0.00";

    REQUIRE(result == expected);
}


TEST_CASE("Shop - Can add cheese to the shop")
{
    shop_data shop;

    cheese_data cheese = new_cheese("Cheddar", 1.5, 2000);
    add_cheese(shop, cheese);

    REQUIRE(shop.cheeses.length() == 1);
    REQUIRE(shop.cheeses[0].name == "Cheddar");
    REQUIRE(shop.cheeses[0].weight == Approx(1.5));
    REQUIRE(shop.cheeses[0].price_per_kg == 2000);

    // Add another cheese
    cheese = new_cheese("Gouda", 2.0, 1500);
    add_cheese(shop, cheese);

    REQUIRE(shop.cheeses.length() == 2);
    REQUIRE(shop.cheeses[1].name == "Gouda");
    REQUIRE(shop.cheeses[1].weight == Approx(2.0));
    REQUIRE(shop.cheeses[1].price_per_kg == 1500);
    // Check the first cheese again
    REQUIRE(shop.cheeses[0].name == "Cheddar");
    REQUIRE(shop.cheeses[0].weight == Approx(1.5));
    REQUIRE(shop.cheeses[0].price_per_kg == 2000);
}


TEST_CASE("Cheese - Calculate total cost")
{
    cheese_data cheese;

    cheese = new_cheese("Cheddar", 1.5, 2000);

    REQUIRE(total_cost(cheese) == 3000);

    cheese = new_cheese("Gouda", 2.0, 1500);

    REQUIRE(total_cost(cheese) == 3000);

    cheese = new_cheese("Camembert", 0.0, 2500);

    REQUIRE(total_cost(cheese) == 0);
}


TEST_CASE("Cheese - Reduce weight")
{
    cheese_data cheese;

    cheese = new_cheese("Cheddar", 1.5, 2000);

    REQUIRE(reduce_weight(cheese, 0.5) == Approx(0.5));

    REQUIRE(cheese.weight == Approx(1.0));

    REQUIRE(reduce_weight(cheese, 2.0) == Approx(1.0));

    REQUIRE(cheese.weight == Approx(0.0));
}


TEST_CASE("Cheese - Reduce weight ignores negatives")
{
    cheese_data cheese;

    cheese = new_cheese("Cheddar", 1.5, 2000);

    REQUIRE(reduce_weight(cheese, -1.0) == Approx(0.0));

    REQUIRE(cheese.weight == Approx(1.5));
}


TEST_CASE("Cheese - Increase weight")
{
    cheese_data cheese;

    cheese = new_cheese("Cheddar", 1.5, 2000);

    increase_weight(cheese, 0.75);

    REQUIRE(cheese.weight == Approx(2.25));
}


TEST_CASE("Cheese - Increase weight ignores negatives")
{
    cheese_data cheese;

    cheese = new_cheese("Cheddar", 1.5, 2000);

    increase_weight(cheese, -5);

    REQUIRE(cheese.weight == Approx(1.5));
}


TEST_CASE("Shop - Delete cheese from shop")
{
    shop_data shop;

    add_cheese(shop, new_cheese("Cheddar", 1.5, 2000));
    add_cheese(shop, new_cheese("Gouda", 2.0, 1500));
    add_cheese(shop, new_cheese("Brie", 1.0, 2500));

    REQUIRE(shop.cheeses.length() == 3);

    delete_cheese(shop, 1);

    REQUIRE(shop.cheeses.length() == 2);

    REQUIRE(shop.cheeses[0].name == "Cheddar");
    REQUIRE(shop.cheeses[1].name == "Brie");
}


TEST_CASE("Shop - Delete cheese ignores invalid index")
{
    shop_data shop;

    add_cheese(shop, new_cheese("Cheddar", 1.5, 2000));

    delete_cheese(shop, -1);
    REQUIRE(shop.cheeses.length() == 1);

    delete_cheese(shop, 5);
    REQUIRE(shop.cheeses.length() == 1);
}


TEST_CASE("Order - Create empty order")
{
    order_data order;

    order = new_order();

    REQUIRE(order.customer_name == "");
    REQUIRE(order.items.length() == 0);
}


TEST_CASE("Order - Create order with customer name")
{
    order_data order;

    order = new_order("Alice");

    REQUIRE(order.customer_name == "Alice");
    REQUIRE(order.items.length() == 0);
}


TEST_CASE("Order - Add cheese to order")
{
    order_data order;

    order = new_order("Alice");

    add_order_item(
        order,
        0,
        1.5
    );

    REQUIRE(order.items.length() == 1);

    REQUIRE(order.items[0].cheese_index == 0);

    REQUIRE(
        order.items[0].weight
        == Approx(1.5)
    );
}


TEST_CASE("Order - Update order item weight")
{
    order_data order;

    order = new_order("Alice");

    add_order_item(order, 0, 1.5);

    update_order_item(order,0,2.25);

    REQUIRE(order.items[0].weight == Approx(2.25));
}


TEST_CASE("Order - Ignore negative item weights")
{
    order_data order;

    order = new_order("Alice");

    add_order_item(order, 0, 1.5);

    update_order_item(order, 0, -5);

    REQUIRE(order.items[0].weight == Approx(1.5));
}


TEST_CASE("Order - Remove item from order")
{
    order_data order;

    order = new_order("Alice");

    add_order_item(order, 0, 1.5);
    add_order_item(order, 1, 2.0);

    REQUIRE(order.items.length() == 2);

    remove_order_item(order, 0);

    REQUIRE(order.items.length() == 1);

    REQUIRE(order.items[0].cheese_index == 1);

    REQUIRE(order.items[0].weight == Approx(2.0));
}


TEST_CASE("Order - Ignore invalid remove index")
{
    order_data order;

    order = new_order("Alice");

    add_order_item(order, 0, 1.5);

    remove_order_item(order, -1);

    REQUIRE(order.items.length() == 1);

    remove_order_item(order, 10);

    REQUIRE(order.items.length() == 1);
}


TEST_CASE("Order - Fulfill order reduces stock")
{
    shop_data shop;

    add_cheese(shop, new_cheese("Cheddar", 5.0, 2000));

    order_data order;

    order = new_order("Alice");

    add_order_item(order, 0, 2.0);

    fulfill_order(shop,order);

    REQUIRE(shop.cheeses[0].weight== Approx(3.0));
}


TEST_CASE("Order - Fulfill order cannot create negative stock")
{
    shop_data shop;

    add_cheese(shop, new_cheese( "Cheddar", 1.5, 2000));

    order_data order;

    order = new_order("Alice");

    add_order_item(order, 0, 3.0);

    fulfill_order(shop, order);

    REQUIRE(shop.cheeses[0].weight == Approx(0.0));
}





