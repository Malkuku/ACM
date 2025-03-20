#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long
/*K. Puzzle*/
//int a[10];
//map<int,bool> g;
//map<int, string> g2;
//vector<int> ans = { ':','1','2','3','4','5','6','7',':' };
//bool st[100000];
//void dfs(int x) {
//	if (x == 8) {
//		stack<int>q;
//		for (int i = 1; i <= 7; i++) {
//			if (ans[i] == '*'+1000000) {
//				int ch1 = q.top();
//				q.pop();
//				int b = (ch1 - '0') * (ans[i + 1] - '0');
//				q.push(b + '0');
//				i++;
//			}
//			/*else if (ans[i] == '/'+1000000) {
//				int ch1 = q.top();
//				q.pop();
//				int b = (ch1 - '0') / (ans[i + 1] - '0');
//				q.push(b + '0');
//				i++;
//			}*/
//			else q.push(ans[i]);
//		}
//		
//		stack<int> qq;
//		while (q.size()) {
//			int t = q.top();
//			q.pop();
//			qq.push(t);
//		}
//		int anss = qq.top() - '0';
//		qq.pop();
//		while (qq.size()) {
//			int ch1 = qq.top();qq.pop();
//			int ch2 = qq.top();qq.pop();
//			if (ch1 == '-'+1000000) {
//				anss -= (ch2 - '0');
//			}
//			else if (ch1 == '+'+1000000) {
//				anss += ch2 - '0';
//			}
//		}
//		g[anss] = 1;
//		//g2[anss] = ans;
//		return;
//	}
//	if (x & 1) {
//		for (int i = 1; i <= 7; i += 2) {
//			if (st[i]) continue;
//			ans[x] = a[i];
//			st[i] = 1;
//			dfs(x + 1);
//			st[i] = 0;
//		}
//	}
//	else {
//		ans[x] = '+'+1000000;
//		dfs(x + 1);
//		ans[x] = '-'+1000000;
//		dfs(x + 1);
//		//ans[x] = '/'+1000000;
//		//dfs(x + 1);
//		ans[x] = '*'+1000000;
//		dfs(x + 1);
//	}
//	
//}
//int main() {
//	ios::sync_with_stdio(0);
//	for (int i = 1; i <= 7; i += 2) cin >> a[i], a[i] += '0';
//	for (int i = 2; i <= 7; i += 2) a[i] = '?';
//	dfs(1);
//	cout << g.size() << "\n";
//	//for (auto t : g2) {
//	//	cout << t.second << " " << t.first << "\n";
//	//}
//	return 0;
//}