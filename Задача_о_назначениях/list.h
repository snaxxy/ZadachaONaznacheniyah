#ifndef objectH
#define objectH 1

#include "header.h"

struct item
{
	int ID = 1;

	int *criterion = NULL;
	int number = 0; //����� ��������� ��������
};

class list
{
	int number; //����� ��������/���������

public:
	static void give_number(int);
	int get_number(); //����� ��������
	
	int get_criterion(int);
	int get_criterions_number(int); //����� ���������
};

class object : list, item
{
	item *arr = NULL;

public:
	object(int N = 6, int Q = 5, int Z = 5);
	int get_criterion(int);
	int get_criterions_number(int); //����� ���������

	~object();

	friend list;
};

class subject : list, item
{
	item *arr = NULL;

public:
	subject(int N = 6, int Q = 5, int Z = 5);
	int get_criterion(int);
	int get_criterions_number(int); //����� ���������

	~subject();

	friend list;
};


#endif