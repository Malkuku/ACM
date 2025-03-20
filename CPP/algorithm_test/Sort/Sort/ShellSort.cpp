#define _CRT_SECURE_NO_WARNINGS 1
#include"head.h"
#define TEST

#ifdef MODEL
void ShellSort(std::array<int, SIZE>& arr)
{
	printf("ϣ������\n");
	int gap = SIZE;
	int i, j, k;
	do
	{
		gap = gap / 3 + 1;//����
		for (i = 0; i < gap; i++)//ÿ��ĵ�i��Ԫ��
		{
			for (j = gap+i; j < SIZE; j += gap)//j��ÿ�鿪ʼ�ĵ�һ��Ԫ��,�����ʵ�ֺ�ֱ�Ӳ��������Ƶ�
			{
				int tmp = arr[j];
				for (k = j - gap; k >= 0 && arr[k] > tmp; k -= gap)//�ȽϺ󽻻�
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


