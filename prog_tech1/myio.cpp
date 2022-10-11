#include "myio.h"

int mscanf(const char* _f, void* _x)
{
	while (1)
	{
		printf("-> ");
		if (scanf(_f, _x) != 1)
			printf("invalid input, try again\n");
		else
			return 1;
		if (getchar());
	}
}

void scanInRange(const char* _f, int* _x, int _min, int _max)
{

	while (1)
	{
		mscanf(_f, _x);
		if (*_x < _min || *_x > _max)
			printf("out of range\n");
		else
			break;
	}

}

int isInRange(int _val, int _min, int _max)
{
	return (_min < _val && _val < _max);
}