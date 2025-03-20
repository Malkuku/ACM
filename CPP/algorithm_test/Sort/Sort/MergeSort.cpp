#define _CRT_SECURE_NO_WARNINGS 1


//�鲢����ģ��
//#include"head.h"
// void Merge(std::array<int, SIZE>& arr, std::array<int, SIZE>& tmp, int low, int mid, int high)//��
// {
// 	int i = low;
// 	int j = mid + 1;
// 	int k = low;
// 	while (i <= mid && j <= high)//��һ��ץ׳��������tmp
// 	{
// 		if (arr[i] < arr[j])//�Ȱ�С�ķŽ�ȥ
// 		{
// 			tmp[k++] = arr[i++];
// 		}
// 		else if (arr[i] >= arr[j])
// 		{
// 			tmp[k++] = arr[j++];
// 		}
// 	}
// 	//�ڶ��Σ���ʣ������ȥ
// 	while (i <= mid)
// 	{
// 		tmp[k++] = arr[i++];
// 	}
// 	while (j <= high)
// 	{
// 		tmp[k++] = arr[j++];
// 	}
// 	for (int n = low; n <= high; n++)//�Ż�arr
// 	{
// 		arr[n] = tmp[n];
// 	}
// }
// void MergeSort(std::array<int, SIZE>& arr, std::array<int, SIZE>& tmp, int low, int high)//��
// {
// 	if (low >= high)
// 		return;
// 	int mid = (low + high) / 2;
// 	MergeSort(arr, tmp, low, mid);
// 	MergeSort(arr, tmp, mid+1, high);
// 	Merge(arr, tmp, low, mid, high);
// }


/*2024.11.13*/ //OI WIKI��
#include<iostream>
void myMerge(int a[],int alen,int b[],int blen,int tmp[]){
	int i = 0,j = 0,k = 0;
	while(i < alen && j < blen){
		if(b[j] < a[i]){ //������С�Ľ���
			tmp[k++] = b[j++];
		}
		else{
			tmp[k++] = a[i++];
		}
	}
	for(;i < alen; i++,k++)tmp[k] = a[i];
	for(;j < blen; j++,k++)tmp[k] = b[j];//����ʣ�µ�
}	
void myMergeSort(int a[],int l,int r){
	if(r - l <= 1) return; //ע���˳�����--�ֽ�һ����ʱ����
	//�ֽ�
	int mid = (r+l) >> 1;
	myMergeSort(a,l,mid),myMergeSort(a,mid,r);
	
	//�ϲ�
	int tmp[1010] = {}; //���ϲ���ɵĽ������tmp
	myMerge(a+l,mid - l,a+mid,r - mid,tmp+l);
	for(int i = l; i < r; i++) a[i] = tmp[i];
}
int main(){
	int arr[] = {1,3,512,53,12,51,21,131};
	myMergeSort(arr,0,sizeof(arr)/sizeof(arr[0])); //����ҿ�
	for(auto t : arr) std::cout << t << " ";
	return 0;
}
