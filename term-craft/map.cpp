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

using namespace std;

void Map::draw_map(Player* pls[]) {
    /* Get current location of players */
    // Hardcoded for two players
    Player* pl1 = pls[0];
    Player* pl2 = pls[1];

    /* Player locations */
    Pos* loc1 = pl1->get_pos(); 
    Pos* loc2 = pl2->get_pos();

    /* Base locations */
    Pos* base1 = pl1->get_base()->get_pos();
    Pos* base2 = pl2->get_base()->get_pos();
    
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

            /* Draw Bases */
            if (j == base1->get_x() && i ==base1->get_y()) { 
                printf("%c ", pl1->get_base()->get_icon());
                continue;
            }
            if (j == base2->get_x() && i ==base2->get_y()) { 
                printf("%c ", pl2->get_base()->get_icon());
                continue;
            }

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
    if (c == 'd') { /* Test to see how I can intercept single non-arrow key presses */ 
        cout << "GOT D" << endl;
        sleep(1);
        return 0;
    }
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
    char e = getch(pl);
    int new_x, new_y; /* values of new x and y position */

    if (!e) 
        return (void)"No arrow press";

    /** Get current x and y possitions of player */
    int curr_x = pl->get_pos()->get_x();
    int curr_y = pl->get_pos()->get_y();
    
    /* validate and make the move if it was so */
    switch(e) { 
        case K_UP:     
            new_x = curr_x;
            new_y = curr_y-1;
            //pl->move_cursor(Pos(curr_x, curr_y-1));
            break;
        case K_DOWN:  
            new_x = curr_x;
            new_y = curr_y+1;
            //pl->move_cursor(Pos(curr_x, curr_y + 1));
            break;
        case K_RIGHT: 
            new_x = curr_x+1;
            new_y = curr_y;
            //pl->move_cursor(Pos(curr_x + 1, curr_y));
            break;
        case K_LEFT: 
            new_x = curr_x-1;
            new_y = curr_y;
            //pl->move_cursor(Pos(curr_x-1, curr_y));
            break;
    }
    /* Validate the new position */
    /** Screen wrap if player moves outside of bounds */ 
    // ((x % range) + range) % range
    int wrap_x = ((new_x % this->dim_x) + this->dim_x) % this->dim_x;
    int wrap_y = ((new_y % this->dim_y) + this->dim_y) % this->dim_y;
    pl->move_cursor(Pos(wrap_x, wrap_y));
    //if (new_x > 0 && new_x < this->dim_x-1) {  
    //    if(new_y > 0 && new_y < this->dim_y-1)
    //        pl->move_cursor(Pos(new_x, new_y));
    //}else{
    //    pl->move_cursor(Pos(new_x % this->dim_x, new_y));
    //}
}
