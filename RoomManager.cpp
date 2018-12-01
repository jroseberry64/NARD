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

#include "RoomManager.hpp"
#include "ErrorHandling.hpp"
#include <time.h>
#include <stdexcept>
#include <random>

//I don't know if we're going to need this later so I've just kept it for now
/*
testForValidData(Sector& sectLeft, Sector& sectRight) {
    
    if(sectLeft._x1 > sectLeft._x2)
        return false;
    else if(sectLeft._x1 == 0)
        return false;
    else if(sectLeft._x2 == 0)
        return false;
    else if(sectLeft._y1 > sectLeft._y2)
        return false;
    else if(sectLeft._y1 == 0)
        return false;
    else if(sectLeft._y2 == 0)
        return false;
    else if(sectLeft._dx > (SECTOR_WIDTH_MAX - SECTOR_WIDTH_MIN))
        return false;
    else if(sectLeft._dy > (SECTOR_HEIGHT_MAX - SECTOR_HEIGHT_MIN))
        return false;
    else if(sectLeft._dy == 0)
        return false;
    else if(sectLeft._dx == 0)
        return false;
    else if(sectRight._x1 > sectRight._x2)
        return false;
    else if(sectRight._x1 == 0)
        return false;
    else if(sectRight._x2 == 0)
        return false;
    else if(sectRight._y1 > sectRight._y2)
        return false;
    else if(sectRight._y1 == 0)
        return false;
    else if(sectRight._y2 == 0)
        return false;
    else if(sectRight._dx > (SECTOR_WIDTH_MAX - SECTOR_WIDTH_MIN))
        return false;
    else if(sectRight._dx == 0)
        return false;
    else if(sectRight._dy > (SECTOR_HEIGHT_MAX - SECTOR_HEIGHT_MIN))
        return false;
    else if(sectRight._dy == 0)
        return false;
    else
        return true;
}
*/

RoomManager* RoomManager::roomManager = nullptr;

void RoomManager::createDungeonExit(void) {
    dungeonExit.loc(placeEntityInRoom());
    dungeonExit.sprite('>');
}

Entity RoomManager::getDungeonExit(void) {
    return dungeonExit;
}

CoordPairs RoomManager::getDungeonExitCoords(void) {
    return dungeonExit.loc();
}

void RoomManager::setRoomVector(std::vector<Room> room) {
    roomVect = room;
}

void RoomManager::setCoordVector(std::vector<CoordPairs> coords) {
    coordVect = coords;
}

Room& RoomManager::getRoom(int roomNumber) {
    if(roomNumber > roomVect.size())
        return roomVect[1];
    else
        return roomVect[roomNumber - 1];
}

bool RoomManager::entityEnteredRoomBounds(CoordPairs entityCoord) {
    return this->pathIsInsideRoomBounds(roomVect, entityCoord);
}

int RoomManager::numberOfRooms(void) {
    return roomVect.size();
}

//
const Room RoomManager::getRoomSubroom(const Room& room) {
    if(room._dx <= 8 || room._dy <= 6)
        return room;
    
    Room newRoom;
 
    //Padding essentially means the max or min distance the
    //room walls will shrink by
    uint8_t _x_padding_min = 1;
    uint8_t _x_padding_max = 3;
    uint8_t _y_padding_min = 1;
    uint8_t _y_padding_max = 3;
    
    //Then you just get the padding somewhere between the
    //max and min values
    uint8_t _xpad = genRoomPadding(_x_padding_min, _x_padding_max);
    uint8_t _ypad = genRoomPadding(_y_padding_min, _y_padding_max);
    
    newRoom._x1 = room._x1 + _xpad;
    newRoom._x2 = room._x2 - _xpad;
    newRoom._y1 = room._y1 + _ypad;
    newRoom._y2 = room._y2 - _ypad;
    
    newRoom._dx = newRoom._x2 - newRoom._x1;
    newRoom._dy = newRoom._y2 - newRoom._y1;
    
    newRoom._p1.x = newRoom._x1;
    newRoom._p1.y = newRoom._y1;
    newRoom._p2.x = newRoom._x2;
    newRoom._p2.y = newRoom._y1;
    newRoom._p3.x = newRoom._x1;
    newRoom._p3.y = newRoom._y2;
    newRoom._p4.x = newRoom._x2;
    newRoom._p4.y = newRoom._y2;
    
    return newRoom;
}

