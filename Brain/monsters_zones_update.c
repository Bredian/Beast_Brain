#include "brain.h"
void monster_zones_update(char (*monster_map)[max_y][max_x], monster* monster_db){
	int i;
	point monster_place;
	for(i = 0; i < number_of_monsters; i++){
		if(monster_db[i].alive == 0) 
			continue;
		monster_place.x = monster_db[i].x;
		monster_place.y = monster_db[i].y;
		wave_scan(monster_place, 5, (*monster_map)[max_y][max_x]);		
	}
	return;
}
