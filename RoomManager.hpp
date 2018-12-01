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

#ifndef ROOMMANAGER_HPP
#define ROOMMANAGER_HPP

#include <ncurses.h>
#include <vector>
#include <stdint.h>
#include "InitNcurses.hpp"
#include "CoordPairs.hpp"
#include "Sector.hpp"
#include "Room.hpp"
#include "Entity.hpp"

#define ROOM_PARTITION_COLUMN_START     10
#define ROOM_PARTITION_COLUMN_END       106
#define ROOM_PARTITION_ROW_START        10
#define ROOM_PARTITION_ROW_END          64

#define SECTOR_WIDTH_MAX                48
#define SECTOR_WIDTH_MIN                1
#define SECTOR_HEIGHT_MAX               27
#define SECTOR_HEIGHT_MIN               1


class RoomManager {
    
public:
    
    //Setters
    void setRoomVector(std::vector<Room> room);
    void setCoordVector(std::vector<CoordPairs> coords);
    const std::vector<Room> getRoomVect(void);
    const std::vector<CoordPairs> getCoordVect(void);
    Room& getRoom(int roomNumber);
    
    //Helpful functions
    
    //CoordPairs placeEntityInRoom(const std::vector<Room>& roomVect, const Entity& entity);      //X
    CoordPairs placeEntityInRoom(void);
    int roomEntityIsIn(CoordPairs coord);
    int roomPlayerIsIn(CoordPairs coord);
    //int roomEntityIsIn(std::vector<Room> roomVect, CoordPairs coord);
    bool hasVisitedPoint(std::vector<CoordPairs> coordVect, CoordPairs coord);            //X
    bool pointIsOnPath(CoordPairs entityCoord);        //X
    bool intersectsRoom(Room room, CoordPairs coord);                                     //X
    bool coordinateIntersectsRoomBounds(std::vector<Room> roomVect, CoordPairs coord);    //X
    bool entityEnteredRoomBounds(CoordPairs entityCoord);
    int numberOfRooms(void);
    const Room getRoomSubroom(const Room& room);                                          //X
    std::vector<Room> selectRoomsFromVector(std::vector<Room>& roomVect);                 //X
    std::vector<CoordPairs> connectRoom(const std::vector<Room>& roomVect);               //X
    bool pointIsInsideRoomBounds(CoordPairs coord, Room room);
    static RoomManager* getRoomManagerInstance() {
        roomManager = new RoomManager();
        return roomManager;
    }
    int roomPointIsIn(CoordPairs coord);
    void createDungeonExit(void);
    CoordPairs getDungeonExitCoords(void);
    Entity getDungeonExit(void);
    
    void EOL_data_cleanup(void);

    
    
private:
    std::vector<Room> roomVect;
    std::vector<CoordPairs> coordVect;
    
    Entity dungeonExit;
    
    //Singleton
    static RoomManager *roomManager;
    
    
    RoomManager() = default;
    ~RoomManager() = default;
    
    CoordPairs genPathfindPoints(int direction, const Room& room);                        //X
    uint8_t genRoomPadding(uint8_t padMin, uint8_t padMax);                               //X
    int genRoomChoice(int min, int max);                                                  //X
    int genRandomPoint(int edgeMin, int edgeMax);                                         //X
    int roomThatPointIntersects(std::vector<Room> roomVect, CoordPairs coord);            //X
    bool haveSelectedRoom(std::vector<int> roomVect, int roomNum);                        //X
    bool pathIsInsideRoomBounds(std::vector<Room> roomVect, CoordPairs coord);            //X

    
};

#endif /* RoomCoordinates_hpp */
