/**
 * structure.cpp
 * 
 * Contains function implementations for the structure class and other structures
 * 
 * Author R3V
 * Created October 1st, 2023
*/

#include "structure.h"

/**
 * set_health
 * 
 * Used to set a structure health to a particular value
 * 
 * @param val Value to set structure health to 
*/
void Structure::set_health(int val) { 
    this->health = val;
}

/**
 * spawn_drone
 * 
 * The Base structure is capable of spawning work drones, create a drone 
 * if player has enough resources to do so
 * 
 * @return True if a drone was able to be spawned, false otherwise
*/
bool Base::spawn_drone() { 
    //
    return false;
}