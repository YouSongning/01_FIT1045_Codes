#include "splashkit.h"
#include "splashkit-arrays.h"
#include "utilities.h"

// Structs:
struct song_data
{
    string name;
    string id;
    string path;
    bool loved;
    int times_played;
};

struct music_player_data
{
    dynamic_array<song_data> songs;
    int next_id;
    bool paused;
};

// Functions:
// read_song()function here
/**
 * Read song details from the user
 *
 * @param player the music player data
 * @return the completed song record
 */
song_data read_song(music_player_data &player)
{
    song_data result;

    result.name = read_string("Enter song name: ");
    result.path = read_string("Enter song path: ");

    result.loved = read_boolean("Is this a loved song? (y/n): ");

    result.times_played = 0;

    // Generate unique id
    result.id = "song-" + to_string(player.next_id);

    // Move to next id
    player.next_id++;

    return result;
}

// print_song() function here
/**
 * Print details of a song
 *
 * @param song the song to print
 */
void print_song(const song_data &song)
{
    write_line("Name: " + song.name);
    write_line("ID: " + song.id);
    write_line("Path: " + song.path);

    if (song.loved)
    {
        write_line("Loved: Yes");
    }
    else
    {
        write_line("Loved: No");
    }

    write_line("Times Played: " + to_string(song.times_played));
}

// add_song() function here
/**
 * Add a song to the music player
 *
 * @param player the music player
 */
void add_song(music_player_data &player)
{
    song_data song;

    song = read_song(player);

    add(player.songs, song);

    load_music(song.id, song.path);

    write_line("Song added successfully.");
}

// print_all_songs() function here
/**
 * Print all songs in the music player
 *
 * @param player the music player
 */
void print_all_songs(const music_player_data &player)
{
    for (int i = 0; i < length(player.songs); i++)
    {
        write_line("\nSong #" + to_string(i));

        print_song(player.songs[i]);
    }
}

// print_matching_songs() function here
/**
 * Print songs that match the search text
 *
 * @param player the music player
 * @param search_text the text to search for
 * @return number of matching songs
 */
int print_matching_songs(const music_player_data &player, string search_text)
{
    int matches = 0;

    for (int i = 0; i < length(player.songs); i++)
    {
        if (contains(player.songs[i].name, search_text))
        {
            write_line(
                to_string(i) + ". " +
                player.songs[i].name);

            matches++;
        }
    }

    return matches;
}

// select_song() function here
/**
 * Select a song from the music player
 *
 * @param player the music player
 * @return the selected index, or -1 if not found
 */
int select_song(const music_player_data &player)
{
    string search_text;
    int index;
    int matches;

    search_text = read_string("Enter search text: ");

    matches = print_matching_songs(player, search_text);

    if (matches == 0)
    {
        write_line("No matching songs found.");
        return -1;
    }

    index = read_integer("Enter song index: ");

    if (index >= 0 && index < length(player.songs))
    {
        return index;
    }

    write_line("Invalid song index.");

    return -1;
}

// print_update_menu() procedure here
/**
 * Print the update song menu
 */
void print_update_menu()
{
    write_line("\nUpdate Song Menu");
    write_line("1. Update name");
    write_line("2. Toggle loved");
    write_line("3. Reset times played");
    write_line("4. Delete");
    write_line("5. Quit update");
}

// update_song() function here
/**
 * Update a selected song
 *
 * @param player the music player
 */
void update_song(music_player_data &player)
{
    int index;

    index = select_song(player);

    if (index < 0)
    {
        return;
    }

    int option;

    do
    {
        write_line("\nSelected Song:\n");

        print_song(player.songs[index]);

        print_update_menu();

        option = read_integer_range(
            "Enter option: ",
            1,
            5);

        switch (option)
        {
        case 1:
            player.songs[index].name =
                read_string("Enter new name: ");
            break;

        case 2:
            player.songs[index].loved =
                !player.songs[index].loved;
            break;

        case 3:
            player.songs[index].times_played = 0;
            break;

        case 4:
            remove_at(player.songs, index);

            write_line("Song deleted.");

            return;
        }

    } while (option != 5);
}

// play_song() function here
/**
 * Play a selected song
 *
 * @param player the music player
 */
void play_song(music_player_data &player)
{
    int index;

    index = select_song(player);

    if (index >= 0)
    {
        play_music(player.songs[index].id);

        player.songs[index].times_played++;

        write_line("Now playing: " + player.songs[index].name);
    }
}

// pause_resume_song() function here
/**
 * Pause or resume the current song
 *
 * @param player the music player
 */
void pause_resume_song(music_player_data &player)
{
    if (player.paused)
    {
        resume_music();

        player.paused = false;

        write_line("Music resumed.");
    }
    else
    {
        pause_music();

        player.paused = true;

        write_line("Music paused.");
    }
}

// print_status() function here
/**
 * Print the status of the music player
 *
 * @param player the music player
 */
void print_status(const music_player_data &player)
{
    int total_played = 0;
    int total_loved = 0;

    for (int i = 0; i < length(player.songs); i++)
    {
        total_played += player.songs[i].times_played;

        if (player.songs[i].loved)
        {
            total_loved++;
        }
    }

    write_line("\nMusic Player Status");
    write_line(
        "Number of songs: " + to_string(length(player.songs)));

    write_line(
        "Total number of songs played: " + to_string(total_played));

    write_line(
        "Total number of loved songs: " + to_string(total_loved));
}

// print_menu() procedure here
void print_menu()
{
    write_line("\nMusic Player Menu");
    write_line("1. Add Song");
    write_line("2. Update Song");
    write_line("3. Play Song");
    write_line("4. Pause / Resume");
    write_line("5. Print Status");
    write_line("6. Print All Songs");
    write_line("7. Quit");
}

int main()
{
    music_player_data player;

    player.next_id = 0;
    player.paused = false;

    int option;

    print_menu();

    option = read_integer_range(
        "Enter option: ",
        1,
        7);

    while (option != 7)
    {
        switch (option)
        {
        case 1:
            add_song(player);
            break;

        case 2:
            update_song(player);
            break;

        case 3:
            play_song(player);
            break;

        case 4:
            pause_resume_song(player);
            break;

        case 5:
            print_status(player);
            break;

        case 6:
            print_all_songs(player);
            break;
        }

        write_line();
        read_string("Press ENTER to continue...");

        print_menu();

        option = read_integer_range("Enter option: ", 1, 7);
    }

    write_line("Goodbye!");

    return 0;
}
