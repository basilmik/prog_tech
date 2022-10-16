#pragma once
#include "Animal.h"

#define BREED 0
#define COLOR 1
#define DIET 2

class Fish : public Animal
{
private:
	void defaultFieldSet(bool _to_copy, Fish & _obj);

public:

	Fish();
	
	~Fish();

	Fish(Fish & _obj)
	{	
		defaultFieldSet(true, _obj);	
	}

	char* getFeatureName(int _n) override
	{
		switch (_n)
		{
		case 0:
			return (char*)"breed";
		case 1:
			return (char*)"color";
		case 2:
			return (char*)"diet";
		default:
			return (char*)"unknown";
		}
	};

	void printFeatures() override
	{
		printf("FISH:\n");
		for (int i = 0; i < getFeatureNum(); i++)
			printf("%s is: -%s-\n", getFeatureName(i), features[i]);

	};

};