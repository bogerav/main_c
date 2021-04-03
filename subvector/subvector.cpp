#include "subvector.h"

bool init(subvector *qv) {
  qv->mas = nullptr;
  qv->top = 0;
  qv->capacity = 0;
  return 1;
}

bool push_back(subvector *qv, int d) {
  
  if (qv->top + 1 > qv->capacity)
    {
        int* p = new int[qv->capacity + 1];
        for (int i = 0; i < qv->capacity; i++)
            p[i] = qv->mas[i];

        if (qv->capacity > 0)
            delete[] qv->mas;

        qv->capacity++;
        qv->mas = p;
        qv->mas[qv->top] = d;
        qv->top++;
    }
  else
    {
        qv->mas[qv->top] = d;
        qv->top++;
    }
  return 1;
}

int pop_back(subvector *qv) {

    if (qv->top > 0)
    {
        qv->top--;
        int d = qv->mas[qv->top];
        return d;
    }
    else return 0;
}

bool resize(subvector *qv, unsigned int new_capacity) {
    if (new_capacity <= qv->capacity) {
        return 0;
    }
    unsigned int *s = &(qv->capacity);
    int last = *s;
    *s = new_capacity;
    int *p = new int[*s];
    int i = 0;
    while (i < last) {
        p[i] = qv->mas[i];
        i++;
    }
    delete[] qv->mas;
    qv->mas = p;
    return 1;
}

void shrink_to_fit(subvector *qv) {
    int *p = new int[qv->top];
    for(int i = 0; i < qv->top; i++){
        p[i] = qv->mas[i];
    }
    delete[] qv->mas;
    qv->mas = p;
    qv->capacity = qv->top;
}

void clear(subvector *qv) {
    qv->top = 0;
}

void destructor(subvector *qv) {
  qv->top = 0;
  qv->capacity = 0;
  delete[] qv->mas;
  qv->mas = nullptr;
}