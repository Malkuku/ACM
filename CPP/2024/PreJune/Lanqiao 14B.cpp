#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*日期统计*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//string s = "2023";
//vector<string> ans;
//char arr[110];
//bool st[110];
//int arr1[] = { 1,3,5,7,8,10,12 };
//int arr2[] = { 4,6,9,11 };
//string tmp = "00000000";
//bool check(string x) {
//	int shu = stoi(x);
//	int d = shu % 100;
//	int y = shu / 100 % 100;
//	if (y > 12 || y < 1 || d < 1) return 0;
//	for (int i : arr1) {
//		if (y == i && d > 31) return 0;
//	}
//	for (int i : arr2) {
//		if (y == i && d > 30) return 0;
//	}
//	if (y == 2 && d > 28) return 0;
//	return 1;
//}
//void dfs(int x,int start) {
//	if (x >= 8) {
//		if (check(tmp)) {
//			ans.push_back(tmp);
//		}
//		return;
//	}
//	for (int i = start; i < 100; i++) {
//		if (x < 4 && arr[i] != s[x]) continue;
//		tmp[x] = arr[i];
//		dfs(x + 1, i + 1);
//	}
//}
//int main() {
//	for (int i = 0; i < 100; i++) {
//		cin >> arr[i];
//	}
//	dfs(0, 0);
//	sort(ans.begin(), ans.end());
//	ans.erase(unique(ans.begin(), ans.end()), ans.end());
//	for (auto t : ans) {
//		cout << t << "\n";
//	}
//	cout << ans.size() << "\n";
//}

/*01串的熵*/ //UF
//int main() {
//	double ans = 11625907.5798;
//	int len = 23333333;
//	for (int i = 100000; i <= len / 2; i++) {
//		int cnt1 = len - i;
//		double bi0 = i / len;
//		double bi1 = cnt1 / len;
//		double h = bi0 * log2(bi0) * i + bi1 * log2(bi1) * cnt1;
//		h = -h;
//		cout << h << " ";
//		if (h == ans) break;
//	}
//	return 0;
//}

/*冶炼金属*/ //二分答案
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 1e4 + 10;
//ll a[N], b[N];
//ll n;
//bool find1(ll x) { //找小值
//	for (int i = 0; i < n; i++) {
//		if (a[i] / x > b[i]) return 1; //x偏小
//	}
//	return 0;
//}
//bool find2(ll x) { //找大值
//	for (int i = 0; i < n; i++) {
//		if (a[i] / x < b[i]) return 1; //x偏大
//	}
//	return 0;
//}
//int main() {
//	cin >> n;
//	ll maxv = 0;
//	ll minv = 1e9 + 10;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i] >> b[i];
//	}
//	ll l = 0;
//	ll r = 1e9 + 10;
//	while (l <= r) {
//		ll mid = (l + r) >> 1;
//		if (find1(mid)) l = mid + 1;
//		else r = mid - 1;
//	}
//	minv = l;
//	l = 0;
//	r = 1e9 + 10;
//	while (l <= r) {
//		ll mid = (l + r) >> 1;
//		if (find2(mid)) r = mid - 1;
//		else l = mid + 1;
//	}
//	maxv = r;
//	cout << minv << " " << maxv << "\n";
//
//	return 0;
//}

/*飞机降落*/ //UF
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 1e5 + 10;
//struct {
//	int T, D, L;
//}node[N];
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		int n;cin >> n;
//		for (int i = 1; i <= n; i++) {
//			int x, y, z;cin >> x >> y >> z;
//			node[i].D = x;
//			node[i].L = y;
//			node[i].T = z;
//		}
//	}
//	return 0;
//}