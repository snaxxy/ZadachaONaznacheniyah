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

			if (!isObject) cout << 'o' << vec[i][0].ID << vec[j][0].ID << " = { ";
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


void preference(int *&preference, vector<vector<item>> subjectVector, vector<vector<item>> objectVector)
{
	int N = items::getAmount();
	
	while (N > 0)
	{
		string **objectMatrix = new string *[N];
		string **subjectMatrix = new string *[N];
		for (int count = 0; count < N; ++count)
		{
			objectMatrix[count] = new string[N];
			subjectMatrix[count] = new string[N];
		}
		
		generateLayers(N, objectMatrix, subjectVector);
		generateLayers(N, subjectMatrix, objectVector);

		for (int i = 0; i < N; ++i)
		{
			for (int j = i+1; j < N; ++j) objectMatrix[i][j].swap(objectMatrix[j][i]);
		}

		printMatrix(N, subjectVector, objectMatrix, objectVector, subjectMatrix);

		char str1[7] = { 'D', 'D', 'H', 'H', 'D', ' ', 'H' };
		string str2;

		vector<element> preferenceVector;

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
						if (objectMatrix[i][j] == (str1[k1] + str2) && subjectMatrix[i][j] == (str1[k2] + str2) && objectMatrix[i][j][1] == str2[0] && subjectMatrix[i][j][1] == str2[0])
						{
							preferenceVector.push_back(element(j, i));
							check = true;
						}
					}
				}
			}
		}

		for (int k = 0, i; k < preferenceVector.size(); ++k)
		{
			for (i = 0; i < preferenceVector.size() && k < preferenceVector.size(); ++i)
			{
				if (k != i && preferenceVector.at(k).x == preferenceVector.at(i).x)
				{
					int temp = 0;
					for (int j = 0; j < subjectVector[0][0].criterionAmount; ++j)
					{
						temp += subjectVector[preferenceVector.at(k).x][preferenceVector.at(k).y].criteriaVector[j] - subjectVector[preferenceVector.at(i).x][preferenceVector.at(i).y].criteriaVector[j];
					}

					if (temp > 0)
					{
						preferenceVector.erase(preferenceVector.begin()+i);
						--i;
					}
					else
					{
						preferenceVector.erase(preferenceVector.begin() + k);
						i = -1;
					}					
					continue;
				}

				if (k != i && preferenceVector.at(k).y == preferenceVector.at(i).y)
				{
					int temp = 0;
					for (int j = 0; j < objectVector[0][0].criterionAmount; ++j)
					{
						temp += objectVector[preferenceVector.at(k).x][preferenceVector.at(k).y].criteriaVector[j] - objectVector[preferenceVector.at(i).x][preferenceVector.at(i).y].criteriaVector[j];
					}

					if (temp > 0)
					{
						preferenceVector.erase(preferenceVector.begin() + i);
						--i;
					}
					else
					{
						preferenceVector.erase(preferenceVector.begin() + k);
						i = -1;
					}
					continue;
				}
			}
		}

		for (int i = 0; i < preferenceVector.size(); ++i)
		{
			preference[subjectVector[preferenceVector.at(i).x][0].ID - 1] = objectVector[preferenceVector.at(i).y][0].ID;
		}

		for (int i = 0, iter_x, iter_y; i < preferenceVector.size(); ++i)
		{
			iter_x = getPosOfMax(preferenceVector, 'x');
			iter_y = getPosOfMax(preferenceVector, 'y');

			for (int n = 0; n < N; ++n)
			{
				subjectVector[n].erase(subjectVector[n].begin() + preferenceVector.at(iter_y).y);
				objectVector[n].erase(objectVector[n].begin() + preferenceVector.at(iter_x).x);
			}
			subjectVector.erase(subjectVector.begin() + preferenceVector.at(iter_x).x);
			objectVector.erase(objectVector.begin() + preferenceVector.at(iter_y).y);

			preferenceVector.at(iter_x).x = -1;
			preferenceVector.at(iter_y).y = -1;

			--N;
		}

		printVector(N, false, subjectVector);
		printVector(N, true, objectVector);
		
		for (int count = 0; count < N; ++count)
		{
			delete[] objectMatrix[count];
			delete[] subjectMatrix[count];
		}
		delete[] objectMatrix;
		delete[] subjectMatrix;
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