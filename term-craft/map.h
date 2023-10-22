/**
 * map.h
 * 
 * Contains function declaractions for the map class
 * 
 * Author R3V
 * Created October 1st, 2023
*/

#include "player.h"
#include "structure.h"
#include "resource.h"

#pragma once 

class Map { 
    private:
        int dim_x; /* Dimensions of the board */
        int dim_y;
    public:
        Map(int x, int y) { /* Constructor */
            this->dim_x = x;
            this->dim_y = y;
        }
        void draw_map(Player* pls[]);
        void get_move(Player* pl); 
        int get_x_dim();
        int get_y_dim();
};