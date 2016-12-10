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
}

typedef struct _path path;

/*variables*/

int max_x;	//double the MAXes defined in player.c
int max_y;

/*DBs*/

int number_of_treasures;
int number_of_monsters;
monster* monster_db;
treasure* treasure_db;

/*maps*/

char (*monster_map)[max_y][max_x]);

/*functions*/

void scan_for_treasures(treasure* treasure_db, char (*map)[max_y][max_x]);
void scan_for_monsters(monster* monster_db, char (*map)[max_y][max_x]);
void refresh_treasure_db(treasure* treasure_db, char (*map)[max_y][max_x]);
void refresh_monster_db(monster* monster_db, char (*map)[max_y][max_x]);

treasure* find_nearest_treasure(point from, treasure* treasure_db);	//decartian distance

																//both wave functions and monster_zones_update also change the maps
int wave_scan(point from, int dist, char (*map)[max_y][max_x]);	//returns number of treasures in range
int wave_scan_to_point(point from, point to, char (*map)[max_y][max_x]);	//returns number of steps

path trace(point from, char (*map)[max_y][max_x]);
path trace_with_monsters(point from, char (*monster_map)[max_y][max_x], char (*map)[max_y][max_x]);

void monster_zones_update(char (*monster_map)[max_y][max_x], monster* monster_db);	//updates 

void init();

void do_next_step(int cur_x, int cur_y, int *command);	//main magic here
