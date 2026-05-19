#include "splashkit.h"
#include "utilities.h"

// menu_option enum declaration here
enum menu_option
{
    ENTER_BOOK,
    PRINT_BOOK,
    QUIT
};

// struct book_data declaration here
struct book_data
{
    string title;
    string location;
    int pages;
};

// function prototypes here
book_data read_book(); // read_book() function prototype

void print_book(book_data book); // print_book() function prototype

menu_option read_menu_option(); // read_menu_option() function prototype

// function implementations here

// read_book() function
book_data read_book()
{
    book_data result;

    result.title = read_string("Enter the name of the book: ");
    result.location = read_string("Enter book location: ");
    result.pages = read_integer("Enter number of pages: ");

    return result;
}

// print_book() function
void print_book(book_data book)
{
    write_line();
    write_line("Book details:");
    write_line("Title: " + book.title);
    write_line("Location: " + book.location);
    write_line("Pages: " + to_string(book.pages));
}

// read_menu_option() function
menu_option read_menu_option()
{
    int option;

    write_line();
    write_line("Menu:");
    write_line("1 - Enter book details");
    write_line("2 - Print book");
    write_line("3 - Quit");

    option = read_integer_range("Option: ", 1, 3);

    return (menu_option)(option - 1);
}

// main function here
int main()
{
    book_data book;
    menu_option option;

    write_line("Book entry system:\n");

    book = read_book();

    do
    {
        option = read_menu_option();

        switch (option)
        {
        case ENTER_BOOK:
            write_line();
            book = read_book();
            break;

        case PRINT_BOOK:
            print_book(book);
            break;

        case QUIT:
            write_line("Goodbye");
            break;
        }

    } while (option != QUIT);

    return 0;
}