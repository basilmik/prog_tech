#pragma once
#include "stdio.h"

class Exeption
{
	char* fileName;
	char* msg;
	int line;

public:

	Exeption() 
	{ 
		fileName = new char[128];
		msg = new char[128];
		line = 0;
	};

	Exeption(const char* _fileName);


	~Exeption(){};

	Exeption* set(const char* _val, int _line);

	void show();

};

