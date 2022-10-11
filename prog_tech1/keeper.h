#pragma once
#include "Animal_fish.h"
#include "Animal_bird.h"
#include "Animal_cat.h"


class Keeper
{
public:

	Keeper();

	~Keeper();

	Animal** animals;
	int numOfAnimals;

	char loadFilePath[512];
	void setLoadFilePath(char* _path);

	char saveFilePath[512];
	void setSaveFilePath(char* _path);
	
	void loadAllAnimalsFromFile(); // loadFilePath
	void saveAllAnimalsToFile(); // saveFilePath

	int isLoadFilePathSet()
	{
		return (loadFilePath != "\0");
	}

	int isSaveFilePathSet()
	{
		return (saveFilePath != "\0");
	}

	void printOneAnimalToscreen(int _id);

	void printAllAnimalsToScreen();

	


	int takeTypeToAdd();

	Animal* createAnimalOfType(int _t);

	void addAnimal();

	int addAnimalMenu();

	int deleteAnimal();
	int deleteOneAnimal(int _id);
	int deleteAnimalMenu(int _id);

	int editAnimalMenu(int _n);
	int editAnimal();

	int editOneAnimalField(int _id);

	int setOneAnimalFeature(int _id, int _n);

	int editAllAnimalFields(int _id);

};


// EOF