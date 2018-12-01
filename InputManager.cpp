#include "InputManager.hpp"
#include <ncurses.h>

InputManager* InputManager::input_manager = nullptr;

char InputManager::getInput(void) {
	return this->input;
}

void InputManager::pollInput(void) {
	do {
		input = getch();
	} while(!validInput());
}


bool InputManager::validInput(void) {
	switch(this->input) {
		case UP_KEY_LOWER:
		case UP_KEY_UPPER:
		case DOWN_KEY_LOWER:
		case DOWN_KEY_UPPER:
		case LEFT_KEY_LOWER:
		case LEFT_KEY_UPPER:
		case RIGHT_KEY_LOWER:
		case RIGHT_KEY_UPPER:
		case INVENTORY_MENU_KEY_LOWER:
		case INVENTORY_MENU_KEY_UPPER:
			return true;
			break;
		default:
			return false;
			break;
	}
	return false;
}
