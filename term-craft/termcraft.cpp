/** Termcraft 
 * Starcraft inspired rts game 
 * 
 * Author R3V
 * Created September 30th, 2023
*/

/** Bugs
 * [ ] If anything other than a digit is entered in the menu, infinity loop
*/
#include <iostream>
#include <cstring>
#include <unistd.h> // May not be cross compatible

using namespace std;

/* This just seems like a fancy way of doing a stupid simple define */
enum gamemode { ONE=0, TWO=1, EXIT=2};

/* Keypress hex sequence values (WASD)
 * Reading hex values from arrow keys is a bitch, there's like 3 of them 
 */
#define KEY_0 0x31
#define KEY_1 0x32
#define KEY_2 0x33

#define KEY_W 0x77
#define KEY_A 0x61
#define KEY_S 0x73
#define KEY_D 0x64
//#define KEY_UP    0x1b 0x5b 0x41
//#define KEY_DOWN  0x1b 0x5b 0x42
//#define KEY_LEFT  0x1B 0x5B 0x44
//#define KEY_RIGHT 0x1B 0x5B 0x43

/**
 * draw_menu
 * 
 * Draws start menu where a player will be able to select a gamemode
 * 
 * @return number corresponding to the menu item selected
*/
int draw_menu() { 
    /* Menu Options
     * 1 - 1-Player
     * 2 - 2-Player
     * 3 - Exit
     */
    int menu_item = 0; 
    
    while(1) { 
        printf("====================================\n"
               "             TERMCRAFT\n" 
               "====================================\n");
        printf("1. 1-Player\n2. 2-Player\n3. Exit\n");
        
        cin >> menu_item;

        if (!isdigit(menu_item) && menu_item >= 1 && menu_item <= 3)
            break;
        
        menu_item = 0;
        cin.clear();
    }
    return menu_item;
}

void draw_map() {
    int x_dim = 50;
    int y_dim = 20;
    
    for(int i = 0; i < y_dim; i++) { 
        for(int j = 0; j < x_dim; j++) { 
            if(i == 0 || j == 0 || i == y_dim - 1 || j == x_dim - 1) /* Draw edges */
                printf("#");
            else
                printf("."); /* Draw inside */
        }
        putc('\n', stdout);
    }
    printf("\n\n");
}

int main() { 
    enum gamemode mode;

    /* Draw the map */
    switch(draw_menu()) { 
        case 1 :
            printf("Selected 1 player\n");
            draw_map();
            break;
        case 2:
            printf("Selected 2 player\n");
            break;
        case 3:
            printf("Selected exit\n");
            exit(0);
    }
}