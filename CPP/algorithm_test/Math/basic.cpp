#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*P1835 素数密度 */
/*2024.8.30*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 70000;
// int primes[N];
// bool isprimes_not[N];
// int primes_len = 0;
// void getPrimes(){
//     for(int i = 2; i <= N; i++){
//         if(!isprimes_not[i]){
//             primes[primes_len++] = i;
//         } 
//         for(int j = 0;i*primes[j] <= N; j++){
//             isprimes_not[primes[j]*i] = 1;
//             if(i%primes[j] == 0) break;
//         }
//     }
// }
// int main(){
//     int l,r;
//     getPrimes();
//     cin >> l >> r;
//     l = l == 1? 2:l;
//     int ans = 0;
//     for(int i = l; i <= r; i++){ //多少有点阴间了
//         bool flag = 0;
//         if(i <= 0) break;
//         if(i <= N && !isprimes_not[i]){
//             ans++;continue;
//         }
//         for(int j = 0; j < primes_len; j++){
//             if(i % primes[j] == 0) {
//                 flag = 1;break;
//             }
//         }
//         if(!flag) ans++;
//     }
//     cout << ans << "\n";
//     return 0;
// }

/*NC14399 素数判断*/
/*2024.3.4 朴素筛+只因数分解*/
////WA: 为了时间复杂度，要用分解只因数
//#include<iostream>
//using namespace std;
//const int N = 1e5 + 10;
//int primes[N];
//bool isprimes(int x,int& cnt) {
//	bool flag = 1;
//	if (x == 1) flag = 0;
//	for (int i = 2; i <= x/i; i++) {
//		if (x % i == 0) {
//			primes[cnt++] = i;
//			while (x % i == 0) x /= i;
//			flag = 0;
//		}
//	}
//	if (x > 1) primes[cnt++] = x;
//	return flag;
//}
//
//int main() {
//	int t;cin >> t;
//	while (t--) {
//		int cnt = 0;
//		int x; cin >> x;
//		bool flag = isprimes(x, cnt);
//		if (flag) {
//			cout << "isprime\n" << x << "\n";
//		}
//		else {
//			cout << "noprime\n";
//			for (int i = 0; i < cnt; i++) {
//				cout << primes[i] << " ";
//			}cout << "\n";
//		}
//	}
//	return 0;
//}

/*NC235228 素数的个数*/
/*2024.3.4 (精)区间求素数*/
////WA:线性筛必须从2开始
//#include<iostream>
//using namespace std;
//const int N = 1e6 + 10;
//bool primes[N];
//int cnt = 0;
//int l, r;
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> l >> r;
//	//两层for循环求l - r内有只因子的数
//	for (int i = 2; i <= r / i; i++) {
//		for (int j = r / i; j >= 2; j--) {
//			if (j * i < l) break; 
//			else primes[i * j - l] = 1;
//		}
//	}
//	for (int i = l; i <= r; i++) if (!primes[i - l]) cnt++;
//	cout << cnt << "\n";
//	return 0;
//}
/*2024.3.23*/
//// TLE i*j < l 直接下一个就好了
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 10;
//bool primes[N];
//
//int main() {
//	int l, r;
//	cin >> l >> r;
//	for (int i = 2; i <= r / i; i++) {
//		for (int j = r / i; j >= 2; j--) {
//			if (i * j < l) break;
//			primes[i * j - l] = 1;
//		}
//	}
//	int ans = 0;
//	for (int i = l; i <= r; i++) if (!primes[i - l]) ans++;
//	cout << ans << "\n";
//	return 0;
//}

/*NC268715 素数三元组*/
/*2024.3.23 TLE*/
//#include <iostream>
//#include<map>
//using namespace std;
//const int N = 1e6 + 100;
//int cnt = 0;
//int primes[N];
//bool isprimes[N];
//void get_primes(){
//    for (int i = 2; i <= N; i++) {
//        if (!isprimes[i]) {
//            primes[cnt++] = i;
//        }
//        for (int j = 0; primes[j] < N / i; j++) {
//            isprimes[primes[j] * i] = 1;
//            if (i % primes[j] == 0) break;
//        }
//    }
//}
//int sum = 0;
//int res = 0;
//int g[N];
//void find() {
//    for (int i = 2; i < cnt; i++) {
//        for (int j = 0; j <= i/2; j++) {
//            if(!isprimes[primes[i] - primes[j]])res++;
//        }
//        g[primes[i]] = res;
//    }
//}
//int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    get_primes();
//    find();
//    int t;cin >> t;
//    while (t--) {
//        int n;cin >> n;
//        int ans = 0;
//        for (int i = 1; i < cnt; i++) {
//            if (n < primes[i]) {
//                ans = g[primes[i - 1]];
//                break;
//            }
//        }
//        cout << ans << "\n";
//    }
//    return 0;
//}
/*2024.3.23 题解 素数的分布规律*/
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 10;
//bool vis[N];
//int primes[N];
//int cnt = 0;
//int a[N];
//void get_primes() {
//	for (int i = 2; i < N; i++) {
//		if (!vis[i]) primes[cnt++] = i;
//		for (int j = 0; primes[j] < N / i; j++) {
//			vis[primes[j] * i] = 1;
//			if (i % primes[j] == 0) break;
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	get_primes();
//	for (int i = 0; i < cnt; i++) {
//		if (!vis[primes[i] + 2]) a[primes[i] + 2] = 1;
//	}
//	for (int i = 1; i < N; i++) a[i] += a[i - 1];
//	int t; cin >> t;
//	while (t--) {
//		int n;cin >> n;
//		cout << a[n] << "\n";
//	}
//	return 0;
//}

/*NC16710 最大公约数(lcm)*/
/*2024.3.4 gcd版子*/
//#include<iostream>
//using namespace std;
//#define ull unsigned long long
//ull gcd(ull a, ull b) {
//	return b ? gcd(b, a % b) : a;
//}
//int main() {
//	ull a, b;
//	cin >> a >> b;
//	ull ans = gcd(a, b);
//	ans = a / ans * b;
//	cout << ans << "\n";
//	return 0;
//}

/*NC23050 华华对月月的忠诚*/ //斐蜀定理(更相减损术)
/*2024.3.4*/
////裴蜀定理具体如下：
////裴蜀定理（或贝祖定理）得名于法国数学家艾蒂安·裴蜀，
////说明了对任何整数a、b和它们的最大公约数d，
////关于未知数x和y的线性不定方程（称为裴蜀等式）：
////若a, b是整数, 且gcd(a, b) = d，
////那么对于任意的整数x, y, ax + by都一定是d的倍数，特别地，
////一定存在整数x, y，使ax + by = d成立。
//#include<iostream>
//using namespace std;
//#define ll long long
//const int N = 1e5 + 10;
//ll a, b ,n;
//ll F[N];
//ll gcd(ll a, ll b) {
//	return b ? gcd(b, a % b) : a;
//}
//
//int main() {
//	cin >> a >> b >> n;
//	ll ans = gcd(a,b);
//	cout << ans << "\n";
//	return 0;
//}

/*NC20313 [SDOI2008]仪仗队*/ //欧拉函数 





/**/