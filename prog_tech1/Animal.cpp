#define _CRT_SECURE_NO_WARNINGS

#include "Animal.h"

#include "string.h"
#include "malloc.h"


Animal::Animal()
{
	animalType = 0;
	featureFieldsNum = 0;
	prop = nullptr;

};

Animal::~Animal() {};



char* Animal::operator[](int _n)
{
	if (_n >= 0 && _n < getFeatureFieldsNum())
		return prop[_n];
	else
		return nullptr;
}


void Animal::editField() {};


void Animal::setAnimalType(int _animalType)
{
	animalType = _animalType;
}

void Animal::setFeatureFieldsNum(int _featureFieldsNum)
{
	featureFieldsNum = _featureFieldsNum;
}

int Animal::getAnimalType()
{
	return animalType;
}

int Animal::getFeatureFieldsNum()
{
	return featureFieldsNum;
}

	
void Animal::setField(int _n)
{
	char* newVal = (char*)calloc(MAXLEN_LONG, sizeof(char));
	if (newVal == nullptr)
		throw 0;

	gets_s(newVal, 511);

	strcpy(prop[_n - 1], newVal);

	free(newVal);
}

// EOF