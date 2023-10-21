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
/* TODO Input will eventually just be an array of pointers to players to make it easier and expandable */
        // draw_map(player[] players, structure[] structs);
        void draw_map(Player* pls[]);
        void get_move(Player* pl); 
};