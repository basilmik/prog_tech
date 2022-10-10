//
//#include "Animal.h"
//#define BREED 0
//#define COLOR 1
//#define DIET 2
//#define HABITAT 3
//
//class Bird : public Animal
//{
//public:
//
//	Bird() {
//		setAnimalType(TYPE_BIRD);
//		int fieldNum = 4;
//		setFeatureFieldsNum(fieldNum);
//
//		prop = (char**)malloc(fieldNum * sizeof(char*));
//		if (prop == nullptr)
//			throw 0; // EXEPTION
//
//		for (int i = 0; i < fieldNum; i++)
//		{
//			prop[i] = (char*)calloc(512, sizeof(char));
//		}
//	};
//
//	~Bird() {};
//
//
//	void printToScreen() override
//	{
//		printf("BIRD:\n");
//		printf("breed is: -%s-\n", prop[BREED]);
//		printf("color is: -%s-\n", prop[COLOR]);
//		printf("diet is: -%s-\n", prop[DIET]);
//		printf("habitat is: -%s-\n", prop[HABITAT]);
//	}
//
//};