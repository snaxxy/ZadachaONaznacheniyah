#include "masterheader.h"

int items::number = 0;

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
			//cin >> N;
			cout << N;

			cout << endl << "Количество критериев: ";
			//cin >> Q;
			cout << Q;

			cout << endl << "Шкала оценок: ";
			//cin >> Z;
			cout << Z;
		}
		items::set_number(N);

		//Создание объектов и субъектов
		items objects(true, N, Q, Z), subjects(false, N, Q, Z);

		//Создание векторов
		vector<vector<item>> c_vec, o_vec;
		{
			create_vectors(false, objects, subjects, c_vec);
			create_vectors(true, subjects, objects, o_vec);
		}

		//Расчёт предпочтений
		int *pref = new int[items::get_number()];
		{
			preference(pref, c_vec, o_vec);
		}

		{
			cout << endl << "О - С" << endl;
			for (int i = 0; i < N; ++i)
			{
				cout << endl << i + 1 << " - " << pref[i] << " : ";

				cout << "( ";
				for (int c = 0; c < Q; ++c) cout << objects.get_criterion(i, c) << ' ';
				cout << ") - ( ";
				for (int c = 0; c < Q; ++c) cout << subjects.get_criterion(i, c) << ' ';
				cout << ')' << endl;

				cout << "o = ( ";
				for (int c = 0; c < Q; ++c) cout << o_vec[pref[i] - 1][i].criterion[c] << ' ';
				cout << ')' << endl;

				cout << "c = ( ";
				for (int c = 0; c < Q; ++c) cout << c_vec[i][pref[i] - 1].criterion[c] << ' ';
				cout << ')' << endl;
			}
		}

		//Чистка памяти
		objects.~items();
		subjects.~items();
		c_vec.~vector();
		o_vec.~vector();
		delete[] pref;

		system("pause");
	}
}