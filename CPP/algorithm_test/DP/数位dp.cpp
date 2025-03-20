#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long

///数位dp///
//注意最高位限制和前导0

/*B3883 [信息与未来 2015] 求回文数（加强版）*/
/*2024.7.21 题解*/ //回文数处理,相当于一半的数位dp
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 105;
// const int mod = 20091119;
// int len = 0,len2 = 0;
// int num[N],tmp[N];
// ll dp[N][N];
// string s;
// bool check(){
//     for(int i = len2,j = (len >> 1)+(len&1); i & j; i-- ,j--){
//         if(tmp[i] > num[j]) return 0;
//         if(tmp[i] < num[j]) return 1;
//     }
//     return 1;
// }
// ll dfs(int pos,bool limit){
//     if(pos == (len >> 1)){ //枚举到一半
//         if(!limit) return 1; //没数位限制，随便取
//         else return check(); //检查是否可取
//     }
//     if(dp[pos][limit] != -1) return dp[pos][limit];
//     int up = limit ? num[pos] : 9;
//     ll ans = 0;
//     for(int i = 0; i <= up; i++){
//         if(!i && pos == len) continue; //前导0
//         tmp[++len2] = i; //回文数的一半
//         ans = (ans + dfs(pos-1,limit && i == up)) % mod;
//         len2--; //回溯
//     }
//     return dp[pos][limit] = ans;
// }
// ll solve(){
//     for(int i = s.size()-1; i >= 0; i--){
//         num[++len] = s[i] - '0';
//     }
//     ll res = 0;
//     //处理len-1长度的回文 (1,len-1) 9x(10^(len/2-1))
//     for(int i = len - 1; i > 0; i--){
//         int res2 = 9; 
//         for(int j = i - 1; j > (i >> 1); j--) res2 = (res2*10) %mod;
//         res = (res+res2)%mod;
//     }
//     memset(dp,-1,sizeof dp);
//     res = (res + dfs(len,1)) % mod;
//     return res;
// }
// int main(){
//     cin >> s;
//     cout << solve() << "\n";    
// }

/* P4999 烦人的数学作业 */
/*2024.7.19*/ //可以根据需要改变sum的含义,已经得到的值不需要重置
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2000;
// ll dp[N][N];
// int num[N];
// ll l,r;int now;
// const int mod = 1e9+7;
// ll dfs(int pos,int sum,bool lead,bool limit){
//     if(!pos) return sum;
//     if(!lead && !limit && dp[pos][sum] != -1) return dp[pos][sum];
//     int up = limit ? num[pos] : 9;
//     ll ans = 0;
//     for(int i = 0; i <= up; i++){
//         ans = (ans + dfs(pos-1,sum+i,lead && i == 0,limit && i == up)) % mod;
//     } 
//     if(!lead && !limit) dp[pos][sum] = ans;
//     return ans;
// }
// ll solve(ll x){
//     int len = 0;
//     ll cnt[N];
//     while(x){
//         num[++len] = x % 10;
//         x /= 10;
//     }
//     return dfs(len,0,1,1);
// }
// int main(){
//     int t;cin >> t;
//     memset(dp, -1, sizeof dp);
//     while(t--){
//         cin >> l >> r;
//         cout << (solve(r) - solve(l-1) + mod) % mod << "\n";
//     }
// }

/*P3286 [SCOI2014] 方伯伯的商场之旅 */ //省选

