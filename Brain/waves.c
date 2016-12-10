#include "header.h"

/* wave functions */

int wave_scan_to_dist(point from, int dist, char** map) {	//returns number of treasures in range
	int d, k, x, y, treas_count = 0;
	int stop_flag = 0;

	int ix, iy;

	int dx[4] = {-1, 0, 1, 0};	//step from current position to
	int dy[4] = {0, 1, 0, -1};	//left, up, right, down


	d = 0;
	map[from.x][from.y] = 'A';
	do {
		stop_flag = 1;               // предполагаем, что все свободные клетки уже помечены
		for ( y = 0; y < max_y; ++y )
			for ( x = 0; x < max_x; ++x )
				if ( map[y][x] == 'A' + d )                         // ячейка (x, y) помечена числом d
				{
					for ( k = 0; k < 4; ++k )                    // проходим по всем непомеченным соседям
					{
						iy = y + dy[k];
						ix = x + dx[k];
						if ( iy >= 0 && iy < max_y && ix >= 0 && ix < max_x && map[iy][ix] != '#' && map[iy][ix] < 'A' )
					{
							stop_flag = 0;              // найдены непомеченные клетки

							if(map[iy][ix] == '*') treas_count++;

							map[iy][ix] = 'A' + d + 1;      // распространяем волну
						}
					}
				}
		d++;
	} while( !stop_flag && d <= dist );

	return treas_count;
}

int wave_scan_to_point(point from, point to, char **map){	//returns number of steps
	int d, k, x, y;
	int stop_flag = 0;

	int ix, iy;

	int dx[4] = {-1, 0, 1, 0};	//step from current position to
	int dy[4] = {0, 1, 0, -1};	//left, up, right, down


	d = 0;
	map[from.x][from.y] = 'A';
	do {
		for ( y = 0; y < max_y; ++y )
			for ( x = 0; x < max_x; ++x )
				if ( map[y][x] == 'A' + d )                         // ячейка (x, y) помечена числом d
				{
					for ( k = 0; k < 4; ++k )                    // проходим по всем непомеченным соседям
					{
						iy = y + dy[k];
						ix = x + dx[k];
						
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
