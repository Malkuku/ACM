#define _CRT_SECURE_NO_WARNINGS 1

///*NC17511 公交线路*/ //最短路 dijkstra
/*2024.2.23 自己尝试写的邻接表*/
////WA:可能会给一条重复但更短的道路
////根本上做法存在问题，因为这题有边权
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<algorithm>
//#include<vector>
//#include<queue>
//#include<map>
//using namespace std;
//#define PII pair<int,int>
//struct Node{
//	int to;
//	int w;
//};
//int dist[20010];
//priority_queue<PII, vector<PII>, greater<PII>> pq;//定义小端堆
//int s, t, n, m;
//vector<Node> node[1010];
//map<pair<int, int>, bool> g;
//void bfs() {
//	pq.push({ 0,s });
//	dist[s] = 0;
//	while (pq.size()) {
//		auto t = pq.top();
//		pq.pop();
//		int pos = t.second;
//		for (auto t : node[pos]) {
//			int to = t.to;
//			int w = t.w;
//			if (dist[pos] + w < dist[to]) {
//				dist[to] = dist[pos] + w;
//				pq.push({ dist[to],to });
//			}
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	memset(dist, 0x3f,sizeof dist);
//	cin >> n >> m;
//	cin >> s >> t;
//	for (int i = 0; i < m; i++) {
//		int a, b, v;
//		cin >> a >> b >> v;
//		node[a].push_back({ b,v });
//		node[b].push_back({ a,v });
//	}
//	bfs();
//	if (dist[t] == 0x3f3f3f3f) cout << -1 << "\n";
//	else cout << dist[t] << "\n";
//	return 0;
//}
/*2024.2.24 链式前向星*/
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<algorithm>
//#include<vector>
//#include<queue>
//#include<map>
//using namespace std;
//#define PII pair<int,int>
//struct edge{
//	int to;
//	int w;
//	int next;
//}node[20010];
//int head[20010];
//int dist[20010];
//priority_queue<PII, vector<PII>, greater<PII>> pq;//定义小端堆
//int s, t, n, m;
//map<pair<int, int>, bool> g;
//int cnt = 1;
//void bfs() {
//	pq.push({ 0,s });
//	dist[s] = 0;
//	while (pq.size()) {
//		auto t = pq.top();
//		pq.pop();
//		int pos = t.second;
//		for (int i = head[pos]; i != -1; i = node[i].next) {
//			int to = node[i].to;
//			int w = node[i].w;
//			if (dist[pos] + w < dist[to]) {
//				dist[to] = dist[pos] + w;
//				pq.push({ dist[to],to });
//			}
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	memset(dist, 0x3f,sizeof dist);
//	memset(head, -1, sizeof head);
//	cin >> n >> m;
//	cin >> s >> t;
//	for (int i = 0; i < m; i++) {
//		int a, b, v;
//		cin >> a >> b >> v;
//		node[cnt].next = head[a];
//		node[cnt].to = b;
//		node[cnt].w = v;
//		head[a] = cnt++;
//		node[cnt].next = head[b];
//		node[cnt].to = a;
//		node[cnt].w = v;
//		head[b] = cnt++;
//	}
//	bfs();
//	if (dist[t] == 0x3f3f3f3f) cout << -1 << "\n";
//	else cout << dist[t] << "\n";
//	return 0;
//}
/*2024.2.24 邻接矩阵*/
////由于本题的点范围较小，且无向图性质，比较适合邻接矩阵
////ps:今天太累了，没有完全自己重新写一遍
////注意重复路径邻接矩阵要取短的一条
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1010;
//int a[N][N];
//int dist[N];
//bool vis[N];
//
//int n, m, s, t;
//int x, y, v;
//void bfs() {
//	dist[s] = 0;//保证了第一个x是s，也就是从s到t的dist路径
//	for (int i = 1; i <= n; i++) {//一共进行n-1次这样的操作(最坏遍历情况是s->2->3->4->...->t)
//		int x = 0;//x必须从0开始，                                
//		int y;
//		for (int j = 1; j <= n; j++) {//相当于我每次从1-n中取一个对应最短路径的x(模拟了优先队列)
//			//x不会重复，且会从上一个x的链接点中选取
//			if (!vis[j] && (x == 0 || dist[j] < dist[x]))//x == 0无法跳过
//			{
//				x = j;
//			}
//		}
//		vis[x] = 1;
//		for (int j = 1; j <= n; j++) {//以这个x点，优化所有链接点
//			dist[j] = min(dist[j], dist[x] + a[x][j]);
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	memset(dist, 0x3f, sizeof dist);
//	memset(a, 0x3f, sizeof a);
//	cin >> n >> m >> s >> t;
//	for (int i = 1;i <= n;i++) a[i][i] = 0;//主对角线自己到自己的距离为0
//	for (int i = 0; i < m; i++) {
//		cin >> x >> y >> v;
//		if (a[x][y] < 0x3f3f3f3f) {
//			a[x][y] = min(a[x][y], v);
//			a[y][x] = min(a[y][x], v);
//		}
//		else {
//			a[x][y] = v;
//			a[y][x] = v;
//		}
//	}
//	bfs();
//	if (dist[t] == 0x3f3f3f3f) cout << -1 << "\n";
//	else cout << dist[t] << "\n";
//	return 0;
//}

