//          /---\-\    /---/-/  /-----\-\      |---------\-\    |---------\-\
//         /     \~\  /   /~/  /   --  \~\     |   _____  \~\   |  ------  \~\
//        /   _   \~\/   /~/  /   /  \  \~\    |   ||__|  |~|   |  ||   |  |-|
//       /   /~\   \/   /~/  /   /----\  \~\   |    ___   /-/   |  ||   |  |~|
//      /   /~/ \      /~/  /   _______   \~\  |   |~| \  \~\   |  ||   |  |~|
//     /   /~/   \    /~/  /   /~/     \   \~\ |   |~|  |  \~\  |  ------  /~/
//    /---/-/     \--/-/  /___/_/       \___\_\|___|_|  |___\_\ |_________/-/ 
//
//
//    
//
//              Created by Jonathan Roseberry and Jared Kimball
//    Copyright © 2018 Jonathan Roseberry and Jared Kimball. All rights reserved.
//
#define NORTH 1
#define SOUTH 2
#define EAST  3
#define WEST  4


#include "Room.hpp"
#include "CoordPairs.hpp"
#include <stdint.h>
#include <vector>
#include "Player.hpp"

//Player sprite printing out null character which is ^@, so fix this

class PlayerManager {
	public:
        const unsigned short getPlayerCurrentHP(void);
        const unsigned short getPlayerCurrentHealth(void);
        const uint8_t getPlayerArmor(void);
        const uint8_t getPlayerStrength(void);
        const char getPlayerSprite(void);
        const CoordPairs getPlayerLocation(void);
        const bool getPlayerVisibility(void);
        const bool getPlayerPermeability(void);
        void movePlayer(int direction);
        Character& getPlayer(void);
        void setPlayerLocation(CoordPairs coord);
        void setPlayerRoom(Room& room);
        void setPlayerRoomToNull(void);
        bool playerInRoom(void);
        uint8_t playerRoom_y1(void);
        uint8_t playerRoom_y2(void);
        uint8_t playerRoom_x1(void);
        uint8_t playerRoom_x2(void);
        void addExp(int exp);
        int getExp(void);
        void attack(Character *enemy);
    
        static PlayerManager* getPlayerManagerInstance(void) {
            playerManager = new PlayerManager;
            return playerManager;
    }
    
	private:
        PlayerManager();
        void levelUp(void);
        void setNewExp(void);
        bool levelUpConditionsMet(void);
    
        Room *_current_room;
        //Inventory _inventory;
        Player _player;
        int _level_up_exp;
        int _current_exp;
        static PlayerManager* playerManager;
		
};
