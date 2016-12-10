#include <stdio.h>
#include <stdlib.h>
#include <brain.h>
void refresh_treasure_db(treasure* treasure_db, char ** map){
	int i;
	for(i=0;i<number_of_treasures;i++)
		if(map[treausre_db[i]->y][treasure_db->x]!='*') treasure_db[i]->exist=0;
}
