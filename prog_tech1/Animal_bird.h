
#include "Animal.h"


class Bird : public Animal
{
public:

	Bird() {
		setAnimalType(TYPE_BIRD);
		setFeatureFieldsNum(4);
	};

	~Bird() {};


	strS(breed);

	strS(color);

	strL(diet);

	strL(habitat);

	void printToScreen() override
	{
		printf("breed is: -%s-\n", breed);
		printf("color is: -%s-\n", color);
		printf("diet is: -%s-\n", diet);
		printf("habitat is: -%s-\n", habitat);
	}

};