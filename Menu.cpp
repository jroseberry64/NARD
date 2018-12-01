#include "Menu.hpp"

char *Logo[] = {
    "      /---\\-\\    /---/-/  /-----\\-\\      |---------\\-\\    |---------\\-\\  ",
    "     /     \\~\\  /   /~/  /   --  \\~\\     |   _____  \\~\\   |  ------  \\~\\ ",
    "    /   _   \\~\\/   /~/  /   /  \\  \\~\\    |   ||__|  |~|   |  ||   |  |-| ",
    "   /   /~\\   \\/   /~/  /   /----\\  \\~\\   |    ___   /-/   |  ||   |  |~| ",
    "  /   /~/ \\      /~/  /   _______   \\~\\  |   |~| \\  \\~\\   |  ||   |  |~| ",
    " /   /~/   \\    /~/  /   /~/     \\   \\~\\ |   |~|  |  \\~\\  |  ------  /~/ ",
    "/---/-/     \\--/-/  /___/_/       \\___\\_\\|___|_|  |___\\_\\ |_________/-/  ",
};

Menu::Menu(/*std::vector<char*> menu_contents, std::vector<Entity> menu_items,*/ const int menu_type) {
    //_menu_contents = menu_contents;
    //_menu_items = menu_items;
    
    if(menu_type < 1 || menu_type > 3) {
        printf("Bad Menu Type. Exiting Program");
        exit(1);
        
    }
    
    _menu_type = menu_type;
    
    switch(_menu_type) {
        case MAIN_MENU:
            icon.ptr_icon[0] = '-';
            icon.ptr_icon[1] = '>';
            icon.ptr_icon[2] = '\0';
            icon.coord.x = 19;
            icon.coord.y = 11;
        case INVENTORY_MENU:
            icon.ptr_icon[0] = '-';
            icon.ptr_icon[1] = '>';
            icon.ptr_icon[2] = '\0';
            break;
        default:
            break;
    }
}

void Menu::runMenu(void) {
    bool selection_complete = false;
    char input;
    
    switch(this->_menu_type) {
        case MAIN_MENU:
            this->printMenu();
            while(!selection_complete) {
                input = this->pollInput();
                int menu_action = this->processInput(input);
                if(menu_action == -1) {
                    this->printMenu();
                    continue;
                } else if(menu_action == MENU_ACTION_LOAD_SAVE_GAME) {
                    set_flag(SAVE_FLAG);
                    selection_complete = true;
                } else if(menu_action == MENU_ACTION_START_NEW_GAME) {
                    set_flag(LEVEL_COMPLETE_FLAG);
                    selection_complete = true;
                }
            }
            this->cleanupMenu();
            break;
        case INVENTORY_MENU:
            break;
        case GAME_OVER_MENU:
            break;
    }
}

void Menu::printMenu(void) {
    switch(this->_menu_type) {
        case MAIN_MENU:
            for(int i = 0; i < 7; i++) {
                move(i,0);
                printw("%s", Logo[i]);
            }
            move(8, 0);
            printw("\t  Welcome to NARD, the awesome Retro DungeonCrawler");
            move(9, 0);
            printw("\t\t\t Please make a selection");
            move(11,0);
            printw("\t\t        \t NEW GAME");
            move(12, 0);
            printw("\t\t        \tSAVED GAME");
            move(icon.coord.y, icon.coord.x);
            printw("%s", icon.ptr_icon);
            break;
        case INVENTORY_MENU:
            break;
        case GAME_OVER_MENU:
            break;
    }
}

char Menu::pollInput(void) {
    char input = getch();
    return input;
}

int Menu::processInput(char input) {
    switch(input) {
        case 'w':
            switch(this->_menu_type) {
                case MAIN_MENU:
                    if(this->icon.coord.y == 11) {
                        break;
                    } else {
                        --this->icon.coord.y;
                        return -1;
                    }
                    break;
                case INVENTORY_MENU:
                    break;
                case GAME_OVER_MENU:
                    break;
                default:
                    break;
            }
            break;
        case 's':
            switch(this->_menu_type) {
                case MAIN_MENU:
                    if(this->icon.coord.y == 12)
                        break;
                    else {
                        ++this->icon.coord.y;
                        return -1;
                    }
                    break;
                case INVENTORY_MENU:
                    break;
                case GAME_OVER_MENU:
                    break;
                default:
                    break;
            }
            break;
        case 0xA:        //Enter character
            switch(this->_menu_type) {
                case MAIN_MENU:
                    if(this->icon.coord.y == 11)
                        return 1;
                    else if(this->icon.coord.y == 12)
                        return 2;
                    break;
                default:
                    return -1;
                    break;
            }
        default:
            return -1;
            break;
    }
    return -1;
}

void Menu::cleanupMenu(void) {
    erase();
}

