
#include "Animal.h"
#define BREED 0
#define COLOR 1
#define OWNER 2
#define NAME 3

class Cat : public Animal
{
public:

	Cat() {
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

	~Cat() {};


	void printToScreen() override
	{
		printf("breed is: -%s-\n", prop[BREED]);
		printf("color is: -%s-\n", prop[COLOR]);
		printf("ownerName is: -%s-\n", prop[OWNER]);
		printf("petName is: -%s-\n", prop[NAME]);
	}
};