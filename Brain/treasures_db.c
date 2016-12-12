#include <stdlib.h>
#include "header.h"

void scan_for_treasures(treasure* treasure_db, char **map) {
	int i, j;
	number_of_treasures = 0;
	for(i = 0; i < max_y; i++) {
		for(j = 0; j < max_x; j++) {
			if( map[i][j] == '*' ) {
				number_of_treasures++;
				treasure_db = realloc(treasure_db, number_of_treasures*sizeof(treasure));
				treasure_db[number_of_treasures].x = j;
				treasure_db[number_of_treasures].y = i;
				treasure_db[number_of_treasures].exist = 1;
			}
		}
	}
	return;
}

void refresh_treasure_db(treasure* treasure_db, char **map){
	int i;
	for(i = 0; i < number_of_treasures; i++)
		if( map[treasure_db[i].y][treasure_db[i].x] != '*' ) treasure_db[i].exist = 0;
	return;
}

int find_nearest_treasure(point from, treasure* treasure_db) {
	int i, number_of_nearest = 0, min;
	min = (treasure_db[0].x - from.x) * (treasure_db[0].x - from.x) + (treasure_db[0].y - from.y) * (treasure_db[0].y - from.y);
	for(i = 0; i < number_of_treasures; i++) {
		if(treasure_db[i].exist == 0) continue;
		if((treasure_db[i].x - from.x) * (treasure_db[i].x - from.x) + (treasure_db[i].y - from.y) * (treasure_db[i].y - from.y) < min) {
			min = (treasure_db[i].x - from.x) * (treasure_db[i].x - from.x) + (treasure_db[i].y - from.y) * (treasure_db[i].y - from.y);
			number_of_nearest = i;
		}
	}
	return number_of_nearest;
}
