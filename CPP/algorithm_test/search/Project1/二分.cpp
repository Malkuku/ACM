#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int, int>

/* 二分模板 10.24更新版*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> a = {1,2,3,4,5,6};
int main(){
    int target = 5;
    int l = -1,r = a.size(); //双开区间
    while(l+1 < r){
        int mid = (l + r) >> 1;
        if(a[mid] < target){ //根据符号的方向 《 从右向左找到第一个符合的位置 
           l = mid;
        }
        else r = mid;
    }
    cout << l << " " << a[l] << "\n";
    l = -1,r = a.size();
    while(l+1 < r){
        int mid = (l + r) >> 1;
        if(a[mid] > target){
            r = mid;
        }
        else l = mid;
    }
    cout << r << " " << a[r] << "\n";
    int pos = upper_bound(a.begin(),a.end(),target) - a.begin(); //第一个 》 target
    cout << pos << "\n";
    pos = lower_bound(a.begin(),a.end(),target) - a.begin();   //第一个 》= target
    cout << pos << "\n";
    return 0;
}

///三分///  //解决如单峰函数的问题

/*AcWing 5201. 午餐音乐会*/
/*2024.7.12*/ //尝试自己二分 //WA思路上有没想通的地方
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// const int N = 1e5+10;
// int n;
// struct{
//     ll p,w,d;
// }a[N];
// bool check(ll x){
//     ll minl = 1e12,maxr = 0;
//     for(int i = 1; i <= n; i++){
//         minl = min(minl,x/a[i].w+a[i].d+a[i].p);
//         maxr = max(maxr,a[i].p-x/a[i].w-a[i].d);
//     }
//     if(minl >= maxr) return 1;
//     else return 0;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n;
//     for(int i = 1; i <= n; i++){
//         ll p,w,d;
//         cin >> p >> w >> d;
//         a[i].p = p,a[i].w = w,a[i].d = d;
//     }
//     ll l = 0,r = 1e12;
//     while(l <= r){
//         ll mid = (l+r) >> 1;
//         if(check(mid)) r = mid - 1;
//         else l = mid + 1;
//     }
//     cout << l << "\n";
//     return 0;
// }
/*2024.7.12 题解*/ //三分
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// const int N = 2e5+10;
// int n;
// struct {
//     int p,w,d;
// }a[N];
// ll check(int mid){
//     ll res = 0;
//     for(int i = 1; i <= n; i++){
//         //不需要移动
//         if(mid >= a[i].p - a[i].d && mid <= a[i].p + a[i].d) continue;
//         //移动成本
//         if(mid < a[i].p) res += (ll)(a[i].p - a[i].d - mid) * a[i].w;
//         else res += (ll)(mid - a[i].p - a[i].d) * a[i].w;
//     }
//     return res;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n;
//     for(int i = 1; i <= n; i++){
//         int p,w,d;cin >> p >> w >> d;
//         a[i] = {p,w,d};
//     }
//     //三分位置
//     int l = 0,r = 1e9;
//     while(l <= r){
//         int midl = l + (r - l) / 3;
//         int midr = r - (r - l) / 3;
//         if(check(midl) <= check(midr)) r = midr - 1;
//         else l = midl + 1;
//     }
//     cout << min(check(r),check(l)) << "\n"; 
//     return 0;
// }

