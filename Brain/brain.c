

#include "header.h"

void do_next_step(int cur_x, int cur_y, int *command) {
	static int treas;
	static path traced_path;
	static int have_path = 0, done_init = 0;
	
	
	if( !done_init ) {
		init();
		done_init = 1;
	}
	refresh_monster_db(monster_db, monster_map);
	refresh_treasure_db(treasure_db, main_map);
	
	if( !have_path ) {
		
		treas = wave_scan_to_dist(location, 15, main_map);
		monster_zones_update(monster_map, monster_db);
	
		if(treas.x != -1) {
			traced_path = trace_with_monsters(treas, main_map);
		}
	}
	
	
	
	return;
}
