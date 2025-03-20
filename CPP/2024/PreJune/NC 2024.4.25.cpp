#define _CRT_SECURE_NO_WARNINGS 1

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define PII pair<int,int>

/*D	BingbongµÄÆæÅ¼ÊÀ½ç*/
//const int N = 2e5 + 10;
//ll dp[N];
//ll sum[N];
//const int mod = 1e9 + 7;
//int main() {
//	ios::sync_with_stdio(0);
//	int n;cin >> n;
//	string s; cin >> s;
//	dp[n - 1] = s[n - 1] & 1 ? 0 : 1;
//	sum[n - 1] = dp[n - 1];
//	for (int i = n - 2; i >= 0; i--) {
//		if (s[i] - '0' & 1) {
//			dp[i] = sum[i + 1];
//		}
//		else {
//			dp[i] = sum[i + 1] + 1;
//		}
//		sum[i] = sum[i + 1] + dp[i];
//		dp[i] %= mod;
//		sum[i] %= mod;
//		//cout << dp[i] << " " << sum[i] << "\n";
//	}
//	ll ans = 0;
//	for (int i = 0; i < n; i++) {
//		if (s[i] - '0')ans += dp[i];
//		else ans += 1;
//		//cout << dp[i] << "\n";
//		ans %= mod;
//	}
//	cout << ans << "\n";
//
//	return 0;
//}