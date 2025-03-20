#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*A. Make it White*/
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
//int t, n;
//int main() {
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		string s;
//		cin >> s;
//		int beg = -1;
//		int pre = -1;
//		for (int i = 0; i < n; i++) {
//			if (beg == -1 && s[i] == 'B') beg = i;
//			if (beg != -1 && s[i] == 'B') pre = i;
//		}
//		printf("%d\n", pre - beg + 1);
//	}
//	return 0;
//}

/*B. Following the String*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
////4 -> g[a]+1;
//int t, n;
//int g[27];
//const int N = 2e5 + 10;
//char arr[] = "abcdefghijklmnopqrstuvwxyz";
//int trace[N];
//
//int main() {
//	cin >> t;
//	while (t--) {
//		memset(g, -1, sizeof g);
//		memset(trace, 0, sizeof g);
//		cin >> n;
//		for (int i = 0; i < n; i++) scanf("%d", &trace[i]);
//		string ans;
//		for (int i = 0; i < n; i++) {
//			int j = 0;
//			while (j < 26) {
//				if (g[arr[j] - 'a'] + 1 == trace[i]) {
//					g[arr[j] - 'a']++;
//					ans += arr[j];
//					break;
//				}
//				j++;
//			}
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}

/*C. Choose the Different Ones!*/
////没大写？？？
////因为target一直在浮动的话就不好判断,不如牺牲一点内存创个队列,太贪了
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
//int t;
//int n, m;
//const int N = 2e5 + 10;
//int k;
//int a[N];
//int b[N];
//
//int main() {
//	cin >> t;
//	while (t--) {
//		
//		scanf("%d %d %d", &n, &m, &k);
//		for (int i = 0; i < n; i++)scanf("%d", &a[i]);
//		for (int j = 0; j < m; j++) scanf("%d", &b[j]);
//		if (n < k / 2 || m < k / 2) {
//			printf("NO\n");
//			continue;
//		}
//		sort(a, a + n);
//		sort(b, b + m);
//		int i = 0;int j = 0;
//		int target = 1;
//		int res1 = 0;
//		int res2 = 0;
//		
//		if(a[0] != 1 && b[0] != 1) {
//			printf("NO\n");
//			continue;
//		}
//		while (i < n && j < m && target <= k) {
//			bool find = 0;
//			if (a[i] == target) {
//				i++;
//				find = 1;
//				res1++;
//			}
//			if (b[j] == target) {
//				j++;
//				find = 1;
//				res2++;
//			}
//			if (find) target++;
//			else break;
//		}
//		//处理不等长情况
//		while (i < n && target <= k) {
//			bool find = 0;
//			if (a[i] == target) {
//				i++;
//				find = 1;
//				res1++;
//			}
//			if (find) target++;
//			else break;
//		}
//		while (j < m && target <= k) {
//			bool find = 0;
//			if (b[j] == target) {
//				j++;
//				find = 1;
//				res2++;
//			}
//			if (find) target++;
//			else break;
//		}
//		if (target == k+1 && res1 >= k/2 && res2 >= k/2) printf("YES\n");
//		else printf("NO\n");
//	}
//	return 0;
//}
/*徐哥哥题解 队列*/
//#include <iostream>
//#include<set>
//#include<queue>
//using namespace std;
//int main()
//{
//	set<int> s1;
//	set<int> s2;
//	set<int> s3;
//	queue<int> q1;
//	int T;
//	cin >> T;
//	for (int i = 0;i < T;i++)
//	{
//		int a, b, k;
//		int ra = 0, rb = 0;
//		cin >> a >> b >> k;
//		s1.clear();
//		s2.clear();
//		s3.clear();
//		for (int j = 0;j < a;j++)
//		{
//			int a1;
//			cin >> a1;
//			if (a1 <= k)
//			{
//				s1.insert(a1);
//				if (s2.insert(a1).second)
//					ra++;
//			}
//		}
//		for (int j = 0;j < b;j++)
//		{
//			int b1;
//			cin >> b1;
//			if (b1 <= k)
//			{
//				s1.insert(b1);
//				if (s3.insert(b1).second)
//					rb++;
//			}
//		}
//		if (ra < k / 2 || rb < k / 2)
//		{
//			q1.push(0);
//		}
//		else
//		{
//			if (s1.size() == k) q1.push(1);
//			else q1.push(0);
//		}
//	}
//	for (int i = 0;i < T;i++)
//	{
//		if (q1.front() == 1) cout << "YES" << endl;
//		else cout << "NO" << endl;
//		q1.pop();
//	}
//	return 0;
//}
/*vector + map*/
//去重是一个问题
//如果用set的话天生就具有独一性
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#include<vector>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
//int t;
//int n, m;
//const int N = 2e5 + 10;
//int k;
//int a[N];
//int b[N];
//vector<int> arr;
//map<int, bool> g;
//
//int main() {
//	cin >> t;
//	while (t--) {
//		scanf("%d %d %d", &n, &m, &k);
//		for (int i = 0; i < n; i++)scanf("%d", &a[i]);
//		for (int j = 0; j < m; j++) scanf("%d", &b[j]);
//		if (n < k / 2 || m < k / 2) {
//			printf("NO\n");
//			continue;
//		}
//		//sort(a, a + n);
//		//sort(b, b + m);
//		int res1 = 0;
//		int res2 = 0;
//		arr.clear();
//		g.clear();
//		for(int i = 0; i < n; i++){
//			if (a[i] <= k) {
//				arr.push_back(a[i]);
//				if (!g[a[i]]) {
//					res1++;
//					g[a[i]] = 1;
//				}
//			}
//		}
//		g.clear();
//		for(int j = 0; j < m; j++) {
//			if (b[j] <= k) {
//				arr.push_back(b[j]);
//				if (!g[b[j]]) {
//					res2++;
//					g[b[j]] = 1;
//				}
//			}
//		}
//		sort(arr.begin(), arr.end());
//		arr.erase(unique(arr.begin(), arr.end()), arr.end());
//		if (arr.size() == k && res1 >= k / 2 && res2 >= k / 2) printf("YES\n");
//		else printf("NO\n");
//	}
//	return 0;
//}

