#ifndef elementheader
#define elementheader

struct element
{
	int x;
	int y;

public: 
	element(int paramX, int paramY)
	{
		x = paramX;
		y = paramY;
	}
	element *previous = 0; //��������� �� ���������� �������
	element *next = 0; //��������� �� ��������� �������
};
#endif

