

#include "header.h"

void do_next_step(int cur_x, int cur_y, int *command) {
	static int treas;
	static path traced_path;
	static int have_path = 0, done_init = 0, step = -1, alarm = 0;

	point buf;
	int i;

	*command = 5;



	if( !done_init ) {		//initialization and refreshing routines
		init();
		done_init = 1;
	}
	
	main_map = (char**)map;
	
	if( alarm%5 == 0 )		//copy moster_map from main_map
		for(i = 0; i < max_x; i++) {
			monster_map[i] = (char*)malloc(max_x*sizeof(char));
			memcpy( monster_map[i], main_map[i], max_x*sizeof(char));
		}
	
	refresh_monster_db(monster_db, monster_map);
	refresh_treasure_db(treasure_db, main_map);


	if(treasure_db[treas].exist == 0) have_path = 0;


	if( !have_path || alarm%5 == 0 ) {		//calculating path if already don't have one
		if( have_path == 1 ) {
			buf.x = cur_x;
			buf.y = cur_y;
			wave_scan_to_dist(buf, traced_path.len - steps, main_map);
			
			free( traced_path.steps );
			buf.x = treasure_db[treas].x;
			buf.y = treasure_db[treas].y;
			traced_path = trace_with_monsters( buf, monster_map, main_map);
			
			if( traced_path.len == -1 ) {
				free( traced_path.steps );
				buf.x = treasure_db[treas].x;
				buf.y = treasure_db[treas].y;
				traced_path = trace( buf, main_map);
		}
		steps = 0;
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
	steps++;
	alarm++;

	return;
}
