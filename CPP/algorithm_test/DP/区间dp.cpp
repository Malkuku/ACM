#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*P1775 石子合并（弱化版）*/ //朴素区间dp板子
/*2024.8.3*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int n,m[310];
// int s[310];
// int dp[310][310]; //dp[i][j] i开头j结尾的一堆石头最小花费
// int main(){
//     cin >> n;
//     for(int i = 1; i <= n; i++) cin >> m[i];
//     for(int i = 1; i <= n; i++){
//         s[i] = s[i-1] + m[i];
//     }
//     memset(dp,0x3f,sizeof dp);
//     for(int i = 1; i <= n; i++) dp[i][i] = 0;
//     for(int len = 2; len <= n; len++){//枚举区间长度
//         for(int i = 1; i <= n - len + 1; i++){ //枚举起始点
//             int j = i + len - 1;//区间终点
//             for(int k = i; k < j; k++){
//                 dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + s[j] - s[i-1]);
//             }
//         }
//     }
//     cout << dp[1][n] << "\n";
//     return 0;
// }
/*2024.8.29*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 310;
// int dp[N][N];
// int sum[N];
// int main(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++){
//         int x;cin >> x;
//         sum[i] = sum[i-1]+x;
//     }
//     for(int len = 2; len <= n; len++){
//         for(int i = 1; i <= n - len + 1; i++){
//             int j = i+len-1;
//             dp[i][j] = 0x3f3f3f3f;
//             for(int k = i; k < j; k++){
//                 dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j] + sum[j] - sum[i-1]);
//             }
//         }
//     }
//     cout << dp[1][n] << "\n";
// }

/*CF1199 F. Rectangle Painting 1*/ //二维区间dp
/*2024.8.3*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int dp[55][55][55][55]; //x1,y1 -> x2,y2
// int main(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= n; j++){
//             char ch;cin >> ch;
//             dp[i][j][i][j] = (ch == '#' ? 1 : 0); //初始化,既最小子问题
//         }
//     }
//     for(int lenx = 1; lenx <= n; lenx++){
//         for(int leny = 1; leny <= n; leny++){
//             for(int x1 = 1; x1 <= n - lenx + 1; x1++){
//                 for(int y1 = 1; y1 <= n - leny + 1; y1++){
//                     int x2 = x1 + lenx - 1;
//                     int y2 = y1 + leny - 1;
//                     if(x1 == x2 && y1 == y2) continue; //lenx=1&&leny=1;
//                     //注意这个初始化，代表当前区间最大代价
//                     dp[x1][y1][x2][y2] = max(abs(x1-x2),abs(y1-y2)) + 1;
//                     //枚举x方向 [x1,x2] -> [x1,k] + [k+1,x2]
//                     for(int k = x1; k < x2; k++){
//                         dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2],dp[x1][y1][k][y2] + dp[k+1][y1][x2][y2]);
//                     }
//                     //枚举y方向
//                     for(int k = y1; k < y2; k++){
//                         dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2],dp[x1][y1][x2][k] + dp[x1][k+1][x2][y2]);
//                     }
//                 }
//             }
//         }
//     }
//     cout << dp[1][1][n][n] << "\n";
// }

/*P2466 [SDOI2008] Sue 的小球 */
/*2024.9.12*/ //这里最后再减最好，dp表示损失值
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// struct{
//     ll x,y,v;
// }a[1010];
// ll dp[1010][1010][2];//0最后在左，1最后在右
// ll sum[1010]; //v前缀和
// ll sov1(int l,int r){
//     if(r >= l) return sum[r] - sum[l-1];
//     else return 0;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     int n,x0;cin >> n >> x0;
//     if(n <= 0){
//         cout << 0.000 << '\n';
//         return 0;
//     }
//     for(int i = 1; i <= n; i++){
//         int x;cin >> x;
//         a[i].x = x;
//     }
//     for(int i = 1; i <= n; i++){
//         int x;cin >> x;
//         a[i].y = x;
//     }
//     for(int i = 1; i <= n; i++){
//         int x;cin >> x;
//         a[i].v = x;
//     }
//     n++;
//     a[n] = {x0,0,0};
//     sort(a+1,a+n+1,[](auto a,auto b){
//         return a.x < b.x;
//     });
//     int pos;
//     for(int i = 1; i <= n; i++){
//         if(a[i].x == x0){
//             pos = i;break;
//         }
//     }
//     ll ans = 0;
//     for(int i = 1; i <= n; i++){
//         sum[i] = sum[i-1] + a[i].v;
//         ans += a[i].y;
//     }
//     memset(dp,0x3f,sizeof dp);
//     dp[pos][pos][0] = dp[pos][pos][1] = 0;
//     for(int i = pos; i >= 1; i--){
//         for(int j = pos; j <= n; j++){
//             if(i == j) continue;
//             int cnt = sov1(1,i-1) + sov1(j+1,n);
//             dp[i][j][0] = min({
//                 dp[i][j][0],
//                 dp[i+1][j][0] + (a[i+1].x - a[i].x)*(a[i].v + cnt),
//                 dp[i+1][j][1] + (a[j].x - a[i].x)*(a[i].v + cnt)
//             });
//             dp[i][j][1] = min({
//                 dp[i][j][1],
//                 dp[i][j-1][1] + (a[j].x - a[j-1].x)*(a[j].v + cnt),
//                 dp[i][j-1][0] + (a[j].x - a[i].x)*(a[j].v + cnt)
//             });
//         }
//     }
//     cout << fixed << setprecision(3) 
//         << (double)(ans - min(dp[1][n][0],dp[1][n][1])) / 1000.0 << "\n";
//     return 0;
// }

