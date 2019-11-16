INTERFACES = 
DEPS = 
MAIN = hashtable.cpp
GCC = g++

run: main.o
	./main.o

main.o: ${MAIN} ${DEPS} ${INTERFACES}
	${GCC} -o main.o -O2 ${MAIN} ${DEPS}