#ifndef itemsdef
#define itemsdef 1

#include "masterheader.h"

struct item
{
	bool isObject;
	//char *name = NULL; //�����������: ������/�������
	
	int ID = 1; //�������������� �����

	int *criterion = nullptr; //������ ���������
	int criterionAmount = 0;//sizeof(criterion)/sizeof(*criterion); //����� ��������� �������/��������
};

class items
{
	static int amount; //����� ��������/���������
	item *itemArray = nullptr; //������ ��������/���������

public:
	
	static void setAmount(int); //������� ����� ��������/���������
	static int getAmount(); //��������� ����� ��������/���������

	items(bool, int N = 6, int Q = 5, int Z = 5);
	int get_ID(int);
	int get_criterion(int, int);
	int getCriterionAmount(int); //��������� ����� ���������
	item get_item(int); //��������� �������/��������
	void view(int N = 6, int Q = 5); //����� ������� �� �����

	~items();
};

#endif