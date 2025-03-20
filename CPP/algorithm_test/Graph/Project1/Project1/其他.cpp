#define _CRT_SECURE_NO_WARNINGS 1


/*luogu P1351 [NOIP2014 提高组] 联合权值 */
/*2024.5.17*/ //基于除法分配率的n^2优化
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 2e5 + 10;
//int head[N];
//ll w[N];
//int cnt = 0;
//struct {
//	int v, next;
//}node[N<<1];
//
//void add(int u, int v) {
//	cnt++;
//	node[cnt].v = v;
//	node[cnt].next = head[u];
//	head[u] = cnt;
//}
//
//int in[N];//每个点链接的点数
//const int mod = 10007;
//ll ans1 = 0, ans2 = 0;
//int n, m;
//
//void check(int x) {
//	vector<int> arr;
//	for (int i = head[x]; i; i = node[i].next) {
//		arr.push_back(node[i].v);
//	}
//	//这里要优化掉n^2
//	ll maxn = 0;
//	ll sum = 0;
//	ll sump = 0;
//	for (int i = 0; i < arr.size(); i++) {
//		ans1 = max(ans1, maxn * w[arr[i]]);
//		sum += w[arr[i]];
//		sump += w[arr[i]] * w[arr[i]];
//		sum %= mod;
//		sump %= mod;
//		maxn = max(maxn, w[arr[i]]);
//	}
//	sum = sum * sum - sump;
//	//cout << sum << "\n";
//	sum %= mod;
//	ans2 += sum;
//	ans2 %= mod;
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n;
//	for (int i = 1; i <= n - 1; i++) {
//		int u, v;cin >> u >> v;
//		add(u, v);
//		add(v, u);
//		in[u]++, in[v]++;
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> w[i];
//		//cout << in[i] << "\n";
//	}
//	for (int i = 1; i <= n; i++) {
//		if (in[i] < 2) continue;
//		check(i);
//	}
//	cout << ans1 << " " << ans2 << "\n";
//	return 0;
//}
