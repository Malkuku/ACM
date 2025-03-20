#define _CRT_SECURE_NO_WARNINGS 1
// 注释 ctrl + k + c //ctrl + k + u
// 全替换 ctrl + shit + L
// 折叠ctrl + k 0 展开ctrl + k j
#include<bits/stdc++.h>
using namespace std;
#define ll long long

/* 类似于板子 */
// #include<iostream>
// using namespace std;
// const int N = 1e5 + 10;
// int p[N];
////找到父节点
// int find(int x) {
//     if (p[x] != x) {
//         p[x] = find(p[x]);
//     }
//     return p[x];
// }
//
// int main() {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) {
//         p[i] = i;//开始自己为自己的一个父节点
//     }
//     for (int i = 1; i <= m; i++) {
//         char op;
//         int a, b;
//         cin >> op >> a >> b;
//         if (op == 'M') {
//             p[find(a)] = find(b);//将含b的树加到含a的父节点中
//         }
//         else {
//             if (find(a) == find(b)) { //查询a,b的父节点是否相同
//                 cout << "Yes\n";
//             }
//             else {
//                 cout << "No\n";
//             }
//         }
//     }
//     return 0;
// }

/* NC23803 DongDong认亲戚 */ // 版题
// #include<bits/stdc++.h>
                             // using namespace std;
                             // const int N = 2e4 + 10;
                             // map<string, int> g;
                             // int p[N];
                             //
                             // int find(int x) {
                             //	if (p[x] != x) p[x] = find(p[x]);
                             //	return p[x];
                             // }
                             //
                             // int main() {
                             //	int n, m;
                             //	cin >> n >> m;
                             //	for (int i = 1; i <= n; i++) {
                             //		string s;cin >> s;
                             //		if (!g.count(s)) g[s] = i;
                             //		p[i] = g[s];
                             //	}
                             //	while (m--) {
                             //		int opt;string x, y;
                             //		cin >> opt >> x >> y;
                             //		if (opt == 1) {
                             //			p[find(g[x])] = find(g[y]);
                             //		}
                             //		else if (opt == 2) {
                             //			if (find(g[x]) != find(g[y])) {
                             //				cout << 0 << "\n";
                             //			}
                             //			else cout << 1 << "\n";
                             //		}
                             //	}
                             //	return 0;
                             // }

/* NC235622 叠积木 */
/* 2024.3.15 题解（精）处理附加信息 */
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 3e5 + 10;
// int p[N];
// int cnt[N];//这一列的积木数
// int d[N]; //向下的积木数量
//
// int find(int x) {
//	if (p[x] != x) {
//		int t = find(p[x]);//这里这样写和处理的顺序有关,确保每次递归都能向下堆叠
//		d[x] += d[p[x]];//向下堆叠
//		p[x] = t;
//	}
//	return p[x];
//}
//
// int main() {
//	for (int i = 1; i <= N; i++) {
//		p[i] = i;
//		cnt[i] = 1;
//		d[i] = 0;
//	}
//	int t;cin >> t;
//	while (t--) {
//		char opt;
//		int x, y;
//		cin >> opt;
//		if (opt == 'M') {
//			cin >> x >> y;
//			int f1 = find(x);
//			int f2 = find(y);
//			if (f1 != f2) {
//				p[f1] = f2;
//				d[f1] = cnt[f2];
//				cnt[f2] += cnt[f1];
//			}
//		}
//		else if (opt == 'C') {
//			int x; cin >> x;
//			find(x);
//			cout << d[x] << "\n";
//		}
//	}
//	return 0;
//}

