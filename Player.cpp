#include "Player.hpp"

Player::Player() {
    //Entity Setters
	//this.loc(const CoordPairs&);
	this->sprite('@');
	this->visible(true);
	this->permeable(true);
    //Character Setters
    this->health(10);
	this->hp(10);
	this->armor(0);
	this->strength(1);
}

//Getters
const uint8_t Player::level() const noexcept {
    return this->_level;
}

//Setters
void Player::ding() noexcept {
    ++_level;
    this->health(health()+5);       //Increase max hp by 5
    this->hp(health());             //Full heal when dings
    this->strength(strength()+1);   //Increase str by 1
}