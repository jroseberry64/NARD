#include "Entity.hpp"

Entity::Entity(CoordPairs loc,char sprite) :
	_loc(loc),
	_sprite(sprite) { };

Entity::Entity(CoordPairs loc,char sprite,bool visible,bool permeable) :
	_loc(loc),
	_sprite(sprite),
	_visible(visible),
	_permeable(permeable) { };


//Setters of Katan
void Entity::loc(const CoordPairs &loc) {
	this->_loc = loc;
}
void Entity::sprite(const char &sprite) {
	this->_sprite = sprite;
}
void Entity::visible(const bool &visible) {
	this->_visible = visible;
}
void Entity::permeable(const bool &permeable) {
	this->_permeable = permeable;
}
