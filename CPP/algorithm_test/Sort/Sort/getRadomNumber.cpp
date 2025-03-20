#define _CRT_SECURE_NO_WARNINGS 1
#include"head.h"

void getRadomNumber(std::array<int, SIZE>& arr)
{
	srand((unsigned int)time(0));
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = (int)rand() % R_MAX;
	}
}