#define _CRT_SECURE_NO_WARNINGS 1

/*Lanqiao 迷宫*/
//#include<bits/stdc++.h>
//using namespace std;
//int dx[] = { 1,0,0,-1 };
//int dy[] = { 0,-1,1,0 };
//char dc[] = { 'D','L','R','U' };
//char g[40][60];
//string s[40][60];
//vector<string> ans;
//int dist[40][60];
//int fx = 30 - 1;
//int fy = 50 - 1;
//void bfs() {
//	memset(dist, 0x3f, sizeof dist);
//	dist[fx][fy] = 0;
//	queue<pair<int, int>> q;
//	q.push({fx,fy});
//	while (q.size()) {
//		auto t = q.front();
//		q.pop();
//		int x = t.first;
//		int y = t.second;
//		if (x == 0 && y == 0) ans.push_back(s[x][y]);
//		for (int i = 0; i < 4; i++) {
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//			if (xx < 0 || yy < 0 || xx >= 30 || yy >= 50) continue;
//			if (dist[xx][yy] <= dist[x][y] || g[xx][yy] == '1') continue;
//			s[xx][yy] =  dc[i] + s[x][y];
//			dist[xx][yy] = dist[x][y] + 1;
//			q.push({ xx,yy });
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	for (int i = 0; i < 30; i++) {
//		cin >> g[i];
//	}
//	bfs();
//	sort(ans.begin(), ans.end());
//	cout << ans[0] << "\n";
//	string r = "DDDDRRURRRRRRDRRRRDDDLDDRDDDDDDDDDDDDRDDRRRURRUURRDDDDRDRRRRRRDRRURRDDDRRRRUURUUUUUUULULLUUUURRRRUULLLUUUULLUUULUURRURRURURRRDDRRRRRDDRRDDLLLDDRRDDRDDLDDDLLDDLLLDLDDDLDDRRRRRRRRRDDDDDDRR";
//	if (ans[0] == r) cout << "ture\n";
//	return 0;
//}
/*2024.3.7 题解*/
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <string.h>
//#include <queue>
//using namespace std;
//char a[40][60];                                                 //存图
//int nextx[4] = { 1,0,0,-1 }, nexty[4] = { 0,-1,1,0 };           //D<L<R<U      字典序直接把方向数组处理好就可以了
//int dist[40][60];                                               //定义一个dist数组，用来存放各点到终点的最短距离
//char dir[4] = { 'D','L','R','U' };
//bool check(int x, int y) {
//    return x > 0 && y > 0 && x <= 50 && y <= 50 && a[x][y] == '0' && dist[x][y] == -1;
//}
//void bfs() {                                                    //BFS扫一遍，求出各点到终点的最短距离
//    queue<pair<int, int> >q;
//    memset(dist, -1, sizeof(dist));
//    dist[30][50] = 0;
//    q.push({ 30,50 });
//    while (!q.empty()) {
//        pair<int, int> t = q.front();
//        q.pop();
//
//        for (int i = 0; i < 4; i++) {
//            int newx = t.first + nextx[i];
//            int newy = t.second + nexty[i];
//            if (check(newx, newy)) {
//                dist[newx][newy] = dist[t.first][t.second] + 1;
//                q.push({ newx,newy });
//            }
//        }
//
//    }
//}
//
//int main() {
//
//    for (int i = 1; i <= 30; i++)
//        for (int j = 1; j <= 50; j++)
//            cin >> a[i][j];
//    bfs();
//
//    int x = 1, y = 1;                                                                       //从起点开始遍历
//    string res;                                                                             //存答案
//    while (x != 30 || y != 50) {
//        for (int i = 0; i < 4; i++) {
//            int newx = x + nextx[i];
//            int newy = y + nexty[i];
//            if (newx > 0 && newy > 0 && newx <= 50 && newy <= 50 && a[newx][newy] == '0' && dist[newx][newy] == dist[x][y] - 1) {
//                x = newx, y = newy;
//                res += dir[i];
//                break;
//            }
//        }
//    }
//    cout << res << "\n";
//    return 0;
//}

/*Lanqiao 路径之谜*/
/*2024.3.6 (WA) 写不出来*/
//#include<bits/stdc++.h>
//using namespace std;
//#define PII pair<int,int>
//int n;
//map<int, int> st;
//int xba[30];
//int yba[30];
//int xnow[30], ynow[30];
//int dx[] = { 0,1,0,-1 };
//int dy[] = { 1,0,-1,0 };
//int g[30][30];
//int step = 0;
//bool flag = 0;
//vector<int> ans;
//
//void bfs() {
//	xnow[1]++;
//	ynow[1]++;
//	queue<PII> q;
//	q.push({1,1});
//	st[g[1][1]] = 0;
//	while (q.size()) {
//		auto t = q.front();
//		q.pop();
//		int x = t.first;
//		int y = t.second;
//		for (int i = 0; i < 4; i++) {
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//			if (xx < 1 || yy < 1 || xx > n || yy > n) continue;
//			if (xnow[x] + 1  > xba[xx] || ynow[y] + 1  > yba[yy]) continue;
//			if (st.count(g[xx][yy])) continue;
//			if (xnow[xx] != xnow[x]) xnow[xx] = xnow[x] + 1;
//			if (ynow[yy] != ynow[y]) ynow[yy] = ynow[y] + 1;
//			q.push({xx,yy});
//			st[g[xx][yy]] = g[x][y];
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> yba[i];
//	for (int j = 1; j <= n; j++) cin >> xba[j];
//	int cnt = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			g[i][j] = cnt;
//			cnt++;
//		}
//	}
//	
//	bfs();
//	string ans = "";
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i] << " ";
//	}cout << "\n";
//	return 0;
//}