/* P4302 [SCOI2003] 字符串折叠 */ //(精)
/*2024.9.10*/ //WA -- 无法处理循环节的位数
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int dp[110][110][2];
// int cnt[110][110];
// int cmp(string s1,string s2){
//     if(s1.size() <= 0 || s2.size() <= 0) return -1;
//     if(max(s1.size(),s2.size()) % min(s1.size(),s2.size())) return -1; 
//     for(int i = 0; i < max(s1.size(),s2.size()); i++){
//         if(s1[i % s1.size()] != s2[i % s2.size()]) return -1;
//     }
//      //cout << s1 << " " << s2 << '\n';
//     return max(s1.size(),s2.size()) / min(s1.size(),s2.size());
// }
// int main(){
//     string s;cin >> s;
//     int n = s.size();
//     memset(dp,0x3f,sizeof dp);
//     for(int i = 0; i < n; i++) dp[i][i][0] = 1;
//     for(int len = 2; len <= n; len++){
//         for(int i = 0; i < n - len + 1; i++){
//             int j = i+len-1;
//             dp[i][j][0] = len;
//             for(int k = i; k < j; k++){
//                 int tmp = cmp(s.substr(i,k-i+1),s.substr(k+1,j-k));
//                 dp[i][j][0] = min({
//                     dp[i][j][0],dp[i][k][1]+dp[k+1][j][1],
//                     dp[i][k][0]+dp[k+1][j][1],dp[i][k][1]+dp[k+1][j][0]
//                 });
//                 if(tmp != -1){
//                     int tmp_len = 0;
//                     while(tmp){
//                         tmp/=10;
//                         tmp_len++;
//                     }
//                     dp[i][j][1] = min({
//                         dp[i][j][1],
//                         min(dp[i][k][1],dp[k+1][j][1]) + tmp_len - cnt[i][j],
//                         min(dp[i][k][0],dp[k+1][j][0]) + 2 + tmp_len,
//                     });
//                     cnt[i][j] = max(cnt[i][j],tmp_len);
//                     //cout << i << " " << j  << " " << dp[i][j][1] << "\n";
//                 }
//             }
//         }
//     }
//     cout << min(dp[0][n-1][0],dp[0][n-1][1]) << "\n";
//     return 0;
// }
/*2024.9.10 题解*/ //问题主要是对于折叠的处理没有想清楚
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// string s;
// int sz[105];//数位数组
// int dp[105][105];
// bool check(int l,int r,int len){
//     for(int i = l; i <= l+len-1;i++){
//         for(int j = i; j <= r; j+=len){
//             if(s[i] != s[j]) return 0;
//         }
//     }
//     return 1;
// }
// int main(){
//     cin >> s;
//     int n = s.size();
//     memset(dp,0x3f,sizeof dp);
//     for(int i = 0; i < n; i++){
//         dp[i][i] = 1;
//     }
//     for(int i = 1; i <= 100; i++){
//         if(i < 10) sz[i] = 1;
//         else if(i < 100) sz[i] = 2;
//         else sz[i] = 3;
//     }
//     for(int len = 2; len <= n; len++){
//         for(int i = 0; i < n-len+1; i++){
//             int j = len + i - 1;
//             for(int k = i; k < j; k++){
//                 dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j]);
//                 int len2 = k-i+1;
//                 if(len % len2) continue; //不是循环节的整数倍
//                 if(check(i,j,len2)) dp[i][j] = min(dp[i][j], sz[len/len2]+dp[i][k] + 2); //向（i，k）压缩，len2是单节长度
//             }
//         }
//     }
//     cout << dp[0][n-1] << "\n";
//     return 0;
// }

