#include "splashkit.h"
#include "utilities.h"

int main()
{
    string name;
    int goal, behind, score;
    
    draw_title("Score Calculator", 26);
    write_line("\nWelcome to the AFL score calculator!\n");

    name = read_string("Enter team name: ");
    goal = read_integer("Enter goals: ");
    behind = read_integer("Enter behinds: ");
    score = goal * 6 + behind;
    
    write_line("\ncurrent Score: " + to_string(score) + "\n");

    interact_menu(name, goal, behind, score);
    
    return 0;
}
