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

#include "RenderingEngine.hpp"

RenderingEngine* RenderingEngine::Renderer = nullptr;

RenderingEngine::RenderingEngine(void) {
	initNcurses();
}

RenderingEngine::~RenderingEngine(void) {
	cleanUpNcurses();
}

void RenderingEngine::updateWindow(void) {
	refresh();
}

/* Some basic draw functions that will get moved later */

void RenderingEngine::printRoom(bool isInRoom, Room& room) {
	this->printTopHorizontalLine(room);
	this->printBottomHorizontalLine(room);
	this->printLeftVerticalLine(room);
	this->printRightVerticalLine(room);
	
	if(isInRoom) {
		for(int i = 0; i < room._dy - 1; i++) {
			move(room._p1.y + (1 + i), room._p1.x + 1);
			hline('.', room._dx - 1);
		}
    } else {
        for(int i = 0; i < room._dy - 1; i++) {
            move(room._p1.y + (1 + i), room._p1.x + 1);
            hline(' ', room._dx - 1);
        }
    }
}

void RenderingEngine::printTopHorizontalLine(Room &room) {
	move(room._p1.y, room._p1.x + 1);
	hline('=', room._dx - 1);
}

void RenderingEngine::printBottomHorizontalLine(Room &room) {
	move(room._p3.y, room._p3.x + 1);
	hline('=', room._dx - 1);
}

void RenderingEngine::printLeftVerticalLine(Room &room) {
	move(room._p1.y, room._p1.x);
	vline('|', room._dy + 1);
}
void RenderingEngine::printRightVerticalLine(Room &room) {
	move(room._p2.y, room._p2.x);
	vline('|', room._dy + 1);
}

void RenderingEngine::printEntity(const Entity& entity) {
    CoordPairs placement = entity.loc();
    move(placement.y, placement.x);
    addch(entity.sprite());

}

void RenderingEngine::printPath(CoordPairs& coord) {
    move(coord.y, coord.x);
    addch('#');
}


/* End of draw functions */
