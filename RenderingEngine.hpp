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

#ifndef RENDERING_ENGINE_HPP
#define RENDERING_ENGINE_HPP

#include "InitNcurses.hpp"
#include "Entity.hpp"
#include "Room.hpp"

class RenderingEngine {
	public:
		void printRoom(bool isInRoom, Room &room);
		void printEntity(const Entity& entity);
        void printPath(CoordPairs& coord);
		void updateWindow(void);
		
    static RenderingEngine* getRenderingEngineInstance() {
        Renderer = new RenderingEngine();
        return Renderer;
    }
		
		
	private:
		//Calls initNcurses
		RenderingEngine();
		//Calls cleanupNcurses
		~RenderingEngine();
		//Singleton
		static RenderingEngine *Renderer;
		
		
		
		void printTopHorizontalLine(Room& room);
		void printBottomHorizontalLine(Room& room);
		void printLeftVerticalLine(Room& room);
		void printRightVerticalLine(Room& room);
		void printRoomData(Room& room);
};

#endif
