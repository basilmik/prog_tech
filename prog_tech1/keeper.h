
#include "Animal_fish.h"





class Keeper
{
public:

	Keeper();

	~Keeper();

	Animal** animals;
	int numOfAnimals;

	char loadFilePath[512];
	void setLoadFilePath();

	char saveFilePath[512];
	void setSaveFilePath();
	

	void printOneAnimalToscreen();

	void printAllAnimalsToScreen();

	void loadAllAnimalsFromFile(); // loadFilePath
	void saveAllAnimalsToFile(); // saveFilePath


	int takeTypeToAdd();

	Animal* createAnimalByType(int _t);

	void addAnimal();



	int addAnimalMenu();

	void deleteAnimal();

	int editAnimalMenu(int _n);




};


// EOF