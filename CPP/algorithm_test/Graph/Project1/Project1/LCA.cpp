#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

//dfs序//

/*NC13611 树（dfs序+区间dp）(精)*/
/*2024.5.17 题解*/
////根据dfs序发现树的形态并不重要
////dp[i][j] //前i个节点涂了j种颜色
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 1e6 + 10;
//ll dp[310][310];
//int main() {
//	ios::sync_with_stdio(0);
//	int n, k;
//	cin >> n >> k;
//	int x, y;
//	for (int i = 1; i <= n - 1; i++)cin >> x >> y;
//	dp[0][0] = 1;
//	const int mod = 1e9 + 7;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= k; j++) {
//			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] * (k - j + 1);
//			dp[i][j] %= mod;
//		}
//	}
//	ll ans = 0;
//	for (int i = 1; i <= k; i++) {
//		ans += dp[n][i];
//		ans %= mod;
//	}
//	cout << ans << "\n";
//	return 0;
//}
//倍增//


//倍增//

/*倍增模板*/ //通过倍增将线性处理转化为对数级处理
////预处理o（nlogn） 查找logn
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 5e4 + 10;
//int depth[N];//节点的深度
//int fa[N / 2][N / 2];//节点i的第1<<j级祖先
//int lg[N];
////预处理出log2(i) + 1
//void getlg(int n) {
//	for (int i = 1; i <= n; i++) {
//		lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
//	}
//}
//
////dfs向下预处理
//void dfs(int now, int fath) { //当前节点与父亲节点
//	fa[now][0] = fath;
//	depth[now] = depth[fath] + 1;
//	for (int i = 1; i <= lg[depth[now]]; i++) {
//		//now的1<<i祖先 == now的1<<i-1祖先的1<<i-1祖先
//		fa[now][i] = fa[fa[now][i - 1]][i - 1];
//	}
//	for (int i = head[now]; i; i = e[i].next) {
//		if (e[i].v != fath) dfs(e[i].v, now);
//	}
//}
//
//int LCA(int x, int y) {
//	//设置深度x>=深度y
//	if (depth[x] < depth[y]) swap(x, y);
//	//x跳到与y同一深度
//	while (depth[x] > depth[y]) {
//		x = fa[x][lg[depth[x] - depth[y]] - 1];
//	}
//	//y是x的祖先
//	if (x == y) return y;
//	for (int k = lg[depth[x]] - 1; k >= 0; k--) {
//		if (fa[x][k] != fa[x][k]) {//不相等，往上跳
//			x = fa[x][k];
//			y = fa[y][k];
//		}
//	}
//	return fa[x][0]; //返回父节点
//}

