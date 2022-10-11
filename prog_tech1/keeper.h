#pragma once
#include "Animal_fish.h"
#include "Animal_bird.h"
#include "Animal_cat.h"
#include "string.h"

class Keeper
{
public:

	Keeper();

	~Keeper();

	Animal** animals;
	int numOfAnimals;
	

	void presetPath()
	{
		setLoadFilePath((char*)"load.txt");
		setSaveFilePath((char*)"save.txt");
	}

	int setFilePathMenu();

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

	void printAllAnimalsToScreen();

	


	int takeTypeToAdd();

	Animal* createAnimalOfType(int _type);

	void addAnimalOfType(int _type);

	void addAnimal();

	int addAnimalMenu();

	int deleteAnimal();
	int deleteOneAnimal(int _id);
	int deleteAnimalMenu(int _id);

	int editOneAnimalMenu(int _n);
	int editAnimalsMenu();

	int editOneAnimalField(int _id);

	int setOneAnimalFeature(int _id, int _n);
	int setOneAnimalFeature(int _id, int _n, char* _fieldValue);

	int editAllAnimalFields(int _id);

};


// EOF