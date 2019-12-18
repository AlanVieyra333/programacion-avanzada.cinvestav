MAIN=main
HEADERS=b_plus_tree.hpp b_plus_page.hpp
RESOURCES=b_plus_tree.cpp b_plus_page.cpp

build: ${MAIN}.o

run: ${MAIN}.o
	./${MAIN}.o

${MAIN}.o: ${MAIN}.cpp ${HEADERS} ${RESOURCES}
	g++ ${MAIN}.cpp -o ${MAIN}.o ${RESOURCES}