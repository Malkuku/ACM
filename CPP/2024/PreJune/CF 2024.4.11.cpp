//
//#include <bits/stdc++.h>
//#include <unordered_map>
//#define endl '\n'
//
//using namespace std;
//using ll = long long;
//
//bool isCan(string s, int n) {
//	int l = 0, r = n - 1;
//	while (l < r) {
//		if (s[l] != s[r]) {
//			return false;
//		}
//		l++;
//		r--;
//	}
//	return true;
//}
//
//void solve() {
//	int n, k;
//	cin >> n >> k;
//	string s;
//	cin >> s;
//	if (k == 0) {
//		cout << s << endl;
//		return;
//	}
//	vector<bool>is(1e6+10);
//
//	for (int i = 0;i < k;i++) {
//		is[i] = isCan(s, s.size());
//		if (is[s.size()-1]) {
//			char word = s[0];
//			bool can = true;
//			for (int i = 0;i < s.size();i++) {
//				if (s[i] != word) {
//					can = false;
//					break;
//				}
//			}
//			if (can) {
//				for (int j = 0;j < k - i;j++) {
//					s += s[0];
//				}
//				cout << s << endl;
//				return;
//			}
//			else {
//				s += s[s.size() - 1];
//			}
//		}
//		else {
//			s.erase(s.begin() + s.size() / 2, s.end());
//		}
//	}
//	cout << s << endl;
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
//	int t;
//	cin >> t;
//	while (t--)
//		solve();
//
//	return 0;
//}