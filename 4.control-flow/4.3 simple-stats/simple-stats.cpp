#include "splashkit.h"

int main()
{

    double total = 0;
    double average = 0;
    int i = 0;
    string input;
    string answer;


    write_line("Welcome to the simple stats calculator: \n");

    do
    {
        write("Enter Value: ");
        input = read_line();
        while (!is_double(input))
        {
            write_line("Please enter a number");
            write("Enter Value: ");
            input = read_line();
        }

        i++;
        total += to_double(input);  
        average = total / i;

        write_line("Count: " + to_string(i));
        write_line("Total: " + to_string(total, 1));
        write_line("Average: " + to_string(average, 1));
        write_line();


        write("Add another value: [y/n] ");
        answer = read_line();


    } while (answer != "n" && answer != "N" && answer != "no");

    write_line("I hope you got the information you are after! ");

}