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

#include "Room.hpp"

Room::Room() {
	_x1 = 0;
	_x2 = 0;
	_y1 = 0;
	_y2 = 0;
	
	_dx = 0;
	_dy = 0;
	
	_p1.x = 0;
	_p1.y = 0;
	_p2.x = 0;
	_p2.y = 0;
	_p3.x = 0;
	_p3.y = 0;
	_p4.x = 0;
	_p4.y = 0;
}

Room::Room(const Sector& sector) {
	//To make the numbers nicer to divide when we generate the BSP Tree
	//(and to deal with the stupid small numbers that we'll get otherwise)
	//we take the total width and height of the room container and divide
	//it by two, but when we recreate the rooms we have to multiply it
	//back out to get the correct sizes.
	
	int multiple = 2;

	_x1 = sector._x1 * multiple;
	_x2 = sector._x2 * multiple;
	_y1 = sector._y1 * multiple;
	_y2 = sector._y2 * multiple;
	
	_dx = sector._dx * multiple;
	_dy = sector._dy * multiple;
	
	_p1.x = sector._p1.x * multiple;
	_p1.y = sector._p1.y * multiple;
	_p2.x = sector._p2.x * multiple;
	_p2.y = sector._p2.y * multiple;
	_p3.x = sector._p3.x * multiple;
	_p3.y = sector._p3.y * multiple;
	_p4.x = sector._p4.x * multiple;
	_p4.y = sector._p4.y * multiple;
	
}

Room::Room(const Room& room) {
	
	_x1 = room._x1;
	_x2 = room._x2;
	_y1 = room._y1;
	_y2 = room._y2;
	
	_dx = room._dx;
	_dy = room._dy;
	
	_p1.x = room._p1.x;
	_p1.y = room._p1.y;
	_p2.x = room._p2.x;
	_p2.y = room._p2.y;
	_p3.x = room._p3.x;
	_p3.y = room._p3.y;
	_p4.x = room._p4.x;
	_p4.y = room._p4.y;

}


Room::~Room() {
}