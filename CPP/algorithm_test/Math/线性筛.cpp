#define _CRT_SECURE_NO_WARNINGS 1

//ʱ�临�Ӷ�Ϊo(n*longlog(n))
//Ҫ�����С��������ʼɸѡ
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int primes[N];//��¼����
int cnt = 0;//��¼��������
bool st[N]; //��¼����i�Ƿ�Ϊ����
void getprimes() {
	for (int i = 2; i <= N; i++) {
		if (!st[i]) primes[cnt++] = i;//����������
		for (int j = 0; primes[j] * i <= N; j++) { //ö��i��ÿ������������
			st[primes[j] * i] = 1;//����������Ȼ��������
			if (i % primes[j] == 0) break; //ö�ٵ�i����С������
		}
	}
}
int main() {
	getprimes();
	for (int i = 0; i < cnt; i++) cout << primes[i] << " ";
	cout << "\n";
	return 0;
}