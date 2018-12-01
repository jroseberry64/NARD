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

#ifndef MENU_HPP
#define MENU_HPP


#define MAIN_MENU 			1
#define INVENTORY_MENU 		2
#define GAME_OVER_MENU		3
//Any others we think of later

#define MENU_ACTION_START_NEW_GAME 1
#define MENU_ACTION_LOAD_SAVE_GAME 2

#include <vector>
#include <cstdlib>
#include "InitNcurses.hpp"
#include "CoordPairs.hpp"
#include "Flags.hpp"

struct MenuPtrIcon {
	char ptr_icon[3];
	CoordPairs coord;
};

//class Entity;

class Menu {
	
	public:
		Menu(/*std::vector<char*> menu_contents, std::vector<Entity> menu_items, */ const int menu_type);
		Menu() = default;
		~Menu() = default;
		
		void runMenu(void);
	
	private:
		//std::vector<char*> _menu_contents;
		//std::vector<Entity> _menu_items;
		int _menu_type;
		MenuPtrIcon icon;
		
		void printMenu(void);
		char pollInput(void);
		int processInput(char input);
		void cleanupMenu(void);
};

#endif
