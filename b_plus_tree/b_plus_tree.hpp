#ifndef b_plus_tree_hpp
#define b_plus_tree_hpp

#include <iostream>

#define ORDER 5
#define MAX_DATA (ORDER - 1)

class BPlusTree
{
public:
    BPlusTree();
    void insert(int element);
    void print();
    
    int n;
    int *data;
    BPlusTree **child_ptr;
    BPlusTree *parent_ptr;
    bool leaf;
    BPlusTree *next_ptr;
};

void insert_into_array(int element, int *data, int &n) {
    for (int i = 0; i < n; i++)   // Buscar lugar donde colocar al elemento.
    {
        if (element > data[i])
        {
            // Recorrer los elementos a la derecha.
            n++;
            for (int j = n; j > i; j--) data[j] = data[j - 1];

            data[i] = element;
            break;
        }
    }
}

void split_leaf(BPlusTree* node) {
    int mid_idx = ORDER / 2;
    int mid_data = node->data[mid_idx];
    BPlusTree *node_left = NULL, *node_right = node;

    // Crear nodos hijos.
    node_left = new BPlusTree();
    for (int i = 0; i < mid_idx; i++)
    {
        node_left->data[i] = node->data[i];
    }
    node_left->n = mid_idx;

    for (int i = 0, j = mid_idx; j < ORDER; i++, j++)
    {
        node_right->data[i] = node_right->data[j];
        node_right->child_ptr[i] = node_right->child_ptr[j];
    }
    
    // Crear nodo padre.
    BPlusTree* parent = new BPlusTree();
    parent->data[0] = mid_data;
    parent->child_ptr[0] = node;

    node->parent_ptr = parent;
}

int split_node(BPlusTree* node)
{
    int mid_idx = ORDER / 2;
    int mid_data = node->data[mid_idx];
    BPlusTree *node_left = NULL, *node_right = node;

    // Crear nodos hijos.
    node_left = new BPlusTree();
    for (int i = 0; i < mid_idx; i++)
    {
        node_left->data[i] = node->data[i];
    }
    node_left->n = mid_idx;
    
    // Crear nodo padre.
    BPlusTree* parent = new BPlusTree();
    parent->data[0] = mid_data;
    parent->child_ptr[0] = node;

    node->parent_ptr = parent;
}

#endif /* b_plus_tree_hpp */