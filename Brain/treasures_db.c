#include <stdlib.h>
#include "brain.h"

void scan_for_treasures(treasure* treasure_db, char (*map)[max_y][max_x]) {
	int i, j;
	number_of_treasures = 0;
	for(i = 0; i < max_y; i++) {
		for(j = 0; j < max_x; j++) {
			if( (*map)[i][j] == '*' ) {
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

void refresh_treasure_db(treasure* treasure_db, char (*map)[max_y][max_x]){
	int i;
	for(i = 0; i < number_of_treasures; i++)
		if( (*map)[treasure_db[i].y][treasure_db[i].x] != '*' ) treasure_db[i].exist = 0;
	return;
}