/*P2518 [HAOI2010] 计数 */
/*2024.7.19 题解*/ //优化的全排列（精）
// //如果删i个0,C(n-i,cnt-i)*2^(n-cnt)
// //先把0放好，再放a[1] -> C(m - a[0],a[1]); 以此类推
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1010;
// ll C[N][N];
// ll getC(ll n,ll m){
//     if(C[n][m]) return C[n][m];
//     if(m == 1) return n;
//     if(m == 0 || m == n) return 1;
//     if(m > n) return 0;
//     C[n][m] = getC(n-1,m) + getC(n-1,m-1);
//     return C[n][m];
// }
// int a[N],v[N];
// ll ans;int n;
// ll dfs(){
//     ll ans = 1;
//     int m = n; //先放0再放1，以此全排列
//     for(int i = 0; i <= 9; i++) if(a[i]) ans *= getC(m,a[i]),m -= a[i];
//     return ans;
// }
// int main(){
//     //ios::sync_with_stdio(0);
//     string s;cin >> s;
//     int len = 0;
//     for(int i = 0; i < s.size(); i++){
//         v[++len] = s[i] - '0'; //表示位上的数字
//         a[v[len]]++; //表示每个数字各自的数量
//     }
//     n = len;
//     for(int i = 1; i <= len; i++){
//         n--;//当前枚举的位置
//         for(int j = 0; j < v[i]; j++){ //比这个数位小的数
//             if(a[j]){ //将它作为第n位
//                 a[j]--;
//                 ans += dfs(); //枚举剩下n-1位的全排列
//                 a[j]++;
//             }
//         }
//         a[v[i]]--; // 接着去枚举n-1位
//     }
//     cout<< ans << "\n";
//     return 0;
// }

/* P3281 [SCOI2013] 数数 */ //省选

/* P4798 [CEOI2015 Day1] 卡尔文球锦标赛 */ 
/*2024.7.18*/ //WA 或许是对题意的理解有问题
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e4+10;
// ll a[N];
// const int MOD = 1000007;
// int main(){
//     ios::sync_with_stdio(0);
//     int n; cin >> n;
//     for(int i = n; i >= 1; i--) cin >> a[i];
//     ll ans = 0;
//     for(int i = 1; i <= n; i++){
//         ans += (a[i] - 1) * i;
//         ans %= MOD;
//     }
//     cout << ans+1 % MOD << "\n";
//     return 0;
// }
/*2024.7.19 题解*/ //（存疑）
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// const int MOD = 1000007;
// ll mx[N],a[N],dp[N]; //mx前缀最大值
// //dp[i][j] i个人,第一个人的队伍编号<=j
// //对于新来的一个人可以在原来（j-1)选其一/自己作为一个新队伍
// //dp[i][j] = dp[i-1][j] * (j-1) + dp[i-1][j+1] 
// //需要统计的是字典序比a小的方案数
// int n;
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n;
//     for(int i = 1; i <= n; i++){
//         dp[i] = 1;// ？为什么初始化为1？
//         cin >> a[i];
//         mx[i] = max(mx[i-1],a[i]); //以字典序来理解
//     }
//     ll ans = 0;
//     for(int i = n; i >= 1; i--){
//         //第i个人的编号最大是mx[i-1] + 1;
//         //？？？
//         for(int j = 1; j <= min(mx[i-1]+1,a[i]-1); j++){
//             ans += dp[max((ll)j+1,mx[i-1]+1)]; 
//             ans %= MOD;
//         }
//         //滚动数组
//         for(int j = 1; j <= i; j++){
//             dp[j] = (j-1)*dp[j] + dp[j+1];
//             dp[j] %= MOD;
//         }
//     }
//     cout << (ans + 1) % MOD << "\n";
//     return 0;
// }

/*P2602 [ZJOI2010] 数字计数 */
/*2024.7.17*/
// #include <bits/stdc++.h>
    // using namespace std;
    // #define ll long long
    // ll a,b;
    // const int N = 1e6+10;
    // ll dp[20];//第i位数出现了多少次
    // ll ten[20]; //10的i次方
    // ll cnta[20],cntb[20];//数字i的出现次数
    // void init(){
    //     dp[0] = 0;
    //     ten[0] = 1;
    //     for(int i = 1; i <= 12; i++){
    //         dp[i] = dp[i-1]*10 + ten[i-1];
    //         ten[i] = ten[i-1]*10;
    //     }
    // }
    // void solve1(ll x,ll cnt[]){
    //     int len = 0;
    //     int num[20]; //第i位的数字
    //     while(x){
    //         num[++len] = x%10;
    //         x/=10;
    //     }
    //     //从高到低处理
    //     for(int i = len; i >= 1; i--){
    //         for(int j = 0; j < 10; j++){
    //             cnt[j] += dp[i-1]*num[i];
    //         }
    //         //处理最高位
    //         for(int j = 0; j < num[i]; j++){
    //             cnt[j] += ten[i-1];
    //         }
    //         ll num2 = 0;
    //         for(int j = i-1; j >= 1;j--){
    //             num2 = num2*10 + num[j];
    //         }
    //         cnt[num[i]] += num2+1;
    //         //处理前导0
    //         cnt[0] -= ten[i-1];
    //     }
    // }
    // int main(){
    //     ios::sync_with_stdio(0);
    //     cin >> a >> b;
    //     init();
    //     solve1(a - 1, cnta);
    //     solve1(b, cntb);
    //     for(int i = 0; i < 10; i++) cout << cntb[i] - cnta[i] << " ";
    //     return 0;
    // }
