#pragma once
#include "Animal_fish.h"
#include "Animal_bird.h"
#include "Animal_cat.h"
#include "string.h"

class Keeper
{
private:

	Animal** animals;
	int numOfAnimals;
	
	char loadFilePath[512];
	char saveFilePath[512];

	
	void setLoadFilePath(char* _path);
	char* getLoadFilePath()
	{
		return loadFilePath;
	}

	int isLoadFilePathSet()
	{
		return (strcmp(loadFilePath, "unknown") != 0);
	}
	

	void setSaveFilePath(char* _path);
	char* getSaveFilePath()
	{
		return saveFilePath;
	}
	int isSaveFilePathSet()
	{
		return (strcmp(saveFilePath, "unknown") != 0);
	}
	

	int setFilePathMenu();

	int loadAllAnimalsFromFile();
	int saveAllAnimalsToFile();

	void print(int _id);

	Animal* createAnimalOfType(int _type);
	int askTypeToCreate();

	void addAnimal(int type);
	int addMenu();


	int deleteOne(int _id);
	int deleteMenu();


	void setOneFeature(int _id, int _n);
	void setOneFeature(int _id, int _n, char* _fieldValue);
	void setEachFeature(int _id);

	int editOneMenu(int _n);
	int editMenu();


	void copyAdd(Animal& _obj);

	int copyMenu();

public:
	Keeper();

	~Keeper();

	
	void callSave()
	{
		if (numOfAnimals > 0)
			saveAllAnimalsToFile();
		else
			printf("no elements added yet\n");
	}

	void callLoad()
	{
		try {
			loadAllAnimalsFromFile();
		}
		catch (Exeption* _e)
		{
			_e->show();
		}
		catch (int i)
		{
			printf("caught %d\n", i);
		}
		
	}

	void callAdd()
	{
		try
		{
			addMenu();
		}
		catch (Exeption _e)
		{
			_e.show();
		}
	}

	void callEdit()
	{
		if (numOfAnimals > 0)
		{
			try
			{
				editMenu();
			}
			catch (Exeption _e)
			{
				_e.show();
			}
		}
		else
			printf("no elements added yet\n");
	}

	void callDelete()
	{
		if (numOfAnimals > 0)
		{
			try
			{
				deleteMenu();
			}
			catch (Exeption _e)
			{
				_e.show();
			}
		}
		else
			printf("no elements added yet\n");
	}

	void callFileMenu()
	{
		try 
		{
			setFilePathMenu();
		}
		catch (Exeption _e)
		{
			_e.show();
		}
	}

	void presetPath()
	{
		setLoadFilePath((char*)"save_load.txt");
		setSaveFilePath((char*)"save_load.txt");
	}

	void printAll();

	void callCopy()
	{
		if (numOfAnimals > 0)
		{
			try
			{
				copyMenu();
			}
			catch (Exeption _e)
			{
				_e.show();
			}
		}
		else
			printf("no elements added yet\n");
		
	}

};

// EOF