#include <stdio.h>
#include <stdlib.h>

typedef struct treasue{
	int x;
	int y;
	int existance;
} treasure;

void scan_for_treasures(treasure* treasure_db, char** map){
	treasure_db=malloc(20*sizeof(treasue))
	int i,j;
	for(i=0;i<MAP_X;i++){
		for(j=0;j<MAP_Y;j++){
			if(map[i][j]=='*'){
				
}