/*2024.7.17 题解*/ // 记忆化搜索
// #include <bits/stdc++.h>
    // using namespace std;
    // #define ll long long
    // const int N = 20;
    // int num[N], now;
    // ll dp[N][N][2][2]; //dp[pos][sum][lead][limit] //除前面now位的sum最后pos位的范围，lead有无前导0，limit有无数位限制
    // ll a,b;
    // ll dfs(int pos,int sum,bool lead,bool limit){
    //     ll ans = 0;
    //     if(pos == 0) return sum;
    //     //直接记忆化搜索
    //     if(dp[pos][sum][lead][limit] != -1) return dp[pos][sum][lead][limit];
    //     int up = (limit ? num[pos] : 9);//是否有限制最高位
    //     for(int i = 0; i <= up; i++){ //遍历最高位的情况
    //         //仅有原有限制且是最高位的最大值时向下递归有限制
    //          if(i == 0 && lead) ans += dfs(pos-1,sum,1,limit && i ==
    //          up); //最高位是0且有前导0
    //          else if(i == now) ans += dfs(pos-1,sum+1,0,limit && i == up); //最高位是now，累计到sum中
    //          else if(i != now) ans += dfs(pos-1,sum,0,limit && i == up);
    //     }
    //     dp[pos][sum][lead][limit] = ans;
    //     return ans;
    // }
    // ll solve(ll x){
    //     int len = 0;
    //     while(x){
    //         num[++len] = x % 10;
    //         x/=10;
    //     }
    //     memset(dp,-1,sizeof dp);
    //     return dfs(len,0,1,1);
    // }
    // int main(){
    //     cin >> a >> b;
    //     for(int i = 0; i < 10; i++) now = i,
    //     cout << solve(b) - solve(a-1) << " ";
    //     return 0;
    // }

/*P2657 [SCOI2009] windy 数 */ //(精) (存疑)
/*2024.7.17*/                  // WA 主要是处理前导0的问题
// #define _CRT_SECURE_NO_WARNINGS 1
    // #include <bits/stdc++.h>
    // using namespace std;
    // #define ll long long
    // const int N = 20;
    // ll dp[N][N]; //dp[pos][last] //pos长，最高位是last
    // ll a,b;
    // void init(){
    //     for(int i = 0; i < 10; i++){
    //         dp[1][i] = 1;
    //     }
    //     for(int n = 2; n <= 9; n++){
    //         for (int i = 0; i < 10; i++){
    //             for (int j = 0; j < 10; j++){
    //                 if (abs(i - j) >= 2 || !i)
    //                     dp[n][i] += dp[n - 1][j];
    //             }
    //         }
    //     }
    // }
    // ll solve(ll x){
    //     cout << "x " << x << "\n";
    //     int len = 0;
    //     int num[N];
    //     if (x == 0) len = 1, num[len] = 0;
    //     while(x){
    //         num[++len] = x % 10;
    //         x /= 10;
    //     }
    //     ll sum = 0;
    //     //处理最高位
    //     for(int j = 0; j <= num[len]-1; j++){
    //         sum += dp[len][j];
    //     }
    //     //cout << "sum1 " << sum << "\n";
    //     for(int i = 2; i <= len-1; i++){
    //         for(int j = 0; j <= num[i]-1; j++){
    //             if(abs(j - num[i+1]) >= 2) sum += dp[i][j];
    //         }
    //     }
    //     //cout << "sum2 " << sum << "\n";
    //     for(int j = 0; j <= num[1]; j++){
    //         if (abs(j - num[2]) >= 2) sum += dp[1][j];
    //     }
    //     //cout << "sum3 " << sum << "\n";
    //      return sum;
    // }
    // int main(){
    //     cin >> a >> b;
    //     init();
    //     cout << solve(b) - solve(a-1) << "\n";
    //     return 0;
    // }
