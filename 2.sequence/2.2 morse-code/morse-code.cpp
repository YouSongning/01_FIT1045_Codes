#include "splashkit.h"

int main()
{
    load_sound_effect("dit", "morse_dit.ogg");
    load_sound_effect("dah", "morse_dah.ogg");

    // Begin 'C' (- . - .)
    play_sound_effect("dah"); delay(300);
    delay(100); // 声音之间的停顿
    play_sound_effect("dit"); delay(100); 
    delay(100);
    play_sound_effect("dah"); delay(300);
    delay(100);
    play_sound_effect("dit"); delay(100);

    //Stop between characters
    delay(300); 

    // Begin 'A' (. -)
    play_sound_effect("dit"); delay(100);
    delay(100);
    play_sound_effect("dah"); delay(300);

    //Stop between characters
    delay(300);

    // Begin T (-)
    play_sound_effect("dah"); delay(300);

    //Over
    delay(2000);
    return 0;
}