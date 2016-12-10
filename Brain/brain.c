#include <stdlin.h>
#include "brain.h"

void init(){
	memcpy(monster_map, map, max_y * max_x * sizeof(char));
	treasure_db = NULL;
	monster_db = NULL;
	scan_for_treasures(treasure_db,map);
	scan_for_monsters(monster_db,map);	
}

void do_next_step(int cur_x, int cur_y, int *command) {
	
	return;
}