/*NC20276 [SCOI2010]传送带*/
//Q: 传送带有可能交叉吗？ 在平面上的运动距离如何表示
//A：不重要，只需要处理好距离时间关系 & 用欧拉距离表示
/*2024.7.12 题解*/ //三分,ab段走的距离，cd段走的距离
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// struct Node{
//     double x;
//     double y;
// } a,b,c,d,ab,cd;
// double P,Q,R;
// //计算距离
// double mydist(Node a,Node b){
//     return sqrt(1e-11+(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
// }
// double calc2(double m){
//     cd.x = c.x + (m / mydist(c, d) * (d.x - c.x));
//     cd.y = c.y + (m / mydist(c, d) * (d.y - c.y));
//     double time1 = mydist(ab,cd)/R;
//     double time2 = mydist(cd,d)/Q;
//     return time1 + time2;
// }
// double calc(double m){
//     double time1 = m/P;
//     double l = 0,r = mydist(c,d);
//     ab.x = a.x + (m/mydist(a,b)*(b.x-a.x));//比例求坐标
//     ab.y = a.y + (m/mydist(a,b)*(b.y-a.y));
//     while(r - l > 1e-8){
//         double midl = l + (r - l) /3;
//         double midr = r - (r - l) / 3;
//         if(calc2(midr) - calc2(midl) > 1e-8){
//             r = midr - 1;
//         }
//         else l = midl + 1;
//     }
//     return time1 + min(calc2(l),calc2(r));
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
//     cin >> P >> Q >> R;
//     double l = 0,r = mydist(a,b);
//     while(r - l > 1e-8){
//         double midl = l + (r - l) / 3;
//         double midr = r - (r - l) / 3;
//         if(calc(midr) - calc(midl) > 1e-8){
//             r = midr; //浮点数不用-+1
//         }
//         else l = midl;
//     }
//     cout << fixed << setprecision(2) << min(calc(r),calc(l)) << "\n";
//     return 0;
// }


///01分数/// //简单来说就是符合和不符合的有一条界限

/*NC14662 小咪买东西*/
/*2024.7.12*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// const int N = 1e4+10;
// struct Node{
//     int c,v;
// }a[N];
// int n,k;
// bool check(double x){
//     vector<double> arr;
//     for(int i = 0; i < n; i++){
//         arr.push_back({a[i].v-a[i].c*x});
//     }
//     sort(arr.begin(),arr.end(),[](auto x,auto y){
//         return x > y;
//     });
//     double sum = 0;
//     for(int i = 0; i < k; i++){
//         sum += arr[i];
//     }
//     if(sum >= 0) return 1;
//     else return 0;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     int t;cin >> t;
//     while(t--){
//         cin >> n >> k;
//         for(int i = 0; i < n; i++){
//             int c,v;cin >> c >> v;
//             a[i] = {c,v};
//         }
//         // 二分答案x v/c = x由公式变换 v - c*x = 0
//         // 如果v - c*x > 0 成立，说明x是偏小的
//         double l = 0, r = 1e9;
//         while (r - l > 1e-8)
//         {
//             double mid = (l + r) / 2;
//             if (check(mid))
//                 l = mid;
//             else
//                 r = mid;
//         }
//         cout << (ll)r << "\n";
//     }
//     return 0;
// }


///二分搜索///

/*NC235558 ????????????*/
// ????l == ??????????????????num??��??
// ????r == ???????????��?????num??��??
/*2024.7.6*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// int n,q;
// const int N = 1e5+10;
// int a[N];
// int find1(int num){
//     int l = 0, r = n - 1;
//     while (l <= r)
//     {
//         int mid = (l + r) >> 1;
//         if (a[mid] < num) l = mid + 1;
//         else r = mid - 1;
//     }
//     return l;
// }
// int find2(int num)
// {
//     int l = 0, r = n - 1;
//     while (l <= r)
//     {
//         int mid = (l + r) >> 1;
//         if (a[mid] <= num)
//             l = mid + 1;
//         else
//             r = mid - 1;
//     }
//     return r;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n;
//     for(int i = 0; i < n; i++) cin >> a[i];
//     cin >> q;
//     while(q--){
//         int x,y; cin >> x >> y;
//         int pos1 = max(find1(x),0);
//         int pos2 = min(find2(y),n-1);
//         //cout << "*" << pos1 << " " << pos2 << "\n";
//         int ans = pos2 - pos1 + 1;
//         cout << max(ans,0) << "\n";
//     }
//     return 0;
// }

/*NC24866 [USACO 2009 Dec S]Music Notes*/
/*2024.7.6*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// const int N = 5e4+10;
// int a[N];
// int n,b;
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n >> b;
//     a[0] = -1;
//     for(int i = 1; i <= n; i++){
//         int x;cin >> x;
//         a[i] = a[i-1] + x;
//     }
//     while(b--){
//         int num; cin >> num;
//         int l = 1,r = n;
//         while(l <= r){
//             int mid = (l+r) >> 1;
//             if(a[mid] < num) l = mid + 1;
//             else r = mid - 1;
//         }
//         if(num > a[l]) l++;
//         cout << l << "\n";
//     }
//     return 0;
// }

///二分答案///

/*NC14301 K-th Number*/ //没看懂
/*2024.7.10 题解*/ //有用到滑窗（精）比较难以想到二分答案
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// const int INF = 0x3f3f3f3f;
// const int N = 1e5+7;
// ll n,k,m;
// ll a[N],b[N];
// bool check(ll x){
//     ll cnt = 0; //第k个数大于等于x的区间个数
//     ll num = 0; //当前区间大于等于x的数的个数
//     int l = 1;
//     for(int r = 1; r <= n; r++){
//         if(a[r] >= x) num++;
//         //这个区间第k大数是大于等于x的
//         if(num == k){
//             cnt += n - r + 1;//加上向右拓展的数量
//             while(a[l] < x){
//                 cnt += n - r + 1; // 左区间移动，新区间加上向右拓展的数量
//                 l++;
//             }
//             l++;
//             num--;
//         }
//     }
//     if(cnt >= m) return 1;
//     else return 0;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     int t;cin >> t;
//     while(t--){
//         cin >> n >> k >> m;
//         for(int i = 1; i <= n; i++) cin >> a[i];
//         ll l = 1,r = INF;//二分答案的预计值
//         //显然，答案越大，第k大数大于等于x的区间数量越少，==m时为答案
//         while(l <= r){
//             ll mid = (l+r) >> 1;
//             if(check(mid)) l = mid + 1;//第k大数大于等于x的区间数量大于等于m，说明x的取值比较小
//             else r = mid - 1;
//         }
//         cout << r << "\n";
//     }
//     return 0;
// }

