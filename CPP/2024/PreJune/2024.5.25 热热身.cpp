#define _CRT_SECURE_NO_WARNINGS 1

/*luogu P9836 ÷÷ ˜ */
/*2024.5.25*/ //√€÷≠¥ÌŒÛ
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>
const int mod = 998244353;
const int N = 1e4 + 10;
ll n, w;
int p[N];
int cnt = 0;
int primes[N];
int st[N];
map<int,int> cntp[N], cntw;


void init1() {
	for (int i = 2; i <= N; i++) {
		if (!st[i]) primes[cnt++] = i; 
		for (int j = 0; j <= N / i; j++) {
			st[primes[j] * i] = primes[j];
			if (i % primes[j] == 0) break;
		}
	}
}
void init2() {
	int tmp = w;
	while (tmp > 1) {
		cntw[st[tmp]]++, tmp /= st[tmp];
	}
	for (int i = 1; i <= n; i++) {
		int tmp = p[i];
		while (tmp > 1) {
			cntp[i][st[tmp]]++, tmp /= st[tmp];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> w;
	for (int i = 1; i <= n; i++) cin >> p[i];
	cntw[1]++;
	cntp[1][2]++;
	init1();
	init2();
	for (auto t : cntw) {
		int req = 1;
		int cnt = t.second;
		while (cnt) {
			for (int i = 1; cnt && i <= n; i++) {
				if (cntp[i][t.first] < req) cntp[i][t.first]++, cnt--;
			}
			req++;
		}
	}
	ll ans = 1;
	for (int i = 1; i <= n; i++) {
		for (auto t : cntp[i]) {
			ans = (ans * (t.second + 1)) % mod;
		}
	}
	cout << ans << "\n";
	return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//typedef long long LL;
//const int MOD = 998244353, MAXN = 1e4 + 10;
//int n, w, p[MAXN], mb[MAXN], idx, prime[MAXN], maxv;
//LL ans = 1;
//map<int, int> cntp[MAXN], cntw;
//
//void init1() {
//    for (int i = 2; i <= maxv; i++) {
//        if (!mb[i]) prime[++idx] = i, mb[i] = i;
//        for (int j = 1; j <= idx && i * prime[j] <= maxv; j++) {
//            mb[i * prime[j]] = prime[j];
//            if (!(i % prime[j])) break;
//        }
//    }
//}
//
//void init2() {
//    for (int i = 1; i <= n; i++) {
//        int tmp = p[i];
//        while (tmp > 1) {
//            cntp[i][mb[tmp]]++, tmp /= mb[tmp];
//        }
//    }
//    int tmp = w;
//    while (tmp > 1) cntw[mb[tmp]]++, tmp /= mb[tmp];
//}
//
//int main() {
//    cin >> n >> w;
//    maxv = w;
//    for (int i = 1; i <= n; i++) cin >> p[i], maxv = max(maxv, p[i]);
//    init1(), init2();
//    for (auto t : cntw) {
//        int req = 1;
//        int cnt = t.second;
//        while (cnt) {
//            for (int i = 1; cnt && i <= n; i++) {
//                if (cntp[i][t.first] < req) cntp[i][t.first]++, cnt--;
//            }
//            req++;
//        }
//    }
//
//    for (int i = 1; i <= n; i++) {
//        for (auto t : cntp[i]) {
//            ans = (ans * (t.second + 1)) % MOD;
//        }
//    }
//    cout << ans;
//    return 0;
//}