std::vector<Room> RoomManager::selectRoomsFromVector(std::vector<Room>& roomVect) {
    std::vector<Room> nRoomVect;
    std::vector<int> rooms_selected;
    int numRooms = 0;
    
    int vector_size = roomVect.size();
    
    int counter;
    
    if(vector_size / 2 > 7)
        counter = 7;
    else
        counter = vector_size / 2;
    
    int num = 0;
    
        while(numRooms < counter) {
            int randRoom;
            
            switch(num) {
                case 0:
                    randRoom = genRoomChoice(0,1);
                    break;
                case 1:
                    randRoom = genRoomChoice(2,3);
                    break;
                case 2:
                    randRoom = genRoomChoice(4,5);
                    break;
                case 3:
                    randRoom = genRoomChoice(6,7);
                    break;
                case 4:
                    randRoom = genRoomChoice(8,9);
                    break;
                case 5:
                    randRoom = genRoomChoice(10,11);
                    break;
                case 6:
                    randRoom = genRoomChoice(12,13);
                    break;
                case 7:
                    randRoom = genRoomChoice(14,15);
                    break;
                default:
                    break;
            }
            
            if(!(haveSelectedRoom(rooms_selected, randRoom))) {
                rooms_selected.push_back(randRoom);
                nRoomVect.push_back(roomVect[randRoom]);
                numRooms++;
                num++;
            } else {
                num++;
                continue;
            }
        }
    return nRoomVect;
}

uint8_t RoomManager::genRoomPadding(uint8_t padMin, uint8_t padMax) {
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_int_distribution<> rand_num(padMin, padMax);
    
    return rand_num(gen);
}

int RoomManager::genRoomChoice(int min, int max) {
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_int_distribution<> rand_num(min, max);
    
    return rand_num(gen);
}

int RoomManager::genRandomPoint(int edgeMin, int edgeMax) {
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_int_distribution<> rand_num(edgeMin, edgeMax);
    
    return rand_num(gen);
}
                            
bool RoomManager::haveSelectedRoom(std::vector<int> roomVect, int roomNum) {
    if(roomVect.size() == 0)
        return false;
    else {
        for(int i = 0; i < roomVect.size(); i++) {
            if(roomNum == roomVect[i])
                return true;
        }
    }
    return false;
}

