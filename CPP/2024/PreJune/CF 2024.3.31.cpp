#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*A. Planets*/
//const int N = 110;
//
//int main() {
//	int t; cin >> t;
//	while (t--) {
//		map<int, int> g;
//		int n, c;cin >> n >> c;
//		for (int i = 0; i < n; i++) {
//			int x; cin >> x;
//			g[x]++;
//		}
//		//一个一个清花费小于c
//		int ans = 0;
//		for (auto t : g) {
//			if (t.second < c) {
//				ans += t.second;
//			}
//			else ans += c;
//		}
//		cout << ans << "\n";
//	}
//	return 0;
//}

/*B. Meeting on the Line*/
//const int N = 1e5 + 10;
//ll x[N];
//ll tim[N];
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//
//	while (t--) {
//		int n; cin >> n;
//		ll sum1 = 0, sum2 = 0;
//		for (int i = 1; i <= n; i++) {
//			cin >> x[i];
//			sum1 += x[i];
//		}
//		for (int i = 1; i <= n; i++) {
//			cin >> tim[i];
//			sum1 += tim[i];
//		}
//		sort(x + 1, x + 1 + n);
//		int l = 1, r = n;
//		ll cha = sum1;
//		double ans = x[0];
//		for (int i = 1; i < n; i++) {
//			sum2 += x[i];
//			sum1 -= x[i];
//			if (cha > abs(sum1 - sum2)) {
//				cha = abs(sum1 - sum2);
//				if (cha == 0) ans = x[i];
//				else ans = (x[i] + x[i + 1]) / 2.0;
//			}
//		}
//		cout << ans << "\n";
//	}
//	return 0;
//}
/*2024.4.1 思维做法（存疑）*/ 
//const int N = 2e5 + 10;
//int fs[N],es[N];
//PII a[N];
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		int n;cin >> n;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i].first;
//			a[i].first *= 2;
//		}
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i].second;
//			a[i].second *= 2;
//		}
//		if (n == 1) {
//			cout << a[1].first / 2 << '\n';
//			continue;
//		}
//		sort(a + 1, a + 1 + n);
//		fs[0] = -1e9;
//		es[n + 1] = -1e9;
//		for (int i = 1; i <= n; i++) {
//			fs[i] = max(fs[i-1], a[i].second - a[i].first);
//		}
//		for (int i = n; i >= 1; i--) {
//			es[i] = max(es[i+1], a[i].first + a[i].second);
//		}
//		int ans = 1e9;
//		int pos;
//		for (int i = 1; i < n; i++) {
//			int mx1 = fs[i], mx2 = es[i + 1];
//			int t = (mx2 - mx1) / 2;
//			t = max(a[i].first, t);
//			t = min(a[i + 1].first, t);
//			if (max(mx1 + t, mx2 - t) < ans) {
//				ans = max(mx1 + t, mx2 - t);
//				pos = t;
//			}
//		}
//		cout << 1.0 * pos / 2 << "\n";
//	}
//	return 0;
//}
/*2024.4.1 浮点数二分*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 2e5 + 10;
//const int inf = 0x3f3f3f3f;
//int n; double ans;
//int a[N], tim[N];
//
////二分时间mid ,a[i]为人原来的位置，mid > t[i], t[i] - mid 表示还能向左边走的距离
//			// mid - t[i] > 0 ，表示还能向右走的距离, 
////mid足够大时，最小的右端点才可能比最大的左端点大
//bool check(double mid) {
//	double l = -2e18, r = 2e18;
//	for (int i = 1; i <= n; i++) {
//		if (mid < tim[i]) return 0; //已经小于装扮时间，mid偏小
//		else {
//			l = max(l, a[i] + tim[i] - mid); //在mid时间下能走到的最大左端点
//			r = min(r, a[i] + mid - tim[i]); //在mid 走到的最小右端点
//		}
//	}
//	ans = l;  //二分到最后ans就是满足 r>=l-1e8 的交点处，此时的时间就是最小值
//	return r >= l - 1e-8; //满足则说明有交集 1e-8可以不要？？？！
//	//return r >= l;
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		cin >> n;
//		for (int i = 1; i <= n; i++) cin >> a[i];
//		for (int i = 1; i <= n; i++) cin >> tim[i];
//
//		double l = 0, r = 2e18;
//		while (r - l > 1e-6) {
//			double mid = (l + r) / 2;
//			if (check(mid)) r = mid;
//			else l = mid;
//		}
//		cout << fixed << setprecision(8) << ans << "\n";
//	}
//	return 0;
//}
/*2024.4.1 最结论的一集*/
////右边最大 xi - x + ti
////左边最小 x - xj + tj
////最佳情况是 右边最大花费时间 == 左边最小花费时间
////化简得 x = (tj - xj + xi + ti) / 2
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 2e5 + 10;
//double a[N], s[N];
//
//int main() {
//	ios::sync_with_stdio(0);
//	int t; cin >> t;
//	while (t--) {
//		int n;cin >> n;
//		for (int i = 0; i < n; i++) {
//			cin >> a[i];
//		}
//		for (int i = 0; i < n; i++) {
//			cin >> s[i];
//		}
//		double minn = 1e18, maxn = -1e18;
//		for (int i = 0; i < n; i++) {
//			minn = min(minn, a[i] - s[i]);
//			maxn = max(maxn, s[i] + a[i]);
//		}
//		cout << fixed << setprecision(8) << (minn + maxn) / 2 << "\n";
//	}
//	return 0;
//}

