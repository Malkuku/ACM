#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*A. Rudolph and Cut the Rope */
//int a[210], b[210];
//int main() {
//	int t;cin >> t;
//	while (t--) {
//		int n;cin >> n;
//		int cnt = 0;
//		for (int i = 0; i < n; i++) {
//			cin >> a[i] >> b[i];
//			if (a[i] - b[i] > 0) cnt++;
//		}
//		cout << cnt << "\n";
//	}
//	return 0;
//}

/*B. Rudolph and Tic-Tac-Toe*/
//char g[10][10];
//int main() {
//	int t;cin >> t;
//	while (t--) {
//		for (int i = 1; i <= 3; i++) {
//			for (int j = 1; j <= 3; j++) {
//				cin >> g[i][j];
//			}
//		}
//		int flag = 0; //0 平 1 O 2 X 3 .
//		for (int i = 1; i <= 3; i++) {
//			map<char, int> mp;
//			for (int j = 1; j <= 3; j++) {
//				mp[g[i][j]]++;
//			}
//			if (mp['O'] == 3) flag = 1;
//			else if (mp['X'] == 3) flag = 2;
//			else if (mp['+'] == 3) flag = 3;
//		}
//		for (int i = 1; i <= 3; i++) {
//			map<char, int> mp;
//			for (int j = 1; j <= 3; j++) {
//				mp[g[j][i]]++;
//			}
//			if (mp['O'] == 3) flag = 1;
//			else if (mp['X'] == 3) flag = 2;
//			else if (mp['+'] == 3) flag = 3;
//		}
//		{
//			map<char, int> mp;
//			mp[g[1][1]]++;
//			mp[g[2][2]]++;
//			mp[g[3][3]]++;
//			if (mp['O'] == 3) flag = 1;
//			else if (mp['X'] == 3) flag = 2;
//			else if (mp['+'] == 3) flag = 3;
//		}
//		{
//			map<char, int> mp;
//			mp[g[1][3]]++;
//			mp[g[2][2]]++;
//			mp[g[3][1]]++;
//			if (mp['O'] == 3) flag = 1;
//			else if (mp['X'] == 3) flag = 2;
//			else if (mp['+'] == 3) flag = 3;
//		}
//		if (flag == 1) cout << "O\n";
//		else if (flag == 2)cout << "X\n";
//		else if (flag == 3) cout << "+\n";
//		else cout << "DRAW\n";
//	}
//	return 0;
//}

/*C. Rudolf and the Another Competition*/
//int n, m, h;
//const int N = 2e5 + 10;
//struct node{
//	ll cnt, pe, pos;
//};
//vector<vector<ll>> a;
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		cin >> n >> m >> h;
//		a.resize(n+1);
//		for (int i = 1; i <= n; i++) {
//			a[i].clear();
//			a[i].reserve(m);
//			for (int j = 1; j <= m; j++) {
//				ll x;cin >> x;
//				a[i].push_back(x);
//			}
//			sort(a[i].begin(), a[i].end());
//		}
//		ll cnt1,pe1;
//		ll res = 1;
//		for (int i = 1; i <= n; i++) {
//			ll cnt = 0;
//			ll sum = 0;
//			ll pe = 0;
//			for (int j = 0; j < m; j++) {
//				if (sum + a[i][j] > h) break;
//				cnt++;
//				sum += a[i][j];
//				pe += sum;
//			}
//			if (i == 1) {
//				cnt1 = cnt;
//				pe1 = pe;
//			}
//			else {
//				if (cnt > cnt1) res++;
//				else if (cnt == cnt1) {
//					if (pe < pe1) res++;
//				}
//			}
//		}
//		cout << res << "\n";
//	}
//	return 0;
//}

/*D. Rudolph and Christmas Tree*/
//处理重合 - 相似三角形
/*2024.4.7*/
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		double n, d, h;
//		cin >> n >> d >> h;
//		double sum = 0;
//		double fd = -0x3f3f3f3f;
//		for (int i = 1; i <= n;i++) {
//			double xd; cin >> xd;
//			if (xd - fd < h) {
//				sum -= (h - xd + fd) * (h - xd + fd) * d / h;
//			}
//			sum += d * h;
//			fd = xd;
//		}
//		sum /= 2;
//		cout << fixed << setprecision(8) << sum << "\n";
//	}
//	return 0;
//}

/*E1. Rudolf and Snowflakes (simple version)*/
//int main() {
//	int t;cin >> t;
//	while (t--) {
//		ll n; cin >> n;
//		bool flag = 0;
//		int k = 1;
//		while (k++) {
//			ll sum = 1 + k;
//			int cnt = 2;
//			if (k + 1 + (ll)pow(k, 2) > n) break;
//			while (sum < n) {
//				sum += (ll)pow(k, cnt);
//				cnt++;
//			}
//			if (sum == n) flag = 1;
//		}
//		if (flag) cout << "YES\n";
//		else cout << "NO\n";
//	}
//	return 0;
//}

/*E2. Rudolf and Snowflakes (hard version)*/ //等比数列
//int main() {
//	int t;cin >> t;
//	while (t--) {
//		ll n; cin >> n;
//		bool flag = 0;
//		for (int i = 2; i <= 64; i++) {
//
//			ll q = pow(n, 1.0 / i); //枚举项数，求出公比q
//			if (q < 2) {
//				break;
//			}
//			ll sum = 0;ll k = 1;
//			for (int j = 0; j <= i; j++) {
//				sum += k;
//				k *= q;
//			}
//			if (sum == n) flag = 1;
//		}
//		if (flag) cout << "YES\n";
//		else cout << "NO\n";
//	}
//	return 0;
//}
/*2024.4.7*/ //弃用，__int128不被支持
//#define ull unsigned __int128
//
//ull qmi(ull x,ull k) {
//	ull ans = 1;
//	while (k) {
//		if (k & 1) {
//			ans *= x;
//		}
//		x *= x;
//		k >>= 1;
//	}
//	return ans;
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	ull t; cin >> t;
//	while (t--) {
//		ull n; cin >> n;
//		bool flag = 0;
//		for (int i = 3; i <= 58; i++) {
//			ull l = 2, r = 1e9;
//			while (l <= r) {
//				ull mid = (l + r) >> 1;
//				ull s = (qmi(mid, i) - 1) / (mid - 1);
//				if (s > n) r = mid - 1;
//				else if (s < n) l = mid + 1;
//				else {
//					flag = 1;
//					break;
//				}
//			}
//			if (flag) break;
//		}
//		if (flag) cout << "YES\n";
//		else cout << "NO\n";
//	}
//	return 0;
//}