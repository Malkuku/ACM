#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<queue>
#include<cstring>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*A. Cipher Shifer*/
//#include<iostream>
//#include<string>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//
//int t;
//int main() {
//	cin >> t;
//	while (t--) {
//		int n;cin >> n;
//		string s;cin >> s;
//		string a;
//		char ch = s[0];
//		int cnt = 1;
//		a += s[0];
//		for (int i = 1; i < n; i++) {
//			if (cnt >= 2) {
//				ch = s[i];
//				cnt = 1;
//				a += s[i];
//			}
//			else if (ch == s[i]) {
//				cnt++;
//			}
//		}
//		cout << a << "\n";
//	}
//	return 0;
//}

/*B. Binary Cafe*/ //��������\����dp? 
/*2024.2.27 WA*/ //�������ڿ��ܳ����ظ�������
//int k, n; //0 -> 1coins
//const int N = 1e3+10;
//ll arr[N];
//void so1() {
//	for (int i = 0; i <= 30; i++) {
//		arr[i] = pow(2, i);
//	}
//}
//ll so2(ll x) {
//	//��������� 1,2,3, 1,2 1,3 2,3 1 2 3 ->4
//	//1,2 1 2
//	//1
//	ll ans = pow(2,x-1);
//	return ans;
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	so1();
//	while (t--) {
//		cin >> n >> k;
//		ll sum = 0;
//		ll res = 0;
//		k = min(31, k);
//		for (int i = k-1; i >= 0; i--) {
//			sum = arr[i];
//			if (sum > n) continue;
//			ll cnt = 1;
//			int r = 0, l = 0;
//			while (r >= l && r < i) {
//				if (sum > n) {
//					while (sum > n && r >= l) {
//						cnt--;
//						sum -= arr[l];
//						l++;
//					}
//					res += so2(cnt);
//				}
//				else {
//					sum += arr[r];
//					cnt++;
//					r++;
//				}
//			}
//			res += so2(cnt);
//		}
//		cout << res+1 << "\n";
//	}
//	return 0;
//}
/*2024.2.27 ������ö��*/ //�������ᳬʱ
//#include<string>
//#include<queue>
//#include<cstring>
//#include<map>
//#include<vector>
//#include<cmath>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//int t, k, n;
//const int N = 1e2 + 10;
//int arr[N];
//void so1() {
//	for (int i = 0; i < 31; i++) {
//		arr[i] = pow(2, i);
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	so1();
//	cin >> t;
//	while (t--) {
//		cin >> n >> k;
//		k = min(k, 30);
//		int pos = 0;
//		for (int i = 0; i < k; i++) {
//			if (arr[i] > n) break;
//			pos++;
//		}
//		int cnt = 0;
//		for (int i = 0; i < (1 << pos); i++) {
//			int sum = 0;
//			for (int j = 0; j < pos; j++) {
//				if (i & (1 << j)) {
//					sum += arr[j];
//				}
//			}
//			if (sum <= n) cnt++;
//		}
//		cout << cnt << "\n";
//	}
//	return 0;
//}
/*2024.2.27 ˼ά*/ //�����Ƽ۸��������
////�۸���˶����Ƶ�ʱ��,��Ӧ��˼��Ϊʲô��ô��
////����ÿһ���۸�n,����һ��Ψһ�ķ�����֮��Ӧ
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//signed main() {
//    int q;
//    cin >> q;
//    while (q--) {
//        ll n, k;
//        cin >> n >> k;
//        if (k > 31) cout << n + 1 << "\n";
//        else cout << min((ll)pow(2, k), n + 1) << "\n";
//    }
//    return 0;
//}

/*C. Ski Resort*/
//#include<iostream>
//#include<string>
//#include<queue>
//#include<cstring>
//#include<map>
//#include<vector>
//#include<cmath>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//// <= q
////k
//int k, n, q;
//const int N = 2e5 + 10;
//int a[N];
//int dp[N]; //��i���ۼ�dp[i]�ļ���
//ll so1(int x) {
//	ll ans = 0;
//	for (int i = k; i <= x; i++) {
//		ans += x - i + 1;
//	}
//	//int y = k - 1;
//	//ll cnt = 1;
//	//while (y) {
//	//	cnt *= y;
//	//	y--;
//	//}
//	return ans;
//}
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		cin >> n >> k >> q;
//		memset(dp, 0, sizeof dp);
//		for (int i = 0; i < n; i++) {
//			cin >> a[i];
//		}
//		dp[0] = a[0] > q ? 0 : 1;
//		ll ans = 0;
//		for (int i = 1; i < n; i++) {
//			if (a[i] <= q) dp[i] = dp[i - 1] + 1;
//			else {
//				dp[i] = 0;
//				ans += so1(dp[i-1]);
//			}
//		}
//		ans += so1(dp[n - 1]);
//		cout << ans << "\n";
//	}
//	return 0;
//}