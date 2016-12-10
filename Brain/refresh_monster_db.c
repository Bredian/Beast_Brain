#include <brain.h>
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
