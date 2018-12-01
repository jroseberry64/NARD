#include "Character.hpp"
#include <iostream> //remove after testing

//Constructor
Character::Character(CoordPairs loc) :
	Entity::Entity(loc,'C') {
	_hp = _health;
}

//Setters
void Character::health(const unsigned short &hp) {
	_health = hp;
}
void Character::hp(const unsigned short &hp) {
	_hp = hp;
}
void Character::armor(const uint8_t &armor) {
   _armor = armor;
}
void Character::strength(const uint8_t &str) {
  _strength = str;
}
void Character::die() {
	if(!_dead) {
		_dead = true;
	} 	
}

//Put gaurds for underflow
Character& Character::operator++(){
	++_hp;
	return *this;
}
const Character Character::operator++(int){
	Character temp = *this;
	++(*this);
	return temp;
}
Character& Character::operator--(){
	if(!_hp) {
		return *this;
	} else {
		--_hp;
		if(!_hp) {
			_dead = true;
		}
		return *this;
	}
}
const Character Character::operator--(int){
	Character temp = *this;
	--(*this);
	return temp;
}

//Attack function
void Character::attack(Character *target) const {
	//             target hp - (attacking char strength - target armor)
	target->hp( target->hp() - (_strength-target->armor()) );
	//Prevent underflow with this one simple trick
	if (target->hp() > target->health()) {
		target->hp(0);
	}
	//Programmers hate him!

	// Sets death to true if nescessary
	if (target->hp() == 0) {
		target->die();
	}
}