/*2024.7.17*/ // 与上题一样的回溯模板
// #define _CRT_SECURE_NO_WARNINGS 1
    // #include <bits/stdc++.h>
    // using namespace std;
    // #define ll long long
    // const int N = 20;
    // int dp[N][N],num[N];
    // int dfs(int pos,int last,bool lead,bool limit){
    //     int ans = 0;
    //     if(pos == 0) return 1;
    //     if(!lead && !limit && dp[pos][last] != -1) return dp[pos][last];
    //     int up = (limit ? num[pos]:9);
    //     for(int i = 0; i <= up; i++){
    //         if(abs(i - last) < 2) continue;
    //         if(lead && i == 0) ans += dfs(pos-1,-2,1,limit && i == up);
    //         else ans += dfs(pos-1,i,0,limit&&i == up);
    //     }
    //     if(!lead&&!limit) dp[pos][last] = ans;
    //     return ans;
    // }
    // int solve(int x){
    //     int len = 0;
    //     while(x){
    //         num[++len] = x % 10;
    //         x/=10;
    //     }
    //     memset(dp,-1,sizeof dp);
    //     return dfs(len,-2,1,1); //为什么是-2???
    // }
    // int main(){
    //     int a,b; cin >> a >> b;
    //     cout << solve(b) - solve(a-1);
    //     return 0;
    // }

/*P4124 [CQOI2016] 手机号码*/
/*2024.7.17 题解*/
// #define _CRT_SECURE_NO_WARNINGS 1
    // #include <bits/stdc++.h>
    // using namespace std;
    // #define ll long long
    // ll dp[20][11][11][2][2][2][2]; //dp[pos][i][j][state][n4][n8][limit]
    // int num[15];
    // ll dfs(int pos,int p1,int p2,bool state,bool n4,bool n8,bool limit){
    //     ll ans = 0;
    //     if(n4 && n8) return 0;
    //     if(pos == 0) return state;
    //     if(dp[pos][p1][p2][state][n4][n8][limit] != -1){
    //         return dp[pos][p1][p2][state][n4][n8][limit];
    //     }
    //     int up = limit ? num[pos] : 9;
    //     for(int i = 0; i <= up; i++){
    //         ans += dfs(pos-1,i,p1,state || (i == p1 && i == p2),n4 || (i == 4) ,n8 || (i == 8), limit && i == up);
    //     }
    //     dp[pos][p1][p2][state][n4][n8][limit] = ans;
    //     return ans;
    // }
    // ll solve(ll x){
    //     int len = 0;
    //     while(x){
    //         num[++len] = x % 10;
    //         x /= 10;
    //     }
    //     if(len != 11) return 0;
    //     ll ans = 0;
    //     memset(dp,-1,sizeof dp);
    //     for(int i = 1; i <= num[len]; i++){
    //         ans += dfs(len-1,i,0,0,i == 4,i == 8,i == num[len]);
    //     }
    //     return ans;
    // }
    // int main(){
    //     ios::sync_with_stdio(0);
    //     ll a,b;
    //     cin >> a >> b;
    //     cout << solve(b) - solve(a-1) << "\n";
    //     return 0;
    // }

/*LC 233. 数字 1 的个数*/
/*LC 902. 最大为 N 的数字组合 */

/// 简单题///

/*NC235911 ��¥��*/
// #include<iostream>
    // #include<string>
    // using namespace std;
    //
    // const int N = 60;
    // int n;
    // int res = 0;
    ////dp[i] ����i���ݵķ���
    //
    // int main()
    //{
    //	scanf("%d", &n);
    //	int dp[N] = { 0 };
    //	dp[1] = 1;
    //	dp[2] = 1;
    //	for (int i = 3; i <= n; i++)
    //	{
    //		dp[i] = dp[i - 1] + dp[i - 2];
    //	}
    //	printf("%d\n", dp[n]);
    //
    //	return 0;
    //}