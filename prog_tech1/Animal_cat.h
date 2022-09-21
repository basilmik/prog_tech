
#include "Animal.h"


class Cat : public Animal
{
public:

	Cat() {
		setAnimalType(TYPE_CAT);
		setFeatureFieldsNum(4);
	};

	~Cat() {};


	strS(breed);

	strS(color);

	strS(ownerName);

	strS(petName);

	void printToScreen() override
	{
		printf("breed is: -%s-\n", breed);
		printf("color is: -%s-\n", color);
		printf("ownerName is: -%s-\n", ownerName);
		printf("petName is: -%s-\n", petName);
	}
};