/** player.h
 * 
 * Contains class and function declarations for the player class 
 * 
 * Author R3V
 * Created October 1st, 2023
*/

#pragma once
#include "pos.h"

class Player { 
    private:
        Pos* pos; /* Position of Player on field */
        char cursor; /* Symbol that represents the player on the map */
    public:
        Player(char cursor, int start_x, int start_y) { /* Constructor for players cursor and start location */
            this->cursor = cursor;
            this->pos = new Pos(start_x, start_y); 
        }
        void set_pos(Pos new_pos);
        Pos* get_pos();
        char get_cursor();
        void move_cursor(Pos new_pos);
        /** TODO  V*/
        int create_structure();
        int create_unit();
};