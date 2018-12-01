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
#include "CoordPairs.hpp"
#include <cstdlib>

void run_level(DungeonData& dungeon_data) {
	while(!flag_is_set(LEVEL_COMPLETE_FLAG) && !flag_is_set(PLAYER_DEATH_FLAG)) {
		run_player_turn(dungeon_data);
		run_enemy_turn(dungeon_data);
		render_map(dungeon_data);
	}
}

void run_player_turn(DungeonData& dungeon_data) {
	bool validKey = false;
	while(!validKey) {
		get_player_input(dungeon_data);
        validKey = dungeon_data.input_manager->validInput();
	}
    CoordPairs testMove = dungeon_data.player_manager->getPlayerLocation();
    
    //Monster Coords here
    int numEnemies = dungeon_data.npc_manager->numberOfEnemiesSpawned();
    
    CoordPairs dungeonExit = dungeon_data.room_manager->getDungeonExitCoords();
    
    CoordPairs enemy_coordinate[numEnemies];
    
    for(int i = 0; i < numEnemies - 1; i++) {
        enemy_coordinate[i] = dungeon_data.npc_manager->getEnemyLocation(i);
    }
    
    bool madeAttack = false;
    
	switch(dungeon_data.input_manager->getInput()) {
		case 'W':
        case 'w':
            testMove.y -= 1;
            //This checks for player colliding into wall
            if(dungeon_data.player_manager->playerInRoom()
               && testMove.y == dungeon_data.player_manager->playerRoom_y1()
               && !dungeon_data.room_manager->pointIsOnPath(testMove)) {
                break;
            } else if(dungeon_data.room_manager->pointIsOnPath(testMove) || dungeon_data.room_manager->entityEnteredRoomBounds(testMove)) {
                //Test for monster intersection here
                for(int i = 0; i < numEnemies - 1; i++) {
                    if(coordsAreEqual(testMove, enemy_coordinate[i])) {
                        Character *enemy = &dungeon_data.npc_manager->getEnemy(i);
                        dungeon_data.player_manager->attack(enemy);
                        dungeon_data.player_manager->addExp(1);
                        madeAttack = true;
                        break;
                    }
                }
                
                if(madeAttack)
                    break;
                
                if(coordsAreEqual(testMove, dungeonExit)) {
                    set_flag(LEVEL_COMPLETE_FLAG);
                    break;
                }
                
                //Check to see if the player re-entered room
                if(dungeon_data.room_manager->entityEnteredRoomBounds(testMove)
                   && !dungeon_data.player_manager->playerInRoom()) {
                    std::vector<Room> roomVect = dungeon_data.room_manager->getRoomVect();
                    dungeon_data.player_manager->setPlayerRoom(roomVect[dungeon_data.room_manager->roomPlayerIsIn(testMove)]);
                }
                
                //Check to see if the player exited the room
                if(!dungeon_data.room_manager->entityEnteredRoomBounds(testMove)
                   && dungeon_data.player_manager->playerInRoom()) {
                    dungeon_data.player_manager->setPlayerRoomToNull();
                }
                    
                dungeon_data.player_manager->movePlayer(NORTH);
            }
            break;
        case 'S':
        case 's':
            testMove.y += 1;
            //This checks for player colliding into wall
            if(dungeon_data.player_manager->playerInRoom()
               && testMove.y == dungeon_data.player_manager->playerRoom_y2()
               && !dungeon_data.room_manager->pointIsOnPath(testMove)) {
                break;
            }
            else if(dungeon_data.room_manager->pointIsOnPath(testMove) || dungeon_data.room_manager->entityEnteredRoomBounds(testMove)) {
                //Test for monster intersection here
                for(int i = 0; i < numEnemies - 1; i++) {
                    if(coordsAreEqual(testMove, enemy_coordinate[i])) {
                        Character *enemy = &dungeon_data.npc_manager->getEnemy(i);
                        dungeon_data.player_manager->attack(enemy);
                        dungeon_data.player_manager->addExp(1);
                        madeAttack = true;
                        break;
                    }
                }
                
                if(madeAttack)
                    break;
                
                if(coordsAreEqual(testMove, dungeonExit)) {
                    set_flag(LEVEL_COMPLETE_FLAG);
                    break;
                }
                
                //Check to see if the player re-entered room
                if(dungeon_data.room_manager->entityEnteredRoomBounds(testMove)
                   && !dungeon_data.player_manager->playerInRoom()) {
                    std::vector<Room> roomVect = dungeon_data.room_manager->getRoomVect();
                    dungeon_data.player_manager->setPlayerRoom(roomVect[dungeon_data.room_manager->roomPlayerIsIn(testMove)]);
                }
                
                //Check to see if the player exited the room
                if(!dungeon_data.room_manager->entityEnteredRoomBounds(testMove)
                   && dungeon_data.player_manager->playerInRoom()) {
                    dungeon_data.player_manager->setPlayerRoomToNull();
                }
                
                dungeon_data.player_manager->movePlayer(SOUTH);
            }
            break;
        case 'A':
        case 'a':
            testMove.x -= 1;
            //This checks for player colliding into wall
            if(dungeon_data.player_manager->playerInRoom()
               && testMove.y == dungeon_data.player_manager->playerRoom_x1()
               && !dungeon_data.room_manager->pointIsOnPath(testMove)) {
                break;
            } else if(dungeon_data.room_manager->pointIsOnPath(testMove) || dungeon_data.room_manager->entityEnteredRoomBounds(testMove)) {
                //Test for monster intersection here
                for(int i = 0; i < numEnemies - 1; i++) {
                    if(coordsAreEqual(testMove, enemy_coordinate[i])) {
                        Character *enemy = &dungeon_data.npc_manager->getEnemy(i);
                        dungeon_data.player_manager->attack(enemy);
                        dungeon_data.player_manager->addExp(1);
                        madeAttack = true;
                        break;
                    }
                }
                
                if(madeAttack)
                    break;
                
                if(coordsAreEqual(testMove, dungeonExit)) {
                    set_flag(LEVEL_COMPLETE_FLAG);
                    break;
                }
                
                //Check to see if the player re-entered room
                if(dungeon_data.room_manager->entityEnteredRoomBounds(testMove)
                   && !dungeon_data.player_manager->playerInRoom()) {
                    std::vector<Room> roomVect = dungeon_data.room_manager->getRoomVect();
                    dungeon_data.player_manager->setPlayerRoom(roomVect[dungeon_data.room_manager->roomPlayerIsIn(testMove)]);
                }
                
                //Check to see if the player exited the room
                if(!dungeon_data.room_manager->entityEnteredRoomBounds(testMove)
                   && dungeon_data.player_manager->playerInRoom()) {
                    dungeon_data.player_manager->setPlayerRoomToNull();
                }
                
                dungeon_data.player_manager->movePlayer(WEST);
            }
            break;
        case 'D':
        case 'd':
            testMove.x += 1;
            //This checks for player colliding into wall
            if(dungeon_data.player_manager->playerInRoom()
               && testMove.y == dungeon_data.player_manager->playerRoom_x2()
               && !dungeon_data.room_manager->pointIsOnPath(testMove)) {
                break;
            } else if(dungeon_data.room_manager->pointIsOnPath(testMove) || dungeon_data.room_manager->entityEnteredRoomBounds(testMove)) {
                //Test for monster intersection here
                for(int i = 0; i < numEnemies - 1; i++) {
                    if(coordsAreEqual(testMove, enemy_coordinate[i])) {
                        Character *enemy = &dungeon_data.npc_manager->getEnemy(i);
                        dungeon_data.player_manager->attack(enemy);
                        dungeon_data.player_manager->addExp(1);
                        madeAttack = true;
                        break;
                    }
                }
                
                if(madeAttack)
                    break;
                
                if(coordsAreEqual(testMove, dungeonExit)) {
                    set_flag(LEVEL_COMPLETE_FLAG);
                    break;
                }
                
                //Check to see if the player re-entered room
                if(dungeon_data.room_manager->entityEnteredRoomBounds(testMove)
                   && !dungeon_data.player_manager->playerInRoom()) {
                    std::vector<Room> roomVect = dungeon_data.room_manager->getRoomVect();
                    dungeon_data.player_manager->setPlayerRoom(roomVect[dungeon_data.room_manager->roomPlayerIsIn(testMove)]);
                }
                
                //Check to see if the player exited the room
                if(!dungeon_data.room_manager->entityEnteredRoomBounds(testMove)
                   && dungeon_data.player_manager->playerInRoom()) {
                    dungeon_data.player_manager->setPlayerRoomToNull();
                }
                
                dungeon_data.player_manager->movePlayer(EAST);
            }
            break;
        default:
            break;
	}
    dungeon_data.npc_manager->deathWatch();
}

