#include "logic.h"


void printVector(int N, bool isObject, vector<vector<item>> &vec)
{
	for (int i = 0; i < N; ++i)
	{
		if (isObject)
		{
			cout << 'о';
		}
		else
		{
			cout << 'c';
		}
		cout << i + 1 << ':' << endl;

		for (int j = 0; j < N; ++j)
		{

			if (!isObject) cout << 'o' << vec[j][0].ID << vec[i][0].ID << " = { ";
			else cout << 'c' << vec[i][0].ID << vec[j][0].ID << " = { ";

			for (int c = 0; c < 5; ++c)
			{
				cout << vec[i][j].criteriaVector[c] << ' ';
			}
			cout << '}' << endl;
		}
		cout << endl;
	}
}

int *compare(item &A, item &B)
{
	int *out = new int[A.criterionAmount];

	int c_end = A.criterionAmount;
	for (int c = 0; c < c_end; ++c)
	{
		if (A.criteriaVector[c] <= B.criteriaVector[c]) out[c] = 0;
		else out[c] = A.criteriaVector[c] - B.criteriaVector[c];
	}

	return out;
}

void calculateVectors(bool isObject, items &list1, items &list2, vector<vector<item>> &vec)
{
	int N = items::getAmount();

	vec.resize(N);
	for (int count = 0; count < N; ++count) vec[count].resize(N);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (isObject)
			{
				vec[j][i].ID = list2.getID(j);
				vec[j][i].criteriaVector = compare(list2.getItem(i), list1.getItem(j));
				vec[j][i].criterionAmount = list1.getCriterionAmount(j);
			}
			else
			{
				vec[i][j].ID = list1.getID(i);
				vec[i][j].criteriaVector = compare(list2.getItem(j), list1.getItem(i));
				vec[i][j].criterionAmount = list1.getCriterionAmount(i);
			}

		}
	}

	printVector(N, isObject, vec);

	/*for (int i = 0; i < N; ++i)
	{
		vec.resize(i+1);

		item *temp1;
		item *temp2;

		int c_end = list1.getCriterionAmount(i);
		for (int j = 0; j < N; ++j)
		{
			temp1 = &list1.getItem(j);
			temp2 = &list2.getItem(j);

			vec[i].resize(j+1);

			if (check == 'c') vec[i][j].ID = i*10 + j;
			else vec[j][i].ID = j*10 + i;

			for (int c = 0; c < c_end; ++c)
			{
				if (check == 'c')
				{
					if (temp1->criteriaVector[c] <= temp2->criteriaVector[c]) vec[i][j].criteriaVector[c] = 0;
					else vec[i][j].criteriaVector[c] = temp1->criteriaVector[c] - temp2->criteriaVector[c];
				}
				else
				{
					if (temp1->criteriaVector[c] <= temp2->criteriaVector[c]) vec[j][i].criteriaVector[c] = 0;
					else vec[j][i].criteriaVector[c] = temp1->criteriaVector[c] - temp2->criteriaVector[c];
				}
			}
		}

		delete temp1;
		delete temp2;
	}*/
	/*for (int i = 0; i < 2*N; ++i)
	{
		int c_end = object_list.getCriterionAmount(i);
		for (int j = abs(N-i); j < N; ++j)
		{
			item *temp_object = &object_list.getItem(j);
			item *temp_subject = &subject_list.getItem(j);

			for (int c = 0; c < c_end; ++c)
			{
				if (temp_object->criteriaVector[c] <= temp_subject->criteriaVector[c]) objects_vectors[j][j] = 0;
				else objects_vectors[j][j] = temp_object->criteriaVector[c] - temp_subject->criteriaVector[c];

				if (temp_subject->criteriaVector[c] <= temp_object->criteriaVector[c]) subjects_vectors[j][j] = 0;
				else subjects_vectors[j][j] = temp_subject->criteriaVector[c] - temp_object->criteriaVector[c];
			}

			delete temp_object;
			delete temp_subject;
		}
	}*/
	/*for (int i = 0; i < list::get_number(); ++i)
	{
		for (int j = 0; j < list::get_number(); ++j)
		{
			item *temp_object = &object_list.getItem(i);
			item *temp_subject = &subject_list.getItem(i);

			int c_end = object_list.getCriterionAmount(i);
			for (int c = 0; c < c_end; ++c)
			{
				objects_vectors[i][j] = compare

				if (lists.get_object_criterion(i, c) <= lists.get_subject_criterion(j, c)) objects_vectors[i][j] = 0;
				else objects_vectors[i][j] = lists.get_object_criterion(i, c) - lists.get_subject_criterion(j, c);

				if (lists.getCriteriaVector(i, c) <= lists.get_object_criterion(j, c)) subjects_vectors[i][j] = 0;
				else subjects_vectors[i][j] = lists.get_subject_criterion(i, c) - lists.get_object_criterion(j, c);
			}

			delete temp_object;
			delete temp_subject;
		}
	}*/
}

