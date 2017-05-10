#include "list.h"

int list::size() { return number; }

void list::add(int x, int y, int pos)
{
	element *new_element = new element;

	if (number == 0)
	{
		first_element = new_element;
		last_element = new_element;
	}
	else if (pos != -1)
	{
		element *temp = first_element;
		for (int i = 0; i < pos; ++i) temp = first_element->next;

		if (pos == 0)
		{
			first_element = new_element;
		}
		else
		{
			new_element->previous = temp->previous;
			temp->previous->next = new_element;
		}

		new_element->next = temp;
		temp->previous = new_element;

		delete temp;
	}
	else
	{
		last_element->next = new_element;
		new_element->previous = last_element;
		last_element = new_element;
	}

	new_element->x = x;
	new_element->y = y;

	++number;
}

int list::get(int i, int j)
{
	element *temp = first_element;
	for (int count = 0; count < i; ++count) temp = temp->next;
	
	int z;
	if (j == 1) z = temp->y;
	else z = temp->x;

	return z;
}

int list::get_max(char ch)
{
	int max = -1, iter = 0;
	element *temp = first_element;

	if (ch == 'x' && temp->x > max) max = temp->x;
	else if (ch == 'y' && temp->y > max) max = temp->y;

	for (int i = 1; temp->next; ++i)
	{
		temp = temp->next;

		if (ch == 'x' && temp->x > max)
		{
			max = temp->x;
			iter = i;
		}
		else if (ch == 'y' && temp->y > max)
		{
			max = temp->y;
			iter = i;
		}
	}

	return iter;
}

void list::set(int iter, char ch)
{
	element *temp = first_element;
	for (int i = 0; i < iter; ++i) temp = temp->next;

	if (ch == 'x') temp->x = -1;
	else temp->y = -1;
}

void list::sort()
{
	double fakt = 1.2473309; //Фактор уменьшения
	int number_temp = number, step = number-1, i, swap;

	element *el1, *el2;
	do
	{
		i = 0; swap = 0;

		for (; step+i < number_temp; ++i)
		{
			el1 = first_element;
			for (int j = 0; j < i; ++j) el1 = el1->next;
			el2 = first_element;
			for (int j = 0; j < i+step-1; ++j) el2 = el2->next;

			if ((el2->x >= el1->x && el2->y > el1->y) || (el2->x > el1->x && el2->y >= el1->y))
			{
				int x = el1->x, y = el1->y;

				el1->x = el2->x;
				el1->y = el2->y;

				el2->x = x;
				el2->y = y;

				++swap;

				{
					/*element *tempP = el2->previous, *tempN = el2->next;
					if (i > 0)
					{
					el1->previous->next = el2;
					el2->previous = el1->previous;
					}
					el2->next = el1->next;
					el1->next->previous = el2;

					el2->previous->next = el1;
					el1->previous = tempP->previous;
					if (i + step < number - 1)
					{
					el1->next = tempN->next;
					el2->next->previous = el1;
					}*/
				}
			}
		}

		if (step != 1) step /= fakt;
		else --number_temp;
	} while(swap > 0 || step > 1);
}

void list::del(int pos)
{
	element *temp;
	if (pos != -1)
	{
		temp = first_element;
		for (int i = 0; i < pos; ++i) temp = temp->next;
	}
	else temp = last_element;

	if (number > 1)
	{
		if (pos == 0)
		{
			first_element = temp->next;
			first_element->previous = NULL;
		}
		else if (pos == number - 1)
		{
			last_element = temp->previous;
			last_element->next = NULL;
		}
		else
		{
			temp->previous->next = temp->next;
			temp->next->previous = temp->previous;
		}
	}
	delete temp;

	--number;
}

void list::clear()
{
	if (number > 0)
	{
		element *temp = first_element;

		while (temp->next)
		{
			temp = temp->next;
			delete temp->previous;
		}

		delete temp->next;
		delete temp;

		number = 0;
		first_element = NULL;
		last_element = NULL;
	}
}

list::~list()
{
	this->clear();

	delete first_element;
	delete last_element;
}