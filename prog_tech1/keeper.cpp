#define _CRT_SECURE_NO_WARNINGS
#include "keeper.h"

#include "malloc.h"
#include "myio.h"

Keeper::Keeper() {
	animals = nullptr;
	numOfAnimals = 0;
};

Keeper::~Keeper() {};


void Keeper::setLoadFilePath() {};

void Keeper::setSaveFilePath() {};


void Keeper::printOneAnimalToscreen() {};

void Keeper::printAllAnimalsToScreen()
{
	for (int i = 0; i < numOfAnimals; i++)
	{
		animals[i]->printFeaturesToScreen();
	}

};

void Keeper::loadAllAnimalsFromFile() {}; // loadFilePath
void Keeper::saveAllAnimalsToFile() {}; // saveFilePath


int Keeper::takeTypeToAdd()
{
	int typeInputed = 0;

	printf("TYPE_FISH 1\nTYPE_BIRD 2\nTYPE_CAT 3\n");
	printf("enter type of animal you would like to create: ");

	/*while (typeInputed <= 0 || typeInputed > 3)
		scanf("%d", &typeInputed);*/
	scanInRange("%d", &typeInputed, 1, 3);

	return typeInputed;
}


Animal* Keeper::createAnimalByType(int _t)
{
	switch (_t)
	{
	case 1: // fish
		return (Animal*) new Fish();

		//case 2: // bird
		//	return (Animal*) new Bird();

		//case 3: // cat
		//	return (Animal*) new Cat();
	}
}

void Keeper::addAnimal()
{
	int type = takeTypeToAdd();

	Animal* animalToAdd = createAnimalByType(type);

	numOfAnimals++;
	animals = (Animal**)realloc(animals, numOfAnimals);

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

void Keeper::deleteAnimal() {};

int Keeper::setOneAnimalFeature(int _id, int _n)
{
	/*char* newVal = (char*)calloc(MAXLEN_LONG, sizeof(char));
	if (newVal == nullptr)
		throw 0;*/

	printf("enter new value: ");
	//gets_s(newVal, 511);

	char newVal[511] = { 0 };
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
	printf("number of field to edit (0 - %d):\n", animals[_id]->getFeatureFieldsNum());
	scanInRange("%d", &n, 0, animals[_id]->getFeatureFieldsNum());
	setOneAnimalFeature(_id, n);

	return 0;
}


int Keeper::editAnimalMenu(int _id)
{
	// choose field to edit/reset

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
			animals[_id]->printFeaturesToScreen();
			break;

		default:
			printf("unknown command\n");
			break;

		}

	}

	return 0;
};



// EOF