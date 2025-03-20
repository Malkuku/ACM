//对于底层数组的封装

#include<bits/stdc++.h>
const int N = 10;
struct Seqlist{
    int* a; //动态数组
    int size;   //有效个数
    int capacity; //动态容量
};
//初始化
void SLInit(Seqlist* ps){
    assert(ps);
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}
//销毁
void SLDestroy(Seqlist* ps){
    if(ps == NULL) return;
    if(ps->a){
        free(ps);
        ps->a = NULL;
        ps->capacity = ps->size = 0;
    }
}
//打印
void SLPrint(Seqlist* ps){
    assert(ps);
    for(int i = 0; i < ps->size;i++){
        printf("%d ",ps->a[i]);
    }printf("\n");
}
//扩容
void SLCheckCapacity(Seqlist* ps){
    if(ps->capacity == ps->size){
        int *tem = (int*)realloc(ps->a,sizeof(int)*4/*newsize+oldsize*/);
        ps->capacity = 4;
        assert(tem);
        ps->a = tem;
    }
}
//头插
void SLPushFront(Seqlist* ps, int x){
	assert(ps);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}
int main(){

    return 0;
}