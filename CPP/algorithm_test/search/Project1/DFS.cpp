#define _CRT_SECURE_NO_WARNINGS 1
//ctrl+M,L

/*Lanqiao ·��֮��*/
//#include<bits/stdc++.h>
//using namespace std;
//int n;
//bool st[30][30];
//int xba[30];
//int yba[30];
//int xnow[30], ynow[30];
//bool emo[30][30]; //1����ͨ
//int dx[] = { 0,1,0,-1 };
//int dy[] = { 1,0,-1,0 };
//int g[30][30];
//int step = 0;
//bool flag = 0;
//vector<int> ans;
//void dfs(int x,int y, int res) {
//	if (step <= res) {
//		if (step == res && x == n && y == n) {
//			flag = 1;
//		}
//		return;
//	}
//	for (int i = 0; i < 4; i++) {
//		int xx = x + dx[i];
//		int yy = y + dy[i];
//		if (st[xx][yy] || xx < 1 || xx > n || yy < 1 || yy > n) continue;
//		if (xnow[xx] + 1 > xba[xx] || ynow[yy] + 1 > yba[yy]) continue;
//		st[xx][yy] = 1;
//		xnow[xx]++;
//		ynow[yy]++;
//		dfs(xx, yy, res+1);
//		if (flag) {
//			ans.push_back(g[xx][yy]);
//			return;
//		} 
//		st[xx][yy] = 0;
//		xnow[xx]--;
//		ynow[yy]--;
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> yba[i];
//	for (int j = 1; j <= n; j++) {
//		cin >> xba[j];
//		step += xba[j];
//	}
//	int cnt = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			g[i][j] = cnt++;
//		}
//	}
//	xnow[1]++;
//	ynow[1]++;
//	dfs(1, 1 ,1);
//	ans.push_back(g[1][1]);
//	for (int i = ans.size() - 1; i >= 0; i--) {
//		cout << ans[i] << " ";
//	}cout << "\n";
//
//	return 0;
//}

/*NC24739 Lake Counting (English)*/
//8��ͨ
//#include<iostream>
//#include<cstring>
//using namespace std;
//int n, m;
//char g[110][110];
//bool st[110][110];
//int res = 0;
//int dx[] = { 1,1,1,0,0,-1,-1,-1 };
//int dy[] = { 1,-1,0,-1,1,1,-1,0};
//void dfs(int x, int y)
//{
//	for (int i = 0; i < 8; i++)
//	{
//		int xx = x + dx[i];
//		int yy = y + dy[i];
//		if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
//		if (st[xx][yy] || g[xx][yy] == '.') continue;
//		st[xx][yy] = 1;
//		dfs(xx, yy);
//	}
//}
//
//int main()
//{
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++) scanf("%s", g + i);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (st[i][j] || g[i][j] == '.') continue;
//			res++;
//			st[i][j] = 1;
//			dfs(i, j);
//		}
//	}
//	printf("%d\n", res);
//	return 0;
//}

/*NC15434 wyh���Թ�*/
//#include<iostream>
//#include<cstring>
//using namespace std;
//int T, n, m;
//const int N = 510;
//bool st[N][N];
//char map[N][N];
//int dx[] = { 1,0,-1,0 };
//int dy[] = { 0,1,0,-1 };
//int x, y, ex, ey;
//bool ans = 0;
//void dfs(int x, int y)
//{
//	if (x == ex && y == ey)
//	{
//		ans = 1;
//		return;
//	}; 
//
//	for (int i = 0; i < 4; i++)
//	{
//		int xx = x + dx[i];
//		int yy = y + dy[i];
//		if (st[xx][yy] || xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
//		if (map[xx][yy] == 'x') continue;
//		st[xx][yy] = 1;
//		dfs(xx, yy);
//		//st[xx][yy] = 0; //�Ѿ��߹���·����Ҫ����
//	}
//}
//
//int main()
//{
//	scanf("%d", &T);
//	
//	while (T--)
//	{
//		scanf("%d %d", &n, &m);
//		memset(st, 0, sizeof st);
//		ans = 0;
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				scanf("%c", &map[i][j]);
//				if (map[i][j] == 's')x = i, y = j;
//				else if (map[i][j] == 't') ex = i, ey = j;
//			}
//		}
//		dfs(x, y);
//		if (ans) printf("YES\n");
//		else printf("NO\n");
//	}
//	return 0;
//}

