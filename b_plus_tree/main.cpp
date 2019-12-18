/**
 * @author Alan Fernando Rincon Vieyra
 * @date 17/Diciembre/2019
 * @test (8,9,10,12,14,15,17) 7 25 27 15 23 19 14 29 10 50 18 22 46 17 70 33 58
 * 17 7 25 27 15 23 19 14 29 10 50 18 22 46 17 70 33 58
 * 16 7 25 27 15 23 19 14 29 10 50 18 22 46 17 20 21
*/

#include "b_plus_tree.hpp"
#include <iostream>

int main()
{
    BPlusTree bPlusTree;
    int n, element;
    
    printf("Ingresa el numero de elementos a insertar:\n");
    scanf("%d", &n);
    printf("Ingresa los %d elementos separados por espacio:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &element);
        bPlusTree.insert(element);
    }
    
    printf("Arbol B+ construido:\n");
    bPlusTree.print();

    printf("Ingrese el elemento a buscar:\n");
    scanf("%d", &element);
    BPlusPage* node = bPlusTree.search(element);
    node->print();

    return 0;
}