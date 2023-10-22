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
#define MAX_STRUCTURES 20 /* Defines how many structures can exist on the map */


class Player { 
    private:
        Pos* pos;             /* Position of Player on field */
        char cursor;          /* Symbol that represents the player on the map */
        Base* base;           /* pointer to Player's base object */
        Structure* structs[MAX_STRUCTURES]; /* Structures controlled by the player */ 
        int owned_structs;
    public:
        Player(char cursor, int start_x, int start_y) { /* Constructor for players cursor and start location */
            this->cursor = cursor;
            this->pos = new Pos(start_x, start_y);
            this->base = new Base(cursor, 
                                  100, 
                                  5, 
                                  this->get_pos()->get_x(), 
                                  this->get_pos()->get_y());
            this->structs[0] = this->base;
            this->owned_structs = 1;
             
        }
        void set_pos(Pos new_pos);
        Pos* get_pos();
        char get_cursor();
        void move_cursor(Pos new_pos);
        Base* get_base() { 
            return this->base;
        }
        Structure* get_structure(int idx) { return this->structs[idx];} 
        int get_owned_structs() { return this->owned_structs; }
        void set_owned_structs(int new_count) { this->owned_structs = new_count; }
        int create_structure(char structure);
        int create_unit();
        
};