#define _CRT_SECURE_NO_WARNINGS
#include "keeper.h"
#include "myio.h"
#include "Exeption.h"

#include "malloc.h"

#include "string.h" 
#include <stdlib.h>
#include "stdio.h"

Exeption* e = new Exeption("keeper.cpp");

Keeper::Keeper() 
{
	printf("keeper constructor called\n");
	animals = nullptr;
	numOfAnimals = 0;

	strcpy(loadFilePath, "unknown");
	strcpy(saveFilePath, "unknown");
};

Keeper::~Keeper() 
{
	printf("keeper destructor called\n");
	for (int i = 0; i < numOfAnimals; i++)
		delete animals[i];
};

void Keeper::print(int _id) 
{
	animals[_id]->printFeatures();
	printf("\n");
};

void Keeper::printAll()
{
	for (int i = 0; i < numOfAnimals; i++)
		print(i);
	if (numOfAnimals == 0)
		printf("no animals added yet\n");
};


void Keeper::setLoadFilePath(char* _path)
{
	strcpy(loadFilePath, _path);
};

void Keeper::setSaveFilePath(char* _path) 
{
	strcpy(saveFilePath, _path);
};




int Keeper::setFilePathMenu()
{
	int take = 0;
	printf("SET FILE PATH MENU:");
	printf("\n-1 exit\n1 set LOAD file path\n2 set SAVE file path\n0 set BOTH THE SAME\n3 see LOAD path\n4 see SAVE path\n");

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
			printf("enter new path:\n");
			mscanf("%s", path);
			setLoadFilePath(path);
			setSaveFilePath(path);
			break;

		case 1:
			printf("enter new path:\n");
			mscanf("%s", path);
			setLoadFilePath(path);
			break;

		case 2:
			printf("enter new path:\n");
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

	throw e->set("menu call error", __LINE__);
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
	{
		printf("could not open file\n");
		return -1;
	}

	int num = 0;
	if (fscanf(fpin, "!%d\n", &num) != 1 || num < 0)
	{
		fclose(fpin);
		
		throw e->set("data corruption error", __LINE__);
	}

	int fieldNum = 0;
	int type = 0;
	int originalNumOfAnimals = numOfAnimals;
	char fieldValue[511] = {0};

	for (int i = 0; i < num; i++)
	{
		if (fscanf(fpin, "%d-%d-\n", &type, &fieldNum) != 2 || !isInRange(type, 0, 4) || !isInRange(fieldNum, 2, 5))
		{
			fclose(fpin);
			throw e->set("data corruption error", __LINE__);
		};

		addAnimal(type);

		for (int n = 0; n < fieldNum; n++)
		{
			if (fgets(fieldValue, 510, fpin) == NULL)
			{
				fclose(fpin);
				throw e->set("data corruption error", __LINE__);
			}
			int len = strlen(fieldValue);

			if (len < 2)
			{
				fclose(fpin);
				throw e->set("data corruption error", __LINE__);
			}

			if (len == 2 && fieldValue[0] == '-')
				setOneFeature(originalNumOfAnimals + i, n, (char*)"n/s\0");
			else
			{
				fieldValue[len - 1] = '\0';
				setOneFeature(originalNumOfAnimals + i, n, fieldValue);
			}
		}

	}

	fscanf(fpin, "%s", fieldValue);
	if (strcmp(fieldValue, "EOF") != 0)
	{
		fclose(fpin);
		throw e->set("data corruption error, possible loss of data", __LINE__);
	}

	fclose(fpin);
	return 0;

};


int Keeper::saveAllAnimalsToFile() 
{
	if (!isSaveFilePathSet())
	{
		printf("save file path is not set\n");
		return -1;
	}

	FILE* fpout = fopen(getSaveFilePath(), "w");
	if (fpout == NULL)
	{
		printf("could not open file\n");
		return -1;
	}

	fprintf(fpout, "!%d\n", numOfAnimals);

	for (int i = 0; i < numOfAnimals; i++)
	{
		int type = animals[i]->getAnimalType();
		int fieldNum = animals[i]->getFeatureNum();

		fprintf(fpout, "%d-%d-\n", type, fieldNum);

		for (int j = 0; j < fieldNum; j++)
		{
			if (strcmp(animals[i]->features[j], "") == 0)	
				fprintf(fpout, "-\n");
			else
				fprintf(fpout, "%s\n", animals[i]->features[j]);
		}
	}

	fprintf(fpout, "EOF");
	fclose(fpout);
	return 0;
};



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

	throw e->set("type to create error", __LINE__);
}

