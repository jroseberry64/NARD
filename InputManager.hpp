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

#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#define UP_KEY_LOWER				'w'
#define UP_KEY_UPPER				'W'
#define DOWN_KEY_LOWER				's'
#define DOWN_KEY_UPPER				'S' 
#define LEFT_KEY_LOWER				'a'
#define LEFT_KEY_UPPER				'A'
#define RIGHT_KEY_LOWER				'd'
#define RIGHT_KEY_UPPER				'D'
#define INVENTORY_MENU_KEY_LOWER	'i'
#define INVENTORY_MENU_KEY_UPPER	'I'



class InputManager {
	
	public:
        static InputManager* getInputManagerInstance(void) {
            input_manager = new InputManager;
            return input_manager;
        }
        bool validInput(void);
        char getInput(void);
        void pollInput(void);
		
	private:
		InputManager() = default;
		~InputManager() = default;
		static InputManager *input_manager;
		
		char input;
		
};

#endif