/*NC22594 Rinne Loves Graph*/ //有限次数的最短路 //无向图
/*2024.2.24 邻接表*/
////longlong 警告
////如果在一条路径上戒严点超过上限，就不再走
////WA: 取数时忘记弹出pq了
////WA：推测是过戒严点的数的计算有问题
////我总觉得这样写会有问题
////WA：不用longlong（最坏800*1e6），而且这样最后不能用0x3f3f3f3f判断
////这个方法确实有问题(已修改)
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<queue>
//#include<vector>
//#include<map>
//using namespace std;
//#define PII pair<int,int>
//#define ll long long
//const int maxn = 810;
//const int maxm = 4010*2;
//int n, m, k;
//int dist[maxn];
//int st[maxn];//到i点已经积累的戒严点
//struct Node {
//	int to;
//	int w;
//};
//bool warn[maxn];//i点是否为戒严点
//vector<Node> node[maxn];
//void dijk() {
//	priority_queue < PII, vector<PII>, greater<PII>> pq;
//	pq.push({ 0, 1 });
//	dist[1] = 0;
//	st[1] = warn[1] ? 1 : 0;
//	warn[n] = 0;//我们不需要再通过n前往任何地方，warn[n] = 1反而会影响到答案的判断
//	while (pq.size()) {
//		auto t = pq.top();
//		pq.pop();
//		int pos = t.second;
//		for (int i = 0; i < node[pos].size(); i++) {
//			int to = node[pos][i].to;
//			int w = node[pos][i].w;
//			if (dist[to] <= dist[pos] + w) continue;
//			if (st[pos] + warn[to] > k) continue;//通过这个点还有没有向下走的可能
//			//if (st[pos] > k) continue; //一开始用到判断方法
//			dist[to] = dist[pos] + w;
//			st[to] = st[pos] + warn[to];
//			pq.push({ dist[to],to });
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	memset(dist, 0x3f, sizeof dist);
//	cin >> n >> m >> k;
//	for (int i = 1; i <= n; i++) {
//		cin >> warn[i];
//	}
//	for (int i = 1; i <= m; i++) {
//		int u, v, w;
//		cin >> u >> v >> w;
//		node[u].push_back({ v,w });
//		node[v].push_back({ u,w });
//	}
//	dijk();
//	if (dist[n] == 0x3f3f3f3f) cout << -1 << "\n";
//	else cout << dist[n] << "\n";
//	return 0;
//}
///* 补充测试用例
//5 5 2
//1 1 1 0 1
//1 2 5
//1 4 10
//2 3 5
//4 3 10
//3 5 0
//1->4->3->5是一条有效路径，但不是无视k下的最短路
//1->2->3->5是最短路，但不满足题目对k的限制
//*/

