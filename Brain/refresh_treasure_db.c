#include <brain.h>
void refresh_treasure_db(treasure* treasure_db, char (*map)[MAP_Y][MAP_X]){
	int i;
	for(i=0;i<number_of_treasures;i++)
		if(map[treausre_db[i]->y][treasure_db->x]!='*') treasure_db[i]->exist=0;
}
