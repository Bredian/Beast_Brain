all: brain
	gcc -c player.c
	gcc treasures_db.o monsters_db.o waves.o brain.o player.o pathfind.o -o player
	g++ ../server/server.c -o ../server/server

clean:
	rm -f *.o
	rm -f player
	rm -f ../server/server

brain: treasures monsters waves pathfind
	gcc -c brain.c

treasures:
	gcc -c treasures_db.c

monsters:
	gcc -c monsters_db.c

waves:
	gcc -c waves.c

pathfind:
	gcc -c pathfind.c

