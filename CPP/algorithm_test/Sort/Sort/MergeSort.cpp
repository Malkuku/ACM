#define _CRT_SECURE_NO_WARNINGS 1


//归并排序模板
//#include"head.h"
// void Merge(std::array<int, SIZE>& arr, std::array<int, SIZE>& tmp, int low, int mid, int high)//并
// {
// 	int i = low;
// 	int j = mid + 1;
// 	int k = low;
// 	while (i <= mid && j <= high)//第一次抓壮丁，塞进tmp
// 	{
// 		if (arr[i] < arr[j])//先把小的放进去
// 		{
// 			tmp[k++] = arr[i++];
// 		}
// 		else if (arr[i] >= arr[j])
// 		{
// 			tmp[k++] = arr[j++];
// 		}
// 	}
// 	//第二次，把剩下塞进去
// 	while (i <= mid)
// 	{
// 		tmp[k++] = arr[i++];
// 	}
// 	while (j <= high)
// 	{
// 		tmp[k++] = arr[j++];
// 	}
// 	for (int n = low; n <= high; n++)//放回arr
// 	{
// 		arr[n] = tmp[n];
// 	}
// }
// void MergeSort(std::array<int, SIZE>& arr, std::array<int, SIZE>& tmp, int low, int high)//分
// {
// 	if (low >= high)
// 		return;
// 	int mid = (low + high) / 2;
// 	MergeSort(arr, tmp, low, mid);
// 	MergeSort(arr, tmp, mid+1, high);
// 	Merge(arr, tmp, low, mid, high);
// }


/*2024.11.13*/ //OI WIKI版
#include<iostream>
void myMerge(int a[],int alen,int b[],int blen,int tmp[]){
	int i = 0,j = 0,k = 0;
	while(i < alen && j < blen){
		if(b[j] < a[i]){ //优先让小的进入
			tmp[k++] = b[j++];
		}
		else{
			tmp[k++] = a[i++];
		}
	}
	for(;i < alen; i++,k++)tmp[k] = a[i];
	for(;j < blen; j++,k++)tmp[k] = b[j];//放入剩下的
}	
void myMergeSort(int a[],int l,int r){
	if(r - l <= 1) return; //注意退出条件--分解一个数时结束
	//分解
	int mid = (r+l) >> 1;
	myMergeSort(a,l,mid),myMergeSort(a,mid,r);
	
	//合并
	int tmp[1010] = {}; //将合并完成的结果放入tmp
	myMerge(a+l,mid - l,a+mid,r - mid,tmp+l);
	for(int i = l; i < r; i++) a[i] = tmp[i];
}
int main(){
	int arr[] = {1,3,512,53,12,51,21,131};
	myMergeSort(arr,0,sizeof(arr)/sizeof(arr[0])); //左闭右开
	for(auto t : arr) std::cout << t << " ";
	return 0;
}
