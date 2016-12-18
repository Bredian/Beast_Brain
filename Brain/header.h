#include <stdio.h>

#define MAX_X 100
#define MAX_Y 25

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

struct _path {
	int len;
	point* steps;
};

typedef struct _path path;

/*variables*/



/*DBs*/

int number_of_treasures;
int number_of_monsters;
monster* monster_db;
treasure* treasure_db;

/*maps*/

char** monster_map;
//char*** main_map;
//extern char map[MAX_Y][MAX_X];

/*functions*/

//~ void scan_for_treasures(treasure* treasure_db, char **map);
//~ void scan_for_monsters(monster* monster_db, char **map);
//~ void refresh_treasure_db(treasure* treasure_db, char **map);
//~ void refresh_monster_db(monster* monster_db, char **map);
void scan_for_treasures(treasure* treasure_db);
void scan_for_monsters(monster* monster_db);
void refresh_treasure_db(treasure* treasure_db);
void refresh_monster_db(monster* monster_db);

int find_nearest_treasure(point from, treasure* treasure_db);	//by decartian distance, returns number in DB

																//both wave functions and monster_zones_update also change the maps
int wave_scan_to_dist(point from, int dist, char (*map)[MAX_X]);	//returns number of nearest treasure in DB
int wave_scan_to_point(point from, point to);	//returns number of steps

path trace(point trace_to);
path trace_with_monsters(point trace_to, char **monster_map);

void monster_zones_update(char **monster_map, monster* monster_db);	//updates 

void init();

void do_next_step(int cur_x, int cur_y, int *command);	//main magic here
