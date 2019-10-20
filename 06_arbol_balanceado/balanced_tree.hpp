#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

typedef struct _node
{
  int key;
  void* element;
  struct _node* left;
  struct _node* right;
} node;

int tree_height(node* n);
bool isEmpty(void* n);
void* search(node* n, int key);
node* insert(node* n, int key, void* element);
int insert_node(node** n, int key, void* element);
node* left_rot(node* n);
node* right_rot(node* n);

#endif
