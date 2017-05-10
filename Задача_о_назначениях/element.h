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
	element *previous = 0; //”казатель на предыдущий элемент
	element *next = 0; //”казатель на следующий элемент
};
#endif

