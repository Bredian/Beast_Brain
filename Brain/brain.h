/*structs*/

struct _point {
	int x;
	int y;
};

typedef _point point;

struct _monster {
	int x;
	int y;
	int alive;
};

typedef _monster monster;

struct _treasure {
	int x;
	int y;
	int exist;
};

typedef _treasure treasure;

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
