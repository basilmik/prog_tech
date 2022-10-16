#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"

#include "keeper.h"
#include "myio.h"
#include <stdlib.h>


void seeCommandList()
{
	printf("MAIN MENU\n");
	printf("commands:\n0 - see command list\n100 - clear screen\n-1  - exit\n1 - file path's menu\n2 - save all animals to file\n3 - load all animals from file\n");
	printf("4 - print animals to screen\n5 - call add menu\n6 - call edit menu\n7 - call delete menu\n8 - ----\n");
	printf("101 - preset file path to load.txt and save.txt\n");
}

	Keeper zoo;
int menu()
{


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
			system("cls"); zoo.callFileMenu(); seeCommandList();
			break;

		case 2:
			zoo.callSave(); 
			break;

		case 3:
			zoo.callLoad(); 
			// load from file
			break;

		case 4:
			zoo.printAll();
			break;

		case 5:// add new animal
			system("cls"); zoo.callAdd(); seeCommandList();
			break;

		case 6:
			system("cls"); zoo.callEdit(); seeCommandList();
			break;

		case 7:
			// delete an animal
			system("cls"); zoo.callDelete(); seeCommandList();
			break;
		case 8:
			system("cls"); zoo.callCopy(); seeCommandList();
			break;
		
		case 100:
			system("cls"); seeCommandList();
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
	//delete zoo;


	return 0;
}

// EOF