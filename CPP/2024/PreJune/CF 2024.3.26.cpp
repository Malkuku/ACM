#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*A. Marathon*/
//int main() {
//	int t;cin >> t;
//	while (t--) {
//		int a;
//		int b[3];
//		cin >> a;
//		for (int i = 0; i < 3; i++) cin >> b[i];
//		int cnt = 0;
//		for (int i = 0; i < 3; i++) {
//			if (a < b[i]) cnt++;
//		}
//		cout << cnt << "\n";
//	}
//	return 0;
//}

/*B. All Distinct*/
//const int N = 1e4 + 10;
//vector<int> a;
//int main() {
//	int t; cin >> t;
//	while (t--) {
//		a.clear();
//		int n;cin >> n;
//		for (int i = 0; i < n; i++) {
//			int x;cin >> x;
//			a.push_back(x);
//		}
//		int len1 = a.size();
//		sort(a.begin(), a.end());
//		a.erase(unique(a.begin(), a.end()), a.end());
//		int len2 = a.size();
//		int cnt = len1 - len2;
//		if (cnt & 1) cnt++;
//		int ans = n - cnt;
//		cout << ans << "\n";
//	}
//	return 0;
//}

/*C. Where's the Bishop?*/
//char g[9][9];
//int main() {
//	int t; cin >> t;
//	while (t--) {
//		int x, y;
//		for (int i = 1; i <= 8; i++) {
//			for (int j = 1; j <= 8; j++) {
//				cin >> g[i][j];
//			}
//		}
//		bool flag = 0;
//		for (int i = 1; i <= 8; i++) {
//			int cnt = 0;
//			int j = 1;
//			int x, y;
//			for (j = 1; j <= 8; j++) {
//				if (g[i][j] == '#') {
//					cnt++;
//					x = i;
//					y = j;
//				}
//			}
//			if (cnt == 2) flag = 1;
//			if (cnt == 1 && flag) {
//				cout << x << " " << y << "\n";
//				break;
//			}
//		}
//	}
//	return 0;
//}

/*D. The Clock*/
//int hour, mi;
//void change(string& s) {
//	int h = (s[0] - '0') * 10 + s[1] - '0';
//	int m = (s[3] - '0') * 10 + s[4] - '0';
//	m += mi;
//	h += hour + (m / 60);
//	m %= 60;
//	h %= 24;
//	if(m < 10)s = to_string(h) + ":" + "0" + to_string(m);
//	else s = to_string(h) + ":" + to_string(m);
//	if (h < 10) s = "0" + s;
//}
//int main() {
//	int t;cin >> t;
//	while (t--) {
//		string tim;
//		cin >> tim >> mi;
//		hour = mi / 60 % 24;
//		mi = mi % 60;
//
//		string start = tim;
//		
//		map<string, bool> g;
//		string tmp = tim;
//		reverse(tmp.begin(),tmp.end());
//		if (tmp == tim) g[tmp] = 1;
//		change(tim);
//		while (tim != start) {
//			string tmp = tim;
//			reverse(tmp.begin(), tmp.end());
//			if (tmp == tim) {
//				g[tmp] = 1;
//				//cout << tmp << "\n";
//			}
//			change(tim);
//		}
//		cout << g.size() << "\n";
//	}
//	return 0;
//}

