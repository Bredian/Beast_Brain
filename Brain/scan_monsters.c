#include <stdio.h>
#include <stdlib.h>

typedef struct  monster{
	int x;
	int y;
	int alive;
} monster;

void scan_for_monstrers(monster * monster_db,char* map){
	int i,j;
	for(i=0;i<MAX_X;i++){
		for(j=0;j<MAX_Y;j++){
			if(map[i][j]=='@'){
				monster_db=realloc(monster_db,sizeof(monster));
				monster_db->x=i;
				monster_db->y=j;
				monster_db->alive=1;
			}
		}
	}
	return;
}
