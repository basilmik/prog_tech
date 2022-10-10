#include "stdio.h"
#include "Animal.h"
#include "Animal_fish.h"
#include "Animal_bird.h"
#include "Animal_cat.h"


class Keeper
{

	Keeper() {
		animals = nullptr;
		numOfAnimals = 0;
	};

	~Keeper();

	Animal** animals;
	int numOfAnimals;

	char loadFilePath[512];
	void setLoadFilePath() {};

	char saveFilePath[512];
	void setSaveFilePath() {};
	

	void printOneAnimalToFile(/*path*/) {};

	void printOneAnimalToscreen() {};

	void printAllAnimalsToFile() {};
	void printAllAnimalsToScreen() {};

	void loadAllAnimalsFromFile() {}; // loadFilePath
	void saveAllAnimalsToFile() {}; // saveFilePath


	int takeTypeToAdd()
	{
		int typeInputed = 0;

		printf("TYPE_FISH 1\nTYPE_BIRD 2\nTYPE_CAT 3\n");
		printf("enter type of animal you would like to create: ");

		while (typeInputed <= 0 || typeInputed > 3)
			scanf("%d", &typeInputed);

		return typeInputed;
	}


	Animal* createAnimalByType(int _t)
	{
		switch (_t)
		{
		case 1: // fish
			return new Fish();

		case 2: // bird
			return new Bird();

		case 3: // cat
			return new Cat();

		}
	}

	void addAnimal(int _t) 
	{
		Animal* animalToAdd = createAnimalByType(_t);

		numOfAnimals++;
		animals[numOfAnimals - 1] = animalToAdd;

	}

	int addAnimalMenu() {
		
		int take = 0;

		printf("0 see command list\n-1 back to menu\n1 add animal\n");
		while (1)
		{
			scanf("%d", &take);
			switch (take)
			{
			case 0:
				printf("0 see command list\n-1 back to menu\n1 add animal\n");
				break;

			case -1:
				return 0;
			
			case 1:
				int type = takeTypeToAdd();
				addAnimal(type);
				break;
			
			default:
				printf("unknown command\n");
				break;

			}
		}

		return -1; // throw
	};

	void deleteAnimal() {};

	void editAnimal() {};




};

// EOF