/*NC16417 ����*/

/*NC15291 �������֢�(��)�����ɣ�*/
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#define ll long long
//using namespace std;
//const int N = 1e4 + 10;
//ll arr[N] = { 0 };
//ll l, r;
//ll ans = 0;
//int cnt = 0;
//
//void dfs(ll x)
//{
//	if (x > r*10) return;
//	arr[cnt++] = x;
//	dfs(x * 10 + 4);
//	dfs(x * 10 + 7);
//}
//
//int main()
//{
//	scanf("%lld %lld", &l, &r);
//	dfs(4);
//	dfs(7);
//	sort(arr, arr + cnt);
//	//�����ұ߽�(����ֵ��һ����ַ)
//	int L = lower_bound(arr, arr + cnt, l) - arr;//�õ��±�λ��
//	int R = upper_bound(arr, arr + cnt, r) - arr;
//	for (int i = L; i <= R; i++)
//	{
//		ans += (min(arr[i], r) - l + 1) * arr[i];
//		l = min(arr[i], r) + 1;
//	}
//	printf("%lld\n", ans);
//	return 0;
//}

/*NC24911 ������ս (��)�����ɣ�*/
//#include<iostream>
//#include<cstring>
//using namespace std;
////��������ж�����x��y�ĵ����ڵڼ����Ź������棬
//
//const int g[10][10] = { {0,0,0,0,0,0,0,0,0,0},
//					 {0,1,1,1,2,2,2,3,3,3},
//					 {0,1,1,1,2,2,2,3,3,3},
//					 {0,1,1,1,2,2,2,3,3,3},
//					 {0,4,4,4,5,5,5,6,6,6},
//					 {0,4,4,4,5,5,5,6,6,6},
//					 {0,4,4,4,5,5,5,6,6,6},
//					 {0,7,7,7,8,8,8,9,9,9},
//					 {0,7,7,7,8,8,8,9,9,9},
//					 {0,7,7,7,8,8,8,9,9,9}, };
////space ���ڼ�¼��Ҫ����λ������
//struct space
//{
//	int x, y;
//} space[90];
//
//bool h[10][10],l[10][10],st[10][10]; //�ж�ĳ�����Ƿ�������j
//int arr[10][10]; 
//int cnt = 0;
//
//void dfs(int dep) //���������,����Ҫ�����������
//{
//	if (dep > cnt) {
//		for (int i = 1; i <= 9; i++) {
//			for (int j = 1; j <= 9; j++) {
//				printf("%d ", arr[i][j]);
//			}
//			printf("\n");
//		}
//		return;
//	}
//	for (int i = 1; i <= 9; i++)
//	{
//		if (h[space[dep].x][i] || l[space[dep].y][i]
//			|| st[g[space[dep].x][space[dep].y]][i]) continue;
//		h[space[dep].x][i] = l[space[dep].y][i]
//			= st[g[space[dep].x][space[dep].y]][i] = 1;
//		arr[space[dep].x][space[dep].y] = i;
//		dfs(dep + 1);
//		h[space[dep].x][i] = l[space[dep].y][i]
//			= st[g[space[dep].x][space[dep].y]][i] = 0;
//		arr[space[dep].x][space[dep].y] = 0;
//	}
//}
//
//int main()
//{
//	for (int i = 1; i <= 9; i++)
//	{
//		for (int j = 1; j <= 9; j++)
//		{
//			scanf("%d", &arr[i][j]);
//			if (arr[i][j] == 0)
//			{
//				space[++cnt].x = i;
//				space[cnt].y = j;
//			}
//			else
//			{
//				h[i][arr[i][j]] = l[j][arr[i][j]] = st[g[i][j]][arr[i][j]] = 1;
//			}
//		}
//	}
//	dfs(1);
//	return 0;
//}

/*NC235814 ��̤����*/
//#include<iostream>
//#include<cstring>
//using namespace std;
//int n, m;
//int dx[] = { 1,1,2,2 };
//int dy[] = { 2,-2,1,-1 };
//int res = 0;
//
//void dfs(int x, int y)
//{
//	if (x == n && y == m)
//	{
//		res++;
//		return;
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		int xx = x + dx[i];
//		int yy = y + dy[i];
//		if (xx < 1 || xx > n || yy < 1 || yy > m) continue;//Խ���˳�
//		//printf("%d %d\n", xx, yy); //��ӡ
//		dfs(xx, yy);
//	}
//}
//
//int main()
//{
//	scanf("%d %d", &m, &n); //��ӡ��һ�£���������������������⣬Ӧ���ǵ�(m,n)
//	dfs(1, 1);
//	printf("%d\n", res);
//	return 0;
//}

