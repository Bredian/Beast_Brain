

#include "header.h"

void do_next_step(int cur_x, int cur_y, int *command) {
	static int treas;
	static path traced_path;
	static int have_path = 0, done_init = 0, step = -1, alarm = 0;

	point location;

	*command = 5;



	if( !done_init ) {		//initialization and refreshing routines
		init();
		done_init = 1;
	}
	refresh_monster_db(monster_db, monster_map);
	refresh_treasure_db(treasure_db, main_map);
	main_map = (char**)map;
	location.x = cur_x;
	location.y = cur_y;


	if( !have_path ) {		//calculating path if already don't have one
		
		treas = wave_scan_to_dist(location, 15, main_map);
		monster_zones_update(monster_map, monster_db);
	
		if(treas.x != -1) {
			traced_path = trace_with_monsters(treas, main_map);
		}
	}


	if( cur_x != traced_path[step].x )		//doing step
		if( cur_x > traced_path[step].x )
			*command = 1;
		else
			*command = 3;
	else if( cur_y > traced_path[step].y )
			*command = 4;
		else
			*command = 2;


	return;
}
