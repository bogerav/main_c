#include <iostream>
#include <random>
#include <chrono>
#pragma once

struct subforwardlist
{
    int data;
    subforwardlist * next;

};

bool push_back(subforwardlist **sfl, int d);
bool init(subforwardlist **sfl);
bool erase_where (subforwardlist **sfl, unsigned int where);
int pop_back(subforwardlist **sfl);
bool push_forward(subforwardlist **sfl, int d); 
int pop_forward(subforwardlist **sfl); 
bool push_where(subforwardlist **sfl, unsigned int where, int d); 
unsigned int size(subforwardlist **sfl);
void clear(subforwardlist **sfl);
bool init_from_file(subforwardlist **sfl, char* filename);