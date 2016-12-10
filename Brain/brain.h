/*structs*/

struct _point {
	int x;
	int y;
}

typedef _point point;

struct _monster {
	int x;
	int y;
	int alive;
}

typedef _monster monster;

struct _treasure {
	int x;
	int y;
	int exist;
}

typedef _treasure treasure;
/*variables*/
int number_of_treasures=0;
int number_of_monsters=0;

/*functions*/

void scan_for_treasures(treasure* treasure_db, char* map);
void scan_for_monsters(monster* monster_db, char* map);
void refresh_treasure_db(treasure* treasure_db, char* map);
void refresh_monster_db(monster* monster_db, char* map);

treasure* find_nearest_treasure(point from, treasure* treasure_db);	//decartian distance

int wave_scan(point from, int range, char* map);	//returns number of treasures in range
int wave_scan_to_point(point from, point to, char* map);	//returns number of steps

void monster_update(char* map; monster* monster_db);	//idk what's it for
