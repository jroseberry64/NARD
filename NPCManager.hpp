#ifndef NPCMANAGER_HPP
#define NPCMANAGER_HPP

#include "Character.hpp"
#include "CoordPairs.hpp"
#include <vector>
#include <stdint.h>

#define NORTH 1
#define SOUTH 2
#define EAST  3
#define WEST  4 

class NPCManager {
   
    public:
    
        //Getters
        const unsigned short getEnemyCurrentHP(int index);
        const unsigned short getEnemyCurrentHealth(int index);
        const uint8_t getEnemyArmor(int index);
        const uint8_t getEnemyStrength(int index);
        const char getEnemySprite(int index);
        const CoordPairs getEnemyLocation(int index);
        const bool getEnemyVisibility(int index);
        const bool getEnemyPermeability(int index);
        Character& getEnemy(int index);
        int numberOfEnemiesSpawned(void);
    
        //enemy_turn() functions
        void moveEnemy(int direction, int index);
        void setEnemyLocation(CoordPairs coord, int index);
        void attack(Character* player, int index);
    
    
        //initialize_and_place_enemies() functions
        void spawnEnemy(int id);
    
        //player_turn() functions
        int enemyPlayerAttacked(CoordPairs enemyCoord);
        void deathWatch(void);
    
        //End of Level Functions
        void EOL_data_cleanup(void);
    
        //singleton
        static NPCManager* getNPCManagerInstance(void) {
            npc_manager = new NPCManager;
            return npc_manager;
        }
    
    
    private:
        NPCManager() = default;
        ~NPCManager() = default;
    
        int numEnemiesSpawned;
        std::vector<Character> enemies;
        static NPCManager *npc_manager;
    
        void removeDeadEnemy(int index);
};


#endif
