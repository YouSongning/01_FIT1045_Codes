#include "splashkit.h"
#include "utilities.h"

void input_grades(int grades[], int &size)
{
    size = read_integer_range("How many grades (1 - 20): ", 1, 20);

    for(int i = 0; i < size; i++)
    {
        grades[i] = read_integer("Enter grade " + to_string(i + 1) + ": ");
    }
}


double calculate_average(int grades[], int size)
{
    int total = 0;

    for(int i = 0; i < size; i++)
    {
        total += grades[i];
    }

    return (double)total / size;
}


double calculate_pass_rate(int grades[], int size)
{
    int pass_count = 0;

    for(int i = 0; i < size; i++)
    {
        if(grades[i] >= 50)
        {
            pass_count++;
        }
    }

    return ((double)pass_count / size) * 100;
}


int count_hd(int grades[], int size)
{
    int hd_count = 0;

    for(int i = 0; i < size; i++)
    {
        if(grades[i] >= 80)
        {
            hd_count++;
        }
    }

    return hd_count;
}


void display_results(double average, double pass_rate, int hd_count)
{
    write_line("\nResults");
    write_line("Average Grade: " + to_string(average, 2));
    write_line("Pass Rate: " + to_string(pass_rate, 2) + "%");
    write_line("HD Count: " + to_string(hd_count));
}


int main()
{
    int grades[20];
    int size;

    double average;
    double pass_rate;
    int hd_count;

    input_grades(grades, size);

    average = calculate_average(grades, size);
    pass_rate = calculate_pass_rate(grades, size);
    hd_count = count_hd(grades, size);

    display_results(average, pass_rate, hd_count);

    return 0;
}