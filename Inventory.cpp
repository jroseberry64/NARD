#include "Inventory.hpp"
#include "CoordPairs.hpp" //for coordpairs, remove after tests

CoordPairs zero = {0,0};

void Inventory::pickup(Item &pickupItem) {
    _inventory.push_back(pickupItem);
    //change pickup item loc to cursor/offscreen
    pickupItem.loc(zero);
    //possibly change characteristics e.g. permeable
}