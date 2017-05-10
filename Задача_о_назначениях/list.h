#ifndef listdef
#define listdef 1

#include "element.h"
#include "masterheader.h"

class list : element
{
	int number = 0;
	element *first_element = nullptr;
	element *last_element = nullptr;

public:
	int size();
	void add(int, int, int pos = -1);
	void set(int, char);
	int get(int, int j = 0);
	int get_max(char ch = 'x');
	void sort(); //Плохо работает
	void del(int pos = -1);
	void clear();

	~list();
};

#endif