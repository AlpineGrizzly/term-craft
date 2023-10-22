/**
 * map.cpp
 * 
 * Function implementations of map class
 *
 * Author R3V
 * Created October 1st, 2023
*/

#include <iostream>
#include <termio.h>
#include "map.h"
#include <unistd.h>

#define STDIN_FILENO 0

/** Movement keys */
#define K_UP    65
#define K_DOWN  66
#define K_RIGHT 67
#define K_LEFT  68

/** Construction keys */
#define BUILD_WALL 'w'

using namespace std;

void Map::draw_map(Player* pls[]) {
    /* Get current location of players */
    // Hardcoded for two players
    Player* pl1 = pls[0];
    Player* pl2 = pls[1];

    /* Player locations */
    Pos* loc1 = pl1->get_pos(); 
    Pos* loc2 = pl2->get_pos();
    
    for(int i = 0; i < this->dim_y; i++) {
        for(int j = 0; j < this->dim_x; j++) { 
            /* Draw the players (Currently hardcoded for two players )*/
            if (j == loc1->get_x() && i == loc1->get_y()) { 
                printf("%c ", pl1->get_cursor());
                continue;
            }

            if (j == loc2->get_x() && i == loc2->get_y()) { 
                printf("%c ", pl2->get_cursor());
                continue;
            }

            /* Draw structures */
            /** Haven't decided if this is good or not; Definitely think having a char array 
             * for the map would be more efficient than looking up a list of objects everytime
            */
            int t = 0; 
            for(int k =0; k < pl1->get_owned_structs(); k++) {  
                if(j == pl1->get_structure(k)->get_pos()->get_x() && i ==  pl1->get_structure(k)->get_pos()->get_y()) { 
                    printf("%c ", pl1->get_structure(k)->get_icon());
                    t = 1;
                    break;
                }
            }
            
            if (t) continue;

            for(int k =0; k < pl2->get_owned_structs(); k++) {  
                if(j == pl2->get_structure(k)->get_pos()->get_x() && i ==  pl2->get_structure(k)->get_pos()->get_y()) { 
                    printf("%c ", pl2->get_structure(k)->get_icon());
                    t = 1;
                    break;
                }
            }

            if (t) continue; // this sucks

            /* Draw the map */
            if(i == 0 || j == 0 || i == this->dim_y - 1 || j == this->dim_x - 1) /* Draw edges */
                printf("# ");
            else
                printf("  ");
        }
        putc('\n', stdout);
    }
    printf("\n\n");
}

int Map::get_x_dim() { 
    return this->dim_x;
}
int Map::get_y_dim() { 
    return this->dim_y;
}

/** 
 * getch
 * 
 * Get a character input from the user and update their location on the field if it was valid
*/
static char getch(Player* pl) { 
    // Black magic to prevent Linux from buffering keystrokes.
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);

    // Once the buffering is turned off, the rest is simple.
    char c,d,e;
    cin >> c;    
    if (c == BUILD_WALL) return c;
    cin >> d;
    cin >> e;
    
    /** Resolving arrow key inputs for cursor movement */
    if ((c==27)&&(d==91))
        return e;
    return 0;
}

/* 
 * get_move
 * 
 * Gets and valids a cursor move of the player 
 * 
 * @param pl1 Instance of player one, used to update cursor location if move is valid
 */
void Map::get_move(Player* pl) { 
    /* Check if the player press an arrow key to move the cursor */
    char p = getch(pl);
    int new_x, new_y; /* values of new x and y position */

    if (!p) return (void)"No key press";

    /** Check for non-cursor movement keys */
    if (p == BUILD_WALL) { 
        pl->create_structure(BUILD_WALL);
        return;
    }

    /** Get current x and y possitions of player */
    int curr_x = pl->get_pos()->get_x();
    int curr_y = pl->get_pos()->get_y();
    
    /* Validate and make the move if it was so */
    switch(p) { 
        case K_UP:     
            new_x = curr_x;
            new_y = curr_y-1;
            break;
        case K_DOWN:  
            new_x = curr_x;
            new_y = curr_y+1;
            break;
        case K_RIGHT: 
            new_x = curr_x+1;
            new_y = curr_y;
            break;
        case K_LEFT: 
            new_x = curr_x-1;
            new_y = curr_y;
            break;
    }
    /* Validate the new position */
    /** Screen wrap if player moves outside of bounds */ 
    /* Formula for wrapping : ((x % range) + range) % range */
    int wrap_x = ((new_x % this->dim_x) + this->dim_x) % this->dim_x;
    int wrap_y = ((new_y % this->dim_y) + this->dim_y) % this->dim_y;
    pl->move_cursor(Pos(wrap_x, wrap_y));
}
