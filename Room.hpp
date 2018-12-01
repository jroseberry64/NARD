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

#ifndef ROOM_HPP
#define ROOM_HPP

#include "Sector.hpp"
#include "CoordPairs.hpp"
#include <stdint.h>

struct Room {
	Room();
	Room(const Sector& sector);
	Room(const Room& room);
	~Room();
	
	unsigned int roomDC;
	
	uint8_t _x1;
	uint8_t _x2;
	uint8_t _y1;
	uint8_t _y2;
	
	uint8_t _dx;
	uint8_t _dy;
	
	CoordPairs _p1;
	CoordPairs _p2;
	CoordPairs _p3;
	CoordPairs _p4;
};

#endif
