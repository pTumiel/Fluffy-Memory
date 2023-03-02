#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    // Print the map
    for (int x = 0; x < MAP_SIZE; x++) {
        for (int y = 0; y < MAP_SIZE; y++) {
            printf("%c ", map[x][y]);
        }
        printf("\n");
    }

    return 0;
}

