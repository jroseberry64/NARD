#ifndef ITEM_HPP
#define ITEM_HPP
#include "Entity.hpp"
#include <string>

class Item : public Entity {
public:
    Item() = default;
    Item(unsigned short, uint8_t, uint8_t);
    ~Item() = default;

    Item(Item&& rhs) = default;                   // Copy constructor
	Item(const Item& rhs) = default;              // Move constructor
	Item& operator= (const Item& rhs) = default;  // Copy assignment overload
	Item& operator= (Item&& rhs) = default;       // Move assignment overload

    //Getter
    const char* name();
    //increase health and hp?
    const unsigned short health() const noexcept { return _health; }
	const uint8_t strength() const noexcept { return _strength; }
	const uint8_t armor() const noexcept { return _armor; }
    //Setter
    void name(const std::string&);
    void health(const unsigned short&);
    void strength(const uint8_t&);
    void armor(const uint8_t&);

private:
    //Name
    std::string _name;
    //Attributes
    unsigned short _health = 0;
	uint8_t _strength = 0;
	uint8_t _armor = 0;
    //_sprite = 'I';
};

#endif