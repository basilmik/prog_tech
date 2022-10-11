
#include "Animal_cat.h"
#include "stdio.h"
#include "malloc.h"

	Cat::Cat() {
		setAnimalType(TYPE_CAT);
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

	Cat::~Cat() {};


	
