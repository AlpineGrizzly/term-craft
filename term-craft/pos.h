/** pos.h
 * 
 * Contains Pos class declaration which holds information about position in the game 
 * 
 * Author R3V
 * Created October 15th, 2023
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