/* P4170 [CQOI2007] 涂色 */
/*2024.9.10*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int dp[110][110]; //0无色 1R 2G 3B
// int main(){
//     string s;cin >> s;
//     int n = s.size();
//     for(int i = 0; i < n; i++) dp[i][i] = 1;
//     for(int len = 2; len <= n; len++){
//         for(int i = 0; i < n - len +1; i++){
//             int j = len + i - 1;
//             dp[i][j] = 0x3f3f3f3f;
//             if(s[i] == s[j]){
//                 dp[i][j] = dp[i][j-1];
//             }
//             else{
//                 for(int k = i; k < j; k++){
//                     dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
//                 }
//             }
//         }
//     }
//     cout << dp[0][n-1] << "\n";
//     return 0;
// }

/* P1005 [NOIP2007 提高组] 矩阵取数游戏 */ //__int128
/*2024.9.5*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// __int128 dp[90][90];
// int a[90][90];
// inline void output(__int128 x)
// {
//     if(x>9)
//         output(x/10);
//     putchar(x%10+'0');
// }
// int main(){
//     int n,m;cin >> n >> m;
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= m; j++){
//             cin >> a[i][j];
//         }
//     }
//     __int128 ans = 0;
//     for(int cnt = 1; cnt <= n; cnt++){
//         memset(dp,0,sizeof dp);
//         for(int len = 1; len <= m; len++){
//             for(int i = 1; i <= m - len + 1; i++){
//                 int j = i + len - 1;
//                 dp[i][j] = max(2*dp[i+1][j] + 2*a[cnt][i],2*dp[i][j-1] + 2*a[cnt][j]);
//             }
//         }
//         ans += dp[1][m];
//     }
//     output(ans);
// }

/* P1063 [NOIP2006 提高组] 能量项链 */
/*2024.9.5*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// struct node{
//     int h,w;
// }a[210];
// int b[210];
// int dp[210][210] = { 0 };
// int main(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++){
//         cin >> b[i];
//     }
//     for(int i = 1; i <= n; i++){
//         a[i] = {b[i],b[i+1]};
//         if(i == n) a[i].w = b[1];
//         a[i+n] = a[i];
//     }
//     for(int len = 2; len <= n; len++){
//         for(int i = 1; i <= 2*n - len + 1; i++){
//             int j = i + len - 1;
//             for(int k = i; k < j; k++){
//                 dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]+
//                 a[i].h*a[k].w*a[j].w);
//             }
//         }
//     }
//     int ans = 0;
//     for(int i = 1; i <= n; i++){
//         ans = max(ans,dp[i][n+i-1]);
//     }
//     cout << ans << "\n";
//     return 0;
// }

/* P3146 [USACO16OPEN] 248 G */
/*2024.9.5*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int dp[300][300];
// int a[300];
// int main(){
//     int n;cin >> n;
//     int ans = 0;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//         dp[i][i] = a[i];
//         ans = max(ans,a[i]);
//     }
//     for(int len = 2; len <= n; len++){
//         for(int i = 1; i <= n - len + 1; i++){
//             int j = len + i - 1;
//             for(int k = i; k < j; k++){
//                 if(dp[i][k] == dp[k+1][j] && dp[i][k] > 0){
//                     dp[i][j] = max(dp[i][j],dp[i][k]+1);
//                     ans = max(dp[i][j],ans);
//                 }
//             }
//         }
//     }
//     cout << ans << "\n";
//     return 0;
// }

/*P1880 [NOI1995] 石子合并 */
/*2024.9.5*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int dp1[210][210] = { 0 };
// int dp2[210][210] = { 0 };
// int a[210],sum[210];
// int main(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++) {
//         cin >> a[i];
//     }
//     for(int i = n+1; i <= 2*n; i++){
//         a[i] = a[i-n];
//     }
//     for(int i = 1; i <= n; i++){
//         sum[i] = sum[i-1] + a[i];
//         sum[i+n] = a[i];
//     }
//     for(int i = n+1; i <= 2*n; i++){
//         sum[i] += sum[i-1];
//     }
//     for(int len = 2; len <= n; len++){
//         for(int i = 1; i <= 2*n - len + 1; i++){
//             int j = i + len - 1;
//             dp1[i][j] = 0x3f3f3f3f;
//             dp2[i][j] = 0;
//             for(int k = i; k < j; k++){
//                 dp1[i][j] = min(dp1[i][j],dp1[i][k]+dp1[k+1][j]+sum[j] - sum[i-1]);
//                 dp2[i][j] = max(dp2[i][j],dp2[i][k]+dp2[k+1][j]+sum[j] - sum[i-1]);
//             }
//         }
//     }
//     int ans1 = dp1[1][n],ans2 = dp2[1][n];
//     for(int i = 1; i <= n; i++){
//         ans1 = min(dp1[i][n+i-1],ans1);
//         ans2 = max(dp2[i][n+i-1],ans2);
//     }
//     cout << ans1 << "\n" << ans2 << "\n"; 
//     return 0;
// }

/*ZOJ 3469 Food Delivery*/ //附加状态 (精)
/*2024.9.3 题解*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1010;
// int dp[N][N][2]; //[i,j] 0最后在i端 1最后在j端
// struct node{
//     int x,b;
//     bool operator < (const node& a) const{
//         return x < a.x;
//     }
// }a[N];
// int sum[N];
// int getDelay(int l,int r){
//     if(l > r) return 0;
//     return sum[r] - sum[l-1];
// }
// int main(){
//     ios::sync_with_stdio(0);
//     int n,v,x0;
//     while(cin >> n >> v >> x0){
//         memset(a,0,sizeof a);
//         memset(sum,0,sizeof sum);
//         for(int i = 1; i <= n; i++){
//             int x,y;cin >> x >> y;
//             a[i] = {x,y};
//         }
//         a[++n] = {x0,0};
//         sort(a+1,a+1+n);
//         int pos;
//         for(int i = 1; i <= n; i++){
//             sum[i] = sum[i-1] + a[i].b;
//             if(a[i].x == x0) pos = i;
//         }
//         memset(dp,0x3f,sizeof dp);
//         dp[pos][pos][0] = dp[pos][pos][1] = 0;
//         for(int i = pos; i >= 1; i--){
//             for(int j = pos; j <= n; j++){
//                 //区间外的怨气值也在累计
//                 if(i == j) continue;
//                 int delay = getDelay(1,i-1) + getDelay(j+1,n);
//                 dp[i][j][0] = min({dp[i][j][0],
//                 dp[i+1][j][0] + (a[i+1].x - a[i].x)*(delay + a[i].b),
//                 dp[i+1][j][1] + ((a[j].x - a[i].x )*(delay + a[i].b))
//                 });
//                 dp[i][j][1] = min({dp[i][j][1],
//                 dp[i][j-1][1] + (a[j].x - a[j-1].x) * (delay + a[j].b),
//                 dp[i][j-1][0] + (a[j].x - a[i].x) * (delay + a[j].b)
//                 });
//             }
//         }
//         cout << min(dp[1][n][0],dp[1][n][1]) * v << "\n";
//     }
//      return 0;
// }
    
/*CF149 D. Coloring Brackets*/ // 区间dp+记忆化 (精)
/*2024.9.3 题解*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// // dp[l][r][c1][c2] //[l,r] -> l染c1,r染c2
// // l+1 == r 贡献1
// // l,r匹配 递归 dp[l+1][r-1]
// // l,r不匹配 dp[l][mx[l]]*dp[mx[l+1],r]
// const int mod = 1e9+7;
// ll dp[710][710][3][3]; //0 无 1 红 2蓝
// map<int,int> mx;
// void dfs(int l,int r){
//     if(l + 1 == r){
//         dp[l][r][0][1] = dp[l][r][1][0] = dp[l][r][2][0] = dp[l][r][0][2] = 1;
//     }
//     else if(mx[l] == r){
//         dfs(l + 1,r-1);
//         for(int i = 0; i < 3; i++){
//             for(int j = 0; j < 3; j++){
//                 if(j != 1) dp[l][r][0][1] =(dp[l][r][0][1]+dp[l+1][r-1][i][j])%mod;
//                 if(i != 1) dp[l][r][1][0] =(dp[l][r][1][0]+dp[l+1][r-1][i][j])%mod;
//                 if(j != 2) dp[l][r][0][2] =(dp[l][r][0][2]+dp[l+1][r-1][i][j])%mod;
//                 if(i != 2) dp[l][r][2][0] =(dp[l][r][2][0]+dp[l+1][r-1][i][j])%mod;
//             }
//         }
//     }
//     else{
//         dfs(l,mx[l]);
//         dfs(mx[l]+1,r); //对于(()) () 俩段的情况独立，可以做乘算
//         for(int i = 0; i < 3; i++){
//             for(int j = 0; j < 3; j++){
//                 for(int k = 0; k < 3; k++){
//                     for(int p = 0; p < 3; p++){
//                         if((k == 1 && p == 1) || (k == 2 && p == 2)) continue; 
//                         dp[l][r][i][j] = (dp[l][r][i][j] + (dp[l][mx[l]][i][k] * dp[mx[l]+1][r][p][j]) % mod) % mod;
//                     }
//                 }
//             }
//         }
//     }
// }
// int main(){
//     string s;cin >> s;
//     s = " " + s;
//     stack<int> st;
//     for(int i = 1; i < s.size(); i++){
//         if(s[i] == '('){
//             st.push(i);
//         }
//         else if(s[i] == ')'){
//             auto t = st.top();st.pop();
//             mx[t] = i;
//         }
//     }
//     ll ans = 0;
//     dfs(1,s.size()-1);
//     for(int i = 0; i < 3; i++){
//         for(int j = 0; j < 3; j++){
//             ans += dp[1][s.size()-1][i][j];
//             ans %= mod;
//         }
//     }
//     cout << ans % mod << '\n';
//     return 0;
// }

/*hdu 4283 You are the one*/ //栈（精）
/*2024.8.3 题解*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int dp[110][110];
// int n, d[110],s[110];
// int main(){
//     int t;cin >> t;
//     for(int p = 1; p <= t; p++){
//         cin >> n;
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> d[i];
//             s[i] = s[i - 1] + d[i];
//         }
//         for (int len = 2; len <= n; len++)
//         {
//             for (int i = 1; i <= n - len + 1; i++)
//             {
//                 int j = i + len - 1;
//                 dp[i][j] = 0x3f3f3f3f;
//                 for (int k = 1; k <= j - i + 1; k++)
//                 { // i和后k位入栈
//                     dp[i][j] = min(dp[i][j], dp[i + 1][i + k - 1] + d[i] * (k - 1) + dp[i + k][j] + k * (s[j] - s[i + k - 1]));
//                 }
//             }
//         }
//         cout << "Case #" << p << ": " << dp[1][n] << "\n";
//     }
//     return 0;
// }

/*hdu 2476 String painter*/  //粉刷问题(精)
/*2024.8.3 题解*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int dp[110][110];
// int main(){
//     string a,b;
//     while(cin >> a >> b){
//         a = " " + a;
//         b = " " + b;
//         int n = a.size();
//         //初始化--空字符串
//         for(int i = 1; i <= n; i++){
//             dp[i][i] = 1;
//         }
//         //先考虑从空白串转换到b
//         for(int len = 2; len <= n; len++){
//             for(int i = 1; i <= n - len + 1; i++){
//                 int j = i + len - 1;
//                 dp[i][j] = 0x3f3f3f3f;
//                 if(b[i] == b[j]) dp[i][j] = dp[i][j-1];
//                 else{
//                     for(int k = i; k < j; k++){
//                         dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j]);
//                     }
//                 }
//             }
//         }
//         //考虑a到b
//         for(int j = 1; j <= n; j++){
//             if(a[j] == b[j]) dp[1][j] = dp[1][j-1];
//             else{
//                 for(int k = 1; k < j; k++){
//                     dp[1][j] = min(dp[1][j],dp[1][k] + dp[k+1][j]);
//                 }
//             } 
//         }
//         cout << dp[1][n] << "\n";
//     }
//     return 0;
// }

/*LightOJ 1422 	Halloween Costumes */
/*2024.8.30*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 110;
// int a[N];
// int dp[N][N];
// int main(){
//     int __;cin >> __;
//     for(int t = 1; t <= __; t++){
//         int n;cin >> n;
//         for(int i = 1;i <= n; i++){
//             cin >> a[i];
//         }
//         for(int i = 1; i <= n; i++) dp[i][i] = 1;
//         for(int len = 2; len <= n; len++){
//             for(int i = 1; i <= n - len + 1; i++){
//                 int j = len + i - 1;
//                 dp[i][j] = 0x3f3f3f3f;
//                 if(a[i] == a[j]) dp[i][j] = dp[i][j-1];
//                 for(int k = i; k < j; k++){
//                     dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
//                 }
//             }
//         }
//         cout << "Case " << t << ": "<<dp[1][n] << "\n";
//     }
// }

/*POJ 2955 Brackets */
/*2024.8.30*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int dp[1010][1010];
// bool check(char ch1,char ch2){
//     if(ch1 == '(' && ch2 == ')') return 1;
//     else if(ch1 == '[' && ch2 == ']') return 1;
//     return 0;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     string s;
//     cin >> s;
//     while(s != "end"){
//         memset(dp,0,sizeof dp);
//         int ans = 0;
//         for(int len = 2; len <= s.size(); len++){
//             for(int i = 0; i < s.size() - len + 1; i++){
//                 int j = len+i-1;
//                 if(check(s[i],s[j])) dp[i][j] = dp[i+1][j-1] + 2;
//                 for(int k = i; k < j; k++){
//                     dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
//                 }
//             }
//         }
//         cout << dp[0][s.size()-1] << "\n";
//         cin >> s;
//     }
//     return 0;
// }

/*POJ 1651 	Multiplication Puzzle */
/*2024.8.30*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll dp[110][110];
// int a[110];
// int main(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     for(int len = 3; len <= n; len++){
//         for(int i = 1; i <= n - len + 1; i++){
//             int j = len + i - 1;
//             dp[i][j] = 0x3f3f3f3f;
//             for(int k = i+1; k < j; k++){
//                 dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]);
//             }
//         }
//     }
//     cout << dp[1][n] << "\n";
//     return 0;
// }


/*LC 516. 最长回文子序列 */
/*LC 730. 统计不同回文子字符串 */ //(精)
/*LC 1039. 多边形三角剖分的最低得分 */ //子问题的划分(精)
/*LC 664. 奇怪的打印机*/ //hdu2476 简单版
/*LC 312. 戳气球*/