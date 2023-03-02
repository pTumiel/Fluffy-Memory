#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>

#define MAP_SIZE 50
#define OCEAN_SIZE 10

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Define the different biomes
    char biomes[] = {'#', '+', '.', ',', '`'};

    // Create the map
    char map[MAP_SIZE][MAP_SIZE];
    for (int x = 0; x < MAP_SIZE; x++) {
        for (int y = 0; y < MAP_SIZE; y++) {
            // Set the default value to ocean
            map[x][y] = '~';
            
            // Check if this position is on land
            if (x >= OCEAN_SIZE && x < MAP_SIZE - OCEAN_SIZE &&
                y >= OCEAN_SIZE && y < MAP_SIZE - OCEAN_SIZE) {
                // Generate a random number to select the biome
                int biome_index = rand() % sizeof(biomes);
                map[x][y] = biomes[biome_index];
            }
        }
    }

    // Set up curses
    initscr();
    noecho();
    curs_set(0);

    // Set the initial position of the player character
    int player_x = MAP_SIZE / 2;
    int player_y = MAP_SIZE / 2;

    // Loop to handle keyboard input and move the player character
    char key;
    while ((key = getch()) != 'q') {
        // Handle arrow keys to move the player character
        switch (key) {
            case KEY_UP:
                if (player_x > 0 && map[player_x-1][player_y] != '~') {
                    player_x--;
                }
                break;
            case KEY_LEFT:
                if (player_y > 0 && map[player_x][player_y-1] != '~') {
                    player_y--;
                }
                break;
            case KEY_DOWN:
                if (player_x < MAP_SIZE-1 && map[player_x+1][player_y] != '~') {
                    player_x++;
                }
                break;
            case KEY_RIGHT:
                if (player_y < MAP_SIZE-1 && map[player_x][player_y+1] != '~') {
                    player_y++;
                }
                break;
            default:
                break;
        }

        // Clear the screen and print the updated map and player position
        clear();
        for (int x = 0; x < MAP_SIZE; x++) {
            for (int y = 0; y < MAP_SIZE; y++) {
                if (x == player_x && y == player_y) {
                    printw("@ ");
                } else {
                    printw("%c ", map[x][y]);
                }
            }
            printw("\n");
        }
        refresh();
    }

    // Clean up curses
    endwin();

    return 0;
}

