
#include "Animal.h"


class Bird : public Animal
{
public:

	Bird() {
		animalType = TYPE_BIRD;
		featureFieldsNum = 4;
	};

	~Bird() {};


	strS(breed);

	strS(color);

	strL(diet);

	strL(habitat);

};