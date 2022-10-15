#define _CRT_SECURE_NO_WARNINGS
#include "Exeption.h"
#include "string.h"

Exeption::Exeption(const char* _fileName)
{
	fileName = new char[128];
	strcpy(fileName, _fileName);
	msg = new char[128];
	line = 0;
};

Exeption* Exeption::set(const char* _val, int _line)
{
	line = _line;
	strcpy(msg, _val);
	return this;
}

void Exeption::show()
{
	printf("\texeption thrown '%s' in line %d in file %s\n", msg, line, fileName);
}


