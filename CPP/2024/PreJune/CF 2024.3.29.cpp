#define _CRT_SECURE_NO_WARNINGS 1

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*A. Coffee Break*/ //UF
//const int N = 2e5 + 10;
//struct {
//	ll x; //分钟
//	ll pos; //原位置
//	ll dy; //喝咖啡的天数
//}node[N];
////map<ll, int> g;
//int main() {
//	ios::sync_with_stdio(0);
//	ll n, m, d;
//	cin >> n >> m >> d;
//	for (int i = 1; i <= n; i++) {
//		ll x; cin >> x;
//		node[i].x = x;
//		node[i].pos = i;
//	}
//	sort(node + 1, node + n + 1, [](auto a, auto b) {
//		return a.x < b.x;
//		});
//	ll res = 0;
//	ll step = 0;
//	ll cnt = 1;
//	for (int i = 1; i <= n; i++) {
//		ll step = node[i].x;
//		while (step <= m) {
//			res++;
//			int l = 1, r = n;
//			while (l <= r) {
//				int mid = (l + r) >> 1;
//				if(node[mid].x < step)
//			}
//
//			step += d;
//		}
//		cnt++;
//		if (res >= n) break;
//	}
//	sort(node + 1, node + n + 1, [](auto a, auto b) {
//		return a.pos < b.pos;
//		});
//	for (int i = 1; i <= n; i++) {
//		cout << node[i].dy << " ";
//	}
//	return 0;
//}

/*B. Glider*/ //WA
//const int N = 2e5 + 10;
//struct {
//	ll x, y;
//} node[N];
//
//int main() {
//	ios::sync_with_stdio(0);
//	ll n, h;cin >> n >> h;
//
//	for (int i = 1; i <= n; i++) {
//		ll x1, x2;cin >> x1 >> x2;
//		node[i].x = x1;
//		node[i].y = x2;
//	}
//	node[n + 1].x = 1e11;
//	node[n + 1].y = 1e11;//预设无限大
//	ll l = 1, r = 1;
//	ll res = 0;
//	ll len = node[1].y - node[1].x + h;
//	while (r <= n) { //res <= h时更新
//		while (res <= h && r <= n) {
//			res += node[r + 1].x - node[r].y;
//			r++;
//			if (res <= h) len = max(len,node[r].y - node[l].x + h - res);
//		}
//		while (res > h) {
//			res -= (node[l + 1].x - node[l].y);
//			l++;
//		}
//		if (res <= h) len = max(len, node[r].y - node[l].x + h - res);
//	}
//	//ll maxlen = 2e9;
//	//if (len <= maxlen)
//	cout << len << "\n";
//	//else cout << maxlen << "\n";
//	return 0;
//}
/*2024.4.8 题解 前缀和二分*/
//int n, h;
//const int N = 2e5 + 10;
//int l[N];
//int r[N];
//int add[N];
//int cost[N];
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> h;
//	for (int i = 1; i <= n; i++) {
//		cin >> l[i] >> r[i];
//	}
//	cost[n] = 2e9 + 10; //无限长
//	for (int i = 1; i < n; i++) {
//		add[i] = add[i - 1] + r[i] - l[i];
//		cost[i] = cost[i - 1] + l[i+1] - r[i];
//	}
//	add[n] = add[n - 1] + r[n] - l[n];
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		int t = lower_bound(cost + 1, cost + 1 + n, cost[i - 1] + h) - cost;//第一个大于等于cost[i - 1] + h的坐标
//		ans = max(ans, add[t] - add[i - 1] + h); //从i出发的
//	}
//	cout << ans << "\n";
//	return 0;
//}
/*2024.4.9*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//
//
//const int N = 2e5 + 10;
//ll cost[N];
//ll add[N];
//ll l[N];
//ll r[N];
//int main() {
//	ios::sync_with_stdio(0);
//	int n;cin >> n;
//	ll h; cin >> h;
//	for (int i = 1; i <= n; i++) {
//		cin >> l[i] >> r[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		add[i] = add[i - 1] + r[i] - l[i];
//	}
//	for (int j = 1; j < n; j++) {
//		cost[j] = cost[j - 1] + l[j + 1] - r[j];
//	}
//	cost[n] = 2e9 + 10;
//	ll ans = 0;
//	for (int i = 1; i <= n; i++) {
//		int pos = lower_bound(cost + 1, cost + 1 + n, cost[i - 1] + h) - cost;
//		ans = max(ans, add[pos] - add[i - 1] + h);
//	}
//	cout << ans << "\n";
//	return 0;
//}

/*I. Heist*/
//ll a[1010];
//int main() {
//	int n;cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	sort(a, a + n);
//	ll res = 0;
//	for (int i = 0; i < n - 1; i++) {
//		res += a[i + 1] - a[i] - 1;
//	}
//	cout << res << "\n";
//	return 0;
//}

