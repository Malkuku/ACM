#include <bits/stdc++.h>
using namespace std;
#define ll long long

///*二进制压缩 -- 集合*///

/*AW 91. 最短Hamilton路径 */ //二进制压缩板子
/*2024.7.28*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int g[25][25];
// ll dp[1<<20][25]; //dp[s][j] ,集合s中0到j的最短路
// //s以二进制形式表示 1代表该位置的点在集合内
// int main(){
//     int n;cin >> n;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             cin >> g[i][j];
//         }
//     }
//     memset(dp,0x3f,sizeof dp);
//     dp[1][0] = 0;
//     for(int i = 1; i < (1 << n); i++){
//         for(int j = 0; j < n; j++){
//             if(!((i >> j) & 1))continue; //判断j是否在s中
//             for(int k = 0; k < n; k++){
//                 if(!((i-(1<<j)) >> k & 1))continue; //点k不在s-j中
//                 dp[i][j] = min(dp[i][j],dp[i-(1<<j)][k] + g[k][j]); //s-j到k——》k到j
//             } 
//         }
//     }
//     cout << dp[(1<<n)-1][n-1];
//     return 0;
// }

/*poj 2411 Mondriaan's Dream*/ //轮廓线（精）
/*2024.7.29 题解*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll dp[2][1 << 11];//定义k为轮廓线上的位置，1表示有填充
// int main(){
//     int n,m;
//     while (cin >> n >> m && (n != 0 || m != 0)){
//         if (n < m) swap(n, m); // 根据复杂度o(nm*2^m)优化
//         int now = 0,old = 1;
//         memset(dp,0,sizeof dp);
//         dp[now][(1<<m)-1] = 1;
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 swap(now,old);//更新
//                 memset(dp[now],0,sizeof dp[now]);
//                 for(int k = 0; k < (1 << m); k++){
//                     if(k & (1 << m-1)){ //不填，要求原k上有砖块
//                         dp[now][(k << 1) & ~(1 << m)] += dp[old][k];
//                     }
//                     if(i && !(k & (1 << m-1))){//填竖砖，要求原k上没有砖块且不是第一行
//                         dp[now][((k << 1) | 1) & ~(1 << m)] += dp[old][k];//??
//                     }
//                     if(j && !(k&1) && (k & 1 << m-1)){ //填横砖，要求不是第一列，k0为0，k（m-1）不为0
//                         dp[now][((k << 1) | 3) & ~(1 << m)] += dp[old][k]; //末尾置为11
//                     }
//                 }
//             }
//         }
//         cout << dp[now][(1 << m)-1] << "\n";
//     }
// }

/*hdu 4539 排兵布阵*/ //预处理二进制状态（精）
/*2024.7.29 题解*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int mp[105][12];
// int dp[105][200][200]; //dp[i][j][k] = 到i行时，i行士兵状态为j，i-1行士兵状态为k时，最多的安排数量
// int n,m;
// int sta[200];
// int init(){ //预计算行的合法情况
//     int len = 0;
//     for(int i= 0; i < (1 << m); i++){
//         if((i&(i >> 2)) == 0 && (i&(i << 2)) == 0){ //左右间隔2没人既合法
//             sta[len++] = i;
//         }
//     }
//     return len; //len表示行的最大合法安排
// }
// int count_line(int i,int x){
//     int sum = 0;
//     for(int j = m - 1; j >= 0; j--){ //x--预处理过的合法安排
//         if(x&1) sum += mp[i][j]; //x与地形匹配
//         x >>= 1;
//     }
//     return sum;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     while(cin >> n >> m){
//         int len = init();
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 cin >> mp[i][j];
//             }
//         }
//         int ans = 0;
//         memset(dp,0,sizeof dp);
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < len; j++){ //枚举i行合法情况
//                 for(int k = 0; k < len; k++){ //枚举i-1行合法情况
//                     if(i == 0){ //计算第一行
//                         dp[i][j][k] = count_line(i,sta[j]);
//                         ans = max(ans,dp[i][j][k]);
//                         continue;
//                     }
//                     if((sta[j] & (sta[k] >> 1)) || (sta[j] & sta[k] << 1)) continue;
//                     int tmp = 0;
//                     for(int p = 0; p < len; p++){ //枚举i-2行
//                         if((sta[k] & (sta[p] >> 1)) || (sta[k] & (sta[p] << 1))) continue;
//                         if(sta[j] & sta[p]) continue; //i行与i-2行冲突
//                         tmp = max(tmp,dp[i-1][k][p]);//i-1行向i行递推
//                     }
//                     dp[i][j][k] = tmp + count_line(i,sta[j]);
//                     ans = max(ans,dp[i][j][k]);
//                 }
//             }
//         }
//         cout << ans << "\n";
//     }
//     return 0;
// }

/*P1433 吃奶酪 */
/*2024.7.28*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// pair<double,double> a[20];
// double dist[20][20];
// double dp[1 << 16][20];
// int main(){
//     int n;cin >> n;
//     a[0] = {0,0};
//     for(int i = 1; i <= n; i++){
//         double x,y;cin >> x >> y;
//         a[i] = {x,y};
//     }
//     for(int i = 0; i <= n; i++){
//         for(int j = i+1; j <= n; j++){
//             double x1 = a[i].first,y1 = a[i].second,x2 = a[j].first,y2 = a[j].second;
//             dist[i][j] = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
//             dist[j][i] = dist[i][j];
//         }
//     }
//     memset(dp,127,sizeof dp);
//     double ans = dp[0][0];
//     dp[1][0] = 0;
//     for(int i = 1; i < (1 << n+1); i++){
//         for(int j = 0; j < n+1; j++){
//             if((i >> j) & 1){
//                 for(int k = 0; k < n+1; k++){
//                     if((i-(1 << j) >> k & 1)){
//                         dp[i][j] = min(dp[i][j],dp[(i-(1<<j))][k] + dist[k][j]);
//                     }
//                 }
//             }
//         }
//     }
//     for(int i = 0; i < n+1; i++){
//         ans = min(dp[(1 << n+1) - 1][i],ans);
//     }
//     cout <<fixed << setprecision(2)<< ans << "\n";
//     return 0;
// }


///*三进制压缩 -- 对应三种状态*///

