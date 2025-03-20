#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
using namespace std;

/*A DFS搜索*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;
//int T, n;
//string s;
//int ans1, ans2;
//string q1 = "dfs"; int hh1 = 0, tt1 = 0;
//string q2 = "DFS"; int hh2 = 0, tt2 = 0;
//int main() {
//	cin >> T;
//	while (T--) {
//		ans1 = ans2 = 0;
//		hh1 = hh2 = 0;
//		cin >> n >> s;
//		for (int i = 0; i < n; i++) {
//			if (s[i] == q1[hh1] && hh1 < 3) hh1++;
//			if (s[i] == q2[hh2] && hh2 < 3) hh2++;
//        }
//		if (hh1 == 3) ans1 = 1;
//		if (hh2 == 3) ans2 = 1;
//		printf("%d %d\n", ans2, ans1);
//	}
//	return 0;
//}

/*B 关鸡*/
/*WA*/
////出不去的情况 特殊 1 1，1 -1，2 0 共需要3个
////关住一边 纵坐标差《=1 最多3个
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;
//int T, n;
//#define PII pair<int,int>
//PII a[] = { {1,1}, {1,-1}, {2,0} };
//const int N = 1e5 + 10;
//PII arr[N];
//int main() {
//	cin >> T;
//	while (T--) {
//		cin >> n;
//		memset(arr, 0, sizeof arr);
//		for (int i = 0; i < n; i++) {
//			int r, c;
//			scanf("%d %d", &r, &c);
//			arr[i] = { r,c };
//		}
//	}
//	return 0;
//}
/*2024.2.4 不太有什么技巧的模拟(WA)*/ //写不出考虑所有情况的代码 //人麻了 //红温了
////特判（1，-1），（2，0），（1，1）他们只需要三个点
////特殊点真的不好处理
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<algorithm>
//using namespace std;
//int T, n;
//#define ll long long
//#define PII pair<int,int>
//const int N = 1e5 + 10;
//PII arr[N];
////为了方便排序，将x,y替换读
//int main() {
//	scanf("%d", &T);
//	while (T--) {
//		scanf("%d", &n);
//		int r, c;
//		for (int i = 0; i < n; i++) {
//			scanf("%d %d", &r, &c);
//			arr[i] = { c,r };
//		}
//		sort(arr, arr + n);
//		bool r1 = 0, r2 = 0, l1 = 0, l2 = 0;//1 盖住一个 2 盖住两个
//		bool s1 = 0, s2 = 0, s3 = 0;//记录特殊点的个数
//		int ans = 3;
//		for (int i = 0; i < n; i++) {
//			int x = arr[i].second;
//			int y = arr[i].first;
//			if ((x == 2 && y == 0)) s1 = 1;
//			if (x == 1 && y == -1) s2 = 1;
//			if (x == 1 && y == 1)s3 = 1;
//			if (y < 0) {
//				l1 = 1;
//				for (int j = i; j < n && j < i + 4; j++) {
//					int xx = arr[j].second;
//					int yy = arr[j].first;
//					if (x + xx == 3) {
//						if(abs(y - yy) <= 1) l2 = 1;//排除0点
//					}
//				}
//			}
//			if (y >= 0) {
//				r1 = 1;
//				for (int j = i; j < n && j < i + 4; j++) {
//					int xx = arr[j].second;
//					int yy = arr[j].first;
//					if (x + xx == 3) {
//						if (abs(y - yy) <= 1) r2 = 1;
//					}
//				}
//			}
//		}
//		if (r2){
//			ans -= 2;
//			if (s2 && s1) ans--;
//		}
//		if (l2) {
//			ans -= 2;
//			if (s3 && s1)ans--;
//		}
//		if (s2) {
//			ans--;
//		}
//		if (s3) {
//			ans--;
//		}
//		if (s1) ans--;
//		if (ans < 0) printf("%d\n", 0);
//		else printf("%d\n", ans);
//	}
//	return 0;
//}

