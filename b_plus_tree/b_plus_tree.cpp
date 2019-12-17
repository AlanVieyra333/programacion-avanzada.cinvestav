#include "b_plus_tree.hpp"

BPlusTree::BPlusTree()
{
    this->data = new int[ORDER];
    this->child_ptr = new BPlusTree *[ORDER + 1];
    this->leaf = true;
    this->n = 0;

    for (int i = 0; i <= ORDER; i++)
    {
        this->child_ptr[i] = NULL;
    }
}

void BPlusTree::sort()
{
    int aux;

    for (int i = 0; i < this->n; i++)
    {
        for (int j = i; j <= this->n; j++)
        {
            if (this->data[i] > this->data[j])
            {
                aux = this->data[i];
                this->data[i] = this->data[j];
                this->data[j] = aux;
            }
        }
    }
}

int BPlusTree::split_child(int i)
{
    int j, mid;
    BPlusTree *np1, *np3, *y;

    np3 = new BPlusTree();
    np3->leaf = true;
    if (i == -1)
    {
        mid = this->data[2];
        this->data[2] = 0;
        this->n--;
        np1 = new BPlusTree();
        np1->leaf = false;
        this->leaf = true;
        for (j = 3; j < 6; j++)
        {
            np3->data[j - 3] = this->data[j];
            np3->child_ptr[j - 3] = this->child_ptr[j];
            np3->n++;
            this->data[j] = 0;
            this->n--;
        }
        for (j = 0; j < 6; j++)
        {
            this->child_ptr[j] = NULL;
        }
        np1->data[0] = mid;
        np1->child_ptr[np1->n] = this;
        np1->child_ptr[np1->n + 1] = np3;
        np1->n++;
        root = np1;
    }
    else
    {
        y = this->child_ptr[i];
        mid = y->data[2];
        y->data[2] = 0;
        y->n--;
        for (j = 3; j < 6; j++)
        {
            np3->data[j - 3] = y->data[j];
            np3->n++;
            y->data[j] = 0;
            y->n--;
        }
        this->child_ptr[i + 1] = y;
        this->child_ptr[i + 1] = np3;
    }
    return mid;
}

void BPlusTree::insert(int element)
{
    int i, t;
    BPlusTree *node = this;

    if (node->leaf == true && node->n == 6)
    {
        t = node->split_child(-1);
        node = root;

        for (i = 0; i < (node->n); i++)
        {
            if ((element > node->data[i]) && (element < node->data[i + 1]))
            {
                i++;
                break;
            }
            else if (element < node->data[0])
            {
                break;
            }
        }
        node = node->child_ptr[i];
    }
    else
    {
        while (node->leaf == false)
        {
            for (i = 0; i < (node->n); i++)
            {
                if ((element > node->data[i]) && (element < node->data[i + 1]))
                {
                    i++;
                    break;
                }
                else if (element < node->data[0])
                {
                    break;
                }
            }
            if ((node->child_ptr[i])->n == 6)
            {
                t = node->split_child(i);
                node->data[node->n] = t;
                node->n++;
            }
            else
            {
                node = node->child_ptr[i];
            }
        }
    }

    node->data[node->n] = element;
    node->sort();
    node->n++;
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
