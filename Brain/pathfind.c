#include <tdlib.h>

#include "brain.c"

path trace(point from, char (*map)[max_y][max_x]) {
	path to_ret;
	
	to_ret.len = (int)((*map)[from.y][from.x] - 'A');
	to_ret.steps = (point*)malloc(to_ret.len*sizeof(point));
	to_ret.steps[len - 1] = from;
	
	
	return to_ret;
}

path trace_with_monsters(point from, char (*monster_map)[max_y][max_x], char (*map)[max_y][max_x]) {
	
}
