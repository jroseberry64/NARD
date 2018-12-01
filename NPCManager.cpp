#include "NPCManager.hpp"

NPCManager* NPCManager::npc_manager = nullptr;

//Public Functions
//
//
//Getters

const unsigned short NPCManager::getEnemyCurrentHP(int index) {
    return enemies[index].hp();
}

const unsigned short NPCManager::getEnemyCurrentHealth(int index) {
    return enemies[index].health();
}

const uint8_t NPCManager::getEnemyArmor(int index) {
    return enemies[index].armor();
}

const uint8_t NPCManager::getEnemyStrength(int index) {
    return enemies[index].strength();
}

const char NPCManager::getEnemySprite(int index) {
    return enemies[index].sprite();
}

const CoordPairs NPCManager::getEnemyLocation(int index) {
    return enemies[index].loc();
}

const bool NPCManager::getEnemyVisibility(int index) {
    return enemies[index].visible();
}

const bool NPCManager::getEnemyPermeability(int index) {
    return enemies[index].permeable();
}

Character& NPCManager::getEnemy(int index) {
    return enemies[index];
}

int NPCManager::numberOfEnemiesSpawned(void) {
    return enemies.size();
}

//End of Getters
//
//
//enemy_turn() functions

void NPCManager::moveEnemy(int direction, int index) {
    CoordPairs newCoord = enemies[index].loc();
    
    switch(direction) {
        case NORTH:
            newCoord.y -= 1;
            break;
        case SOUTH:
            newCoord.y += 1;
            break;
        case EAST:
            newCoord.x += 1;
            break;
        case WEST:
            newCoord.x -= 1;
            break;
    }
    
    enemies[index].loc(newCoord);
}

void NPCManager::attack(Character *player, int index) {
    enemies[index].attack(player);
}

//End enemy_turn() functions
//
//
//initialize_and_place_enemies() functions

void NPCManager::spawnEnemy(int id) {
    //Do something with the id later
    enemies.emplace_back(Character());
    ++numEnemiesSpawned;
    enemies[numEnemiesSpawned - 1].sprite('B');
}

void NPCManager::setEnemyLocation(CoordPairs coord, int index) {
    enemies[index].loc(coord);
}

//End of initialize_and_place_enemies() functions
//
//
//player_turn() functions

int NPCManager::enemyPlayerAttacked(CoordPairs coord) {
    //If we return -1 it indicates some sort of failure
    int index = -1;
    
    for (int i = 0; i < enemies.size() - 1; i++) {
        if(coordsAreEqual(enemies[i].loc(), coord)) {
            index = i;
            return index;
        }
    }
    return index;
}

void NPCManager::deathWatch(void) {
    //Do some stuff here
    for(int i = 0; i < enemies.size(); i++)
    if(enemies[i].is_dead()) {
        removeDeadEnemy(i);
    }
    
}

//End of player_turn() functions
//
//
//Private Functions


void NPCManager::removeDeadEnemy(int index) {
    enemies.erase(enemies.begin()+index);
    numEnemiesSpawned--;
}


void NPCManager::EOL_data_cleanup(void) {
    enemies.clear();
    numEnemiesSpawned = 0;
}
