#define _CRT_SECURE_NO_WARNINGS 1

//时间复杂度为o(n*longlog(n))
//要求从最小的素数开始筛选
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int primes[N];//记录素数
int cnt = 0;//记录素数个数
bool st[N]; //记录数字i是否为素数
void getprimes() {
	for (int i = 2; i <= N; i++) {
		if (!st[i]) primes[cnt++] = i;//加入素数表
		for (int j = 0; primes[j] * i <= N; j++) { //枚举i与每个质数的因数
			st[primes[j] * i] = 1;//这样的数必然不是素数
			if (i % primes[j] == 0) break; //枚举到i的最小质因子
		}
	}
}
int main() {
	getprimes();
	for (int i = 0; i < cnt; i++) cout << primes[i] << " ";
	cout << "\n";
	return 0;
}