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
	void setLoadFilePath(char* _path);

	char* getLoadFilePath()
	{
		return loadFilePath;
	}

	char saveFilePath[512];

	void setSaveFilePath(char* _path);

	char* getSaveFilePath()
	{
		return saveFilePath;
	}
	
	int loadAllAnimalsFromFile(); // loadFilePath

	int saveAllAnimalsToFile(); // saveFilePath


	int isLoadFilePathSet()
	{
		return (strcmp(loadFilePath, "unknown") != 0);
	}

	int isSaveFilePathSet()
	{
		return (strcmp(saveFilePath, "unknown") != 0);
	}


	void printOneAnimalToscreen(int _id);


	Animal* createAnimalOfType(int _type);

	void addAnimalOfType(int _type);

	void addAnimal();

	int addAnimalMenu();



	int deleteAnimal(int _id);
	int deleteAnimalsMenu();


	int setOneFeature(int _id, int _n);
	int setOneFeature(int _id, int _n, char* _fieldValue);
	int setEachField(int _id);

	int editOneMenu(int _n);
	int editMenu();

	

public:
	Keeper();

	~Keeper();

	
	int callSave()
	{
		if (numOfAnimals > 0)
			return saveAllAnimalsToFile();
	}

	int callLoad()
	{
		return loadAllAnimalsFromFile();
	}

	int callAdd()
	{
		return addAnimalMenu();
	}

	int callEdit()
	{
		if (numOfAnimals > 0)
		return editMenu();
	}

	int callDelete()
	{
		if (numOfAnimals > 0)
			return deleteAnimalsMenu();
	}


	void presetPath()
	{
		setLoadFilePath((char*)"save_load.txt");
		setSaveFilePath((char*)"save_load2.txt");
	}

	int setFilePathMenu();
	void printAllAnimalsToScreen();

};


// EOF