
#include "Animal.h"


class Fish : public Animal
{
private:
	strS(breed);

	strS(color);

	strL(diet);

public:

	Fish() {
		setAnimalType(TYPE_FISH);
		setFeatureFieldsNum(3);
		
		//memset(&str, 0, sizeof(str));

	};

	~Fish() {};

	
	
	void printToScreen() override
	{
		printf("breed is: -%s-\n", breed);
		printf("color is: -%s-\n", color);
		printf("diet is: -%s-\n", diet);
	}

};