std::vector<CoordPairs> RoomManager::connectRoom(const std::vector<Room>& roomVect) {
    
    //Use this later to store all the coordinates for the points along the paths
    //so we can add the data to the 2d array that stores everything in the map
    std::vector<CoordPairs> coordVect;
    
    for(int i = 0; i < roomVect.size() - 1; i++) {
        int startX;
        int startY;
        int endX;
        int endY;
        
        int wallNumOne, wallNumTwo, wallNumSum;
        bool isValidRoomCombo;
        
        int directionOne, directionTwo;
        
        //This loop checks that the rooms are connecting in a visually appealing way
        //that also avoids some of the stupid things the algorithm below does when it
        //tries to find a path to connect two rooms with walls that are on unoptimal
        //sides. It will continue to run until it comes up with a valid configuration.
        //
        //      ***********************
        //      *THINGS TO ACCOUNT FOR*
        //      ***********************
        //
        //If one room is to the southwest and another room is to the northeast
        //there is one set of valid room paths that the paths are allowed to follow.
        //
        //If one room is to the northwest and another room is to the southeast
        //then there's another set of valid room paths.
        //
        //Another thing we need to account for is rooms that are side by side
        //or one above the other. These two types of rooms also have a set of
        //paths that are valid. With this you also run into the possibility
        //that the rooms are north and south or east and west walls are shared
        //due to the way the BSP generator works, so you need to check to
        //see if those walls are touching, because then you only have two
        //options of how to connect the rooms.
        
        do {
            // 1 = North, 2 = South, 3 = East, 4 = West
            directionOne = genRandomPoint(1, 4);
            directionTwo = genRandomPoint(1, 4);
            
            CoordPairs firstPair = genPathfindPoints(directionOne, roomVect[i]);
            startX = firstPair.x;
            startY = firstPair.y;
            
            //If we've got an out of bounds point we're gonna have a bad
            //day, so just exit and handle that
            if(startX > 106 || startX < 0)
                throw(OUT_OF_BOUNDS_START_COORD);
            
            
            CoordPairs secondPair = genPathfindPoints(directionTwo, roomVect[i + 1]);
            endX = secondPair.x;
            endY = secondPair.y;
            
            //Same here
            if(startY > 64 || startY < 3)
                throw(OUT_OF_BOUNDS_END_COORD);
            
            
            if((startX < endX && startY > endY) || (startX > endX && startY < endY)) {
            
                switch(directionOne) {
                    case 1:
                        wallNumOne = 5;
                        break;
                    case 2:
                        wallNumOne = 3;
                        break;
                    case 3:
                        wallNumOne = 17;
                        break;
                    case 4:
                        wallNumOne = 19;
                        break;
                    default:
                        break;
                }
            
                switch(directionTwo) {
                    case 1:
                        wallNumTwo = 3;
                        break;
                    case 2:
                        wallNumTwo = 5;
                        break;
                    case 3:
                        wallNumTwo = 19;
                        break;
                    case 4:
                        wallNumTwo = 17;
                        break;
                    default:
                        break;
                }
                
                wallNumSum = wallNumOne + wallNumTwo;
                
                switch(wallNumSum) {
                    case 8:
                        isValidRoomCombo = true;
                        break;
                    case 21:
                        isValidRoomCombo = true;
                        break;
                    case 22:
                        isValidRoomCombo = true;
                        break;
                    case 34:
                        isValidRoomCombo = true;
                        break;
                    default:
                        isValidRoomCombo = false;
                        break;
                }
            } else if((startX > endX && startY > endY) || (startX < endX && startY < endY)) {
                
                switch(directionOne) {
                    case 1:
                        wallNumOne = 3;
                        break;
                    case 2:
                        wallNumOne = 5;
                        break;
                    case 3:
                        wallNumOne = 19;
                        break;
                    case 4:
                        wallNumOne = 17;
                        break;
                    default:
                        break;
                }
                
                switch(directionTwo) {
                    case 1:
                        wallNumTwo = 5;
                        break;
                    case 2:
                        wallNumTwo = 3;
                        break;
                    case 3:
                        wallNumTwo = 17;
                        break;
                    case 4:
                        wallNumTwo = 19;
                        break;
                    default:
                        break;
                }
                
                wallNumSum = wallNumOne + wallNumTwo;
                
                switch(wallNumSum) {
                    case 8:
                        isValidRoomCombo = true;
                        break;
                    case 20:
                        isValidRoomCombo = true;
                        break;
                    case 24:
                        isValidRoomCombo = true;
                        break;
                    case 38:
                        isValidRoomCombo = true;
                        break;
                    default:
                        isValidRoomCombo = false;
                        break;
                }
            } else if((roomVect[i]._x1 <= roomVect[i+1]._x1 && roomVect[i]._x2 >= roomVect[i+1]._x2) && roomVect[i]._y2 <= roomVect[i+1]._y1) {
                
                switch(directionOne) {
                    case 1:
                        wallNumOne = 17;
                        break;
                    case 2:
                        wallNumOne = 19;
                        break;
                    case 3:
                        wallNumOne = 5;
                        break;
                    case 4:
                        wallNumOne = 3;
                        break;
                    default:
                        break;
                }
                
                switch(directionTwo) {
                    case 1:
                        wallNumTwo = 17;
                        break;
                    case 2:
                        wallNumTwo = 19;
                        break;
                    case 3:
                        wallNumTwo = 5;
                        break;
                    case 4:
                        wallNumTwo = 3;
                        break;
                    default:
                        break;
                }
                
                wallNumSum = wallNumOne + wallNumTwo;
                
                if(roomVect[i]._y2 < roomVect[i+1]._y1) {
                    switch(wallNumSum) {
                        case 8:
                            isValidRoomCombo = true;
                            break;
                        case 38:
                            isValidRoomCombo = true;
                            break;
                        default:
                            isValidRoomCombo = false;
                            break;
                    }
                } else if(roomVect[i]._y2 == roomVect[i+1]._y1) {
                    switch(wallNumSum) {
                        case 8:
                            isValidRoomCombo = true;
                            break;
                        default:
                            isValidRoomCombo = false;
                            break;
                    }
                }
            } else if((roomVect[i]._y1 <= roomVect[i+1]._y1 && roomVect[i]._y2 >= roomVect[i+1]._y2) && roomVect[i]._x2 <= roomVect[i+1]._x1) {
                
                
                switch(directionOne) {
                    case 1:
                        wallNumOne = 17;
                        break;
                    case 2:
                        wallNumOne = 19;
                        break;
                    case 3:
                        wallNumOne = 5;
                        break;
                    case 4:
                        wallNumOne = 3;
                        break;
                    default:
                        break;
                }
                
                switch(directionTwo) {
                    case 1:
                        wallNumTwo = 17;
                        break;
                    case 2:
                        wallNumTwo = 19;
                        break;
                    case 3:
                        wallNumTwo = 5;
                        break;
                    case 4:
                        wallNumTwo = 3;
                        break;
                    default:
                        break;
                }
                
                wallNumSum = wallNumOne + wallNumTwo;
                
                if(roomVect[i]._y2 < roomVect[i+1]._y1) {
                    switch(wallNumSum) {
                        case 10:
                            isValidRoomCombo = true;
                            break;
                        case 38:
                            isValidRoomCombo = true;
                            break;
                        case 34:
                            isValidRoomCombo = true;
                            break;
                        default:
                            isValidRoomCombo = false;
                            break;
                    }
                } else if(roomVect[i]._y2 == roomVect[i+1]._y1) {
                    switch(wallNumSum) {
                        case 10:
                            isValidRoomCombo = true;
                            break;
                        default:
                            isValidRoomCombo = false;
                            break;
                    }
                }
            }
        } while(!isValidRoomCombo);

        //We always want to know where exactly we're at and to not overwrite
        //startX and startY we just create a new value;
        int currentX = startX;
        int currentY = startY;
    
        int previousX;
        int previousY;
        
    
        int iteration = 0;
    
        CoordPairs coord;
        coord.x = startX;
        coord.y = startY;
        coordVect.push_back(coord);
        CoordPairs endCoord;
        endCoord.x = endX;
        endCoord.y = endY;

        //clock_t runTime;
        //runTime = clock();

        //This loop executes until the two points are connected
        while(!(coordsAreEqual(endCoord, coord))) {
            //runTime = clock() - runTime;
            
            //if(runTime > 200)
                //throw(PATHFINDING_STUCK);
            
            if(iteration > 450)
                throw(PATHFINDING_STUCK);
            
            bool didMove = false;
        
            //Set up our variables
            previousX = currentX;
            previousY = currentY;
            CoordPairs coordTest;
        
            //If we're in the first iteration we don't want the path to start forming through
            //the inside of the room, so we automatically move in the direction away from
            //the room in whatever direction is opposite of the door.
            if(iteration == 0) {
                
                /* If the room is on the wrong side patch */
                coordTest.x = currentX;
                coordTest.y = currentY;
                
                Room roomOne(roomVect[i]);
                Room roomTwo(roomVect[i+1]);
                
                if( (roomOne._y1 >= roomTwo._y1 && roomOne._y2 <=  roomTwo._y2) || (roomOne._y1 <= roomTwo._y1 && roomOne._y2 >=  roomTwo._y2) ) {
                    if( (directionOne == 3 && directionTwo == 3) || (directionOne == 4 && directionTwo == 4) ) {
                        directionTwo == 3 ? endX = roomTwo._x1 : endX = roomTwo._x2;
                    }
                }
                /* End of patch */
                
                if(directionOne == 1)
                    --currentY;
                else if(directionOne == 2)
                    ++currentY;
                else if(directionOne == 3)
                    ++currentX;
                else if(directionOne == 4)
                    --currentX;
                
                ++iteration;
                coord.x = currentX;
                coord.y = currentY;
                coordVect.push_back(coord);
                
                continue;
            }
        
            /*****Works by favoring movement in the direction of the door*****/
        
            //The algorithm checks to see if the current X position is less or greater than the
            //end X coordinate so we're not trying to walk the path in the wrong direction for
            //no reason.
            //
            //If the X coordinate is less than the end X value or greater than the end X value
            //then the algorithm goes through the following steps:
            //
            //  1.Generate a random number between one and four.
            //  2A.If the number is greater than 1:
            //      A) If x is less than endX, test to see if x + 1 intersects any room bounds
            //         and if it doesn't, let x = x + 1; if it does, continue to the start.
            //      B) If x is greater than endX, test to see if x - 1 intersects any room
            //         bounds, and if it doesn't, let x = x - 1; if it does continue to
            //         the start.
            //  2B.If the number equals 1:
            //      A) Pick a random number between one and two.
            //      B) If it equals one, test to see if y - 1 intersects any room bounds
            //         and if it doesn't, let y = y - 1; if it does continue to the start.
            //      C) If it equals two, test to see if y + 1 intersects any room bounds
            //         and if it doesn't, let y = y + 1; if it does continue to the start.
            //
            //
            //If the X coordinate equals the end X value, then we know that we are
            //either above or below the end point we need to reach. Since we know that
            //all we have to do is keep moving up or down to reach the end the X value
            //probably doesn't need to be changed.
            //
            //The problem is that there's a chance that we may actually run into another
            //room if we're far enough away from the the endX position, so we need to
            //walk up from current Y to endY and check to see if there's another room
            //in the way. If there is, we need to evaluate how to move around the room
            //that's in the way in order to reach the endY point.
            //
            //The second problem we might run into is that we're at the right room but
            //the endX coordinate is on the opposite wall from where we're at. In this
            //case we can either flip the Y-position so endY is actually at the opposite
            //end of the original position and we fix our problem.
            
            if((currentX + 2 == endX || currentX - 2 == endX) && currentY == endY) {    //#################################################//
                
                //This accounts for an edge case were the algorithm gets stuck
                //right before the end of the
                for(int i = 0; i < 2; i++) {
                    if(i == 0)
                        currentX + 2 == endX ? currentX++ : currentX--;
                    else
                        currentX + 1 == endX ? currentX++ : currentX--;
                    
                    if(currentX > 106 || currentX < 0)
                        throw(OUT_OF_BOUNDS_COORD);
                    
                    coord.x = currentX;
                    coord.y = currentY;
                    coordVect.push_back(coord);
                    
                    didMove = true;
                }
            } else if(currentX < endX) {        //################################################//
                
           
                //Test to see if the next point is going to intersect the room we want to get to,
                //and if it is, just move the final position to that x-position, with the caveat
                //that we're not bumping into the corner
                coordTest.x = currentX + 1;
                coordTest.y = currentY;
                Room roomTwo(roomVect[i+1]);
                if(intersectsRoom(roomTwo, coordTest) && (currentX != roomTwo._x1 && currentX != roomTwo._x2)) {
                    endX = roomTwo._x1;
                    endCoord.x = roomTwo._x1;
                }
                
                //If this isn't the room we're looking for we need to go around the obstacle that's in the way.
                if(coordinateIntersectsRoomBounds(roomVect, coordTest) && !coordsAreEqual(coordTest, endCoord)) {
                    bool canMoveRight = false;
                    while(!canMoveRight) {
                        ++iteration;
                        int test = coordVect.size();
                        
                        //We check for this again because there's always the possibility as we try and move around
                        //the room that's in the way we could bump into the room we're trying to get to.
                        coordTest.x = currentX;
                        coordTest.y = currentY + 1;
                        Room roomTwo(roomVect[i+1]);
                        if(intersectsRoom(roomTwo, coordTest) && (currentY != roomTwo._y1 && currentY != roomTwo._y2) && coordTest.x == endX) {
                            endY = coordTest.y;
                            endCoord.y = coordTest.y;
                            endX = coordTest.x;
                            endCoord.x = coordTest.x;
                            break;
                        }
                        
                        //This is how we decide which way to move in the X or Y direction
                        if(currentY < endY)
                            currentY++;
                        else if(currentY > endY)
                            currentY--;
                        else if(currentY == endY) {
                            if(previousY < currentY)
                                currentY++;
                            else
                                currentY--;
                        }
                        
                        //Now we add the updated position to our coordinate vector
                        coord.x = currentX;
                        coord.y = currentY;
                        coordVect.push_back(coord);
                                    
                        coordTest.x = currentX + 1;
                        coordTest.y = currentY;
                        if(!coordinateIntersectsRoomBounds(roomVect, coordTest) || (coordinateIntersectsRoomBounds(roomVect, coordTest) && coordsAreEqual(coordTest, endCoord)))
                            canMoveRight = true;
                        
                        if(test > 4 && coordsAreEqual(coordVect[test], coordVect[test - 2]) &&  coordsAreEqual(coordVect[test - 1], coordVect[test - 3]))
                            throw(PATHFINDING_STUCK);
                        
                        if(test > 4 && coordsAreEqual(coordVect[test], coordVect[test - 4]) &&  coordsAreEqual(coordVect[test - 1], coordVect[test - 3]))
                            throw(PATHFINDING_STUCK);
                        
                        if(pathIsInsideRoomBounds(roomVect, coord))
                            throw(PATH_INSIDE_ROOM);
                    }
                }
                ++currentX;
                
                if(currentX > 106 || currentX < 0)
                    throw(OUT_OF_BOUNDS_COORD);

                
                didMove = true;
            } else if(currentX > endX) {        //####################################//
                bool didMoveXFinal = false;
                
                coordTest.x = currentX - 1;
                coordTest.y = currentY;
                Room roomTwo(roomVect[i+1]);
                if(intersectsRoom(roomTwo, coordTest) && (currentX != roomTwo._x1 && currentX != roomTwo._x2)) {
                    endX = roomTwo._x2;
                    endCoord.y = roomTwo._x2;
                }
                if(coordinateIntersectsRoomBounds(roomVect, coordTest) && !coordsAreEqual(coordTest, endCoord)) {
                    bool canMoveLeft = false;
                    while(!canMoveLeft) {
                        ++iteration;
                        
                        int test = coordVect.size();
                        
                        coordTest.x = currentX - 1;
                        coordTest.y = currentY;
                        Room roomTwo(roomVect[i+1]);
                        if(intersectsRoom(roomTwo, coordTest) && (currentY != roomTwo._y1 && currentY != roomTwo._y2) && coordTest.x == endX) {
                            endY = coordTest.y;
                            endCoord.y = coordTest.y;
                            endX = coordTest.x;
                            endCoord.x = coordTest.x;
                            break;
                        }
                        
                        if(currentY < endY)
                            currentY++;
                        else if(currentY > endY)
                            currentY--;
                        else if(currentY == endY) {
                            if(previousY < currentY)
                                currentY++;
                            else
                                currentY--;
                        }
                            
                        
                        coord.x = currentX;
                        coord.y = currentY;
                        coordVect.push_back(coord);
                                        
                        coordTest.x = currentX - 1;
                        coordTest.y = currentY;
                        if(!coordinateIntersectsRoomBounds(roomVect, coordTest) || (coordinateIntersectsRoomBounds(roomVect, coordTest) && coordsAreEqual(coordTest, endCoord)))
                            canMoveLeft = true;
                        
                        if(test > 4 && coordsAreEqual(coordVect[test], coordVect[test - 2]) &&  coordsAreEqual(coordVect[test - 1], coordVect[test - 3]))
                            throw(PATHFINDING_STUCK);
                        
                        if(test > 4 && coordsAreEqual(coordVect[test], coordVect[test - 4]) &&  coordsAreEqual(coordVect[test - 1], coordVect[test - 3]))
                            throw(PATHFINDING_STUCK);
                        
                        if(pathIsInsideRoomBounds(roomVect, coord))
                            throw(PATH_INSIDE_ROOM);
                    }
                }
                --currentX;
                if(currentX > 106 || currentX < 0)
                    throw(OUT_OF_BOUNDS_COORD);
                
                coord.x = currentX;
                coord.y = currentY;
                coordVect.push_back(coord);
                
                didMove = true;
            } else if(currentY < endY) { //#####################################//
                
                coordTest.x = currentX;
                coordTest.y = currentY + 1;
                Room roomTwo(roomVect[i+1]);
                if(intersectsRoom(roomTwo, coordTest) && (currentX != roomTwo._x1 && currentX != roomTwo._x2)) {
                    endY = roomTwo._y1;
                    endCoord.y = roomTwo._y1;
                }
                if(coordinateIntersectsRoomBounds(roomVect, coordTest) && !coordsAreEqual(coordTest, endCoord)) {
                    bool canMoveDown = false;
                    while(!canMoveDown) {
                        ++iteration;
                        int test = coordVect.size();
                        
                        coordTest.x = currentX + 1;
                        coordTest.y = currentY;
                        Room roomTwo(roomVect[i+1]);
                        if(intersectsRoom(roomTwo, coordTest) && (currentX != roomTwo._x1 && currentX != roomTwo._x2)) {
                            endY = coordTest.y;
                            endCoord.y = coordTest.y;
                            endX = coordTest.x;
                            endCoord.x = coordTest.x;
                            break;
                        }
                        
                        currentX++;
                        coord.x = currentX;
                        coord.y = currentY;
                        coordVect.push_back(coord);
                                   
                        coordTest.x = currentX;
                        coordTest.y = currentY + 1;
                        if(!coordinateIntersectsRoomBounds(roomVect, coordTest) || (coordinateIntersectsRoomBounds(roomVect, coordTest) && coordsAreEqual(coordTest, endCoord)))
                            canMoveDown = true;
                        
                        if(test > 4 && coordsAreEqual(coordVect[test], coordVect[test - 2]) &&  coordsAreEqual(coordVect[test - 1], coordVect[test - 3]))
                            throw(PATHFINDING_STUCK);
                        
                        if(test > 4 && coordsAreEqual(coordVect[test], coordVect[test - 4]) &&  coordsAreEqual(coordVect[test - 1], coordVect[test - 3]))
                            throw(PATHFINDING_STUCK);
                        
                        if(pathIsInsideRoomBounds(roomVect, coord))
                            throw(PATH_INSIDE_ROOM);
                    }
                }
                ++currentY;
            } else if(currentY > endY) { //#########################################################//
                
                coordTest.x = currentX;
                coordTest.y = currentY - 1;
                Room roomTwo(roomVect[i+1]);
                if(intersectsRoom(roomTwo, coordTest) && (currentX != roomTwo._x1 && currentX != roomTwo._x2)) {
                    endY = roomTwo._y2;
                    endCoord.y = roomTwo._y2;
                }
                
                if(coordinateIntersectsRoomBounds(roomVect, coordTest) && !coordsAreEqual(coordTest, endCoord)) {
                    bool canMoveUp = false;
                    while(!canMoveUp) {
                        ++iteration;
                        int test = coordVect.size();
                        
                        coordTest.x = currentX - 1;
                        coordTest.y = currentY;
                        Room roomTwo(roomVect[i+1]);
                        if(intersectsRoom(roomTwo, coordTest) && (currentX != roomTwo._x1 && currentX != roomTwo._x2)) {
                            endY = coordTest.y;
                            endCoord.y = coordTest.y;
                            endX = coordTest.x;
                            endCoord.x = coordTest.x;
                            break;
                        }
                        
                        currentX--;
                        coord.x = currentX;
                        coord.y = currentY;
                        coordVect.push_back(coord);
                                    
                        coordTest.x = currentX;
                        coordTest.y = currentY - 1;
                        if(!coordinateIntersectsRoomBounds(roomVect, coordTest) || (coordinateIntersectsRoomBounds(roomVect, coordTest) && coordsAreEqual(coordTest, endCoord)))
                            canMoveUp = true;
                
                        if(test > 4 && coordsAreEqual(coordVect[test], coordVect[test - 2]) &&  coordsAreEqual(coordVect[test - 1], coordVect[test - 3]))
                            throw(PATHFINDING_STUCK);
                        
                        if(test > 4 && coordsAreEqual(coordVect[test], coordVect[test - 4]) &&  coordsAreEqual(coordVect[test - 1], coordVect[test - 3]))
                            throw(PATHFINDING_STUCK);
                        
                        if(pathIsInsideRoomBounds(roomVect, coord))
                            throw(PATH_INSIDE_ROOM);
                    }
                }
                --currentY;
                didMove = true;
            } else if((currentX < endX || currentX > endX) && currentY == endY) {   //###########################################################//
                coordTest.x = currentX;
                (directionTwo == 1) ? coordTest.y = currentY + 1 : coordTest.y = currentY - 1;
                if(hasVisitedPoint(coordVect, coordTest)) {
                    ++iteration;
                    continue;
                } else if(coordinateIntersectsRoomBounds(roomVect, coordTest) && !coordsAreEqual(coordTest, endCoord)) {
                    ++iteration;
                    continue;
                }
                (directionTwo == 1) ? currentY += 1 : currentY -= 1;
                
                didMove = true;
            }
            coord.x = currentX;
            coord.y = currentY;
            coordVect.push_back(coord);
            
            int test = coordVect.size();

            if(test > 4 && coordsAreEqual(coordVect[test], coordVect[test - 2]) &&  coordsAreEqual(coordVect[test - 1], coordVect[test - 3]))
                throw(PATHFINDING_STUCK);
            
            if(test > 4 && coordsAreEqual(coordVect[test], coordVect[test - 4]) &&  coordsAreEqual(coordVect[test - 1], coordVect[test - 3]))
                throw(PATHFINDING_STUCK);
            
            if(pathIsInsideRoomBounds(roomVect, coord))
                throw(PATH_INSIDE_ROOM);
            
            ++iteration;
            
            continue;
        }
    }
    
    return coordVect;
}

