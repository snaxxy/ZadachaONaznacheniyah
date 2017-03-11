#include "header.h"

void main()
{
	setlocale(LC_ALL, "russian");

	srand(time(0));

	cout << "Входные данные:" << endl;
	int N = 6, Q = 5, Z = 5;
	{
		cout << endl << "Количество объектов/субъектов: ";
		//cin >> N;
		cout << N;

		cout << endl << "Количество критериев: ";
		//cin >> Q;
		cout << Q;

		cout << endl << "Шкала оценок: ";
		//cin >> Z;
		cout << Z;
	}
	list::give_number(N);

	object object_list(N, Q, Z);
	subject subject_list(N, Q, Z);

	int **objects_vectors = new int*[lists.get_number()];
	int **subjects_vectors = new int*[lists.get_number()];
	for (int count = 0; count < lists.get_number(); ++count)
	{
		objects_vectors[count] = new int[lists.get_number()];
		subjects_vectors[count] = new int[lists.get_number()];
	}
	{
		create_vectors(lists, objects_vectors, subjects_vectors);
	}

	for (int count = 0; count < lists.get_number(); ++count)
	{
		delete[] objects_vectors[count];
		delete[] subjects_vectors[count];
	}
	delete[] objects_vectors;
	delete[] subjects_vectors;
	lists.~list();
}