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
int max_x;
int max_y;

/*functions*/

void scan_for_treasures(treasure* treasure_db, char (*map)[max_y][max_x]);
void scan_for_monsters(monster* monster_db, char (*map)[max_y][max_x]);
void refresh_treasure_db(treasure* treasure_db, char (*map)[max_y][max_x]);
void refresh_monster_db(monster* monster_db, char (*map)[max_y][max_x]);

treasure* find_nearest_treasure(point from, treasure* treasure_db);	//decartian distance

int wave_scan(point from, int dist, char (*map)[max_y][max_x]);	//returns number of treasures in range
int wave_scan_to_point(point from, point to, char (*map)[max_y][max_x]);	//returns number of steps

void monster_update(char (*map)[max_y][max_x], monster* monster_db);	//idk what's it for

void do_next_step(int cur_x, int cur_y, int *command);	//main magic here
