#include <stdlib.h>
#include <string.h>

#include "header.h"

void do_next_step(int cur_x, int cur_y, int *command) {
	extern char map[MAX_Y][MAX_X];
	static int treas;
	static path traced_path;
	static int have_path = 0, done_init = 0, step = -1, alarm = 0;

	point buf, buf1;
	int i;

	*command = 5;
	traced_path.len = -2;	//to determine whether memory has been allocated


	if( !done_init ) {		//initialization and refreshing routines
		init();
		done_init = 1;
	}
	else 
		if(treasure_db[treas].exist == 0) have_path = 0;

	
	if( alarm%5 == 0 )		//copy moster_map from main_map
		for(i = 0; i < MAX_Y; i++)
			memcpy( monster_map[i], map[i], MAX_X*sizeof(char));
	
	refresh_monster_db(monster_db);
	refresh_treasure_db(treasure_db);


	printf("Main loop started\n");


	if( (!have_path) || (alarm%5 == 0) )		//calculating path if already don't have one
		if( have_path == 1 ) {	//alarms happen once in 5 steps
			buf.x = cur_x;		//we use them to recalculate the path
			buf.y = cur_y;
			wave_scan_to_dist(buf, traced_path.len - step, map);
			
			free( traced_path.steps );
			buf.x = treasure_db[treas].x;
			buf.y = treasure_db[treas].y;
			traced_path = trace_with_monsters( buf, monster_map);

			if( traced_path.len == -1 ) {	//if there is no safe path...
				free( traced_path.steps );
				buf.x = treasure_db[treas].x;
				buf.y = treasure_db[treas].y;
				traced_path = trace( buf );	//... we just go straight to treasure
			}
		step = 0;
		}
		else {
			if( traced_path.len != -2 ) free(traced_path.steps);
			buf.x = cur_x;
			buf.y = cur_y;
			treas = wave_scan_to_dist(buf, 15, map);
			
			if(treas == -1) {
				treas = find_nearest_treasure(buf, treasure_db);//if no treasure near us
				buf1.x = treasure_db[treas].x;
				buf1.y = treasure_db[treas].y;
				wave_scan_to_point(buf, buf1 );
				traced_path = trace( buf1 );//going to the nearest one
			}
			else {	//just like the first part
				buf.x = treasure_db[treas].x;
				buf.y = treasure_db[treas].y;
				traced_path = trace_with_monsters( buf, monster_map );
				
				if( traced_path.len == -1 ) {
					free( traced_path.steps );
					buf.x = treasure_db[treas].x;
					buf.y = treasure_db[treas].y;
					traced_path = trace( buf );
				}
			}
		have_path = 1;
		step = 0;
		}


	if( cur_x != traced_path.steps[step].x )		//doing step
		if( cur_x > traced_path.steps[step].x )
			*command = 1;
		else
			*command = 3;
	else if( cur_y > traced_path.steps[step].y )
			*command = 4;
		else
			*command = 2;
	step++;
	alarm++;

	return;
}
