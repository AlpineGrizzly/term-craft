/**
 * player.cpp
 * 
 * Contains function implementations for player class
 * 
 * Author R3V
 * Created October 1st, 2023
*/
#include <iostream>
#include "player.h"

/**
 * set_pos
 * 
 * Sets a new position of the player
*/
void Player::set_pos(Pos new_pos) { 
    this->pos->set_x(new_pos.get_x());
    this->pos->set_y(new_pos.get_y());
}   

/**
 * get_pos
 * 
 * Get's the current position of the player and returns it
 * 
 * @return the current position of the player
*/
Pos* Player::get_pos() { 
    Pos* tmp = this->pos;
    return tmp;
}

/**
 * get_cursor
 * 
 * @return Character representing the player's cursor
*/
char Player::get_cursor() { 
    return this->cursor;
}

/**
 * move_cursor 
 * 
 * Given a new x and y coordinate on the map, move the player
 * 
 * @param new_x Relative new x location to which to move player
 * @param new_y Relative new y location to which to move player
 * 
 * @return True if a valid move was made, false otherwise
*/
void Player::move_cursor(Pos new_pos) {  
    this->set_pos(new_pos);
}

/**
 * create_structure
 * 
 * Create a new structure where the player's cursor currently is
 * 
 * @param struct Structure to be built
*/
int Player::create_structure(char structure) { 
    if (this->owned_structs >= MAX_STRUCTURES) return 0; /* Only you can prevent overflows */  
    switch(structure) { 
        case 'w': // Build wall
            structs[this->owned_structs++] = new Structure('^', 50, this->pos->get_x(), this->pos->get_y());
    }
    return 0;
}

int Player::create_unit() { 

    return 0;
}