#include "splashkit.h"




// print_repeated procedure
void print_repeated(string text, int times, bool with_newline)
{
    int i = 0;
    while (i < times)
    {
        write(text);
        i++;
    }

    if(with_newline)
    {
        write_line("\n");
    }
}


// draw_heading_line procedure
void draw_heading_line(int length)
{
    write("+");
    print_repeated("-", length-2, 0);
    write("+");
}


// draw_title procedure
void draw_title(string text, int length)
{
    draw_heading_line(length);
    write_line();

    write("| "+ text);
    print_repeated(" ", length-4-length_of(text), 0);
    write_line (" |");

    draw_heading_line(length);
    write_line();

}




// read_string function
string read_string(string prompt)
{
    write(prompt);
    return read_line();
}




// read_integer function
int read_integer(string prompt)
{
    string input = read_string(prompt);
    while (!is_integer(input))
    {
        write_line("Please enter a whole number.");
        input = read_string(prompt); 
    }
    return to_integer(input);
}








// read_integer_range function
int read_integer_range(string prompt, int low, int high)
{
    // if low > high， swap
    if (low > high)
    {
        int temp = low;
        low = high;
        high = temp;
    }

    string input = read_string(prompt);

    // first validation：integer
    while (!is_integer(input))
    {
        write_line("Please enter a whole number.");
        input = read_string(prompt);
    }

    int value = to_integer(input);

    // second validation：scope
    while (value < low || value > high)
    {
        write_line("Please enter a value between " + to_string(low) 
                   + " and " + to_string(high) + ".");
        
        input = read_string(prompt);
        while (!is_integer(input))
        {
            write_line("Please enter a whole number.");
            input = read_string(prompt);
        }
        value = to_integer(input);
    }

    return value;
}



// get_main_menu() procedure
void display_main_menu()
    {
        draw_title("Main Menu", 26);
        write_line("1: Update goals\n2: Update behinds\n3: Print details\n4: Quit");
        draw_heading_line(26);
        write_line();   
    }


  




//record_menu procedure
void interact_menu(string name, int& goal, int& behind, int& score)
    {

        int option;
        string quit;
        bool finish = false;

        while(!finish)
        {

            display_main_menu();
        
            option = read_integer_range("Enter Option: ", 1, 4);
            write_line();


            switch (option) 
            {
                case 1:
                    write_line("Current goals: " + to_string(goal));
                    goal = read_integer("Enter new goals: ");

                    score = goal * 6 + behind;
                    write_line("\nCurrent scores: " + to_string(score) + "\n");

                    break;
                case 2:
                    write_line("Current behinds: " + to_string(behind));
                    behind = read_integer("Enter new behinds: ");
                    
                    score = goal * 6 + behind;
                    write_line("\nCurrent scores: " + to_string(score) + "\n");

                    break;
                case 3:
                    write_line(name + ": ");
                    write_line("    " + to_string(goal) + " Goals");
                    write_line("    " + to_string(behind) + " Behinds");
                    write_line("    " + to_string(score) + " Scores");
                    write_line();

                    break;
                case 4:
                    do
                    {
                        quit = read_string("Are you sure you want to quit? [Y/n]? ");

                        if (quit != "y" and quit !="Y" and quit != "n" and quit != "N") 
                        {
                            write_line("Please enter y or n.");
                        }     

                        if (quit == "n" or quit == "N")  
                        {
                            write_line();
                            break;
                        }        

                        if (quit == "y" or quit == "Y")
                        {
                            finish = true;
                            write("\nBye!");
                            break;
                        }
                    }while(quit != "y" and quit != "Y");

                    break;
            }

        }
    }
    




