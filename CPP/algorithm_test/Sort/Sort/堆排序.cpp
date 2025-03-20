
#include<iostream>
using namespace std;
#define ll long long

//调整堆 -- 大根堆
void heapify(int arr[],int n,int i){
    int largest = i; //当前索引
    int left = 2*i + 1; //左右子树
    int right = 2*i + 2; 

    if(left < n && arr[left] > arr[largest]) largest = left; //下滤
    if(right < n && arr[right] > arr[largest]) largest = right;

    if(largest != i){ //发生变化，交换节点并向下递归
        swap(arr[i],arr[largest]);

        heapify(arr,n,largest);
    }
}

//堆排序
void heapSort(int arr[],int n){
    //建堆 0 1 2 3 4  5/2-1 -> 1
    for(int i = n/2-1;i>=0;i--){ //只对前面的n/2个元素煎堆，后半部分是叶子节点
        heapify(arr,n,i);
    }

    //排序
    for(int i = n-1; i > 0; i--){
        swap(arr[0],arr[i]); //每次最大的元素会成为根顶，将它放在数组末尾

        heapify(arr,i,0);  //对剩下的进行排序
    }

}

/*2024.11.13*/ //堆排序模板
int main(){
    int arr[] = {12,11,3,5,6,7,123,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr,n);
    for(auto t : arr) cout << t << " ";
    return 0;
}

