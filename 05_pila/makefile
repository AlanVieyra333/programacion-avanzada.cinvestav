INTERFACES = pila.hpp
DEPS = 
MAIN = pila2.cpp

run: main.o
	./main.o

main.o: ${MAIN} ${DEPS} ${INTERFACES}
	g++ -o main.o -O2 ${MAIN} ${DEPS}