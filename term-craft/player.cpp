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


void Player::set_x(int new_x) { 
    this->curr_x = new_x;
}
void Player::set_y(int new_y) { 
    this->curr_y = new_y;

}

/**
 * get_x
 * 
 * @returns x location of the player
 * 
*/
int Player::get_x() { 
    return this->curr_x;
}

/**
 * get_y
 * 
 * @returns y location of the player
 * 
*/
int Player::get_y() { 
    return this->curr_y;
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
 * @param new_x New x location to which to move player
 * @param new_y New y location to which to move player
 * 
 * @return True if a valid move was made, false otherwise
*/
bool Player::move_cursor(int new_x, int new_y) { 
    return 0;
}

int Player::create_structure() { 

    return 0;
}

int Player::create_unit() { 

    return 0;
}