/*hdu 3001 	Travelling*/ //进制压缩模板(精)
/*2024.7.29 题解*/ 
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int n,m;
// int g[11][11];
// int bit[12];//存三进制状态
// const int bit11 = pow(3,10);
// int tri[bit11 + 10][11]; //存所有可能的路径 tir[i][j] //路径i由j点出发
// int dp[11][bit11 + 10]; //dp[j][i] 从j出发，访问路径i中所有城市的最小花费
// //dp[j][i] = min(dp[k][i-bit[j]] + g[k][j]);//从j出发可以等价于从i-j出发到j
// void init(){
//     bit[0] = 0; //事实上，bit[0]并没有意义
//     bit[1] = 1;
//     for (int i = 2; i < 12; i++){
//         bit[i] = bit[i - 1] * 3;
//     }
//     // 初始化所有可能路径
//     for (int i = 0; i <= bit[11]; i++){
//         int t = i;
//         for(int j = 1; j <= 10; j++){
//             tri[i][j] = t % 3; t/= 3;
//         }
//     }
// }
// int main(){
//     init();
//     while(cin >> n >> m){
//         memset(g,0x3f,sizeof g);
//         for(int i = 0; i < m; i++){
//             int a,b,c;cin >> a >> b >> c;
//             if(c < g[a][b]) g[a][b] = g[b][a] = c;
//         }
//         int ans = 0x3f3f3f3f;
//         memset(dp,0x3f,sizeof dp);
//         for(int j = 1; j <= n; j++){
//             dp[j][bit[j]] = 0; //初始化出发地
//         }
//         for(int i = 1; i < bit[n+1]; i++){
//             bool flag = 1;
//             for(int j = 1; j <= n; j++){
//                 if(tri[i][j] == 0){ //是否有没访问的城市
//                     flag = 0;
//                     continue;
//                 }
//                 for (int k = 1; k <= n; k++){
//                     dp[j][i] = min(dp[j][i], dp[k][i - bit[j]] + g[k][j]);
//                 }
//             }
//             if(flag){
//                 for(int j = 1; j <= n; j++){
//                     ans = min(ans,dp[j][i]);
//                 }
//             }
//         }
//         if(ans >= 0x3f3f3f3f) cout << -1 << "\n";
//         else cout << ans << "\n";
//     }
//     return 0;
// }


