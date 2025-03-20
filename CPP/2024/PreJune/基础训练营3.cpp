#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#define ll long long
using namespace std;
#define PII pair<int,int>
/*A 智乃与瞩目狸猫、幸运水母、月宫龙虾 */
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>;
//int T;
//int main() {
//	cin >> T;
//	while (T--) {
//		string s1, s2;
//		cin >> s1 >> s2;
//		char ch1 = tolower(s1[0]);
//		char ch2 = tolower(s2[0]);
//		if (ch1 == ch2) printf("Yes\n");
//		else printf("No\n");
//	}
//	return 0;
//}

/*B 智乃的数字手串*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
/*2024.2.17 博弈论基础*/
////(最优策略)是博弈论的关键词
////想出现不可选的情况，必须是一奇一偶的组合（总长为偶数）
////那么先手想赢，开始长度就必须是奇数
////这种抛开复杂的结果思考最终结果是博弈论的思路
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
//int t, n;
//int a;
//int main() {
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		for (int i = 0; i < n; i++)cin >> a;
//		if (n % 2) printf("qcjj\n");
//		else printf("zn\n");
//	}
//	return 0;
//}
/*NC223888 红色和紫色 (类似题)*/
////在棋盘这种具有对称性质的题目中，对称走法往往是最优策略
////WA:写反了获胜条件，读数时只读了n
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
//int main() {
//	ll n, m;
//	cin >> n >> m;
//	//printf("%lld\n", (n * m) % 2);
//	if ((n * m) % 2 == 0) printf("yukari\n");
//	else printf("akai\n");
//	return 0;
//}

/*C 智乃的前缀、后缀、回文*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>

///*G 智乃的比较函数(easy version) (WA)*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
//
////矛盾：1 2 1, 2 1 1
////不矛盾：1 2 1,2 1 0
////相等时：1 1 0
//int T, n, x, y, z;
//int g[4][4];
//
//int main() {
//	cin >> T;
//	while (T--) {
//		memset(g, -1, sizeof g);
//		bool ans = 1;
//		scanf("%d", &n);
//		scanf("%d %d %d", &x, &y, &z);
//		if (x == y && z == 1) ans = 0;
//		if (x < y) {
//			g[1][2] = z;
//			g[1][3] = z;
//			g[2][3] = z;
//		}
//		else if (x > y) {
//			g[2][1] = z;
//			g[3][1] = z;
//			g[3][2] = z;
//		}
//
//		for (int i = 1; i < n; i++) {
//			scanf("%d %d %d", &x, &y, &z);
//			if (x == y && z == 1) ans = 0;
//			if (g[x][y] == -1) g[x][y] = z;
//			if (g[y][x] == z) ans = 0;
//			if (g[x][y] != z) ans = 0;
//		}
//		if (ans) printf("Yes\n");
//		else printf("No\n");
//	}
//	return 0;
//}

/*L 智乃的36倍数(easy version) */
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
//int n;
//const int N = 1e5 + 10;
//ll arr[N];
////ll s[N];
//ll head(ll x) {
//	ll tmp = x;
//	while (tmp) {
//		tmp /= 10;
//		x *= 10;
//	}
//	return x;
//}
//
//int main() {
//	cin >> n;
//	//for (int i = 0; i < 20; i++) s[i] = 36 * (i + 1);
//	if (n < 2) {
//		printf("%d\n", 0);
//		return 0;
//	}
//	for (int i = 0; i < n; i++) {
//		scanf("%lld", &arr[i]);
//	}
//	//sort(arr, arr + n);
//	int res = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			ll sum = head(arr[i]) + arr[j];
//			if (sum % 36 == 0)res++;
//		}
//	}
//	printf("%d\n", res);
//	return 0;
//}

