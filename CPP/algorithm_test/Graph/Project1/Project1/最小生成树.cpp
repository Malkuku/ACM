#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*luogu P3366 【模板】最小生成树 */ 
/*kruskal*/ //并查集 时间复杂度 ElogE //E-边数 
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 2e5 + 10;
//struct{
//	int x, y;
//	int cost;
//}node[N];
//int fa[N]; //并查集
//int cnt = 0;//记录边数
//ll ans = 0;
//int n, m;
//int find(int x) {
//	return fa[x] == x ? x : fa[x] = find(fa[x]);
//}
//void krus() {
//	//初始化
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//	}
//	//遍历边
//	for (int i = 0; i < m; i++) {
//		int x = find(node[i].x);
//		int y = find(node[i].y);//找父根
//		if (x == y) continue;
//		fa[x] = y; //并入集合
//		cnt++;
//		ans += node[i].cost; //累加边权
//		if (cnt == n - 1) break;
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> m;
//	//读入
//	for (int i = 0; i < m; i++) {
//		int x, y, z;
//		cin >> x >> y >> z;
//		node[i] = { x,y,z };
//	}
//	//按边权排序
//	sort(node, node + m, [](auto x, auto y) {
//		return x.cost < y.cost;
//		});
//	krus();
//	if (cnt == n - 1) cout << ans << "\n";
//	else cout << "orz\n";
//	return 0;
//}
/*prim*/ //类dijkstra 时间复杂度 V^2 //V-点数 
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 2e5 + 10;
//const int INF = 0x3f3f3f3f;
//int n, m;
//int res = 0; //记录树的边数
//bool st[N]; //记录该点是否已经加入树
//int dis[N];//到i点的距离
//struct {
//	int v, w, next;
//}edge[N*2]; //无向边记得开两倍大小 （我就忘记了）
////建图
//int cnt = 0;//记录边数
//int head[N];
//void add(int u,int v,int w) {
//	cnt++;//将0作为空边
//	edge[cnt].v = v;
//	edge[cnt].w = w;
//	edge[cnt].next = head[u];
//	head[u] = cnt;
//}
//ll ans = 0;
//void prim() {
//	dis[1] = 0;//起始边
//	//从小排列优先队列
//	priority_queue<PII, vector<PII>, greater<PII>> q;
//	q.push({ dis[1],1 });
//	while (q.size() && res < n) {
//		auto t = q.top();
//		q.pop();
//		int cost = t.first;
//		int pos = t.second;
//		if (st[pos]) continue;
//		res++;//累加边
//		ans += cost; //累加答案
//		st[pos] = 1;
//		//遍历pos链接边
//		for (int i = head[pos]; i; i = edge[i].next) {
//			int w = edge[i].w;
//			int v = edge[i].v;
//			if (w < dis[v]) {
//				dis[v] = w;
//				q.push({dis[v],v});
//			}
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++) {
//		int x, y, z;
//		cin >> x >> y >> z;
//		add(x, y, z);
//		add(y, x, z);
//	}
//	memset(dis, INF, sizeof dis);
//	prim();
//	if (res == n) cout << ans << "\n"; //遍历时是到n结束的
//	else cout << "orz\n";
//	return 0;
//}

/*NC17509 挖沟*/
/*2024.5.10*/
//WA：经典忘记开俩倍大小
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 5e5 + 10;
//int head[N];
//int cnt = 0;
//struct {
//	int v, w, next;
//}node[N*2];
//bool st[N];
//priority_queue<PII,vector<PII>,greater<PII>> q;
//ll dis[N];
//ll ans = 0;
//ll res = 0;
//int n, m;
//void add(int u,int v,int w) {
//	cnt++;
//	node[cnt].v = v;
//	node[cnt].w = w;
//	node[cnt].next = head[u];
//	head[u] = cnt;
//}
//void prim() {
//	dis[1] = 0;
//	q.push({dis[1],1});
//	while (q.size() && res < n) {
//		auto t = q.top();q.pop();
//		int cost = t.first;
//		int pos = t.second;
//		if (st[pos]) continue;
//		st[pos] = 1;
//		ans += cost;
//		res++;
//		for (int i = head[pos]; i; i = node[i].next) {
//			int v = node[i].v;
//			int w = node[i].w;
//			if (w < dis[v]) {
//				dis[v] = w;
//				q.push({ w,v });
//			}
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> m;
//	memset(dis, 0x3f3f3f3f, sizeof dis);
//	for (int i = 1; i <= m; i++) {
//		int u, v, w;cin >> u >> v >> w;
//		add(u, v, w);
//		add(v, u, w);
//	}
//	prim();
//	if (res == n) cout << ans << "\n";
//	else while (1);
//	return 0;
//}

/*NC15108 道路建设*/
/*kruskal 2024.5.10*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 1e5 + 10;
//int fa[N];
//int find(int x) {
//	return fa[x] == x ? x : fa[x] = find(fa[x]);
//}
//struct {
//	int u, v, w;
//}node[N];
//int c,n, m;
//ll ans = 0;
//int res = 0;
//void krus() {
//	for (int i = 1; i <= m; i++) {
//		fa[i] = i;
//	}
//	for (int i = 0; i < n; i++) {
//		int x = find(node[i].u);
//		int y = find(node[i].v);
//		if (x == y) continue;
//		fa[x] = y;
//		res++;
//		ans += node[i].w;
//		if (res == m - 1) return;
//	}
//}
//int main() {
//	cin >> c >> n >> m;
//	for (int i = 0; i < n; i++) {
//		int x, y, h;
//		cin >> x >> y >> h;
//		node[i] = { x,y,h };
//	}
//	sort(node, node + n, [](auto x, auto y) {
//		return x.w < y.w;
//		});
//	krus();
//	if (res == m - 1 && ans <= c) cout << "Yes\n";
//	else cout << "No\n";
//}

/*NC53074 Forsaken喜欢独一无二的树*/
/*题解 唯一的最小生成树*/
////删去权重相同的边
////WA:没开longlong
////WA: 滑窗的细节不对
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//const int N = 2e5 + 10;
//int fa[N];
//int find(int x) {
//	return fa[x] == x ? x : fa[x] = find(fa[x]);
//}
//
//struct {
//	int x, y, z;
//}node[N];
//int n, m;
//int res = 0;
//ll ans = 0;
//void krus() {
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//	}
//	sort(node, node + m, [](auto x, auto y) {
//		return x.z < y.z;
//		});
//	for (int i = 0; i < m; i++) {
//		int l = i, r = i;
//		while (r < m && node[l].z == node[r + 1].z) r++;
//		//删去相同权重的边
//		for (int j = l; j <= r; j++) {
//			int x = find(node[j].x);
//			int y = find(node[j].y);
//			if (x != y) ans += node[j].z;
//		}
//		//如果这个边是构建最小生成树必须的，则加入他
//		for (int j = l; j <= r; j++) {
//			int x = find(node[j].x);
//			int y = find(node[j].y);
//			if (x != y) {
//				ans -= node[j].z;
//				fa[x] = y;
//			}
//		}
//		i = r;
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> m;
//	for (int i = 0; i < m; i++) {
//		int x, y, z;
//		cin >> x >> y >> z;
//		node[i] = { x,y,z };
//	}
//	krus();
//	cout << ans << "\n";
//	return 0;
//}

/*NC20568 [SCOI2012] 滑雪与时间胶囊*/ //附加条件的生成树
/*题解 kruskal*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//int n, m;
//const int N = 1e6 + 10;
//ll h[N];
//bool st[N]; //从1可以到达的点
//int head[N];
//int cnt = 0;
//struct {
//	int v, w,next;
//}node[N*2];
//
//struct node2{
//	ll x, y, z, h;
//};
//vector<node2> arr;
//void add(int u,int v,int w) {
//	cnt++;
//	node[cnt].v = v;
//	node[cnt].w = w;
//	node[cnt].next = head[u];
//	head[u] = cnt;
//}
//
//void bfs() {
//	queue<int> q;
//	q.push(1);
//	while (q.size()) {
//		int pos = q.front();
//		q.pop();
//		if (st[pos]) continue;
//		st[pos] = 1;
//		for (int i = head[pos]; i; i = node[i].next) {
//			int p = node[i].v;
//			ll high = h[p];
//			if ( h[p] > h[pos]) continue;
//			q.push(p);
//			arr.push_back({ pos,p,node[i].w,h[p] });
//		}
//	}
//}
//int fa[N];
//int find(int x) {
//	return fa[x] == x ? x : fa[x] = find(fa[x]);
//}
//ll ans = 0;
//ll sum = 1;
//void krus() {
//	sort(arr.begin(), arr.end(), [](auto x, auto y) {
//		if (x.h != y.h) return x.h > y.h;
//		else return x.z < y.z;
//		});
//	for (int i = 1; i <= n; i++) {
//		fa[i] = i;
//	}
//	int res = 0;
//	for (int i = 0; i < arr.size(); i++) {
//		int x = find(arr[i].x);
//		int y = find(arr[i].y);
//		if (x == y) continue;
//		fa[x] = y;
//		ans += arr[i].z;
//		sum++;
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) cin >> h[i];
//	for (int i = 1; i <= m; i++) {
//		int u, v, w;cin >> u >> v >> w;
//		add(u, v, w);
//		add(v, u, w);
//	}
//	bfs();
//	krus();
//	cout << sum << " " << ans << "\n";
//	return 0;
//}