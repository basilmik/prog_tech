#include "stdio.h"

#define TYPE_FISH 1
#define TYPE_BIRD 2
#define TYPE_CAT 3


#define MAXLEN_LONG 512



class Animal
{
private:
	int animalType;

	int featureFieldsNum;

public:	

	char** prop;

	Animal();

	~Animal();

	char* operator[](int _n);

	void editField();


	void setAnimalType(int _animalType);

	void setFeatureFieldsNum(int _featureFieldsNum);

	int getAnimalType();

	int getFeatureFieldsNum();

	virtual void printToScreen() {};

	void setField(int _n);
};

;

// EOF