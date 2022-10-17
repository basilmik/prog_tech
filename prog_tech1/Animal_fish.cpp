#define _CRT_SECURE_NO_WARNINGS
#include "Animal_fish.h"
#include "stdio.h"
#include "malloc.h"

#define BREED 0
#define COLOR 1
#define DIET 2

Exeption* ef = new Exeption("Animal_fish.cpp");


void Fish::defaultFieldSet(bool _to_copy, Fish & _obj = *((Fish*)nullptr))
{
	setAnimalType(TYPE_FISH);
	int fieldNum = 3;
	setFeatureNum(fieldNum);

	features = (char**)malloc(fieldNum * sizeof(char*));
	if (features == nullptr)
		throw ef->set("memory error", __LINE__);

	for (int i = 0; i < fieldNum; i++)
	{
		features[i] = (char*)calloc(512, sizeof(char));
		if (features[i] == NULL)
			throw ef->set("memory error", __LINE__);

		if (_to_copy == true)
			strcpy(features[i], _obj.features[i]);
		else
			strcpy(features[i], "n/s");
	}
}

Fish::Fish() 
{
	printf("fish constructor called\n");

	defaultFieldSet(false);
};


Fish::~Fish() { 
	printf("fish destructor called\n"); 
};