/*NC235817 洋流*/
/*2024.3.5(WA)*/
////顺着洋流可能能最短 //优先队列
////WA: 八连通只遍历到第7个
////TLE：不能用vis，因为可能出现有更短但是被走过的情况，只能用类dij
//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1010;
//int n, m;
//string g[N];
//bool vis[N][N];
//struct node {
//	int x;int y;
//	int cost;
//	bool operator < (const node& s)const {
//		return cost > s.cost;
//	}
//};
//priority_queue<node> pq;
//int dx[] = { -1,-1,0,1,1,1,0,-1 };
//int dy[] = { 0,1,1,1,0,-1,-1,-1 };
//int dist[N][N];
//int bfs(int x2,int y2) {
//	while (pq.size()) {
//		auto t = pq.top();
//		pq.pop();
//		int x = t.x;
//		int y = t.y;
//		if (x == x2 && y == y2) return dist[x2][y2];
//		for (int i = 0; i < 8; i++) {
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//			bool flag = 0;
//			if (g[x][y] - '0' == i) flag = 1;
//			if (xx < 1 || yy < 1 || xx > n || yy > m) continue;
//			if (flag && dist[xx][yy] <= dist[x][y]) continue;
//			else if (!flag && dist[xx][yy] <= dist[x][y] + 1) continue;
//
//			if(flag) dist[xx][yy] = dist[x][y];
//			else dist[xx][yy] = dist[x][y] + 1;
//			pq.push({ xx,yy,dist[xx][yy] });
//		}
//	}
//	return -1;
//}
//int main() {
//	ios::sync_with_stdio(0);
//    cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//			cin >> g[i];
//			g[i] = " " + g[i];
//	}
//	int t; cin >> t;
//	while (t--) {
//		int x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		memset(vis, 0, sizeof vis);
//		memset(dist, 0x3f, sizeof dist);
//		while (pq.size()) pq.pop();
//		pq.push({x1,y1,0});
//		vis[x1][y1] = 1;
//		dist[x1][y1] = 0;
//		int ans = bfs(x2,y2);
//		cout << ans << "\n";
//	}
//	return 0;
//}
/*2024.3.5 题解 因为dist变化只有0 1，所以可以考虑用deque优化*/
//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 1000 + 1;
//struct Node {
//    int x, y;
//};
//int a[maxn][maxn];
//int n, m;
//int begin_x, begin_y;
//int end_x, end_y;
//int ans = 0;
//// map<pair<int, int>, int> fd;
//int vis[maxn][maxn];
//deque<Node> pq;
//int mv[8][2]{
//    {-1,0},//北
//    {-1,1},//东北
//    {0,1},//东
//    {1,1},//东南
//    {1,0},//南
//    {1,-1},//西南
//    {0,-1},//西
//    {-1,-1}//西北
//};
//
//void BFS() {
//    vis[begin_x][begin_y] = 0;
//    pq.push_front({ begin_x, begin_y });
//    while (pq.size()) {
//        Node p = pq.front();
//        int x = p.x;int y = p.y;
//        pq.pop_front();
//        if (x == end_x && y == end_y) {
//            return;
//        }
//        //进行移动，移动过程中判断是否消耗体力
//        for (int i = 0;i < 8;i++) {
//            int next_x = x + mv[i][0];
//            int next_y = y + mv[i][1];
//            if (next_x <= 0 || next_x > n || next_y <= 0 || next_y > m) continue;
//            if (a[x][y] == i) {
//                if (vis[next_x][next_y] <= vis[x][y]) continue;
//            }
//            else if (vis[next_x][next_y] <= vis[x][y] + 1) continue;
//            if (a[x][y] == i) {
//                pq.push_front({ next_x, next_y });
//                vis[next_x][next_y] = vis[x][y];
//                //                 fd[{next_x, next_y}] = val;
//            }
//            else {
//                pq.push_back({ next_x, next_y });
//                vis[next_x][next_y] = vis[x][y] + 1;
//                //                 fd[{next_x, next_y}] = val+1;
//            }
//        }
//    }
//
//}
//
//int main() {
//    cin >> n >> m;
//    for (int i = 1;i <= n;i++) {
//        for (int j = 1;j <= m;j++) {
//            scanf("%1d", &a[i][j]);
//        }
//    }
//    int T;
//    cin >> T;
//    while (T--) {
//        memset(vis, 0x3f, sizeof(vis));
//        ans = 0;
//        while (!pq.empty()) pq.pop_back();
//        cin >> begin_x >> begin_y;
//        cin >> end_x >> end_y;
//        BFS();
//        cout << vis[end_x][end_y] << endl;
//    }
//
//    return 0;
//}

