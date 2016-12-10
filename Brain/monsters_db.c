#include <brain.h>
void scan_for_monstrers(monster * monster_db,char (*map)[MAX_Y][MAX_X]){
    int i,j;
    number_of_monsters=0;
    for(i=0;i<MAX_Y;i++){
        for(j=0;j<MAX_X;j++){
            if((*map)[i][j]=='@'){
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

void refresh_monster_db(monster * monster_db,char (*map)[MAX_Y][MAX_X]){
    int i;
    for(i=0;i<number_of_monsters;i++){
        if((*map)[monster_db[i].y][monster_db[i].x]=='@')
            monster_db[i].alive=1;
        if((*map)[monster_db[i].y+1][monster_db[i].x]=='@')
            monster_db[i].y=monster_db[i].y+1;
        if((*map)[monster_db[i].y-1][monster_db[i].x]=='@')
            monster_db[i].y=monster_db[i].y-1;
        if((*map)[monster_db[i].y][monster_db[i].x+1]=='@')
            monster_db[i].x=monster_db[i].x+1;
        if((*map)[monster_db[i].y][monster_db[i].x-1]=='@')
            monster_db[i].x=monster_db[i].x-1;
        else
            monster_db[i].alive=0;
    }
	return;
}
