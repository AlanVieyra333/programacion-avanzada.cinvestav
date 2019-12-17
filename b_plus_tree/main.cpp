#include "b_plus_tree.hpp"

int main()
{
    BPlusTree root;
    int n, element;
    
    printf("Ingresa el numero de elementos a insertar:\n");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        printf("Ingresa el elemento:\n");
        scanf("%d", &element);
        
        root.insert(element);
    }
    printf("Arbol B+ construido:\n");
    root.print();

    return 0;
}