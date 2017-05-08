#ifndef listdef
#define listdef 1

#include "masterheader.h"

struct element
{
	int x;
	int y;

	element *previous = NULL; //”казатель на предыдущий элемент
	element *next = NULL; //”казатель на следующий элемент
};

class list : element
{
	int number = 0;
	element *first_element = NULL;
	element *last_element = NULL;

public:
	int size();
	void add(int, int, int pos = -1);
	void set(int, char);
	int get(int, int j = 0);
	int get_max(char ch = 'x');
	void sort(); //ѕлохо работает
	void del(int pos = -1);
	void clear();

	~list();
};

#endif