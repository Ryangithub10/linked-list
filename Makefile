default:
	gcc -c ./src/list.c -o ./obj/list.o 
	gcc -c ./src/main.c -o ./obj/main.o 
	gcc -o ./bin/main ./obj/main.o ./obj/list.o

build_project:
	mkdir ./bin/ ./obj/ 
	touch ./src/main.c
