MAIN=main
HEADERS=b_plus_tree.hpp b_plus_page.hpp
RESOURCES=b_plus_tree.cpp b_plus_page.cpp

#build: ${MAIN}.o

run: ${MAIN}.o
	echo "17 7 25 27 15 23 19 14 29 10 50 18 22 46 17 70 33 58 33" | ./${MAIN}.o

${MAIN}.o: ${MAIN}.cpp ${HEADERS} ${RESOURCES}
	g++ ${MAIN}.cpp -o ${MAIN}.o ${RESOURCES}