///*题单*///

/* P5005 中国象棋 - 摆上马 */
/*2024.8.1*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int x,y;
// const int mod = 1e9+7;
// int dp[2][1<<6+1][1<<6+1];
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> x >> y;
//     bool now = 0,old = 1;
//     dp[0][0][0] = 1;
//     for(int i = 1; i <= x; i++){
//         swap(now, old);
//         memset(dp[now], 0, sizeof dp[now]);
//         for(int j = 0; j < (1 << y); j++){
//             for(int k = 0; k < (1 << y); k++){
//                 if (!(!(((j & (~(j >> 1))) & (k >> 2)) || ((j & (~(j << 1))) & (k << 2)) || (((k & (~(k >> 1))) & (j >> 2))) || ((k & (~(k << 1))) & (j << 2)))))continue;
//                 for(int p = 0; p < (1 << y); p++){
//                     if (!(!(((k & (~(k >> 1))) & (p >> 2)) || ((k & (~(k << 1))) & (p << 2)) || (((p & (~(p >> 1))) & (k >> 2))) || ((p & (~(p << 1))) & (k << 2)))))continue;
//                     if (!(!(((j & (~k)) & (p >> 1)) || ((j & (~k)) & (p << 1)) || ((p & (~k)) & (j >> 1)) || ((p & (~k)) & (j << 1)))))continue;
//                     dp[now][j][k] = (dp[now][j][k] + dp[old][k][p]) % mod;
//                 }
//             }
//         }
//     }
//     ll ans = 0;
//     for(int j = 0; j < (1 << y); j++){
//         for(int k = 0; k < (1 << y); k++){
//             ans = (ans + dp[now][j][k]) %mod;
//         }
//     }
//     cout << ans << "\n";
//     return 0;
// }

/*P3694 邦邦的大合唱站队 */ //(精) 01表示排好队情况，思考在前情况排队开销
/*2024.8.1 题解*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int dp[1 << 22];
// const int N = 1e5+10;
// int num[22],sum[N][22];//sum[i][j] 前i个位置中编号为j的合唱队员的个数
// int main(){
//     ios::sync_with_stdio(0);
//     int n,m;cin >> n >> m;
//     for(int i = 1; i <= n; i++){
//         int x;cin >> x;
//         num[x]++;
//         for(int j = 1; j <= m; j++) sum[i][j] = sum[i-1][j];
//         sum[i][x]++;
//     }
//     memset(dp,0x3f,sizeof dp);
//     dp[0] = 0;
//     for(int i = 1; i < (1 << m); i++){
//         int len = 0; //已经排好队的总人数
//         for(int j = 1; j <= m; j++){
//             if(i&(1<<(j-1))) len+=num[j];
//         }
//         for(int j = 1; j <= m; j++){
//             if(i&(1<<(j-1))){
//                 dp[i] = min(dp[i],dp[i-(1<<(j-1))]+num[j] - sum[len][j]+sum[len-num[j]][j]);
//             }
//         }
//     }
//     cout << dp[(1<<m)-1] << "\n";
//     return 0;
// }

/* P3092 [USACO13NOV] No Change G */
/*2024.8.1*/ //又被二分卡了
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// int dp[1 << 16];
// ll sum[N];
// ll coins[16];
// int n,k;
// int find(ll x){
//     int l = 1,r = n;
//     while(l <= r){
//         int mid = (l+r) >> 1;
//         if(sum[mid] > x) r = mid-1;
//         else l = mid+1;
//     }
//     return r;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> k >> n;
//     for (int i = 1; i <= k; i++){
//         cin >> coins[i];
//     }
//     for(int i = 1; i <= n; i++){
//         int x; cin >> x;
//         sum[i] = sum[i-1] + x;
//     }
//     //for(int i = 1; i <= n; i++){
//     //   cout << sum[i] << " ";
//     //}cout << "\n";
//     for(int i = 0; i < (1 << k); i++){
//         for(int j = 1; j <= k; j++){
//             if(i & (1 << (j-1))){
//                 dp[i] = max(dp[i],find(sum[dp[i-(1 << (j-1))]] + coins[j]));
//                 //cout << dp[i - (1 << (j - 1))] << " " << coins[j]<< " " << dp[i] << " " << sum[dp[i - (1 << (j - 1))]] + coins[j] << "\n";
//             }
//         }
//     }
//     ll ans = -1;
//     for(int i = 0; i < (1 << k); i++){
//         if(dp[i] >= n){
//             //cout << bitset<8>(i) << " " << dp[i] << "\n";
//             ll sheng = 0;
//             for(int j = 1; j <= k; j++){
//                 if((i & (1 << (j-1))) == 0){
//                     sheng += coins[j];
//                 }
//             }
//             ans = max(ans,sheng);
//         }
//     }
//     cout << ans << "\n";
// }

