//
//  InitNcurses.cpp
//  Rogue_Dun_Gen
//
//  Created by Jonathan Roseberry on 8/22/18.
//  Copyright © 2018 Jonathan Roseberry. All rights reserved.
//

#include "InitNcurses.hpp"

void initNcurses(void) {
    initscr();      //Initialize screen
    curs_set(0);    //Makes the cursor invisible
    noecho();       //stops getch from echoing
}

void cleanUpNcurses(void) {
    endwin();
}
