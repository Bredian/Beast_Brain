#include <stdlib.h>
#include "header.h"

void scan_for_monsters(monster* monster_db) {
	printf("Scanning for monsters\n");
	extern char map[MAX_Y][MAX_X];
	int i, j;
	number_of_monsters = 0;
	for(i = 0; i < MAX_Y; i++) {
		for(j = 0; j < MAX_X; j++) {
			if( map[i][j] == '@' ){
				number_of_monsters++;
				monster_db = realloc(monster_db, number_of_monsters*sizeof(monster));
				monster_db[number_of_monsters - 1].y = i;
				monster_db[number_of_monsters - 1].x = j;
				monster_db[number_of_monsters - 1].alive = 1;
			}
		}
	}
	printf("Done\n");
	return;
}

void refresh_monster_db(monster* monster_db) {
	extern char map[MAX_Y][MAX_X];
	int i, j, x, y;
	int dx[5] = {0, -1, 0, 1, 0};	//step from current position to
	int dy[5] = {0, 0, 1, 0, -1};	//nowhere, left, up, right, down

	for(i = 0; i < number_of_monsters; i++) {
		if(monster_db[i].alive == 0) continue;
 		for(j = 0; j < 5; j++) {
			if( *(*(map + monster_db[i].y + dy[j]) + monster_db[i].x + dx[j]) == '@' ) {
				monster_db[i].x = monster_db[i].x + dx[j];
				monster_db[i].y = monster_db[i].y + dy[j];
				break;
			}
			monster_db[i].alive = 0;
		}
	}
	return;
}

