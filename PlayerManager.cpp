#include "PlayerManager.hpp"
#include "GPRandNumGenerator.hpp"

PlayerManager* PlayerManager::playerManager = nullptr;

PlayerManager::PlayerManager(void) {
    _player.health(15);
    _player.hp(_player.health());
    _player.sprite('@');
    _current_exp = 0;
    _level_up_exp = 10;
}

const unsigned short PlayerManager::getPlayerCurrentHP(void) {
	return _player.hp();
}

const unsigned short PlayerManager::getPlayerCurrentHealth(void) {
    return _player.health();
}

const uint8_t PlayerManager::getPlayerArmor(void) {
	return _player.armor();
}

const uint8_t PlayerManager::getPlayerStrength(void) {
	return _player.strength();
}

const char PlayerManager::getPlayerSprite(void) {
	return _player.sprite();
}

const CoordPairs PlayerManager::getPlayerLocation(void) {
	return _player.loc();
}

const bool PlayerManager::getPlayerVisibility(void) {
	return _player.visible();
}

const bool PlayerManager::getPlayerPermeability(void) {
	return _player.permeable();
}

Character& PlayerManager::getPlayer(void) {
    return _player;
}

void PlayerManager::setPlayerRoom(Room& room) {
    _current_room = &room;
}

bool PlayerManager::playerInRoom(void) {
    return (_current_room != nullptr);
}

void PlayerManager::setPlayerRoomToNull(void) {
    _current_room = nullptr;
}

uint8_t PlayerManager::playerRoom_y1(void) {
    if(_current_room == nullptr) {
        throw(std::runtime_error("Player room is currently null\n"));
    } else {
        return _current_room->_y1;
    }
}

uint8_t PlayerManager::playerRoom_y2(void) {
    if(_current_room == nullptr) {
        throw(std::runtime_error("Player room is currently null\n"));
    } else {
        return _current_room->_y2;
    }
}

uint8_t PlayerManager::playerRoom_x1(void) {
    if(_current_room == nullptr) {
        throw(std::runtime_error("Player room is currently null\n"));
    } else {
        return _current_room->_x1;
    }
}

uint8_t PlayerManager::playerRoom_x2(void) {
    if(_current_room == nullptr) {
        throw(std::runtime_error("Player room is currently null\n"));
    } else {
        return _current_room->_x2;
    }
}

void PlayerManager::attack(Character *enemy) {
    _player.attack(enemy);
}

void PlayerManager::movePlayer(int direction) {
    CoordPairs newCoord = getPlayerLocation();
    switch(direction) {
        case NORTH:
            newCoord.y -= 1;
            _player.loc(newCoord);
            break;
        case SOUTH:
            newCoord.y += 1;
            _player.loc(newCoord);
            break;
        case WEST:
            newCoord.x -= 1;
            _player.loc(newCoord);
            break;
        case EAST:
            newCoord.x += 1;
            _player.loc(newCoord);
            break;
    }
}

void PlayerManager::setPlayerLocation(CoordPairs coord) {
    _player.loc(coord);
}

void PlayerManager::addExp(int exp) {
    _current_exp += exp;
    if(levelUpConditionsMet()) {
        levelUp();
        setNewExp();
    }
}

void PlayerManager::levelUp(void) {
    _player.ding();
}

bool PlayerManager::levelUpConditionsMet(void) {
    if(_level_up_exp == _current_exp)
        return true;
    else
        return false;
}

void PlayerManager::setNewExp(void) {
    _level_up_exp = _level_up_exp * RandNumGenerator::genRandNumber(3, 5) / 2;
}

int PlayerManager::getExp(void) {
    return _current_exp;
}
