#include "header.h"

/* wave functions */

int wave_scan_to_dist(point from, int dist, char** map) {	//returns number of treasures in range
	//extern char map[MAX_Y][MAX_X];
	int d, i, x, y, number = -1;
	int stop_flag = 0, treas_flag = 0;

	point nearest_treasure;

	nearest_treasure.x = -1;
	nearest_treasure.y = -1;

	int ix, iy;

	int dx[4] = {-1, 0, 1, 0};	//step from current position to
	int dy[4] = {0, 1, 0, -1};	//left, up, right, down


	d = 0;
	*(*(map + from.x) + from.y) = 'A';
	do {
		stop_flag = 1;               // предполагаем, что все свободные клетки уже помечены
		for ( y = 0; y < max_y; y++ )
			for ( x = 0; x < max_x; x++ )
				if ( *(*(map + y) + x) == 'A' + d )                         // ячейка (x, y) помечена числом d
				{
					for ( i = 0; i < 4; i++ )                    // проходим по всем непомеченным соседям
					{
						iy = y + dy[i];
						ix = x + dx[i];
						if ( iy >= 0 && iy < max_y && ix >= 0 && ix < max_x && *(*(map + iy) + ix) != '#' && *(*(map + iy) + ix) < 'A' )
					{
							stop_flag = 0;              // найдены непомеченные клетки

							if(*(*(map + iy) + ix) == '*' && !treas_flag) {
								nearest_treasure.x = x;
								nearest_treasure.y = y;
								treas_flag = 1;
							}

							*(*(map + iy) + ix) = 'A' + d + 1;      // распространяем волну
						}
					}
				}
		d++;
	} while( !stop_flag && d <= dist );

	for(i = 0; i < number_of_treasures; i++)
		if(treasure_db[i].x == nearest_treasure.x && treasure_db[i].y == nearest_treasure.y)
			number = i;
	
	return number;
}

int wave_scan_to_point(point from, point to){	//returns number of steps
	extern char map[MAX_Y][MAX_X];
	int d, i, x, y;
	int stop_flag = 0;

	int ix, iy;

	int dx[4] = {-1, 0, 1, 0};	//step from current position to
	int dy[4] = {0, 1, 0, -1};	//left, up, right, down


	d = 0;
	map[from.x][from.y] = 'A';
	do {
		for ( y = 0; y < max_y; y++ )
			for ( x = 0; x < max_x; x++ )
				if ( map[y][x] == 'A' + d )                         // ячейка (x, y) помечена числом d
				{
					for ( i = 0; i < 4; i++ )                    // проходим по всем непомеченным соседям
					{
						iy = y + dy[i];
						ix = x + dx[i];
						
						if ( iy >= 0 && iy < max_y && ix >= 0 && ix < max_x && map[iy][ix] != '#' && map[iy][ix] < 'A' )
						{
							if( ix == to.x && iy == to.y ) stop_flag = 1;

							map[iy][ix] = 'A' + d + 1;      // распространяем волну
						}
					}
				}
		d++;
	} while( !stop_flag );
	
	return d;
}
