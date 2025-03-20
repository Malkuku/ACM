#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*A. Plus or Minus*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//int main() {
//	int t; cin >> t;
//	while (t--) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		if (a + b == c) cout << "+\n";
//		else if (a - b == c) cout << "-\n";
//	}
//	return 0;
//}

/*B. Grab the Candies*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
////even -> M
////ji -> B
//int main() {
//	int a[110];
//	int t; cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		int m = 0, b = 0;
//		for (int i = 0; i < n; i++) {
//			cin >> a[i];
//		}
//		for (int i = 0; i < n; i++) {
//			if (a[i] % 2) b += a[i];
//			else m += a[i];
//		}
//		if (m > b) cout << "Yes\n";
//		else cout << "No\n";
//	}
//	return 0;
//}
//

/*C. Find and Replace*/
//int main() {
//	int t; cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		map<int, bool> g;
//		char ch;
//		string s; cin >> s;
//		bool flag = 0;
//		for (int i = 0; i < n; i++) {
//			if (g[s[i]]) continue;
//			ch = s[i];
//			g[s[i]] = 1;
//			int hao = i;
//			for (int j = i + 1; j < n; j++) {
//				if (s[j] == ch) {
//					if ((hao - j + 1) % 2 == 0) {
//						flag = 1;
//						break;
//					}
//					else {
//						hao = j;
//					}
//				}
//			}
//		}
//		if (flag) cout << "NO\n";
//		else cout << "YES\n";
//	}
//	return 0;
//}

/*D. Odd Queries*/
////odd change
//const int N = 2e5 + 10;
//ll a[N];
//ll s[N];
//int main() {
//	ios::sync_with_stdio(0);
//	int t; cin >> t;
//	while (t--) {
//		int n, q;cin >> n >> q;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//		}
//		s[0] = 0;
//		s[1] = a[1];
//		for (int i = 2; i <= n; i++) {
//			s[i] = s[i - 1] + a[i];
//		}
//		bool ans = 0; //0 odd
//		if (s[n] % 2 == 0) ans = 1;
//		while (q--) {
//			int l, r, k;
//			cin >> l >> r >> k;
//			int cover = r - l + 1;
//			ll sum1 = k * cover;
//			ll sum2 = s[r] - s[l - 1];
//			sum1 = abs(sum2 - sum1);
//			if (sum1 % 2 && ans == 0) { //ji+ji
//				cout << "NO\n";
//			}
//			else if (sum1 % 2 && ans) { //ji+ou
//				cout << "YES\n";
//			}
//			else if (sum1 % 2 == 0 && ans == 0) { //ou + ji
//				cout << "YES\n";
//			}
//			else if (sum1 % 2 == 0 && ans) { //ou + ou
//				cout << "NO\n";
//			}
//		}
//	}
//	return 0;
//}

/*E. Interview*/

/*G1. Subsequence Addition (Easy Version)*/
//const int N = 5010;
//int a[N];
//bool dp[N];
//void so1(int x) {
//	memset(dp, 0, sizeof dp);
//	dp[0] = 1;
//	for (int i = 0; i < x; i++) {
//		for (int j = a[x]; j >= a[i]; j--) {
//			dp[j] = dp[j - a[i]];
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	int t; cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		memset(dp, 0, sizeof dp);
//		for (int i = 0; i < n; i++) {
//			cin >> a[i];
//		}
//		sort(a, a + n); //可以是背包 //dp[i]能否装满
//		bool flag = 0;
//		for (int i = 0; i < n; i++) {
//			if (a[i] == 1) continue;
//			so1(i);
//			if (dp[a[i]] == 0) {
//				flag = 1;
//				break;
//			}
//		}
//		if (flag) {
//			cout << "NO\n";
//		}
//		else cout << "YES\n";
//	}
//	return 0;
//}
/*贪心*/
//const int N = 2e5+10;
//ll a[N];
//bool dp[N];
//ll s[N];
//int main() {
//	ios::sync_with_stdio(0);
//	int t; cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//		}
//		sort(a, a + n + 1);
//		s[0] = 0;
//		s[1] = a[1];
//		for (int i = 2; i <= n; i++) {
//			s[i] = s[i - 1] + a[i];
//		}
//		bool flag = 0;
//		for (int i = 2; i <= n; i++) {
//			if (s[i - 1] < a[i]) {
//				flag = 1;
//				break;
//			}
//		}
//		if (a[1] != 1) flag = 1;
//		if (flag) {
//			cout << "NO\n";
//		}
//		else cout << "YES\n";
//	}
//	return 0;
//}

/*F. Bouncy Ball*/ //比较复杂的模拟\BFS