void run_enemy_turn(DungeonData& dungeon_data) {
    
    CoordPairs playerCoord = dungeon_data.player_manager->getPlayerLocation();
    int playerRoom = dungeon_data.room_manager->roomPlayerIsIn(playerCoord);
    
    Character *player = &dungeon_data.player_manager->getPlayer();
    
    for(int i = 0; i < dungeon_data.npc_manager->numberOfEnemiesSpawned() - 1; i++) {
        
        CoordPairs enemyCoord = dungeon_data.npc_manager->getEnemyLocation(i);
        int enemyRoom = dungeon_data.room_manager->roomPointIsIn(enemyCoord);
        
        if(playerRoom == enemyRoom) {
            if(enemyCoord.x < playerCoord.x && enemyCoord.y < playerCoord.y) {
                enemyCoord.x += 1;
                enemyCoord.y += 1;
            } else if(enemyCoord.x > playerCoord.x && enemyCoord.y > playerCoord.y) {
                enemyCoord.x -= 1;
                enemyCoord.y -= 1;
            } else if(enemyCoord.x < playerCoord.x && enemyCoord.y > playerCoord.y) {
                enemyCoord.x += 1;
                enemyCoord.y -= 1;
            } else if(enemyCoord.x > playerCoord.x && enemyCoord.y < playerCoord.y) {
                enemyCoord.x -= 1;
                enemyCoord.y += 1;
            } else if(enemyCoord.x == playerCoord.x) {
                (enemyCoord.y < playerCoord.y) ? enemyCoord.y += 1 : enemyCoord.y -= 1;
            } else if(enemyCoord.y == playerCoord.y) {
                (enemyCoord.x < playerCoord.x) ? enemyCoord.x += 1 : enemyCoord.x -= 1;
            }
            
            bool canMove = true;
            for(int j = 0; j < dungeon_data.npc_manager->numberOfEnemiesSpawned() - 1; j++) {
                if(i == j)
                    continue;
                if(coordsAreEqual(enemyCoord, dungeon_data.npc_manager->getEnemyLocation(j))) {
                    canMove = false;
                    break;
                }
            }
            
            if(!canMove)
                continue;
            
            if(coordsAreEqual(enemyCoord, playerCoord)) {
                dungeon_data.npc_manager->attack(player, i);
                if(dungeon_data.player_manager->getPlayerCurrentHP() == 0) {
                    set_flag(PLAYER_DEATH_FLAG);
                    break;
                }
            } else {
                dungeon_data.npc_manager->setEnemyLocation(enemyCoord, i);
            }
        }
        
        if(flag_is_set(PLAYER_DEATH_FLAG))
            break;
    }
}

