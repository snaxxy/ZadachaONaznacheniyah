#include "header.h"

int comparison()
{


	return
}

void create_vectors(list &lists, int **&objects_vectors, int **&subjects_vectors)
{
	for (int i = 0; i < lists.get_number(); ++i)
	{
		for (int j = 0; j < lists.get_number(); ++j)
		{
			int c_end = lists.get_criterions_number(i);
			for (int c = 0; c < c_end; ++c)
			{
				objects_vectors[i][j] = comparison

				if (lists.get_object_criterion(i, c) <= lists.get_subject_criterion(j, c)) objects_vectors[i][j] = 0;
				else objects_vectors[i][j] = lists.get_object_criterion(i, c) - lists.get_subject_criterion(j, c);

				if (lists.get_subject_criterion(i, c) <= lists.get_object_criterion(j, c)) subjects_vectors[i][j] = 0;
				else subjects_vectors[i][j] = lists.get_subject_criterion(i, c) - lists.get_object_criterion(j, c);
			}
		}
	}
}