/* hdu3038 How Many Answers Are Wrong*/  //附加信息
/*2024.9.13*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+10;
// const int M = 4e4+10;
// int fa[N],d[N];
// int find(int x){
//     if(fa[x] != x){
//         int t = fa[x];
//         fa[x] = find(fa[x]);
//         d[x] += d[t];
//     }
//     return fa[x];
// }
// int main(){
//     ios::sync_with_stdio(0);
//     int n,m;
//     while(cin >> n >> m){
//     int ans = 0;
//     for(int i = 0; i <= n; i++) fa[i] = i,d[i] = 0;
//     for(int i = 1; i <= m; i++){
//         int x,y,v;cin >> x >> y >> v;
//         x--;// 将一个区间和转化为两个区间差
//         int fx = find(x),fy = find(y);
//         if(fx == fy){
//             if(d[x] - d[y] != v) ans++;
//         }
//         else{
//             fa[fx] = fy;
//             d[fx] = d[y] - d[x] + v; 
//         }
//     }
//     cout << ans << "\n";
//     }
//     return 0;
// }

/*P1455 搭配购买*/ // + 01背包
/*2025.2.16*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4+10;
int fa[N];
int dp[N];
int w[N],cnt[N];
int find(int x){
    if(x != fa[x]) return fa[x] = find(fa[x]);
    else return fa[x];
}
void solve(){
    int n,m,k;cin >> n >> m >> k;
    memset(dp,0,sizeof dp);
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= n; i++) {
        int x,y;cin >> x >> y;
        w[i] = x;
        cnt[i] = y;
    }
    for(int i = 1; i <= m; i++){
        int x,y;cin >> x >> y;
        fa[find(x)] = y;
    }
    for(int i = 1; i <= n; i++){
        if(fa[i] != i){
            w[find(i)] += w[i];
            w[i] = 0;
            cnt[find(i)] += cnt[i];
            cnt[i] = 0;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(fa[i] != i) continue;
        for(int j = k; j >= w[i]; j--){
            dp[j] = max(dp[j],dp[j-w[i]]+cnt[i]);
            ans = max(ans,dp[j]);
        }
    }
    cout << ans << "\n";
}
int main(){
    int t = 1;//cin >> t;
    while(t--){
        solve();
    }
}


/* [NOI2002]银河英雄传说 */
/* 2024.3.16 */
// //TLE 数据比较大记得关同步流k
// //细节 x==y时应该特判输出0
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 3e4 + 10;
// //查询一个区间
// //d[j] - d[i]
// int d[N]; 
// int cnt[N]; //这一列的总数
// int fa[N];
// int find(int x){
//     if(fa[x] != x){
//         int t = find(fa[x]);//向上找根
//         d[x] += d[fa[x]];//下向找堆叠
//         fa[x] = t;
//     }
//     return fa[x];
// }
// int main(){
//     ios::sync_with_stdio(0);
//     for (int i = 1; i <= N; i++){
//         fa[i] = i;
//         cnt[i] = 1;
//         d[i] = 0;
//     }
//     int t;
//     cin >> t;
//     while(t--){
//         char ch;
//         int x, y;
//         cin >> ch >> x >> y;
//         if(ch == 'M'){
//             int f1 = find(x);
//             int f2 = find(y);
//             if(f1 != f2){
//                 d[f1] = cnt[f2];
//                 cnt[f2] += cnt[f1];
//                 fa[f1] = f2;
//             }
//         }
//         else if(ch == 'C')
//         {
//             int f1 = find(x);
//             int f2 = find(y);
//             if(f1 != f2)
//                 cout << -1 << "\n";
//             else if(x == y)
//                 cout << 0 << "\n";
//             else
//                 cout << abs(d[y] - d[x]) - 1 << "\n";
//         }
//     }
// }

