#include <stdlib.h>
#include <string.h>

#include "header.h"

void init() {					//TODO: write location finding
	main_map = (char**)map;
	max_x = MAX_X;
	max_y = MAX_Y;
	
	int i;
	monster_map = (char**)malloc(max_y*sizeof(char*));
	for(i = 0; i < max_x; i++) {
		monster_map[i] = (char*)malloc(max_x*sizeof(char));
		memcpy( monster_map[i], main_map[i], max_x*sizeof(char));
	}
	
	treasure_db = NULL;
	monster_db = NULL;
	scan_for_treasures(treasure_db, (char**)map);
	scan_for_monsters(monster_db, (char**)map);	
	return;
}
