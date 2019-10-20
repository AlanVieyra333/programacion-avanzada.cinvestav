#include "balanced_tree.hpp"
#include <stdio.h>
#include <stdlib.h>

typedef struct _element
{
  int value = -1;
} element;

int main(int argc, char const *argv[])
{
  node* tree = NULL;

  for (int i = 10; i <= 20; i+=1)
  {
    printf("Inserta: %d,\t", i);

    element* e = (element*) malloc(sizeof(element));
    e->value = i;

    tree = insert(tree, i, (void*) e);

    printf("Nodo raiz: %d\n", tree->key);  
  }

  for (int i = 1; i <= 10; i+=1)
  {
    printf("Inserta: %d,\t", i);

    element* e = (element*) malloc(sizeof(element));
    e->value = i;

    tree = insert(tree, i, (void*) e);

    printf("Nodo raiz: %d\n", tree->key);  
  }
  
  element* e = (element*) search(tree, 3);

  if (!isEmpty(e))
  {
    printf("Elemento buscado: %d\n", e->value);
  }
  
  return 0;
}
