#include "splashkit.h"

const int MINUTES_PER_HOUR = 60;

int main()
{
    string name, user_input;
    double distance, time;
    double speed;
    double remaining_distance, time_to_destination;
    double total_distance, total_time;

    write("What is your name: ");
    name = read_line();

    write_line();
    write_line("Hi " + name + ".");
    write_line();

    write("How far have you travelled so far? Enter km: ");
    user_input = read_line();
    distance = to_double(user_input);

    write("How long has it taken? Enter minutes: ");
    user_input = read_line();
    time = to_double(user_input);

    speed = distance / (time / MINUTES_PER_HOUR);

    write_line();
    write_line("Your average speed is " + to_string(speed, 14) + "  km/h");
    write_line();

    write("How far do you have to go? Enter km: ");
    user_input = read_line();
    remaining_distance = to_double(user_input);

    time_to_destination = remaining_distance / speed * MINUTES_PER_HOUR;

    write_line("You will take another " + to_string(time_to_destination) + " minutes before you arrive");
    
    total_distance = distance + remaining_distance;
    total_time = time + time_to_destination;

    write_line("Total distance will be " + to_string(total_distance) + " km");
    write_line("Total time will be " + to_string(total_time) + " minutes");

}