/*NC16564 ?????*/
/*2024.7.8*/ //差分（精）
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// const int N = 1e6+10;
// int n,m;
// ll cha[N],he[N],a[N];
// struct{
//     ll d,s,t;
// }zhu[N];
// bool check(int x){
//     memset(cha,0,sizeof cha);
//     for(int i = 1; i <= x; i++){ //订单
//         cha[zhu[i].s] += zhu[i].d;
//         cha[zhu[i].t+1] -= zhu[i].d;
//     }
//     he[1] = cha[1];
//     if(he[1] > a[1]) return 0;
//     for(int i = 2; i <= n; i++){ //天数
//         he[i] = he[i-1] + cha[i];
//         if(he[i] > a[i]) return 0;
//     }
//     return 1;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     for(int i = 1; i <= m; i++){
//         ll d,s,t;cin >> d >> s >> t;
//         zhu[i].d = d,zhu[i].s = s,zhu[i].t = t;
//     }
//     //二分满足订单的号数
//     int l = 0,r = m;
//     while(l <= r){
//         int mid = (l+r) >> 1;
//         if(check(mid)) l = mid + 1;
//         else r = mid - 1;
//     }
//     //r是最大能满足的订单编号
//     if(r+1 >= m) cout << 0 << "\n";
//     else{
//         cout << -1 << "\n";
//         cout << r+1 << "\n";
//     }
//     return 0;
// }

/*[CQOI2010]?????*/
/*2024.7.8*/ // ???????J???????????
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// const int N = 1e5+10;
// ll a[60];
// ll n,m;
// bool check(ll x){
//     ll sum = 0;
//     for(int i = 1; i <= n; i++){
//         if(a[i] < x) sum += x - a[i];
//     }
//     if(sum > m || sum > x) return 0; //???????j????????,????j??????<=x
//     else return 1;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
//
//     ll l = 0,r = 1e12;
//     while(l <= r){
//         ll mid = (l+r) >> 1;
//         if(check(mid)) l = mid + 1;
//         else r = mid - 1;
//     }
//     cout << r << "\n";
//     return 0;
// }

