#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Entity.hpp"

class Character : public Entity {
public:
	Character() = default;
	~Character() = default;
	Character(CoordPairs);

	Character(Character&& rhs) = default;                   // Copy constructor
	Character(const Character& rhs) = default;              // Move constructor
	Character& operator= (const Character& rhs) = default;  // Copy assignment overload
	Character& operator= (Character&& rhs) = default;       // Move assignment overload

	//Getters
	const unsigned short health() const { return _health; }
	const unsigned short hp() const { return _hp; }
	const uint8_t armor() const { return _armor; }
	const uint8_t strength() const { return _strength; }
	const bool is_dead() const { return _dead; }
	//Setters
	void health(const unsigned short&);
	void hp(const unsigned short&);
	void armor(const uint8_t&);
	void strength(const uint8_t&);
	void die();

	Character& operator++();
	const Character operator++(int);
	Character& operator--();
	const Character operator--(int);

	void attack(Character *target) const;

private:
	//stats
	unsigned short _health = 10;
	unsigned short _hp = _health;
	uint8_t _strength = 1;
	uint8_t _armor = 0;
	bool _dead = false;
};

#endif
