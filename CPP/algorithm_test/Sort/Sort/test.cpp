#define _CRT_SECURE_NO_WARNINGS 1
#include"head.h"
#define TEST_LEVEL 0
int main()
{
	
	std::array<int, SIZE> arr1 = { 0 };
	getRadomNumber(arr1);
	Print(arr1);

 #if TEST_LEVEL == 1
	BinarySort(arr1);
	Print(arr1);
#endif

#if TEST_LEVEL == 2
	ShellSort(arr1);
	Print(arr1);
#endif

#if TEST_LEVEL == 3
	QuickSort(arr1, 0, SIZE - 1);//range
	Print(arr1);
#endif

#if TEST_LEVEL == 4
	auto tmp = arr1;//创建相同大小的容器
	MergeSort(arr1, tmp, 0, SIZE - 1);//range
	Print(arr1);
#endif

#if TEST_LEVEL == 5
	
#endif

	/*test2*/using std::vector;

	int arr5[] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	vector<int> height(arr5, arr5 + 9);
	maxArea(height);


	/*test
	std::sort(arr1.begin(), arr1.end(), [](int x, int y) {return x > y;});
	Print(arr1);

	int arr2[SIZE] = { 0, 213, 41, 5, 3, 4, 10, 1, 2, 3 };
	std::sort(arr2, arr2 + SIZE, [](int x, int y){ return x > y; });
	for (int i : arr2)
	{
		printf("%d ", i);
	}
	*/

	std::cin.get();
	return 0;
}