/*NC235260 ???????*/
/*2024.7.8 ???????????*/ // ?????longlong????????
// //??????????��???????????????
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// const int N = 10100;
// ll a[N],b[N],c[N],d[N];
// int main(){
//     ios::sync_with_stdio(0);
//     int n;cin >> n;
//     for(int i = 0; i < n; i++){
//         cin >> a[i] >> b[i] >> c[i] >> d[i];
//     }
//     map<ll,ll> g;
//     ll ans = 0;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             g[a[i] + b[j]]++;
//         }
//     }
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             ans += g[-1*(c[i]+d[j])];
//         }
//     }
//     cout << ans << "\n";
//     return 0;
// }

/*NC24724 [USACO 2010 Feb S] Chocolate Eating*/
/*2024.7.8*/ // ?????????��
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// const int N = 5e4+10;
// ll a[N];
// int n,d;
// ll ans[N];
// bool check(ll x){
//     ll sum = 0;
//     int res = 0;
//     int day = 1;
//     while(day <= d){
//         //cout << "? " << day << " " << sum << "\n";
//         if (res > n)return 0;
//         if (sum < x) sum += a[res++];
//         else {
//             day++;
//             sum >>= 1;
//         }
//
//     }
//     return 1;
// }
// void output(ll x){
//     ll sum = 0;
//     int res = 0;
//     int day = 1;
//     while (day <= d)
//     {
//         if (sum < x){
//             ans[res] = day;
//             sum += a[res++];
//         }
//         else
//         {
//             day++;
//             sum >>= 1;
//         }
//     }
//     while(res < n){
//         ans[res++] = d;
//     }
//     for(int i = 0; i < n; i++) cout << ans[i] << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n >> d;
//     for(int i = 0; i < n; i++) cin >> a[i];
//     ll l = 1,r = 1e12+10;
//     while(l <= r){
//         ll mid = (l+r) >> 1;
//         if(check(mid)) l = mid+1;
//         else r = mid - 1;
//     }
//     cout << r << "\n";
//     output(r);
//     return 0;
// }

