#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*2024.11.3 ��չŷ����� exgcd*/
// #define _CRT_SECURE_NO_WARNINGS 1
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// //��p1516Ϊ��
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
//     ll ans = ((t * (b/d) % (L/d) + (L/d))) % (L/d); //��Ϊd��L��Լ��--�߶ȿ�����С
//     if(b % d != 0) cout << "Impossible\n";
//     else cout << ans << "\n"; 
//     return 0;
// }

/*2024.8.30 ����ȡģ*/
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

/*2024.2.26 �����ж�*/
//#include<bits/stdc++.h>
//#include <omp.h>
//using namespace std;
//const int N = 1e8+10;
//
////����ɸ
//int primes3[N];
//bool vis3[N];
//void getPrime3(int x) {
//	int cnt = 0;
//	memset(primes3, -1, sizeof primes3);
//	for (int i = 2; i <= x; i++) {
//		if (!vis3[i]) primes3[cnt++] = i;
//		for (int j = 0; primes3[j] <= x / i; j++) { //ö������
//			vis3[primes3[j] * i] = 1;
//			if (i % primes3[j] == 0) break; //���������С������
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
////��ʽɸ
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
////����ɸ
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
//	//����ɸ
//	double start_time1 = omp_get_wtime()*1000;
//	cout << "����:\n";
//	for (int i = 1; i <= n; i++)if (getPrime1(i)) {
//		//cout << i << " ";
//	}
//	cout << "\n";
//	double end_time1 = omp_get_wtime()*1000;
//
//	//��ʽɸ
//	double start_time2 = omp_get_wtime() * 1000;
//	cout << "��ʽɸ:\n";
//	getPrime2(n);
//	//for (int i = 1; i <= n; i++)if (isPrimes2(i)) {
//		//cout << i << " ";
//	//}
//	cout << "\n";
//	double end_time2 = omp_get_wtime() * 1000;
//
//	//����ɸ
//	double start_time3 = omp_get_wtime() * 1000;
//	cout << "��ʽɸ:\n";
//	getPrime3(n);
//	//for (int i = 1; i <= n; i++)if (isPrimes3(i)) {
//		//cout << i << " ";
//	//}
//	cout << "\n";
//	double end_time3 = omp_get_wtime() * 1000;
//	
//	cout << "����: " << end_time1 - start_time1 << " ms\n";
//	cout << "��ʽɸ: " << end_time2 - start_time2 << " ms\n";
//	cout << "����ɸ: " << end_time3 - start_time3 << " ms\n";
//	return 0;
//}

/*2024.3.4 ������*/
////�����ݵĺ����ǽ����ָ���ֿ���ÿ��ֻ����ƽ����Ȼ��ָ��/2
//#include<iostream>
//using namespace std;
//#define ll long long
//
//ll fastPow(ll a, ll b) {
//	ll ans = 1;
//	while (b) {
//		if (b & 1) { //ָ��Ϊ����
//			ans *= a;//�൱�ڶ������˳���
//		}
//		a *= a;//aƽ��
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

/*2024.3.4 ֻ�����ֽ�*/
//#include<iostream>
//using namespace std;
//#define ll long long
//
////ɸѡ�������ʺ���2-nÿ������//�𳭣�������
////const int N = 1e7 + 10;
////int p[N];
////void so2(int n) {
////	p[1] = 1;
////	for (int i = 2; i <= n / i; i++) {
////		if (p[i] == 0) {
////			for(int j = i + i; j <= N; j += i)//i������ʱ��ɾ��i�ı���
////				if (p[j] == 0) p[j] = i;
////		}
////		int j = n;
////		for (j = n; p[j] > 0; j = j / p[i]) {
////			cout << p[j] << " ";
////		}cout << j << "\n";
////	}
////}
//
////�̳���
//void so1(int n) {
//	for (int i = 2; i <= n / i; i++) {
//		if (n % i == 0) {
//			cout << i << " ";
//		}
//		while (n % i == 0) n /= i;
//	}
//	if (n > 1) cout << n << "\n"; //��sprt���������ֻ����һ��
//}
//int main() {
//	ll n;cin >> n;
//	cout << "�̳�����"; so1(n);
//	//cout << "ɸѡ����"; so2(n);
//	return 0;
//}

/*2024.3.4 ���gcd lcm*/
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

/*2024.3.29 ����ʽϵ�� C(n,k)*/
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