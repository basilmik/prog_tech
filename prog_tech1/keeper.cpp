#define _CRT_SECURE_NO_WARNINGS
#include "keeper.h"

#include "malloc.h"
#include "myio.h"
#include "string.h" 

Keeper::Keeper() 
{
	animals = nullptr;
	numOfAnimals = 0;

	strcpy(loadFilePath, "\0");
	strcpy(saveFilePath, "\0");

};

Keeper::~Keeper() 
{
	for (int i = 0; i < numOfAnimals; i++)
	{
		delete animals[i];
	}

};

void Keeper::printOneAnimalToscreen(int _id) 
{
	animals[_id]->printFeaturesToScreen();
};

void Keeper::printAllAnimalsToScreen()
{
	for (int i = 0; i < numOfAnimals; i++)
		printOneAnimalToscreen(i);
};


void Keeper::setLoadFilePath(char* _path)
{
	strcpy(loadFilePath, _path);
};

void Keeper::setSaveFilePath(char* _path) 
{
	strcpy(loadFilePath, _path);
};






void Keeper::loadAllAnimalsFromFile() 
{


}; // loadFilePath
void Keeper::saveAllAnimalsToFile() {}; // saveFilePath


int Keeper::takeTypeToAdd()
{
	int typeInputed = 0;

	printf("TYPE_FISH 1\nTYPE_BIRD 2\nTYPE_CAT 3\n");
	printf("enter type of animal you would like to create: ");

	scanInRange("%d", &typeInputed, 1, 3);

	return typeInputed;
}


Animal* Keeper::createAnimalOfType(int _t)
{
	switch (_t)
	{
	case 1:
		return (Animal*) new Fish();

	case 2:
		return (Animal*) new Bird();

	case 3:
		return (Animal*) new Cat();
	}

	return nullptr; // throw
}

void Keeper::addAnimal()
{
	int type = takeTypeToAdd();

	Animal* animalToAdd = createAnimalOfType(type);
	if (animalToAdd == nullptr)
		throw -1;

	numOfAnimals++;
	animals = (Animal**)realloc(animals, numOfAnimals);
	
	if (animals == NULL)
		throw -1;

	animals[numOfAnimals - 1] = animalToAdd;
}

int Keeper::addAnimalMenu() {

	int take = 0;

	while (1)
	{
		printf("ADD ANIMAL MENU: ");
		printf("\n-1 back to menu\n1 add animal\n2 add and set animal\n");
			
		mscanf("%d", &take);

		switch (take)
		{
		case -1:
			return 0;

		case 1:
			addAnimal();
			break;

		case 2:
			addAnimal();
			editAnimalMenu(numOfAnimals - 1);
			break;

		default:
			printf("unknown command\n");
			break;

		}
	}

	return -1; // throw
};




int Keeper::deleteOneAnimal(int _id) 
{
	delete animals[_id];
	for (int i = _id; i < numOfAnimals - 1; i++)
		animals[i] = animals[i + 1];
	numOfAnimals--;
	return 0;
};

int Keeper::deleteAnimal() {
	int id = -1;
	printf("enter id of animal to delete (from 0 to %d):\n", numOfAnimals-1);
	scanInRange("%d", &id, 0, numOfAnimals-1);

	deleteAnimalMenu(id);
	return 0;
};

int Keeper::deleteAnimalMenu(int _id) 
{
	int take = 0;
	while (1)
	{
		printf("DELETE MENU:\n");
		printf("-1 exit\n1 delete %d animal\n2 see field values\n", _id);
		mscanf("%d", &take);

		switch (take)
		{
		case -1:
			return 0;

		case 1:
			deleteOneAnimal(_id);
			break;

		case 2:
			printOneAnimalToscreen(_id);
			break;

		default:
			printf("unknown command\n");
			break;

		}

	}


	return 0;
};



int Keeper::setOneAnimalFeature(int _id, int _n)
{

	char newVal[511] = { 0 };
	printf("enter new value: ");

	mscanf("%s", &newVal);
	animals[_id]->setField(newVal, _n);

	return 0;
}

int Keeper::editAllAnimalFields(int _id)
{
	for (int i = 0; i < animals[_id]->getFeatureFieldsNum(); i++)
		setOneAnimalFeature(_id, i);

	return 0;
}

int Keeper::editOneAnimalField(int _id)
{
	int n = -1;
	printf("number of field to edit (0 - %d):\n", animals[_id]->getFeatureFieldsNum()-1);
	scanInRange("%d", &n, 0, animals[_id]->getFeatureFieldsNum());
	setOneAnimalFeature(_id, n);

	return 0;
}


int Keeper::editAnimalMenu(int _id)
{
	int take = 0;
	while (1)
	{
		printf("EDIT MENU:\n");
		printf("-1 exit\n1 edit one field\n2 edit all fields\n3 see field values\n");
		mscanf("%d", &take);

		switch (take)
		{
		case -1:
			return 0;

		case 1:
			editOneAnimalField(_id);
			break;

		case 2:
			editAllAnimalFields(_id);
			break;

		case 3:
			printOneAnimalToscreen(_id);
			
			break;

		default:
			printf("unknown command\n");
			break;

		}

	}

	return 0;
};

int Keeper::editAnimal()
{
	int n = -1;
	printf("enter id of animal to edit (from 0 to %d):\n", numOfAnimals-1);
	scanInRange("%d", &n, 0, numOfAnimals-1);
	editAnimalMenu(n);
	return 0;
}


// EOF