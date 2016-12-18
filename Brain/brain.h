#include <stdlib.h>
#include <string.h>

#include "header.h"

const int max_x = MAX_X;
const int max_y = MAX_Y;



void init() {
	printf("Init\n");
	int i;

	monster_map = (char**)malloc(max_y*sizeof(char*));
	for(i = 0; i < max_y; i++) {
		monster_map[i] = (char*)malloc(max_x*sizeof(char));
		memcpy( monster_map[i], map[i], max_x*sizeof(char));
	}

	printf("Monster map copied\n");

	treasure_db = (treasure*)malloc(sizeof(treasure));
	monster_db = (monster*)malloc(sizeof(monster));
	scan_for_treasures(treasure_db);
	scan_for_monsters(monster_db);

	printf("Init done\n");
	return;
}
