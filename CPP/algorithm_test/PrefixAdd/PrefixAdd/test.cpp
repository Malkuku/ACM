#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

int main()
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int s[10];


	s[0] = a[0];
	for (int i = 1; i < 10; i++)
	{
		s[i] = s[i - 1] + a[i];
	}

	{
		int l, r;
		std::cin >> l >> r;
		std::cout << s[r] - s[l] << std::endl;
	}

	return 0;
}