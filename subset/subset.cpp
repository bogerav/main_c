#include "subset.h"

using namespace std;

bool init(subset_node** sn) {
  *sn = nullptr;
  return 1;
}

subset_node* find(subset_node* sn, int k) {
  if (sn == nullptr)
    return nullptr;
  if (sn->key == k)
    return sn;
  if (k < sn->key)
    return find(sn->left, k);
  else if (k > sn->key)
    return find(sn->right, k);
}

bool insert(subset_node** sn, int k) {
  if (!(*sn)) {
    *sn = new subset_node;
    (*sn)->key = k;
    (*sn)->right = nullptr;
    (*sn)->left = nullptr;
    return true;
  }
  if (find(*sn, k) != nullptr)
    return false;
  if (k < (*sn)->key)
    return insert(&(*sn)->left, k);
  else if (k > (*sn)->key)
    return insert(&(*sn)->right, k);
}

void del(subset_node** sn, int k) {
  if ((*sn)->left)
    del(&(*sn)->left, k);
  if ((*sn)->right)
    del(&(*sn)->right, k);
  if ((*sn)->left == nullptr) {
     subset_node* right = (*sn)->right;
     delete *sn;
     *sn = right;
  }
  else if ((*sn)->right == nullptr) {
    subset_node* left = (*sn)->left;
    delete *sn;
    (*sn) = left;
  }
  else { 
    subset_node* right = (*sn)->right;
    if (right->left == nullptr)  {
      (*sn)->key = right->key;
      (*sn)->right = right->right;
      delete right;
    }
    else {
      subset_node* min_parent = right;
      while (min_parent->left->left != nullptr)
        min_parent = min_parent->left;
      subset_node* min = min_parent->left;
      min_parent->left = min->right;
      delete min;
    }
  }
}

bool remove(subset_node** sn, int k) {
  if (*sn == nullptr)
    return false;
  if ((*sn)->key == k) {
    del(&(*sn), k);
    return true;
  }
  if (k < (*sn)->key)
    return remove(&(*sn)->left, k);
  return remove(&(*sn)->right, k);
}

unsigned int size(subset_node* sn) {
  unsigned int s = 0;
  if (sn == nullptr)
    return 0;
  else
    return size(sn->left) + size(sn->right) + 1;
}

unsigned int height(subset_node* sn) {
  if (sn == nullptr)
    return 0;
  return (max(height(sn->right), height(sn->left)) + 1);
}

void destructor(subset_node* sn) {
  if (sn->left)
    destructor(sn->left);
  if (sn->right)
    destructor(sn->right);
  sn->right = nullptr;
  sn->left = nullptr;
  sn = nullptr;
  delete sn;
}

void DFS_h(subset_node* sn, int* a, int* i) {
  if (sn == nullptr)
    return;
  DFS_h(sn->left, a, i);
  a[*i] = sn->key;
  (*i)++;
  DFS_h(sn->right, a, i);
}

int* DFS(subset_node* sn) {
  int i = 0;
  unsigned int s = size(sn);
  int* a = new int[s];
  DFS_h(sn, a, &i);
  return a;
}