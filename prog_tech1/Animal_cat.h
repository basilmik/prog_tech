#pragma once
#include "Animal.h"

#define BREED 0
#define COLOR 1
#define OWNER 2
#define NAME 3

class Cat : public Animal
{
private:
	void defaultFieldSet(bool _to_copy, Cat& _obj);

public:

	Cat();

	~Cat();

	Cat(Cat& _obj)
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
			return (char*)"ownerName";
		case 3:
			return (char*)"petName";
		default:
			return (char*)"unknown";
		}
	};

	void printFeatures() override
	{
		printf("CAT:\n");
		for (int i = 0; i < getFeatureNum(); i++)
			printf("%s is: -%s-\n", getFeatureName(i), features[i]);

	};

};