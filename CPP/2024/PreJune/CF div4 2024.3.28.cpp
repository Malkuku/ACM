#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define PII pair<int,int>

/*A. Stair, Peak, or Neither?*/
//int main() {
//	int t;cin >> t;
//	while (t--) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		if (a < b && b < c) {
//			cout << "STAIR\n";
//		}
//		else if (a < b && b > c) {
//			cout << "PEAK\n";
//		}
//		else cout << "NONE\n";
//	}
//	return 0;
//}

/*B. Upscaling*/
//int main() {
//	string s1 = "##..";
//	string s2 = "..##";
//	int t;cin >> t;
//	while (t--) {
//		int n;cin >> n;
//		int cnt2 = 0;
//		for (int i = 1; i <= n*2; i++) {
//			cnt2++;
//			int cnt1 = 0;
//			for (int j = 1; j <= n * 2; j++) {
//				if (cnt2 % 4 == 0 || cnt2 % 4 == 3) {
//					cout << s2[cnt1 % 4];
//				}
//				else cout << s1[cnt1 % 4];
//				cnt1++;
//			}cout << "\n";
//		}
//	}
//	return 0;
//}

/*C. Clock Conversion*/
//int main() {
//	int t;cin >> t;
//	while (t--) {
//		string st;
//		cin >> st;
//		int h = (st[0]-'0') * 10 + (st[1] -  '0');
//		int m = (st[3] - '0') * 10 + (st[4] - '0');
//		string s2;
//		if (h > 12) {
//			h %= 12;
//			s2 += "PM";
//		}
//		else if (h == 12) s2 += "PM";
//		else if (h == 0) {
//			h = 12;
//			s2 += "AM";
//		}
//		else s2 += "AM";
//		st[0] = (h / 10) + '0';
//		st[1] = (h % 10) + '0';
//		cout << st << " " << s2 << "\n";
//	}
//	return 0;
//}

/*D. Product of Binary Decimals*/
//int a[] = { 10,11,100,101,110,111,1000,1100,1010,1001,1110,
//1101,1011,1111,10000,11000,10100,10010,10001,11001,
//11100,11010,10110,10101,10011,
//11110,11101,11011,10111,11111,100000 };
//int len = 31;
//map<int, bool> g;
//void dfs(int x) {
//	for (int i = 0; i < len; i++) {
//		x *= a[i];
//		if (x > 1e5) return;
//		g[x] = 1;
//		dfs(x);
//		x /= a[i];
//	}
//}
//int main() {
//	int t;cin >> t;
//	dfs(1);
//	g[1] = 1;
//	while (t--) {
//		int n;cin >> n;
//		if (g[n]) cout << "YES\n";
//		else cout << "NO\n";
//	}
//	return 0;
//}