#ifndef elementheader
#define elementheader

struct element
{
	int x;
	int y;

	element *previous = 0; //��������� �� ���������� �������
	element *next = 0; //��������� �� ��������� �������
};
#endif