/*M 智乃的36倍数(normal version)*/
/*2024.2.17 枚举+数学 (WA)*/ //推测是a+b的时候不对
////36倍数有一个特性，无论多少位10000 % 36 == 28
////因此我们可以忽略数的位数直接讨论它%36的余数
////（a+b）% 36 == a%36 + b%36
////（a%36*28）%36 + b%36
////WA: 但是小数据版本能过
////个位数的b会影响到a
////WA:还是不对，但过得更少了
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
//const int N = 1e5 + 10;
//ll arr[N];
//ll cnt1[37]; //计数，余数是i的数的个数
//ll cnt2[37];
//int main() {
//	//printf("%d\n", 70 % 36);
//	int n;cin >> n;
//	ll ans = 0;
//	for (int i = 0; i < n; i++) cin >> arr[i];
//	for (int i = 0; i < n; i++) {
//		if (arr[i] > 9)cnt1[arr[i] % 36]++;
//		else cnt2[arr[i] % 36]++;
//	}
//	//枚举a与b拼接
//	for (int i = 0; i < n; i++) {
//		if (arr[i] % 36 == 0) {
//			ans += cnt1[0];
//		}
//		else if (arr[i] > 9LL) {//个位数以外的
//			ll a = (arr[i] % 36 * 28LL) % 36;
//			ans += cnt1[36 - a];
//			ans += cnt2[36 - a];
//		}
//		else {
//			ll a1 = (arr[i] % 36 * 28LL) % 36;
//			ll a2 = (arr[i] * 10LL) % 36;
//			ans += cnt1[36 - a1];
//			ans += cnt2[36 - a2];
//		}
//	}
//	//去掉自己拼自己的情况
//	for (int i = 0; i < n; i++) {
//		if (arr[i] % 36 == 0) {
//			ans--;
//		}
//		else if (arr[i] > 9) {//个位数以外的	
//			ll a = (arr[i] % 36 * 28LL) % 36;
//			if ((a + (arr[i] % 36)) == 36) ans--;
//		}
//		else {
//			ll a = (arr[i] * 10LL) % 36;
//			if ((a + (arr[i] % 36)) == 36) ans--;
//		}
//	}
//	printf("%lld\n", ans);
//	return 0;
//}
/*2024.2.18 分段枚举+数学*/
////与上文的数学原理相同
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
//const int N = 1e5 + 10;
//ll a[N];
//ll sum[N] = { 0 };
//int n;
//ll ans = 0;
//void slo() {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < 36; j++) {
//			if (a[i] < 10LL) {
//				if (((j * 10LL) % 36 + a[i]) % 36 == 0) ans += sum[j];
//			}
//			else {
//				if (((j * 28LL) % 36 + a[i]) % 36 == 0) ans += sum[j];
//			}
//		}
//		sum[a[i] % 36]++;
//	}
//}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) cin >> a[i];
// 	slo();
//	reverse(a, a + n);
//	memset(sum, 0, sizeof sum);
//	slo();
//	printf("%lld\n", ans);
//	return 0;
//}

/*D chino's bubble sort and maximum subarray sum(easy version)*/
//WA:printf("%lld");//孩子要小心阿
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
////dp[i] //以i为结尾的最长子段和
////dp[i][0] dp[i][1] //交换k次，
//int n, k;
//const int N = 2e3 + 10;
//ll arr[N];
//ll dp[N][2];
//ll tp[N][2];
//
//int main() {
//	memset(dp, 0, sizeof dp);
//	scanf("%d %d", &n, &k);
//	for (int i = 0; i < n; i++) scanf("%lld\n", &arr[i]);
//	dp[0][0] = arr[0];
//	ll ans = dp[0][0];
//	for (int i = 1; i < n; i++) {
//		if (dp[i - 1][0] < 0) dp[i][0] = arr[i];
//		else dp[i][0] = dp[i - 1][0] + arr[i];
//		ans = max(ans, dp[i][0]);
//	}
//	if (k < 1) {
//		printf("%lld\n", ans);
//		return 0;
//	}
//	//交换的递推不对
//	//if(dp[i][0] < 0) dp[i][1] = dp[i][0] + (为负数的前一个数的dp和);
//	for (int i = 0; i < n-1; i++) {
//		dp[i][1] = dp[i][0] - arr[i] + arr[i + 1];
//		ans = max(ans, dp[i][1]);
//	}
//	memset(tp, 0, sizeof tp); //tp[i] 以i为开头的和
//	tp[n - 1][0] = arr[n - 1];
//	for (int i = n - 2; i >= 0; i--) {
//		if (tp[i + 1][0] < 0) tp[i][0] = arr[i];
//		else tp[i][0] = tp[i + 1][0] + arr[i];
//	}
//	for (int i = n -1; i >= 1; i--) {
//		tp[i][1] = tp[i][0] - arr[i] + arr[i - 1];
//		ans = max(ans, tp[i][1]);
//	}
//
//	printf("%lld\n", ans); //死在了最后
//	return 0;
//}
//
////5 1
////- 10 10 - 1 9 2
