/** player.h
 * 
 * Contains class and function declarations for the player class 
 * 
 * Author R3V
 * Created October 1st, 2023
*/

#pragma once

/**
 * Pos
 * 
 * Class to represent position on the board
*/
class Pos {
    private: 
        int x_pos;
        int y_pos;

    public: 
        Pos(int x, int y){ 
            this->x_pos = x;
            this->y_pos = y;
        }
        void set_x(int new_x) {this->x_pos = new_x;}
        void set_y(int new_y) {this->y_pos = new_y;}
        int  get_x() {return this->x_pos;}
        int  get_y() {return this->y_pos;}
};

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
        int create_structure();
        int create_unit();
};