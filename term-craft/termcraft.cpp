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
#include "map.h"

#define DEBUG

using namespace std;

/* This just seems like a fancy way of doing a stupid simple define */
enum gamemode { ONE, TWO, EXIT};

/** Structure classes for creating buildings */

void draw_logo() { 
    printf("\t\t\t\t▄▄▄█████▓▓█████  ██▀███   ███▄ ▄███▓ ▄████▄   ██▀███   ▄▄▄        █████▒▄▄▄█████▓    ▄▄▄▄ ▓██   ██▓    ██▀███  ▓█████ ██▒   █▓\n"
           "\t\t\t\t▓  ██▒ ▓▒▓█   ▀ ▓██ ▒ ██▒▓██▒▀█▀ ██▒▒██▀ ▀█  ▓██ ▒ ██▒▒████▄    ▓██   ▒ ▓  ██▒ ▓▒   ▓█████▄▒██  ██▒   ▓██ ▒ ██▒▓█   ▀▓██░   █▒\n"
           "\t\t\t\t▒ ▓██░ ▒░▒███   ▓██ ░▄█ ▒▓██    ▓██░▒▓█    ▄ ▓██ ░▄█ ▒▒██  ▀█▄  ▒████ ░ ▒ ▓██░ ▒░   ▒██▒ ▄██▒██ ██░   ▓██ ░▄█ ▒▒███   ▓██  █▒░\n"
           "\t\t\t\t░ ▓██▓ ░ ▒▓█  ▄ ▒██▀▀█▄  ▒██    ▒██ ▒▓▓▄ ▄██▒▒██▀▀█▄  ░██▄▄▄▄██ ░▓█▒  ░ ░ ▓██▓ ░    ▒██░█▀  ░ ▐██▓░   ▒██▀▀█▄  ▒▓█  ▄  ▒██ █░░\n"
           "\t\t\t\t  ▒██▒ ░ ░▒████▒░██▓ ▒██▒▒██▒   ░██▒▒ ▓███▀ ░░██▓ ▒██▒ ▓█   ▓██▒░▒█░      ▒██▒ ░    ░▓█  ▀█▓░ ██▒▓░   ░██▓ ▒██▒░▒████▒  ▒▀█░  \n"
           "\t\t\t\t  ▒ ░░   ░░ ▒░ ░░ ▒▓ ░▒▓░░ ▒░   ░  ░░ ░▒ ▒  ░░ ▒▓ ░▒▓░ ▒▒   ▓▒█░ ▒ ░      ▒ ░░      ░▒▓███▀▒ ██▒▒▒    ░ ▒▓ ░▒▓░░░ ▒░ ░  ░ ▐░  \n"
           "\t\t\t\t    ░     ░ ░  ░  ░▒ ░ ▒░░  ░      ░  ░  ▒     ░▒ ░ ▒░  ▒   ▒▒ ░ ░          ░       ▒░▒   ░▓██ ░▒░      ░▒ ░ ▒░ ░ ░  ░  ░ ░░  \n"
           "\t\t\t\t  ░         ░     ░░   ░ ░      ░   ░          ░░   ░   ░   ▒    ░ ░      ░          ░    ░▒ ▒ ░░       ░░   ░    ░       ░░  \n"
           "\t\t\t\t            ░  ░   ░            ░   ░ ░         ░           ░  ░                     ░     ░ ░           ░        ░  ░     ░  \n"
           "\t\t\t\t                                    ░                                                     ░░ ░                            ░   \n"
    );
}

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
        draw_logo();
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
    /** Init map size */    
    const int map_x = 50;
    const int map_y = 20;
    int test = 0;

    /* Initialize the map */
    Map map = Map(map_x, map_y);

    /* Initialize Player locations on map */
    Player* pl1 = new Player('@', 1,1);
    Player* pl2 = new Player('&', map_x-2, map_y-2);

    /* Array of pointers to our player objects */
    Player *pls[] = {pl1, pl2};

    /* Main Game loop */
    while(1) { 
        system("clear"); /* Clears screen so its not ugly looking */
        draw_logo();
        
        /* Update map with new locations for player 1 and 2 */
        map.draw_map(pls);
        test++;
#ifdef DEBUG
        printf("Curr Loc: (%d, %d)\n", pl1->get_pos()->get_x(), pl1->get_pos()->get_y());
        printf("Health: %d\nDrones: %d\nStructures: %d\nResourecs: %d\n", 
                pl1->get_base()->get_health(), 
                pl1->get_base()->get_num_drones(),
                pl1->get_owned_structs(),
                test);
#endif
        /* Get input from user on next action */
        map.get_move(pl1);
    }
    delete pl1, pl2; /* Stop the leaks! */
}