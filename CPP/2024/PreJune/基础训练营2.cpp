#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
using namespace std;

/*A Tokitsukaze and Bracelet */
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;
//
//int da[] = { 100,150,200 };
//int db[3][4] = { {29,30,31,32} ,{34,36,38,40}, {45} };
//int n;
//int a[110], b[110], c[110];
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		scanf("%d %d %d", &a[i], &b[i], &c[i]);
//	}
//	for (int i = 0; i < n; i++) {
//		int ans = 0;
//		for (int j = 0; j < 3; j++) {
// 			if (a[i] == da[j]) ans += j;
//			for (int k = 0; k < 4; k++) {
//				if (b[i] == db[j][k]) ans += j;
//				if (c[i] == db[j][k]) ans += j;
//			}  
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}

/*M Tokitsukaze and Password (EX) */

/*B Tokitsukaze and Cats */
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;
////数边长
//const int N = 310;
//int dx[] = { 0,1,0,-1 };
//int dy[] = { 1,0,-1,0 };
//bool st[N][N];
//int arr[N][N] = { 0 };
//int n, m, k;
//pair<int, int> q[N * N * 10];
//int hh = 0, tt = 0;
//int res = 0;
//
//void bfs() {
//
//	while (hh <= tt) {
//		auto t = q[hh++];
//		int x = t.first;
//		int y = t.second;
//		if (st[x][y]) continue;
//		st[x][y] = 1;
//		for (int i = 0; i < 4; i++) {
//			int xx = x + dx[i];
//			int yy = y + dy[i];
//			if (xx <= 0 || yy <= 0 || xx > n || yy > m) continue;
//			if (st[xx][yy] || !arr[xx][yy]) continue;
//			q[tt++] = { xx,yy };
//			res++;
//		}
//	}
//	
//}
//
//int main() {
//	cin >> n >> m >> k;
//	memset(st, 0, sizeof st);
//	memset(arr, 0, sizeof arr);
//	int ans = k * 4;
//	while (k--) {
//		int x, y; cin >> x >> y;
//		arr[x][y] = 1;
//		q[tt++] = { x,y };
//	}
//	bfs();
//	printf("%d\n",ans-res);
//	return 0;
//}

/*C Tokitsukaze and Min-Max XOR */
////1<=b<=n
////严格递增
////最大|最小 <= k
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;

/*E&F Tokitsukaze and Eliminate (easy) */
////WA: 究极sb想写continue写了return
////TLE: 计算t值的方式不对
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<string>
//#include<map>
//#include<queue>
//using namespace std;
//#define ll long long
//const int N = 2e5 + 10;
////贪心，每次从最右找
//int T, n;
//map<int, int> g;
//int arr[N];
//
//int main() {
//	cin >> T;
//	while (T--) {
//		g.clear();
//		int tmp = 0;
//		scanf("%d", &n);
//		for (int i = 0; i < n; i++) {
//			scanf("%d", &arr[i]);
//			//if (!g[arr[i]])tmp++;
//			g[arr[i]]++;
//		}
//		if (n == 1) {
//			printf("%d\n", 1);
//			continue;
//		}
//		int r = n - 1;
//		int res = 0;
//		int size = g.size();
//			while (r >= 0) {
//				int t = size;
//				map<int, bool> mp;
//				int l = r;
//				for (l = r; l >= 0 && t;l--) {
//					if (!mp[arr[l]]) t--;
//					mp[arr[l]] = 1;
//					g[arr[l]]--;
//					if (g[arr[l]] == 0) size--;
//				}
//				r = l;
//				res++;
//			}
//		printf("%d\n", res);
//	}
//	return 0;
//}