#ifndef itemsdef
#define itemsdef 1

#include "masterheader.h"

struct item
{
	bool isObject; //������ ��� �������
	int ID = 1; //������������� �������/��������
	int *criteriaVector = nullptr; //������ ���������
	int criterionAmount = 0; //����� ��������� �������/��������
};

class items
{
	static int amount; //����� ��������/���������
	item *itemArray = nullptr; //������ ��������/���������

public:
	
	static void setAmount(int); //������� ����� ��������/���������
	static int getAmount(); //��������� ����� ��������/���������

	items(bool, int N = 6, int Q = 5, int Z = 5);
	int getID(int);
	int getCriteriaVector(int, int);
	int getCriterionAmount(int); //��������� ����� ���������
	item getItem(int); //��������� �������/��������
	void printItems(int N = 6, int Q = 5); //����� ������� �� �����

	~items();
};

#endif