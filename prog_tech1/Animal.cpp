#define _CRT_SECURE_NO_WARNINGS

#include "Animal.h"

#include "string.h"
#include "malloc.h"


Animal::Animal()
{
	animalType = 0;
	featureNum = 0;
	features = nullptr;

};

Animal::~Animal() {};



char* Animal::operator[](int _n)
{
	if (_n >= 0 && _n < getFeatureNum())
		return features[_n];
	else
		return nullptr;
}



void Animal::setAnimalType(int _animalType)
{
	animalType = _animalType;
}

void Animal::setFeatureNum(int _featureNum)
{
	featureNum = _featureNum;
}

int Animal::getAnimalType()
{
	return animalType;
}

int Animal::getFeatureNum()
{
	return featureNum;
}

	
void Animal::setFeature(char* _val, int _n)
{
	strcpy(features[_n], _val);
}

// EOF