/*C. Bacteria*/
//const int N = 2e5 + 10;
//priority_queue<ll,vector<ll>,greater<ll>> a;
//int find(ll x, ll y) {
//	if(y % x) return -1;
//	ll a = y / x;
//	a = log2(a);
//	return a;
//}
//int main() {
//	ios::sync_with_stdio(0);
//	int n; cin >> n;
//	for (int i = 0; i < n; i++) {
//		ll x;cin >> x;
//		a.push(x);
//	}
//	ll ans = 0;
//	while (a.size() > 1) {
//		ll a1 = a.top();
//		a.pop();
//		ll a2 = a.top();
//		a.pop();
//		int res = find(a1, a2);
//		if (res != -1) {
//			a.push(a2 * 2);
//			ans += res;
//		}
//		else {
//			cout << -1 << "\n";
//			return 0;
//		}
//	}
//	cout << ans << "\n";
//	return 0;
//}

/*J. Buying a TV Set*/
//ll gcd(ll a, ll b) {
//	return b ? gcd(b, a % b) : a;
//}
//
//int main() {
//	ll a, b, x, y;
//	cin >> a >> b >> x >> y;
//	ll n = gcd(x, y);
//	//cout << n << "\n";
//	ll a1 = x / n;
//	ll b1 = y / n;
//	ll cnt = min(a / a1, b / b1);
//	cout << cnt << "\n";
//	return 0;
//}

/*H. Theater Square*/
////奇数+1
////喷泉位置 长度 x2 - x1 宽 y2 - y1
//
//int main() {
//	ll n, m; cin >> n >> m;
//	ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
//	ll cang = x2 - x1 + 1;
//	ll kuan = y2 - y1 + 1;
//	ll ans = 0;
//	if (m & 1) ans += (n - cang);
//	ll rkuan = m - y2;
//	ll lkuan = y1 - 1;
//	if (rkuan & 1) ans += cang;
//	if (lkuan & 1) ans += cang;
//	if (ans & 1) ans++;
//	ans /= 2;
//	cout << ans << "\n";
//	return 0;
//}

/*D. Masquerade strikes back*/
////一个数的因子
//const int N = 2e5 + 10;
//struct {
//	int x, pos;
//}node[N];
//
////vector<PII> ans[N];
//queue<PII> q[N];
//map<int, int> g1;
//map<int, int> g2;
//int main() {
//	ios::sync_with_stdio(0);
//	cout.tie(0);cin.tie(0);
//	int n;cin >> n;
//	for (int i = 0; i < n; i++) {
//		int x; cin >> x;
//		node[i].x = x;
//		g1[x]++;
//		g2[x] = i;
//		node[i].pos = i;
//	}
//	for (auto t : g1) {
//		int x = t.first;
//		int cnt = t.second;
//		for (int i = 1; i <= x / i; i++) {
//			if (i * i == x) {
//				cnt--;
//				q[g2[x]].push({ i,i });
//			}
//			else if (x % i == 0) {
//				cnt -= 2;
//				q[g2[x]].push({ i, x / i });
//				q[g2[x]].push({ x / i, i });
//			}
//			if (cnt <= 0)break;
//		}
//		if (cnt > 0) {
//			cout << "NO\n";
//			return 0;
//		}
//	}
//	cout << "YES\n";
//	for (int i = 0; i < n; i++) {
//		int x = node[i].x;
//		int pos = g2[x];
//		auto t = q[pos].front();
//		q[pos].pop();
//		cout << t.first << " " << t.second << "\n";
//	}
//
//	return 0;
//}

/*F. Tickets*/
//int main() {
//	ll sum = 0;
//	for (int i = 1; i <= 234; i++) {
//		sum += (219 - 1) * 2;
//	}
//	ll cnt = 0;
//	for (int i = 1; i <= 218; i++) {
//		sum += 436 - cnt;
//		cnt++;
//	}
//	cout << sum << "\n";
//	
//	return 0;
//}


//#define ll long long
//#define PII pair<int,int>
//const int N = 1e4 + 10;
//ll b[N];
//void init() {
//	b[0] = 1;
//	for (int i = 1; i <= 10; i++) {
//		b[i] = b[i-1] * 3;
//	}
//}
//ll n;
//ll ans;
//bool st[N];
//void dfs(int x,int sum) {
//	if (x > 10) return;
//	for (int i = 0; i <= 10; i++) {
//		if (st[i]) continue;
//		sum += b[i];
//		if (sum >= n) {
//			ans = sum;
//			return;
//		}
//		st[i] = 1;
//		dfs(x + 1, sum);
//		sum -= b[i];
//		st[i] = 0;
//	}
//}
//int main() {
//	init();
//	int q;cin >> q;
//	while (q--) {
//		memset(st, 0, sizeof st);
//		cin >> n;
//		dfs(0, 0);
//		cout << ans << "\n";
//	}
//
//	return 0;
//}
