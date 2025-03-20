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
/**/
// #include<iostream>
// #include<cstring>
// #include<algorithm>
// #include<string>
// #include<map>
// #include<queue>
// #include<vector>
// #define ll long long
// using namespace std;
// #define PII pair<int,int>
// int t;
// int n, m;
// const int N = 2e5 + 10;
// int k;
// int a[N];
// int b[N];
// vector<int> arr;
// map<int, bool> g;

// int main() {
// 	cin >> t;
// 	while (t--) {
// 		scanf("%d %d %d", &n, &m, &k);
// 		for (int i = 0; i < n; i++)scanf("%d", &a[i]);
// 		for (int j = 0; j < m; j++) scanf("%d", &b[j]);
// 		if (n < k / 2 || m < k / 2) {
// 			printf("NO\n");
// 			continue;
// 		}
// 		sort(a, a + n);
// 		sort(b, b + m);
// 		int res1 = 0;
// 		int res2 = 0;
// 		arr.clear();
// 		g.clear();
// 		for(int i = 0; i < n; i++){
// 			if (a[i] <= k) {
// 				arr.push_back(a[i]);
// 				if (!g[a[i]]) {
// 					res1++;
// 					g[a[i]] = 1;
// 				}
// 			}
// 		}
// 		g.clear();
// 		for(int j = 0; j < m; j++) {
// 			if (b[j] <= k) {
// 				arr.push_back(b[j]);
// 				if (!g[b[j]]) {
// 					res2++;
// 					g[b[j]] = 1;
// 				}
// 			}
// 		}
// 		sort(arr.begin(), arr.end());
// 		arr.erase(unique(arr.begin(), arr.end()), arr.end());
// 		if (arr.size() == k && res1 >= k / 2 && res2 >= k / 2) printf("YES\n");
// 		else printf("NO\n");
// 	}
// 	return 0;
// }

/*D. Find the Different Ones!*/
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
//PII g[N];
//int main() {
//	cin >> t;
//	while (t--) {
//		scanf("%d", &n);
//		for (int i = 1; i <= n; i++)scanf("%d", &arr[i]);
//		scanf("%d", &q);
//		while (q--) {
//			scanf("%d %d", &l, &r);
//			memset(g, -1, sizeof g);
//			int step = 0;
//			for (int i = l; i <= r; i++) {
//				g[step++] = { arr[i],i };
//			}
//			sort(g, g + r - l + 1);
//			if (g[0] != g[r - l]) {
//				auto x = g[0];
//				auto y = g[r - l];
//				if (x.second < y.second)printf("%d %d\n", x.second, y.second);
//				else printf("%d %d\n", y.second, x.second);
//			}
//			else printf("%d %d\n", -1, -1);
//		}
//	}
//	return 0;
//}