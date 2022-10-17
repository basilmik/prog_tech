#include "myio.h"

int mscanf(const char* _f, void* _x)
{
	while (1)
	{
		printf("-> ");
		if (scanf(_f, _x) != 1)
			printf("invalid input, try again\n");
		else
		{
			if (getchar());
			return 1;
		}
		if (getchar());
	}
}

int scanInRange(const char* _f, int* _x, int _min, int _max)
{
	if (_max < _min)
	{
		printf("\terror: incorrect input range in line %d\n", __LINE__);
		return -1;
	}
	while (1)
	{
		mscanf(_f, _x);
		if (*_x < _min || *_x > _max)
			printf("out of range\n");
		else
			return 0;
	}

}

int isInRange(int _val, int _min, int _max)
{
	return (_min < _val && _val < _max);
}