int getPosOfMax(vector<element> list, char ch)
{
	int max = -1;
	int position = -1;

	if (ch == 'x')
	{
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			if (it->x > max)
			{
				position = distance(list.begin(), it);
				max = it->x;
			}
		}
	}
	else
	{
		for (auto it = list.begin(); it != list.end(); ++it)
		{
			if (it->y > max)
			{
				position = distance(list.begin(), it);
				max = it->y;
			}
		}
	}
	return position;
}


void preference(int *&preference, vector<vector<item>> c_vec, vector<vector<item>> o_vec)
{
	int N = items::getAmount();
	
	while (N > 0)
	{
		string **o_matrix = new string *[N];
		string **c_matrix = new string *[N];
		for (int count = 0; count < N; ++count)
		{
			o_matrix[count] = new string[N];
			c_matrix[count] = new string[N];
		}
		
		generateLayers(N, o_matrix, c_vec);
		generateLayers(N, c_matrix, o_vec);

		for (int i = 0; i < N; ++i)
		{
			for (int j = i+1; j < N; ++j) o_matrix[i][j].swap(o_matrix[j][i]);
		}

		printMatrix(N, c_vec, o_matrix, o_vec, c_matrix);

		char str1[7] = { 'D', 'D', 'H', 'H', 'D', ' ', 'H' };
		string str2;

		//list preference_list;
		vector<element> preference_list;

		bool check = false;
		for (int m = 1; m <= N && check == false; ++m)
		{
			str2 = to_string(m);
			for (int k1 = 0, k2 = 0; k1 < 4 && (check == false || k1 == 2); ++k1, k2 += 2)
			{
				for (int i = 0; i < N; ++i)
				{
					for (int j = 0; j < N; ++j)
					{
						if (o_matrix[i][j] == (str1[k1] + str2) && c_matrix[i][j] == (str1[k2] + str2) && o_matrix[i][j][1] == str2[0] && c_matrix[i][j][1] == str2[0])
						{
							//preference_list.add(j, i);
							preference_list.push_back(element(j, i));
							check = true;
						}
					}
				}
			}
		}

		for (int k = 0, i; k < preference_list.size(); ++k)
		{
			for (i = 0; i < preference_list.size() && k < preference_list.size(); ++i)
			{
				//if (k != i && preference_list.get(k, 0) == preference_list.get(i, 0))
				if (k != i && preference_list.at(k).x == preference_list.at(i).x)
				{
					int temp = 0;
					for (int j = 0; j < c_vec[0][0].criterionAmount; ++j)
					{
						//temp += c_vec[preference_list.get(k, 0)][preference_list.get(k, 1)].criteriaVector[j] - c_vec[preference_list.get(i, 0)][preference_list.get(i, 1)].criteriaVector[j];
						temp += c_vec[preference_list.at(k).x][preference_list.at(k).y].criteriaVector[j] - c_vec[preference_list.at(i).x][preference_list.at(i).y].criteriaVector[j];
					}

					if (temp > 0)
					{
						//preference_list.del(i);
						preference_list.erase(preference_list.begin()+i);
						--i;
					}
					else
					{
						//preference_list.del(k);
						preference_list.erase(preference_list.begin() + k);
						i = -1;
					}					
					continue;
				}

				//if (k != i && preference_list.get(k, 1) == preference_list.get(i, 1))
				if (k != i && preference_list.at(k).y == preference_list.at(i).y)
				{
					int temp = 0;
					for (int j = 0; j < o_vec[0][0].criterionAmount; ++j)
					{
						//temp += o_vec[preference_list.get(k, 0)][preference_list.get(k, 1)].criteriaVector[j] - o_vec[preference_list.get(i, 0)][preference_list.get(i, 1)].criteriaVector[j];
						temp += o_vec[preference_list.at(k).x][preference_list.at(k).y].criteriaVector[j] - o_vec[preference_list.at(i).x][preference_list.at(i).y].criteriaVector[j];
					}

					if (temp > 0)
					{
						preference_list.erase(preference_list.begin() + i);
						--i;
					}
					else
					{
						preference_list.erase(preference_list.begin() + k);
						i = -1;
					}
					continue;
				}
			}
		}

		for (int i = 0; i < preference_list.size(); ++i)
		{
			//preference[c_vec[preference_list.get(i, 0)][0].ID - 1] = o_vec[preference_list.get(i, 1)][0].ID;
			preference[c_vec[preference_list.at(i).x][0].ID - 1] = o_vec[preference_list.at(i).y][0].ID;
		}

		for (int i = 0, iter_x, iter_y; i < preference_list.size(); ++i)
		{
			iter_x = getPosOfMax(preference_list, 'x');
			iter_y = getPosOfMax(preference_list, 'y');

			for (int n = 0; n < N; ++n)
			{
				//c_vec[n].erase(c_vec[n].begin() + preference_list.get(iter_y, 1));
				c_vec[n].erase(c_vec[n].begin() + preference_list.at(iter_y).y);
				//o_vec[n].erase(o_vec[n].begin() + preference_list.get(iter_x, 0));
				o_vec[n].erase(o_vec[n].begin() + preference_list.at(iter_x).x);
			}

			//c_vec.erase(c_vec.begin() + preference_list.get(iter_x, 0));
			c_vec.erase(c_vec.begin() + preference_list.at(iter_x).x);
			//o_vec.erase(o_vec.begin() + preference_list.get(iter_y, 1));
			o_vec.erase(o_vec.begin() + preference_list.at(iter_y).y);

			//preference_list.set(iter_x, 'x');
			preference_list.at(iter_x).x = -1;
			//preference_list.set(iter_y, 'y');
			preference_list.at(iter_y).y = -1;

			--N;
		}

		printVector(N, false, c_vec);
		printVector(N, true, o_vec);
		
		for (int count = 0; count < N; ++count)
		{
			delete[] o_matrix[count];
			delete[] c_matrix[count];
		}
		delete[] o_matrix;
		delete[] c_matrix;
//		preference_list.~list();
	}
}