/*NC235813 N�ʺ����� ������*/
////����ͬһ�С�ͬһ�У�����ͬһ�Խ���
////�Խ��ߵ��ж� ����x-y��ͬ������x+y��ͬ��
//#include<iostream>
//#include<cstring>
//using namespace std;
//bool col[20], dg[20], udg[30];            
//int res = 0;
//int n;
//void dfs(int x)
//{
//	if (x > n)
//	{
//		res++;
//		return;
//	}
//	for (int i = 1; i <= n; i++)//ģ�����зŶ���
//	{
//		if (col[i]||dg[x+i]||udg[n - x + i]) continue; //��+n����֤����
//		col[i] = 1;dg[x + i] = 1;udg[n - x + i] = 1;
//		dfs(x + 1); //��һ��
//		col[i] = 0;dg[x + i] = 0;udg[n - x + i] = 0;
//	}
//}
//
//int main()
//{
//	scanf("%d", &n);
//	dfs(1);
//	printf("%d\n", res);
//	return 0;
//}

/*NC15128 ���ӵ�ȫ������*/
////1-8��ȫ����
//#include<iostream>
//int a[10];
//bool st[10];
//
//void dfs(int x)
//{
//	if (x > 8)
//	{
//		for (int i = 1;i <= 8; i++) printf("%d ", a[i]);
//		printf("\n");
//		return;
//	}
//	for (int i = 1; i <= 8; i++)
//	{
//		if (st[i]) continue;
//		a[x] = i;
//		st[i] = 1;
//		dfs(x+1);
//		st[i] = 0;
//	}
//}
//
//int main()
//{
//	dfs(1);
//	return 0;
//}

/*��׼�������*/
//#include<iostream>
//const int N = 21;
//int r, n;
//int arr[N];
//void dfs(int x, int start)
//{
//	if (x > r)//> r֮�����֦������
//	{
//		if (1)
//		{
//			for (int i = 1; i <= r; i++)
//			{
//				printf("%3d", arr[i]);
//			}
//			printf("\n");
//		}
//		return;
//	}
//
//	for (int i = start; i <= n; i++)
//	{
//		arr[x] = i;
//		dfs(x + 1, i + 1);
//		arr[x] = 0;
//	}
//}
//int main()
//{
//	scanf("%d %d", &n, &r);
//	dfs(1,1);
//	return 0;
//}

/*p1019 luogu ���ʽ���*/
//#include<iostream>
//#include<algorithm>
//const int N = 21;
//int st[N] = { 0 };//���ô���
//std::string words[N];
//int n;
//int g[N][N];//g[i][j] ��i���������j�����ʵ��غϳ���
//int ans = 0;
//
//void dfs(std::string dargon, int x)
//{
//	ans = std::max(ans, (int)dargon.size());
//	st[x]++;
//	for (int j = 0; j < n; j++)
//	{
//		if (g[x][j] && st[j] < 2)
//		{
//			dfs(dargon + words[j].substr(g[x][j]), j);
//		}
//	}
//	st[x]--;
//}
//
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) std::cin >> words[i];
//	char start;
//	std::cin >> start;
//
//	//Ԥ����
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			std::string a = words[i];
//			std::string b = words[j];
//			for (int k = 1; k < std::min(a.size(),b.size()); k++)
//			{
//				if (a.substr(a.size() - k, k) == b.substr(0, k))
//				{
//					g[i][j] = k;
//					break;
//				}
//			}
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		if (words[i][0] == start)
//		{
//			dfs(words[i], i);
//		}
//	}
//
//	printf("%d\n", ans);
//	return 0;
//}

/*p1025 luogu ���Ļ��� ����� ������ͬ����*/
//#include<iostream>
//
//int n, k;
//int res = 0;
//
//void dfs(int x ,int start, int sum)
//{
//	if (x > k)
//	{
//		if(sum == n) res++;
//		return;
//	}
//	for (int i = start; sum+(k -x+1)*i <= n; i++)/*��֦*/
//	{
//		dfs(x + 1, i, sum + i);
//	}
//}
//
//int main()
//{
//	scanf("%d %d", &n, &k);
//	dfs(1, 1, 0);
//	printf("%d\n", res);
//	return 0;
//}

