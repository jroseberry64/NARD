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

#ifndef LEVEL_INITIALIZER_HPP
#define LEVEL_INITIALIZER_HPP
#include "Node.hpp"
#include "Flags.hpp"
#include "DungeonData.hpp"

void initialize_level(DungeonData& data);
void initialize_map(RoomManager& room_manager);
void initialize_and_place_enemies(NPCManager& npc_manager, RoomManager& room_manager);
//void initialize_and_place_items(ItemManager& item_manager, RoomManager& room_manager);
void initialize_and_place_player_character(PlayerManager& player_manager, RoomManager& room_manager);


#endif
