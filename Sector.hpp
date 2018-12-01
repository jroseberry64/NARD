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

#ifndef SECTOR_HPP
#define SECTOR_HPP

#include "CoordPairs.hpp"
#include <stdint.h>

//_x1 and _y1 need to be equal when a partition splits, so that the
//only thing that changes is the height or the
struct Sector {
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