/*luogu P3379 【模板】最近公共祖先（LCA）*/
/*2024.5.14*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//int n, m, s;
//const int N = 5e5 + 10;
//int head[N];
//int cnt = 0;
//struct{
//	int v, next;
//}e[N << 1];
//
//void add(int u,int v) {
//	cnt++;
//	e[cnt].v = v;
//	e[cnt].next = head[u];
//	head[u] = cnt;
//}
//
//int lg[N];
//void getlg() {
//	for (int i = 1; i <= n; i++) {
//		lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
//	}
//}
//int fa[N][30];
//int depth[N];
//void dfs(int s,int f) {
//	fa[s][0] = f;
//	depth[s] = depth[f] + 1;
//	for (int i = 1; i <= lg[depth[s]]; i++) {
//		fa[s][i] = fa[fa[s][i - 1]][i - 1];
//	}
//	for (int i = head[s]; i; i = e[i].next) {
//		if (e[i].v != f) dfs(e[i].v, s);
//	}
//}
//
//int LCA(int x, int y) {
//	if (depth[x] < depth[y]) swap(x, y);
//	while (depth[x] > depth[y]) {
//		x = fa[x][lg[depth[x] - depth[y]] - 1];
//	}
//	if (x == y) return y;
//	for (int k = lg[depth[x]] - 1; k >= 0; k--) {//lg是常数优化
//		if (fa[x][k] != fa[y][k]) {
//			x = fa[x][k];
//			y = fa[y][k];
//		}
//	}
//	return fa[x][0];
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> m >> s;
//	for (int i = 1; i <= n-1; i++) {
//		int u, v;
//		cin >> u >> v;
//		add(u, v);
//		add(v, u);
//	}
//	getlg();
//	dfs(s,0);
//	while (m--) {
//		int a, b;cin >> a >> b;
//		cout << LCA(a, b) << "\n";
//	}
//	return 0;
//}
/*2024.5.17*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//int n, m, s;
//const int N = 5e5 + 10;
//int head[N];
//int cnt = 0;
//struct {
//	int v, next;
//}node[N << 1];
//
//int lg[N];
//void getlg(int n) {
//	for (int i = 1; i <= n; i++) {
//		lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
//	}
//}
//
//void add(int x, int y) {
//	cnt++;
//	node[cnt].v = y;
//	node[cnt].next = head[x];
//	head[x] = cnt;
//}
//int depth[N],fa[N][30];
//void dfs(int s, int f) {
//	fa[s][0] = f;
//	depth[s] = depth[f] + 1;
//	for (int i = 1; i <= lg[depth[s]]; i++) {
//		fa[s][i] = fa[fa[s][i - 1]][i - 1];
//	}
//	for (int i = head[s]; i; i = node[i].next) {
//		if (node[i].v != f) dfs(node[i].v, s);
//	}
//}
//
//int find(int x,int y) {
//	if (depth[x] < depth[y]) swap(x, y);
//	while (depth[x] > depth[y]) {
//		x = fa[x][lg[depth[x] - depth[y]]-1];
//	}
//	if (x == y) return y;
//	for (int i = lg[depth[x]] - 1; i >= 0; i--) {
//		if (fa[x][i] != fa[y][i]) {
//			x = fa[x][i];
//			y = fa[y][i];
//		}
//	}
//	return fa[x][0];
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> m >> s;
//	for (int i = 1; i <= n - 1; i++) {
//		int x, y;cin >> x >> y;
//		add(x, y);
//		add(y, x);
//	}
//	getlg(n);
//	dfs(s, 0);
//	while (m--) {
//		int a, b;cin >> a >> b;
//		cout << find(a, b) << "\n";
//	}
//	return 0;
//}

/*NC16527 货车运输*/ //恶心
/*2024.5.17 UF*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//int n, m;
//const int N = 1e5 + 10;
//const int NN = 5e5 + 10;
//int head[N];
//int cnt = 0;
//struct{
//	int next,v, w;
//}node[NN << 1];
//struct {
//	int x, y, z;
//}e[NN];
//void add(int u,int v,int w) {
//	cnt++;
//	node[cnt].v = v;
//	node[cnt].w = w;
//	node[cnt].next = head[u];
//	head[u] = cnt;
//}
//int fi[N];
//bool st[NN]; //存在于最大生成树的边
//int find(int x) {
//	return fi[x] == x ? x : fi[x] = find(fi[x]);
//}
//
//void kruskal() {
//	for (int i = 1; i <= n; i++) {
//		fi[i] = i;
//	}
//	for (int i = 0; i < m; i++) {
//		int x = find(e[i].x);
//		int y = find(e[i].y);
//		if (x != y) {
//			fi[x] = y;
//		}
//	}
//}
//bool st[N];
//int depth[N];
//int fa[N][30];
//int lg[N];
//void getlg(int n) {
//	for (int i = 1; i <= n; i++) {
//		lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
//	}
//}
//void dfs(int x, int y) {
//	if (st[x])return;
//	st[x] = 1;
//	depth[x] = y;
//	for (int i = head[x]; i; i = node[i].next) {
//		int pos = node[i].v;
//		if (pos = fa[x][0]) continue;
//		fa[pos][0] = x;
//		depth[pos] = depth[x] + 1;
//
//	}
//}
//
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> m;
//	for (int i = 0; i < m; i++) {
//		int x, y, z;cin >> x >> y >> z;
//		e[i] = { x,y,z };
//		add(x, y, z);
//		add(y, x, z);
//	}
//	sort(e, e + m, [](auto x, auto y) {
//		return x.z > y.z;
//		});
//	kruskal();
//	getlg(n);
//	int q;cin >> q;
//
//	return 0;
//}
/*2024.5.27*/
// //问题：
// //1.怎么进行dfs（根未知）
// //2.怎么查找的过程中更新ans
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// int n, m;
// const int N = 1e5 + 10;
// const int M = 5e5 + 10;
// int fi[N];
// int head[M<<2];
// int cnt = 0;
// struct {
//     int x, y, z;
// }e[M<<2];
// struct{
//     int next,v,w,flag;
// } node[M << 2];
// int depth[N];
// int fa[N][30];
// int find(int x){
//     return fi[x] == x ? x : fi[x] = find(fi[x]);
// }
// void init1(){
//     for (int i = 1; i <= n; i++)
//         fi[i] = i;
// }
// void add(int u,int v,int w){
//     cnt++;
//     node[cnt].v = v;
//     node[cnt].w = w;
//     node[cnt].next = head[u];
//     head[u] = cnt;
//     node[cnt].flag = 1;
// }
// void kruskal(){
//     init1();
//     sort(e + 1, e + 1 + m, [](auto x, auto y) {    
//         return x.z > y.z; 
//     });
//     for (int i = 1; i <= m; i++){
//         int x = find(e[i].x);
//         int y = find(e[i].y);
//         if(x != y){
//             fi[x] = y;
//             add(e[i].x, e[i].y, e[i].z);
//             add(e[i].y, e[i].x, e[i].z);
//         }
//     }
// }
// int lg[N];
// int val[N][30];
// void getlg(){
//     for (int i = 1; i <= n; i++){
//         lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
//     }
// }
// void dfs(int s,int f,int w){
//     if(fa[s][0]) return; //奇怪，怎么会走个环出来
//     fa[s][0] = f;
//     val[s][0] = w;
//     depth[s] = depth[f] + 1;
//     for (int i = 1; i <= lg[depth[s]]; i++){
//         fa[s][i] = fa[fa[s][i - 1]][i - 1];
//         val[s][i] = min(val[s][i - 1], val[fa[s][i - 1]][i - 1]);
//     }
//     for (int i = head[s]; i; i = node[i].next){
//         if(node[i].flag == 0) continue;
//         int pos = node[i].v;
//         if(pos != f)
//             dfs(pos, s, node[i].w);
//     }
// }

