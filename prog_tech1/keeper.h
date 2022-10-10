
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

	int editOneAnimalField(int _id);
	int setOneAnimalFeature(int _id, int _n);
	int editAllAnimalFields(int _id);

};


// EOF