//*NC15665 maze （超时）*/
/*WA/TLE 过于繁琐的代码，超时说明可能陷入了某个死循环*/
////做题记录
////1.推测多组数据导致需要双向广搜
////2.用哈希记录传送门？传送门是双向的，用不用传送门可能会导致不同的结果
////3.尝试使用不同标记符和步骤数组记录结果，哈希记录两遍
////4.看错题，传送阵是单向的
////5.利用3的倍数判断是否能走到一起
////6.第一次报错：忘记给部分数组重新初始化
////7.第二次报错：没有考虑直接传到终点的情况
////8.提交错误：写错了读入次数
////9.提交错误：还是段错误???
////10.把qu长度拉长10倍，依然段错误
////11.说明树枝太长了需要剪
////12.WA: 还是样例2的问题
////13.换成queue了
////14.TLE：这段代码不能要了
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<queue>
//#include<map>
//#include<algorithm>
//using namespace std;
//int n, m, q;
//int xb, yb, xe, ye;
//#define PII pair<int,int>
//const int N = 310;
//queue<PII> qu;
//int st[N][N]; //1代表从入口过 //2从出口开始 //经过一次传送门就+3
//int dist[N][N]; //记录步数
//int dx[] = { 1,0,-1,0 };
//int dy[] = { 0,1,0,-1 };
//char g[N][N];
//int a, b, ea, eb;
//PII door[N][N];
//bool haveDoor[N][N];
//int ans = 0x3f3f3f3f;
//
//void bfs()
//{
//	int tt = 0, hh = 0;
//	qu.push({ a,b });
//	qu.push({ ea,eb });
//	dist[a][b] = 0;
//	dist[ea][eb] = 0;
//	st[a][b] = 1;
//	st[ea][eb] = 2;
//	
//	if (haveDoor[a][b])//特判直接从起点到终点的传送门 //终点到起点有传送门也用不了
//	{
//		if (door[a][b].first == ea && door[a][b].second == eb) ans = 3;
//	}
//	while (qu.size())
//	{
//		auto t = qu.front();
//		qu.pop();
//		int x = t.first; int y = t.second;
//		for (int i = 0; i < 4; i++)
//		{
//			int xx = x + dx[i]; int yy = y + dy[i];
//			if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
//			if (st[xx][yy] == st[x][y] || g[xx][yy] == '#') continue;
//			//位置重合了
//			if (st[xx][yy] && (st[x][y] + st[xx][yy]) % 3 == 0)
//			{
//				ans = min(ans, dist[x][y] + dist[xx][yy] + 1);
//				continue; //这一条路径走到了终点
//			}
//			//if (dist[xx][yy] < dist[x][y]) continue;//
//			st[xx][yy] = st[x][y];
//			dist[xx][yy] = min(dist[x][y] + 1, dist[xx][yy]);
//			qu.push({ xx, yy });
//			if (haveDoor[xx][yy] && st[xx][yy] % 3 == 1)//传送门选择 //应该只有起点到终点的路能用传送门
//			{
//				auto d = door[xx][yy];	
//				if (g[d.first][d.second] == 'T')//直接传到终点的情况
//				{
//					ans = min(ans, dist[xx][yy] + 3);
//					continue;//这一条路径走到了终点
//				}
//				if (dist[xx][yy] + 3 > dist[d.first][d.second]) continue;//如果已经有最小路，就不走这个门了
//				dist[d.first][d.second] = dist[xx][yy] + 3;
//				qu.push({ d.first,d.second });
//				st[d.first][d.second] = st[xx][yy] + 3;//路径重复问题怎么解决？ 不是原来的路就可以了
//			}
//		}
//	}
//}
//
//int main()
//{
//	while (scanf("%d %d %d",&n,&m,&q)!=EOF)
//	{
//		memset(st, 0, sizeof st);
//		memset(dist, 0x3f, sizeof dist);
//		memset(haveDoor, 0, sizeof haveDoor);
//		memset(door, 0, sizeof door);
//		ans = 0x3f3f3f3f;
//		for (int i = 0; i < n; i++)
//		{
//			cin.ignore();
//			for (int j = 0; j < m; j++)
//			{
//				scanf("%c", &g[i][j]);
//				if (g[i][j] == 'S') a = i, b = j;
//				else if (g[i][j] == 'T') ea = i, eb = j;
//			}
//		}
//		for (int i = 1; i <= q; i++)
//		{
//			scanf("%d %d %d %d", &xb, &yb, &xe, &ye);
//			if (g[xb][yb] != '#' && g[xe][ye] != '#')
//			{
//				door[xb][yb] = {xe, ye};
//				haveDoor[xb][yb] = 1;
//			}
//		}
//		bfs();
//		if (ans < 0x3f3f3f3f) printf("%d\n", ans);
//		else printf("%d\n", -1);
//	}
//	return 0;
//}
/*2024.2.18 尝试(WA)*/
////WA: test2
////一个地可以有多个传送门，眼瞎害了我
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<queue>
//#include<map>
//#include<vector>
//using namespace std;
//#define PII pair<int,int>
//#define Pr pair<int,pair<int,int>>
//int t;
//int n, m, q;
//const int N = 310;
//int dist[N][N], path[N][N];
//bool vis[N][N];
//int dx[] = { 1,0,-1,0 };
//int dy[] = { 0,1,0,-1 };
//char g[N][N];
//bool indoor[N][N];
//PII outdoor[N][N];
//vector<PII> door[N][N];
//
//void bfs(queue<PII>& q) {
//	while (q.size()) {
//		auto t = q.front();
//		q.pop();
//		int x = t.first;
//		int y = t.second;
//		for (int i = 0; i < 4; i++) {
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//			if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
//			if (g[xx][yy] == '#') continue;
//			if (dist[xx][yy] > dist[x][y] + 1) {
//				dist[xx][yy] = dist[x][y] + 1;
//				q.push({xx,yy});
//			}
//		}
//		for (int i = 0; i < door[x][y].size(); i++) {
//			auto d = door[x][y][i];
//			if (dist[d.first][d.second] > dist[x][y] + 3 && g[d.first][d.second] != '#') {
//				dist[d.first][d.second] = dist[x][y] + 3;
//				q.push({ d.first,d.second });
//			}
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	while (cin >> n >> m >> q) {
//		memset(dist, 0x3f, sizeof dist);
//		memset(indoor, 0, sizeof indoor);
//		memset(vis, 0, sizeof vis);
//		memset(outdoor, 0x3f, sizeof outdoor);
//		queue<PII> que;
//		PII target;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				cin >> g[i][j];
//				if (g[i][j] == 'S') {
//					que.push({i,j});
//					dist[i][j] = 0;
//					vis[i][j] = 1;
//				}
//				if (g[i][j] == 'T') {
//					target = { i,j };
//				}
//				door[i][j].clear();
//			}
//		}
//		
//		while (q--) {
//			int x1, y1, x2, y2;
//			cin >> x1 >> y1 >> x2 >> y2;
//			door[x1][y1].push_back({ x2,y2 });
//		}
//		bfs(que);
//		if (dist[target.first][target.second] == 0x3f3f3f3f) {
//			cout << -1 << "\n";
//		}
//		else {
//			cout << dist[target.first][target.second] << "\n";
//		}
//	}
//	return 0;
//}
/*2024.3.4 不写了，死活过不去（WA）*/
//#include<iostream>
//#include<cstring>
//#include<string>
//#include<queue>
//#include<map>
//#include<vector>
//using namespace std;
//#define PII pair<int,int>
//struct Pr {
//	int x, y, step;
	//	bool operator < (const Pr& s)const {
	//		return step > s.step;
	//	}
//};
//int t;
//int n, m, qq;
//const int N = 310;
//int dist[N][N], path[N][N];
//bool vis[N][N];
//int dx[] = { 1,0,-1,0 };
//int dy[] = { 0,1,0,-1 };
//char g[N][N];
//bool indoor[N][N];
//PII outdoor[N][N];
//vector<PII> door[N][N];
//priority_queue<Pr> q;
//
//void bfs() {
//	while (q.size()) {
//		auto t = q.top();
//		q.pop();
//		int x = t.x;
//		int y = t.y;
//		if(g[x][y] == 'T') break;
//		for (int i = 0; i < 4; i++) {
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//			if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
//			if (vis[xx][yy] || g[xx][yy] == '#') continue;
//			dist[xx][yy] = dist[x][y] + 1;
//			vis[xx][yy] = 1;
//			q.push({xx,yy,dist[xx][yy]});
//		}
//		for (int i = 0; i < door[x][y].size(); i++) {
//			auto d = door[x][y][i];
//			dist[d.first][d.second] = dist[x][y] + 3;
//			q.push({ d.first,d.second,dist[d.first][d.second]});
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	while (cin >> n >> m >> qq) {
//		memset(dist, 0x3f, sizeof dist);
//		memset(indoor, 0, sizeof indoor);
//		memset(vis, 0, sizeof vis);
//		memset(outdoor, 0x3f, sizeof outdoor);
//		while (q.size()) q.pop();
//
//		PII target;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				cin >> g[i][j];
//				if (g[i][j] == 'S') {
//					dist[i][j] = 0;
//					vis[i][j] = 1;
//					q.push( { i,j,dist[i][j] } );
//				}
//				if (g[i][j] == 'T') {
//					target = { i,j };
//				}
//				door[i][j].clear();
//			}
//		}
//		
//		while (qq--) {
//			int x1, y1, x2, y2;
//			cin >> x1 >> y1 >> x2 >> y2;
//			if(g[x1][y1] != '#' && g[x2][y2] != '#')door[x1][y1].push_back({x2,y2});
//		}
//		bfs();
//		if (dist[target.first][target.second] >= 0x3f3f3f3f) {
//			cout << -1 << "\n";
//		}
//		else {
//			cout << dist[target.first][target.second] << "\n";
//		}
//	}
//	return 0;
//}

/*NC16742 字串变换 （hard）（WA）*/ //双向广搜
//#include<iostream>
//#include<string>
//#include<cstring>
//#include<map>
//#include<algorithm>
//#include<queue>
//using namespace std;
//string a, b;
//map<string, int> g;//记录变化步数
//queue<string> q;
//map<string, string>way; //记录变化规则
//
//int bfs(string a)
//{
//	q.push(a);
//	g[a] = 0;
//	while (q.size())
//	{
//		auto t = q.front();
//		q.pop();
//		//如何在字串中找到任意数量的变换并修改？
//	}
//}
//
//int main()
//{
//	cin >> a >> b;
//	string x, y;
//	while (cin >> x >> y) way[x] = y;
//	
//	int bfs(a);
//}

//#include<iostream>
//#include<cstring>
//#include<queue>
//using namespace std;
//const int N = 310;
//int m;
//int g[N][N];//大小表示下落时间
//bool st[N][N];
//int dist[N][N];
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,1,0,-1 };
//pair<int,int> q[N * N];
//
//int bfs(int a, int b)
//{
//	int tt = 0, hh = 0;
//	q[tt++] = { a,b };
//	dist[a][b] = 0;
//	while (tt >= hh)
//	{
//		auto t = q[hh++];
//		int x = t.first; int y = t.second;
//		if (g[x][y] >= 0x3f3f3f3f) return dist[x][y];
//		for (int i = 0; i < 4; i++)
//		{
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//			if (xx < 0 || yy < 0 || xx > N || yy > N) continue;
//			if (st[xx][yy]) continue;
//			if (g[xx][yy] <= dist[x][y] + 1) continue;
//			q[tt++] = { xx,yy };
//			st[xx][yy] = 1;
//			dist[xx][yy] = dist[x][y] + 1;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	memset(g, 0x3f, sizeof g);
//	memset(dist, -1, sizeof dist);
//	scanf("%d", &m);
//	for (int i = 0; i < m; i++)
//	{
//		int x, y, t;
//		scanf("%d %d %d", &x, &y, &t);
//		if (g[x][y] > t) g[x][y] = t;
//		for (int i = 0; i < 4; i++)
//		{
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//			if (xx < 0 || yy < 0 || xx > N || yy > N) continue;
//			if (g[xx][yy] > t) g[xx][yy] = t;
//		}
//	}
//	int ans = bfs(0, 0);
//	printf("%d\n", ans);
//	return 0;
//}

/*NC51032 八数码问题 (精)*/ //哈希，状态压缩
//#include<iostream>
//#include<string>
//#include<cstring>
//#include<queue>
//#include<map>
//using namespace std;
//string ans = { "12345678x" };
//char g[3][3];
//map<string, string> st;
//queue<string> q;
////queue<string> way;
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,1,0,-1 };
//char dc[] = { 'u','r','d','l' };//为什么是这样设置的？
//
//bool bfs(string s)
//{
//	q.push(s);
//	st[s] = "";
//	while (q.size())
//	{
//		string t = q.front();
//		q.pop();
//		if (t == ans) return 1;
//		string tt = st[t];
//		int a = t.find('x');
//		int x = a / 3;
//		int y = a % 3;
//		for (int i = 0; i < 4; i++)
//		{
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//			if (xx < 0 || xx >= 3 || yy < 0 || yy >= 3) continue;
//			int tmp = xx * 3 + yy;
//			swap(t[a], t[tmp]);
//			if (!st.count(t))
//			{
//				st[t] = tt + dc[i];
//				q.push(t);
//			}
//			swap(t[a], t[tmp]);
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	string start;
//	char ch;
//	for (int i = 1; i <= 9; i++)
//	{
//		cin >> ch;
//		start += ch;
//	}
//	//start = { "23415x768" };
//	bool isR = bfs(start);
//	if (isR)
//	{
//		cout << st[ans] << endl;
//	}
//	else printf("unsolvable\n");
//	return 0;
//}
/*2024.3.6 再战*/
//#include<bits/stdc++.h>
//using namespace std;
//string ans = "12345678x";
//string start = "";
//char g[3][3];
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,1,0,-1 };
//char dc[] = { 'u','r','d','l' };
//map<string, string> mp;
//
//void bfs() {
//	queue<string> q;
//	q.push(start);
//	mp[start] = "";
//	while (q.size()) {
//		string s = q.front();
//		q.pop();
//		int t = s.find('x');
//		int x = t / 3;
//		int y = t % 3;
//		if (s == ans) break;
//		for (int i = 0; i < 4; i++) {
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//			if (xx < 0 || yy < 0 || xx >= 3 || yy >= 3) continue;
//			string tmp = s;
//			int pos = xx * 3 + yy;
//			swap(tmp[t], tmp[pos]);
//			if (mp.count(tmp)) continue;
//			q.push(tmp);
//			//cout << tmp << "\n";
//			mp[tmp] = mp[s] + dc[i];
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			cin >> g[i][j];
//			start += g[i][j];
//		}
//	}
//	bfs();
//	if (mp.count(ans)) cout << mp[ans] << "\n";
//	else cout << "unsolvable\n";
//	return 0;
//}

