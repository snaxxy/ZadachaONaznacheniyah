#include "items.h"

void items::setAmount(int x) { amount = x; }
int items::getAmount() { return amount; }

items::items(bool isObject, int N, int Q, int Z)
{	
	//int mass1[4][5] = { { 2, 3, 2, 1, 2 }, { 2, 2, 3, 2, 1 }, { 3, 3, 1, 1, 2 }, { 1, 1, 3, 2, 2 } };
	//int mass2[4][5] = { { 3, 3, 1, 1, 2 },{ 2, 2, 3, 1, 2 },{ 1, 1, 2, 2, 3 },{ 2, 3, 2, 1, 1 } };
	
	int mass1[6][5] = { { 4, 5, 5, 1, 4 },{ 2, 2, 2, 3, 4 },{ 1, 2, 3, 4, 3 },{ 2, 5, 2, 2, 4 },{ 4, 4, 1, 1, 3 },{ 4, 5, 4, 2, 5 } };
	int mass2[6][5] = { { 1, 5, 2, 5, 5 },{ 3, 4, 4, 3, 5 },{ 1, 5, 1, 3, 3 },{ 1, 5, 2, 2, 5 },{ 1, 2, 1, 3, 1 },{ 5, 5, 3, 4, 3 } };

	itemArray = new item[N];

	for (int n = 0; n < N; ++n)
	{
		itemArray[n].isObject=isObject;
		if (n > 0) itemArray[n].ID = itemArray[n-1].ID + 1;
		
		itemArray[n].criterion = new int[Q];
		if (isObject) for (int q = 0; q < Q; ++q) itemArray[n].criterion[q] = mass1[n][q]; //rand() % Z + 1;
		else for (int q = 0; q < Q; ++q) itemArray[n].criterion[q] = mass2[n][q]; //rand() % Z + 1;
		itemArray[n].criterionAmount = Q;
	}

	this->view(N, Q);
}

int items::get_ID(int n) { return itemArray[n].ID; }
int items::get_criterion(int n, int q) { return itemArray[n].criterion[q]; }
int items::getCriterionAmount(int n) { return itemArray[n].criterionAmount; }
item items::get_item(int n) { return itemArray[n]; }

void items::view(int N, int Q)
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
		for (int j = 0; j < Q; ++j)	printf("| %i ", this->itemArray[i].criterion[j]);
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
	/*for (int i = 0; i < get_number(); ++i)
	{
		delete[] itemArray[i].name;
		delete[] itemArray[i].criterion;
	}
	delete[] itemArray;*/
}