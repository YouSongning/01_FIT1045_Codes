#include "splashkit.h"
#include "utilities.h"

// Declare struct here
struct unit_result
{
    string unit_code;
    string unit_name;
    int score;
};

// Declare other functions and procedures here

unit_result read_unit_result()
{
    unit_result result;

    result.unit_code = read_string("Enter unit code: ");
    result.unit_name = read_string("Enter unit name: ");
    result.score = read_integer("Enter your score: ");

    return result;
}

void write_unit_result(unit_result result)
{
    write(result.unit_code + ", " + result.unit_name + ", " + to_string(result.score));

    if (result.score >= 80)
    {
      write_line(" congratulations");
    }
    else
    {
      write_line();
    }
}



int main()
{
  // Create a local variable for your result here...
  unit_result result;

  // We can then read in a value
  result = read_unit_result();  

  // And output it to the terminal
  write_unit_result(result);

  return 0;
}