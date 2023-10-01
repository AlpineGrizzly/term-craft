/**
 * structure.h
 * 
 * Contains function declaractions for the structure class
 * 
 * Author R3V
 * Created October 1st, 2023
*/

class Structure { 
    private:
        int health; /* Health associated with structure */
        char icon;  /* Standard structure icon */
    public:
    Structure(char icon, int health) { 
        this->icon = icon;
        this->health = health;
    }
    void set_health(int val);
};

class Base : public Structure { 
    private: 
        int num_drones; /* Number of drones associated with a base */
    public:
        bool spawn_drone();
};

