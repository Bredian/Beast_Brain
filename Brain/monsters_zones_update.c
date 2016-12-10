#include "brain.h"
void monster_zones_update(char (*monster_map)[max_y][max_x], monster* monster_db){
	int i;
	point *monster_place=malloc(number_of_monsters*sizeof(point));
	for(i = 0; i < number_of_monsters; i++){
		if(monster_db[i].alive == 0) 
			continue;
		monster_place[i].x = monster_db[i].x;
		monster_place[i].y = monster_db[i].y;
		wave_scan(point monster_place, 5, (*monster_map)[max_y][max_x]);		
	}
	return;
}
