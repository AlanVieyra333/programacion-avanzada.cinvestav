#include "b_plus_tree.hpp"

BPlusTree::BPlusTree()
{
    this->data = new int[ORDER];
    this->child_ptr = new BPlusTree *[ORDER];
    this->leaf = true;
    this->n = 0;
    this->parent_ptr = NULL;
    this->next_ptr = NULL;

    for (int i = 0; i < ORDER; i++)
    {
        this->child_ptr[i] = NULL;
    }
}

void BPlusTree::insert(int element)
{
    if (this->leaf)
    {
        // Insertar en el lugar correspondiente para que queden ordenados.
        insert_into_array(element, this->data, this->n);

        if (this->n > MAX_DATA) // Dividir la pagina entre 2, 
        {
            split_node(this);
        }
        
    } else {

    }
    
}

void BPlusTree::print()
{
    int i;

    printf("\n");

    for (i = 0; i < this->n; i++)
    {
        if (this->leaf == false)
        {
            this->child_ptr[i]->print();
        }
        
        printf(" %data", this->data[i]);
    }

    if (this->leaf == false)
    {
        this->child_ptr[i]->print();
    }
    
    printf("\n");
}