bool RoomManager::hasVisitedPoint(std::vector<CoordPairs> coordVect, CoordPairs coord) {
    if(coordVect.size() == 0)
        return false;
    
    for(int i = 0; i < coordVect.size(); i++) {
        if(coordVect[i].x == coord.x && coordVect[i].y == coord.y)
            return true;
    }
    
    return false;
}

CoordPairs RoomManager::placeEntityInRoom(void) {
    int room = genRoomChoice(0, roomVect.size() - 1);
    
    CoordPairs coord;
    coord.y = genRandomPoint(roomVect[room]._y1 + 1, roomVect[room]._y2 - 1);
    coord.x = genRandomPoint(roomVect[room]._x1 + 1, roomVect[room]._x2 - 1);
    
    return coord;
}

int RoomManager::roomPointIsIn(CoordPairs coord) {
    int room = -1;
    
    for(int i = 0; i < roomVect.size() - 1; i++) {
        if(pointIsInsideRoomBounds(coord, roomVect[i])) {
            room = i;
            return room;
        }
    }
    return room;
}

bool RoomManager::pointIsInsideRoomBounds(CoordPairs coord, Room room) {
    if(coord.x > room._x1 && coord.x < room._x2 && coord.y > room._y1 && coord.y < room._y2)
        return true;
    else
        return false;
}

