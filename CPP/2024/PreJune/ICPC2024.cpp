#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*武汉 F*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//int n, k;
//int check(int mid){
//	int ans = 0;
//	int x = n, y = 1;
//	while (x >= 1 && y <= n) {
//		cout << "? " << x << " " << y << " " << mid << endl;
//		bool isr; cin >> isr;
//		if (isr) {
//			ans += x;
//			y++;
//		}
//		else x--;
//	}
//	return ans;
//}
//int main() {
//	cin >> n >> k;
//	k = n * n - k + 1;
//	int l = 1, r = n * n;
//	while (l <= r) {
//		int mid = (l + r) >> 1;
//		if (check(mid) >= k) r = mid-1;
//		else l = mid+1;
//	}
//	
//	cout << "! " << l << endl;
//	return 0;
//}

/*湖北 L. LCMs*/
//从两个质数考虑，到这两个质数作为因子的情况
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//ll gcd(ll a, ll b) {
//	return b ? gcd(b, a % b) : a;
//}
//ll lcm(ll a, ll b) {
//	return a * b / gcd(a, b);
//}
//ll check(ll x) {
//	for (int i = 2; i <= x / i; i++) {
//		if (x % i == 0) return i;
//	}
//	return x;
//}
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		ll a, b;
//		cin >> a >> b;
//		ll ans = lcm(a, b);
//		ll fa = check(a);
//		ll fb = check(b);
//		ans = min(ans, lcm(a, 2) + lcm(b, 2));
//		ans = min(ans, lcm(b, fa) + a);
//		ans = min(ans, lcm(a, fb) + b);
//		ans = min(ans, b + a + lcm(fa, fb));
//		ans = min(ans, a + lcm(fa, 2) + lcm(b, 2));
//		ans = min(ans, b + lcm(fb, 2) + lcm(a, 2));
//		ans = min(ans, lcm(fa, 2) + lcm(fb, 2) + a + b);
//		if (gcd(a, b) != 1) ans = min(ans,a + b);
//		if (a == b) ans = 0;
//		cout << ans << "\n";
//	}
//	return 0;
//}

/*湖北 B. Nana Likes Polygons*/
/*2024.5.13*/ //特判放在读取前面了！！！
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//double a[110], b[110];
//bool check(int i,int j,int k) {
//	double k1 = (b[i] - b[j]) / (a[i] - a[j]);
//	double k2 = (b[i] - b[k]) / (a[i] - a[k]);
//	if (abs(k1 - k2) <= 1e-6) return 0;
//	return 1;
//}
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		int n;cin >> n;
//		for (int i = 1; i <= n; i++) {
//			cin >> a[i] >> b[i];
//		}
//		if (n < 3) {
//			cout << -1 << "\n";
//			continue;
//		}
//		double ans = -1;
//		for (int i = 1; i <= n; i++) {
//			for (int j = i + 1; j <= n; j++) {
//				for (int k = j + 1; k <= n; k++) {
//					if (check(i, j, k)) {
//						double aa = sqrt(abs(a[i] - a[j])* abs(a[i] - a[j]) + abs(b[i] - b[j])* abs(b[i] - b[j]));
//						double bb = sqrt(abs(a[i] - a[k])* abs(a[i] - a[k]) + abs(b[i] - b[k])* abs(b[i] - b[k]));
//						double cc = sqrt(abs(a[j] - a[k])* abs(a[j] - a[k]) + abs(b[j] - b[k])* abs(b[j] - b[k]));
//						double p = (aa + bb + cc) / 2;
//						double s = sqrt(p * abs(p - aa) * abs(p - bb) * abs(p - cc));
//						if (ans == -1)ans = s;
//						else ans = min(ans, s);
//					}
//				}
//			}
//		}
//		cout << fixed << setprecision(8) << ans << "\n";
//	}
//	return 0;
//}

/*江苏 I. Integer Reaction*/
/*2024.5.13*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 1e5 + 10;
//PII a[N];
//int n;
//int check2(int x,vector<PII>& arr) {
//	int l = 0, r = arr.size()-1;
//	while (l <= r) {
//		int mid = (l + r) >> 1;
//		if (arr[mid].first < x) l = mid + 1;
//		else r = mid - 1;
//	}
//	return l;
//}
//void insert(PII& a, vector<PII>& arr) {
//	
//}
//
//bool check(int x) {
//	vector<PII> arr;
//	for (int i = 0; i < n; i++) {
//		if (arr.size() == 0) insert(a[i],arr);
//		else if (arr[0].second + a[i].second == 1) {
//			int pos = check2(x - a[i].first, arr);
//			if (pos == -1) return 0;
//			//cout << pos << "\n";
//			arr.erase(arr.begin()+pos,arr.begin()+pos+1);
//		}
//		else insert(a[i],arr);
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int x;cin >> x;
//		a[i].first = x;
//	}
//	for (int i = 0; i < n; i++) {
//		int x; cin >> x;
//		a[i].second = x;
//	}
//	int l = 1, r = 2e8;
//	while (l <= r) {
//		int mid = (l + r) >> 1;
//		if (check(mid)) l = mid + 1;
//		else r = mid - 1;
//	}
//	cout << r << "\n";
//	return 0;
//}