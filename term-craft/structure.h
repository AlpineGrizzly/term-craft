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
    void set_health(int val);
};

class Base : public Structure { 
    private: 
        int num_drones; /* Number of drones associated with a base */
    public:
        bool spawn_drone();
};

