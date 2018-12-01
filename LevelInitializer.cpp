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

#include "LevelInitializer.hpp"
#include "GPRandNumGenerator.hpp"

void initialize_level(DungeonData& data) {

	initialize_map(*data.room_manager);

	//Use the statement below in the function
	//if(!flag_is_set(LEVEL_COMPLETE_FLAG))
	initialize_and_place_player_character((*data.player_manager), (*data.room_manager));
    

		
	/* Initialize the enemies */
	initialize_and_place_enemies(*data.npc_manager, *data.room_manager);
	
	/* Initialize the items */
	//initialize_and_place_items(&data.item_manager, &data.room_manager);
}

void initialize_map(RoomManager& room_manager) {
	std::vector<Node> nodeVector;
	
	Node *node = nullptr;
	Node *BSP_Tree = nullptr;
	
	Sector sector;
	sector._x1 = SECTOR_WIDTH_MIN;
	sector._x2 = SECTOR_WIDTH_MAX;
	sector._y1 = SECTOR_HEIGHT_MIN;
	sector._y2 = SECTOR_HEIGHT_MAX;
	
	sector._dx = sector._x2 - sector._x1;
	sector._dy = sector._y2 - sector._y1;
	
	sector._p1.x = sector._x1;
	sector._p1.y = sector._y1;
	sector._p2.x = sector._x2;
	sector._p2.y = sector._y1;
	sector._p3.x = sector._x1;
	sector._p3.y = sector._y2;
	sector._p4.x = sector._x2;
	sector._p4.y = sector._y2;
	
	int partnDir = 0;
	int partnDirStart = Node::genRandPartnDirect();

    if(partnDirStart == 1) {
        partnDir = 1;
    } else if(partnDirStart == 2) {
        partnDir = -1;
    }
    
    BSP_Tree = node->create(sector, nullptr, 4, partnDir);
    
    
    
    std::vector<Room> roomVect;
    std::vector<Sector> sectorVector = Node::getFinalBranches();
    std::vector<Room> secondRoomVect;
    std::vector<Room> finalRoomVect;
    
    //Delete the blank sector
    sectorVector.erase(sectorVector.begin());
    
    for(int i = 0; i < sectorVector.size(); i++) {
        roomVect.push_back(Room(sectorVector[i]));
    }
    
	for(int i = 0; i < roomVect.size(); i++) {
		secondRoomVect.push_back(Room(room_manager.getRoomSubroom(roomVect[i])));
	}
	
ReselectRoom:
	finalRoomVect = room_manager.selectRoomsFromVector(secondRoomVect);
	
	std::vector<CoordPairs> pathCoords;
	
	try {
		pathCoords = room_manager.connectRoom(finalRoomVect);
	} catch(int e) {
		switch(e) {
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
				finalRoomVect.erase(finalRoomVect.begin(), finalRoomVect.end());
				goto ReselectRoom;
		}
	}
    
	room_manager.setRoomVector(finalRoomVect);
	room_manager.setCoordVector(pathCoords);
    room_manager.createDungeonExit();
    
}

void initialize_and_place_player_character(PlayerManager& player_manager, RoomManager& room_manager) {
    player_manager.setPlayerLocation(room_manager.placeEntityInRoom());
    player_manager.setPlayerRoom(room_manager.getRoom(room_manager.roomPointIsIn(player_manager.getPlayerLocation())));
}

void initialize_and_place_enemies(NPCManager& npc_manager, RoomManager& room_manager) {
        
    //For now since this is pretty much a demo and we're only using one
    //enemy type we're gonna cap the number of bats
    int enemyCap = RandNumGenerator::genRandNumber(10, 15);
    int numEnemies = RandNumGenerator::genRandNumber(5, enemyCap);
    
    //Spawn the enemies
    for(int j = 0; j < numEnemies; j++) {
        CoordPairs location = room_manager.placeEntityInRoom();
        
        //Check to see if we've spawned an enemy on top of the dungeon exit
        if(coordsAreEqual(location, room_manager.getDungeonExitCoords())) {
            j -= 1;
            continue;
        }
        
        for(int i = 0; i < npc_manager.numberOfEnemiesSpawned(); i++) {
            //Check to see if we're getting piled on top of another entity
            if(j > 0) {
                int k = j - 1;
                while(k != 0) {
                    if(coordsAreEqual(location, npc_manager.getEnemyLocation(k))) {
                        j -= 1;
                        continue;
                    }
                    --k;
                }
            }
        }
               
        npc_manager.spawnEnemy(1);
        npc_manager.setEnemyLocation(location, j);
    }
}
