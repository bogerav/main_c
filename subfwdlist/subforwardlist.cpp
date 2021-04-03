#include "subforwardlist.h"

using namespace std;

void pop_front(subforwardlist** sfl) {
	subforwardlist* t = *sfl;
	*sfl = (*sfl)->next;
	delete t;
}

bool push_back(subforwardlist** sfl, int d) {
	if (*sfl != nullptr) {
		subforwardlist* t = (*sfl);
		while (t->next != nullptr)
			t = t->next;
		t->next = new subforwardlist;
		t->next->data = d;
		t->next->next = nullptr;
	}
	else {
		*sfl = new subforwardlist;
		(*sfl)->data = d;
		(*sfl)->next = nullptr;
	}
	return 1;
}

bool init(subforwardlist** sfl) {
	*sfl = nullptr;
	return true;
}

bool erase_where(subforwardlist** sfl, unsigned int where) {
	if (where == 0)
		pop_front(&(*sfl));
	else {
		subforwardlist* pr = nullptr;
		subforwardlist* cr = (*sfl);
		for (unsigned int i = 0; i != where; i++) {
			pr = cr;
			cr = cr->next;
		}
		subforwardlist* next_elem = cr->next;
		pr->next = next_elem;
		delete cr;
	}
	return 1;
}

int pop_back(subforwardlist** sfl) {
	if (*sfl != nullptr) {
		subforwardlist* cr = (*sfl);
		int l = 0;
		if (cr->next != nullptr) {
			subforwardlist* pr = nullptr;
			while (cr->next != nullptr) {
				pr = cr;
				cr = cr->next;
      }
			l = cr->data;
			pr->next = nullptr;
			delete cr;
			return l;
		}
		else {
			l = cr->data;
			delete cr;
			(*sfl) = nullptr;
			return l;
		}
	}
	else
		return 0;
}

bool push_forward(subforwardlist** sfl, int d) {
	if (*sfl == nullptr) {
		*sfl = new subforwardlist;
		(*sfl)->data = d;
		(*sfl)->next = nullptr;
	}
	else {
		subforwardlist* t = new subforwardlist;
		t->data = d;
		t->next = *sfl;
		*sfl = t;
	}
	return 1;
}

int pop_forward(subforwardlist** sfl) {
	if (*sfl != nullptr)
	{	
		int f = (*sfl)->data;
		pop_front(&(*sfl));
		return f;
	}
	else
		return 0;
}

bool push_where(subforwardlist** sfl, unsigned int where, int d) {
	if (where == 0 or *sfl == nullptr)
		push_forward(&(*sfl), d);
	else {
		subforwardlist* pr = nullptr;
		subforwardlist* cr = (*sfl);
		for (int i = 0; i != where; i++) {
			pr = cr;
			cr = cr->next;
		}
		subforwardlist* new_elem = new subforwardlist;
		new_elem->data = d;
		new_elem->next = cr;
		pr->next = new_elem;
		cr = cr->next;
	}
	return 1;
}

unsigned int size (subforwardlist** sfl) {
	unsigned int s = 1;
	if ((*sfl) != nullptr) {
		subforwardlist* t = (*sfl);
		while (t->next != nullptr) {
			t = t->next;
			s++;
		}
		return s;
	}
	else
		return 0;
}

void clear(subforwardlist** sfl) {
	unsigned int s = size(&(*sfl));
	for (unsigned int i = 0; i < s; i++)
		pop_front(&(*sfl));
}
