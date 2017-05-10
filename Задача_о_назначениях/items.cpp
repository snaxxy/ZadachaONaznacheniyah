#include "masterheader.h"

void items::setAmount(int x) { amount = x; }
int items::getAmount() { return amount; }

items::items(bool isObject, int N, int Q, int Z)
{	
	//int mass1[4][5] = { { 2, 3, 2, 1, 2 }, { 2, 2, 3, 2, 1 }, { 3, 3, 1, 1, 2 }, { 1, 1, 3, 2, 2 } };
	//int mass2[4][5] = { { 3, 3, 1, 1, 2 },{ 2, 2, 3, 1, 2 },{ 1, 1, 2, 2, 3 },{ 2, 3, 2, 1, 1 } };
	
	int mass1[6][5] = { { 4, 5, 5, 1, 4 },{ 2, 2, 2, 3, 4 },{ 1, 2, 3, 4, 3 },{ 2, 5, 2, 2, 4 },{ 4, 4, 1, 1, 3 },{ 4, 5, 4, 2, 5 } };
	int mass2[6][5] = { { 1, 5, 2, 5, 5 },{ 3, 4, 4, 3, 5 },{ 1, 5, 1, 3, 3 },{ 1, 5, 2, 2, 5 },{ 1, 2, 1, 3, 1 },{ 5, 5, 3, 4, 3 } };

	arr = new item[N];

	for (int n = 0; n < N; ++n)
	{
		arr[n].isObject=isObject;
		if (n > 0) arr[n].ID = arr[n-1].ID + 1;
		
		arr[n].criterion = new int[Q];
		if (isObject) for (int q = 0; q < Q; ++q) arr[n].criterion[q] = mass1[n][q]; //rand() % Z + 1;
		else for (int q = 0; q < Q; ++q) arr[n].criterion[q] = mass2[n][q]; //rand() % Z + 1;
		arr[n].criterionAmount = Q;
	}

	this->view(N, Q);
}

int items::get_ID(int n) { return arr[n].ID; }
int items::get_criterion(int n, int q) { return arr[n].criterion[q]; }
int items::get_criterions_number(int n) { return arr[n].criterionAmount; }
item items::get_item(int n) { return arr[n]; }

void items::view(int N, int Q)
{
	if (arr[0].isObject)
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
		printf("\n|  %i  ", this->arr[i].ID);
		for (int j = 0; j < Q; ++j)	printf("| %i ", this->arr[i].criterion[j]);
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
		delete[] arr[i].name;
		delete[] arr[i].criterion;
	}
	delete[] arr;*/
}