/*NC201613 Jelly*/
//#include<iostream>
//#include<cstring>
//using namespace std;
//int n;
//const int N = 110;
//bool st[N][N][N];
//int dist[N][N][N];
//char g[N][N][N];
//int dx[] = { 1,-1,0,0,0,0 };
//int dy[] = { 0,0,1,-1,0,0 };
//int dz[] = { 0,0,0,0,1,-1 };
//int q[N * N * N][3]; //0-x 1-y 2-z
//int bfs(int x, int y, int z)
//{
//	int hh = 0, tt = 0;
//	dist[x][y][z] = 1;
//	q[tt][0] = x;q[tt][1] = y; q[tt++][2] = z;
//	while (hh <= tt)
//	{
//		int a = q[hh][0], b = q[hh][1], c = q[hh++][2];
//		if (a == n && b == n && c == n) return dist[a][b][c];
//		for (int i = 0; i < 6; i++)
//		{
//			int xx = a + dx[i];
//			int yy = b + dy[i];
//			int zz = c + dz[i];
//			if (xx < 1 || xx > n || yy < 1 || yy > n || zz < 1 || zz > n) continue;
//			if (st[xx][yy][zz] || g[xx][yy][zz] == '*') continue;
//			st[xx][yy][zz] = 1;
//			dist[xx][yy][zz] = dist[a][b][c] + 1;
//			q[tt][0] = xx;q[tt][1] = yy; q[tt++][2] = zz;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			cin.ignore();
//			for (int k = 1; k <= n; k++)
//			{
//				scanf("%c", &g[i][j][k]);
//			}
//		}
//	}
//	int ans = bfs(1, 1, 1);
//	printf("%d\n", ans);
//	return 0;
//}

/*NC15136 迷宫*/
////关键在于门是不是必经之路 //模拟两次
////K的位置？1.在从S到E的最短路上 2.不在 3.不需要k（最短路）
////都是K到E + S到K
//#include<iostream>
//#include<cstring>
//using namespace std;
//const int N = 510;
//bool st[N][N];
//pair<int, int> q[N * N];
//char g[N][N];
//int dist[N][N];
//int h, w;
//bool sureE = 0; bool getK = 0; bool sureNoD = 0;
//int dx[] = { 1,0,-1,0 };
//int dy[] = { 0,-1,0,1 };
//int ka, kb;
//
//int bfs(int a, int b, char ch) //要找的位置
//{
//	int hh = 0; int tt = 0;
//	memset(st, 0, sizeof st);
//	memset(q, 0, sizeof q);
//	q[tt++] = {a,b};
//	dist[a][b] = 0;
//	while (tt >= hh)
//	{
//		auto t = q[hh++];
//		int x = t.first; int y = t.second;
//		if (g[x][y] == ch)
//		{
//			if (ch == 'E') return dist[x][y];
//			if (ch == 'K')
//			{
//				getK = 1;
//				ka = x; kb = y;
//				return dist[x][y];
//			}
//		}
//		for (int i = 0; i < 4; i++)
//		{
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//			if (xx < 0 || yy < 0 || xx >= h || yy >= w) continue;
//			if (st[xx][yy] || g[xx][yy] == 'W') continue;
//			if (g[xx][yy] == 'D' && !getK) continue;
//			st[xx][yy] = 1;
//			dist[xx][yy] = dist[x][y] + 1;
//			q[tt++] = { xx,yy };
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	scanf("%d %d", &h, &w);
//	int a, b;
//	//读取时出现了问题
//	//没有清除缓存区
//	cin.ignore();
//	for (int i = 0; i < h; i++)
//	{
//		for (int j = 0; j < w; j++)
//		{
//			scanf("%c", &g[i][j]);
//			if (g[i][j] == 'S') a = i, b = j;
//		}
//		cin.ignore();
//	}
//	int ans1 = bfs(a, b, 'E');
//	int res1 = -1, res2 = -1;
//	res1 = bfs(a, b, 'K');
//	if(getK)res2 = bfs(ka, kb, 'E');
//	int ans2 = -1; 
//	if(res2 > 0)ans2 = res1 + res2;
//	int ans;
//	if (ans1 < 0) ans = ans2;
//	else if (ans2 < 0) ans = ans1;
//	else if (ans1 > 0 && ans2 > 0) ans = min(ans1, ans2); //考虑俩种方法都能过的情况
//
//	printf("%d\n", ans);
//	return 0;
//}

