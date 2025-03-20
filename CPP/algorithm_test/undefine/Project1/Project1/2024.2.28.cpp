#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//int arr[1000];
//void so1() {
//    int sum = 0;
//    for (int i = 1; i <= 100; i++) {
//        sum += 2 * i - 1;
//        arr[i] = sum * 2 - 1;
//    }
//}
//
//int main() {
//    char ch;
//    int n; cin >> n >> ch;
//    int ans = 0;
//    int cnt = 0;
//    so1();
//    //for(int i : arr) cout << i << " ";
//    for (int i = 1; i <= 100; i++) {
//        if (arr[i] > n) {
//            ans = n - arr[i - 1];
//            cnt = i - 1;
//            break;
//        }
//    }
//    int res = 0;
//    for (int i = 0; i < cnt; i++) {
//        for (int j = 0; j < cnt * 2 - 1; j++) {
//            if (j >= res && j < cnt * 2 - 1 - res) {
//                cout << ch;
//            }
//            else cout << " ";
//        }
//        cout << "\n";
//        res++;
//    }
//    res = cnt;
//    for (int i = 0; i < cnt; i++) {
//        res--;
//        if (i == 0) continue;
//        for (int j = 0; j < cnt * 2 - 1; j++) {
//            if (j >= res && j < cnt * 2 - 1 - res) {
//                cout << ch;
//            }
//            else cout << " ";
//        }
//        cout << "\n";
//    }
//    cout << ans << "\n";
//
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int n;
//    char c;
//    scanf("%d %c", &n, &c);
//    int sum = 1;//沙漏需要的字符个数
//    int i = 1;//层数
//    while (sum <= n)
//    {
//        sum += 2 * (2 * (i + 1) - 1);//2n-1是一层的个数，乘以2代表两层一共需要的
//        if (sum <= n)
//            i++;
//    }
//    int j, k;
//    for (j = 0;j < i;j++)//打印上半部分
//    {
//        for (k = 0;k < j;k++)
//            printf(" ");
//        for (k = 0;k < 2 * (i - j) - 1;k++)
//        {
//            printf("%c", c);
//        }//输出*
//
//
//        printf("\n");
//    }
//    for (j = 2;j <= i;j++)
//    {
//        for (k = 0;k < i - j;k++)
//            printf(" ");
//        for (k = 0;k < 2 * j - 1;k++)
//        {
//            printf("%c", c);
//        }
//
//
//        printf("\n");
//    }
//    printf("%d", n - (sum - 2 * (2 * (i + 1) - 1)));
//
//
//}

//#include<iostream>
//#include<string>
//#include<vector>
////gcc lcd
//using namespace std;
//#define ll long long
//ll pr[110];
//ll ed[110];
//ll x;
//void gcd(ll a, ll b) {
//    if (a % b == 0) x = b;
//    else gcd(b, a % b);
//}
//int main() {
//    ios::sync_with_stdio(0);
//    int n; cin >> n;
//    ll maxn = 0;
//    for (int i = 0; i < n; i++) {
//        string s; cin >> s;
//        string s1, s2;
//        bool flag = 0;
//        for (char ch : s) {
//            if (ch == '/') {
//                flag = 1;
//                continue;
//            }
//            if (!flag) {
//                s1 += ch;
//            }
//            else s2 += ch;
//        }
//        pr[i] = stoi(s1);
//        ed[i] = stoi(s2);
//        maxn = max(maxn, ed[i]);
//    }
//    for (int i = 0; i < n; i++) {
//        if (ed[i] < maxn) {
//           gcd(ed[i], maxn);
//           maxn = max(maxn * ed[i] / x, maxn);
//        }
//    }
//    ll spr = 0;
//    for (int i = 0; i < n; i++) {
//        pr[i] *= maxn / ed[i];
//        spr += pr[i];
//    }
//    gcd(spr, maxn);
//    spr /= x;
//    maxn /= x;
//    ll ans = spr / maxn;
//    if(ans)spr -= ans*maxn;
//    if (ans && spr) {
//        cout << ans << " ";
//    }
//    else if (ans && !spr) {
//        cout << ans;
//    }
//    if (spr) {
//        cout << spr << "/" << maxn << "\n";
//    }
//    if (!spr && !ans) {
//        cout << 0 << "\n";
//    }
//  
//    return 0;
//}

/*2024.3.4 hy*/
//#include<iostream>
//using namespace std;
//int main() {
//	cout << (-11) % 10 << "\n";
//	int a = -1;
//	cout <<  a % 10 << "\n";
//	return 0;
//}

/*2024.3.4 hy*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//bool vis[25][25] = { false };
//bool memo[25][25] = { true };//记忆化,只记录错误的
//int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
//int fx[25] = { 0 }, fy[25] = { 0 };//目标
//int sx[25] = { 0 }, sy[25] = { 0 };//实际
//int N = 0, step = 0;
//vector <int> ans;
////防止越界
//bool check(int x, int y) {
//    if (x<1 || x>N || y<1 || y>N || fx[x] < (sx[x]+1) || fy[y] < (sy[y]+1)) {
//        return false;
//    }
//    else {
//        return true;
//    }
//}
////搜索
//bool dfs(int x, int y, int cnt) {
//    if (!memo[x][y]) {
//        return false;
//    }
//    //终止
//    if (x == N && y == N && cnt == step) {
//        ans.push_back(N * N - 1);
//        return true;
//    }
//    //四个方向遍历
//    for (int i = 0;i < 4;i++) {
//        int nx = x + dx[i], ny = y + dy[i];
//        if (!vis[nx][ny] && check(nx, ny)) {
//            vis[nx][ny] = true;
//            sx[nx]++;sy[ny]++;
//            if (dfs(nx, ny, step + 1)) {
//                ans.push_back((nx - 1) * N + ny - 1);
//                return true;
//            }
//            //回溯
//            vis[nx][ny] = false;
//            sx[nx]--;sy[ny]--;
//        }
//    }
//    //四个方向都不对
//    return memo[x][y] = 0;
//}
//int main()
//{
//    memset(memo, 1, sizeof memo);
//    cin >> N;
//    for (int i = 1;i <= N;i++) {
//        cin >> fy[i];
//        step += fy[i];
//    }
//    for (int i = 1;i <= N;i++) {
//        cin >> fx[i];
//        step += fx[i];
//    }
//    //因为narrow固定所以步数固定
//    step = step >> 1;
//    //初始化地图
//    sx[1]++;sy[1]++;
//    if (dfs(1, 1, 1)) cout << "Yes";
//    else cout << "No";
//    reverse(ans.begin(), ans.end());
//    for (auto s : ans)cout << s << ' ';
//    return 0;
//}
