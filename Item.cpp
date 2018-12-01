#include "Item.hpp"

Item::Item(unsigned short health, uint8_t strength, uint8_t armor) :
    _health(health),
    _strength(strength),
    _armor(armor) {};

const char* Item::name() {
    return _name.c_str();
}

void Item::name(const std::string &name) {
    _name = name;
}
void Item::health(const unsigned short &health) {
    _health = health;
}
void Item::strength(const uint8_t &strength) {
    _strength = strength;
}
void Item::armor(const uint8_t &armor) {
    _armor = armor;
}