/*NC208246 胖胖的牛牛*/
/*2024.3.11 01队列 WA*/ //能用优先尽量用优先吧， 用dist判断的时候要小心
////拐弯的定义记录x，y的变化，如果发生改变放在1
//#include<bits/stdc++.h>
//using namespace std;
//#define PII pair<int,int>
//
//struct node{
//	int x;
//	int y;
//	int xy; // 1 x 2 y
//};
//
//char g[110][110];
//int dist[110][110];
//bool st[110][110];
//int n;
//int sx, sy;
//int fx, fy;
//int dx[] = { 0,-1,0,1 };
//int dy[] = { 1,0,-1,0 };
//
//void bfs(int ssx,int ssy,int way) {
//	deque<node> dq;
//	memset(dist, 0x3f, sizeof dist);
//	memset(st, 0, sizeof st);
//	dq.push_back({ ssx,ssy,way});
//	dist[ssx][ssy] = 0;
//
//	while (dq.size()) {
//		auto t = dq.front();
//		dq.pop_front();
//		int x = t.x;
//		int y = t.y;
//		int xy = t.xy;
//		st[x][y] = 1;
//		for (int i = 0; i < 4; i++) {
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//			if (xx < 1 || yy < 1 || xx > n || yy > n) continue;
//			if (st[xx][yy] || g[xx][yy] == 'x') continue;
//			if (((xy == 1 && dx[i]) || (xy == 2 && dy[i]))) {
//				dist[xx][yy] = dist[x][y];
//				dq.push_front({ xx,yy,xy});
//			}
//			else{
//				dist[xx][yy] = dist[x][y] + 1;
//				dq.push_back({ xx,yy, xy == 1 ? 2 : 1 });
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> n;
//	for(int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++) {
//			cin >> g[i][j];
//			if (g[i][j] == 'A') {
//				sx = i; sy = j;
//			}
//			else if (g[i][j] == 'B') {
//				fx = i; fy = j;
//			}
//		}
//	}
//	int ans = 0x3f3f3f3f;
//	for (int i = 0; i < 4; i++) {
//		int ssx = sx + dx[i];
//		int ssy = sy + dy[i];
//		if (ssx < 1 || ssy < 1 || ssx > n || ssy > n || g[ssx][ssy] == 'x') continue;
//		int way = dx[i] ? 1 : 2;
//		bfs(ssx,ssy,way);
//		ans = min(ans, dist[fx][fy]);
//	}
//	if (ans == 0x3f3f3f3f) cout << -1 << "\n";
//	else cout << ans << "\n";
//	return 0;
//}
/*2024.3.11 题解 优先队列*/
//#include<bits/stdc++.h>
//using namespace std;
//const int maxn = 400;
//int head[maxn], mp[200][200], cnt, tx, ty, n, dis[maxn][maxn], vis[maxn][maxn];
//int d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };//0==下，1==上，2==右，3==左
//struct edge {
//    int nx, to, w;
//}e[6 * maxn];
//struct node {
//    int x, y, cost, dir;
//    friend bool operator  < (const node& a, const node& b) {
//        return a.cost > b.cost;
//    }
//};
//void dijstra(int sx, int sy, int dir)//dir表示前一个点从哪个方向到达该点
//{
//    priority_queue<node> q;
//    if (sx <= 0 || sy <= 0 || sx > n || sy > n || mp[sx][sy]) return;
//    dis[sx][sy] = 0;
//    q.push(node{ sx,sy,0,dir });
//    while (!q.empty())
//    {
//        node k = q.top();q.pop();
//        int x = k.x, y = k.y, di = k.dir;
//        if (vis[x][y]) continue;
//        vis[x][y] = 1;
//        for (int i = 0;i < 4;i++)
//        {
//            int dx = x + d[i][0], dy = y + d[i][1];
//            if (dx <= 0 || dy <= 0 || dx > n || dy > n) continue;
//            if (mp[dx][dy]) continue;
//            int c = 0;
//            if (di != i) c = 1;//根据贪心思想，不可能在往回走，所以直接判断即可
//            if (dis[dx][dy] > dis[x][y] + c) {
//                dis[dx][dy] = dis[x][y] + c;
//                q.push(node{ dx,dy,dis[dx][dy],i });
//            }
//        }
//    }
//}
//int main()
//{
//    int sx, sy;
//    memset(dis, 0x3f, sizeof(dis));
//    cin >> n;
//    for (int i = 1;i <= n;i++)
//    {
//        for (int j = 1;j <= n;j++)
//        {
//            char ch;
//            cin >> ch;
//            if (ch == 'A') sx = i, sy = j;
//            if (ch == 'B') tx = i, ty = j;
//            if (ch == 'x') mp[i][j] = 1;
//        }
//    }
//    int ans = 1e8;
//    for (int i = 0;i < 4;i++)
//    {
//        dijstra(sx + d[i][0], sy + d[i][1], i);//起点从四个方向分别开始
//        ans = min(ans, dis[tx][ty]);
//        memset(dis, 0x3f, sizeof(dis));
//        memset(vis, 0, sizeof(vis));
//    }
//    if (ans >= 0x3f) cout << -1 << endl;
//    else cout << ans << endl;
//}
/*2024.3.11 优先队列*/
//#include<bits/stdc++.h>
//using namespace std;
//int dx[] = { 0,1,0,-1 };
//int dy[] = { 1,0,-1,0 };
//const int N = 110;
//char g[N][N];
//int n;
//bool st[N][N];
//int fx, fy, sx, sy;
//struct Node {
//	int x, y;
//	int prex, prey;
//	int dis;//转弯次数
//	bool operator < (const Node& w) const {
//		return dis > w.dis;
//	}
//};
//
//int bfs() {
//	priority_queue<Node> q;
//	q.push({ sx,sy,sx,sy,0 });
//	st[sx][sy] = 1;//代表转弯的次数已经确定
//
//	while (q.size()) {
//		auto t = q.top();
//		q.pop();
//		int x = t.x;
//		int y = t.y;
//		if (x == fx && y == fy) return t.dis;
//		st[x][y] = 1;
//		for (int i = 0; i < 4; i++) {
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//			if (xx < 1 || yy < 1 || xx > n || yy > n) continue;
//			if (st[xx][yy] || g[xx][yy] == 'x') continue;
//			int add = 0;
//			if (t.prex != xx && t.prey != yy) add++;
//			q.push({ xx,yy,x,y,t.dis + add });
//		}
//	}
//	return -1;
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cin >> g[i][j];
//			if (g[i][j] == 'A') {
//				sx = i, sy = j;
//			}
//			else if (g[i][j] == 'B') {
//				fx = i, fy = j;
//			}
//		}
//	}
//	cout << bfs() << "\n";
//	return 0;
//}

