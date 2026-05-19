#include "splashkit.h"
#include "utilities.h"

// add enumeration here called 'day'

enum day
{
    SUNDAY, 
    MONDAY, 
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

// add a constant NUM_DAYS to capture number of days in a week

const int NUM_DAYS = (int)SATURDAY + 1;

// add to_string here
/** 
 * Converts the given day enum value to a string representation.
 * 
 * @param d The day enum value to convert.
 * @return The string representation of the day. 
 */ 

string to_string (day d) 
{
    switch (d)
    {
        case SUNDAY : 
            return "Sunday";    
        case MONDAY : 
            return "Monday"; 
        case TUESDAY : 
            return "Tuesday"; 
        case WEDNESDAY : 
            return "Wednesday"; 
        case THURSDAY : 
            return "Thursday"; 
        case FRIDAY : 
            return "Friday"; 
        case SATURDAY : 
            return "Saturday"; 
        default: 
            return "Invalid day";
    }
}

// add read day here
/** Reads a day from the user. 
 *
 * @return The day entered by the user. 
 */ 

day read_day (string prompt) 
{ 
    int day_number; 
    write_line (prompt) ;

    // Output the list of day options 
    for (int i = 0; i < NUM_DAYS; i++) 
    {
        day current_day = (day) i; 
        write_line (to_string (i + 1) + ": " + to_string (current_day)); 
    } 
    
    // Read day as a number 1 to 7 
    // Subtract 1 so that it is 0 to 6 
    // Use read integer with range if you have it! 
    day_number = read_integer_range ("Enter a day number (1-7): ", 1, 7) - 1; 
    return (day)day_number;
}


int main()
{
    // Enum variable declaration
    day today;

    // Assigning a value to the enum variable
    today = read_day("What day is it today? ");

    // Print the value of today
    write_line("Today is " + to_string(today));

    return 0;
}


