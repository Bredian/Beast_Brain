#include <brain.h>
void refresh_treasure_db(treasure* treasure_db, char (*map)[MAX_Y][MAX_X]){
    int i;
    for(i=0;i<number_of_treasures;i++)
        if((*map)[treasure_db[i].y][treasure_db[i].x]!='*') treasure_db[i].exist=0;
	return;
}