/*NC235254 ???��?*/
/*2024.7.6*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// const int N = 1e5+10;
// ll a[N];
// int n,k;
// bool check(ll x){
//     ll res = 0; //res?��?1e9???,????int??
//     for(int i = 1; i <= n; i++){
//         if(a[i] - x > 0) res += (a[i] - x + k - 1 - 1) / (k-1); //????��??????????k-1?????
//         //else if(a[i] - x > 0 && k == 1) return 0;
//     }
//     if(res <= x) return 1;
//     else return 0;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n;
//     ll maxn = 0;
//     for(int i = 1; i <= n; i++) {
//         cin >> a[i];
//         maxn = max(a[i],maxn);
//     }
//     cin >> k;
//     if(k <= 1){
//         cout << maxn << "\n";
//         return 0;
//     }
//     ll l = 0, r = 1e9+10;
//     while(l <= r){
//         int mid = (l+r) >> 1;
//         if(check(mid)) r = mid - 1;
//         else l = mid + 1;
//     }
//     if(check(r)) l = r;
//     cout << l << "\n";
//     return 0;
// }

/*NC24017 [USACO 2016 Jan S]Angry Cows*/
/*2024.7.6*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// const int N = 5e4+10;
// int a[N];
// int n,k;
// //???????????
// bool check(int x){
//     int range = x * 2;
//     int head = 0;
//     int res = 0;
//     //cout << "!! " << range << "\n";
//     while(head <= n-1 && res <= k){
//         //cout << "? " << head << " " << res << "\n";
//         int l = head, r = n-1;
//         while (l <= r){
//             int mid = (l + r) >> 1;
//             if (a[mid] - a[head] <= range)
//                 l = mid + 1;
//             else
//                 r = mid - 1;
//         }
//         res++;
//         //cout << "?? " << a[l] - a[head] << "\n";
//         head = r + 1;
//         //cout << "! " << head << " " << n <<"\n";
//     }
//     if(res <= k) return 1;
//     else return 0;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n >> k;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     if(n == 1){
//         cout << 0 << "\n";
//         return 0;
//     }
//     sort(a,a+n);
//     int l = 1, r = 1e9+10;
//     while(l <= r){
//         int mid = (l+r)>>1;
//         if(check(mid)) r = mid - 1;
//         else l = mid + 1;
//     }
//     cout << l << "\n";
//
//     return 0;
// }

/*NC16462 [NOIP2015]????*/
/*2024.7.6*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// const int N = 5e4+10;
// int len,n,m;
// int a[N];
// bool check(int x){
//     int res = 0;
//     int dis = 0;
//     for(int i = 0; i <= n; i++){
//         if(a[i] - dis < x) res++;
//         else dis = a[i];
//     }
//     if(res <= m) return 1;
//     else return 0;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> len >> n >> m;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }a[n] = len;
//     int l = 0, r = 1e9+10;
//     while(l <= r){
//         int mid = (l+r) >> 1;
//         if(check(mid)) l = mid + 1;
//         else r = mid - 1;
//     }
//     cout << r << "\n";
//     return 0;
// }

/// ???????///

/*p2678 luogu ???? ��??*/
// #include<iostream>
//
// const int N = 5e4 + 10;
// int L, n, m;
// int g[N];
////int s[N] = { 0 };
//
// bool check(int x)
//{
//	int cnt = 0;
//	int i = 0, j = 0;
//	while (i < n + 1)
//	{
//		i++;
//		while (g[i] - g[j] < x)
//		{
//			cnt++;
//			if (i < n + 1) i++;
//			else break;
//		}
//		j = i;
//	}
//	if (cnt <= m) return 1;
//	else return 0;
//}
//
// int main()
//{
//	scanf("%d %d %d", &L, &n, &m);
//	int max = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &g[i]);
//		//s[i] = g[i] - g[i - 1];
//	}
//	g[0] = 0;
//	g[n + 1] = L;
//	//s[n + 1] = g[n + 1] - g[n];
//
//	int l = -1, r = L + 1; //r????????????��?????????????��?
//	while (l + 1 < r)
//	{
//		int mid = (l + r) >> 1;
//		if (check(mid)) l = mid;
//		else r = mid;
//	}
//	if (check(r)) printf("%d\n", r);
//	else printf("%d\n", l);
//
//	return 0;
//}

/*p3852 luogu ��?????? ��??*/
// #include<iostream>
//
// const int N = (int)1e5 + 10;
// int L, n, K;
// int g[N];
// int s[N];//????????????
//
// bool check(int x)
//{
//	int cnt = 0;
//	for (int i = 1; i <= n + 1; i++)
//	{
//		if (s[i] > x)
//		{
//			cnt++;
//			int num = s[i] - x;
//			while (num > x)
//			{
//				cnt++;
//				num -= x;
//			}
//		}
//	}
//	if (cnt <= K) return 1;
//	else return 0;
// }
//
// int main()
//{
//	int max = 0;
//	scanf("%d %d %d", &L, &n, &K);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &g[i]);
//		s[i] = g[i] - g[i - 1];
//		//max = std::max(max, g[i]);
//	}
//	g[n + 1] = L;
//	s[n + 1] = g[n + 1] - g[n];
//
//	int l = -1;
//	int r = L + 1;
//	while (l + 1 < r)
//	{
//		int mid = (l + r) / 2;
//		if (check(mid))  r = mid;
//		else l = mid;
//	}
//	if (check(l)) printf("%d\n", l);//???????????
//	else printf("%d\n", r);
//	return 0;
// }

