#include "header.h"

void list::give_number(int x) { number = x; }

object::object(int N, int Q, int Z)
{
	arr = new item[N];

	for (int n = 0; n < N; ++n)
	{
		if (n > 0) arr[n].ID = arr[n-1].ID + 1;
		
		arr[n].criterion = new int[Q];
		for (int q = 0; q < Q; ++q) arr[n].criterion[q] = rand() % Z + 1;
		arr[n].number = Q;
	}
}

subject::subject(int N, int Q, int Z)
{
	objects_arr = new list[N];
	subjects_arr = new list[N];

	for (int n = 0; n < N; ++n)
	{
		if (n > 0)
		{
			objects_arr[n].ID = objects_arr[n - 1].ID + 1;
			subjects_arr[n].ID = subjects_arr[n - 1].ID + 1;
		}

		objects_arr[n].criterion = new int[Q];
		subjects_arr[n].criterion = new int[Q];

		for (int q = 0; q < Q; ++q)
		{
			objects_arr[n].criterion[q] = rand() % Z + 1;
			subjects_arr[n].criterion[q] = rand() % Z + 1;
		}

		objects_arr[n].number = Q;
		subjects_arr[n].number = Q;
	}
	number = N;
}

int list::get_number() { return number; }
int list::get_criterions_number(int n) { return objects_arr[n].number; }
int list::get_object_criterion(int n, int q) { return criterion[q]; }
int list::get_subject_criterion(int n, int q) { return subjects_arr[n].criterion[q]; }

list::~list()
{
	for (int n = 0; n < number; ++n) delete[] objects_arr[n].criterion;
	delete[] objects_arr;
}