/*p1114 AcWing �������� ȫ���� ����*/
//#include<iostream>
//int n, k;
//const int N = 10;
//char arr[N][N];
//bool st[N];//��¼ÿ���Ƿ��������
//int res = 0;
//
//void dfs(int x, int c)
//{
//	if (c == k)
//	{
//		res++;
//		return;
//	}
//	if (x >= n) return;
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[x][i] == '#' && !st[i])//x�еĵ�i��
//		{
//			st[i] = 1;
//			dfs(x + 1, c + 1);
//			st[i] = 0;
//		}
//	}
//	dfs(x + 1, c);//ǿ������һ��
//	/*���ʣ�ΪʲôҪǿ������һ���أ�*/
//  //�統��1��1��#��ֻ��Ҫ��һ�����ӵ�ʱ�򣬵�һ��ֱ�ӷ��أ���һ��ֻ��������һ�е���������������
//	//���� #.
//	//	   .#
//
//
//}
//
//int main()
//{
//	scanf("%d %d", &n, &k);
//	while (n != -1 && k != -1)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%s", arr[i]);
//		}
//
//		//ȫ����
//		dfs(0, 0);
//		printf("%d\n", res);
//		res = 0;
//
//		scanf("%d %d", &n, &k);
//	}
//	return 0;
//}

/*p1596 luogu  Lake Counting S ��ˮ���*/
//#include<iostream>
//const int N = 101;
//char arr[N][N];
//bool st[N][N];
//int n, m;//hang lie
//int res = 0;
//int xdis[8] = { 1,1,1,0,0,-1,-1,-1 };
//int ydis[8] = { 1,0,-1,1,-1,1,0,-1 };
//
//void dfs(int x, int y)
//{
//	for (int i = 0; i < 8; i++)
//	{
//		int xx = xdis[i] + x;
//		int yy = ydis[i] + y;
//		if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
//		if (arr[xx][yy] != 'W') continue;
//		if (st[xx][yy]) continue;
//
//		st[xx][yy] = 1;
//		dfs(xx, yy);
//	}
//	return;
//}
//
//int main()
//{
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s", arr[i]);
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (arr[i][j] == 'W' && !st[i][j])
//			{
//				st[i][j] = 1;
//				dfs(i, j);
//				res++;
//			}
//		}
//	}
//	printf("%d\n", res);
//	return 0;
//}

/*p1683 luogu ���� �Թ�*/
//#include<iostream>
//#include<algorithm>
//
//int H, W;
//const int N = 21;
//int res = 0;
//char arr[N][N];
//bool st[N][N];
//int disx[] = { -1,0,1,0 };�������һ�����ϣ��ң��£���
//int disy[] = { 0,1,0,-1 };
//
//void dfs(int h, int w)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		int x = h + disx[i];
//		int y = w + disy[i];
//		if (x >= H || y >= W || x < 0 || y < 0) continue;
//		if (arr[x][y] != '.') continue;
//		if (st[x][y]) continue;
//		st[x][y] = 1;
//		res++;
//		dfs(x, y);
//	}
//}
//
//int main()
//{
//	scanf("%d %d", &W, &H);
//	for (int i = 0; i < H; i++)
//	{
//		scanf("%s", arr[i]);
//	}
//	for (int i = 0; i < H; i++)
//	{
//		for (int j = 0; j < W; j++)
//		{
//			if (arr[i][j] == '@')
//			{
//				dfs(i, j);
//				printf("%d\n", ++res);
//				return 0;
//			}
//		}
//	}
//	return 0;
//}

/*p1135 luogu ��ֵĵ��� ���� 64��*/
//#include<iostream>
//#include<algorithm>
//
//const int N = 10010;
//int n, A, B;
//int k[N];
//bool st[N];
//int res = 2e9;
//
//void dfs(int x, int c)
//{
//	if (c >= res) return;
//
//	if (x == B)
//	{
//		res = std::min(res, c);
//		return;
//	}
//	if (x + k[x] <= n && !st[x + k[x]])
//	{
//		st[x + k[x]] = 1;
//		dfs(x + k[x], c + 1);
//		st[x + k[x]] = 0;
//	}
//	if (x - k[x] > 0 && !st[x - k[x]])
//	{
//		st[x - k[x]] = 1;
//		dfs(x - k[x], c + 1);
//		st[x - k[x]] = 0;
//	}
//}
//
//int main()
//{
//	scanf("%d %d %d", &n, &A, &B);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &k[i]);
//	}
//	dfs(A, 0);
//	if (res == 2e9)	printf("%d\n", -1);
//	else            printf("%d\n", res);
//	return 0;
//}

