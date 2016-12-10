#include <stdio.h>
#include <stdlib.h>

typedef struct treasure{
    int x;
    int y;
    int exist;
} treasure;

void scan_for_treasures(treasure* treasure_db, char* map){
    int i,j;
    for(i=0;i<MAX_X;i++){
        for(j=0;j<MAX_Y;j++){
            if(map[i][j]=='*'){
                treasure_db=realloc(treasure_db,sizeof(treasure));
                treasure_db->x=j;
                treasure_db->y=i;
                treasure_db->exist=1;
            }
        }
    }
    return;
}
