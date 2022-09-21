
#include "Animal.h"


class Fish : public Animal
{
private:
	str(breed);

	str(color);

	str(diet);

public:

	Fish() {
		setAnimalType(TYPE_FISH);
		setFeatureFieldsNum(3);
	};

	~Fish() {};

	char* getField(int _n)
	{
		if (_n == 1)
			return breed;
		if (_n == 2)
			return color;
		if (_n == 3)
			return diet;
	}
	
	void printToScreen() override
	{
		printf("breed is: -%s-\n", breed);
		printf("color is: -%s-\n", color);
		printf("diet is: -%s-\n", diet);
	}

	void setField(int _n)
	{
		char* editField = getField(_n);		
		char* newVal = (char *)calloc(MAXLEN_LONG, sizeof(char));

		scanf("%s", newVal);

		strcpy(editField, newVal);
	}

};