/** player.h
 * 
 * Contains class and function declarations for the player class 
 * 
 * Author R3V
 * Created October 1st, 2023
*/

#pragma once

class Player { 
    private:
        int curr_x;
        int curr_y; 
        char cursor; /* Symbol that represents the player on the map */
    public:
        Player(char cursor, int start_x, int start_y) { /* Constructor for players cursor and start location */
            this->cursor = cursor;
            this->curr_x = start_x;
            this->curr_y = start_y;
        }
        int get_x();
        int get_y();
        void set_x(int new_x);
        void set_y(int new_y);
        char get_cursor();
        int move_cursor(int new_x, int new_y);
        int create_structure();
        int create_unit();
};