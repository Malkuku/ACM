#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;

/* #QED2403B. 运算表达式 */ //不要用奇怪的取余方式
//#include<bits/stdc++.h>
//using namespace std;
//stack<string> st;
//const int mod = 998244353;
//#define ll long long
//ll change(string& s) {
//	ll ans = 0;
//	for (int i = 0; i < s.size(); i++) {
//		ans *= 10;
//		ans += s[i] - '0';
//		ans %= mod;
//	}
//	return ans;
//}
//int main() {
//	string s;
//	int n;
//	cin >> n >> s;
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] <= '9' && s[i] >= '0') {
//			string ss;
//			while (s[i] <= '9' && s[i] >= '0') {
//				ss += s[i];
//				i++;
//			}
//			i--;
//			st.push(ss);
//		}
//		else {
//			string ss;
//			ss += s[i];
//			st.push(ss);
//		}
//		if (s[i] == ')') {
//			string t = st.top();
//			st.pop();
//			ll sum = 0;
//			while (t != "(") {
//				t = st.top();
//				st.pop();
//				if (t != "@" && t != "(") {
//					sum += change(t) % mod;
//				}
//			}
//			sum %= mod;
//			st.push(to_string(sum));
//		}
//		else if (s[i] == ']') {
//			string t = st.top();
//			st.pop();
//			ll sum = 1;
//			while (t != "[") {
//				t = st.top();
//				st.pop();
//				if (t != "@" && t != "[") {
//					sum = (sum % mod) * (change(t) % mod);
//					sum %= mod;
//				}
//			}
//			sum %= mod;
//			st.push(to_string(sum));
//		}
//	}
//	string t = st.top();
//	ll ans = change(t);
//	ans %= mod;
//	cout << ans << "\n";
//	return 0;
//}