/*p2089 luogu */
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<vector>
//int n;
//std::vector<std::vector<int>> ans;
//std::vector<int> a;
//int res;
//void dfs(int x, int sum)
//{
//	//��֦
//	if (sum > n)
//	{
//		return;
//	}
//	if (x > 10)
//	{
//		if (sum == n)
//		{
//			res++;//�����res��
//			ans.push_back({ a });
//		}
//		return;
//	}
//	for (int i = 1; i <= 3; i++)
//	{
//		a.push_back(i);
//		dfs(x+1, sum+i);
//		a.pop_back();
//	}
//}
//int main()
//{
//	a.reserve(10);
//	scanf("%d", &n);
//	dfs(1, 0);
//	printf("%d\n", res);
//	for (int i = 0;i < ans.size();i++)
//	{
//		for (int j : ans[i])
//		{
//			printf("%d ", j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

/*p1036 luogu */
//using namespace std;
//const int N = 21;
//int n, k;
//int arr[N];
//int q[N];
//int res = 0;
//bool is_prim(int sum)
//{
//	if (sum < 2) return 0;
//	for (int i = 2; i <= sum / i; i++)
//	{
//		if (sum % i == 0) return 0;
//	}
//	return 1;
//}
//void dfs(int x, int start)
//{
//	if (x - 1 + n - start + 1 < k)//(x - 1)�Ѿ�������֦��(n - start + 1)ʣ�µ�֦
//	{
//		return;
//	}
//	if (x > k)
//	{
//		int sum = 0;
//		for (int i = 1; i <= k; i++)
//		{
//			sum += arr[i];
//		}
//		if (is_prim(sum))
//		{
//			res++;
//		}
//		return;
//	}
//	for (int i = start; i <= n; i++)
//	{
//		arr[x] = q[i];
//		dfs(x + 1, i + 1);
//		arr[x] = 0;
//	}
//}
//int main()
//{
//	scanf("%d %d", &n, &k);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &q[i]);
//	}
//	dfs(1, 1);
//	printf("%d\n", res);
//	return 0;
//}

/*p2036 luogu Perket ȫ����*/
//#include<iostream>
//#include<cmath>
//
//int n;
//int s[11];
//int k[11];
//int s_sum = 1;
//int k_sum = 0;
//int min = INT_MAX;
//
//void dfs(int x, int start)
//{
//	if (x > n)
//		return;
//	for (int i = start; i <= n; i++)
//	{
//		s_sum *= s[i];
//		k_sum += k[i];
//		min = min < abs(s_sum - k_sum) ? min : abs(s_sum - k_sum);
//		dfs(x + 1, i + 1);
//		s_sum /= s[i];
//		k_sum -= k[i];
//	}
//}
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d %d", &s[i], &k[i]);
//	}
//	dfs(1, 1);
//	printf("%d\n", min);
//	return 0;
//}

/*p1088 luogu ������ ȫ����(�ֵ���) ͨ����˵��������ͬ����*/
//#include<vector>
//#include<iostream>
// 
//const int N = 1e4 + 1;
//int n, m;
//int q[N];
//bool st[N];
//int arr[N];
//int count = 0;
// 
//void dfs(int x)
//{
//	if (x > n)
//	{
//		count++;
//		if (m + 1 == count)//m�Ǽӵ�������1Ϊ�ܴ���
//		{
//			for (int i = 1; i <= n; i++)
//			{
//				printf("%d ", arr[i]);
//			}
//		}
//		return;
//	}
//	for (int i = 1; i <= n && m + 1 != count; i++)
//	{
//		if (!count)
//		{
//			i = q[x];//����ǵ�һ���ң����ҵ�q��Ӧ��֦
//		}
//		if (!st[i])
//		{
//			arr[x] = i;
//			st[i] = 1;
//			dfs(x + 1);
//			arr[x] = 0;
//			st[i] = 0;
//		}
//	}
//}
// 
//int main()
//{
//	scanf("%d", &n);
//	scanf("%d", &m);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &q[i]);
//	}
//	dfs(1);
//
//	return 0;
//}

