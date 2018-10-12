#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>

void tests();

#include <iostream>

int main()
{
	tests();

	system("pause");
	return 0;
}

void tests()
{
	int const size1 = 5;
	int const size2 = 3;
	bool array1[size1]{ true, false, false, false, true };
	bool array2[size2]{ true, true, true };
	whichNumberISGrander(size1, array1, size2, array2);
	printf("RESULT MUST BE: First number is grander\n");

	int const size3 = 5;
	int const size4 = 3;
	bool array3[size3]{ false, false, false, false, true };
	bool array4[size4]{ false, false, true };
	whichNumberISGrander(size3, array3, size4, array4);
	printf("RESULT MUST BE: Numbers are the same\n");
}
