build_debug:
	gcc -g -Wall --debug -c ./src/LinkedList.c -o ./obj/LinkedList.o 
	gcc -g -Wall --debug -c ./src/main.c -o ./obj/main.o 

build_release:
	gcc -c ./src/LinkedList.c -o ./obj/LinkedList.o 
	gcc -c ./src/main.c -o ./obj/main.o

build_project:
	mkdir ./bin/ ./obj/ 
	touch ./src/main.c

compile:
	gcc -o ./bin/main ./obj/main.o ./obj/LinkedList.o