bool RoomManager::coordinateIntersectsRoomBounds(std::vector<Room> roomVect, CoordPairs coord) {
    CoordPairs roomCoord;
    for(int i = 0; i < roomVect.size(); i++) {
        for(int j = roomVect[i]._x1; j < roomVect[i]._x2 + 1; j++) {
            roomCoord.x = j;
            roomCoord.y = roomVect[i]._y1;
            if(coordsAreEqual(coord, roomCoord))
                return true;
            roomCoord.y = roomVect[i]._y2;
            if(coordsAreEqual(coord, roomCoord))
                return true;
        }
    
        for(int j = roomVect[i]._y1; j < roomVect[i]._y2 + 1; j++) {
            roomCoord.x = roomVect[i]._x1;
            roomCoord.y = j;
            if(coordsAreEqual(coord, roomCoord))
                return true;
            roomCoord.x = roomVect[i]._x2;
            if(coordsAreEqual(coord, roomCoord))
                return true;
        }
    }
    
    return false;
}

bool RoomManager::intersectsRoom(Room room, CoordPairs coord) {
    CoordPairs roomCoord;
    for(int j = room._x1; j < room._x2 + 1; j++) {
        roomCoord.x = j;
        roomCoord.y = room._y1;
        if(coordsAreEqual(coord, roomCoord))
            return true;
        roomCoord.y = room._y2;
        if(coordsAreEqual(coord, roomCoord))
            return true;
    }
    
    for(int j = room._y1; j < room._y2 + 1; j++) {
        roomCoord.x = room._x1;
        roomCoord.y = j;
        if(coordsAreEqual(coord, roomCoord))
            return true;
        roomCoord.x = room._x2;
        if(coordsAreEqual(coord, roomCoord))
            return true;
    }
    
    return false;
}
                          
