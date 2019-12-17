#ifndef b_plus_tree_hpp
#define b_plus_tree_hpp

#include <iostream>
#define ORDER 6

class BPlusTree
{
public:
    BPlusTree();
    void insert(int element);
    void print();
    
private:
    int *data;
    BPlusTree **child_ptr;
    bool leaf;
    int n;

    void sort();
    int split_child(int i);
};

BPlusTree *root = NULL, *np = NULL;

#endif /* b_plus_tree_hpp */