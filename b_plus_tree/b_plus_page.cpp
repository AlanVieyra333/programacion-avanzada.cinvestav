#include "b_plus_page.hpp"
#include <iostream>

BPlusPage::BPlusPage()
{
    this->leaf = true;
    this->n = 0;
    this->parent_ptr = NULL;
    this->left_ptr = NULL;
    this->right_ptr = NULL;
    this->data = new int[ORDER];                  // Se agrega un espacio de memoria para almacenar temporalmente el elemento agregado antes de split.
    this->child_ptr = new BPlusPage *[ORDER + 1]; // Tambien aqui.

    for (int i = 0; i < ORDER + 1; i++)
    {
        this->child_ptr[i] = NULL;
    }
}

BPlusPage::BPlusPage(BPlusPage *other)
{
    this->leaf = other->leaf;
    this->n = other->n;
    this->parent_ptr = other->parent_ptr;
    this->left_ptr = other->left_ptr;
    this->right_ptr = other->right_ptr;
    this->data = new int[ORDER];                  // Se agrega un espacio de memoria para almacenar temporalmente el elemento agregado antes de split.
    this->child_ptr = new BPlusPage *[ORDER + 1]; // Tambien aqui.

    for (int i = 0; i < ORDER; i++)
        this->data[i] = other->data[i];

    for (int i = 0; i < ORDER + 1; i++)
        this->child_ptr[i] = other->child_ptr[i];
}

/**
 * Funcion encargada de insertar un elemento dentro de esta pagina en el lugar correspondiente
 * para conservar el orden.
 * |_|_|_|_|
 * |_  |_|_|_|
 * @return Indice del elemento en donde fue insertado el nuevo elemento.
*/
int BPlusPage::insert(int e)
{
    int i;

    for (i = 0; i < this->n; i++) // Buscar lugar donde colocar al elemento.
    {
        if (e < this->data[i])
            break;
    }

    // Recorrer los elementos a la derecha.
    for (int j = this->n; j > i; j--)
        this->data[j] = this->data[j - 1];

    this->data[i] = e;

    // Recorrer hijos a la derecha.
    for (int j = this->n + 1; j > i; j--)
        this->child_ptr[j] = this->child_ptr[j - 1];

    this->n++;
    return i;
}

void BPlusPage::print_neighbor()
{
    BPlusPage *node = this;

    while (node != NULL)
    {
        for (int i = 0; i < node->n; i++)
        {
            printf("|%d", node->data[i]);
        }
        printf("|\t");

        node = node->right_ptr;
    }
    printf("\n");
}

void BPlusPage::print()
{
    for (int i = 0; i < this->n; i++)
    {
        printf("|%d", this->data[i]);
    }
    printf("|\t");
    printf("\n");
}