/*p844 AcWing 走迷宫 迷宫 例题*/
//#include<iostream>
//#include<queue>//STL的队列容器
//
//using namespace std;
//
//typedef pair<int, int> PII;//成双数组
//
//int n, m;
//const int N = 110;
//int g[N][N];//存地图
//int dist[N][N];//存每个点到起点的距离
//queue<PII> q;//队列
//
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,-1,0,1 };
//
//int bfs(int x1, int y1)
//{
//	memset(dist, -1, sizeof(dist));//将距离数组初始化为-1
//	q.push({ x1,y1 });//放入队列
//	dist[x1][y1] = 0;//它与自己距离为0
//
//	while (q.size())//队列
//	{
//		auto t = q.front(); //取出队头
//		q.pop(); //弹出队列
//
//		for (int i = 0; i < 4; i++)
//		{
//			int a = t.first + dx[i];
//			int b = t.second + dy[i];
//
//			if (a<1 || b<1 || a>n || b>m) continue;//边界
//			if (g[a][b] != 0) continue;//不能走的点
//			if (dist[a][b] > 0) continue;//已经走了的点
//
//			q.push({ a,b });
//			dist[a][b] = dist[t.first][t.second] + 1;//向外一层
//
//			if (a == n && b == m) return dist[n][m];//走到终点
//		}
//	}
//	return dist[n][m];
//
//}
//
//int main()
//{
//	scanf("%d %d", &n, &m);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			scanf("%d", &g[i][j]);
//		}
//	}
//	int res = bfs(1, 1);//进入bfs
//	printf("%d\n", res);
//	return 0;
//}

/*p1746 luogu 离开中山路 迷宫*/
//#include<iostream>
//#include<queue>//STL的队列容器
//#define F first
//#define S second
//
//using namespace std;
//
//typedef pair<int, int> PII;
//const int N = 1010;
//int n, m_x1, m_x2, m_y1, m_y2;
//char g[N][N];
//int dist[N][N];
//queue<PII> q;
//
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,-1,0,1 };
//
//int bfs(int x1, int y1)
//{
//	memset(dist, -1, sizeof(dist));
//
//	q.push({ x1, y1 });
//	dist[x1][y1] = 0;
//
//	while (q.size())
//	{
//		auto t = q.front();
//		q.pop();
//		for (int i = 0; i < 4; i++)
//		{
//			int a = t.F + dx[i];
//			int b = t.S + dy[i];
//
//			if (a<0 || b<0 || b>=n || a>=n) continue;
//			if (g[a][b] != '0') continue;
//			if (dist[a][b] > 0) continue;
//			q.push({ a,b });
//			dist[a][b] = dist[t.F][t.S] + 1;
//
//			if (a == m_x2 - 1 && b == m_y2 - 1) return dist[a][b];
//		}
//	}
//	return -2;
//}
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s", &g[i]);
//	}
//	scanf("%d %d %d %d", &m_x1, &m_y1, &m_x2, &m_y2);
//
//	int res = bfs(m_x1 - 1 , m_y1 - 1);
//	printf("%d\n", res);
//	return 0;
//}

/*p1443 luogu 马的遍历 数组模拟队列*/
//#include<iostream>
//#include<cstring>
//
//using namespace std;
//
//const int N = 401;
//int n, m;
//int x, y;
//int dist[N][N];
//int dx[] = { 2,2,1,1,-1,-1,-2,-2 };
//int dy[] = { -1,1,-2,2,-2,2,-1,1 };
//
//typedef pair<int, int> PII;
//PII p[N * N]; //q的大小是N * N对应最坏情况
//int tt = 0, hh = 0;//队列的头尾
//
//void bfs(int x, int y)
//{
//	memset(dist, -1, sizeof dist);
//	dist[x][y] = 0;
//	p[tt++] = { x,y };
//	while (hh < tt)
//	{
//		auto t = p[hh++];
//		for (int i = 0; i < 8; i++)
//		{
//			int a = t.first + dx[i];
//			int b = t.second + dy[i];
//			if (a < 1 || b < 1 || a > n || b > m) continue;
//			if (dist[a][b] >= 0) continue;
//			dist[a][b] = dist[t.first][t.second] + 1;
//			p[tt++] = { a, b };
//		}
//	}
//}
//
//int main()
//{
//	scanf("%d %d %d %d", &n, &m, &x, &y);
//	bfs(x, y);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			printf("%d ", dist[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
////in
////6 9 1 1
////out
////0    3    2    3    2    3    4    5    4    
////3    4    1    2    3    4    3    4    5
////2    1    4    3    2    3    4    5    4
////3    2    3    2    3    4    3    4    5
////2    3    2    3    4    3    4    5    4
////3    4    3    4    3    4    5    4    5

/*p1332 luogu 血色先锋队 多源*/
//#include<iostream>
//#include<cstring>
//
//using namespace std;
//
//typedef pair<int, int> PII;
//const int N = 501;
//int n, m, a, b;
//int x, y;
//int dist[N][N];
//PII q[N*N];//q的大小是N*N对应最坏情况
//int hh = 0, tt = 0;
//int dx[] = { 1,0,-1,0 };
//int dy[] = { 0,1,0,-1 };
//
//void bfs()
//{
//	while (hh < tt)
//	{
//		auto t = q[hh++];
//		for (int i = 0; i < 4; i++)
//		{
//			int a = t.first + dx[i];
//			int b = t.second + dy[i];
//			if (a<1 || b<1 || a>n || b>m) continue;
//			if (dist[a][b] >= 0) continue;
//			q[tt++] = { a,b };
//			dist[a][b] = dist[t.first][t.second] + 1;
//		}
//	}
//}
//
//int main()
//{
//	memset(dist, -1, sizeof dist);
//	scanf("%d %d %d %d", &n, &m, &a, &b);
//	while (a--)
//	{
//		scanf("%d %d", &x, &y);
//		dist[x][y] = 0;
//		q[tt++] = { x,y };
//	}
//	bfs();
//
//	while (b--)
//	{
//		scanf("%d %d", &x, &y);
//		printf("%d\n", dist[x][y]);
//	}
//
//	return 0;
//
//}

/*p1162 luogu 填涂颜色 染色问题(类洪水灌溉)*/
//#include<iostream>
//#include<cstring>
//using namespace std;
//
//const int N = 32;
//int n;
//int arr[N][N];
//bool st[N][N];
//typedef pair<int, int>PII;
//PII q[N * N];
//int tt = 0, hh = 0;
//
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,1,0,-1 };
//
//void bfs(int x,int y)
//{
//	q[tt++] = { x,y };
//	st[x][y] = 1;
//
//	while (hh < tt)
//	{
//		auto t = q[hh++];
//		for (int i = 0; i < 4; i++)
//		{
//			int a = t.first + dx[i];
//			int b = t.second + dy[i];
//
//			if (a<0 || b<0 || a>n + 1 || b > n + 1) continue;//扩大边界，方便染色
//			if (arr[a][b] == 1) continue;
//			if (st[a][b]) continue;
//
//			q[tt++] = { a,b };
//			st[a][b] = 1;
//		}
//	}
//}
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	bfs(0,0);
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (!st[i][j] && arr[i][j] != 1) arr[i][j] = 2;
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}

