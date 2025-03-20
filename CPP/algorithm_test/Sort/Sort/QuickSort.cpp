#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int part(std::array<int, 10>& arr, int low, int high)
{
	int l = low;
	int h = high;
	int key = low;//���������ȡ��Ԫ��Ϊ��׼
	while (l < h)
	{
		while (l < h && arr[key] < arr[h]/*��������ʽ*/)
		{
			h--;
		}
		while (l < h && arr[key] >= arr[l])
		{
			l++;
		}
		swap(arr[l],arr[h]);
	}
	//����������keyֵ
	swap(arr[key],arr[l]);
	return l;
}

void QuickSort(std::array<int, 10>& arr, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = part(arr, low, high);
		QuickSort(arr, low, mid - 1);//�󲿷�
		QuickSort(arr, mid + 1, high);//�Ҳ���

	}
}

int main(){
	array<int,10> arr{1,3,2,5,4,6,7,9,8,10};
	QuickSort(arr,0,arr.size());
	for(auto t : arr){
		cout << t << " ";
	}
	return 0;
}