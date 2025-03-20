#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*A. Round Down the Price*/
//int main() {
//	ll t;cin >> t;
//	while (t--) {
//		ll n;ll cnt = 0;
//		cin >> n;
//		ll tmp = n;
//		while (tmp) {
//			tmp /= 10;
//			cnt++;
//		}
//		ll res = pow(10, cnt-1);
//		ll ans = n - res;
//		cout << ans << "\n";
//	}
//	return 0;
//}

/*B. Polycarp Writes a String from Memory*/
//int main() {
//	int t; cin >> t;
//	while (t--) {
//		string s;cin >> s;
//		int cnt = 0;
//		int i = 0;
//		while (i < s.size()) {
//			map<char, int> g;
//			while (g.size() <= 3 && i < s.size()) {
//				g[s[i]]++;
//				i++;
//				if (g.size() > 3)i--;
//			}
//			cnt++;
//		}
//		cout << cnt << "\n";
//	}
//	return 0;
//}

/*C. Train and Queries*/
//int n, k;
//const int N = 2e5 + 10;
//int arr[N];
//map<int, int> ga;
//map<int, int> gb;
//int main() {
//	ios::sync_with_stdio(0);
//	int t; cin >> t;
//	while (t--) {
//		ga.clear();
//		gb.clear();
//		cin >> n >> k;
//		for (int i = 0; i < n; i++) {
//			cin >> arr[i];
//		}
//		for (int i = n - 1; i >= 0; i--) {
//			ga[arr[i]] = i;
//		}
//		for (int i = 0; i < n; i++) {
//			gb[arr[i]] = i;
//		}
//		while (k--) {
//			int a, b; cin >> a >> b;
//			if (!ga.count(a) || !gb.count(b)) {
//				cout << "NO\n";
//				continue;
//			}
//			int posa = ga[a];
//			int posb = gb[b];
//			//cout << posa << " " << posb << "\n";
//			if (posb - posa > 0) cout << "YES\n";
//			else cout << "NO\n";
//		}
//	}
//	return 0;
//}

///*D. Not a Cheap String*/
////尽可能装多，贪心
//const int N = 2e5 + 10;
//const int P = 6e6 + 10;
//PII arr[N];
//
//int main() {
//	ios::sync_with_stdio(0);
//	int t; cin >> t;
//	while (t--) {
//		string s; cin >> s;
//		int n = s.size();
//		for (int i = 0; i < n; i++) {
//			arr[i] = { s[i] - 'a'+1,i };
//		}
//		int p; cin >> p;
//		sort(arr, arr + n, [](auto x, auto y) {
//			return x.first < y.first; });
//		int res = 0;
//		int sum = 0;
//		for (int i = 0; i < n; i++) {
//			if (sum + arr[i].first > p) break;
//			sum += arr[i].first;
//			res++;
//		}
//		sort(arr, arr + res, [](auto x, auto y) {
//			return x.second < y.second;});
//		string ans;
//		for (int i = 0; i < res; i++) {
//			ans += arr[i].first + 'a'- 1;
//		}
//		cout << ans << "\n";
//	}
//	return 0;
//}

/*E. Split Into Two Sets*/ //UF //并查集/二分图
////1.同一数字出现三次
////2.一组有相同的数字
////当我的进组可以随便时，？
//const int N = 2e5 + 10;
//
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//
//	}
//	return 0;
//}

/*G1. Passable Paths (easy version) (WA)*/ //写错了好多(其实是二叉树)
//#define to second
//#define w first
//const int N = 2e5 + 10;
//int n, k, q;
//int arr[N];
//vector<PII> node[N];
//priority_queue<PII> pq;
//string s[N];
//map<string, bool> g;
//void bfs() {
//	pq.push({ 0,1 });
//	s[1] = "1";
//	while (pq.size()) {
//		auto t = pq.top();
//		pq.pop();
//		int pos = t.to;
//		int cost = t.w;
//		if (node[pos].size() == 0) {
//			sort(s[pos].begin(), s[pos].end());
//			g[s[pos]] = 1;
//		}
//		for (int i = 0; i < node[pos].size(); i++) {
//			int to = node[pos][i].to;
//			int w = node[pos][i].w + cost;
//			char ch = to + '0';
//			s[to] = s[pos] + ch;
//			pq.push({ w,to });
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n;
//	for (int i = 0; i < n - 1; i++) {
//		int u, v;cin >> u >> v;
//		node[u].push_back({ 1,v });
//	}
//	bfs();
//	cin >> q;
//	while (q--) {
//		cin >> k;
//		for (int i = 0; i < k; i++) {
//			cin >> arr[i];
//		}
//		sort(arr, arr + k);
//		string ss;
//		for (int i = 0; i < k; i++) {
//			ss += arr[i] + '0';
//		}
//		if (g[ss]) cout << "YES\n";
//		else cout << "NO\n";
//	}
//}
