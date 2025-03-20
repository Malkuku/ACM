#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ll long long

/*A 宇宙的终结*/
//#include<bits/stdc++.h>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//int pri[] = { 30,42,66,70,78 };
////首先是个偶数 2 30 42 66 78 70 
//int main() {
//	int l, r;
//	cin >> l >> r;
//	int ans = -1;
//	for (int i = 0; i < 5; i++) {
//		if (pri[i] >= l && pri[i] <= r) ans = pri[i];
//	}
//	cout << ans << "\n";
//	return 0;
//}

/*B 爱恨的纠葛(WA)*/ //枚举二分
/*.WA*/
//#include<bits/stdc++.h>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//const int N = 1e5 + 10;
//int a[N];
//int b[N];
//int ans[N];
//pair<int, int> g[N];
//int n;
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	for (int i = 0; i < n; i++) {
//		cin >> b[i];
//		g[i] = { b[i],i };
//	}
//	sort(a, a + n);
//	sort(g, g + n, [](auto x, auto y) {
//		return x.first < y.first;});
//	int la = 0;int ra = n - 1;
//
//
//	for (int i = 0; i < n; i++)
//		cout << ans[i] << " ";
//	cout << "\n";
//	return 0;
//}
/*2024.3.3 枚举二分*/
////WA: 需要找俩次
//#include<bits/stdc++.h>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//const int N = 1e5 + 10;
//ll a[N];
//ll b[N];
//int n;
//ll pos1 = -1;
//ll pos2 = -1;
//ll cha = 0x3f3f3f3f;
//bool flag = 0;
//int findUp(ll x) {
//	int l = 1, r = n;
//	while (l <= r) {
//		ll mid = (l + r) >> 1;
//		if (x < a[mid]) r = mid - 1;//
//		else if (x > a[mid]) l = mid + 1; ///因为l是+1，所以返回l找的是比它大的位置
//		else return mid;
//	}
//	return l;
//}
//int findLow(ll x) {
//	int l = 1, r = n;
//	while (l <= r) {
//		ll mid = (l + r) >> 1;
//		if (x > a[mid]) l = mid + 1;
//		else if (x < a[mid]) r = mid - 1; //因为r是-1，所以返回r找的是比它小的位置
//		else return mid;
//	}
//	return r;
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> b[i];
//	}
//	sort(a + 1, a + n + 1);
//	for (int i = 1; i <= n; i++) {
//		//枚举每个b，搜索其在a的位置
//		int p = findLow(b[i]);
//		if (abs(a[p] - b[i]) < cha) {
//			cha = abs(a[p] - b[i]);
//			pos1 = i;
//			pos2 = p;
//		}
//		p = findUp(b[i]);
//		if (abs(a[p] - b[i]) < cha) {
//			cha = abs(a[p] - b[i]);
//			pos1 = i;
//			pos2 = p;
//		}
//	}
//	ll tmp = a[pos1];
// 	a[pos1] = a[pos2];
//	a[pos2] = tmp;
//	for (int i = 1; i <= n; i++) {
//		cout << a[i] << " ";
//	}
//	return 0;
//}

/*D 友谊的套路*/ //数学 //好怪哦
//#include<bits/stdc++.h>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//double p;
//int main() {
//	cin >> p;
//	double ans = ((1-p) * (1-p))*(p)*(p);
//	cout << ans << "\n";
//	return 0;
//}

/*E 未来的预言 */
////WA:弱智了，只考虑了一位
//#include<bits/stdc++.h>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//string box;
//string arr;
//int red = 0;
//int prp = 0;
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> box;
//	cin >> arr;
//	box[0] = '0';
//	box[1] = '0';
//	int win = stoi(box);
//	win = win / 2;
//	int cnt = 0;
//	int iswin = 0;//1 red 2 prp
//	for (int i = 0; i < arr.size(); i++) {
//		cnt++;
//		if (arr[i] == 'R') red++;
//		else if (arr[i] == 'P') prp++;
//		if (red > win) {
//			iswin = 1;
//			break;
//		}
//		else if (prp > win) {
//			iswin = 2;
//			break;
//		}
//	}
//	if (iswin == 0) {
//		cout << "to be continued.\n";
//		cout << cnt << "\n";
//	}
//	else if (iswin == 1) {
//		cout << "kou!\n";
//		cout << cnt << "\n";
//	}
//	else if (iswin == 2) {
//		cout << "yukari!\n";
//		cout << cnt << "\n";
//	}
//	return 0;
//}

/*C 心绪的解剖 */
////0，1，1，2，3，5，8，13，21，34，55，89
////1.它是Feb+0+0
////2.它不是Feb
////WA:判断最后能不能组成应该看和等不等于n
//#include<bits/stdc++.h>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//map<int, int> g;
//const int N = 1e5 + 10;
//int Feb[N];
//int cnt = 0;
//int ans[3];
//void feb(int a, int b) {
//	if (cnt > 46) {
//		return;
//	}
//	Feb[cnt] = a;
//	cnt++;
//	feb(b, a + b);
//}
//void search(int x, int n) {
//	if (x > 2 || n < 0) return;
//	for (int i = 46; i >= 0; i--) {
//		if (Feb[i] <= n) {
//			ans[x] = Feb[i];
//			n -= Feb[i];
//			x++;
//			search(x, n);
//			return;
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	feb(0, 1);
//	int q, n;
//	cin >> q;
//	while (q--) {
//		cin >> n;
//		memset(ans, -1, sizeof ans);
//		search(0, n);
//		int sum = 0;
//		for (int i = 0; i < 3; i++) {
//			sum += ans[i];
//		}
//		if (sum != n) {
//			cout << -1 << "\n";
//			continue;
//		}
//		for (int i = 0; i < 3; i++) {
//			cout << ans[i] << " ";
//		}cout << "\n";
//	}
//	return 0;
//}

///*I 时空的交织*/
////像这种有数学公式的题，一定要具体写看
////化简公式可以得到，sum = (a1+...+an)*(b1+...+bm)
////也就是求a,b两个串的子串
////WA：根据a,b的正负情况会产生4种情况
//#include<iostream>
//#include<string>
//using namespace std;
//#define ll long long
//const int N = 1e5 + 10;
////int s[N][N];
//ll a[N];
//ll b[N];
//ll dp[N];
//int main() {
//	ios::sync_with_stdio(0);
//	int n, m; cin >> n >> m;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	for (int j = 0; j < m; j++) cin >> b[j];
//	ll maxa = a[0], maxb = b[0], mina = a[0], minb = b[0];
//	dp[0] = a[0];
//	for (int i = 1; i < n; i++) {
//		if (dp[i - 1] > 0) dp[i] = dp[i - 1] + a[i];
//		else dp[i] = a[i];
//		maxa = max(maxa, dp[i]);
//	}
//	dp[0] = a[0];
//	for (int i = 1; i < n; i++) {
//		if (dp[i - 1] < 0) dp[i] = dp[i - 1] + a[i];
//		else dp[i] = a[i];
//		mina = min(mina, dp[i]);
//	}
//	dp[0] = b[0];
//	for (int i = 1; i < m; i++) {
//		if (dp[i - 1] > 0) dp[i] = dp[i - 1] + b[i];
//		else dp[i] = b[i];
//		maxb = max(maxb, dp[i]);
//	}
//	dp[0] = b[0];
//	for (int i = 1; i < m; i++) {
//		if (dp[i - 1] < 0) dp[i] = dp[i - 1] + b[i];
//		else dp[i] = b[i];
//		minb = min(minb, dp[i]);
//	}
//	ll ans1 = mina * minb;
//	ll ans2 = maxa * maxb;
//	ll ans3 = maxa * minb;
//	ll ans4 = mina * maxb;
//	ll ans = max(max(ans1, ans2), max(ans3, ans4));
//	cout << ans << "\n";
//	return 0;
//}