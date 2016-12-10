/*structs*/

struct _point {
    int x;
    int y;
};

typedef struct _point point;

struct _monster {
    int x;
    int y;
    int alive;
};

typedef struct _monster monster;

struct _treasure {
    int x;
    int y;
    int exist;
};

typedef struct _treasure treasure;

/*variables*/

int number_of_treasures;
int number_of_monsters;

/*functions*/

void scan_for_treasures(treasure* treasure_db, char (*map)[MAX_Y][MAX_X]);
void scan_for_monsters(monster* monster_db, char (*map)[MAX_Y][MAX_X]);
void refresh_treasure_db(treasure* treasure_db, char (*map)[MAX_Y][MAX_X]);
void refresh_monster_db(monster* monster_db, char (*map)[MAX_Y][MAX_X]);

treasure* find_nearest_treasure(point from, treasure* treasure_db);	//decartian distance

int wave_scan(point from, int dist, char (*map)[MAX_Y][MAX_X]);	//returns number of treasures in range
int wave_scan_to_point(point from, point to, char (*map)[MAX_Y][MAX_X]);	//returns number of steps

void monster_update(char (*map)[MAX_Y][MAX_X], monster* monster_db);	//idk what's it for
void scan_for_treasures(treasure* treasure_db, char (*map)[MAX_Y][MAX_X]){
    int i,j;
    number_of_treasures=0;
    for(i=0;i<MAX_Y;i++){
        for(j=0;j<MAX_X;j++){
            if((*map)[i][j]=='*'){
                number_of_treasures++;
                treasure_db=realloc(treasure_db,number_of_treasures*sizeof(treasure));
                treasure_db->x=j;
                treasure_db->y=i;
                treasure_db->exist=1;
            }
        }
    }
    return;
}
