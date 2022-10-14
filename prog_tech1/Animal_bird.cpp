#define _CRT_SECURE_NO_WARNINGS
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
		if (prop[i] == NULL)
			throw - 1; // throw memory exeption
		strcpy(prop[i], "n/s");
	}
};

Bird::~Bird() {};