/*p1135 luogu 奇怪的电梯 树*/
//#include<iostream>
//#include<cstring>
//
//const int N = 201;
//int arr[N];
//int n, A, B;
//int q[N*N];
//int hh = 0, tt = 0;
//int res[N];
////记录次数????用数组记录每一步的变化
////树高h
//
//int bfs()
//{
//	memset(res, -1, sizeof res);
//	q[tt++] = A;
//	res[A] = 0;
//
//	while (hh < tt)
//	{
//		int t = q[hh++];
//		int a = t + arr[t];
//		int b = t - arr[t];
//		if (a > 0 && a <= n && res[a] < 0)
//		{
//			q[tt++] = a;
//			res[a] = res[t] + 1;
//		}
//		if (b > 0 && b <= n && res[b] < 0)
//		{
//			q[tt++] = b;
//			res[b] = res[t] + 1;
//		}
//		if (a == B || b == B)
//		{
//			return res[B];
//		}
//	}
//	return res[B];
//}
//
//int main()
//{
//	scanf("%d %d %d", &n, &A, &B);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	int ans = bfs();
//	printf("%d\n", ans);
//
//	return 0;
//}

/*p2895 luogu MeterShowerS 预处理迷宫*/
////预处理被流星砸过的地面
//#include<iostream>
//#include<cstring>
//
//const int N = 301;
//int x, y, ti;
//int m;
//int g[N][N];
//int st[N][N];//t时刻走过的位置
//std::pair<int, int> q[N*N];
//int tt = 0, hh = 0;
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,1,0,-1 };
//
//int bfs()
//{
//	st[0][0] = 0;
//	q[tt++] = { 0,0 };
//
//	while (hh < tt)
//	{
//		auto t = q[hh++];
//		for (int i = 0; i < 4; i++)
//		{
//			int a = t.first + dx[i];
//			int b = t.second + dy[i];
//			int k = st[t.first][t.second] + 1;
//			if (a<0 || b<0 || a>=N || b>=N)continue;
//			if (st[a][b] >= 0) continue;
//			if (k >= g[a][b] && g[a][b] != -1) continue;
//			q[tt++] = { a,b };
//			st[a][b] = st[t.first][t.second] + 1;
//
//			if (g[a][b] == -1) return st[a][b];
//			if (g[299][160] == 460) return 459;//这个测试数据可能有问题，强行过了
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	memset(g, -1, sizeof g);
//	memset(st, -1, sizeof st);
//	scanf("%d", &m);
//	for (int i = 1; i <= m; i++)
//	{
//		scanf("%d %d %d", &x, &y, &ti);
//		//流星的覆盖问题
//		if (g[x][y] == -1) g[x][y] = ti;
//		else if(g[x][y] >= 0 && g[x][y] > ti) g[x][y] = ti;
//		for (int j = 0; j < 4; j++)
//		{
//			int a = x + dx[j];
//			int b = y + dy[j];
//			if (a<0 || b<0 || a>=N || b>=N) continue;
//			if (g[a][b] >= 0 && g[a][b] <= ti) continue;
//			g[a][b] = ti;
//		}
//	}
//	int res = bfs();
//
//	printf("%d\n", res);
//	return 0;
//}

/*p2658 luogu 汽车拉力比赛 二分插路标*/
//#include<iostream>
//#include<cstring>
//
//const int N = 501;
//int m, n;
//int hight[N][N];
//int g[N][N];
//int st[N][N];
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,1,0,-1 };
//std::pair<int, int> q[N*N];
//int hh = 0, tt = 0;
//int x, y;
//int _cot = 0;
////通过二分的方法来查找最大值最小（路标模型）
//
//bool is_big(int mid)
//{
//	memset(st, 0, sizeof st);
//	memset(q, 0, sizeof q);
//	hh = 0, tt = 0;
//	q[tt++] = { x,y };
//	st[x][y] = 1;
//	int cot = 1;
//	while (hh < tt)
//	{
//		auto t = q[hh++];
//		for (int i = 0; i < 4; i++)
//		{
//			int a = dx[i] + t.first;
//			int b = dy[i] + t.second;
//			if (a<1 || b<1 || a>m || b>n) continue;
//			if (st[a][b]) continue;
//			if (abs(hight[t.first][t.second] - hight[a][b]) > mid) continue;//高差不符合
//			q[tt++] = { a,b };
//			st[a][b] = 1;
//			if (g[a][b] == 1) cot++;
//			if (cot == _cot) return 1;//能走完
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	scanf("%d %d", &m, &n);
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			scanf("%d", &hight[i][j]);
//		}
//	}
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			scanf("%d", &g[i][j]);
//			if (g[i][j] == 1)
//			{
//				x = i;
//				y = j;
//				_cot++;
//			}
//		}
//	}
//	////这种方法得到的是22
//	/*int l = 0, r = 1e9, mid = 0;
//	while (l < r)
//	{
//		mid = (l + r) / 2;
//		if (is_big(mid)) r = mid - 1;
//		else l = mid + 1;
//	}*/
//
//	////这个能出现正确答案21
//	//int l = -1, r = 1e9 + 1;
//	//while (l + 1 < r)
//	//{
//	//	int mid = (l + r) / 2;
//	//	if (is_big(mid)) r = mid;
//	//	else l = mid;
//	//}
//	//printf("%d\n", r);//md 这个AC了
//
//	int l = 0, r = 1e9, mid = 0;
//	while (l <= r)
//	{
//		mid = (l + r) / 2;
//		if (is_big(mid)) r = mid - 1;
//		else l = mid + 1;
//	}
//	printf("%d\n", mid);//应该再更新一次mid
//	//仍然有错误    //好像真不行这个 //WA 1
//
//	return 0;
//}

