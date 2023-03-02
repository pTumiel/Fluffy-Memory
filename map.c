#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the game world
#define WORLD_WIDTH 20
#define WORLD_HEIGHT 10

// Define the player character
struct Player {
    int x, y; // Player position
};

// Define the game world
char world[WORLD_HEIGHT][WORLD_WIDTH];

// Initialize the game world
void initWorld() {
    srand(time(NULL)); // Seed the random number generator
    
    // Generate random walls and floors
    for (int y = 0; y < WORLD_HEIGHT; y++) {
        for (int x = 0; x < WORLD_WIDTH; x++) {
            if (rand() % 100 < 30) {
                world[y][x] = '#'; // Wall
            } else {
                world[y][x] = '.'; // Floor
            }
        }
    }
}

// Render the game world to the terminal
void renderWorld(struct Player player) {
    system("clear"); // Clear the terminal
    
    // Render the game world
    for (int y = 0; y < WORLD_HEIGHT; y++) {
        for (int x = 0; x < WORLD_WIDTH; x++) {
            if (x == player.x && y == player.y) {
                printf("@"); // Render the player character
            } else {
                printf("%c", world[y][x]); // Render the game world tile
            }
        }
        printf("\n");
    }
}

// Handle keyboard input
void handleInput(struct Player* player) {
    char input = getchar();
    
    switch (input) {
        case 'w': // Move up
            if (player->y > 0) {
                player->y--;
            }
            break;
        case 'a': // Move left
            if (player->x > 0) {
                player->x--;
            }
            break;
        case 's': // Move down
            if (player->y < WORLD_HEIGHT - 1) {
                player->y++;
            }
            break;
        case 'd': // Move right
            if (player->x < WORLD_WIDTH - 1) {
                player->x++;
            }
            break;
    }
}

// Main game loop
int main() {
    struct Player player = {WORLD_WIDTH / 2, WORLD_HEIGHT / 2}; // Initialize the player character
    initWorld(); // Initialize the game world
    
    // Game loop
    while (1) {
        renderWorld(player); // Render the game world
        handleInput(&player); // Handle keyboard input
    }
    
    return 0;
}

