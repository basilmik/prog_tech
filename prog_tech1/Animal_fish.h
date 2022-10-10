
#include "Animal.h"

#define BREED 0
#define COLOR 1
#define DIET 2

class Fish : public Animal
{

public:

	Fish();
	
	~Fish();

	void printToScreen() override
	{
		printf("FISH:\n");
		printf("breed is: -%s-\n", prop[BREED]);
		printf("color is: -%s-\n", prop[COLOR]);
		printf("diet is: -%s-\n", prop[DIET]);
	};

};