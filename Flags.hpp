#ifndef FLAGS_HPP
#define FLAGS_HPP

#include <stdint.h>

//In order to not have a gazzillion booleans floating around
//the codebase, one 8 bit unsigned integer will store the more
//commonly used boolean values. The use of bitwise operators will
//evaluate whether or not a given flag is set or unset, as well as
//setting and unsetting flags.



#define SAVE_FLAG 						0b00000001
#define LEVEL_COMPLETE_FLAG				0b00000010
#define PLAYER_DEATH_FLAG				0b00000100
#define BOSS_LEVEL_FLAG					0b00001000
#define PLAYER_TURN_FLAG				0b00010000
#define ENEMY_TURN_FLAG					0b00100000
#define MENU_SELECTED_FLAG				0b01000000
#define LEVEL_GENERATION_ERROR_FLAG		0b10000000

bool flag_is_set(uint8_t flag);
void set_flag(uint8_t flag);
void unset_flag(uint8_t flag);



#endif