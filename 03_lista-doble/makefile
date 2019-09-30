INTERFACES = lista2.h
DEPS = lista2.c

run: main.o
	./main.o

main.o: main.c ${DEPS} ${INTERFACES}
	gcc -o main.o -O2 main.c ${DEPS}