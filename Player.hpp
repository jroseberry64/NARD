#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Character.hpp"
#include <string>

class Player : public Character {
public:
    Player();
    ~Player() = default;
    //Getters
    const uint8_t level() const noexcept;
    const std::string name() const noexcept;
    //Setters
    void name(const std::string&);
    //level_up//ding?
    void ding() noexcept;

private:
    //Character name
    std::string _name = "Steve";
    //Level Junk implement experience l8r m8
    uint8_t _level = 1;

};

#endif
