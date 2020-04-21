poG: poG.o list.o Graph.o
	gcc -o poG poG.o list.o Graph.o

poG.o : poG.c list.h Graph.h
	gcc -Wall -Werror -std=c11 -c poG.c

list.o : list.c list.h
	gcc -Wall -Werror -std=c11 -c list.c

Graph.o : Graph.c Graph.h 
	gcc -Wall -Werror -std=c11 -c Graph.c

clean:
	rm -f poG poG.o list.o Graph.o core
