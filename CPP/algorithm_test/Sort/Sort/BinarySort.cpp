#define _CRT_SECURE_NO_WARNINGS 1
#include"head.h"

void BinarySort(std::array<int,SIZE>& arr)
{
	printf("’€∞Î≤Â»Î≈≈–Ú\n");

	int i, j;
	int low, high, mid;
	for (i = 1; i < SIZE; i++)
	{
		int tmp = arr[i];
		low = 0;
		high = i - 1;

		while (low <= high)
		{
			mid = (low + high) / 2;

			if (arr[mid] > tmp)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		for (j = i - 1; j >= low; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = tmp;
	}
}