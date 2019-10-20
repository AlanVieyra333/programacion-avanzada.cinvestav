INTERFACES = balanced_tree.hpp
DEPS = balanced_tree.cpp
MAIN = main.cpp

run: main.o
	./main.o

main.o: ${MAIN} ${DEPS} ${INTERFACES}
	g++ -o main.o -O2 ${MAIN} ${DEPS}