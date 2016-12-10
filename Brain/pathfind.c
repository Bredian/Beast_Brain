#include <stdlib.h>

#include "header.h"

path trace(point trace_to, char **map) {
	int d, i, x, y;
	int ix, iy;

	int dx[4] = {-1, 0, 1, 0};	//step from current position to
	int dy[4] = {0, 1, 0, -1};	//left, up, right, down

	path to_ret;

	to_ret.len = (int)(map[trace_to.y][trace_to.x] - 'A');
	to_ret.steps = (point*)malloc(to_ret.len*sizeof(point));

	d = to_ret.len;
	x = trace_to.x;
	y = trace_to.y;
	while ( d > 0 )
	{
		to_ret.steps[d - 1].x = x;
		to_ret.steps[d - 1].y = y;
		d--;
		for (i = 0; i < 4; i++)
		{
			int iy=y + dy[i], ix = x + dx[i];
			if ( iy >= 0 && iy < max_y && ix >= 0 && ix < max_x && map[iy][ix] == 'A' + d)
			{
				x = x + dx[i];
				y = y + dy[i];           // переходим в ячейку, которая на 1 ближе к старту
				break;
			}
		}
	}

	return to_ret;
}

path trace_with_monsters(point trace_to, char **monster_map, char **map) {
	int d, i, x, y;
	int ix, iy;
	int no_way;

	int dx[4] = {-1, 0, 1, 0};	//step from current position to
	int dy[4] = {0, 1, 0, -1};	//left, up, right, down

	path to_ret;

	to_ret.len = (int)(map[trace_to.y][trace_to.x] - 'A');
	to_ret.steps = (point*)malloc(to_ret.len*sizeof(point));

	d = to_ret.len;
	x = trace_to.x;
	y = trace_to.y;
	while ( d > 0 )
	{
		no_way = 0;
		to_ret.steps[d - 1].x = x;
		to_ret.steps[d - 1].y = y;
		d--;

		for (i = 0; i < 4; i++)
		{
			iy = y + dy[i];
			ix = x + dx[i];
			if ( iy >= 0 && iy < max_y && ix >= 0 && ix < max_x && map[iy][ix] + 'A' + 5 - monster_map[iy][ix] ==  d)	//our steps + 5 from monster_zones_update + 'A' offset -
			{																												//- monster's steps to the point
				x = x + dx[i];
				y = y + dy[i];           // переходим в ячейку, которая на 1 ближе к старту
				break;
			}
			else if(map[iy][ix] + 'A' + 5 - monster_map[iy][ix] > d) no_way++;
		}

	if(no_way == 4) to_ret.len = -1;
	}

	return to_ret;
}
