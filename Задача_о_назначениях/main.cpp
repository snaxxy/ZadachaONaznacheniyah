#include "masterheader.h"
#include "items.h"
#include "logic.h"

int items::amount = 0;

void main()
{
	setlocale(LC_ALL, "russian");

	srand(time(0));

	//for(;;)
	{
		system("cls");

		cout << "Входные данные:" << endl;
		int N = 6, Q = 5, Z = 5;
		{
			cout << endl << "Количество объектов/субъектов: ";
			cin >> N;
			cout << N;

			cout << endl << "Количество критериев: ";
			cin >> Q;
			cout << Q;

			cout << endl << "Шкала оценок: ";
			cin >> Z;
			cout << Z;
		}
		items::setAmount(N);

		//Создание объектов и субъектов
		items objects(true, N, Q, Z), subjects(false, N, Q, Z);

		//Создание векторов
		vector<vector<item>> subjectVector, objectVector;
		{
			calculateVectors(false, objects, subjects, subjectVector);
			calculateVectors(true, subjects, objects, objectVector);
		}
		//Расчёт предпочтений
		int *pref = new int[items::getAmount()];
		{
			preference(pref, subjectVector, objectVector);
		}

		{
			cout << endl << "О - С" << endl;
			for (int i = 0; i < N; ++i)
			{
				cout << endl << i + 1 << " - " << pref[i] << " : ";

				cout << "( ";
				for (int c = 0; c < Q; ++c) cout << objects.getCriteriaVector(i, c) << ' ';
				cout << ") - ( ";
				for (int c = 0; c < Q; ++c) cout << subjects.getCriteriaVector(i, c) << ' ';
				cout << ')' << endl;

				cout << "o = ( ";
				for (int c = 0; c < Q; ++c) cout << objectVector[pref[i] - 1][i].criteriaVector[c] << ' ';
				cout << ')' << endl;

				cout << "c = ( ";
				for (int c = 0; c < Q; ++c) cout << subjectVector[i][pref[i] - 1].criteriaVector[c] << ' ';
				cout << ')' << endl;
			}
		}

		//Чистка памяти
		objects.~items();
		subjects.~items();
		subjectVector.~vector();
		objectVector.~vector();
		delete[] pref;

		system("pause");
	}
}