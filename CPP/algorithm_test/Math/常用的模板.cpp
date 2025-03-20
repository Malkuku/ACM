#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*2024.11.3 扩展欧几里得 exgcd*/
// #define _CRT_SECURE_NO_WARNINGS 1
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// //以p1516为例
// ll exgcd(ll a,ll b,ll &x,ll& y){
//     if(b == 0) {x = 1,y = 0; return a;}
//     ll d = exgcd(b,a%b,y,x);
//     y -= a/b * x;
//     return d;
// }
// int main(){
//     ll n,m,x,y,L;
//     cin >> x >> y >> m >> n >> L;
//     ll a = n-m; ll b = x - y;
//     if(a < 0) {a = -a,b = -b;}
//     ll t,k;
//     ll d = exgcd(a,L,t,k); 
//     ll ans = ((t * (b/d) % (L/d) + (L/d))) % (L/d); //因为d是L公约数--尺度可以缩小
//     if(b % d != 0) cout << "Impossible\n";
//     else cout << ans << "\n"; 
//     return 0;
// }

/*2024.8.30 分数取模*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
// a/b mod M = a*b^(M-2) mod M
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll ksm(ll a,ll b,ll mod){
//     ll res = 1;
//     while(b){
//         if(b & 1) res = res * a % mod;
//         a = a*a % mod;
//         b >>= 1;
//     }
//     return res;
// }
// int main(){
//     ll a,b,mod;cin >> a >> b >> mod;
//     ll ans = a * ksm(b,mod-2,mod) % mod;
//     return 0;
// }

/*2024.2.26 素数判断*/
//#include<bits/stdc++.h>
//#include <omp.h>
//using namespace std;
//const int N = 1e8+10;
//
////线性筛
//int primes3[N];
//bool vis3[N];
//void getPrime3(int x) {
//	int cnt = 0;
//	memset(primes3, -1, sizeof primes3);
//	for (int i = 2; i <= x; i++) {
//		if (!vis3[i]) primes3[cnt++] = i;
//		for (int j = 0; primes3[j] <= x / i; j++) { //枚举质数
//			vis3[primes3[j] * i] = 1;
//			if (i % primes3[j] == 0) break; //这个数的最小质因子
//		}
//	}
//}
//bool isPrimes3(int x) {
//	int i = 0;
//	while (primes3[i] > 0) {
//		if (x < primes3[i]) return 0;
//		if (x == primes3[i++]) return 1;
//	}
//	return 0;
//}
//
////埃式筛
//int primes2[N];
//bool vis2[N];
//void getPrime2(int x) {
//	int cnt = 0;
//	memset(primes2, -1, sizeof primes2);
//	for (int i = 2; i <= x; i++) {
//		if (vis2[i]) continue;
//		primes2[cnt++] = i;
//		for (int j = i; j <= x / i; j++) {
//			vis2[i * j] = 1;
//		}
//	}
//}
//bool isPrimes2(int x) {
//	int i = 0;
//	while (primes2[i] > 0) {
//		if (x < primes2[i]) return 0;
//		if (x == primes2[i++]) return 1;
//	}
//	return 0;
//}
//
////暴力筛
//bool getPrime1(int x) {
//	if (x < 2) return 0;
//	for (int i = 2; i <= x/i; i++) {
//		if (x % i == 0) return 0;
//	}
//	return 1;
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	int n;cin >> n;
//
//	//暴力筛
//	double start_time1 = omp_get_wtime()*1000;
//	cout << "暴力:\n";
//	for (int i = 1; i <= n; i++)if (getPrime1(i)) {
//		//cout << i << " ";
//	}
//	cout << "\n";
//	double end_time1 = omp_get_wtime()*1000;
//
//	//埃式筛
//	double start_time2 = omp_get_wtime() * 1000;
//	cout << "埃式筛:\n";
//	getPrime2(n);
//	//for (int i = 1; i <= n; i++)if (isPrimes2(i)) {
//		//cout << i << " ";
//	//}
//	cout << "\n";
//	double end_time2 = omp_get_wtime() * 1000;
//
//	//线性筛
//	double start_time3 = omp_get_wtime() * 1000;
//	cout << "埃式筛:\n";
//	getPrime3(n);
//	//for (int i = 1; i <= n; i++)if (isPrimes3(i)) {
//		//cout << i << " ";
//	//}
//	cout << "\n";
//	double end_time3 = omp_get_wtime() * 1000;
//	
//	cout << "暴力: " << end_time1 - start_time1 << " ms\n";
//	cout << "埃式筛: " << end_time2 - start_time2 << " ms\n";
//	cout << "线性筛: " << end_time3 - start_time3 << " ms\n";
//	return 0;
//}

/*2024.3.4 快速幂*/
////快速幂的核心是将大的指数分开，每次只进行平方，然后将指数/2
//#include<iostream>
//using namespace std;
//#define ll long long
//
//ll fastPow(ll a, ll b) {
//	ll ans = 1;
//	while (b) {
//		if (b & 1) { //指数为奇数
//			ans *= a;//相当于独立提了出来
//		}
//		a *= a;//a平方
//		b >>= 1;//b/2
//	}
//	return ans;
//}
//
//int main() {
//	ll a, b; cin >> a >> b;
//	ll ans = fastPow(a, b);
//	cout << ans << "\n";
//	return 0;
//}

/*2024.3.4 只因数分解*/
//#include<iostream>
//using namespace std;
//#define ll long long
//
////筛选法（更适合求2-n每个数）//别抄，有问题
////const int N = 1e7 + 10;
////int p[N];
////void so2(int n) {
////	p[1] = 1;
////	for (int i = 2; i <= n / i; i++) {
////		if (p[i] == 0) {
////			for(int j = i + i; j <= N; j += i)//i是质数时，删除i的倍数
////				if (p[j] == 0) p[j] = i;
////		}
////		int j = n;
////		for (j = n; p[j] > 0; j = j / p[i]) {
////			cout << p[j] << " ";
////		}cout << j << "\n";
////	}
////}
//
////短除法
//void so1(int n) {
//	for (int i = 2; i <= n / i; i++) {
//		if (n % i == 0) {
//			cout << i << " ";
//		}
//		while (n % i == 0) n /= i;
//	}
//	if (n > 1) cout << n << "\n"; //比sprt大的质因子只能有一个
//}
//int main() {
//	ll n;cin >> n;
//	cout << "短除法："; so1(n);
//	//cout << "筛选法："; so2(n);
//	return 0;
//}

/*2024.3.4 简洁gcd lcm*/
//#include<iostream>
//using namespace std;
//#define ll long long
//ll gcd(ll a, ll b) {
//	return b ? gcd(b, a % b) : a;
//}
//int main() {
//	ll a, b;
//	cin >> a >> b;
//	ll ans1 = gcd(a, b);
//	ll ans2 = a / ans1 * b;
//	cout << "gcd: " << ans1 << " lcm: " << ans2 << "\n";
//	return 0;
//}

/*2024.3.29 二项式系数 C(n,k)*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//ll f[1010][1010];
//ll C(ll n, ll k) {
//	for (int i = 0; i <= n; i++) {
//		f[i][0] = 1; //C(n,0) = 1
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= k; j++) {
//			//C(k,n) = C(k,n-1) + C(k-1,n-1)
//			f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
//		}
//	}
//	return f[n][k];
//}