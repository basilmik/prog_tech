#define _CRT_SECURE_NO_WARNINGS
#include "Animal_fish.h"
#include "stdio.h"
#include "malloc.h"

#define BREED 0
#define COLOR 1
#define DIET 2


Fish::Fish() {
	setAnimalType(TYPE_FISH);
	int fieldNum = 3;
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


Fish::~Fish() {};



