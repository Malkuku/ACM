#define _CRT_SECURE_NO_WARNINGS 1

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll unsigned long long
#define PII pair<int,int>

/*A - Zero Sum Game*/
//
//int main() {
//	int n; int a[110];
//	cin >> n;
//	int sum = 0;
//	for (int i = 0; i < n - 1; i++) {
//		cin >> a[i];
//		sum += a[i];
//	}
//	cout << 0 - sum << "\n";
//	return 0;
//}


/*B*/
/*
int cnt[30];
int main() {
	string s;
	cin >> s;
	map<int, int> ans;
	for (int i = 0; i < s.size(); i++) cnt[s[i] - 'a']++;
	for (int i = 'a'; i <= 'z'; i++) {
		if(cnt[i-'a'] != 0)
		    ans[cnt[i - 'a']]++;
	}
	bool flag = 1;
	for (auto k : ans) {
		if (k.second != 0 && k.second != 2) {
			flag = 0;
			break;
		}
	}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
}
*/


//C
/*
int main() {
	string s, S;
	cin >> s >> S;
	int pos = 0, num = 0;
	for (int i = 0;i < S.size();i++) {
		while (pos < s.size()) {
			if (s[pos] - 32 == S[i]) {
				num++;
				pos++;
				break;
			}
			pos++;
		}
		if (pos == s.size()) break;
	}
	if (num == 3) {
		cout << "Yes" << endl;
	}
	else if (num == 2) {
		if (S[2] == 'X') {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
*/


//D
//ll p[80];
//vector<pair<ll, ll>> ans;
//	
//int main() {
//	ll l, r;
//	cin >> l >> r;
//	p[0] = 1;
//	for (int i = 1; i <= 64; i++) p[i] = p[i - 1] * 2;
//	while (l < r) {
//      for (int i = 63; i >= 0; i--) {
//		if ((l % p[i] == 0 && l + p[i] <= r)) {
//			ans.push_back({ l,l + p[i] });
//			l = l + p[i];
//			break;
//		}
//	}
//	}
//	
//	cout << ans.size() << endl;
//	for (auto k : ans) cout << k.first << " " << k.second << endl;
//	return 0;
//}