void generateLayers(int N, string **&matrix, vector<vector<item>> &vec)
{
	char **R = new char*[N];
	for (int count = 0; count < N; ++count) R[count] = new char[N];
	vector<int> layer;

	for (int i = 0; i < N; ++i)
	{
		for (int k = 0; k < N; ++k)
		{
			bool allAreNotBetter;
			bool allAreNotWorse;

			for (int j = 0; j < N; ++j)
			{
				allAreNotBetter = true;
				allAreNotWorse = true;

				for (int c = 0; c < vec[i][j].criterionAmount; ++c)
				{
					if (vec[i][k].criteriaVector[c] > vec[i][j].criteriaVector[c]) allAreNotBetter = false;
					if (vec[i][k].criteriaVector[c] < vec[i][j].criteriaVector[c]) allAreNotWorse = false;
				}

				if (allAreNotBetter == true && allAreNotWorse == true)
				{
					R[k][j] = '=';
					R[j][k] = '=';
				}
				else if (allAreNotBetter == true)
				{
					R[k][j] = '>';
					R[j][k] = '<';
				}
				else if (allAreNotWorse == true)
				{
					R[k][j] = '<';
					R[j][k] = '>';
				}
				else
				{
					R[k][j] = '#';
					R[j][k] = '#';
				}
			}
		}

		//Вывод "графа"
		{
			cout << endl;
			for (int n = 0; n < N; ++n)
			{
				for (int m = 0; m < N; ++m)
				{
					cout << R[n][m] << ' ';
				}
				cout << endl;
			}
		}

		bool check = true;
		for (int s = 0; check != false; ++s)
		{
			for (int k = 0; k < N; ++k)
			{
				bool check = true, empty = true;
				for (int j = 0; j < N; ++j)
				{
					if (R[k][j] == '<') check = false;
					if (R[k][j] != '#') empty = false;
				}

				if (check == true && empty == false) layer.push_back(k);
			}

			if (layer.size() > 1)
			{
				bool equivalent = true;
				for (int k = 0; k < layer.size(); ++k)
				{
					for (int j = 0; j < layer.size(); ++j)
					{
						if (R[layer[k]][layer[j]] != '=') equivalent = false;
					}
				}

				char ch = 'D';
				if (equivalent != true) ch = 'H';

				for (int k = 0; k < layer.size(); ++k) matrix[i][layer[k]] = ch + to_string(s+1);
			}
			else matrix[i][layer[0]] = 'D' + to_string(s+1);

			for (int k = 0; k < layer.size(); ++k)
			{
				for (int j = 0; j < N; ++j)
				{
					R[layer[k]][j] = '#';
					R[j][layer[k]] = '#';
				}
			}
			layer.clear();

			check = false;
			for (int n = 0; n < N && check != true; ++n)
			{
				for (int m = 0; m < N && check != true; ++m)
				{
					if (R[n][m] != '#') check = true;
				}
			}
		}
	}

	layer.~vector();
	for (int count = 0; count < N; ++count) delete[] R[count];
	delete[] R;

	/*int N = list::get_number();

	char **R = new char *[N];
	for (int count = 0; count < N; ++count) R[count] = new char [N];

	for (int i = 0; i < N; ++i)
	{
	for (int j = i; j < N; ++j)
	{
	if (i != j)
	{
	R[i][j] = compare(objects_vectors[i], objects_vectors[j]);

	if (R[i][j] == '>') R[j][i] == '<';
	else if (R[i][j] == '<') R[j][i] == '>';
	else R[j][i] = R[i][j];
	}
	else R[i][j] = '=';
	}
	}

	vector<int> layer;

	bool check, check_H = false, check_D = false;
	for (int i = 0; i < N; ++i)
	{
	check = true;
	for (int j = 0; j < N, check != false; ++j)
	{
	if (R[i][j] == '<') check == false;
	}
	if (check == true) layer.push_back(i);
	}

	if (layer.size() != 1)
	{
	for (int i = 0; i < layer.size(); ++i)
	{

	}
	}*/
}

