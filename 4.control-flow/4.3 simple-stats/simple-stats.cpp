#include "splashkit.h"

int main()
{

    double total = 0;
    double average = 0;
    int i = 1;
    string input;
    string answer;


    write_line("Welcome to the simple stats calculator: \n");


    write("Enter Value: ");
    input = read_line();
    while (!is_double(input))
    {
        write_line("Please enter a number");
        write("Enter Value: ");
        input = read_line();
    }

    total += to_double(input);
    average = total / i;
    
    
    write_line("Count: " + to_string(i));
    write_line("Total: " + to_string(total, 1));
    write_line("Average: " + to_string(average, 1));
    write_line();

    
    do
    {
        
        i++;

        write("Add another value: [y/n] ");
        answer = read_line();
        if (answer != "n" and answer != "N" and answer != "no")
        {
            write("Enter Value: ");
            input = read_line();
            while (!is_double(input))
            {
                write_line("Please enter a number");
                write("Enter Value: ");
                input = read_line();
            }
            
            total += to_double(input);
            average = total / i;

            

            write_line("Count: " + to_string(i));
            write_line("Total: " + to_string(total, 1));
            write_line("Average: " + to_string(average, 1));

            write_line();
        }
        else {break;}

        process_events();

    } while (!quit_requested());

    write_line("I hope you got the information you are after! ");

}