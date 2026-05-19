#include "splashkit.h"
#include "utilities.h"

class account
{
    /**
     * The balance of the account in cents.
     */
    int balance;

    public:
        /**
         * The name of the account holder.
         */
        string name;

    account(string name_, int balance_)
    {
        // Initialises the account
        // We've added _ to the end of the parameters, to differentiate them from the class fields
        name = name_;
        balance = balance_;
    }

    account()
    {
        // A default constructor lets you initialise the value when no parameters are passed
        name = "Account Holder Unknown";
        balance = 0;
    }

    void print()
        {
            write_line(name + ": $" + to_string(balance / 100.0));
        }
};

int main()
{
    // Create 5 accounts objects on the stack
    account a1("Atabak", 100);
    account a2("Sheena", 734231);
    account a3("Azadeh", 90210);
    account a4("Jo", -1000);
    account a5;

    // Print the accounts
    a1.print();
    a2.print();
    a3.print();
    a4.print();
    a5.print();

    return 0;
}