#define _CRT_SECURE_NO_WARNINGS 1

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*A. Love Story*/
//int main() {
//	string a = "codeforces";
//	int t;cin >> t;
//	while (t--) {
//		string s;
//		cin >> s;
//		int res = 0;
//		for (int i = 0; i < a.size(); i++) {
//			if (s[i] != a[i]) res++;
//		}
//		cout << res << "\n";
//	}
//	return 0;
//}

/*B. Blank Space*/
//const int N = 110;
//int a[N];
//int main() {
//	int t; cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		for (int i = 0; i < n; i++) cin >> a[i];
//		int res = 0;
//		int ans = 0;
//		for (int i = 0; i < n; i++) {
//			if (a[i] == 0) res++;
//			else res = 0;
//			ans = max(ans, res);
//		}
//		cout << ans << "\n";
//	}
//	return 0;
//}

/*C. Mr. Perfectly Fine*/
//const int N = 2e5 + 10;
//string s[N];
//int cost[N];
//
//int main() {
//	ios::sync_with_stdio(0);
//	int t; cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		for (int i = 0; i < n; i++) {
//			cin >> cost[i] >> s[i];
//		}
//		int sk1 = 0x3f3f3f3f;
//		int sk2 = 0x3f3f3f3f;
//		int sk3 = 0x3f3f3f3f;
//		for (int i = 0; i < n; i++) {
//			if (s[i][0] == '1' && s[i][1] == '0') {
//				sk1 = min(sk1, cost[i]);
//			}
//			if (s[i][0] == '0' && s[i][1] == '1') {
//				sk2 = min(sk2, cost[i]);
//			}
//			if (s[i][0] == '1' && s[i][1] == '1') {
//				sk3 = min(sk3, cost[i]);
//			}
//		}
//		int ans = sk1 + sk2;
//		ans = min(ans, sk3);
//		if (ans < 0x3f3f3f3f)cout << ans << "\n";
//		else cout << -1 << "\n";
//	}
//	return 0;
//}

/*D. Gold Rush*/
//const int N = 1e7 + 10;
//int arr[100000];
//bool flag = 0;
//void isY(int n, int m) {
//	if (n <= m) return;
//	    if (n % 3 == 0) {
//			int a1 = n / 3;
//			int a2 = a1 + a1;
//			if (a1 == m || a2 == m) {
//				flag = 1;
//			}
//			else {
//				isY(a1, m);
//				isY(a2, m);
//			}
//			return;
//		}
//}
//int main() {
//	int t; cin >> t;
//	while (t--) {
//		flag = 0;
//		int n, m; cin >> n >> m;
//		if (n == m) {
//			cout << "YES\n";
//			continue;
//		}
//		isY(n, m);
//		if (flag) cout << "YES\n";
//		else cout << "NO\n";
//	}
//	return 0;
//}

/*E. The Lakes*/
//const int N = 1010;
//int g[N][N];
//bool vis[N][N];
//int dx[] = { 1, 0, -1, 0 };
//int dy[] = { 0, 1, 0 ,-1 };
//int n, m;
//int bfs(int a, int b) {
//	queue<PII> q;
//	q.push({ a,b });
//	int sum = g[a][b];
//	vis[a][b] = 1;
//	while (q.size()) {
//		auto t = q.front();
//		q.pop();
//		int x = t.first;
//		int y = t.second;
//		for (int i = 0; i < 4; i++) {
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//			if (xx <= 0 || yy <= 0 || xx > n || yy > m) continue;
//			if (vis[xx][yy] || g[xx][yy] <= 0) continue;
//			q.push({ xx,yy });
//			sum += g[xx][yy];
//			vis[xx][yy] = 1;
//		}
//	}
//	return sum;
//}
//int main() {
//	int t;scanf("%d", &t);
//	while (t--) {
//		int ans = 0;
//		memset(vis, 0, sizeof vis);
//		scanf("%d %d", &n, &m);
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++) {
//				scanf("%d", &g[i][j]);
//			}
//		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++) {
//				if (!vis[i][j] && g[i][j] > 0) {
//					int res = bfs(i,j);
//					ans = max(ans, res);
//				}
//			}
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}
/*2024.3.5*/ //别再写错模拟队列了
//const int N = 1010;
//int g[N][N];
//bool vis[N][N];
//int dx[] = { 1, 0, -1, 0 };
//int dy[] = { 0, 1, 0 ,-1 };
//int n, m;
//PII q[N * N];
//int bfs(int a, int b) {
//	int hh = 0, tt = 0;
//	q[tt++] = { a,b };
//	int sum = g[a][b];
//	vis[a][b] = 1;
//	while (hh < tt) {
//		auto t = q[hh++];
//		int x = t.first;
//		int y = t.second;
//		for (int i = 0; i < 4; i++) {
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//			if (xx <= 0 || yy <= 0 || xx > n || yy > m) continue;
//			if (vis[xx][yy] || g[xx][yy] <= 0) continue;
//			q[tt++] = { xx,yy };
//			sum += g[xx][yy];
//			vis[xx][yy] = 1;
//		}
//	}
//	return sum;
//}
//int main() {
//	int t;scanf("%d", &t);
//	while (t--) {
//		int ans = 0;
//		memset(vis, 0, sizeof vis);
//		scanf("%d %d", &n, &m);
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++) {
//				scanf("%d", &g[i][j]);
//			}
//		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++) {
//				if (!vis[i][j] && g[i][j] > 0) {
//					int res = bfs(i, j);
//					ans = max(ans, res);
//				}
//			}
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}
//

/*F. Forever Winter*/
//const int N = 1010;
//
//int main() {
//	ios::sync_with_stdio(0);
//	int t; cin >> t;
//	while (t--) {
//		map<int, int> g;
//		int n, m; cin >> n >> m;
//		for (int i = 1; i <= m; i++) {
//			int u, v;cin >> u >> v;
//			g[u]++;
//			g[v]++;
//		}
//		vector<int> arr;
//		for (auto t : g) {
//			arr.push_back(t.second);
//		}
//		sort(arr.begin(), arr.end(), [](auto x, auto y) {
//			return x > y;
//			});
//		int x = arr[0];
//		int y = -1;
//		int cnt = 0;
//		for (int i = 1; i < x; i++) {
//			if (arr[i] != x) {
//				y = arr[i];
//				break;
//			}
//			else cnt++;
//		}
//		if (y == -1) cout << x << " " << x - 1 << "\n";
//		else if (cnt) {
//			cout << y << " " << x - 1 << "\n";
//		}
//		else cout << x << " " << y - 1 << "\n";
//	}
//	return 0;
//}
