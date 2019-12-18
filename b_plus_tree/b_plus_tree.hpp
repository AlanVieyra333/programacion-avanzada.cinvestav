#ifndef b_plus_tree_hpp
#define b_plus_tree_hpp

#include "b_plus_page.hpp"

class BPlusTree
{
public:
    BPlusTree();
    void insert(int element);
    void print();
private:
    BPlusPage *root;

    void split_page(BPlusPage* node);
    BPlusPage* add_parent(BPlusPage* node_l, BPlusPage* node_r, int data);
};

#endif /* b_plus_tree_hpp */