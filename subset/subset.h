#include <iostream>
#include <random>
#include <chrono>
#include <cmath>
#pragma once

struct subset_node { 
  int key;
  subset_node *left;
  subset_node *right;
};

bool init(subset_node **sn);
bool insert(subset_node **sn, int k);
bool remove(subset_node **sn, int k);
subset_node* find(subset_node *sn, int k);
unsigned int size(subset_node *sn);
unsigned int height(subset_node *sn);
void destructor(subset_node *sn);
int* DFS (subset_node *sn); 