/* NC16884 食物链 */
/* 2024.3.17 扩展域并查集*/
// // 开三倍的n，表示同类，被x吃的类，能吃x的类
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 5e4 + 10;
// int n, k;
// int fa[N*3];
//
// int find(int x){
//     return fa[x] == x ? x : find(fa[x]);
// }
//
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n >> k;
//     for (int i = 1; i <= n*3; i++){
//         fa[i] = i;
//     }
//     int res = 0;
//     while(k--){
//         int t, x, y;
//         cin >> t >> x >> y;
//         if(x > n || y > n){
//             res++;
//             continue;
//         }
//         int f1 = find(x);
//         int f2 = find(y);
//         int ff1 = find(x+n);
//         int ff2 = find(y+n);
//         int fff1 = find(x+n+n);
//         int fff2 = find(y+n+n);
//         if(t == 1){
//             if(f1 == ff2 || f1 == fff2){ //同类必须在同层
//                 res++;
//                 continue;
//             }
//             fa[f1] = f2;
//             fa[ff1] = ff2;
//             fa[fff1] = fff2;
//         }
//         else if(t == 2){ //x吃y关系,y被吃层中x，x能吃层中y
//             if(x == y || f1 == f2 || f1 == ff2) {//同城，关系倒转为错
//                 res++;
//                 continue;
//             }
//             //这是一个环形的食物链
//             fa[f1] = fff2;
//             fa[ff1] = f2;
//             fa[fff1] = ff2;
//         }
//     }
//     cout << res << "\n";
//     return 0;
// }
/*2024.9.13 题解*/ // 附加信息
// //d[a-c] = (d[a-b] + d[b-c]) % 3;
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 5e4+10;
// int fa[N],d[N];
// int find(int x){
//     if(fa[x] != x){
//         int t = fa[x];
//         fa[x] = find(fa[x]);
//         d[x] = (d[x] + d[t]) % 3;
//     }
//     return fa[x];
// }
// int main(){
//     ios::sync_with_stdio(0);
//     int n,k;cin >> n >> k;
//     for(int i = 1; i <= n; i++) fa[i] = i,d[i] = 0;
//     int ans = 0;
//     while(k--){
//         int dd,x,y;cin >> dd >> x >> y;
//         if(x > n || y > n || (dd == 2 && x == y)) ans++;
//         else{
//             int fx = find(x),fy = find(y);
//             if(fx == fy){
//                 if(dd-1 != (d[x] - d[y] + 3)%3){ //0同类 1 x吃y
//                     ans++;
//                 }
//             }
//             else{
//                 fa[fx] = fy;
//                 d[fx] = (d[y] - d[x] + dd - 1) % 3;
//             }
//         }
//     }
//     cout << ans << '\n';
//     return 0;
// } 

