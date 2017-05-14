#include "items.h"

void items::setAmount(int x) { amount = x; }
int items::getAmount() { return amount; }

items::items(bool isObject, int N, int Q, int Z)
{	
	int objectsInitial[5][5] = { { 4, 2, 2, 1, 5 }, { 4, 2, 4, 3, 5 }, { 1, 2, 3, 4, 1 }, { 1, 4, 4, 1, 5 }, {4,1,4,1,3} };
	int subjectsInitial[5][5] = { { 1, 4, 3, 1, 2 },{ 2, 1, 2, 2, 3 },{ 3, 5, 1, 5, 4 },{ 2, 2, 2, 1, 3 }, {4,1,4,1,2} };
	

	itemArray = new item[N];

	for (int n = 0; n < N; ++n)
	{
		itemArray[n].isObject=isObject;
		if (n > 0) itemArray[n].ID = itemArray[n-1].ID + 1;
		
		itemArray[n].criteriaVector = new int[Q];
		if (isObject) for (int q = 0; q < Q; ++q) itemArray[n].criteriaVector[q] = objectsInitial[n][q]; //rand() % Z + 1;
		else for (int q = 0; q < Q; ++q) itemArray[n].criteriaVector[q] = subjectsInitial[n][q]; //rand() % Z + 1;
		itemArray[n].criterionAmount = Q;
	}

	this->printItems(N, Q);
}

int items::getID(int n) { return itemArray[n].ID; }
int items::getCriteriaVector(int n, int q) { return itemArray[n].criteriaVector[q]; }
int items::getCriterionAmount(int n) { return itemArray[n].criterionAmount; }
item items::getItem(int n) { return itemArray[n]; }

void items::printItems(int N, int Q)
{
	if (itemArray[0].isObject)
	{
		printf("\n\nÎáúåêòû:");
	}
	else
	{
		printf("\n\nÑóáúåêòû:");
	}
	

	cout << endl << "|-----";
	for (int i = 0; i < Q; ++i) cout << "|---";
	cout << '|';

	cout << endl << "|  ¹  ";
	for (int i = 0; i < Q; ++i) printf("| %c ", i+129);
	cout << '|';

	cout << endl << "|-----";
	for (int i = 0; i < Q; ++i) cout << "|---";
	cout << '|';

	for (int i = 0; i < N; ++i)
	{
		printf("\n|  %i  ", this->itemArray[i].ID);
		for (int j = 0; j < Q; ++j)	printf("| %i ", this->itemArray[i].criteriaVector[j]);
		cout << '|';

		if (i+1 != N)
		{
			cout << endl << "|     ";
			for (int j = 0; j < Q; ++j)	cout << "|   ";
			cout << '|';
		}
	}

	cout << endl << "|-----";
	for (int i = 0; i < Q; ++i) cout << "|---";
	cout << '|' << endl << endl;
}

items::~items()
{
	delete[] itemArray;
}