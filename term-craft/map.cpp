/**
 * map.cpp
 * 
 * Function implementations of map class
*/

#include <iostream>
#include "map.h"

void Map::draw_map(Player pl1, Player pl2) {
    for(int i = 0; i < this->dim_y; i++) {
        for(int j = 0; j < this->dim_x; j++) { 
            /* Draw the players (Currently hardcoded for two players )*/
            if (j == pl1.get_x() && i == pl1.get_y()) { 
                printf("%c ", pl1.get_cursor());
                continue;
            }

            if (j == pl2.get_x() && i == pl2.get_y()) { 
                printf("%c ", pl2.get_cursor());
                continue;
            }

            /* Draw the field */
            if(i == 0 || j == 0 || i == this->dim_y - 1 || j == this->dim_x - 1) /* Draw edges */
                printf("# ");
            else
                printf(". "); /* Draw inside */
        }
        putc('\n', stdout);
    }
    printf("\n\n");
}