/* NC16591 关押罪犯 */
/* 2024.3.17 矛盾关系 */
// // 影响力从大到小排序，从大到小枚举每个冲突，尽可能的让冲突避免
// // 首个无法避免的冲突，就是最大的答案
// // WA：到底哪里有问题？？？ //当b[x]存在时，应该把y和b[x]放在一块
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 10;
// int b[N] = { 0 }; //b[i]的最大敌人是i
// struct node{
//     int x, y;
//     long long w;
// } a[N];
// int fa[N];
// int find(int x){
//     return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
// }
//
// int main(){
//     ios::sync_with_stdio(0);
//     int n, m;
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++){
//         fa[i] = i;
//     }
//     for (int i = 1; i <= m;i++){
//         cin >> a[i].x >> a[i].y >> a[i].w;
//     }
//
//     sort(a + 1, a + m + 1, [](auto x, auto y)
//          { return x.w > y.w; });
//     for (int i = 1; i <= m; i++)
//     {
//         int x = a[i].x;
//         int y = a[i].y;
//         long long w = a[i].w;
//         if (find(x) == find(y))
//         {
//             // 冲突已经无法避免
//             cout << w << "\n";
//             return 0;
//         }
//         if (b[x] == 0)
//         {
//             b[x] = y;
//         }
//         else
//         {
//             fa[find(y)] = find(b[x]);
//         }
//         if (b[y] == 0)
//         {
//             b[y] = x;
//         }
//         else
//         {
//             fa[find(x)] = find(b[y]);
//         }
//         }
//     return 0;
// }

/* CF E. Split Into Two Sets */
/* 2024.3.17 (TLE)用矛盾关系的想法不太对 */
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 2e5 + 10;
// int b[N]; //i与b【i】
// struct node{
//     int x, y;
// } a[N];
// int fa[N];
//
// int find(int x){
//     return fa[x] == x ? x : fa[x] = find(fa[x]);
// }
// int sum[N];
//
// int main(){
//     ios::sync_with_stdio(0);
//     int t;
//     cin >> t;
//     while(t--){
//         memset(b, 0, sizeof b);
//         memset(sum, 0, sizeof sum);
//         int n;
//         cin >> n;
//         for (int i = 1; i <= n; i++){
//             fa[i] = i;
//             int x, y;
//             cin >> x >> y;
//             a[i].x = x;
//             a[i].y = y;
//             sum[x]++;
//             sum[y]++;
//         }
//         bool flag = 0;
//         sort(a + 1, a + 1 + n, [](auto x, auto y)
//              { if(x.x < y.x)return x.x < y.x;
//                 else return x.y < y.y; });
//         for (int i = 1; i <= n; i++){
//             int x = a[i].x;
//             int y = a[i].y;
//             if(find(x) == find(y) || sum[x] != 2 || sum[y] != 2){
//                 flag = 1;
//                 break;
//             }
//             if(b[x] == 0)
//                 b[x] = y;
//             else
//                 fa[find(b[x])] = y;
//             if(b[y] == 0)
//                 b[y] = x;
//             else
//                 fa[find(b[y])] = x;
//         }
//         if(!flag)cout << "YES\n";
//         else cout << "NO\n";
//     }
//     return 0;
// }
/* 2024.3.17 题解 扩展域 */
// //想表示多元关系，将域扩张
// // x表示它的朋友，x+n表示它的敌人
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 2e5 + 10;
// int fa[N*2];
// int sum[N];
// int find(int x){
//     return fa[x] == x ? x : fa[x] = find(fa[x]);
// }
// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         memset(sum, 0, sizeof sum);
//         int n;
//         cin >> n;
//         for (int i = 1; i <= n+n; i++){
//             fa[i] = i;
//         }
//         bool flag = 0;
//         for (int i = 1; i <= n; i++){
//             int x, y;
//             cin >> x >> y;
//             sum[x]++;
//             sum[y]++;
//             int f1 = find(x);
//             int ff1 = find(x + n);
//             int f2 = find(y);
//             int ff2 = find(y + n);
//             if(x == y || f1 == f2 || sum[x] > 2 || sum[y] > 2 || x > n || y > n) {
//                 flag = 1;
//                 continue;
//             }
//             //只能这么写(f层与ff层要有交集)
//             fa[f1] = ff2;
//             fa[ff1] = f2;
//         }
//         if(flag)
//             cout << "NO\n";
//         else
//             cout << "YES\n";
//     }
//     return 0;
// }
/* 2024.3.17 题解 联通集合(精) */
// //1.每个数字必须出现2次
// //2.我们将a，b链接，最后联通的数字数量应该是偶数,否则说明有一个集合的数与俩边分组都相同
// #include <stdio.h>
// #include <iostream>
// using namespace std;
// int vis[(int)2e5 + 6];
// int arr[(int)2e5 + 6];
// int sum[(int)2e5 + 6];
// int find(int t)
// {
//     if (t == vis[t])
//         return t;
//     return vis[t] = find(vis[t]);
// }
// void pre(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         vis[i] = i;
//         arr[i] = 0;
//         sum[i] = 0;
//     }
// }
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, a, b;
//         cin >> n;
//         pre(n);
//         for (int i = 1; i <= n; i++)
//         { // 并查集的实现
//             cin >> a >> b;
//             sum[a]++;
//             sum[b]++;
//             vis[find(a)] = find(b);
//         }
//         bool flag = 1;
//         for (int i = 1; i <= n; i++)
//         { // 思路1的判断
//             if (sum[i] != 2)
//             { // 因为数字不能超过n，故要想分成两组必须每个数字出现两次
//                 flag = 0;
//             }
//             arr[find(i)]++;
//         }
//         for (int i = 1; i <= n; i++)
//         { // 思路2的判断
//             if (arr[i] & 1)
//                 flag = 0;
//             //cout << arr[i] << " ";
//         }
//         if (flag == 1)
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }
//     return 0;
// }

/* NC51097 Parity game */
/* 2024.3.21 扩展域 */
////1.x比较大，所以用map代替
////2.把x-y区间问题变成 1-- x-1 和 1 -- y,它们都是从1出发的，故1可以省略
////3.扩展域 设x 与 x+n 的鸡偶性相反，y与y+n相反，
////则x--y为奇数时,x-1与y相反，偶-鸡 = 鸡 / 鸡 - 偶 = 鸡
////为偶数时，x-1与y相同，鸡 - 鸡 = 偶 / 偶 - 偶 = 偶
////WA:  y 写成了y-1  域必须扩大到n+1
//#include<iostream>
//#include<string>
//#include<cstring>
//#include<map>
//using namespace std;
//#define ll long long
//map<ll, ll> fa;
//ll find(ll x) {
//    return fa[x] == x ? x : fa[x] = find(fa[x]);
//}
//int main() {
//    ll n; cin >> n; n++;//x-1+n不能在原来的域内
//    ll m; cin >> m;
//    int i = 0;
//    for (i = 0; i < m; i++) {
//        string opt;
//        ll x, y;
//        cin >> x >> y >> opt;
//        if (!fa.count(x - 1)) {
//            fa[x - 1] = x - 1;
//            fa[x - 1 + n] = x - 1 + n;
//        }
//        if (!fa.count(y)) {
//            fa[y] = y;
//            fa[y + n] = y + n;
//        }
//        int fx = find(x - 1);
//        int fy = find(y);
//        int ffx = find(x - 1 + n);
//        int ffy = find(y + n);
//        if (opt == "even") {
//            if (fx == ffy) break;
//            fa[fx] = fy;
//            fa[ffx] = ffy;
//        }
//        else {
//            if (fx == fy) break;
//            fa[fx] = ffy;
//            fa[ffx] = fy;
//        }
//    }
//    cout << i << "\n";
//    return 0;
//}

