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
		animals[i]->printToScreen();
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

int Keeper::editAnimalMenu(int _n)
{
	// choose field to edit/reset

	int take = 0;
	while (1)
	{
		printf("EDIT MENU:\n");
		printf("-1 exit\n1choose field to edit\n2 edit all fields\n");
		printf("-> ");
		scanf("%d", &take);

		/*switch (take)
		{
		case -1:
			return 0;
		case 1:

			break;

		case 0:

			break;
		}*/

	}

};



// EOF