/*p1163 luogu ???��??? ??????????*/
// #include<iostream>
// using namespace std;
// typedef long long ll;
// ll a, b, m;
//
//
// bool check(double mid)
//{
//	mid /= 100;
//	double v = 1, sum = 0;
//	for(int i = 1; i<= m; i++)//??????��????
//	{
//		v *= (1 + mid);
//		sum += (b/v);
//	}
//	if (sum > a) return 1;
//	else return 0;
// }
//
// int main()
//{
//	scanf("%lld %lld %lld", &a, &b, &m);
//	double l = 0, r = 301;
//	while (r - l > 1e-9)
//	{
//		double mid = (r + l) / 2;
//		if (check(mid)) l = mid;
//		else r = mid;
//	}
//	if (check(r)) printf("%.1f", r);//???????????
//	else printf("%.1f", l);
//
//	return 0;
// }
/*2024.4.2*/ // ??????��??
// #include<bits/stdc++.h>
// using namespace std;
// double s, w, m;
// bool check(double mid) {
//	double sum = 0, c = 1;
//	mid /= 100;
//	for (int i = 1; i <= m; i++) {
//		c *= (1 + mid);
//		sum += w / c;
//	}
//	if (sum <= s) return 1;
//	else return 0;
// }
// int main() {
//	cin >> s >> w >> m;
//	double l = 0, r = 310;
//	while (r - l > 1e-8) {
//		double mid = (r + l) / 2;
//		if (check(mid)) r = mid;
//		else l = mid;
//	}
//	cout << fixed << setprecision(1) << l << "\n";
//	return 0;
// }

/*p2241 luogu ?????13.??1?????? ????*/
// #include<iostream>
// const int N = 1e6 + 10;//??????????main??
// int arr[N];
//
// int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 1; i <= m; i++)
//	{
//		int q;
//		scanf("%d", &q);
//		int l = 0; int r = n + 1;
//		while (l + 1 < r)
//		{
//			int mid = (l + r) / 2;
//			if (arr[mid] < q) l = mid;
//			else r = mid;
//		}
//		if (arr[l] == q) printf("%d ", l);
//		else printf("%d ", -1);
//	}
//	return 0;
// }

/*p1102 luogu A-B ????*/
// #include<iostream>
// #include<algorithm>
// typedef long long ll;
// const int N = 2e5 + 10;
// ll arr[N];
// ll n, c;
//
// int scearch_l(ll x)//????
//{
//	int l = 0, r = n + 1;
//	while (l + 1 < r)
//	{
//		int mid = (l + r) / 2;
//		if (arr[mid] < x) l = mid;
//		else r = mid;
//	}
//	if (arr[r] == x) return r;
//	else return -1;
// }
//
// int scearch_r(ll x)//????
//{
//	int l = 0, r = n + 1;
//	while (l + 1 < r)
//	{
//		int mid = (l + r) / 2;
//		if (arr[mid] > x) r = mid;
//		else l = mid;
//	}
//	if (arr[l] == x) return l;
//	else return -1;
// }
//
// int main()
//{
//	scanf("%lld %lld", &n, &c);
//	for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
//
//	std::sort(arr + 1, arr + n + 1);
//	//???A = B+C ??????
//	int res1, res2;
//	long long cnt = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		long long A = arr[i] + c;
//		res1 = scearch_l(A);
//		if (res1 == -1) continue;
//
//		res2 = scearch_r(A);
//		cnt += res2 - res1 + 1;
//	}
//
//	printf("%lld\n", cnt);
//	return 0;
// }

/*unkown*/
// #include<iostream>
// #include<algorithm>
// #include<cstring>
// #include<unordered_map>
// using namespace std;
//
// const int N = 1e5 + 10;
// int n;
// int arr[N];
// unordered_map<int, int> h;
//
// int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &arr[i]);
//		h[arr[i]] += 1;
//	}
//	int sum = 0;
//	sort(arr, arr + n + 1);
//	int j = unique(arr, arr + n + 1) - arr;
//	for (int i = 1; i < j; i++)
//	{
//		if (h[arr[i]] < arr[i]) sum += h[arr[i]];
//		else sum += h[arr[i]] - arr[i];
//	}
//	printf("%d\n", sum);
//	return 0;
// }