bool endGameConditionsMet(void) {
	if(flag_is_set(PLAYER_DEATH_FLAG) || flag_is_set(SAVE_FLAG))
		return true;
	else 
		return false;
}

void get_player_input(DungeonData& dungeon_data) {
	dungeon_data.input_manager->pollInput();
}

void main_loop(DungeonData& dungeon_data) {		
	Menu main_menu(MAIN_MENU);
	//Menu game_over_menu();	//Need to #define GAME_OVER_MENU in the header file
	main_menu.runMenu();
	
	if(flag_is_set(LEVEL_COMPLETE_FLAG)) {
		unset_flag(LEVEL_COMPLETE_FLAG);
        initialize_level(dungeon_data);
	}

    render_map(dungeon_data);
	/*else if(flag_is_set(SAVE_FLAG)) {
		load_level(dungeon_data);
		unset_flag(SAVE_FLAG);
	} */
		
	while(1) {
		run_level(dungeon_data);
        if(endGameConditionsMet())
            break;
        dungeon_data.npc_manager->EOL_data_cleanup();
        dungeon_data.room_manager->EOL_data_cleanup();
		initialize_level(dungeon_data);
        unset_flag(LEVEL_COMPLETE_FLAG);
	}
	
	if(flag_is_set(PLAYER_DEATH_FLAG))
        cleanUpNcurses();
		//game_over_menu.runMenu();
	//else if(flag_is_set(SAVE_FLAG))
		//saveGame();	Still need to create this function	
}

void render_map(DungeonData& dungeon_data) {
    std::vector<Room> roomVect = dungeon_data.room_manager->getRoomVect();
    std::vector<CoordPairs> coordVect = dungeon_data.room_manager->getCoordVect();
    CoordPairs playerCoord = dungeon_data.player_manager->getPlayerLocation();
    int roomPlayerIsIn = dungeon_data.room_manager->roomPlayerIsIn(playerCoord);
    //bool isInRoom = false;
    
    erase();
    
    
    
    for(int i = 0; i < roomVect.size(); i++) {
        bool isInRoom = dungeon_data.room_manager->pointIsInsideRoomBounds(playerCoord, roomVect[i]);
        dungeon_data.rendering_engine->printRoom(isInRoom, roomVect[i]);
    }
    
    for(int i = 0; i < coordVect.size(); i++)
        dungeon_data.rendering_engine->printPath(coordVect[i]);
    
    dungeon_data.rendering_engine->printEntity(dungeon_data.player_manager->getPlayer());
    
    for(int i = 0; i < dungeon_data.npc_manager->numberOfEnemiesSpawned() - 1; i++) {
        
        if(dungeon_data.room_manager->roomEntityIsIn(dungeon_data.npc_manager->getEnemyLocation(i)) == roomPlayerIsIn)
            dungeon_data.rendering_engine->printEntity(dungeon_data.npc_manager->getEnemy(i));
    }
    
    if(dungeon_data.room_manager->roomEntityIsIn(dungeon_data.room_manager->getDungeonExitCoords()) == roomPlayerIsIn)
        dungeon_data.rendering_engine->printEntity(dungeon_data.room_manager->getDungeonExit());
    
    move(0, 0);
    move(200, 0);
    printw("HP:   %d/%d     Armor: %d     Strength:%d     EXP:%d",
           dungeon_data.player_manager->getPlayerCurrentHP(),
           dungeon_data.player_manager->getPlayerCurrentHealth(),
           dungeon_data.player_manager->getPlayerArmor(),
           dungeon_data.player_manager->getPlayerStrength(),
           dungeon_data.player_manager->getExp());
    
    dungeon_data.rendering_engine->updateWindow();
}
