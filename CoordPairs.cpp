#include "CoordPairs.hpp"

CoordPairs::CoordPairs(uint8_t _x, uint8_t _y) {
    x = _x;
    y = _y;
}

bool coordsAreEqual(CoordPairs coordOne, CoordPairs coordTwo) {
	return (coordOne.x == coordTwo.x && coordOne.y == coordTwo.y);
}
