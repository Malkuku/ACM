#define _CRT_SECURE_NO_WARNINGS 1
//不急不急 >_< !
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*A. Immobile Knight*/
//int dx[] = {1,1,-1,-1,2,2,-2,-2};
//int dy[] = {2,-2,2,-2,1,-1,1,-1};
//
//int main() {
//	int t;cin >> t;
//	while (t--) {
//		bool flag = 0;
//		int n, m;cin >> n >> m;
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++) {
//				bool flag2 = 0;
//				for (int k = 0; k < 8; k++) {
//					int xx = i + dx[k];
//					int yy = j + dy[k];
//					if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
//					flag2 = 1;
//				}
//				if (flag2 == 0) flag = 1;
//				if (flag) {
//					cout << i << " " << j << "\n";
//					break;
//				}
//			}
//			if (flag) break;
//		}
//		if (flag == 0) cout << n << " " << m << "\n";
//	}
//	return 0;
//}

/*B. Array Recovery*/


/*E.Image*/
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		map<char, int> g;
//		for (int i = 0; i < 4; i++) {
//			char ch; cin >> ch;
//			g[ch]++;
//		}
//		if (g.size() == 1) cout << 0 << "\n";
//		else if (g.size() == 2) cout << 1 << "\n";
//		else if (g.size() == 3) cout << 2 << "\n";
//		else if (g.size() == 4) cout << 3 << "\n";
//	}
//	return 0;
//}

/*F. Deadly Laser*/
//int dx[] = { 1,0,-1,0 };
//int dy[] = { 0,1,0,-1 };
//int g[1010][1010];
//int n, m, sx, sy, d;
//int dist[1010][1010];
//int st[1010][1010];
//int ans;
//void dfs() {
//	queue<PII> q;
//	q.push({ 1,1 });
//	q.push({ n,m });
//	dist[1][1] = 0;
//	dist[n][m] = 0;
//	st[1][1] = 1;
//	st[n][m] = 2;
//	while (q.size()) {
//		auto t = q.front();
//		q.pop();
//		int x = t.first;
//		int y = t.second;
//		for (int i = 0; i < 4; i++) {
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//			if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
//			if ((st[xx][yy] + st[x][y]) % 3 == 0) {
//				ans = dist[xx][yy] + dist[x][y] + 1;
//				break;
//			}
//			if (st[xx][yy] || abs(sx - xx) + abs(sy - yy) <= d) continue;
//			dist[xx][yy] = dist[x][y] + 1;
//			st[xx][yy] = st[x][y];
//			q.push({ xx,yy });
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int t;cin >> t;
//	while (t--) {
//		cin >> n >> m >> sx >> sy >> d;
//		memset(dist, 0x3f, sizeof dist);
//		memset(st, 0, sizeof st);
//		ans = -1;
//		int lx = sx - d;
//		int ly = sy - d;
//		int rx = sx + d;
//		int ry = sy + d;
//		if (abs(sx - n) + abs(sy - m) <= d) cout << -1 << "\n";
//		else if (lx <= 1 && ly <= 1 && rx >= n && ry >= m) cout << -1 << "\n";
//		else {
//			dfs();
//			cout << ans << "\n";
//		}
//	}
//	return 0;
//}

//int dx[] = { 1,0,-1,0 };
//int dy[] = { 0,1,0,-1 };
//int n, m, sx, sy, d;
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		cin >> n >> m >> sx >> sy >> d;
//		bool flag = 1;
//		int lx = sx - d;
//		int ly = sy - d;
//		int rx = sx + d;
//		int ry = sy + d;
//		if (abs(sx - n) + abs(sy - m) <= d) cout << -1 << "\n";
//		else if (lx <= 1 && rx >= n) cout << -1 << "\n";
//		else if (ly <= 1 && ry >= m) cout << -1 << "\n";
//		else if (rx >= n && ry >= m) cout << -1 << "\n";
//		else if (lx <= 1 && ly <= 1) cout << -1 << "\n";
//		else {
//			int dist = n - 1 + m - 1;
//			cout << dist << "\n";
//		}
//	}
//	return 0;
//}
/*B. Array Recovery*/
//int d[110];
//int a[110];
//
//int main() {
//	ios::sync_with_stdio(0);
//	int t; cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		for (int i = 0; i < n; i++) {
//			cin >> d[i];
//		}
//
//		map<int, bool> g[110];
//		a[0] = d[0];
//		for (int i = 1; i < n; i++) {
//			int a1 = a[i - 1] + d[i];
//			int a2 = a[i - 1] - d[i];
//			if (a1 >= 0) {
//				a[i] = a1;
//				g[i][a1] = 1;
//			}
//			if (a2 >= 0) {
//				a[i] = a2;
//				g[i][a2] = 1;
//			}
//		}
//		bool flag = 0;
//		for (int i = 1; i < n; i++) {
//			if (g[i].size() >= 2) {
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0) {
//			for (int i = 0; i < n; i++) {
//				cout << a[i] << " ";
//			}cout << "\n";
//		}
//		else cout << -1 << "\n";
//	}
//	return 0;
//}

/*I. 2-3 Moves*/
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		int ans = 0;
//		if (n % 3 == 2) ans = n / 3 + 1;
//		else if (n % 3 == 1) ans = n / 3 + 1;
//		else if (n % 3 == 0) ans = n / 3;
//		if (n == 1) ans = 2;
//		cout << ans << '\n';
//	}
//	return 0;
//}

/*L. Recover an RBS*/
//int main() {
//	ios::sync_with_stdio(0);
//	int t; cin >> t;
//	while (t--) {
//		string s;
//		cin >> s;
//		bool flag = 0;
//		int len = s.size();
//		s[0] = '('; 
//		s[len - 1] = ')';
//
//		if (flag) cout << "NO\n";
//		else cout << "YES\n";
//	}
//}
/*2024.4.8 题解 贪心*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
//	int t;cin >> t;
//	while (t--) {
//		string s;
//		cin >> s;
//		int ldep = 0;
//		int cnt = 0;
//		for (int i = 0; i < s.size(); i++) {
//			if (s[i] == '?') cnt++;
//			else if (s[i] == '(') ldep++;
//			else if (s[i] == ')') {
//				if (ldep <= 0) cnt--;
//				else ldep--;
//			}
//			//如果没有剩余的左括号可以消耗，且只剩下一个？，则这个？应该被转化成右括号
//			if (cnt == 1 && ldep == 0) {
//				cnt--;
//				ldep++;
//			}
//		}
//		if (ldep == cnt) cout << "YES\n";
//		else cout << "NO\n";
//	}
//	return 0;
//}

/*C. Card Game*/
/*2024.4.8 题解 思维*/
////将先手赢分情况
////1.先手有8， C（7，3）
////2.先手有7，6，5  C(4，2)
////3.先手有7，6 f（4） //因为5-8平了
//// dp[i] = c(i,i-1) + c(i,i-3) + dp[i-4]
//ll C[63][63];
//const int mod = 998244353;
//void init() {
//	for (int i = 0; i <= 60; i++) { //从0开始
//		C[i][0] = 1;
//	}
//	for (int i = 1; i <= 60; i++) {
//		for (int j = 1; j <= i; j++) {
//			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
//			C[i][j] %= mod;
//		}
//	}
//}
//ll dp[70];
//void init2() {
//	dp[2] = 1;
//	dp[4] = 3;
//	for (int i = 6; i <= 60; i += 2) {
//		dp[i] = dp[i - 4] + C[i-1][i/2] + C[i-4][i/2 - 3];
//		dp[i] %= mod;
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	init();
//	init2();
//	while (t--) {
//		int n; cin >> n;
//		ll b = (C[n][n / 2] - dp[n] - 1 + mod) % mod; //这样
//		cout << dp[n]<<" " << b << " " << 1 << "\n";
//	}
//	return 0;
//}

/*M. Rorororobot*/

/*J. Permutation Chain*/
//int a[110];
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		cout << n << "\n";
//		for (int i = 1; i <= n; i++) {
//			a[i] = i;
//			cout << a[i] << " ";
//		}cout << "\n";
//		for (int i = 1; i < n; i++)
//		{
//			swap(a[n], a[n - i]);
//			for (int j = 1; j <= n; j++)
//			{
//				cout << a[j] << " ";
//			}
//			cout << "\n";
//		}
//	}
//	return 0;
//}