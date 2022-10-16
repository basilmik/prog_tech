#define _CRT_SECURE_NO_WARNINGS
#include "Animal_cat.h"
#include "stdio.h"
#include "malloc.h"

Exeption* ec = new Exeption("Animal_cat.cpp");

Cat::Cat() 
{
	printf("cat constructor called\n");

	setAnimalType(TYPE_CAT);

	int fieldNum = 4;
	setFeatureNum(fieldNum);

	features = (char**)malloc(fieldNum * sizeof(char*));
	if (features == nullptr)
		throw ec->set("memory error", __LINE__);

	for (int i = 0; i < fieldNum; i++)
	{
		features[i] = (char*)calloc(512, sizeof(char));
		if (features[i] == NULL)
			throw ec->set("memory error", __LINE__);

		strcpy(features[i], "n/s");
	}
};

Cat::~Cat() { printf("cat destructor called\n"); };
