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

using namespace std;

/* This just seems like a fancy way of doing a stupid simple define */
enum gamemode { ONE=0, TWO=1, EXIT=2};

/* Keypress hex sequence values (WASD)
 * Reading hex values from arrow keys is a bitch, there's like 3 of them 
 */
#define KEY_0 0x31
#define KEY_1 0x32
#define KEY_2 0x33

#define KEY_W 0x77
#define KEY_A 0x61
#define KEY_S 0x73
#define KEY_D 0x64
//#define KEY_UP    0x1b 0x5b 0x41
//#define KEY_DOWN  0x1b 0x5b 0x42
//#define KEY_LEFT  0x1B 0x5B 0x44
//#define KEY_RIGHT 0x1Bx5B 0x43 0

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

    Map field = Map(map_x, map_y); /* Arbitrary initialization dims */

    /* Initialize player 1 */
    Player pl1('@', 1,1);
    Player pl2('&', map_x-2, map_y-2);

    int new_x;
    int new_y;

    /* Main Game loop */
    while(1) { 
        /* Draw the map for the player to see */
        field.draw_map(pl1, pl2);

        /* Get input from user on next action */
        // TODO allow these to be comma seperated and retrieve a line at a time
        cout << "x: "; cin >> new_x;
        cout << endl << "y: "; cin >> new_y;    
        cout << endl;

        /* Update player's position */
        /* TODO Validate input from user */
        pl1.set_x(new_x);
        pl1.set_y(new_y);
    }
}