int RoomManager::roomThatPointIntersects(std::vector<Room> roomVect, CoordPairs coord) {
    CoordPairs roomCoord;
    for(int i = 0; i < roomVect.size(); i++) {
        for(int j = roomVect[i]._x1; j < roomVect[i]._x2 + 1; j++) {
            roomCoord.x = j;
            roomCoord.y = roomVect[i]._y1;
            if(coordsAreEqual(coord, roomCoord))
                return i;
            roomCoord.y = roomVect[i]._y2;
            if(coordsAreEqual(coord, roomCoord))
                return i;
        }
        
        for(int j = roomVect[i]._y1; j < roomVect[i]._y2 + 1; j++) {
            roomCoord.x = roomVect[i]._x1;
            roomCoord.y = j;
            if(coordsAreEqual(coord, roomCoord))
                return i;
            roomCoord.x = roomVect[i]._x2;
            if(coordsAreEqual(coord, roomCoord))
                return i;
        }
    }
    
    return -1;
}

//Simple function to generate start and end of the path connecting two rooms
//
CoordPairs RoomManager::genPathfindPoints(int direction, const Room& room) {
    uint8_t X;
    uint8_t Y;
    
    if(direction == 1) {
        X = genRandomPoint(room._p1.x + 1, room._p2.x - 1);
        Y = room._p1.y;
    } else if(direction == 2) {
        X = genRandomPoint(room._p3.x + 1, room._p4.x - 1);
        Y = room._p3.y;
    } else if(direction == 3) {
        Y = genRandomPoint(room._p2.y + 1, room._p4.y - 1);
        X = room._p2.x;
    } else if(direction == 4) {
        Y = genRandomPoint(room._p1.y + 1, room._p3.y - 1);
        X = room._p1.x;
    }
    
    return CoordPairs{X, Y};
}