void Keeper::addAnimal(int type = 0)
{
	Animal* animalToAdd;
	if (type == 0)
	type = askTypeToCreate();
	if (type ==-1)
		throw e->set("type input error", __LINE__);

	try {
		animalToAdd = createAnimalOfType(type);
	}
	catch (Exeption _e)
	{
		throw _e;
	}

	if (animalToAdd == nullptr)
		throw e->set("memory error", __LINE__);
	
	if (animals == NULL && numOfAnimals != 0)
	{
		throw e->set("memory error", __LINE__);
	}
	
	numOfAnimals++;

	Animal** animals_new = (Animal**)calloc(numOfAnimals, sizeof(Animal*));
	
	if (animals_new == NULL)
	{
		throw e->set("memory error", __LINE__);
	}
	

	for (int i = 0; i < numOfAnimals-1; i++)
	{
		animals_new[i] = new Animal;
		animals_new[i] = animals[i];
	}

	free(animals);

	animals = animals_new;
	animals[numOfAnimals - 1] = animalToAdd;

}


void Keeper::copyAdd(Animal & _obj)
{

	Animal* animalToAdd = nullptr;

	switch (_obj.getAnimalType())
	{
	case TYPE_FISH:
		animalToAdd = new Fish((Fish&)_obj);
		break;
	case TYPE_CAT:
		animalToAdd = new Cat((Cat&)_obj);
		break;
	case TYPE_BIRD:
		animalToAdd = new Bird((Bird&)_obj);
		break;
	}
	
	
	if (animalToAdd == nullptr)
		throw e->set("memory error", __LINE__);

	if (animals == NULL && numOfAnimals != 0)
	{
		throw e->set("memory error", __LINE__);
	}

	numOfAnimals++;

	Animal** animals_new = (Animal**)calloc(numOfAnimals, sizeof(Animal*));

	if (animals_new == NULL)
	{
		throw e->set("memory error", __LINE__);
	}


	for (int i = 0; i < numOfAnimals - 1; i++)
	{
		animals_new[i] = new Animal;
		animals_new[i] = animals[i];
	}

	free (animals);
	
	animals = animals_new;
	animals[numOfAnimals - 1] = animalToAdd;
}

int Keeper::copyMenu()
{
	int take = 0;

	while (1)
	{
		printf("COPY ANIMAL MENU:");
		printf("\n-1 back to menu\n1 enter num to copy\n2 see all\n");

		mscanf("%d", &take);

		switch (take)
		{
		case -1:
			system("cls");
			return 0;

		case 1:
		{
			int id = -1;
			printf("enter id of animal to edit (from 0 to %d):\n", numOfAnimals - 1);
			if (scanInRange("%d", &id, 0, numOfAnimals - 1) == 0)
			copyAdd(*animals[id]);
		}
			break;

		case 2:
			printAll();
			break;

		default:
			printf("unknown command\n");
			break;
		}
	}

	throw e->set("menu call error", __LINE__);
}



int Keeper::askTypeToCreate()
{
	int typeInputed = 0;

	printf("TYPE_FISH 1\nTYPE_BIRD 2\nTYPE_CAT 3\n");
	printf("enter type of animal you would like to create:\n");

	
	if (scanInRange("%d", &typeInputed, 1, 3) == 0)
		return typeInputed;
	else
		return -1;
}


int Keeper::addMenu() {

	int take = 0;

	while (1)
	{
		printf("ADD ANIMAL MENU:");
		printf("\n-1 back to menu\n1 add animal\n2 add and set animal\n");
			
		mscanf("%d", &take);

		switch (take)
		{
		case -1:
			system("cls");
			return 0;

		case 1:
			try {
				addAnimal();
			}
			catch (Exeption _e)
			{
				throw _e;
			}
			
			break;

		case 2:
			try {
				addAnimal();
			}
			catch (Exeption _e)
			{
				throw _e;
			}
			system("cls");
			editOneMenu(numOfAnimals - 1);
			break;

		default:
			printf("unknown command\n");
			break;
		}
	}

	throw e->set("menu call error", __LINE__);
};




