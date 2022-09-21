#include "stdio.h"
#define TYPE_FISH 1
#define TYPE_BIRD 2
#define TYPE_CAT 3

#include <string>
using std::string;

#define MAXLEN_LONG 512
#define strL(var_name) char var_name[MAXLEN_LONG] = {'\0'}
#define MAXLEN_SHORT 128
#define strS(var_name) char var_name[MAXLEN_SHORT] = {'\0'}



class Animal
{
protected:
	Animal() 
	{ 
		animalType = 0; 
		featureFieldsNum = 0;
	};

	~Animal() {};

	int animalType;

	int featureFieldsNum;

	void printToScreen() {};
	void createOfType() {};
	void editField() {};
};

// EOF