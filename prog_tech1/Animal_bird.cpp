#define _CRT_SECURE_NO_WARNINGS
#include "Animal_bird.h"
#include "malloc.h"

Exeption* eb = new Exeption("Animal_bird.h");

Bird::Bird() {
	setAnimalType(TYPE_BIRD);

	int fieldNum = 4;
	setFeatureNum(fieldNum);

	features = (char**)malloc(fieldNum * sizeof(char*));
	if (features == nullptr)
		throw eb->set("memory error", __LINE__);

	for (int i = 0; i < fieldNum; i++)
	{
		features[i] = (char*)calloc(512, sizeof(char));
		if (features[i] == NULL)
			throw eb->set("memory error", __LINE__);

		strcpy(features[i], "n/s");
	}
};

Bird::~Bird() {};