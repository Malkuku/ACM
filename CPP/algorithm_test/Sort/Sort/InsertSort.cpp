#define _CRT_SECURE_NO_WARNINGS 1
#include"head.h"

void InsertSort(std::array<int, SIZE>& arr)
{
	int i, j;
	for (i = 1; i < SIZE; i++)
	{
		int tmp = arr[i];
		for (j = i - 1; j >= 0 && tmp < arr[j]; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = tmp;
	}
}





/*2024.11.12*/
#include<iostream>
using namespace std;
#define ll long long

void InsertSort(vector<int> a){
	for(int i = 0,j; i < a.size(); i++){
		int tmp = a[i];
		for(j = i - 1; j >= 0 && tmp < a[j]; j--){
			a[j + 1] = a[j];
		}
		a[j+1] = tmp;
	}
}