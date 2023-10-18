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

int main() { 
    //enum gamemode mode;
    /* Declare necessary game objects */

    /** Init map size */
    // TODO will allow this to be modifiable at the menu screen
    int map_x = 50;
    int map_y = 20;

    Map map = Map(map_x, map_y); /* Arbitrary initialization dims */

    /* Initialize player 1 */
    Player* pl1 = new Player('@', 1,1);
    Player* pl2 = new Player('&', map_x-2, map_y-2);

    int new_x;
    int new_y;

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
}