/*p1149 luogu ���� Ԥ���� �ֵ���*/
//#include<iostream>
//
//int n;
//const int N = 1e4 + 10;
//int arr[4];
//int fire[10] = { 6,2,5,5,4,5,6,3,7,6 };//����Ӧ����
//int res = 0;
//int sum = 0;
//
//int col(int x)
//{
//	if (x <= 9) return fire[x];
//	int sum = 0;
//	while (x)
//	{
//		sum += fire[x % 10];
//		x /= 10;
//	}
//	return sum;
//}
//
//void dfs(int x)
//{
//	if (sum > n) return;
//	if (x > 3)
//	{
//		if (arr[1] + arr[2] == arr[3] && sum == n)
//		{
//			res++;
//		}
//		return;
//	}
//
//	for(int i = 0;i <= 1000; i++)//��������
//	{
//		arr[x] = i;
//		sum += col(i);
//		dfs(x + 1);
//		arr[x] = 0;
//		sum -= col(i);
//	}
//}
//
//int main()
//{
//	scanf("%d", &n);
//	n -= 4;//Ԥ����+=
//	dfs(1);
//	printf("%d\n", res);
//	return 0;
//}

/*p1451 luogu ��ϸ������ ��ˮ���*/
//#include<iostream>
//#include<cstring>
//
//const int N = 110;
//int n, m;
//char g[N][N];
//bool st[N][N];
//int cot = 0;
//int dx[] = { 0,-1,0,1 };
//int dy[] = { -1,0,1,0 };
//int tmp;
//
//void dfs(int x, int y)
//{
//	st[x][y] = 1;
//	for (int i = 0; i < 4; i++)
//	{
//		int a = x + dx[i];
//		int b = y + dy[i];
//
//		if (a<1 || b<1 || a>n || b>m) continue;
//		if (st[a][b]) continue;
//		if (g[a][b] == '0') continue;
//		st[a][b] = 1;
//		dfs(a, b);
//	}
//	return;
//}
//
//int main()
//{
//	scanf("%d %d", &n, &m);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%s", g[i] + 1);
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			if (!st[i][j] && g[i][j] != '0')
//			{
//				cot++;
//				dfs(i, j);
//
//			}
//		}
//	}
//	printf("%d\n", cot);
//	return 0;
//}

/*pB3621 luogu ö��Ԫ�� ָ��*/
//#include<iostream>
//using namespace std;
//
//const int N = 6;
//int n, k;
//int arr[N];
//
//void dfs(int x)
//{
//	if (x > n)
//	{
//		for (int i = 1; i <= n; i++) printf("%d ", arr[i]);
//		printf("\n");
//		return;
//	}
//	for (int i = 1; i <= k; i++)
//	{
//		arr[x] = i;
//		dfs(x + 1);
//		arr[x] = 0;
//	}
//}
//
//int main()
//{
//	scanf("%d %d", &n, &k);
//	dfs(1);
//
//	return 0;
//}

/*pB3622 luogu ö���Ӽ�*/
//#include<iostream>
//using namespace std;
//const int N = 11;
//
//int n;
//char ans[N] = { 0 };
//char arr[] = { 'N','Y'};
//
//void dfs(int x)
//{
//	if (x > n)
//	{
//	    printf("%s", ans + 1);
//		printf("\n");
//		return;
//	}
//	for (int i = 0; i < 2; i++)
//	{
//		ans[x] = arr[i];
//		dfs(x + 1);
//		ans[x] = 0;
//	}
//}
//
//int main()
//{
//	scanf("%d", &n);
//	dfs(1);
//
//	return 0;
//}




/*useless*/
//#include<stdio.h>
//
//int main()
//{
//	char c1 = 'C';
//	char c2 = 'h';
//	char c3 = 'i';
//	char c4 = 'n';
//	char c5 = 'a';
//	c1 += 4;
//	c2 += 4;
//	c3 += 4;
//	c4 += 4;
//	c5 += 4;
//	
//	putchar(c1);
//	putchar(c2);
//	putchar(c3);
//	putchar(c4);
//	putchar(c5);
//
//	printf("\n%c%c%c%c%c", c1, c2, c3, c4, c5);
//}