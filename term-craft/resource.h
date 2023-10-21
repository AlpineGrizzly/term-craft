/**
 * resource.h 
 * 
 * Resources that the player will be able to harvest and use to buy
 * upgrades, units, structures, etc. 
 * 
 * Author R3V
 * Created October 21st, 2023
*/

#pragma once
#include "pos.h"

/** 
 * Resource
 * 
 * Base class that all resource types will inherit from 
*/
class Resource { 
    private:
        char icon; /* Icon to represent resource on board */
        int value; /* Total value of resource */
        int harvest_value; /* How much the player will acrue per second from resource */
        Pos* pos;  /* Position on board of resource */
    public:
        Resource(char icon, int value, int harvest_value, int x, int y) { 
            this->icon = icon;                             
            this->value = value;
            this->harvest_value;
            this->pos = new Pos(x, y);  
        }
        char get_icon();
        int get_value();
        void set_value(int new_value);
        int get_harvest_value();
        Pos* get_pos();
};

///**
// * Crystal
// * 
// * Crystals are resources that will generate value for use towards units, structures, etc. 
//*/
//class Crystal : public Resource { 
//    private:    
//    public:
//};
//
///**
// * Vespene
// * 
// * Vespene gas is another resource that is rarer than crystals but will allow
// * more options for constructing additional units, structures, etc. 
//*/
//class Vespene : public Resource { 
//    private:
//    public:
//};