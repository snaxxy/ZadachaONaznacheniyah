#ifndef itemsdef
#define itemsdef 1

#include "masterheader.h"

struct item
{
	bool isObject; //Объект или субъект
	int ID = 1; //Идентификатор объекта/субъекта
	int *criteriaVector = nullptr; //Вектор критериев
	int criterionAmount = 0; //Число критериев объекта/субъекта
};

class items
{
	static int amount; //Число объектов/субъектов
	item *itemArray = nullptr; //Вектор объектов/субъектов

public:
	
	static void setAmount(int); //Задание числа объектов/субъектов
	static int getAmount(); //Получение числа объектов/субъектов

	items(bool, int N = 6, int Q = 5, int Z = 5);
	int getID(int);
	int getCriteriaVector(int, int);
	int getCriterionAmount(int); //Получение числа критериев
	item getItem(int); //Получение объекта/субъекта
	void printItems(int N = 6, int Q = 5); //Вывод вектора на экран

	~items();
};

#endif