/*E. Binary Deque*/
//const int N = 2e5 + 10;
//int arr[N];
//int ss[N];
//vector<int> g1;
//vector<int> g2;
//
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		g1.clear();
//		g2.clear();
//		int n, s;
//		cin >> n >> s;
//		int sum = 0;
//		for (int i = 1; i <= n; i++) {
//			cin >> arr[i];
//			if (arr[i]) {
//				sum++;
//			}
//		}
//		if (arr[1] == 0) {
//			for (int i = 2; i <= n; i++) {
//				if (arr[i]) {
//					g1.push_back(i);
//					break;
//				}
//			}
//		}
//		for (int i = 1; i <= n; i++) {
//			if (arr[i]) g1.push_back(i);
//		}
//		if (arr[n] == 0) {
//			for (int i = n-1; i >= 1; i--) {
//				if (arr[i]) {
//					g1.push_back(i);
//					break;
//				}
//			}
//		}
//		if (sum < s) {
//			cout << -1 << "\n";
//			continue;
//		}
//		if (sum == s) {
//			cout << 0 << "\n";
//			continue;
//		}
//		int cnt = 0;
//		int l = 1, r = n;
//		int pos1 = 0, pos2 = g1.size() - 1;
//		while (l < r) {
//			int dis1 = abs(g1[pos1] - g1[pos1 + 1]);
//			int dis2 = abs(g1[pos2] - g1[pos2 - 1]);
//			if (dis1 < dis2) {
//				cnt += dis1;
//				l += dis1;
//				pos1++;
//				sum--;
//			}
//			else {
//				cnt += dis2;
//				r -= dis2;
//				pos2--;
//				sum--;
//			}
//			if (sum == s) break;
//		}
//		cout << cnt << "\n";
//	}
//	return 0;
//}
/*滑动窗口 因为是从俩边减数*/ //记得先搞清楚三问三答
//const int N = 2e5 + 10;
//int a[N];
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		int n, s;
//		cin >> n >> s;
//		int sum = 0;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i];
//			if (a[i]) sum++;
//		}
//		if (sum < s) {
//			cout << -1 << "\n";
//			continue;
//		}
//		else if (sum == s) {
//			cout << 0 << "\n";
//			continue;
//		}
//		int l = 1; int r = 1;
//		int res = 0;
//		int len = 0;
//		while (r <= n) {
//			while (res <= s && r <= n) {
//				if (a[r]) res++;
//				if (res == s) len = max(len, r - l + 1);
//				r++;
//			}
//			while (res > s) {
//				if (a[l]) res--;
//				l++;
//			}
//		}
//		cout << n - len << "\n";
//	}
//	return 0;
//}

/*F.3SUM*/
//const int N = 2e5 + 10;
//ll a[N];
//bool flag = 0;
//ll sum = 0;
//bool st[N];
//void dfs(int x,vector<int>& arr) {
//	if (flag) return;
//	if (x >= 3) {
//		if (sum % 10 == 3) flag = 1;
//		return;
//	}
//	for (int i = 0; i < arr.size(); i++) {
//		if (st[i]) continue;
//		sum += arr[i];
//		st[i] = 1;
//		dfs(x + 1, arr);
//		sum -= arr[i];
//		st[i] = 0;
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	int t; cin >> t;
//	while (t--) {
//		flag = 0;
//		sum = 0;
//		int n; cin >> n;
//		map<int, int> g;
//		for (int i = 0; i < n; i++){
//			cin >> a[i];
//			if (g[a[i] % 10] >= 3) continue;
//			g[a[i] % 10]++;
//		}
//		vector<int> b;
//		for (auto t : g) {
//			for (int i = 0; i < t.second; i++)
//				b.push_back(t.first);
//		}
//		dfs(0,b);
//		if (flag) cout << "YES\n";
//		else cout << "NO\n";
//	}
//	return 0;
//}

/*G. 2^Sort*/
//WA:用到了a[n]没有把a[n]重置
//const int N = 2e5 + 10;
//ll a[N];
//
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		int n,k;cin >> n >> k;
//		for (int i = 0; i < n; i++) cin >> a[i];
//		vector<int> b;
//		int cnt = 0;
//		a[n] = 0;
//		for (int i = 0; i < n; i++) {
//			if (a[i] < a[i + 1] * 2) cnt++;
//			else {
//				b.push_back(cnt+1);
//				cnt = 0;
//			}
//		}
//		ll ans = 0;
//		for (int i = 0; i < b.size(); i++) {
//			if (b[i] < k + 1) continue;
//			else {
//				ans += b[i] - k;
//			}
//		}
//		cout << ans << "\n";
//	}
//	return 0;
//}
