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

#ifndef DUNGEONDATA_HPP
#define DUNGEONDATA_HPP

#include "RoomManager.hpp"
#include "InputManager.hpp"
#include "RenderingEngine.hpp"
#include "PlayerManager.hpp"
#include "NPCManager.hpp"


//const std::vector<Room> roomVector;
//const std::vector<CoordPairs> pathPoints;
//const std::vector<CoordPairs> entityStartPoints;
//std::vector<CoordPairs> entityCurrentPosition;
//std::vector<Entity> objectEntities;
//std::vector<Entity> npcEntities;
//Entity player;
	
struct DungeonData {
	//ItemManager *item_manager = ItemManager::getItemManagerInstance();
    RoomManager *room_manager; // = RoomManager::getRoomManagerInstance();
    NPCManager *npc_manager;  // = NPCManager::getNCPManagerInstance();
    PlayerManager *player_manager; // = PlayerManager::getPlayerManagerInstance();
    InputManager *input_manager; // = InputManager::getInputManagerInstance();
    RenderingEngine *rendering_engine; // = RenderingEngine::getRenderingEngineInstance();
};

#endif
