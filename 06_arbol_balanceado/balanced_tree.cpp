#include "balanced_tree.hpp"
#include<algorithm>
#include <stdio.h>

int tree_height(node* n){
  int height = 0;

  if (!isEmpty(n)) {
    int l_height = tree_height(n->left);
    int r_height = tree_height(n->right);
    int max_height = std::max(l_height, r_height);
    height = max_height + 1;
  }

  return height;
}

bool isEmpty(void* value) {
  return (value == NULL) ? true : false;
}

void* search(node* n, int key) {
  void* element = NULL;

  if (!isEmpty(n)) {
    if (n->key == key)
    {
      element = n->element;
    } else
    {
      element = search(n->left, key);
      if (isEmpty(element)) {
        element = search(n->right, key);
      }
    }
  }

  return element;
}

node* insert(node* n, int key, void* element) {
  if (isEmpty(n)) {
    node* newNode = (node*) malloc(sizeof(node));

    newNode->key = key;
    newNode->element = element;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
  } else if (key == n->key){
    return n;
  } else if (key < n->key) {
    n->left = insert(n->left, key, element);
  } else if (key >= n->key) {
    n->right = insert(n->right, key, element);
  }

  // Balance
  int l_height = tree_height(n->left);
  int r_height = tree_height(n->right);

  if (l_height - r_height > 1) {
    printf("rota right -> nodo: (%d)\t", n->key);
    return right_rot(n);
   } else if (r_height - l_height > 1) {
    printf("rota left -> nodo: (%d)\t", n->key);
    return left_rot(n);
   }
  
  return n;
}

node* left_rot(node* n) {
  node *tmp;
  tmp = n->right;
  n->right = tmp->left;
  tmp->left = n;
  
  return tmp;
}

node* right_rot(node* n) {
  node *tmp;
  tmp = n->left;
  n->left = tmp->right;
  tmp->right = n;
  
  return tmp;
}