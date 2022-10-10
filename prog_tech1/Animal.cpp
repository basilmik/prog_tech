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

	
void Animal::setField(char* _val, int _n)
{
	strcpy(prop[_n], _val);
}

// EOF