/*D. Find the Different Ones!*/
////记录重复数，dp[i] 以i开头的数的连续重复数
////l+dp[i] <= r
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#define ll long long
//using namespace std;
//#define PII pair<int,int>
//int t, n, q, l, r;
//const int N = 2e5 + 10;
//int arr[N];
//int dp[N];
//int main() {
//	cin >> t;
//	while (t--) {
//		scanf("%d", &n);
//		memset(dp, 0, sizeof dp);
//		for (int i = 1; i <= n; i++)scanf("%d", &arr[i]);
//		dp[n] = 1;
//		for (int i = n - 1; i >= 1; i--) {
//			if (arr[i + 1] == arr[i]) dp[i] = dp[i + 1] + 1;
//			else dp[i] = 1;
//		}
//		scanf("%d", &q);
//		while (q--) {
//			scanf("%d %d", &l, &r);
//			if(l + dp[l] <= r){
//				printf("%d %d\n", l, l + dp[l]);
//			}
//			else printf("%d %d\n", -1, -1);
//		}
//	}
//	return 0;
//}

/*E. Klever Permutation*/
////1 -> k+1 -> 2k+1 每次跳两格->k
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
//int n, k, t;
//const int N = 2e5 + 10;
//int arr[N];
//
//int main() {
//	cin >> t;
//	while (t--) {
//		scanf("%d %d", &n, &k);
//		memset(arr, 0, sizeof arr);
//		int step = 1;
//		for (int i = 1; i <= k; i += 2) {
//			for (int j = i; j <= n; j += k) {
//				arr[j] = step;
//				step++;
//			}
//		}
//		step = n;
//		for (int i = 2; i <= k; i += 2) {
//			for (int j = i; j <= n; j += k) {
//				arr[j] = step;
//				step--;
//			}
//		}
//		for (int i = 1; i <= n; i++) printf("%d ", arr[i]);
//		printf("\n");
//	}
//	return 0;
//}

/*I Tokitsukaze and Short Path (plus) */
/*2024.2.11 思维题*/
////套了一层图论的皮，但是拆开公式就会发现问题所在 
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
//ll t, n;
//const int N = 2e5 + 10;
//ll arr[N];
//
//int main() {
//	scanf("%lld", &t);
//	while (t--) {
//		scanf("%lld", &n);
//		for (int i = 0; i < n; i++)scanf("%lld", &arr[i]);
//		sort(arr, arr + n);
//		ll ans = 0;
//		for (int i = n-1; i >= 0; i--) {
//			ans += arr[i] * 2 * 2 * i;
//		}
//		printf("%lld\n", ans);
//	}
//	return 0;
//}

/*J Tokitsukaze and Short Path (minus)*/
/*2024.2.11 思维题*/
////两边之中取较小的，有可能绕路
////(A,C) -> (A,B),(B,C) 如果4B > 2min(A,C) 就会绕
////不需要考虑连绕三次的情况
////出现第一个比4b大的a点时选择绕路
////其他与I题的思路是一致的
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//
//ll t, n;
//const int N = 2e5 + 10;
//ll arr[N];
//
//int main() {
//	scanf("%lld", &t);
//	while (t--) {
//		scanf("%lld", &n);
//		for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
//		sort(arr, arr + n);
//		ll ans = 0;
//		int pos = 0;
//		for (int i = 0; i < n; i++) {
//			if (2 * arr[0] > arr[i]) ans += 2 * 2 * (n - 1 - i) * arr[i];
//			else ans += 4 * 2 * (n - 1 - i) * arr[0];
//		}
//		printf("%lld\n", ans);
//	}
//	return 0;
//}

/*K Tokitsukaze and Password (easy) */
/*2024.2.13 */
////WA:单个零不算前导零，但没有考虑这种情况
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//#include<set>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//#define mo (int)(1e9+7) 
//ll t, n;
//ll col(int x) {
//	ll res = 0;
//	while (x) {
//		x /= 10;
//		res++;
//	}
//	return res;
//}
//int main() {
//	cin >> t;
//	while (t--) {
//		set<ll> arr;
//		cin >> n;
//		string s;
//		cin >> s;
//		ll y;
//		cin >> y;
//		int res = 0;
//		for (int a = 0; a <= 9; a++) {
//			for (int b = 0; b <= 9; b++) {
//				for (int c = 0; c <= 9; c++) {
//					for (int d = 0; d <= 9; d++) {
//						set<int> q = { a,b,c,d };
//						if (q.size() != 4) continue;
//						for (int _ = 0; _ <= 9; _++) {
//							ll x = 0;
//							for (char ch : s) {
//								if (ch == 'a') x = x * 10 + a;
//								if (ch == 'b') x = x * 10 + b;
//								if (ch == 'c') x = x * 10 + c;
//								if (ch == 'd') x = x * 10 + d;
//								if (ch == '_') x = x * 10 + _;
//								if (ch <= '9' && ch >= '0') x = x * 10 + (ch - '0');
//							}
//							if (col(x) == n && x % 8 == 0 && x <= y) arr.insert(x % mo);
//						}
//					}
//				}
//			}
//		}
//		printf("%lld\n", arr.size()%mo);
//	}
//	return 0;
//}