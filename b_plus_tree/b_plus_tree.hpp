#ifndef b_plus_tree_hpp
#define b_plus_tree_hpp

#include "b_plus_page.hpp"

class BPlusTree
{
public:
    BPlusTree();
    void insert(int element);
    void print();
    BPlusPage* search(int element);

private:
    BPlusPage *root;

    void split_page(BPlusPage* node);
    BPlusPage* add_parent(BPlusPage* node_l, BPlusPage* node_r, int data);
    BPlusPage* tree_search(int element, BPlusPage* node);
};

#endif /* b_plus_tree_hpp */