bool RoomManager::pathIsInsideRoomBounds(std::vector<Room> roomVect, CoordPairs coord) {
    for(int i = 0; i < roomVect.size(); i++) {
        if(coord.x > roomVect[i]._x1 && coord.x < roomVect[i]._x2 && coord.y > roomVect[i]._y1 && coord.y < roomVect[i]._y2)
            return true;
    }
    return false;
}

int RoomManager::roomPlayerIsIn(CoordPairs coord) {
    for(int i = 0; i < roomVect.size() - 1; i++) {
        if(coord.x > roomVect[i]._x1 && coord.x < roomVect[i]._x2 && coord.y > roomVect[i]._y1 && coord.y < roomVect[i]._y2)
            return i;
    }
    return  - 1;
}

int RoomManager::roomEntityIsIn(CoordPairs coord) {
    for(int i = 0; i < roomVect.size() - 1; i++) {
        if(coord.x > roomVect[i]._x1 && coord.x < roomVect[i]._x2 && coord.y > roomVect[i]._y1 && coord.y < roomVect[i]._y2)
            return i;
    }
    return  - 1;
}

bool RoomManager::pointIsOnPath(CoordPairs entityCoord) {
    for(int i = 0; i < coordVect.size(); i++) {
        if(coordsAreEqual(entityCoord, coordVect[i]))
            return true;
    }
    return false;
}

const std::vector<Room> RoomManager::getRoomVect(void) {
    return roomVect;
}

const std::vector<CoordPairs> RoomManager::getCoordVect(void) {
    return coordVect;
}

void RoomManager::EOL_data_cleanup(void) {
    roomVect.clear();
    coordVect.clear();
}