/*C. Minimum Notation*/
//const int N = 2e5 + 10;
//vector<int> q1;
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		queue<int> q[10];
//		string s;
//		cin >> s;
//		string tmp = s;
//		sort(tmp.begin(), tmp.end());
//		q1.clear();
//		q1.reserve(s.size());
//		int cnt = 0;
//		string ans;
//		int res = 0;
//		for (int i = 0; i < tmp.size(); i++) {
//			q[tmp[i] - '0'].push(i);
//		}
//		for (int i = 0; i < s.size(); i++) {
//			while (tmp[cnt] == '?') cnt++;
//			if (s[i] == tmp[cnt]) {
//				ans += s[i];
//				cnt++;
//			}
//			else {
//				q1.push_back(s[i] - '0');
//				int pos = q[s[i] - '0'].front();
//				q[s[i] - '0'].pop();
//				tmp[pos] = '?';
//			}
//		}
//		sort(q1.begin(), q1.end());
//		for (int i = 0; i < q1.size(); i++) {
//			int co = min(q1[i] + 1, 9);
//			ans += co + '0';
//		}
//		sort(ans.begin(), ans.end());
//		cout << ans << "\n";
//	}
//	return 0;
//}

/*E. Bright, Nice, Brilliant*/
//int main() {
//	int t;cin >> t;
//	while (t--) {
//		int n; cin >> n;
//		int cnt = -1;
//		for (int i = 1; i <= n; i++) {
//			if (i == 1) cout << 1 << "\n";
//			else {
//				cout << 1 << " ";
//				for (int i = 1; i <= cnt; i++) {
//					cout << 0 << " ";
//				}
//				cout << 1 << "\n";
//			}
//			cnt++;
//		}
//	}
//	return 0;
//}

/*H. Consecutive Sum*/
////vector<ll> q[110];
//ll a[110];
//int main() {
//	int t;cin >> t;
//	while (t--) {
//		priority_queue<ll> q[110];
//		int n, k; cin >> n >> k;
//		for (int i = 0; i < n; i++) {
//			cin >> a[i];
//		}
//		int cnt = 0;
//		for (int i = 0; i < k; i++) {
//			int step = i;
//			while (step < n) {
//				q[cnt].push(a[step]);
//				step += k;
//			}
//			cnt++;
//		}
//		ll ans = 0;
//		for (int i = 0; i < k; i++) {
//			if(q[i].size())ans += q[i].top();
//		}
//		cout << ans << "\n";
//	}
//}

/*I. Rule of League*/ //三心二意让你变笨了
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		int n, x, y;
//		cin >> n >> x >> y;
//		if (x && y) {
//			cout << -1 << "\n";
//			continue;
//		}
//		if (x == 0 && y == 0) {
//			cout << -1 << "\n";
//			continue;
//		}
//		if (n == 2) {
//			if (x == 1 && y == 0) {
//				cout << 1 << "\n";
//			}
//			else if (x == 0 && y == 1) {
//				cout << 1 << "\n";
//			}
//			else {
//				cout << -1 << "\n";
//			}
//			continue;
//		}
//		if (x == 0) {
//			if ((n-1)%y) {
//				cout << -1 << "\n";
//				continue;
//			}
//			int step = 2;
//			int k = (n - 1) / y;
//			while (k--) {
//				for (int i = 1;i <= y; i++) {
//					cout << step << " ";
//				}
//				step += y;
//			}
//			cout << "\n";
//			continue;
//		}
//		if (y == 0) {
//			if ((n - 1)%x) {
//				cout << -1 << "\n";
//				continue;
//			}
//			int step = 2;
//			int k = (n - 1) / x;
//			while (k--) {
//				for (int i = 1;i <= x; i++) {
//					cout << step << " ";
//				}
//				step += x;
//			}
//			cout << "\n";
//			continue;
//		}
//	}
//	return 0;
//}

/*G. Slime Escape*/ //做题的思路不够清晰
////WA: 用了前缀和，但是没有撇清关系
////WA：对于左右的更新，事实上我们是要将左边能得到的最大增量给到右边，右边也是如此，这样才能保证最大概率能过关
//const int N = 2e5 + 10;
//ll a[N];
//ll s[N];
//
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while(t--){
//		int n, k;cin >> n >> k;
//		for (int i = 1; i <= n;i++) {
//			cin >> a[i];
//		}
//		s[k] = 0;
//		for (int i = k + 1; i <= n; i++) {
//			s[i] = s[i - 1] + a[i];
//		}
//		for (int i = k - 1; i >= 1; i--) {
//			s[i] = s[i + 1] + a[i];
//		}
//		int l = k, r = k;
//		s[0] = 0;
//		s[n + 1] = 0;
//		bool isright = 1;
//		ll tmp1 = 0;
//		ll tmp2 = 0;
//		while (l >= 1 && r <= n) {
//			bool flag1 = 0;
//			bool flag2 = 0;
//			while (l >= 1 && a[k] + tmp2 + s[l - 1] >= 0) {
//				l--;
//				flag1 = 1;
//				if (s[l] > 0) tmp1 = max(s[l],tmp1);
//			}
//			while (r <= n && a[k] + tmp1 + s[r + 1] >= 0) {
//				r++;
//				flag2 = 1;
//				if (s[r] > 0) tmp2 = max(s[r], tmp2);
//			}
//			if (!flag1 && !flag2) {
//				isright = 0;
//				break;
//			}
//		}
//		if (isright)cout << "YES\n";
//		else cout << "NO\n";
//	}
//	return 0;
//}

