#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
#define pair <int,int>

/*A. Is It a Cat?*/
//int main() {
//	int t;cin >> t;
//	while (t--) {
//		char arr[] = { 'm','e','o','w' };
//		int cnt = 0;
//		int n; cin >> n;
//		string s;cin >> s;
//		for (int i = 0; i < n; i++) {
//			if (s[i] >= 'A' && s[i] <= 'Z') {
//				s[i] = s[i] - 'A' + 'a';
//			}
//		}
//		bool flag = 0;
//		if (s[0] != arr[cnt]) flag = 1;
//		for (int i = 0; i < s.size(); i++) {
//			if (s[i] != arr[cnt]) {
//				cnt++;
//				if (cnt < 4 && s[i] != arr[cnt]) flag = 1;
//			}
//			if (cnt >= 4) {
//				flag = 1;
//				break;
//			}
//		}
//		if (cnt != 3) flag = 1;
//		if (flag) cout << "NO\n";
//		else cout << "YES\n";
//	}
//	return 0;
//}

/*B. Count the Number of Pairs*/
//const int N = 2e5 + 10;
//map<char, int> g;
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		g.clear();
//		int n, k;
//		cin >> n >> k;
//		string s;cin >> s;
//		for (int i = 0; i < n; i++) {
//			g[s[i]]++;
//		}
//		int cnt = 0;
//		for (char i = 'a'; i <= 'z'; i++) {
//			int x = g[i];
//			int X = g[i - 'a' + 'A'];
//			int shen = abs(X - x) / 2;
//			cnt += min(X, x);
//			if (shen <= k) {
//				k -= shen;
//				cnt += shen;
//			}
//			else if (k > 0) {
//				cnt += k;
//				k = 0;
//			}
//		}
//		cout << cnt << "\n";
//	}
//	return 0;
//}

/*C1. Powering the Hero (easy version)*/
/*WA*/
//const int N = 2e5 + 10;
//ll arr[N];
//int f[N]; //以n开头的连续0区间的数量
//bool st[N];
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		int n;cin >> n;
//		ll ans = 0;
//		memset(st, 0, sizeof st);
//		for (int i = 1; i <= n; i++) {
//			cin >> arr[i];
//		}
//		f[n] = arr[n] == 0 ? 1 : 0;
//		for (int i = n-1; i >= 1; i--) {
//			if (arr[i] == 0) f[i] = f[i + 1] + 1;
//			else f[i] = 0;
//		}
//		int pos = 1;
//		for (int i = 2; i <= n; i++) {
//			if (arr[i] == 0) {
//				int len = f[i];
//				sort(arr + pos, arr + i);
//				int cnt = i - 1;
//				for (int j = 0; j < len; j++) {
//					if (cnt >= 1) {
//						if (!st[cnt]) {
//							ans += arr[cnt];
//							st[cnt] = 1;
//						}
//						else j--;
//						if (arr[cnt] == 0) j--;
//						cnt--;
//					}
//				}
//				i += len;
//				pos = i;
//			}
//		}
//		cout << ans << "\n";
//	}
//	return 0;
//}
/*map*/
//const int N = 2e5 + 10;
//map<ll, int, greater<ll>> g;
//
//int main() {
//	int t;cin >> t;
//	while (t--) {
//		int n;cin >> n;
//		g.clear();
//		ll ans = 0;
//		for (int i = 0; i < n; i++) {
//			ll x;cin >> x;
//			if (x == 0) {
//				for (auto t : g) {
//					ans += t.first;
//					g[t.first]--;
//					if (g[t.first] == 0) g.erase(t.first);
//					break;
//				}
//			}
//			else g[x]++;
//		}
//		cout << ans << "\n";
//	}
//	return 0;
//}

