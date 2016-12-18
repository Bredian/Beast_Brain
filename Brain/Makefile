GCC_FLAGS = -O0 -g

all: brain
	gcc -c $(GCC_FLAGS) player.c
	gcc $(GCC_FLAGS) treasures_db.o monsters_db.o waves.o brain.o player.o pathfind.o -o player
	g++ ../server/server.c -o ../server/server

clean:
	rm -f *.o
	rm -f player
	rm -f ../server/server

brain: treasures monsters waves pathfind
	gcc $(GCC_FLAGS) -c brain.c

treasures:
	gcc $(GCC_FLAGS) -c treasures_db.c

monsters:
	gcc $(GCC_FLAGS) -c monsters_db.c

waves:
	gcc $(GCC_FLAGS) -c waves.c

pathfind:
	gcc $(GCC_FLAGS) -c pathfind.c

