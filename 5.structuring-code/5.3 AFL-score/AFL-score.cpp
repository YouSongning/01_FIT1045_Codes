#include "splashkit.h"
#include "AFL-score.h"

int main()
{
    string name;
    int goal;
    int behind;
    int score;
    
    draw_title("Score Calculator", 26);
    write_line();

    write_line("Welcome to the AFL score calculator!\n");

    name = read_string("Enter team name: ");
    goal = read_integer("Enter goals: ");
    behind = read_integer("Enter behinds: ");
    write_line();

    score = goal * 6 + behind;
    write_line("current Score: " + to_string(score) + "\n");


    interact_menu(name, goal, behind, score);

}
