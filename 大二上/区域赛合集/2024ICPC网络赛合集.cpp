#include<bits/stdc++.h>
using namespace std;
#define ll long long

///*CCPC by gym/105336*///

/*J 找最小*/ //线性基
/*2024.9.24 题解（精）*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int n;
// int p[32];
// void add(int x){
//     for(int i = 31; i >= 0; i--){
//         if(1 & (x >> i)){
//             if(p[i]) x ^= p[i];
//             else{
//                 p[i] = x;
//                 break;
//             }
//         }
//     }
// }
// const int N = 1e6+5;
// int a[N],b[N];
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     while(t--){
//         memset(p,0,sizeof p);
//         int sum_a = 0,sum_b = 0;
//         int n; cin >> n;
//         for(int i = 0; i < n; i++){
//             cin >> a[i];
//             sum_a ^= a[i];
//         }
//         for(int i = 0; i < n; i++){
//             cin >> b[i];
//             sum_b ^= b[i];
//             add(a[i]^b[i]);
//         }
//         //因为相当于异或上a[i]^b[i]的组合
//         for(int i = 31; i >= 0; i--){ 
//             if(max(sum_a,sum_b) > max(sum_a^p[i],sum_b^p[i])){
//                 sum_a = sum_a^p[i];
//                 sum_b = sum_b^p[i];
//             }
//         }
//         cout << max(sum_a,sum_b) << "\n";
//     }
//     return 0;
//     //交换 ^= a[i]^b[i] ^ a[j]^b[j] 
// }

/*D 编码器-解码器*/
/*2024.9.24  题解（精）*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// //dp[i][j][k] 第i层，子序列（j,k）的个数
// const int mod = 998244353;
// const int N = 105;
// ll dp[N][N][N];
// int main(){
//     string s,t;
//     cin >> s >> t;
//     s = " " + s;
//     t = " " + t;
//     for(int i = 1; i < s.size(); i++){
//         //记录长度为1的子序列
//         for(int j = 1; j < t.size(); j++){
//             dp[i][j][j] = (2*(dp[i-1][j][j] % mod)) % mod;
//         }
//         //记录长度<=2
//         for(int j = 1; j < t.size(); j++){
//             for(int k = j + 1; k < t.size(); k++){
//                 dp[i][j][k] = ((2*dp[i-1][j][k])%mod)%mod;
//                 //以p作为中间点
//                 for(int p = j; p < k; p++){
//                     dp[i][j][k] += (dp[i-1][j][p]*dp[i-1][p+1][k]) % mod;
//                     dp[i][j][k] %= mod;
//                 }
//             }
//         }
//         //计算中间字符贡献
//         for(int j = 1; j < t.size(); j++){
//             if(s[i] != t[j]) continue;
//             dp[i][j][j]++;
//             dp[i][j][j] %= mod;
//             //字符在不同位置的贡献
//             //右端点
//             for(int k = 1; k < j; k++){
//                 dp[i][k][j] += dp[i-1][k][j-1] % mod;
//                 dp[i][k][j] %= mod;
//             }
//             //左端点
//             for(int k = j + 1; k < t.size(); k++){
//                 dp[i][j][k] += dp[i-1][j+1][k];
//                 dp[i][j][k] %= mod;
//             }
//             //中间值
//             for(int k = 1; k < j; k++){
//                 for(int p = j + 1; p < t.size(); p++){
//                     dp[i][k][p] += (dp[i-1][k][j-1] * dp[i-1][j+1][p]) % mod;
//                     dp[i][k][p] %= mod;
//                 }
//             }
//         }
//     }
//     cout << dp[s.size()-1][1][t.size()-1] << "\n";
//     return 0;
// }


///*icpcI by qoj/contest/1794 *///

/*C. Permutation Counting 4 */ // 线性代数
/*2024.10.1 题解*/
// //我们把p的总数表示出来。设矩阵 a{i,j} ​，表示的是第 i个位置的是否可以表示 j
// //行列式线性无关说明矩阵结果为0
// //r ，l-1 表示向量 并查集找线性相关性
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int n,m;
// int pre[1000005];
// pair<int,int> a[1000005];
// int find(int x){
//     return x == pre[x] ? x : find(pre[x]);
// }
// int main(){
//     ios::sync_with_stdio(0);
//     int t;cin >> t;
//     while(t--){
//         int n;cin >> n;
//         for(int i = 0; i <= n; i++) pre[i] = i;
//         for(int i = 1; i <= n; i++){
//             int x,y;cin >> x >> y;
//             a[i] = {x,y};
//         }
//         int ans = 1;
//         for(int i = 1; i <= n; i++){
//             int l = find(a[i].first-1);
//             int r = find(a[i].second);
//             if(l == r) {
//                 ans = 0;
//                 break;
//             }
//             else{
//                 pre[r] = l;
//             }
//         }
//         cout << ans << "\n";
//     }
//     return 0;
// }