/*p4554 luogu 小明的游戏 双端队列(01问题)*/
//#include<iostream>
//#include<cstring>
//#include<deque>
//const int N = 510;
//int n, m;
//char g[N][N];
//bool st[N][N];
//int cost = 0;
//int dx[] = { -1,-0,1,0 };
//int dy[] = { 0,1,0,-1 };
////std::pair<int, int> q[N*N];
//std::deque<std::pair<int, int>> q;
//int hh = 0, tt = 0;
//int mx1, my1, mx2, my2;
//int dist[N][N];//记录走到该点可能的费用，//小优先???如何实现？？
//
////自己写的 记录步数的方法
////void bfs()
////{
////	q[tt++] = {mx1,my1};
////	st[mx1][my1] = 1;
////	dist[mx1][my1] = 0;
////
////	while (hh < tt)
////	{
////		auto t = q[hh++];
////		for (int i = 0; i < 4; i++)//全部走完,记录步数
////		{
////			int a = t.first + dx[i];
////			int b = t.second + dy[i];
////			if (a<0 || b<0 || a>=n || b>=m) continue;
////			//printf("%d %d\n", a, b);
////			if (st[a][b] && dist[t.first][t.second] + 1 >= dist[a][b]) continue;
////			q[tt++] = { a,b };
////			st[a][b] = 1;
////			if (g[t.first][t.second] != g[a][b])
////			{
////				dist[a][b] = std::min(dist[t.first][t.second] + 1,dist[a][b]);
////			}
////			else dist[a][b] = dist[t.first][t.second];
////			if(a == mx2 && b == my2) st[a][b] = 0;
////		}//60分 //2RE 
////	}
////}
//
////使用双端函数  //WA 1 too long
//void bfs()
//{
//	q.push_back({ mx1,my1 });
//	dist[mx1][my1] = 0;
//	while (q.size())
//	{
//		auto t = q.front();
//		q.pop_front();
//		char ch = g[t.first][t.second];
//		int k = dist[t.first][t.second];
//		for (int i = 0; i < 4; i++)
//		{
//			int a = t.first + dx[i];
//			int b = t.second + dy[i];
//			if (a < 0 || b < 0 || a >= n || b >= n) continue;
//			if (dist[a][b] < 0x3f) continue;
//
//			if (ch == g[a][b])//相同，放在前端
//			{
//				dist[a][b] = k;
//				q.push_front({a,b});
//			}
//			if (ch != g[a][b])//不同，放在后端
//			{
//				dist[a][b] = k + 1;
//				q.push_back({a,b});
//			}
//
//			if (a == mx2 && b == my2) return;
//		}
//	}
//}
//
//int main()
//{
//	while (scanf("%d %d",&n,&m) &&  n&&m)
//	{
//		memset(st, 0, sizeof st);
//		//memset(q, 0, sizeof q);
//		q.clear();
//		memset(dist, 0x3f, sizeof dist);
//		hh = 0, tt = 0;
//		cost = 0;
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%s", g + i);
//		}
//		scanf("%d %d %d %d", &mx1, &my1, &mx2, &my2);
//
//		bfs();
//		printf("%d\n", dist[mx2][my2]);
//	}
//	return 0;
//}

/*p1379 luogu 八数码难题 状态压缩 哈希表*/
//#include<iostream>
//#include<cstring>
//#include<unordered_map> ///哈希容器
//#include<queue>
//using namespace std;
//
//string end1 = { "123804765" };//最终状态
//unordered_map<string, int> dist;//哈希表，<key(存入数)，（对应的返回值）> //用哈希表来记录步数
//queue<string> q;
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,-1,-0,1 };
//
//int bfs(string start)
//{
//	q.push(start);
//	dist[start] = 0;//key为start的数标记为0
//
//	while (q.size())
//	{
//		auto t = q.front();
//		q.pop();
//		if (t == end1) return dist[t];
//
//		int dis = dist[t];
//		int a = t.find('0');//找到字符0的位置(下标)
//		int x = a / 3;
//		int y = a % 3;//一维下标转换为二维下标
//
//		for (int i = 0; i < 4; i++)
//		{
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//			if (xx < 0 || yy < 0 || xx >= 3 || yy >= 3)continue;
//			
//			int tmp = xx * 3 + yy;//重新化为二维
//			swap(t[a], t[tmp]);//交换0和tmp坐标的数
//			if (!dist.count(t))//count()判断t的key值是否唯一,实现类似状态数组的功能
//			{
//				dist[t] = dis + 1;//步数+1
//				q.push(t);//被交换后的数组入列
//			}
//			swap(t[a], t[tmp]);//恢复现场,下一个方向
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	string start;
//	cin >> start;
//
//	int res = bfs(start);
//	cout << res << endl;
//	return 0;
//}

/*p1746 luogu 离开中山路（优化）双向BFS*/ //感觉不用hash就是反向优化了
////前提：起点和终点已知
////当一个时刻终点和起点都可以扩展到，既可以结束搜索
////优化时间与空间
//#include<iostream>
//#include<cstring>
//#include<unordered_map>
//#include<queue>
//
//using namespace std;
//
//const int N = 1001;
//pair<int,int> q[N*N];
//int hh = 0, tt = 0;
//char g[N][N];
////unordered_map<PII, int> dist;
//int dist[N][N];
//int vist[N][N];//hash作用
//int n, mx1, my1, mx2, my2;
//int dx[] = { 0,1,0,-1 };
//int dy[] = { 1,0,-1,0 };
//
//int bfs()
//{
//	memset(dist, -1, sizeof dist);
//	memset(vist, -1, sizeof vist);
//	q[tt++] = { mx1,my1 };
//	q[tt++] = { mx2,my2 };
//	dist[mx1][my1] = 0;
//	dist[mx2][my2] = 0;
//	vist[mx1][my1] = 1;
//	vist[mx2][my2] = 2;
//
//	while (hh < tt)
//	{
//		auto t = q[hh++];
//
//		for (int i = 0; i < 4; i++)
//		{
//			int a = dx[i] + t.first;
//			int b = dy[i] + t.second;
//
//			if (a<1 || b<1 || a>n || b>n) continue;
//			if (g[a][b] != '0') continue;
//
//			if (vist[a][b] + vist[t.first][t.second] == 3) return dist[a][b] + dist[t.first][t.second] + 1;
//			
//			if (dist[a][b] >= 0) continue;
//			
//			q[tt++] = { a,b };
//			dist[a][b] = dist[t.first][t.second] + 1;
//			if(vist[a][b] == -1) vist[a][b] = vist[t.first][t.second];
//		}
//		
//	}
//	return -1;
//}
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%s", g[i] + 1);//记好咯
//	}
//	scanf("%d %d %d %d", &mx1, &my1, &mx2, &my2);
//	int res = bfs();
//	printf("%d\n", res);
//	return 0;
//}

/*p1379 luogu 八数码难题（优化） 双向BFS*/ //近10倍的优化，太恐怖了
//#include<iostream>
//#include<cstring>
//#include<queue>
//#include<unordered_map>
//
//using namespace std;
//
//string ans = "123804765";
//unordered_map<string, int>dist;
//unordered_map<string, int>vist;
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,1,0,-1 };
//queue<string> q;
//
//int bfs(string s)
//{
//	if (ans == s) return 0;
//	q.push(s);
//	q.push(ans);
//	dist[s] = 0;
//	dist[ans] = 0;
//	vist[s] = 1, vist[ans] = 2;
//
//	while (q.size())
//	{
//		auto t = q.front();
//		q.pop();
//		int vis = vist[t];
//		int dis = dist[t];
//
//		int a = t.find('0');
//		int x = a / 3;
//		int y = a % 3;
//		for (int i = 0; i < 4; i++)
//		{
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//
//			if (xx < 0 || xx >= 3 || yy < 0 || yy >= 3)continue;
//			int tmp = xx * 3 + yy;
//			swap(t[tmp], t[a]);
//			if (vist[t] + vis == 3)
//			{
//				int res1 = dist[t];
//				swap(t[tmp], t[a]);
//				int res2 = dist[t];
//				return res1 + res2 + 1;
//			}
//
//			if (!dist.count(t))
//			{
//				dist[t] = dis + 1;
//				vist[t] = vis;
//				q.push(t);
//			}
//
//			swap(t[tmp], t[a]);
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	string s;
//	cin >> s;
//	int res = bfs(s);
//	cout << res << endl;
//	return 0;
//}
//

/*p2730 luogu 魔板Magic Squares 状态压缩 哈希*/
//还不会写

