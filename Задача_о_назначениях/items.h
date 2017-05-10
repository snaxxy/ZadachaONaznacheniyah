#ifndef itemsdef
#define itemsdef 1

#include "masterheader.h"

struct item
{
	bool isObject;
	//char *name = NULL; //Определение: объект/субъект
	
	int ID = 1; //Индивидуальный номер

	int *criterion = NULL; //Вектор критериев
	int criterionAmount = 0;//sizeof(criterion)/sizeof(*criterion); //Число критериев объекта/субъекта
};

class items
{
	static int amount; //Число объектов/субъектов
	//static int number; //Число объектов/субъектов
	item *arr = NULL; //Вектор объектов/субъектов

public:
	
	static void setAmount(int); //Задание числа объектов/субъектов
	static int getAmount(); //Получение числа объектов/субъектов

	items(bool, int N = 6, int Q = 5, int Z = 5);
	int get_ID(int);
	int get_criterion(int, int);
	int get_criterions_number(int); //Получение числа критериев
	item get_item(int); //Получение объекта/субъекта
	void view(int N = 6, int Q = 5); //Вывод вектора на экран

	~items();
};

#endif