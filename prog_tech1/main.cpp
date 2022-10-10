#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "Animal_fish.h"

void seeCommandList()
{
	printf("commands:\n0 see command list\n-1  - exit");
}

int menu()
{
	seeCommandList();

	int take = 0;
	while (1)
	{
		printf("command: ");
		scanf("%d", &take);

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
			// see animals
			break;

		case 6:
			// add new animal
			break;

		case 7:
			// edit an animal
			break;
		}

	}


	return 0;
}


int main()
{
	Fish fish;
	

	//int a[3];
	//a = { 0 };
	fish.printToScreen();
	fish.setField(3);
	fish.printToScreen();
	return 0;
}

// EOF