int Keeper::deleteOne(int _id) 
{
	delete animals[_id];

	for (int i = _id; i < numOfAnimals - 1; i++)
		animals[i] = animals[i + 1];

	numOfAnimals--;

	return 0;
};

int Keeper::deleteMenu() 
{
	int take = 0;
	while (1)
	{
		if (numOfAnimals == 0)
		{
			system("cls");
			printf("number of animals is zero\nback to main menu\n");
			return 0;
		}
		printf("DELETE MENU:");
		printf("\n-1 exit\n1 choose animal to delete\n2 see all\n3 delete all\n");
		mscanf("%d", &take);
		
		
		switch (take)
		{
		case -1:
			system("cls");
			return 0;

		case 1:
		{
			int id = -1;
			printf("enter id of animal to delete (from 0 to %d):\n", numOfAnimals - 1);
			if (scanInRange("%d", &id, 0, numOfAnimals - 1) == 0)
			deleteOne(id);
		}
			break;

		case 2:
			printAll();
			break;

		case 3:
		{
			printf("are you sure you want to delete all?\n0 NO\n1 YES\n");
			int take = 0;
			mscanf("%d", &take);
			switch (take)
			{
			case 0: break;
			case 1:
			{
				int originalNum = numOfAnimals;
				for (int i = originalNum-1; i >= 0; i--)
					deleteOne(i);
			}	break;
			default:
				printf("unknown command");
				break;
			}
			break;
		}

		default:
			printf("unknown command\n");
			break;
		}
	}

	throw e->set("menu call error", __LINE__);
};




void Keeper::setOneFeature(int _id, int _n, char* _fieldValue)
{
	animals[_id]->setFeature(_fieldValue, _n);
}

void Keeper::setOneFeature(int _id, int _n)
{
	char newVal[511] = { 0 };
	printf("enter new %s:\n->", animals[_id]->getFeatureName(_n));
	gets_s(newVal);

	setOneFeature(_id, _n, newVal);
}

void Keeper::setEachFeature(int _id)
{
	for (int n = 0; n < animals[_id]->getFeatureNum(); n++)
		setOneFeature(_id, n);
}


int Keeper::editOneMenu(int _id)
{
	int take = 0;
	system("cls");

	while (1)
	{
		printf("EDIT ONE ANIMAL MENU:");
		printf("\n-1 exit\n1 edit one field\n2 edit all fields\n3 see field values\n");
		mscanf("%d", &take);

		switch (take)
		{
		case -1:
			system("cls");
			return 0;

		case 1:
		{
			int n = -1;
			printf("number of field to edit (0 - %d):\n", animals[_id]->getFeatureNum() - 1);
			if (scanInRange("%d", &n, 0, animals[_id]->getFeatureNum()) == 0)
			setOneFeature(_id, n);
		}			
			break;

		case 2:
			setEachFeature(_id);
			break;

		case 3:
			print(_id);
			break;

		default:
			printf("unknown command\n");
			break;
		}
	}

	throw e->set("menu call error", __LINE__);
};

int Keeper::editMenu()
{
	int take = 0;
	while (1)
	{
		printf("EDIT ANIMALS MENU:");
		printf("\n-1 exit\n1 choose animal to edit\n2 see all\n");
		mscanf("%d", &take);

		switch (take)
		{
		case -1:
			system("cls");
			return 0;

		case 1:
		{
			int id = -1;
			printf("enter id of animal to edit (from 0 to %d):\n", numOfAnimals - 1);
			
			if (scanInRange("%d", &id, 0, numOfAnimals - 1) == 0)
			try 
			{
				editOneMenu(id);
			}
			catch (Exeption _e)
			{
				throw _e;
			}
		}
			break;


		case 2:
			printAll();
			break;

		default:
			printf("unknown command\n");
			break;

		}
	}

	
	throw e->set("menu call error", __LINE__);
}


// EOF