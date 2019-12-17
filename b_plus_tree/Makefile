MAIN=main
HEADERS=b_plus_tree.hpp
RESOURCES=b_plus_tree.cpp

run: ${MAIN}.o
	./${MAIN}.o

${MAIN}.o: ${MAIN}.cpp ${HEADERS}
	g++ ${MAIN}.cpp -o ${MAIN}.o ${RESOURCES}