// int search(int x,int y){
//     int ans = 0x3f3f3f3f;
//     if(depth[x] < depth[y])
//         swap(x, y);
//     while(depth[x] > depth[y]){
//         ans = min(ans, val[x][lg[depth[x] - depth[y]] - 1]);
//         x = fa[x][lg[depth[x] - depth[y]] - 1];
//     }
//     if(x == y)
//         return ans;
//     for (int k = lg[depth[x]] - 1; k >= 0; k--){
//         if(fa[x][k] != fa[y][k]){
//             ans = min(ans, val[x][k]);
//             ans = min(ans, val[y][k]);
//             x = fa[x][k];
//             y = fa[y][k];
//         }
//     }
//     ans = min({ans,val[x][0],val[y][0]});
//     return ans;
// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n >> m;
//     for (int i = 1; i <= m; i++){
//         int x, y, z;
//         cin >> x >> y >> z;
//         e[i] = {x, y, z};
//     }
//     kruskal();
//     getlg();
//     int q;
//     cin >> q;
//     while(q--){
//         //cout << "#cnt " << cnt << "\n";
//         int x, y;
//         cin >> x >> y;
//         if(find(x) != find(y)){
//             cout << -1 << "\n";
//             continue;
//         }
//         dfs(1, 0, 0);
//         int ans = search(x, y);
//         cout << ans << "\n";
//     }
//     return 0;
// }

