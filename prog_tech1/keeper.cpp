#define _CRT_SECURE_NO_WARNINGS
#include "keeper.h"

#include "malloc.h"
#include "myio.h"
#include "string.h" 
#include <stdlib.h>

Keeper::Keeper() 
{
	animals = nullptr;
	numOfAnimals = 0;

	strcpy(loadFilePath, "unknown");
	strcpy(saveFilePath, "unknown");

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


int Keeper::setFilePathMenu()
{
	int take = 0;
	printf("SET FILE PATH MENU:\n");
	printf("-1 exit\n1 set LOAD file path\n2 set SAVE file path\n0 set BOTH THE SAME\n3 see LOAD path\n4 see SAVE path\n");

	char path[511] = { '\0' };

	while (1)
	{
		mscanf("%d", &take);
		switch (take)
		{
		case -1:
			system("cls");
			return 0;
		case 0:
			mscanf("%s", path);
			setLoadFilePath(path);
			setSaveFilePath(path);
			break;

		case 1:
			mscanf("%s", path);
			setLoadFilePath(path);
			break;

		case 2:
			mscanf("%s", path);
			setSaveFilePath(path);
			break;

		case 3:
			printf("::\"%s\"\n", getLoadFilePath());
			break;

		case 4:
			printf("::\"%s\"\n", getSaveFilePath());
			break;

		default:
			printf("unknown command\n");
			break;
		}

	}

}



int Keeper::loadAllAnimalsFromFile() 
{
	if (!isLoadFilePathSet())
	{
		printf("load file path is not set\n");
		return -1;
	}

	FILE* fpin = fopen(getLoadFilePath(), "r");
	if (fpin == NULL)
		return - 1; // throw memory error

	int num = 0;
	if (fscanf(fpin, "%d\n", &num) != 1 || num < 0)
	{
		fclose(fpin);
		return -1; // throw data corruption
	}

	int fieldNum = 0;
	int type = 0;
	int originalNumOfAnimals = numOfAnimals;

	for (int i = 0; i < num; i++)
	{
		if (fscanf(fpin, "%d %d\n", &type, &fieldNum) != 2 || isInRange(type, 0, 4) || isInRange(fieldNum, 2, 5))
		{
			fclose(fpin);
			return -1; // throw data corruption
		};

		// TRY OR THROW?
		addAnimalOfType(type);

		char fieldValue[511];
		for (int n = 0; n < fieldNum; n++)
		{
			if (fscanf(fpin, "%s\n", fieldValue) != 1)
				return -1; // THROW DATA COPPUPTION
			setOneAnimalFeature(originalNumOfAnimals + i - 1, n, fieldValue);
		}

	}

	fclose(fpin);
	return 0;

}; // loadFilePath


int Keeper::saveAllAnimalsToFile() {
	return 0;
}; // saveFilePath


int Keeper::takeTypeToAdd()
{
	int typeInputed = 0;

	printf("TYPE_FISH 1\nTYPE_BIRD 2\nTYPE_CAT 3\n");
	printf("enter type of animal you would like to create: ");

	scanInRange("%d", &typeInputed, 1, 3);

	return typeInputed;
}


Animal* Keeper::createAnimalOfType(int _type)
{
	switch (_type)
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

void Keeper::addAnimalOfType(int _type)
{
	Animal* animalToAdd = createAnimalOfType(_type);
	if (animalToAdd == nullptr)
		throw - 1; // throw memory error

	numOfAnimals++;
	animals = (Animal**)realloc(animals, numOfAnimals);

	if (animals == NULL)
		throw - 1; // throw memory error

	animals[numOfAnimals - 1] = animalToAdd;
}

void Keeper::addAnimal()
{
	int type = takeTypeToAdd();

	addAnimalOfType(type);
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
			system("cls");
			return 0;

		case 1:
			addAnimal();
			
			break;

		case 2:
			addAnimal();
			editOneAnimalMenu(numOfAnimals - 1);
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
			system("cls");
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

	return -1; // throw
};

int Keeper::setOneAnimalFeature(int _id, int _n, char* _fieldValue)
{
	animals[_id]->setField(_fieldValue, _n);
	return 0;
}

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


int Keeper::editOneAnimalMenu(int _id)
{
	int take = 0;
	while (1)
	{
		printf("EDIT ONE ANIMAL MENU:\n");
		printf("-1 exit\n1 edit one field\n2 edit all fields\n3 see field values\n");
		mscanf("%d", &take);

		switch (take)
		{
		case -1:
			system("cls");
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

int Keeper::editAnimalsMenu()
{
	int take = 0;
	while (1)
	{
		printf("ADIT ANIMALS MENU:");
		printf("-1 exit\n1 edit one field\n2 edit all fields\n3 see field values\n");
		mscanf("%d", &take);

		switch (take)
		{
		case -1:
			system("cls");
			return 0;

		case 1:
		{
			int n = -1;
			printf("enter id of animal to edit (from 0 to %d):\n", numOfAnimals - 1);
			scanInRange("%d", &n, 0, numOfAnimals - 1);
			editOneAnimalMenu(n);
		}
			break;


		case 3:
		{
			int n = -1;
			printf("enter id of animal to see (from 0 to %d):\n", numOfAnimals - 1);
			scanInRange("%d", &n, 0, numOfAnimals - 1);
			printOneAnimalToscreen(n);
		}
			
			break;

		default:
			printf("unknown command\n");
			break;

		}
	}

	
	return 0;
}


// EOF