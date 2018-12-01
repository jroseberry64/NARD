#ifndef COORDPAIRS_HPP
#define COORDPAIRS_HPP

#include <stdint.h>

//Useful for drawing the rooms
//change to Coor
struct CoordPairs {
    CoordPairs() = default;
    CoordPairs(uint8_t _x, uint8_t _y);
    uint8_t x;
	uint8_t y;
};

bool coordsAreEqual(CoordPairs coordOne, CoordPairs coordTwo);

#endif
