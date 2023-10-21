/**
 * structure.h
 * 
 * Contains function declaractions for the structure class
 * 
 * Author R3V
 * Created October 1st, 2023
*/

#pragma once
#include "pos.h"

#define MAX_DRONES 5 /* Maximum amount of drones that can be assigned to a base */

class Structure { 
    private:
        Pos* pos;   /* Position of structure on map */
        int health; /* Health associated with structure */
        char icon;  /* Standard structure icon */
    public:
        Structure(char icon, int health, int start_x, int start_y) { 
            this->icon = icon;
            this->health = health;
            this->pos = new Pos(start_x, start_y);
        }
        char get_icon() { return this->icon; }
        void set_health(int val);
        int get_health();
        Pos* get_pos() { return this->pos; } 
};

/**
 * Base
 * 
 * Structure that will act as the main base of each player on the board.
 * Capable of producing drones that will be able to harvest resources
*/
class Base : public Structure { 
    private:
        Pos* pos;       /* Position of structure on map */
        int health;     /* Health associated with structure */
        char icon;      /* Standard structure icon */ 
        int num_drones; /* Number of drones associated with a base */
    public:
        Base(char icon, int health, int drones, int start_x, int start_y) : Structure(icon, health, start_x, start_y) { 
            this->num_drones = drones;
        }
        bool spawn_drone();
        int get_num_drones();
};
