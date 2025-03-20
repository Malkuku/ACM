#define _CRT_SECURE_NO_WARNINGS 1
#include"head.h"

void Print(std::array<int, SIZE>& arr)
{
	for (int i : arr)
	{
		printf("%d ", i);
	}
	printf("\n");
}