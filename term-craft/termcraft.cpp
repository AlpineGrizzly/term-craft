/** Termcraft 
 * Starcraft inspired rts game 
 * 
 * Author R3V
 * Created September 30th, 2023
*/

/** Bugs
 * [ ] If anything other than a digit is entered in the menu, infinity loop
*/
#include <iostream>
#include <cstring>
#include <unistd.h> // May not be cross compatible

#include "player.h"
#include "map.h"

#define DEBUG

using namespace std;

/* This just seems like a fancy way of doing a stupid simple define */
enum gamemode { ONE, TWO, EXIT};

/** Structure classes for creating buildings */

/** Unit classes for creating units to fight */
/**
 * draw_menu
 * 
 * Draws start menu where a player will be able to select a gamemode
 * 
 * @return number corresponding to the menu item selected
*/
int draw_menu() { 
    /* Menu Options
     * 1 - 1-Player
     * 2 - 2-Player
     * 3 - Exit
     */
    int menu_item = 0;
    
    while(1) { 
        printf("====================================\n"
               "             TERMCRAFT\n" 
               "====================================\n");
        printf("1. 1-Player\n2. 2-Player\n3. Exit\n");
        
        cin >> menu_item;

        if (!isdigit(menu_item) && menu_item >= 1 && menu_item <= 3)
            break;
        
        menu_item = 0;
        cin.clear();
    }
    return menu_item;
}

/*
 * generate_map
 * 
 * Generates a new map and returns a char array 
 *
 * @return char array of new map generated
 */
char* generate_map(int dim_x, int dim_y) { 
    /* Initializing map pointer */
    char gen_map[dim_x][dim_y];

    for(int i = 0; i < dim_y; i++) {
        for(int j = 0; j < dim_x; j++) { 
            if(i == 0 || j == 0 || i == dim_y - 1 || j == dim_x - 1)
                gen_map[j][i] = '#'; 
            else
                gen_map[j][i] = '.';
        }
    }
    return &gen_map;
}

int main() { 
    /** Init map size */    
    const int map_x = 50;
    const int map_y = 20;

    /* Initialize the map */
    char* new_map = generate_map(map_x, map_y); /* Generate a new map */
    Map map = Map(map_x, map_y, &new_map);

    /* Initialize Player locations on map */
    Player* pl1 = new Player('@', 1,1);
    Player* pl2 = new Player('&', map_x-2, map_y-2);

    /* Main Game loop */
    while(1) { 
        system("clear"); /* Clears screen so its not ugly looking */

        /* Update map with new locations for player 1 and 2 */
        map.draw_map(*pl1, *pl2);

        /* Temporary, this will eventually be replaced by listening to arrow key commands */
#ifdef DEBUG
        printf("Curr Loc: (%d, %d)\n", pl1->get_pos()->get_x(), pl1->get_pos()->get_y());
#endif
        /* Get input from user on next action */
        map.get_move(pl1);
    }
    free(pl1);
    free(pl2);
}