#include <stdio.h>
#include <stdlib.h>
#include <brain.h>
void scan_for_treasures(treasure* treasure_db, char (*map)[MAP_Y][MAP_X]){
    int i,j;
    number_of_treasures=0;
    for(i=0;i<MAX_Y;i++){
        for(j=0;j<MAX_X;j++){
            if(map[i][j]=='*'){
                number_of_treasures++;
                treasure_db=realloc(treasure_db,sizeof(treasure));
                treasure_db->x=j;
                treasure_db->y=i;
                treasure_db->exist=1;
            }
        }
    }
    return;
}
