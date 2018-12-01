#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <stdint.h>
#include "CoordPairs.hpp"

class Entity {
public:
	Entity() = default; 
	~Entity() = default;
	Entity(CoordPairs,char);
	Entity(CoordPairs,char,bool,bool);

	//Getters
	CoordPairs loc() const noexcept { return _loc; }
	char sprite() const noexcept { return _sprite; }
	bool visible() const noexcept { return _visible; }
	bool permeable() const noexcept { return _permeable; }

	//Setters
	void loc(const CoordPairs&);
	void sprite(const char&);
	void visible(const bool&);
	void permeable(const bool&);
private:
	CoordPairs _loc;
	char _sprite;
	//non static member initialization
	bool _visible = true;
	bool _permeable = false;
};

#endif
