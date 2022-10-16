#pragma once
#include "stdio.h"
#include "string.h"
#include "Exeption.h"

#define TYPE_FISH 1
#define TYPE_BIRD 2
#define TYPE_CAT 3


class Animal
{
private:
	int animalType;
	int featureNum;

public:	

	char** features;

	Animal();

	~Animal();



	char* operator[](int _n);


	void setAnimalType(int _animalType);

	void setFeatureNum(int _featureNum);


	int getAnimalType();

	int getFeatureNum();


	virtual void printFeatures() {};

	virtual char* getFeatureName(int _n) { return nullptr; };

	void setFeature(char* _val, int _n);
};


// EOF