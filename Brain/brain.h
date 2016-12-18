#include <stdlib.h>
#include <string.h>

#include "header.h"


void init() {
	extern char map[MAX_Y][MAX_X];
	printf("Init\n");
	int i;

	monster_map = (char**)malloc(MAX_Y*sizeof(char*));
	for(i = 0; i < MAX_Y; i++) {
		monster_map[i] = (char*)malloc(MAX_X*sizeof(char));
		memcpy( monster_map[i], map[i], MAX_X*sizeof(char));
	}

	printf("Monster map copied\n");

	treasure_db = (treasure*)malloc(sizeof(treasure));
	monster_db = (monster*)malloc(sizeof(monster));
	//~ treasure_db = NULL;
	//~ monster_db = NULL;
	
	scan_for_treasures(treasure_db);
	scan_for_monsters(monster_db);

	printf("Init done\n");
	return;
}
