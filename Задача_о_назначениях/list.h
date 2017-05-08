#ifndef listdef
#define listdef 1

#include "masterheader.h"

struct element
{
	int x;
	int y;

	element *previous = NULL; //��������� �� ���������� �������
	element *next = NULL; //��������� �� ��������� �������
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
	void sort(); //����� ��������
	void del(int pos = -1);
	void clear();

	~list();
};

#endif