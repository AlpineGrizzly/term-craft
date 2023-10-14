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

#define STDIN_FILENO 0
#define K_UP    65
#define K_DOWN  66
#define K_RIGHT 67
#define K_LEFT  68

using namespace std;

void Map::draw_map(Player pl1, Player pl2) {
    /* Get current location of players */
    Pos* loc1 = pl1.get_pos(); 
    Pos* loc2 = pl2.get_pos();

    for(int i = 0; i < this->dim_y; i++) {
        for(int j = 0; j < this->dim_x; j++) { 
            /* Draw the players (Currently hardcoded for two players )*/
            if (j == loc1->get_x() && i == loc1->get_y()) { 
                printf("%c ", pl1.get_cursor());
                continue;
            }

            if (j == loc2->get_x() && i == loc2->get_y()) { 
                printf("%c ", pl2.get_cursor());
                continue;
            }

            /* Draw structures */
            /* Draw the map */
            if(i == 0 || j == 0 || i == this->dim_y - 1 || j == this->dim_x - 1) /* Draw edges */
                printf("# ");
            else
                printf(". ");
        }
        putc('\n', stdout);
    }
    printf("\n\n");
}


/** 
 * getch
 * 
 * Get a character input from the user and update their location on the field if it was valid
*/
static void getch(Player* pl) { 
    // Black magic to prevent Linux from buffering keystrokes.
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
    
    /** Get current x and y possitions of player */
    int curr_x = pl->get_pos()->get_x();
    int curr_y = pl->get_pos()->get_y();

// Once the buffering is turned off, the rest is simple.
    char c,d,e;
    cin >> c;
    cin >> d;
    cin >> e;
// Using 3 char type, Cause up down right left consist with 3 character
    if ((c==27)&&(d==91)) {
        if (e==K_UP)    {pl->move_cursor(Pos(curr_x, curr_y-1));}
        if (e==K_DOWN)  {pl->move_cursor(Pos(curr_x, curr_y + 1));}
        if (e==K_RIGHT) {pl->move_cursor(Pos(curr_x + 1, curr_y));}
        if (e==K_LEFT)  {pl->move_cursor(Pos(curr_x-1, curr_y));}
    }
}

#include <unistd.h>
/* 
 * get_move
 * 
 * Gets and valids a cursor move of the player 
 * 
 * @param pl1 Instance of player one, used to update cursor location if move is valid
 */
void Map::get_move(Player* pl1) { 
    /* Check if the player press an arrow key to move the cursor */
    getch(pl1);
    /* validate and make the move if it was so */
}