/*C 按闹分配*/
/*WA/TLE*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;
//#define ll long long
//int n, Q;
//ll tc;
//const int N = 1e6 + 10;
//ll arr[N];
//ll s[N];
//ll sc[N];
//ll st[N];
//int main() {
//	scanf("%lld %lld %lld", &n, &Q, &tc);
//	for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
//	sort(arr, arr + n);
//	s[0] = arr[0];
//	ll sum = s[0];
//	for (int i = 1; i < n; i++) {
//		s[i] = s[i - 1] + arr[i];
//		sum += s[i];
//	}
//	//鸡加入队伍i后面需要的等待时间
//	//总的时间变化：sum+=tc*（插队人数n - i)
//	sc[0] = tc;
//	st[0] = sum + tc * (n);
//	ll msum = st[0];
//	for (int i = 1; i <= n; i++) {
//		sc[i] = s[i-1] + tc;
//		st[i] = sum + tc * (n - i);
//		//msum = min(msum, st[i]);
//	}
//	while (Q--) {
//		ll M;scanf("%lld", &M);
//		bool out = 0;
//		for (int i = 0; i <= n; i++) {
//			if (st[i] - sum <= M) {
//				printf("%lld\n", sc[i]);
//				break;
//			}
//		}
//	}
//	return 0;
//}
/*2024.2.4 前缀和+数学分析*/
//鸡插到某人后面，让之后的人时间都推迟tc，总不满意度增加tc*排在鸡后的人 m = tc*des
//现在给定了最大不满意度M，那么M/tc 就是排在鸡后面最多的人
//WA: 没有理解des的意义，判断条件出错
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//#define ll long long
//int n, Q, tc;
//const int N = 1e6 + 10;
//ll arr[N];
//ll s[N];
//int main() {
//	cin >> n >> Q >> tc;
//	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
//	sort(arr, arr + n);
//	s[0] = arr[0];
//	for (int i = 1; i < n; i++) s[i] = s[i - 1] + arr[i];
//	while (Q--) {
//		ll m; cin >> m;
//		ll des = m / tc;
//		ll ans;
//		if (n - des - 1 >= 0) ans = s[n - des - 1] + tc;
//		else ans = tc;
//		printf("%lld\n", ans);
//	}
//}

/*D 数组成鸡*/
/*WA*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;

/*E 本题又主要考察了贪心*/
/*WA*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;
////让1号一直赢，其他比多的输，少的赢，一样多的平 / 一输一赢
/*2024.2.4 被骗了 用dfs*/ //看数据范围猜出来的
////但是还真不知道怎么做
////枚举所有情况
////WA: 将比小值变成比大值
////WA：ans的初始化不对
////WA: ans的初始化位置，res排名的计算都不对
////WA: 计算排名应该在比赛结束后
////WA: md 比完赛才开始排名，你初始化的时候排锤子
//#include<iostream>
//#include<cstring>
//#include<string>
//using namespace std;
//int T, n, m;
////比赛是可以随便比的
//int arr[20];
//int b[20];int c[20];
//int dx[] = { 0,1,3 };
//int dy[] = { 3,1,0 };
//int ans = 0;
//
////int mySort() {
////	int res = 1;
////	for (int i = 2; i <= n; i++) {
////		if (arr[i] > arr[1]) res++;
////	}
////	//for (int j = 1; j <= n; j++) {
////	//	printf("%d ", arr[j]);
////	//}printf("\n");
////	return res;
////}
//
//void dfs(int x) {
//	if (x > m)
//	{
//		int cnt = 1;
//		for (int i = 2; i <= n; i++)
//		{
//			if (arr[i] > arr[1])
//				cnt++;
//		}
//		ans = min(ans, cnt);
//		return;
//	}
//	for (int i = 0; i < 3; i++) {
//		arr[b[x]] += dx[i];
//		arr[c[x]] += dy[i];
//		dfs(x + 1);
//		arr[b[x]] -= dx[i];
//		arr[c[x]] -= dy[i];
//	}
//}
//
//int main() {
//	scanf("%d", &T);
//	while (T--) {
//		scanf("%d %d", &n, &m);
//		for (int i = 1; i <= n; i++) {
//			scanf("%d", &arr[i]);
//		}
//		ans = n;
//		for (int i = 1; i <= m; i++) {
//			scanf("%d %d", &b[i], &c[i]);
//		}
//		dfs(1);
//		printf("%d\n", ans);
//	}
//	return 0;
//}

