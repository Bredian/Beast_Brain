#include <stdio.h>
#include <stdlib.h>

typedef struct  monster{
	int x;
	int y;
	int alive;
} monster;

void scan_for_monstrers(monster * monster_db,char (*map)[MAP_Y][MAP_X]){
	int i,j;
	for(i=0;i<MAX_Y;i++){
		for(j=0;j<MAX_X;j++){
			if(map[i][j]=='@'){
				number_of_monsters++;
				monster_db=realloc(monster_db,sizeof(monster));
				monster_db->x=j;
				monster_db->y=i;
				monster_db->alive=1;
			}
		}
	}
	return;
}