/* NC235745 拆路 */ 
/* 2024.3.21 避免删边（精）*/
////map存下边，将操作从后向前遍历
////WA 用g并图时用了x，y
//#include<bits/stdc++.h>
//using namespace std;
//#define PII pair<int,int>
//const int N = 1e5 + 10;
//int v[N]
//set<PII> g;
//vector<PII> op; //-1表示Q
//vector<int> ans;
//int fa[N];
//int find(int x) {
//    if (fa[x] != x) fa[x] = find(fa[x]);
//    return fa[x];
//}
//
//int main() {
//    ios::sync_with_stdio(0);
//    int n, m;cin >> n >> m;
//    for (int i = 1; i <= n; i++) cin >> v[i];
//    for (int i = 1; i <= m; i++) {
//        int a, b;cin >> a >> b;
//        g.insert({ a,b });
//    }
//    int qq; cin >> qq;
//    while (qq--) {
//        char opt; int x, y;
//        cin >> opt;
//        if (opt == 'Q') {
//            cin >> x;
//            op.push_back({ x,-1 });
//        }
//        else {
//            cin >> x >> y;
//            op.push_back({ x,y });
//            g.erase({ x,y });
//            g.erase({ y,x });//a-b和b-a是同一条边，可能mp中只存了a-b或者只存了b-a。
//        }
//    }
//    for (int i = 1; i <= n; i++) {
//        fa[i] = i;
//    }
//    for (auto t : g) {
//        int x = t.first;
//        int y = t.second;
//        int fx = find(x);
//        int fy = find(y);
//        if (v[fx] > v[fy]) {
//            fa[fy] = fx;
//        }
//        else fa[fx] = fy;
//    }
//    for (int i = op.size() - 1; i >= 0; i--) {
//        int x = op[i].first;
//        int y = op[i].second;
//        if (y == -1) {
//            int fx = find(x);
//            ans.push_back(v[fx]);
//        }
//        else {
//            int fx = find(x);
//            int fy = find(y);
//            if (v[fx] > v[fy]) {
//                fa[find(fy)] = fx;
//            }
//            else fa[find(fx)] = fy;
//        }
//    }
//    for (int i = ans.size() - 1; i >= 0; i--) {
//        cout << ans[i] << "\n";
//    }
//    return 0;
//}

/*[JSOI2010]GROUP 部落划分 GROUP */ //kursa

/*NC15121 Call to your teacher */
/* 2024.3.22 扩域表示方向（存疑）*/
//#include<bits/stdc++.h>
//using namespace std;
//int fa[60*2];
////有方向的图 x入 x+n出 
//int find(int x) {
//    return fa[x] == x ? x : fa[x] = find(fa[x]);
//}
//int main() {
//    int n, m;
//    while (cin >> n >> m) {
//        memset(fa, 0, sizeof fa);
//        for (int i = 1; i <= n*2; i++) {
//            fa[i] = i;
//        }
//        for (int i = 2; i < n; i++) { //只记中间传递的过程
//            fa[find(i)] = find(i + n); 
//        }
//        for (int i = 0; i < m; i++) {
//            int x, y;cin >> x >> y;
//            fa[find(x + n)] = find(y);
//        }
//        if (find(1+n) == find(n)) cout << "Yes\n";
//        else cout << "No\n";
//    }
//    return 0;
//}

