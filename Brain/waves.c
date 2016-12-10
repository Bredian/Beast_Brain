#include "brain.h"

/* wave functions */

int wave_scan_to_dist(point from, int dist, char (*map)[MAX_Y][MAX_X]) {	//returns number of treasures in range
	int d, k, x, y, treas_count = 0;
	int stop_flag = 0;

	int ix, iy;

	int dx[4] = {-1, 0, 1, 0};	//step from current position to
	int dy[4] = {0, 1, 0, -1};	//left, up, right, down


	d = 0;
	(*map)[from.x][from.y] = 'A';
	do {
		stop_flag = 1;               // предполагаем, что все свободные клетки уже помечены
		for ( y = 0; y < MAX_Y; ++y )
			for ( x = 0; x < MAX_X; ++x )
				if ( (*map)[y][x] == 'A' + d )                         // ячейка (x, y) помечена числом d
				{
					for ( k = 0; k < 4; ++k )                    // проходим по всем непомеченным соседям
					{
						iy = y + dy[k];
						ix = x + dx[k];
						if ( iy >= 0 && iy < MAX_Y && ix >= 0 && ix < MAX_X && (*map)[iy][ix] != '#' && (*map)[iy][ix] < 'A' )
					{
							stop_flag = 0;              // найдены непомеченные клетки

							if((*map)[iy][ix] == '*') treas_count++;

							(*map)[iy][ix] = 'A' + d + 1;      // распространяем волну
						}
					}
				}
		d++;
	} while( !stop_flag && d <= dist );

	return treas_count;
}

int wave_scan_to_point(point from, point to, char (*map)[MAX_Y][MAX_X]){	//returns number of steps

}
