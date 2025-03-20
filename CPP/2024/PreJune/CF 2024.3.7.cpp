#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*A. Musical Puzzle*/
//int main() {
//	int t; cin >> t;
//	while (t--) {
//		string s;int n;
//		cin >> n; cin >> s;
//		map<string, bool> g;
//		for (int i = 0; i < n-1; i++) {
//			string tmp; 
//			tmp += s[i];
//			tmp += s[i + 1];
//			g[tmp] = 1;
//		}
//		cout << g.size() << "\n";
//	}
//	return 0;
//}

/*B. Restore the Weather*/
//int k, n;
//const int N = 1e5 + 10;
//PII a[N];
//int b[N];
//int ans[N];
//int main() {
//	ios::sync_with_stdio(0);
//	int t; cin >> t;
//	while (t--) {
//		cin >> n >> k;
//		for (int i = 0; i < n; i++) {
//			int x;cin >> x;
//			a[i] = { x,i };
//		}
//		for (int i = 0; i < n; i++) cin >> b[i];
//		sort(a, a + n);
//		sort(b, b + n);
//
//		for (int i = 0; i < n; i++) {
//			auto t = a[i];
//			int pos = t.second;
//			ans[pos] = b[i];
//		}
//		for (int i = 0; i < n; i++) {
//			cout << ans[i] << " ";
//		}cout << "\n";
//
//	}
//	return 0;
//}

/*C. Vlad Building Beautiful Array*/
////最小的奇偶数出现的地方
////最前是寄，变全奇
////最前是偶，必须全偶
//const int N = 2e5 + 10;
//int a[N];
//
//int main() {
//	int t; cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		for (int i = 0; i < n; i++) cin >> a[i];
//		sort(a, a + n);
//		if (a[0] & 1) cout << "YES\n";
//		else {
//			bool flag = 0;
//			for (int i = 1; i < n; i++) {
//				if (a[i] & 1) {
//					flag = 1;
//					break;
//				}
//			}
//			if (flag) cout << "NO\n";
//			else cout << "YES\n";
//		}
//	}
//	return 0;
//}

/*D. Flipper*/
//const int N = 2010;
//int a[N];
//int b[N][N];
//int ans[N];
//int n;
//bool cmp(int ans[], int b[]) {
//	for (int i = 1; i <= n; i++) {
//		if (ans[i] < b[i]) return 1;
//		else if (ans[i] > b[i]) return 0;
//	}
//	return 0;
//}
//bool cmp2(int ans[], int a[]) {
//	for (int i = 1; i <= n; i++) {
//		if (ans[i] < a[i]) return 1;
//		else if (ans[i] > a[i]) return 0;
//	}
//	return 0;
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		cin >> n;
//		int maxpos = -1;
//		int maxa = 0;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//		}
//
//		if (n == 1) {
//			cout << a[1] << "\n";
//			continue;
//		}
//
//		for (int i = 2; i <= n; i++) {
//			if (a[i] > maxa) {
//				maxa = a[i];
//				maxpos = i;
//			}
//		}
//		int cnt = 1;
//		while (cnt <= maxpos - 1) {
//			int res = 1;
//			for (int i = maxpos; i <= n; i++) {
//				b[cnt][res++] = a[i];
//			}
//			int tmp = cnt;
//			for (int i = maxpos - 1;i >= 1; i--) {
//				if (tmp <= 0) break;
//				b[cnt][res++] = a[i];
//				tmp--;
//			}
//			int k = maxpos - 1 - cnt;
//			for (int i = 1; i <= k; i++) {
//				b[cnt][res++] = a[i];
//			}
//			cnt++;
//		}
//		reverse(a + 1, a + n + 1);
//		for (int j = 1; j <= n; j++) ans[j] = b[1][j];
//		for (int i = 2; i <= maxpos - 2; i++) {
//			if (cmp(ans, b[i])) {
//				for (int j = 1; j <= n; j++) ans[j] = b[i][j];
//			}
//		}
//		if(cmp(ans, a)) for (int j = 1; j <= n; j++) ans[j] = a[j];
//		if (maxpos == n) {
//			reverse(a + 1, a + n + 1);
//			int tmp = a[n];
//			for (int i = n; i >= 2; i--) {
//				a[i] = a[i - 1];
//			}
//			a[1] = tmp;
//			if (cmp(ans, a)) for (int j = 1; j <= n; j++) ans[j] = a[j];
//		}
//		for (int i = 1; i <= n; i++) {
//			cout << ans[i] << " ";
//		}cout << "\n";
//	}
//}