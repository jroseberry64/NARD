#include "Flags.hpp"

uint8_t global_flags = 0;

bool flag_is_set(uint8_t flag) {
	uint8_t flagState = global_flags;
	uint8_t testFlag;
	
	switch(flag) {
		case SAVE_FLAG:
			testFlag = flagState & SAVE_FLAG;
			return (testFlag == 1) ? true : false;
			break;
		case LEVEL_COMPLETE_FLAG:
			testFlag = flagState & LEVEL_COMPLETE_FLAG;
			return (testFlag == 2) ? true : false;
			break;
		case PLAYER_DEATH_FLAG:
			testFlag = flagState & PLAYER_DEATH_FLAG;
			return (testFlag == 4) ? true : false;
			break;
		case BOSS_LEVEL_FLAG:
			testFlag = flagState & BOSS_LEVEL_FLAG;
			return (testFlag == 8) ? true : false;
			break;
		case PLAYER_TURN_FLAG:
			testFlag = flagState & PLAYER_TURN_FLAG;
			return (testFlag == 16) ? true : false;
			break;
		case ENEMY_TURN_FLAG:
			testFlag = flagState & ENEMY_TURN_FLAG;
			return (testFlag == 32) ? true : false;
			break;
		case MENU_SELECTED_FLAG:
			testFlag = flagState & MENU_SELECTED_FLAG;
			return (testFlag == 64) ? true : false;
			break;
		case LEVEL_GENERATION_ERROR_FLAG:
			testFlag = flagState & LEVEL_GENERATION_ERROR_FLAG;
			return (testFlag == 128) ? true : false;
			break;
		default:
			return false;
			break;
	}
}

void set_flag(uint8_t flag) {
	
	switch(flag) {
		case SAVE_FLAG:
			global_flags = global_flags | SAVE_FLAG;
			break;
		case LEVEL_COMPLETE_FLAG:
			global_flags = global_flags | LEVEL_COMPLETE_FLAG;
			break;
		case PLAYER_DEATH_FLAG:
			global_flags = global_flags | PLAYER_DEATH_FLAG;
			break;
		case BOSS_LEVEL_FLAG:
			global_flags = global_flags | BOSS_LEVEL_FLAG;
			break;
		case PLAYER_TURN_FLAG:
			global_flags = global_flags | PLAYER_TURN_FLAG;
			break;
		case ENEMY_TURN_FLAG:
			global_flags = global_flags | ENEMY_TURN_FLAG;
			break;
		case MENU_SELECTED_FLAG:
			global_flags = global_flags | MENU_SELECTED_FLAG;
			break;
		case LEVEL_GENERATION_ERROR_FLAG:
			global_flags = global_flags | LEVEL_GENERATION_ERROR_FLAG;
			break;
		default:
			break;
	}		
}

void unset_flag(uint8_t flag) {
	
	switch(flag) {
		case SAVE_FLAG:
			if(flag_is_set(SAVE_FLAG))
				global_flags = global_flags ^ SAVE_FLAG;
			break;
		case LEVEL_COMPLETE_FLAG:
			if(flag_is_set(LEVEL_COMPLETE_FLAG))
				global_flags = global_flags ^ LEVEL_COMPLETE_FLAG;
			break;
		case PLAYER_DEATH_FLAG:
			if(flag_is_set(PLAYER_DEATH_FLAG))
				global_flags = global_flags ^ PLAYER_DEATH_FLAG;
			break;
		case BOSS_LEVEL_FLAG:
			if(flag_is_set(BOSS_LEVEL_FLAG))	
				global_flags = global_flags ^ BOSS_LEVEL_FLAG;
			break;
		case PLAYER_TURN_FLAG:
			if(flag_is_set(PLAYER_TURN_FLAG))
				global_flags = global_flags ^ PLAYER_TURN_FLAG;
			break;
		case ENEMY_TURN_FLAG:
			if(flag_is_set(ENEMY_TURN_FLAG))	
				global_flags = global_flags ^ ENEMY_TURN_FLAG;
			break;
		case MENU_SELECTED_FLAG:
			if(flag_is_set(MENU_SELECTED_FLAG))
				global_flags = global_flags ^ MENU_SELECTED_FLAG;
			break;
		case LEVEL_GENERATION_ERROR_FLAG:
			if(flag_is_set(LEVEL_GENERATION_ERROR_FLAG))
				global_flags = global_flags ^ LEVEL_GENERATION_ERROR_FLAG;
			break;
		default:
			break;
	}
}