void printMatrix(int N, vector<vector<item>> &c_vec, string **&o_matrix, vector<vector<item>> &o_vec, string **&c_matrix)
{	
	cout << endl << "Матрица предпочтения:";

	cout << endl << "|----";
	for (int i = 0; i < N; ++i) cout << "|------";
	cout << '|';

	cout << endl << "|    ";
	for (int i = 0; i < N; ++i) printf("|   O%i ", c_vec[i][0].ID);
	cout << '|';

	cout << endl << "|----";
	for (int i = 0; i < N; ++i) cout << "|------";
	cout << '|';

	for (int i = 0; i < N; ++i)
	{
		printf("\n|    ");
		for (int j = 0; j < N; ++j)	cout << "|   " << o_matrix[i][j] << ' ';
		cout << '|';

		printf("\n| C%i ", o_vec[i][0].ID);
		for (int j = 0; j < N; ++j)	cout << "| " << c_matrix[i][j] << "   ";
		cout << '|';

		if (i+1 != N)
		{
			cout << endl << "|    ";
			for (int i = 0; i < N; ++i) printf("|      ", i+1);
			cout << '|';
		}
	}

	cout << endl << "|----";
	for (int i = 0; i < N; ++i) cout << "|------";
	cout << '|' << endl << endl;
}