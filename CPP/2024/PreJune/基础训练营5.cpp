#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
using namespace std;
#define PII pair<int,int>
#define ll long long

/*A mutsumi的质数合数*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#include<vector>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//const int N = 110;
//int arr[N];
//int isp(int x) {
//	if (x == 1)return -1;
//	for (int i = 2; i < x / 2; i++) {
//		if (x % i) return 0;
//	}
//	return 1;
//}
//int main() {
//	int n;
//	int cnt1 = 0;
//	int cnt2 = 0;
//	cin >> n;
//	int ans = n;
//	for (int i = 0; i < n; i++) {
//		int a;cin >> a;
//		if (a == 1) ans--;
//	}
//	cout << ans << "\n";
//	return 0;
//}

/*B tomorin的字符串迷茫值*/
//longlong
//1.删掉mygo之外的字符，迷茫值不变
//2.删掉其中一个mygo，（迷茫值-1）*4*2*2
//3.
/*2024.2.25(WA)*/ //请不要再用这种难蚌的方法了
////考虑每个mygo对答案的贡献 x—-mygo--y，贡献为x*y*1
////mygo的形态十分有限
////mygo m_ygo my_go myg_o m_y_go my_g_o m_yg_o m_y_g_o //_一定要删，不会记录迷茫值
////求x，y可以通过dp
////判断mygo怎么写？
////WA:pd的递推公式写错了
////WA:对于每一边都有不删的选项
////WA:有一个if里面写错了
////dp的定义有点问题
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#include<vector>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//const int N = 2e5 + 10;
//const int MOD = 1e9 + 7;
////int dp[N]; //以i-1结尾有dp【i】种删除方法
////int pd[N]; //以i-1开头有dp【i】种删除方法
//int dp[N]; //有i个数时有dp【i】种删除方法
//
//int main() {
//	//什么也不删算一种
//	ios::sync_with_stdio(0);
//	string arr; cin >> arr;
//	int n = arr.size();
//	arr = "?" + arr + "?";
//	dp[0] = 1;
//	dp[1] = 2;
//	for (int i = 2; i <= n; i++) {
//		dp[i] = (0LL + dp[i - 1] + dp[i - 2]) % MOD;
//	}
//	
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		if (i + 3 <= n && arr[i] == 'm' && arr[i + 1] == 'y' && arr[i + 2] == 'g' && arr[i + 3] == 'o') { //mygo
//			ans = ((1LL * (dp[i - 1]) * (dp[n - (i + 3)])) % MOD + ans) % MOD;
//		}
//		else if (i + 4 <= n && arr[i] == 'm' && arr[i + 2] == 'y' && arr[i + 3] == 'g' && arr[i + 4] == 'o') { //m_ygo
//			ans = ((1LL * (dp[i - 1]) * (dp[n - (i + 4)])) % MOD + ans) % MOD;
//		}
//		else if (i + 4 <= n && arr[i] == 'm' && arr[i + 1] == 'y' && arr[i + 3] == 'g' && arr[i + 4] == 'o') {//my_go
//			ans = ((1LL * (dp[i - 1]) * (dp[n - (i + 4)])) % MOD + ans) % MOD;
//		}
//		else if (i + 4 <= n && arr[i] == 'm' && arr[i + 1] == 'y' && arr[i + 2] == 'g' && arr[i + 4] == 'o') {//myg_o
//			ans = ((1LL * (dp[i - 1]) * (dp[n - (i + 4)])) % MOD + ans) % MOD;
//		}
//		else if (i + 5 <= n && arr[i] == 'm' && arr[i + 2] == 'y' && arr[i + 4] == 'g' && arr[i + 5] == 'o') { //m_y_go
//			ans = ((1LL * (dp[i - 1]) * (dp[n - (i + 5)])) % MOD + ans) % MOD;
//		}
//		else if (i + 5 <= n && arr[i] == 'm' && arr[i + 1] == 'y' && arr[i + 3] == 'g' && arr[i + 5] == 'o') { //my_g_o
//			ans = ((1LL * (dp[i - 1]) * (dp[n - (i + 5)])) % MOD + ans) % MOD;
//		}
//		else if (i + 5 <= n && arr[i] == 'm' && arr[i + 2] == 'y' && arr[i + 3] == 'g' && arr[i + 5] == 'o') { //m_yg_o
//			ans = ((1LL * (dp[i - 1]) * (dp[n - (i + 5)])) % MOD + ans) % MOD;
//		}
//		else if (i + 6 <= n && arr[i] == 'm' && arr[i + 2] == 'y' && arr[i + 4] == 'g' && arr[i + 6] == 'o') { //m_y_g_o
//			ans = ((1LL * (dp[i - 1]) * (dp[n - (i + 6)])) % MOD + ans) % MOD;
//		}
//	}
//	cout << ans << "\n";
//	return 0;
//}
/*2024.2.26 题解 思维+简单dp*/ //（精）字符串的一些处理方法
//#include<bits/stdc++.h>
//using namespace std;
//const int M = 1e9 + 7;
//const int N = 2e5 + 10;
//int f[N];
//string s;
//bool check(string a, string b) {
//    for (int i = 0;i < a.size();i++) {
//        if (a[i] == ' ')continue;
//        if (a[i] != b[i])return 0;
//    }
//    return 1;
//}
//int main() {
//    cin >> s;
//    int n = s.size();
//    s = "!" + s + "soyorinlove"; //可以
//    f[0] = 1;
//    f[1] = 2;
//    for (int i = 2;i <= n;i++) {
//        f[i] = (f[i - 1] + f[i - 2]) % M;//预处理
//    }
//    vector<string> t = { "mygo","m ygo","m y go","m y g o",
//                    "my go","my g o","myg o","m yg o" };//简化了中间的操作
//    int ans = 0;
//    //     for(int i=0;i<=n;i++)cout<<f[i]<<' ';
//    //     cout<<'\n';
//    for (int i = 1;i <= n;i++) {
//        for (auto j : t) {
//            string x = s.substr(i, j.size());//检查是否出现八种字符串
//            if (check(j, x)) {
//                ans = (ans + 1ll * f[i - 1] * f[n - (i + j.size()) + 1] % M) % M;//计算贡献
//            }                                       //6 - (1 + 4) + 1
//        }
//    }
//    cout << ans;
//}
/*2024.2.26*/
//#include<bits/stdc++.h>
//using namespace std;
//vector<string> s = { "mygo","m_ygo", "my_go", "myg_o", "m_y_go", "my_g_o", "m_yg_o","m_y_g_o"};
//string arr;
//const int MOD = 1e9 + 7;
//const int N = 2e5 + 10;
//int dp[N];
//bool check(string x,string y) {
//	for (int i = 0; i < x.size(); i++) {
//		if (x[i] == '_') continue;
//		if (x[i] != y[i]) return 0;
//	}
//	return 1;
//}
//int main() {
//	cin >> arr;
//	int n = arr.size();
//	arr = "?" + arr + "?";
//	dp[0] = 1;
//	dp[1] = 2;
//	for (int i = 2; i <= n; i++) {
//		dp[i] = (0LL + dp[i - 1] + dp[i - 2]) % MOD;
//	}
//	int ans = 0;
//	for (int i = 1; i <= n; i++) {
//		for (auto j : s) {
//			string x = arr.substr(i, j.size());
//			if (check(j, x)) ans = (ans + 1LL * (dp[i - 1]) * dp[n - (i + j.size()) + 1]) % MOD;
//		}
//	}
//	cout << ans << "\n";
//	return 0;
//}
/*题解 dp状态机 （未看）*/
////逛了一圈发现还没有用状态机dp写的题解，这里发一个QAQ。
////
////首先，很自然的一个状态定义是 :
////
////f[i][0 / 1]f[i][0 / 1] 表示只考虑前 ii 个字符，第 ii 个字符不选（选）的所有方案中，子串 mygo 出现的次数。
////
////我们的答案就是 f[n][0]f[n][0] + f[n][1]f[n][1]。
////
////考虑如何转移：
////
////f[i][0]f[i][0] : 第 ii 个不选，那么第 i−1i−1 个字符一定要选，则 f[i][0] = f[i - 1][1]。
////
////f[i][1]f[i][1] : 第 ii 个字符选的话，第 i−1i−1 个字符可选可不选。
////
////先算上前 i−1i−1 个字符中 mygo 出现的次数 f[i−1][0]f[i−1][0] + f[i−1][1]f[i−1][1]，
////
////再考虑第 ii 个字符加进去后产生的贡献，如果 s[i] == o, 则只要前 i−1i−1 个字符产生的字符串的后缀是 'myg', 就可以产生贡献。
////
////所以 f[i][1] = f[i - 1][0] + f[i - 1][1] + 前 i - 1 个中选的方案中后缀为 myg 的方案数量 * (s[i] == 0)
////
////现在我们只需要考虑如何处理出 '前 i-1 个中选的方案中后缀为 myg 的方案数量' 即可。
////
////后缀 myg 可由 my 变化过来，my 可由 m 变化过来，m 可由任意后缀变化过来，所以我们一共要维护四种后缀的数量，我们不妨用 3、2、1、0 来代表上面四种后缀（0 代表除了前三种后缀的其他后缀）。
////
////这四个状态的转移关系如下图（有点多，但不难分析）：
////
////alt
////
////我们定义转态 g[i][0 / 1][0 / 1 / 2 / 3] 为 只考虑前 i 个，第 i 个不选（选），后缀状态为 0 / 1 / 2 / 3 的方案数。
////
////根据上面的图可以很快的得出转移方程。
////
////Code
//#include<bits/stdc++.h>
//#define int long long
//using namespace std;
//
//const int N = 2e5 + 100;
//const int mod = 1e9 + 7;
//
//int n;
//int g[N][2][4], f[N][2];
//string s;
//
//signed main()
//{
//    cin >> s;
//    n = s.size();
//    s = " " + s;
//    if (s[1] == 'm')
//    {
//        g[1][1][1] = 1;
//        g[1][0][0] = 1;
//    }
//    else
//    {
//        g[1][1][0] = 1;
//        g[1][0][0] = 1;
//    }
//    for (int i = 2;i <= n;i++)
//    {
//        g[i][0][0] = g[i - 1][1][0] % mod;
//        g[i][0][1] = g[i - 1][1][1] % mod;
//        g[i][0][2] = g[i - 1][1][2] % mod;
//        g[i][0][3] = g[i - 1][1][3] % mod;
//        g[i][1][0] = (g[i - 1][0][0] * (s[i] != 'm') + g[i - 1][0][1] * (s[i] != 'm' && s[i] != 'y') + g[i - 1][0][2] * (s[i] != 'm' && s[i] != 'g') + g[i - 1][0][3] * (s[i] != 'm')
//            + g[i - 1][1][0] * (s[i] != 'm') + g[i - 1][1][1] * (s[i] != 'm' && s[i] != 'y') + g[i - 1][1][2] * (s[i] != 'm' && s[i] != 'g') + g[i - 1][1][3] * (s[i] != 'm')) % mod;
//        g[i][1][1] = (g[i - 1][0][0] * (s[i] == 'm') + g[i - 1][0][1] * (s[i] == 'm') + g[i - 1][0][2] * (s[i] == 'm') + g[i - 1][0][3] * (s[i] == 'm')
//            + g[i - 1][1][0] * (s[i] == 'm') + g[i - 1][1][1] * (s[i] == 'm') + g[i - 1][1][2] * (s[i] == 'm') + g[i - 1][1][3] * (s[i] == 'm')) % mod;
//        g[i][1][2] = (g[i - 1][0][1] * (s[i] == 'y') + g[i - 1][1][1] * (s[i] == 'y')) % mod;
//        g[i][1][3] = (g[i - 1][0][2] * (s[i] == 'g') + g[i - 1][1][2] * (s[i] == 'g')) % mod;
//    }
//
//    for (int i = 1;i <= n;i++)
//    {
//        f[i][0] = f[i - 1][1] % mod;
//        f[i][1] = (f[i - 1][0] + f[i - 1][1] + g[i - 1][0][3] * (s[i] == 'o') + g[i - 1][1][3] * (s[i] == 'o')) % mod;
//    }
//    int ans = (f[n][0] + f[n][1]) % mod;
//    cout << ans << '\n';
//}

/*M mutsumi的排列连通 */
////WA：首先就是题目没看清
////WA:我真tm服了，特判真jb多，主要还是忽略了边缘的地方
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#include<vector>
//#include<cmath>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//int T, n;
//const int N = 1e5 + 10;
//int arr1[N];
//int arr2[N];
//int g[N];
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> T;
//	while (T--) {
//		int ans = 0x3f3f3f3f;
//		cin >> n;
//		memset(g, 0, sizeof g);
//		for (int i = 1; i <= n; i++) {
//			cin >> arr1[i];
//			g[arr1[i]] = i;
//		}
//		for (int i = 1; i <= n; i++) {
//			cin >> arr2[i];
//		}
//		if (n == 1) {
//			cout << -1 << "\n";
//			continue;
//		}
//		if (n == 2) {
//			if (arr1[1] == arr2[1]) cout << -1 << "\n";
//			else cout << 1 << "\n";
//			continue;
//		}
//		for (int i = 2; i < n; i++) {
//			ans = min(ans, abs(i - g[arr2[i]]));
//		}
//		if (ans == 0 || ans == 1) cout << 1 << "\n";
//		else if (arr2[1] == arr1[2] || arr2[n] == arr1[n - 1]) {
//			cout << 1 << "\n";
//		}
//		else cout << 2 << "\n";
//	}
//	return 0;
//}

/*L anon的星星*/
////去掉不合理
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#include<vector>
//#include<cmath>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//int main() {
//	int n, x;
//	cin >> n >> x;
//	int cnt = n - (abs(x));
//	if (cnt % 2) {
//		cout << -1 << "\n";
//		return 0;
//	}
//	int win = cnt/2;
//	int ji = cnt/2;
//	if (x < 0) ji += abs(x);
//	else if (x > 0) win += x;
//	if (win + ji != n) cout << -1 << "\n";
//	else cout << win << " " << ji << "\n";
//	return 0;
//}

/*C anon的私货*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#include<vector>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
////可以夹0的地方？
////dp[i] i的左右的实际分配
////s[i] 代表第i个数最多还可以分配的0数
//const int N = 1e5 + 10;
//int arr[N];
//int s[N];
//int dp[N] = { 0 };
//int main() {
//	ios::sync_with_stdio(0);
//	int n;cin >> n;
//	memset(arr, 0x3f, sizeof arr);
//	for (int i = 1; i <= n; i++) {
//		cin >> arr[i];
//		s[i] = arr[i] - 1;
//	}
//	ll ans = 0;
//	dp[0] = s[1];
//	s[1] = 0;
//	s[n + 1] = 0x3f3f3f3f;
//	for (int i = 1; i <= n; i++) {
//		int tmp = 0;
//		if (s[i] >= s[i + 1]) {
//			dp[i] = s[i + 1];
//			s[i + 1] = 0;
//		}
//		else {
//			dp[i] = s[i];
//			s[i + 1] -= s[i];
//		}
//	}
//	for (int i = 0; i <= n; i++) ans += dp[i];
//	cout << ans << "\n";
//	return 0;
//}
//

/*I rikki的最短路*/
////到达T之前能不能看到A
////1.A T在同一方向上，1》A在T前，距离为T，2》A在T后，距离T+（A-T）*2
////2.A T在相反方向上，1》没看见A，先去T，距离T*3+A*2
//// 2>>看见A，先去A，距离A*2+T
////WA :忘记加绝对值了
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#include<vector>
//#include<cmath>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//int main() {
//	ll t, a, k;
//	ll ans = 0;
//	cin >> t >> a >> k;
//	if ((t <= 0 && a <= 0) || (t >= 0 && a >= 0)) {
//		if (abs(t) > abs(a)) {
//			ans = abs(t);
//		}
//		else {
//			ans = abs(t) + (abs(a) - abs(t)) * 2;
//		}
//	}
//	else {
//		if (abs(a) <= abs(k)) {
//			ans = abs(t) + abs(a) * 2;
//		}
//		else {
//			ans = abs(t) * 3 + abs(a) * 2;
//		}
//	}
//	cout << ans << "\n";
//	return 0;
//}

/*G&H sakiko的排列构造*/ //思维 //素数的判断 
//有没有一种可能，暴力能过？//不可能，绝对不可能 //10s都跑不完
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#include<vector>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//const int N = 1e3 + 10;
//int n;
//int arr[N];
//bool st[N];
//void dfs(int x) {
//	if (x > n) {
//		for (int i = 1; i <= n; i++) {
//			cout << arr[i] << " ";
//		}cout << "\n";
//		return;
//	}
//	for (int i = 1;i <= n; i++) {
//		if (st[i]) continue;
//		arr[x] = i;
//		st[i] = 1;
//		dfs(x + 1);
//		st[i] = 0;
//		arr[x] = 0;
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n;
//	dfs(1);
//	return 0;
//}
/*2024.2.26*/  //说白了就是找到了一个可能的规律但不敢往下写，最后一次只研究一个可能的规律，别把自己绕进去了
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//const int N = 2e6 + 10;
//int ans[N] = { 0 };
//
//vector<int> primes; // primes[]存储所有素数
//bool st[N];         // st[x]存储x是否被筛掉
//void get_primes(int n)
//{
//	for (int i = 2; i <= n; i++)
//	{
//		if (!st[i]) primes.push_back(i);
//		for (int j = 0; primes[j] <= n / i; j++)
//		{
//			st[primes[j] * i] = true;
//			if (i % primes[j] == 0) break;
//		}
//	}
//}
//
//bool isprime(int x){
//	for (int i = primes.size() - 1; i >= 0; i--) {
//		if (primes[i] == x) return 1;
//	}
//	return 0;
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n;
//	get_primes(n*2); //偷来的线性筛
//	int pos = n;
//	bool flag = 0;
//	int res = 0;
//	while (pos > 0) {
//		for (int i = 1; i <= pos; i++) {
//			if (isprime(pos + i)) {
//				int x = i;
//				int y = pos;
//				for (int j = x; j <= y; j++) {
//					ans[j] = pos--;
//					res++;
//				}
//				break;
//			}
//		}
//	}
//	if (res == n) {
//		for (int i = 1; i <= n; i++) {
//			cout << ans[i] << " ";
//		}cout << "\n";
//	}
//	else cout << -1 << "\n"; //根据数学公理，（n，2n）（n > 1）区间内一定存在一个素数
//	return 0;
//}