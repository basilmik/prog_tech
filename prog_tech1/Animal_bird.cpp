#include "Animal_bird.h"
#include "malloc.h"

Bird::Bird() {
	setAnimalType(TYPE_BIRD);
	int fieldNum = 4;
	setFeatureFieldsNum(fieldNum);

	prop = (char**)malloc(fieldNum * sizeof(char*));
	if (prop == nullptr)
		throw 0; // EXEPTION

	for (int i = 0; i < fieldNum; i++)
	{
		prop[i] = (char*)calloc(512, sizeof(char));
	}
};

Bird::~Bird() {};