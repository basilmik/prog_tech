#pragma once
#include "Animal.h"

#define BREED 0
#define COLOR 1
#define DIET 2
#define HABITAT 3

class Bird : public Animal
{
private:
	void defaultFieldSet(bool _to_copy, Bird& _obj);

public:

	Bird();

	~Bird();

	Bird(Bird& _obj)
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
		case 3:
			return (char*)"habitat";
		default:
			return (char*)"unknown";
		}
	};

	void printFeatures() override
	{
		printf("BIRD:\n");
		for (int i = 0; i < getFeatureNum(); i++)
			printf("%s is: -%s-\n", getFeatureName(i), features[i]);

	};

};