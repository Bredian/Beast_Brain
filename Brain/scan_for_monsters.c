#include <brain.h>
void scan_for_monstrers(monster * monster_db,char (*map)[MAP_Y][MAP_X]){
	int i,j;
	number_of_monsters=0;
	for(i=0;i<MAX_Y;i++){
		for(j=0;j<MAX_X;j++){
			if(map[i][j]=='@'){
				number_of_monsters++;
				monster_db=realloc(monster_db,number_of_monsters*sizeof(monster));
				monster_db->x=j;
				monster_db->y=i;
				monster_db->alive=1;
			}
		}
	}
	return;
}
