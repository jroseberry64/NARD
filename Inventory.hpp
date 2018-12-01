#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#ifndef ITEM_HPP // not sure if this is redundant
#include "Item.hpp"
#endif

#include <vector>
#include <stdint.h>


class Inventory {
public:
	Inventory() = default;
    ~Inventory() = default;

    Inventory(Inventory&& rhs) = default;                   // Copy constructor
	Inventory(const Inventory& rhs) = default;              // Move constructor
	Inventory& operator= (const Inventory& rhs) = default;  // Copy assignment overload
	Inventory& operator= (Inventory&& rhs) = default;       // Move assignment overload
	//Getters
	//Add item using id()
	//Setters
	//add item
	void pickup(Item&);
	
private:
	//Vector of items
	std::vector<Item> _inventory;

};

#endif