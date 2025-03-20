#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define PII pair<int,int>

/*A. Rook*/
//string dx = "087654321";
//string dy = "0abcdefgh";
//
//int main() {
//	int t;cin >> t;
//	while (t--) {
//		string ch;
//		cin >> ch; //ch 0->a 1->'1'
//		//x行
//		for (int i = 1; i < dx.size(); i++) {
//			if (dx[i] == ch[1]) continue;
//			else cout << ch[0] << dx[i] << "\n";
//		}
//		for (int i = 1; i < dy.size(); i++) {
//			if (dy[i] == ch[0]) continue;
//			else cout << dy[i] << ch[1] << "\n";
//		}
//	}
//	return 0;
//}

/*B. YetnotherrokenKeoard*/
//// b删掉最右小写
////B       大写
//int main() {
//	int t;cin >> t;
//	while (t--) {
//		string s;cin >> s;
//		string ans;
//		stack<int> upper;
//		stack<int> lower;
//		int cnt = 0;
//		for (int i = 0; i < s.size(); i++) {
//			if ((s[i] == 'b' || s[i] == 'B')) {
//				ans += "0";
//				if (s[i] == 'b') {
//					if (lower.empty()) continue;
//					int pos = lower.top();
//					lower.pop();
//					ans[pos] = '0';
//				}
//				else if (s[i] == 'B') {
//					if (upper.empty()) continue;
//					int pos = upper.top();
//					upper.pop();
//					ans[pos] = '0';
//				}
//			}
//			else {
//				ans += s[i];
//				if (isupper(s[i])) upper.push(i);
//				else if (islower(s[i])) lower.push(i);
//			}
//		}
//		string anss;
//		for (int i = 0; i < ans.size(); i++) {
//			if (ans[i] == '0') continue;
//			anss += ans[i];
//		}
//		cout << anss << "\n";
//	}
//	return 0;
//}

/*C. Removal of Unattractive Pairs*/
//const int N = 2e5 + 10;
//map<char, int> g;
//int main() {
//	int t;cin >> t;
//	while (t--) {
//		int n;cin >> n;
//		g.clear();
//		for (int i = 0; i < n; i++) {
//			char ch;cin >> ch;
//			g[ch]++;
//		}
//		int maxn = 0;
//		for (auto t : g) {
//			maxn = max(t.second, maxn);
//		}
//		if (maxn * 2 - n > 0) cout <<  maxn*2 - n << "\n";
//		else {
//			if (n & 1) cout << 1 << "\n";
//			else cout << 0 << "\n";
//		}
//	}
//	return 0;
//}

/*D. Jumping Through Segments*/ //不要只考虑一个数，考虑一个区间，区间包含了可能性
//const int N = 2e5 + 10;
//int n;
//struct {
//	ll x, y;
//}node[N];
//bool find(int k) {
//	ll maxst = 0;
//	ll minst = 0;
//	for (int i = 1; i <= n; i++) {
//		maxst += k;
//		minst -= k;
//		ll x1 = node[i].x;
//		ll y1 = node[i].y;
//		ll xx = max(x1, minst);
//		ll yy = min(y1, maxst);
//		if (xx > yy) return 0;
//		maxst = yy;
//		minst = xx;
//	}
//	return 1;
//}
//int main() {
//	ios::sync_with_stdio(0);
//	int t;cin >> t;
//	while (t--) {
//		cin >> n;
//		node[0].x = 0;
//		node[0].y = 0;
//		for (int i = 1; i <= n; i++) {
//			ll x, y;cin >> x >> y;
//			node[i].x = x;
//			node[i].y = y;
//		}
//		int l = 0, r = 1e9 + 10;
//		while (l <= r) {
//			int mid = (l + r) >> 1;
//			if (find(mid) == 0) l = mid + 1;
//			else r = mid - 1;
//		}
//		int ans = l;
//		if (find(r)) ans = min(l, r);
//		cout << ans << "\n";
//	}
//	return 0;
//}

/*E. Good Triples*/
