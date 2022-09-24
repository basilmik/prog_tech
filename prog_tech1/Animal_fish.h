#include "Animal.h"
#define BREED 0
#define COLOR 1
#define DIET 2

class Fish : public Animal
{
private:


public:

	Fish() {
		setAnimalType(TYPE_FISH);
		int fieldNum = 3;
		setFeatureFieldsNum(fieldNum);
		
		prop = (char**)malloc(fieldNum * sizeof(char*));
		if (prop == nullptr)
			throw 0; // EXEPTION

		for (int i = 0; i < fieldNum; i++)
		{
			prop[i] = (char*)calloc(512 , sizeof(char));
		}
	};

	
	~Fish() {};

	

	void printToScreen() override
	{
		printf("breed is: -%s-\n", prop[BREED]);
		printf("color is: -%s-\n", prop[COLOR]);
		printf("diet is: -%s-\n", prop[DIET]);
	}

	void setField(int _n)
	{
		char* newVal = (char *)calloc(MAXLEN_LONG, sizeof(char));
		scanf("%s", newVal);

		strcpy(prop[_n-1], newVal);

		free(newVal);
	}

};