#include "stdio.h"
#include "Animal.h"
class Keeper
{

	Keeper();
	~Keeper();

	Animal* animals;
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



	void addAnimal() {};

	void deleteAnimal() {};

	void editAnimal() {};


	






};

// EOF