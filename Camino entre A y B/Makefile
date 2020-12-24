all:
	gcc -g -c -Wall main.c -o main.o
	gcc -g -c -Wall camino.c -o camino.o
	gcc -g -Wall main.o camino.o -o application

clean:
	rm *.o
	rm application