/*2024.5.28 题解*/
// //WA：lca有问题？!
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
////
// const int N = 1e5 + 10;
// const int M = 5e5 + 10;
// int n, m, q;
// struct {
//     int u, v, w, next, flag; 
//     //u和flag？ flag表示能不能走，u方便并查集
// }e[M<<2];
// int cnt = 0;
// int head[M << 1];
// void add1(int u,int v,int w){
//     e[++cnt].u = u;
//     e[cnt].v = v;
//     e[cnt].w = w;
//     e[cnt].next = head[u];
//     e[cnt].flag = 0;
//     head[u] = cnt;
// }
// void add2(int u,int v,int w){
//     e[++cnt].u = u;
//     e[cnt].v = v;
//     e[cnt].w = w;
//     e[cnt].flag = 1;
//     e[cnt].next = head[u];
//     head[u] = cnt;
// }
// int fi[N];
// int find(int x){
//     return fi[x] == x ? x : fi[x] = find(fi[x]);
// }
// int dep[N], fa[N][30], g[N][30],lg[N];
// void getlg(){
//     for (int i = 1; i <= n; i++){
//         lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
//     }
// }
// //dfs
// void dfs(int s,int f,int w){
//     dep[s] = dep[f] + 1;
//     fa[s][0] = f;
//     g[s][0] = w;
//     //cout << lg[dep[s]] << "\n";
//     for (int i = 1; i <= lg[dep[s]]; i++){
//         fa[s][i] = fa[fa[s][i - 1]][i - 1];
//         g[s][i] = min(g[s][i - 1], g[fa[s][i - 1]][i - 1]);
//         //cout << "G " << g[s][i] << " ";
//     }
//     //cout << "\n";
//     for (int i = head[s]; i; i = e[i].next){
//         if(e[i].flag == 0) continue;
//         int v = e[i].v, w = e[i].w;
//         if(v == f) continue;
//         dfs(v, s, w);
//     }
// }
// //LCA
// int lca(int a,int b){
//     if(dep[a] < dep[b]) swap(a,b);
//     int ans = 0x3f3f3f3f;
//     while(dep[a] > dep[b]){
//         ans = min(ans, g[a][lg[dep[a] - dep[a]]-1]);
//         a = fa[a][lg[dep[a] - dep[b]] - 1];
//         //cout << " ans1 " << ans;
//     }
//     if(a == b)
//         return ans;
//     for (int k = lg[dep[a]]-1; k >= 0; k--){
//         if(fa[a][k] != fa[b][k]){
//             ans = min({ans, g[a][k], g[b][k]});
//             a = fa[a][k];
//             b = fa[b][k];
//             //cout << " ans2 " << ans;
//         }
//     }
//     ans = min({ans, g[a][0], g[b][0]});
//    // cout << " ans2 " << ans;
//     return ans;
// }
// // int lca(int a, int b)
// // {
// //     if (dep[a] > dep[b])
// //         swap(a, b);
// //     int ans = 2e9;
// //     for (int i = dep[b] - dep[a], j = 0; i; i >>= 1, j++)
// //         if (i & 1)
// //         {
// //             ans = min(ans, g[b][j]);
// //             b = fa[b][j];
// //         }
// //     if (a == b)
// //         return ans;
// //     int k;
// //     for (k = 0; (1 << k) < dep[a]; k++)
// //         ;
// //     for (; k >= 0; k--)
// //         if ((1 << k) < dep[a] && fa[a][k] != fa[b][k])
// //         {
// //             ans = min({ans, g[a][k], g[b][k]});
// //             a = fa[a][k];
// //             b = fa[b][k];
// //         }
// //     ans = min({ans, g[a][0], g[b][0]});
// //     return ans;
// // }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n >> m;
//     for (int i = 1; i <= m; i++){
//         int u, v, w;
//         cin >> u >> v >> w;
//         add1(u, v, w);
//     }
//     sort(e + 1, e + 1 + m, [](auto x, auto y){ 
//         return x.w > y.w; 
//     });
//     for (int i = 1; i <= n; i++)
//         fi[i] = i;
//     //kruskal
//     for (int i = 1; i <= m; i++){
//         int u = e[i].u, v = e[i].v, w = e[i].w;
//         int x = find(u), y = find(v);
//         if(x != y){
//            // cout << "add\n";
//             fi[x] = y;
//             add2(u, v, w);
//             add2(v, u, w);
//         }
//     }
//     getlg();
//     dfs(1, 0, 0);
//     cin >> q;
//     //cout << "%cnt " << cnt << "\n";
//     while(q--){
//         int a,b;
//         cin >> a >> b;
//         if(find(a) != find(b)){
//             cout << -1 << "\n";
//             continue;
//         }
//         else
//             cout << lca(a, b) << "\n";
//     }
//     return 0;
// }

