#include "stdio.h"
#include <string.h>
#include "malloc.h"


#define TYPE_FISH 1
#define TYPE_BIRD 2
#define TYPE_CAT 3


#define MAXLEN_LONG 512
#define str(var_name) char var_name[MAXLEN_LONG] = {'\0'}

#define str0(var_name) var_name = {'\0'}



class Animal
{
private:
	int animalType;

	int featureFieldsNum;

	

protected:
	
	char** prop;

	Animal() 
	{ 
		animalType = 0; 
		featureFieldsNum = 0;
	};

	~Animal() {};

	void setAnimalType(int _animalType)
	{
		animalType = _animalType;
	}

	void setFeatureFieldsNum(int _featureFieldsNum)
	{
		featureFieldsNum = _featureFieldsNum;
	}

	int getAnimalType()
	{
		return animalType;
	}

	int getFeatureFieldsNum()
	{
		return featureFieldsNum;
	}




	char* operator[](int _n)
	{
		if (_n >= 0 && _n < getFeatureFieldsNum())
			return prop[_n];
		else
			return nullptr;
	}

	

	virtual void printToScreen() = 0;

	void editField() {};

public:

	void setField(int _n)
	{
		char* newVal = (char*)calloc(MAXLEN_LONG, sizeof(char));
		if (newVal == nullptr)
			throw 0;

		gets_s(newVal, 511);

		//fgets(newVal, MAXLEN_LONG, )
		//scanf("%s", newVal);

		strcpy(prop[_n - 1], newVal);

		free(newVal);
	}
};

// EOF