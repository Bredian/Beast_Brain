#include <stdio.h>
#include <stdlib.h>
#include <brain.h>
void refresh_monster_db(monster * monster_db,char (*map)[MAX_Y][MAP_X]){
	for(i=0;i<number_of_monster)
	if(map[monster_db[i]->y][monster_db->x]=='@') monster_db[i]->alive=1;
	if(map[monster_db[i]->y+1][monster_db->x]=='@') monster_db[i]->y=monster_db[i]->y+1;
	if(map[monster_db[i]->y-1][monster_db->x]=='@') monster_db[i]->y=monster_db[i]->y-1;
	if(map[monster_db[i]->y][monster_db->x+1]=='@') monster_db[i]->x=monster_db[i]->x+1;
	if(map[monster_db[i]->y][monster_db->x-1]=='@') monster_db[i]->x=monster_db[i]->x-1;
	else monster_db[i]->alive=0;
}
