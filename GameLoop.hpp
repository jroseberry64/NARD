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

#ifndef GAMELOOP_HPP
#define GAMELOOP_HPP

#include "LevelInitializer.hpp"
#include "Flags.hpp"
#include "Menu.hpp"
#include "DungeonData.hpp"
#include <stdint.h>

void run_level(DungeonData& dungeon_data);
void run_player_turn(DungeonData& dungeon_data);
void run_enemy_turn(DungeonData& dungeon_data);
void get_player_input(DungeonData& dungeon_data);
void render_map(DungeonData& dungeon_data);
bool endGameConditionsMet(void);
void process_player_input(DungeonData& dungeon_data);
void main_loop(DungeonData& dungeon_data);



#endif
