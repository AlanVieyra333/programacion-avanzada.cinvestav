#include "b_plus_tree.hpp"
#include <iostream>

BPlusTree::BPlusTree()
{
    root = new BPlusPage();
}

void BPlusTree::insert(int element)
{
    BPlusPage *node = root;

    while (node != NULL)
    {
        if (node->leaf)
        {
            // Insertar en el lugar correspondiente para que queden ordenados.
            node->insert(element);

            if (node->n > MAX_DATA) // Dividir la pagina entre 2,
                split_page(node);
            break;
        }
        else
        {
            int idx;
            // Buscar el hijo en donde sera insertado el nuevo elemento.
            for (idx = 0; idx < node->n; idx++)
            {
                if (element < node->data[idx])
                    break;
            }
            node = node->child_ptr[idx];
        }
    }
}

void BPlusTree::print()
{
    BPlusPage *node = root;

    while (node != NULL)
    {
        node->print_neighbor();
        node = node->child_ptr[0];
    }
}

void BPlusTree::split_page(BPlusPage *node)
{
    int mid_idx = ORDER / 2;
    int mid_data = node->data[mid_idx];
    BPlusPage *node_l = NULL, *node_r = node;

    // Crear nodo iquierdo.
    node_l = new BPlusPage(node);
    node_l->n = mid_idx;
    //if (node_l->leaf)
    node_l->left_ptr = node->left_ptr;
    if (node_l->left_ptr != NULL)
        node_l->left_ptr->right_ptr = node_l;
    node_l->right_ptr = node_r;

    // Modificar nodo actual (derecho).
    int mid_r_idx = mid_idx;
    if (!node_r->leaf) // No Duplicar dato en nodo hijo.
        mid_r_idx++;
    for (int i = 0, j = mid_r_idx; j < node->n; i++, j++)
        node_r->data[i] = node->data[j];
    for (int i = 0, j = mid_r_idx; j <= node->n; i++, j++)
        node_r->child_ptr[i] = node->child_ptr[j];
    node_r->n = node->n - mid_r_idx;
    node_r->left_ptr = node_l;

    // Nodo padre.
    BPlusPage *current_parent = node_l->parent_ptr;
    BPlusPage *new_parent = add_parent(node_l, node_r, mid_data);

    if (current_parent != NULL) // Actualizar nodo padre.
    {
        node_l->parent_ptr = current_parent;
        node_r->parent_ptr = current_parent;

        int idx = current_parent->insert(mid_data);
        current_parent->child_ptr[idx] = node_l;

        if (current_parent->n > MAX_DATA)
        {
            split_page(current_parent);
        }
    }
    else
    {
        root = new_parent;
    }
}

/**
 * Funcion que crea un nodo padre, enlaza a sus nodos hijos y lo devuleve como salida.
*/
BPlusPage *BPlusTree::add_parent(BPlusPage *node_l, BPlusPage *node_r, int key)
{
    BPlusPage *parent = new BPlusPage();
    parent->data[0] = key;
    parent->n = 1;
    parent->child_ptr[0] = node_l;
    parent->child_ptr[1] = node_r;
    parent->leaf = false;

    node_l->parent_ptr = parent;
    node_r->parent_ptr = parent;

    return parent;
}

BPlusPage* BPlusTree::search(int element) {
    return tree_search(element, root);
}

BPlusPage* BPlusTree::tree_search(int element, BPlusPage* node) {
    if (node->leaf)
        return node;

    for (int i = 0; i < node->n; i++)
    {
        if( element < node->data[i])
            return tree_search(element, node->child_ptr[i]);
    }

    return tree_search(element, node->child_ptr[node->n]);
}