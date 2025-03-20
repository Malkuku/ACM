#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*P5301 [GXOI/GZOI2019] 宝牌一大堆 */ //(省选)(UF)

/* P4158 [SCOI2009] 粉刷匠 */
/*2024.7.27*/ //不操作也是一种状态，不要漏了
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int n,m,t;
// int dp[55][55][2510][3];
// char g[55][55];
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n >> m >> t;
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= m; j++){
//             cin >> g[i][j];
//         }
//     }
//     for(int i = 1; i <= n; i++){
//         for (int k = 1; k <= t; k++){
//             dp[i][0][k][1] = max({dp[i-1][m][k-1][1],dp[i-1][m][k-1][2],dp[i-1][m][k-1][0]});
//             dp[i][0][k][2] = max({dp[i - 1][m][k - 1][1], dp[i - 1][m][k - 1][2],dp[i-1][m][k-1][0]});
//             dp[i][0][k][0] = max({dp[i - 1][m][k][1], dp[i - 1][m][k][2], dp[i - 1][m][k][0]});
//             for (int j = 1; j <= m; j++){
//                 if(g[i][j] == '0'){
//                     dp[i][j][k][1] = max({dp[i][j-1][k][1] + 1,dp[i][j-1][k-1][2] + 1,dp[i][j-1][k-1][0] + 1});
//                     dp[i][j][k][2] = max({dp[i][j-1][k-1][1],dp[i][j-1][k][2],dp[i][j-1][k-1][0]});
//                 }
//                 else if(g[i][j] == '1'){
//                     dp[i][j][k][2] = max({dp[i][j - 1][k][2] + 1, dp[i][j-1][k-1][1] + 1,dp[i][j-1][k-1][0] + 1});
//                     dp[i][j][k][1] = max({dp[i][j - 1][k][1], dp[i][j - 1][k-1][2],dp[i][j-1][k-1][0]});
//                 }
//                 dp[i][j][k][0] = max({dp[i][j-1][k][0],dp[i][j-1][k][1],dp[i][j-1][k][2]});
//             }
//         }
//     }
//     cout << max({dp[n][m][t][0],dp[n][m][t][1],dp[n][m][t][2]}) << "\n";
//     return 0;
// }

/*P3558 [POI2013] BAJ-Bytecomputer*/ //思考状态
/*2024.7.27*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e6 + 10;
// int dp[N][3];
// int a[N];
// int main()
// {
//     ios::sync_with_stdio(0);
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//     }
//     memset(dp, 0x3f3f3f3f, sizeof dp);
//     if (a[1] == 1)
//     {
//         dp[1][2] = 0;
//     }
//     else if (a[1] == 0)
//     {
//         dp[1][1] = 0;
//     }
//     else if (a[1] == -1)
//     {
//         dp[1][0] = 0;
//     }
//     for (int i = 2; i <= n; i++)
//     {
//         dp[i][0] = dp[i - 1][0] + a[i] + 1;
//         if (a[i] == 0)
//             dp[i][1] = min(dp[i - 1][0] + a[i], dp[i - 1][1]);
//         else if (a[i] == 1)
//             dp[i][1] = dp[i - 1][0] + a[i];
//         else
//             dp[i][1] = 0x3f3f3f3f;
//         if (a[i] == 1)
//             dp[i][2] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] + 1 - a[i]});
//         else
//             dp[i][2] = dp[i - 1][2] + 1 - a[i];
//     }
//     int ans = min({dp[n][1], dp[n][2], dp[n][0]});
//     if (ans >= 0x3f3f3f3f)
//         cout << "BRAK\n";
//     else
//         cout << ans << "\n";
//     return 0;
// }

/*P2501 [HAOI2006] 数字序列 */ //(省选)（UF）

/*P2679 [NOIP2015 提高组] 子串 */ //字符串操作
/*2024.7.27 题解*/ //(精) 多思考状态
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N =1010;
// const int mod = 1e9+7;
// ll dp[2][210][210][2];
// //dp[i][j][k][1/0] //ai,bj,选了k个，是否使用当前字符
// //dp[i-1] 和 dp[i]俩个滚，max的滚法是错的
// int main(){
//     ios::sync_with_stdio(0);
//     int n,m,k;cin >> n >> m >> k;
//     string a,b;cin >> a >> b;
//     a = " " + a;
//     b = " " + b;
//     dp[0][0][0][0] = 1;
//     dp[1][0][0][0] = 1;
//     for(int i = 1; i <= n;i++){
//         for(int j = 1; j <= m; j++){
//             for(int p = 1; p <= k; p++){
//                 if(a[i] == b[j]){
//                     dp[i % 2][j][p][0] = (dp[(i - 1) % 2][j][p][1] + dp[(i - 1) % 2][j][p][0]) % mod;
//                     dp[i % 2][j][p][1] = (dp[(i-1)%2][j-1][p-1][0] + dp[(i-1)%2][j-1][p-1][1] + dp[(i-1)%2][j-1][p][1]) % mod;
//                 }
//                 else{
//                     dp[i % 2][j][p][0] =(dp[(i - 1) % 2][j][p][1] + dp[(i - 1) % 2][j][p][0]) % mod;
//                     dp[i % 2][j][p][1] = 0; //不能用
//                 }
//             }
//         }
//     }
//     cout << (dp[n%2][m][k][1] + dp[n%2][m][k][0]) % mod << "\n";
//     return 0;
// }

/*P1868 饥饿的奶牛 */
/*2024.7.27 题解*/ //线性解决(精)
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 3e6+10;
// int dp[N]; //dp[j] = max dp[i-1] + j - i + 1
// vector<int> a[N];//以i结尾的区间
// int main(){
//     ios::sync_with_stdio(0);
//     int n;cin >> n;
//     int maxlen = 0;
//     for(int i = 0; i < n; i++){
//         int x,y;cin >> x >> y;
//         a[y].push_back(x);
//         maxlen = max(maxlen,y);
//     }
//     for(int i = 1; i <= maxlen; i++){
//         dp[i] = dp[i-1];
//         for(int j = 0; j < a[i].size(); j++){
//             dp[i] = max(dp[i],dp[a[i][j] - 1] + i - a[i][j] + 1);
//         }
//     }
//     cout << dp[maxlen] << "\n";
//     return 0;
// }
/*2024.7.27 题解*/ //二分优化暴力
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e6+10;
// const int N2 = 1.5e5+10;
// struct unit{
//     int head,tail,val;
// }a[N2];
// int dp[N];
// int bound(int l,int r,int key){
//     int ans = 0;
//     while(l <= r){
//         int mid = (l+r) >> 1;
//         if(a[mid].tail < key) l = mid + 1;
//         else r = mid -1; 
//     }
//     return r;
// }
// int main(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++){
//         int x,y;cin >> x >> y;
//         a[i] = {x,y,y-x+1};
//     }
//     sort(a+1,a+1+n,[](auto x, auto y){
//         return x.tail < y.tail;
//     });
//     for(int i = 1; i <= n; i++){
//         dp[i] = max(dp[i-1],dp[bound(1,i-1,a[i].head)]+a[i].val);//找第一个尾 < 当前头的区间
//     }
//     cout << dp[n] << "\n";
//     return 0;
// }

/* P1095 [NOIP2007 普及组] 守望者的逃离 */ //处理附加条件
/*2024.7.27*/ //(WA) dp的问题在于只考虑了一次闪现的最佳而忽略了连续使用闪限的问题
//dp[i] //第i秒能移动的最远距离
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// const int N = 3e5+10;
// PII dp[N];
// int main(){
//     ios::sync_with_stdio(0);
//     int M,S,T;cin >> M >> S >> T;
//     dp[0] = {0,M};
//     for(int i = 1; i <= T; i++){
//         dp[i] = {dp[i-1].first+17,dp[i-1].second};
//         for(int j = 1; j <= T; j++){
//             if(i-j < 0) break;
//             if(dp[i-j].second >= 10 - 4*(j-1)){
//                 if(dp[i].first < dp[i-j].first+60){
//                     dp[i] = {dp[i-j].first+60,dp[i-j].second - 10 + 4*(j-1)};
//                 }
//                 else if(dp[i].first == dp[i-j].first + 60 && dp[i].second < dp[i-j].second - 10 + 4 * (j-1)){
//                     dp[i] = {dp[i - j].first + 60, dp[i - j].second - 10 + 4 * (j - 1)};
//                 }
//             }
//         }
//         cout << "! " << i << " " << dp[i].first << "\n";
//         if(dp[i].first > S){
//             cout << "Yes\n" << i << "\n";
//             return 0;
//         }      
//     }
//     cout << "No\n" << dp[T].first << "\n";
//     return 0;
// }
/*2024.7.27 题解*/ //所以然的贪心
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int main(){
//     int m,s,t;
//     cin >> m >> s >> t;
//     int s1 = 0,s2 = 0;
//     for(int i = 1; i <= t; i++){
//         s1+=17;
//         if(m>=10){
//             s2 += 60; m-=10;
//         }
//         else m += 4;
//         if(s2 > s1) s1 = s2;
//         if(s1 > s){
//             cout << "Yes\n" << i << "\n"; 
//             return 0;
//         }
//     }
//     cout << "No\n" << s1 << "\n";
// }

/* P1091 [NOIP2004 提高组] 合唱队形 */
/*2024.7.22*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int n;const int N = 110;
// int dp1[N],dp2[N];
// int a[N];
// int main(){
//     cin >> n;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//         dp1[i] = 1,dp2[i] = 1;
//     }
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j < i; j++){
//             if(a[i] > a[j])dp1[i] = max(dp1[i],dp1[j] + 1);
//         }
//     }
//     for(int i = n; i >= 1; i--){
//         for(int j = n; j > i; j--){
//             if(a[i] > a[j]) dp2[i] = max(dp2[i],dp2[j]+1);
//         }
//     }
//     int ans = 0;
//     for(int i = 1; i <= n; i++){
//         ans = max(dp1[i] + dp2[i] - 1,ans);
//     }
//     cout << n - ans << "\n";
//     return 0;
// }

/*P1020 [NOIP1999 提高组] 导弹拦截 */
/*2024.7.22 题解*/ //dp+二分
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// int n,t,h[N],f[N]; //f[x] ,长度为x时，f[x]的最大值
// int main(){
//     ios::sync_with_stdio(0);
//     int x;
//     while(cin >> x) h[++n] = x;
//     t = 0,memset(f,0,sizeof f),f[0] = 0x3f3f3f3f;
//     for(int i = 1; i <= n; i++){
//         int l = 0,r = t+1;
//         while (r - l > 1){
//             int mid = l + (r - l) / 2;
//             if (f[mid] >= h[i]) l = mid;
//             else r = mid;
//         }
//         int x = l+1; //dp[i]向r+l转移
//         if(x > t) t = x;
//         f[x] = h[i];
//     }
//     cout << t << "\n";
//     t = 0,memset(f,0,sizeof f),f[0] = 0;
//     //计算最长上升子序列，Dilworth定理
//     for(int i = 1; i <= n; i++){
//         int l = 0,r = t + 1;
//         while (l + 1 != r){ //??神奇二分，我自己的就过不了
//            // int mid = l + (r - l) / 2;
//            int mid = (l + r) >> 1;
//             if (f[mid] < h[i])
//                 l = mid;
//             else
//                 r = mid;
//         }
//         int x = l+1;
//         if(x > t) t = x;
//         f[x] = h[i];
//     }
//     cout << t << '\n';
//     return 0;
// }

/*P1216 [USACO1.5] [IOI1994]数字三角形 Number Triangles */
/*2024.7.22*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e3+10;
// ll dp[N][N];
// int g[N][N];
// int n;
// ll ans = 0;
// ll dfs(int x,int y){
//     if(x > n || y > x + 1) return 0;
//     if(dp[x][y] != -1) return dp[x][y];
//     dp[x][y] = max(dfs(x+1,y),dfs(x+1,y+1)) + g[x][y];
//     return dp[x][y];
// }
// int main(){
//     ios::sync_with_stdio(0);
//     memset(g, -1, sizeof g);
//     memset(dp, -1, sizeof dp);
//     cin >> n;
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= i; j++){
//             cin >> g[i][j];
//         }
//     }
//     cout << dfs(1,1) << "\n";
//     return 0;
// }

/*P2758 编辑距离 */
/*2024.7.21*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2010;
// ll dp[N][N]; //dp[i][j] a前i个与b前j个
// int main(){
//     string a,b;
//     cin >> a >> b;
//     a = " " + a;
//     b = " " + b;
//     //注意初始化的问题，既b，a变成0的开销是多少
//     for(int i = 1; i <= a.size(); i++) dp[i][0] = i;
//     for(int i = 1; i <= b.size(); i++) dp[0][i] = i;
//     for(int i = 1; i <= a.size(); i++){
//         for(int j = 1; j <= b.size(); j++){
//             if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1];
//             else dp[i][j] = min({
//                 dp[i-1][j-1],dp[i][j-1],dp[i-1][j]
//             }) + 1;
//         }
//     }
//     cout << dp[a.size()][b.size()] << "\n";
//     return 0;
// }

/*NC22096 ����������*/
// #include<iostream>
// #include<string>
// using namespace std;
//
// int main()
//{
//	int n;
//	while (scanf("%d",&n) != EOF)
//	{
//		for (int i = 1; i <= n; i++)
//		{
//			for (int j = 1; j <= i; j++)
//			{
//				printf("%d ", j);
//			}
//			printf("\n");
//		}
//	}
//
//	return 0;
// }

/*NC16708 ������*/
// #include<iostream>
// #include<string>
//
// using namespace std;
////��û�뵽��������ݻᱬint
// #define ll long long
//
// int n, m;
// int x, y;
// int xx[] = { -2,-2,-1,-1,2,2,1,1 };
// int yy[] = { -1,1,2,-2,-1,1,-2,2 };
//
// bool find(int a,int b)
//{
//	if (a == x && b == y) return 1;
//	for (int i = 0; i < 8; i++)
//	{
//		if (a == x+xx[i] && b == y+yy[i]) return 1;
//	}
//	return 0;
// }
////int -> 21��
////long long ����
//
// int main()
//{
//	//dp[i][j] ��(i,j)�ķ�����
//	//�������Ŀ��Ƶ�
//	//����i��j��
//	// i-2,j+1  i-2,j-1  i+2,j+1  i+2,j-1
//	// i-1,j+2  i-1,j-2 ...
//	//i,j
//
//	//dp
//	ll dp[30][30] = { 0 };
//	dp[0][0] = 1;
//
//	scanf("%d %d %d %d", &n, &m, &x, &y);
//	for (int i = 1; i <= n; i++)
//	{
//		if (find(i,0)) break;
//		dp[i][0] = 1;
//	}
//	for (int j = 1; j <= m; j++)
//	{
//		if (find(0,j)) break;
//		dp[0][j] = 1;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (find(i,j)) continue;
//			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//		}
//	}
//	printf("%lld ", dp[n][m]);
//
//	return 0;
//}

/*NC16619 ������Ϸ ��WA��*/
////m��n�Ĺ�ϵ m == n����ʱΪһȦ,һȦ��˳ʱ��ʱ���ַ���
////			m <= nʱ, ���mΪ�����Σ������ܴ���ȥ
////							mΪż���Σ���dp[3][2] = 2 ����
//
// #include<iostream>
// #include<string>
// #include<cmath>
// #define ll long long
// using namespace std;
// int n, m;
//
// int main()
//{
//	ll dp[32][32] = { 0 };//dp[i][j] i->n,j->mʱ�ķ�����
//	scanf("%d %d", &n, &m);
//	dp[3][1] = 0;
//	dp[3][2] = 2;
//	dp[3][3] = 2;
//
//	for (int i = 3; i <= n; i++)
//	{
//		for (int j = 3; j <= m; j++)
//		{
//			int k = j / i;
//			if (j % i == 0) dp[i][j] = (ll)pow(2,k) + dp[i-2][j-2];
//			else
//			{
//				if (j > i) dp[i][j] = dp[i][k] + dp[i][j - i];
//				else if (j < i)
//				{
//					if (j % 2) dp[i][j] = dp[i][j-2];
//					else dp[i][j] = 2 + dp[i][j-2];
//				}
//			}
//		}
//	}
//	printf("%lld\n", dp[n][m]);
//
//	return 0;
//}

/*NC16810 [NOIP1999]���ص���*/
////�ϸ�ݼ�������??
////1 ����ݼ������еĳ���
////2 ��ݼ������е�����??
////dp1[i] ��iΪβ����ݼ������еĳ���
////dp2[i] ��iΪβʱ���������е�����
// #include<iostream>
// #include<string>
// #include<cmath>
// #include<vector>
// #define ll long long
//
// using namespace std;
// const int N = 1e5 + 10;
// int nums[N] = { 0 };
// int dp1[N] = { 0 };
// int dp2[N] = { 0 };
// int n;
//
// int main()
//{
//	int k = 0;
//	while (cin >> n) nums[++k] = n;
//	int ans1 = 1;
//	int ans2 = 1;
//	for (int i = 1; i <= k; i++)
//	{
//		dp1[i] = 1;
//		dp2[i] = 1;
//		for (int j = i - 1; j >= 0; j--)
//		{
//			if (nums[j] > nums[i]) dp1[i] = max(dp1[i], dp1[j] + 1);
//			if (nums[j] <= nums[i]) dp2[i] = max(dp2[i], dp2[j] + 1);
//		}
//		ans1 = max(ans1, dp1[i]);
//		ans2 = max(ans2, dp2[i]);
//	}
//	printf("%d\n%d\n", ans1, ans2);
//
//	return 0;
// }

/*NC16664 [NOIP2004]�ϳ�����*/
////���ںϳ����Σ������㣺1.�ϸ����?? 2.�ϸ�ݼ�?? 3.�ϸ������ݼ�
////������Ϊ�ϸ������ݼ�������г���
////dp[i][0] ��iΪβ����������г���
////dp[i][1] ��iΪ�׵���ݼ����г���
////������ݼ���һ������� k ��β����-1Ϊ����
// #include<iostream>
// using namespace std;
//
// int n;
// int nums[110];
// int dp[110][2];
//
// int main()
//{
//	scanf("%d", &n);
//	for (int i = 0; i <= n; i++)
//	{
//		int num;
//		scanf("%d", &num);
//		nums[i] = num;
//	}
//
//	dp[0][0] = 1;dp[0][1] = 1;
//	for (int i = 1; i < n; i++)
//	{
//		dp[i][0] = 1, dp[i][1] = 1;
//		for (int j = i - 1; j >= 0; j--)
//		{
//			//��������
//			if (nums[j] < nums[i]) dp[i][0] = max(dp[i][0], dp[j][0] + 1);
//		}
//	}
//	//�ݼ�
//	for (int i = n;i >= 1;i--) {
//		for (int j = n;j > i;j--)
//			if (nums[i] > nums[j]) dp[i][1] = max(dp[i][1], dp[j][1] + 1);
//	}
//
//	int maxlen = 1;
//
//	/*
//	for(int i = 0; i < n; i++) printf("%d ",dp[i][0]);
//	printf("\n");
//	for(int i = 0; i < n; i++) printf("%d ",dp[i][1]);
//	printf("\n");
//	*/
//
//	for (int k = 0; k < n; k++)
//	{
//		maxlen = max(maxlen, dp[k][0] + dp[k][1] - 1);
//		//printf("%d %d %d %d\n",maxlen,dp[k][0],dp[n - 1][1],dp[k][1]);
//	}
//	printf("%d\n", n - maxlen);
//
//	return 0;
// }

/*NC235954 ��ѩ (���仯����)*/
////һ��������Χ4��������
////dp�Ļ�����//��͵������
////dp�ĺ��� dp[i][j] (i,j)�����������³���??
// #include<iostream>
// #include<algorithm>
// using namespace std;
//
// int n, m;
// int dp[110][110] = { 0 };
// int nums[110][110] = { 0 };
// int dx[] = { 1,-1,0,0 };
// int dy[] = { 0,0,1,-1 };
//
// int find(int x, int y)
//{
//	if (dp[x][y]) return dp[x][y];
//	dp[x][y] = 1;
//	for (int i = 0; i < 4; i++)
//	{
//		int xx = x + dx[i];
//		int yy = y + dy[i];
//		if (xx <= 0 || yy <= 0 || xx > n || yy > m) continue;
//		if (nums[xx][yy] < nums[x][y]) dp[x][y] = max(dp[x][y], find(xx, yy) + 1);
//	}
//	return dp[x][y];
// }
//
// int main()
//{
//	scanf("%d %d", &n, &m);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			int num;
//			scanf("%d", &num);
//			nums[i][j] = num;
//		}
//	}
//
//	int maxlen = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			maxlen = max(maxlen, find(i, j));
//		}
//	}
//	printf("%d\n", maxlen);
//
//	return 0;
// }

/*NC235948 ����Ӵ���??*/
////dp[i]��iΪβ������
// #include<iostream>
// #define ll long long
// using namespace std;
// int n;
// const int N = 1e6 + 10;
// ll a[N] = { 0 };
// ll dp[N] = { 0 };
//
// int main()
//{
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
//	dp[0] = a[0];
//	ll ans = a[0];
//	for (int i = 1; i < n; i++)
//	{
//		dp[i] = max(dp[i - 1] + a[i], a[i]);
//		ans = max(dp[i], ans);
//	}
//	printf("%lld\n", ans);
//
//	return 0;
// }

/*NC235624 ţ���ֺ������������*/
////dp[i][j] s��i-1Ϊβ��t��j-1Ϊβ������������г���
// #include<iostream>
// #include<string>
// using namespace std;
// const int N = 5e3 + 10;
// string s;
// string t;
// int dp[N][N] = { 0 };
//
// int main()
//{
//	while (cin >> s >> t)
//	{
//		int n1 = s.size();
//		int n2 = t.size();
//		int ans = 0;
//		for (int i = 1; i <= n1; i++)
//		{
//			for (int j = 1; j <= n2; j++)
//			{
//				if (s[i-1] == t[j-1]) dp[i][j] = dp[i - 1][j - 1] + 1;
//				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//				ans = max(ans, dp[i][j]);
//			}
//		}
//		printf("%d\n", ans);
//	}
//
//	return 0;
// }

/*LC 120. 三角形最小路径和*/
/*LC 152. 乘积最大子数组*/
/*LC 887. 鸡蛋掉落（DP+二分）*/ //(精)（不懂）
/*LC 354. 俄罗斯套娃信封问题*/ //(精)-单调队列+二分优化LIS
/*LC 44. 通配符匹配*/ //(精) -存在任意匹配长度匹配
/*LC 10. 正则表达式匹配*/ //(精)（UF）上题超级升级，逻辑复杂暂不写