/*NC236176 分层图最短路*/ //建图问题
/*2024.3.12 WA每一层之间的链接都要考虑到*/
////1）通过一个有点的最近层传送 2*cost
////2)两点在异层，直接传送 (!必须保证之间的所有层都有点)
////3）通过同一层的边过去
////WA: 还可以通过链接点传到上下层
//#include<bits/stdc++.h>
//using namespace std;
//#define PII pair<int,int>
//int n, m, cost;
//const int N = 1e5 + 10;
//bool ceng[N]; //是否存在第i层
//int cnt[N]; //第i个数在第几层
//struct Node {
//	int to;
//	int w = -1;
//};
//vector<Node> node[N];
//int qian[N] = { 0 };
//
//int dij() {
//	priority_queue<PII> q;
//	memset(qian, -1, sizeof qian);
//	q.push({ 0,1 });
//	qian[1] = 0;
//	while (q.size()) {
//		auto t = q.top();
//		q.pop();
//		int pos = t.second;
//		for (int i = 0; i < node[pos].size(); i++) {
//			int to = node[pos][i].to;
//			int w = node[pos][i].w;
//			if (w + t.first <= qian[to]) continue;
//			qian[to] = w + t.first;
//			q.push({ qian[to],to });
//		}
//	}
//	return qian[n];
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> m >> cost;
//	for (int i = 1; i <= n; i++) {
//		cin >> cnt[i];
//		ceng[cnt[i]] = 1;
//	}
//	for (int i = 1; i <= m; i++) {
//		int u, v, w;
//		cin >> u >> v >> w;
//		node[u].push_back({ v,w });
//		node[v].push_back({ u,w });
//	}
//	if (cnt[1] != cnt[n]) {
//		bool flag = 0;
//		int tmp1 = max(cnt[1], cnt[n]);
//		int tmp2 = min(cnt[1], cnt[n]);
//		for (int i = tmp2; i <= tmp1; i++) {
//			if (!ceng[i]) {
//				flag = 1;
//				break;
//			}
//		}
//		if (flag) cout << -1 << "\n";
//		else cout << cost * (tmp1 - tmp2);
//	}
//	else {
//		int ans1 = dij();
//		int ans2 = -1;
//		if (ceng[cnt[1] - 1] || ceng[cnt[1] + 1]) {
//			ans2 = cost * 2;
//		}
//		if (ans1 != -1 && ans2 == -1) cout << ans1 << "\n";
//		else if (ans2 != -1 && ans1 == -1) cout << ans2 << "\n";
//		else {
//			int ans = min(ans1, ans2);
//			cout << ans << "\n";
//		}
//	}
//
//	return 0;
//}
/*2024.3.13 题解（精） 哈希建图*/
////图论问题，通过不同层去建立不同层之间的连线，然后还有特殊连线。将图建立起来之后利用Dijkstra算法即可
////可以用hash去保存每个层里面的点编号，然后直接连线即可。
//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 1e5 + 10;
//int n, m, c;
////只用链式前向星存图
//struct sy {
//    int to;
//    int next;
//    int w;
//} edge[maxn * 10];
//int head[maxn * 10];
//int cnt = 0;
//struct Node {
//    int number;
//    int len;
//    bool operator < (const Node& n) const
//    {
//        return len > n.len;
//    }
//};
//priority_queue<Node> pq;
//int ans[maxn];
//int bianhao[maxn];
//bool vis[maxn];
//vector<int> mp[maxn];
//map<pair<int, int>, int> mpr;
//
//void add_edge(int x, int y, int w)
//{
//    edge[++cnt].next = head[x];
//    edge[cnt].to = y;
//    edge[cnt].w = w;
//    head[x] = cnt;
//}
//
//void Dijkstra(int bg)
//{
//    memset(ans, 127, sizeof(ans));
//    pq.push({ bg, 0 });
//    ans[bg] = 0;
//    while (pq.size())
//    {
//        int number = pq.top().number;
//        pq.pop();
//        if (vis[number]) continue;
//        //         cout<<"number="<<number<<endl;
//        vis[number] = true;
//        for (int i = head[number];i;i = edge[i].next)
//        {
//            int to = edge[i].to;
//            int w = edge[i].w;
//            if (ans[number] + w < ans[to])
//            {
//                ans[to] = ans[number] + w;
//                //                 cout<<"to="<<to<<" ans[to]="<<ans[to]<<endl;
//                pq.push({ to, ans[to] });
//            }
//        }
//    }
//    if (ans[n] >= 2139062143) cout << -1;
//    else
//        cout << ans[n];
//}
//
//int main()
//{
//    int x, y, w;
//    int l;
//    cin >> n >> m >> c;
//    for (int i = 1;i <= n;i++)
//    {
//        cin >> l;
//        mp[l].push_back(i);//？
//        bianhao[i] = l;//点i所在的层
//    }
//    //将层级之间连线
//    for (int i = 1;i <= n;i++)
//    {
//        int layer = bianhao[i];//该点到上下层的所有点连接上边权
//        for (int j = 0;j < mp[layer - 1].size();j++)
//        {
//            mpr[{i, mp[layer - 1][j]}] = c;
//        }
//        for (int j = 0;j < mp[layer + 1].size();j++)
//        {
//            mpr[{i, mp[layer + 1][j]}] = c;
//        }
//    }
//    //为额外的边建立
//    for (int i = 1;i <= m;i++)
//    {
//        cin >> x >> y >> w;
//        if (mpr[{x, y}] != 0)
//        {
//            mpr[{x, y}] = min(mpr[{x, y}], w); //改成最短路径
//        }
//        else
//        {
//            mpr[{x, y}] = w;
//        }
//        if (mpr[{y, x}] != 0)
//        {
//            mpr[{y, x}] = min(mpr[{y, x}], w);
//        }
//        else
//        {
//            mpr[{y, x}] = w;
//        }
//    }
//    //哈希存点与点的最短路径
//    //遍历边开始建图
//    map<pair<int, int>, int>::iterator it;
//    for (it = mpr.begin();it != mpr.end();it++)
//    {
//        //         cout<<(*it).first.first<<' '<<(*it).first.second<<endl;
//        add_edge((*it).first.first, (*it).first.second, (*it).second);
//    }
//    //由一个分层问题变成普通最短路问题
//    //开始迪杰斯特拉求最短路
//    Dijkstra(1);
//
//    return 0;
//}
/*2024.3.13*/
//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define PII pair<int,int>
//
//int n, m, c;
//const int N = 1e5 + 10;
//map<PII, int> gr;
//struct Node {
//	int to;
//	int w;
//	bool operator < (const Node& s)const {
//		return w > s.w;
//	}
//};
//priority_queue<Node> pq;
//vector<Node> node[N];
//vector<int> ceng[N];
//int hao[N];
//int dist[N]; //可能有回路
//int dij() {
//	memset(dist, 0x3f, sizeof dist);
//	pq.push({ 1,0 });
//	dist[1] = 0;
//	while (pq.size()) {
//		auto t = pq.top();
//		pq.pop();
//		int pos = t.to;
//		int cost = t.w;
//		if (pos == n) return cost;
//		for (int i = 0; i < node[pos].size(); i++) {
//			int to = node[pos][i].to;
//			int w = node[pos][i].w;
//			if (dist[to] <= w + cost) continue;
//			pq.push({ to,w + cost });
//			dist[to] = w + cost;
//		}
//	}
//	return -1;
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n >> m >> c;
//	for (int i = 1;i <= n; i++) {
//		int x; cin >> x;
//		ceng[x].push_back(i);
//		hao[i] = x;
//	}
//	for (int i = 1; i <= n; i++) {
//		int lou = hao[i];
//		for (int j = 0; j < ceng[lou - 1].size(); j++) {
//			gr[{i, ceng[lou - 1][j]}] = c;
//		}
//		for (int j = 0; j < ceng[lou + 1].size(); j++) {
//			gr[{i, ceng[lou + 1][j]}] = c;
//		}
//	}
//	for (int i = 1; i <= m; i++) {
//		int u, v, w;
//		cin >> u >> v >> w;
//		if (gr[{u, v}] != 0)gr[{u, v}] = min(gr[{u, v}], w);
//		else gr[{u, v}] = w;
//		if (gr[{v, u}] != 0)gr[{v, u}] = min(gr[{v,u}], w);
//		else gr[{v, u}] = w;
//	}
//	for (auto i : gr) {
//		int pos = i.first.first;
//		int to = i.first.second;
//		int cost = i.second;
//		node[pos].push_back({ to,cost });
//	}
//	int ans = dij();
//	cout << ans << "\n";
//	return 0;
//}

