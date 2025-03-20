#define _CRT_SECURE_NO_WARNINGS 1
#include"head.h"
#define TEST

#ifdef MODEL
void ShellSort(std::array<int, SIZE>& arr)
{
	printf("希尔排序\n");
	int gap = SIZE;
	int i, j, k;
	do
	{
		gap = gap / 3 + 1;//分组
		for (i = 0; i < gap; i++)//每组的第i个元素
		{
			for (j = gap+i; j < SIZE; j += gap)//j是每组开始的第一个元素,下面的实现和直接插入是类似的
			{
				int tmp = arr[j];
				for (k = j - gap; k >= 0 && arr[k] > tmp; k -= gap)//比较后交换
				{
					arr[k + gap] = arr[k];
				}
				arr[k + gap] = tmp;
			}
		}
	} while (gap > 1);
}
#endif


#ifdef TEST
void ShellSort(std::array<int, SIZE>& arr)
{
	printf("ShellSort:\n");
	int gap = SIZE;
	int i, j, k;
	do
	{
		gap = gap / 3 + 1;
		for (i = 0; i < gap; i++)
		{
			for (j = gap + i; j < SIZE; j += gap)
			{
				int tmp = arr[j];
				for (k = j - gap; k >= 0 && arr[k] > tmp; k -= gap)
				{
					arr[k + gap] = arr[k];
				}
				arr[k + gap] = tmp;
			}
		}

	} while (gap > 1);
}

#endif