/*F 鸡数题*/ //第二类斯特林数 //不会就做不出来

/*G why买外卖*/
/*AC*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;
//int T, n, m;
//const int N = 1e5 + 10;
//#define ll long long 
//map<int, ll> g;
//int s[N];
//int main() {
//	cin >> T;
//	while (T--) {
//		scanf("%d %d",&n,&m);
//		g.clear();
//		memset(s, 0, sizeof s);
//		for (int i = 0; i < n; i++) {
//			int a, b;
//			scanf("%d %d", &a, &b);
//			s[i] = a;
//			g[a] += b;
//		}
//		sort(s, s + n);
//		for (int i = 1; i < n; i++) {
//			if (s[i] > s[i - 1])g[s[i]] += g[s[i - 1]];
//		}
//		ll ans = m;
//		for (auto t : g) {
//			if (t.second + m >= t.first) ans = max(ans, t.second + m);
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}

/*H 01背包，但是bit*/
//递推从？？开始
/*2024.2.4 题解 建议先思考一bit重量的情况*/
//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//#define N 1000005
//const ll mod=998244353;
//ll t,n,m;
//ll w[N],v[N];
//
//int main()
//{
//    scanf("%lld",&t);
//    while(t--){
//        ll maxx=0;
//        scanf("%lld%lld",&n,&m);
//        for(int i=1;i<=n;i++)scanf("%lld%lld",&v[i],&w[i]);
//        for(int p=1;p<=m;p=(p<<1)){//枚举bit 1 10 100 ... 与m的最大位相同
//            if((m|p)>m)continue;//如果这个重量 |m 比m大，不取（即取出m的每位1bit）
//            ll mm=0;
//            //printf("%lld\n",p);
//            for(int i=1;i<=n;i++){//比p小的任意组合，比p大的取w的子集，//== p？？
//                if(w[i]<p)mm+=v[i]; //比p小的与p同位的bit肯定为0
//                if(w[i]>p&&w[i]<=m){ //比p大的，例如p=100， w=101 p|w=101（会出现>w的情况吗？）//p=100，w=1010 
//                                     //如果一个数比m大，显然不是m的子集
//                    if(((w[i]/p*p)|m)==m&&(w[i]|p)>w[i])mm+=v[i]; //？？？（/p*p？）//
//                                                                   //w|p>w说明p不是w的子集 //即w有的某位bit m没有，w|m>m
//                }
//            }
//            maxx=max(maxx,mm);
//        }
//        ll mm=0;
//        for(int i=1;i<=n;i++)if((w[i]|m)==m)mm+=v[i]; //w中属于m的bit的子集和
//        maxx=max(maxx,mm);
//        printf("%lld\n",maxx);
//    }
//}

/*I It's bertrand paradox. Again!*/ //机器学习 二分类 概率论

/*J 又鸟之亦心*/

/*M 牛客老粉才知道的秘密*/
/*AC*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;
//
//int T, n;
//int main() {
//	scanf("%d", &T);
//	while (T--) {
//		scanf("%d", &n);
//		if (n % 6) printf("%d\n", (n / 6) * 2);
//		else printf("%d\n", n / 6);
//		
//	}
//	return 0;
//}

/*L 要有光 （几何）*/
/*2024.2.4 几何题*/ //用几何的方法分析
////淦 x0y坐标才是土地的面积
////WA: 逆天，没加 \n
//#include<iostream>
//using namespace std;
//int T;
//int main() {
//	cin >> T;
//	int c, d, h, w;
//	while (T--) {
//		cin >> c >> d >> h >> w;
//		printf("%.6f",3*w*c);
//	}
//	return 0;
//}