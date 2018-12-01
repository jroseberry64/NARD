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



#include "GameLoop.hpp"


int main(int argc, const char * argv[]) {
    DungeonData dungeon_data;
    dungeon_data.room_manager = RoomManager::getRoomManagerInstance();
    dungeon_data.rendering_engine = RenderingEngine::getRenderingEngineInstance();
    dungeon_data.player_manager = PlayerManager::getPlayerManagerInstance();
    dungeon_data.input_manager = InputManager::getInputManagerInstance();
    dungeon_data.npc_manager = NPCManager::getNPCManagerInstance();
    main_loop(dungeon_data);
    return 0;
}
