#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"

#include "keeper.h"
#include "myio.h"
#include <stdlib.h>


void seeCommandList()
{
	printf("MAIN MENU\n");
	printf("commands:\n0 - see command list\n100 - clear screen\n-1  - exit\n1 - file path's menu\n2 - save all animals to file\n3 - load all animals from file\n");
	printf("4 - print animals to screen\n5 - add menu\n6 - edit menu\n7 - delete menu\n8 - ----\n");
	printf("101 - preset lofe path to load.txt and save.txt\n");
}

int menu()
{
	Keeper zoo;

	int take = 0;
	int n = -1;
	seeCommandList();
	while (1)
	{
		//system("cls");
		
		mscanf("%d", &take);

		switch (take)
		{
		case 0:
			seeCommandList();
			break;

		case -1: // exit
			return 0;

		case 1:
			zoo.setFilePathMenu();
			break;

		case 2:
			// save to file
			break;

		case 3:
			zoo.loadAllAnimalsFromFile();
			// load from file
			break;

		case 4:
			zoo.printAllAnimalsToScreen();
			break;

		case 5:// add new animal
			zoo.addAnimalMenu();
			break;

		case 6:
			zoo.editAnimalsMenu();
			break;

		case 7:
			// delete an animal
			zoo.deleteAnimal();
			break;

		case 8:
			//zoo.printAllAnimalsToScreen();
			break;
		
		case 100:
			system("cls");
			break;

		case 101:
			zoo.presetPath();
			break;

		default:
			printf("unknown command\n");
			break;
		}
		
		

	}


	return 0;
}


int main()
{

	menu();


	return 0;
}

// EOF