/*NC236210 传送门*/
/*2024.3.13 题解 加权排重(精)*/ //通过加点来处理重边问题
//直接考虑1，n到每个点的距离来处理双端
//#include<bits/stdc++.h>
//using namespace std;
//#define PII pair<int,int>
//const int N = 2e5 + 10, M = 2e6 + 01;
//int head[N], idx = 0;
//struct {
//	int to;
//	int w;
//	int next;
//}edge[M];
//int dist1[N], dist2[N];
//bool st[N];
//int n, m;
//void add_edge(int u,int v,int w){
//	edge[idx].next = head[u];
//	edge[idx].to = v;
//	edge[idx].w = w;
//	head[u] = idx++;
//	edge[idx].next = head[v];
//	edge[idx].to = u;
//	edge[idx].w = w;
//	head[v] = idx++;
//}
//void dij(int x, int* dist) {
//	memset(st, 0, sizeof st);
//	priority_queue<PII,vector<PII>,greater<PII>>pq;
//	pq.push({0,x});
//	dist[x] = 0;
//	while (pq.size()) {
//		auto t = pq.top();
//		pq.pop();
//		int pos = t.second;
//		int cost = t.first;
//		if (st[pos]) continue;
//		st[pos] = 1;
//		for (int i = head[pos]; i != -1; i = edge[i].next) {
//			int to = edge[i].to;
//			int w = edge[i].w;
//			if (dist[to] <= w + cost) continue;
//			dist[to] = w + cost;
//			pq.push({ dist[to],to });
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	memset(dist1, 0x3f, sizeof dist1);
//	memset(dist2, 0x3f, sizeof dist2);
//	memset(head, -1, sizeof head);
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++) {
//		int t, s;
//		cin >> t >> s;
//		for (int j = 1; j <= s; j++) {
//			int r; cin >> r;//从r到传送门类型i
//			add_edge(100000 + i, r, t);//加点去重，传送门的类型，距离翻倍
//		} //例：从1 -> 3 变成 1 -> 1 + w -> 3 //1e5是原点集的总数
//	}
//	dij(1, dist1);
//	dij(n, dist2);
//	int inf = 0x3f3f3f3f;
//	int ans = inf;
//	for (int i = 1; i <= n; i++) {
//		if (dist1[i] == inf || dist2[i] == inf) continue;
//		ans = min(ans, max(dist1[i], dist2[i]));
//	}
//	if (ans == inf) cout << -1 << "\n";
//	else {
//		cout << ans / 2 << "\n";
//		for (int i = 1; i <= n; i++) {
//			if (max(dist1[i], dist2[i]) == ans) {
//				cout << i << " ";
//			}
//		}cout << "\n";
//	}
//	return 0;
//}

/*NC25064 [USACO 2007 Mar G]Ranking the Cows*/

/*NC208252 瘦了的牛牛去旅游*/

/*NC19987 [HAOI2012]ROAD*/

/*NC16416 [NOIP2017]逛公园*/

/*NC20284 [SCOI2011]糖果*/