/*P1896 [SCOI2005] 互不侵犯 */ //限制放置次数--多一层状态
/*2024.7.31*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int n,k;
// ll dp[12][200][90]; //用了k个
// int len = 0;
// int hang[200];
// int cnt[200];
// void init(){
//     for(int i = 0; i < (1 << n); i++){
//         if((i&(i << 1))  || (i&(i>>1))) continue;
//         hang[len++] = i;
//         int x = i;
//         int res = 0;
//         while(x){
//             if(x&1) res++;
//             x >>= 1;
//         }
//         cnt[len-1] = res;
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n >> k;
//     init();
//     for(int i = 0; i < n; i++){
//         for (int j = 0; j < len; j++){
//                 if(i == 0){
//                     if (cnt[j] > k)continue;
//                     dp[i][j][cnt[j]] = 1;
//                     continue;
//                 }
//                 for(int z = 0; z < len; z++){
//                     if((hang[j] & hang[z]) || (hang[j] & (hang[z] >> 1)) || (hang[j] & (hang[z] << 1))) continue;
//                     for(int p = 0; p <= k; p++){
//                         if (p - cnt[j] < 0) continue;
//                         dp[i][j][p] += dp[i - 1][z][p - cnt[j]];
//                     }
//                 }
//             }
//     }
//     ll ans = 0;
//     for(int j = 0; j < len; j++){
//         ans += dp[n - 1][j][k];
//     }
//     cout << ans << "\n";
//     return 0;
// }

/*P1879 [USACO06NOV] Corn Fields G */
/*2024.7.31*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int n,m;
// int len = 0;
// ll dp[15][400];
// int hang[10010];
// int g[15][15];
// const int mod = 1e8;
// void init(){
//     for(int i = 0; i < (1 << m); i++){
//         if((i & (i << 1)) == 0 && (i & (i >> 1)) == 0) {
//             hang[len++] = i;
//         }
//     }
// }
// bool check(int i,int x){
//     for(int j = m; j >= 1; j--){
//         if((x & 1) && !g[i][j]) return 0;
//         x >>= 1;
//     }
//     return 1;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= m; j++){
//             cin >> g[i][j];
//         }
//     }
//     init();
//     for(int i = 1; i <= n; i++){
//         for(int j = 0; j < len; j++){
//             if(i == 1){
//                 if (check(i, hang[j])) dp[i][j] = 1;
//                 continue;
//             }
//             for(int k = 0; k < len; k++){
//                 if(!check(i,hang[j])) continue;
//                 if(hang[j] & hang[k]) continue;
//                 dp[i][j] += dp[i-1][k];
//                 dp[i][j] %= mod;
//             }
//         }
//     }
//     ll ans = 0;
//     for(int j = 0; j < len; j++){
//             ans += dp[n][j];
//             ans %= mod;
//     }
//     cout << ans << "\n";
//     return 0;
// }
/*2024.7.31 题解*/ //轮廓线写法--可以解决18大小的数据(不懂)
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int mod = 1e8;
// int dp[2][1 << 18],n,m,a[18][18],cur;
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n >> m;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m;j++){
//             cin >> a[i][j];
//         }
//     }
//     memset(dp,0,sizeof dp);
//     bool now = 0,old = 1;//表示状态
//     dp[0][0] = 1;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             swap(now, old);
//             memset(dp[now],0,sizeof dp[now]);
//             for(int k = 0; k < (1 << m); k++){
//                 int up = (1 << j) & k;
//                 int left = 0;
//                 if(j > 0) left = (1 << (j-1)) & k;
//                 if(!i && up) continue;
//                 if(!j && left) continue; //矛盾
//                 if ((up && left) || up){
//                     dp[now][k^(1<<j)] += dp[old][k]; //对应位改为0
//                     dp[now][k^(1<<j)] %= mod;
//                 }
//                 else if(!up && left){
//                     dp[now][k] += dp[old][k];//因为k没有冲突
//                     dp[now][k] %= mod;
//                 }
//                 else if (!a[i][j]){
//                     dp[now][k] += dp[old][k];
//                     dp[now][k] %= mod;
//                 }
//                 else{
//                     dp[now][k] = (dp[now][k] + dp[old][k]) % mod;
//                     dp[now][k^(1<<j)] = (dp[now][k^(1<<j)] + dp[old][k]) % mod; 
//                 }
//             }
//         }
//     }
//     int ans = 0;
//     for(int i = 0; i < (1 << m); i++){
//         ans = (ans + dp[now][i]) % mod;
//     }
//     cout << ans << "\n";
//     return 0;
// }

/*P2704 [NOI2001] 炮兵阵地 */
/*2024.7.30*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int dp[110][100][100];//第i行，i行站j人，i-1行站k人
// int n,m;
// int len = 0;
// int hang[1 << 10];
// int g[110][15];
// void init(){
//     for(int i = 0; i < (1 << m); i++){
//         if ((i & (i >> 2)) == 0 && (i & (i << 2)) == 0 && (i & (i << 1)) == 0 && (i & (i >> 1)) == 0){
//             hang[len++] = i;
//         }
//     }
// }
// int cnt_hang(int hang,int x){
//     int sum = 0;
//     for(int i = m-1; i >= 0; i--){
//         if((x & 1)) sum += g[hang][i];
//         x >>= 1;
//     }
//     return sum;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n >> m;
//     int res = 0;
//     init();
//     memset(dp,0,sizeof dp);
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             char ch;cin >> ch;
//             g[i][j] = ch == 'P' ? 1 : 0;
//         }
//     }
//     //for(int i = 0; i < len; i++){
//     //    cout << bitset<32>(hang[i]) << "\n";
//     //}
//     int ans = 0;
//     for(int i = 0; i <= n; i++){
//         for(int j = 0; j < len; j++){ //i行
//             for(int k = 0; k < len; k++){ //i-1行
//                 if(i == 0){ //第一行
//                     dp[i][j][k] = cnt_hang(i,hang[j]);
//                     ans = max(ans,dp[i][j][k]);
//                     continue;
//                 }
//                 if(hang[j] & hang[k]) continue;
//                 int tmp = 0;
//                 for(int p = 0; p < len; p++){
//                     if(((hang[j] & hang[p]) || (hang[k] & hang[p]))) continue;
//                     tmp = max(tmp,dp[i-1][k][p]);
//                     res++;
//                 }
//                 dp[i][j][k] = tmp + cnt_hang(i,hang[j]);
//                 ans = max(ans,dp[i][j][k]);
//                 //cout << i << " " << cnt_hang(i, hang[j]) << "\n";
//             }
//         }
//         //cout << i << " " << ans << "\n";
//     }
//     cout << ans << "\n";
//     return 0;
// }

/* P2831 [NOIP2016 提高组] 愤怒的小鸟 */ //(UF)

/*LC 464. 我能赢吗*/ //博弈论（精）
/*LC 526. 优美的排列 */
/*LC 935. 骑士拨号器 */
/*LC 1349. 参加考试的最大学生数*/