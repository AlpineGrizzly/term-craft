/**
 * resource.c 
 * 
 * Resources that the player will be able to harvest and use to buy
 * upgrades, units, structures, etc. 
 * 
 * Author R3V
 * Created October 21st, 2023
*/
#include "resource.h"

/**
 * get_icon
 * 
 * @return the icon that represents the resource 
*/
char Resource::get_icon() { 
    return this->icon;
}

/**
 * get_value
 * 
 * @return The total value of the resource 
*/
int Resource::get_value() { 
    return this->value;
}

/** 
 * set_value
 * 
 * Set the total value of the resource to a new value
 * 
 * @param new_value New total value
*/
void Resource::set_value(int new_value) { 
    this->value = new_value;
}

/**
 * get_harvest_value
 * 
 * @return The harvest value of the resource per second 
*/
int Resource::get_harvest_value() { 
    return this->harvest_value;
}

/**
 * get_pos
 * 
 * @return The position of the resouce on the field
*/
Pos* Resource::get_pos() { 
    return this->pos;
}

