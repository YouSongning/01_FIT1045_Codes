#include "splashkit.h"

int main()
{
    string user_input, path, name;
    int time;
    double percent_initial, percent_repeat;


//collect inputs
    write_line("Welcome to the music play test");

    write_line();

    write("What file would you like to load? Enter path: ");
    user_input = read_line();
    path = user_input;

    write("What should I call this music? Enter name: ");
    user_input = read_line();
    name = user_input;

    write_line();

    write_line("Loading " + name + " music from " + path);

    write_line();

    write("How long do you want to play it for? Enter seconds: ");
    user_input = read_line();
    time = to_integer(user_input);

    write("At what initial volumn? Enter percent (0-1): ");
    user_input = read_line();
    percent_initial = to_double(user_input);

    write("At what repeat volumn? Enter percent (0-1): ");
    user_input = read_line();
    percent_repeat = to_double(user_input);

    write_line();


// play music first time
    write_line("Playing " + name + " at " + to_string(percent_initial, 2) + " volumn for " + to_string(time, 0) + " seconds...");

    load_sound_effect(name, path);
    play_sound_effect(name, percent_initial);
    delay(time*1000);

    write_line("Stopping music");

    write_line();

//play music second time
    write_line("Playing " + name + " at " + to_string(percent_repeat, 2) + " volumn for " + to_string(time, 0) + " seconds...");

    play_sound_effect(name, percent_repeat);
    delay(time*1000);

    write_line("Stopping music");
    

}