/*G. The Median of the Median of the Median*/ //中位数之中位数
/*2024.10.1 题解*/ //二分答案
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2010;
// int n,suma[N],a[N],b[N][N],c[N][N];
// bool check(int x){
//     //记录>=x 的a[i] 数量
//     for(int i = 1; i <= n; i++) suma[i] = suma[i-1] + (a[i] >= x);
//     //b数组 -- 该区间内中位数是否大于等于x
//     for(int i = 1; i <= n; i++){
//         for(int j = i; j <= n; j++){
//             c[i][j] = (2 * (suma[j] - suma[i - 1]) > (j - i + 1));
//         }
//     }
//     //c数组前缀和处理
//     //统计倒三角左边区域
//     for(int i = 1; i <= n; i++){
//         for(int j = i + 1; j <= n; j++) c[i][j] += c[i][j-1];
//     }
//     //统计倒三角下边区域
//     for(int j = 1; j <= n; j++){
//         for(int i = j - 1; i >= 1; i--) c[i][j] += c[i+1][j];
//     }
//     int sumc = 0;
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= n; j++){ //c[i][j] 以i，j为顶点的倒三角
//             sumc += (2*c[i][j]) > (j - i + 1) * (j - i + 2) / 2; //区间内b数量的一半
//         }
//     }
//     return 2 * sumc > n * (n + 1) / 2; //c数量的一半
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
//     int l = 0,r = 1e9 + 1;
//     while(l <= r){
//         int mid = (l+r) >> 1;
//         if(check(mid)) l = mid + 1;
//         else r = mid - 1;
//     }
//     cout << r << "\n";
//     return 0;
// }

///*icpcII by gym/105358*///

/*L. 502 Bad Gateway*/
/*2024.10.8 题解*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<ll,ll>
//对勾函数 (1+x)/2 + T/x - 1, 最小值 c = +- sqrt(2t); 
int n;
ll gcd(ll a,ll b){
    return b ? gcd(b,a%b) : a;
}
void update(int k, int T, PII& ans){ //?
    PII now;
    now.first = 2* k;
    now.second = 2 * T + k * k - k;
    ll g = gcd(now.first,now.second);
    now.first /= g,now.second /= g;
    if(now.second * ans.first < now.first * ans.second) ans = now;
}
void solve(){
    ll t;cin >> t;
    ll k = sqrt(2 * t);
    PII ans = { 1 , 1e9};
    if(k <= t && k) update(k,t,ans);
    if(k-1 <= t && k-1) update(k-1,t,ans);
    if(k+1 <= t && k+1) update(k+1,t,ans);
    cout << ans.second << " " << ans.first << "\n"; 
}
int main(){
    cin >> n;
    while(n--) solve();
    return 0;
}

/*G. Game*/ 
/*2024.10.1 题解*/ //所有的分数都可以提前逆元处理
// // x>=y 时 1.A赢 0 到 x/y-1 轮中赢一轮   2.向 x < y转移
// // x <y 时 1.B赢  2. x/y轮后向 x >= y转移  
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int mod = 998244353;
// ll qmi(ll a,ll b){
//     ll res = 1;
//     a %= mod;
//     while(b){
//         if(b&1){
//             res = res * a % mod;
//         }
//         b >>= 1;
//         a = a * a % mod;
//     }
//     return res;
// }
// ll inv(ll x){
//     return qmi(x % mod, mod - 2);
// }
// ll ans = 0;
// ll p0,p1;
// void dfs(ll cur,ll x,ll y){
//     if(x == 0){
//         return;
//     }
//     if(y == 0){
//         ans = (ans + cur) % mod;
//         return;
//     }
//     if(x >= y){
//         ll k = x / y;
//         ll mul = 1ll * (1 - qmi(p1,k) + mod) % mod * inv(1 - p1 + mod) % mod * p0 % mod;
//         ans = (ans + 1ll * cur * mul % mod) % mod;
//         dfs(cur * qmi(p1,k) % mod, x % y, y);
//     }
//     else if(x < y){
//         dfs(cur * qmi(p0, y / x) % mod, x, y % x);
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     ll t;cin >> t;
//     while(t--){
//         ll x,y,a0,a1,b;
//         cin >> x >> y >> a0 >> a1 >> b;
//         b = a0 + a1;
//         p0 = a0 * inv(b) % mod;
//         p1 = a1 * inv(b) % mod;
//         ans = 0;
//         dfs(1,x,y);
//         cout  << ans << "\n";
//     }
//     return 0;
// }

/*J. Stacking of Goods*/
/*2024.10.1*/ //贪心
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5 + 10;
// struct{
//     ll w,v,c;
// }a[N];
// int main(){
//     ios::sync_with_stdio(0);
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++) {
//         ll x,y,z;
//         cin >> x >> y >> z;
//         a[i] = {x,y,z};
//     }
//     sort(a+1,a+1+n,[](auto x,auto y){
//         return x.w * y.c > y.w * x.c;  
//     });
//     ll sum = 0, ans = 0;
//     for(int i = 1; i <= n; i++){
//         ans += a[i].v - sum * a[i].c;
//         sum += a[i].w;
//     }
//     cout << ans << "\n";
//     return 0;
// }
