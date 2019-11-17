DEPS=disperse_matrix.o
LIBS=disperse_matrix.hpp

run: main.o
	./main.o

main.o: main.cpp ${LIBS} ${DEPS}
	g++ main.cpp ${DEPS} -o main.o

disperse_matrix.o: disperse_matrix.cpp disperse_matrix.hpp
	g++ -c disperse_matrix.cpp -o disperse_matrix.o