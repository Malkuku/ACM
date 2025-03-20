#define _CRT_SECURE_NO_WARNINGS 1

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*A. Yes-Yes?*/
//string s = "Yes";
//
//int main() {
//	int t; cin >> t;
//	while (t--) {
//		string a; cin >> a;
//		int i = 0;
//		bool flag = 1;
//		int j = 0;
//		int cnt = 1;
//		while (s[j % 3] != a[0] && cnt <= 3) {
//			j++;
//			cnt++;
//		}
//		if (cnt > 3) {
//			flag = 0;
//		}
//		while (i < a.size()) {
//			if (s[j % 3] != a[i]) {
//				flag = 0;
//				break;
//			}
//			i++;
//			j++;
//		}
//		if (flag) cout << "Yes\n";
//		else cout << "No\n";
//	}
//	return 0;
//}

/*B. Lost Permutation*/
//const int N = 60;
//
//int main() {
//	int t; cin >> t;
//	while (t--) {
//		int b[N];
//		int n, s;
//		cin >> n >> s;
//		for (int i = 0; i < n; i++) {
//			cin >> b[i];
//		}
//		sort(b, b + n);
//		int sum = 0;
//		int cnt = 0;
//		for (int i = 1; i <= 100000; i++) {
//			if (b[cnt] == i && cnt < n) cnt++; //?
//			else sum += i;
//			if (sum >= s && cnt >= n) break;
//		}
//		if (sum == s) cout << "YES\n";
//		else cout << "No\n";
//	}
//	return 0;
//}

/*C. Thermostat*/ //sb
////1.相等 0
////2.差值大于等于 x 1
////3.至少有一个数能动向两边 2
////4.两个数都只能一边,且不是同一边 3
////5.有一个数不能动 -1
//
//int main() {
//	int t; cin >> t;
//	while (t--) {
//		ll l, r, x, a, b;
//		cin >> l >> r >> x >> a >> b;
//		int cnta1 = 0,cnta2 = 0,cntb1 = 0,cntb2 = 0;
//		if (a == b) cout << 0 << "\n";
//		else {
//			if (a + x <= r) cnta1++;
//			if (a - x >= l) cnta2++;
//			if (b + x <= r) cntb1++;
//			if (b - x >= l) cntb2++;
//			int cnta = cnta1 + cnta2;
//			int cntb = cntb1 + cntb2;
//			if (cnta == 0 || cntb == 0) cout << -1 << "\n";
//			else if (abs(a - b) >= x) cout << 1 << "\n";
//			else if (cnta >= 2 || cntb >= 2 || (cnta1 == 1 && cntb1 == 1) || (cnta2 == 1 && cntb2 == 1)) cout << 2 << "\n";
//			else cout << 3 << "\n";
//		}
//	}
//	return 0;
//}

/*D. Make It Round*/ //只取最大的两位 //遍历0-10，取结果
//int main() {
//	int t; cin >> t;
//	while (t--) {
//		ll n, m;
//		cin >> n >> m;
//		ll ans;
//		if (n % 10 == 0) ans = n * m;
//		else if (n & 1) {
//			if (n % 5 == 0) {
//				if (m & 1) ans = n * (m - 1);
//				else ans = n * m;
//			}
//			else ans = n * m;
//		}
//		else {
//			m = m - m % 5;
//			ans = n * m;
//		}
//		cout << ans << "\n";
//		//cout << "\n" << 120600000 / 10050;
//	}
//	return 0;
//}

/*E. The Humanoid*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//
//const int N = 2e5 + 10;
//ll a[N];
//
//int main() {
//	//2 2 3
//	//2 3 2
//	//3 2 2
//	ios::sync_with_stdio(0);
//	int t; cin >> t;
//	while (t--) {
//		ll n, h; cin >> n >> h;
//		for (int i = 0; i < n; i++) {
//			cin >> a[i];
//		}
//		sort(a, a + n);
//		int cnt = 0;
//		ll ans1 = 0;
//		ll tmp = h;
//		for (int i = 0; i < n; i++) {
//			if (tmp > a[i]) {
//				tmp += a[i] >> 1;
//				ans1++;
//			}
//			else {
//				i--;
//				if (cnt == 0) {
//					cnt++;
//					tmp *= 2;
//				}
//				else if (cnt == 1) {
//					cnt++;
//					tmp *= 2;
//				}
//				else if (cnt == 2) {
//					cnt++;
//					tmp *= 3;
//				}
//				else if (cnt == 3) break;
//			}
//		}
//		cnt = 0;
//		ll ans2 = 0;
//		tmp = h;
//		for (int i = 0; i < n; i++) {
//			if (tmp > a[i]) {
//				tmp += a[i] >> 1;
//				ans2++;
//			}
//			else {
//				i--;
//				if (cnt == 0) {
//					cnt++;
//					tmp *= 2;
//				}
//				else if (cnt == 1) {
//					cnt++;
//					tmp *= 3;
//				}
//				else if (cnt == 2) {
//					cnt++;
//					tmp *= 2;
//				}
//				else if (cnt == 3) break;
//			}
//		}
//
//		cnt = 0;
//		ll ans3 = 0;
//		tmp = h;
//		for (int i = 0; i < n; i++) {
//			if (tmp > a[i]) {
//				tmp += a[i] >> 1;
//				ans3++;
//			}
//			else {
//				i--;
//				if (cnt == 0) {
//					cnt++;
//					tmp *= 3;
//				}
//				else if (cnt == 1) {
//					cnt++;
//					tmp *= 2;
//				}
//				else if (cnt == 2) {
//					cnt++;
//					tmp *= 2;
//				}
//				else if (cnt == 3) break;
//			}
//		}
//		ll ans = max(ans1, max(ans2, ans3));
//		//cout << ans1 << " " << ans2 << " " << ans3 << "\n";
//		cout << ans << "\n";
//	}
//	return 0;
//}