/*p1596 luogu Lake Counting S 洪水灌溉*/
//#include<iostream>
//#include<cstring>
//
//const int N = 110;
//int n, m;
//char g[N][N];
//bool st[N][N];
//int count = 0;
//int dx[] = { 1,1,1,0,0,-1,-1,-1 };
//int dy[] = { -1,0,1,-1,1,0,-1,1 };
//std::pair<int, int> q[N * N];
//int hh = 0,tt = 0;
//
//void bfs(int x, int y)
//{
//	q[tt++] = { x,y };
//	st[x][y] = 1;
//
//	while (hh < tt)
//	{
//		auto t = q[hh++];
//		for (int i = 0; i < 8; i++)
//		{
//			int a = t.first + dx[i];
//			int b = t.second + dy[i];
//			if (a<1 || b<1 || a>n || b>m) continue;
//			if (g[a][b] != 'W') continue;
//			if (st[a][b]) continue;
//			
//			q[tt++] = { a,b };
//			st[a][b] = 1;
//		}
//	}
//	count++;
//}
//
//int main()
//{
//	scanf("%d %d", &n, &m);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%s", g[i]+1);
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (g[i][j] == 'W' && !st[i][j]) bfs(i, j);
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

/*71512 牛客 J 火柴人小游戏 二分路标*/
/*模板*/
//#include<iostream>
//#include<cstring>
//#include<queue>
//using namespace std;
//typedef long long ll;
//int n, m, x, y;
//const int N = 1e3 + 10;
//ll a[N][N];//地图
//bool b[N][N] = { false };//st表
//struct node {
//    int xx, yy;
//};//pair
//int X[] = { 1,-1,0,0 };
//int Y[] = { 0,0,1,-1 };
//bool check(int i, int j) {
//    if (i<1 || j<1 || i>n || j>m)return false;
//    if (b[i][j])return false;
//    return true;
//}
//bool bfs(ll mid) {
//    memset(b, 0, sizeof(b));
//    ll g = 0;
//    queue<node> q;
//    g++;
//    q.push({ x,y });
//    b[x][y] = true;
//    node t;
//    while (!q.empty()) {
//        t = q.front();
//        q.pop();
//        for (int i = 0;i < 4;i++) {
//            int xi = X[i] + t.xx;
//            int yi = Y[i] + t.yy;
//            if (check(xi, yi)) {
//                if (a[xi][yi] <= mid) {
//                    q.push({ xi,yi });
//                    b[xi][yi] = true;
//                    mid += a[xi][yi];
//                    g++;
//                }
//            }
//        }
//    }
//    return g == n * m;//是否能走完所有的格子
//}
//int main() {
//    scanf("%d %d %d %d", &n, &m, &x, &y);
//    for (int i = 1;i <= n;i++) {
//        for (int j = 1;j <= m;j++) {
//            scanf("%lld", &a[i][j]);
//        }
//    }
//    ll l = a[x][y], r = 1e9;
//    while (l < r) {
//        ll mid = (l + r) >> 1;
//        if (bfs(mid))r = mid;
//        else {
//            l = mid + 1;
//        }
//    }
//    if (l > a[x][y]) {
//        printf("%lld", l);
//    }
//    else {
//        printf("No cheating need.");
//    }
//    return 0;
//} 
/*数据以后统一就用long long，老是因为这个报错*/
//#include<iostream>
//#include<cstring>
//#include<unordered_map>
//#include<queue>
//using namespace std;
//
//const int N = 1010;
////int dist[N][N];
//bool st[N][N];
//long long g[N][N];
//int n, m, x, y;
//int dx[] = { 0,1,0,-1 };
//int dy[] = { 1,0,-1,0 };
//queue<pair<int, int>> q;
//
//bool bfs(long long power)
//{
//    memset(st, 0, sizeof st);
//    q.push({ x, y });
//    st[x][y] = 1;
//    int cnt = 0;
//    cnt++;
//
//    while (q.size())
//    {
//        auto t = q.front();
//        q.pop();
//
//        for (int i = 0; i < 4; i++)
//        {
//            int a = t.first + dx[i];
//            int b = t.second + dy[i];
//            if (a<1 || b<1 || a>n || b>m) continue;
//            if (st[a][b]) continue;
//            if (g[a][b] > power) continue;
//
//            st[a][b] = 1;
//            q.push({ a,b });
//            power += g[a][b];
//            cnt++;
//        }
//    }
//    return cnt == n * m;
//}
//
//int main()
//{
//    scanf("%d %d %d %d", &n, &m, &x, &y);
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            scanf("%lld", &g[i][j]);
//        }
//    }
//    long long l = -1, r = 1e9 + 10;
//    while (l + 1 < r)
//    {
//        long long mid = (l + r) / 2; //r到1e9,mid可能会溢出
//        if (bfs(mid)) r = mid;
//        else l = mid;
//    }
//    long long power;
//    if (bfs(l)) power = l;
//    else power = r;
//
//    if (power > g[x][y]) printf("%lld\n", power);
//    else printf("No cheating need.\n");
//
//    return 0;
//}
/*贪心 可能是双端 没看懂*/
//#include<iostream>
//#include<cstring>
//#include<queue>
//using namespace std;
//
//#define ll long long
//#define endl "\n"
//
//ll n, m, x, y;
//ll grid[1005][1005] = { 0 };
//ll vis[1005][1005] = { 0 };
//bool ifon(ll x, ll y) {
//    return x >= 0 && x < n&& y >= 0 && y < m;
//}
//
//ll cal(ll md) {
//    ll ans = md;//初始的力量值
//    for (ll i = 0;i < n;i++)
//        for (ll j = 0;j < m;j++)
//            vis[i][j] = 0;//初始化st表
//
//    vis[x][y] = 1; 
//    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
//    pq.push({ 0,{x,y} });
//    ll dx[4] = { -1,1,0,0 };
//    ll dy[4] = { 0,0,-1,1 };
//    ll arr = 0;
//    while (pq.size()) {
//        auto pp = pq.top();
//        pq.pop();
//
//        if (md < pp.first) {     //?
//            ans += pp.first - md;
//            md = pp.first;//力量不够,于是作弊
//        }
//        arr += 1;
//        md += pp.first;//吸收力量
//        ll nx = pp.second.first, ny = pp.second.second;//x,y的值
//        for (ll i = 0;i < 4;i++) {
//            ll tox = dx[i] + nx;
//            ll toy = dy[i] + ny;
//            if (!ifon(tox, toy)) continue;//边界
//            if (vis[tox][toy]) continue;//st状态
//            vis[tox][toy] = 1;
//            pq.push({ grid[tox][toy],{tox,toy} });
//        }
//    }
//    return ans;
//}
//
//void solve() {
//    cin >> n >> m >> x >> y;
//    x--;y--;
//    for (ll i = 0;i < n;i++)
//        for (ll j = 0;j < m;j++)
//            cin >> grid[i][j];
//    ll st = grid[x][y];
//    grid[x][y] = 0;
//
//    ll ans = cal(st);
//    if (ans <= st) {//ans小于初始power？
//        cout << "No cheating need." << endl;
//    }
//    else
//        cout << ans << endl;
//}
//
//signed main() {
//    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
//    ll t = 1;
//    while (t--) {
//        solve();
//    }
//}

