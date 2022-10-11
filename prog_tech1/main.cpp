#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"

#include "keeper.h"
#include "myio.h"

void seeCommandList()
{
	printf("MAIN MENU\n");
	printf("commands:\n0 see command list\n-1  - exit\n");
}

int menu()
{
	seeCommandList();

	Keeper zoo;

	int take = 0;
	int n = -1;

	while (1)
	{
		
		mscanf("%d", &take);

		switch (take)
		{
		case 0:
			seeCommandList();
			break;

		case -1: // exit
			return 0;

		case 1:
			// setFile save path
			// would you like to set load and save the same?
			break;

		case 2:
			// setFile load path
			// would you like to set load and save the same?
			break;

		case 3:
			// save to file
			break;

		case 4:
			// load from file
			break;

		case 5:
			zoo.printAllAnimalsToScreen();
			break;

		case 6:// add new animal
			zoo.addAnimalMenu();
			break;

		case 7:
			zoo.editAnimal();
			break;

		case 8:
			// delete an animal
			zoo.deleteAnimal();
			break;

		case 9:
			zoo.printAllAnimalsToScreen();
			break;

		default:
			printf("unknown command\n");
			break;
		}

		printf("MAIN MENU\n");

	}


	return 0;
}


int main()
{

	menu();


	return 0;
}

// EOF