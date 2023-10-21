/** player.h
 * 
 * Contains class and function declarations for the player class 
 * 
 * Author R3V
 * Created October 1st, 2023
*/

#pragma once
#include "structure.h"
#define DEBUG

class Player { 
    private:
        Pos* pos;    /* Position of Player on field */
        char cursor; /* Symbol that represents the player on the map */
        Base* base;   /* pointer to Player's base object */
    public:
        Player(char cursor, int start_x, int start_y) { /* Constructor for players cursor and start location */
            this->cursor = cursor;
            this->pos = new Pos(start_x, start_y);
            this->base = new Base(cursor, 
                                  100, 
                                  5, 
                                  this->get_pos()->get_x(), 
                                  this->get_pos()->get_y()); 
        }
        void set_pos(Pos new_pos);
        Pos* get_pos();
        char get_cursor();
        void move_cursor(Pos new_pos);
        /** TODO  V*/
#ifdef DEBUG
        int get_base_health() { 
            return this->base->get_health();
        }
        int get_num_drones() { 
            return this->base->get_num_drones();
        }
#endif
        int create_structure();
        int create_unit();
        
};