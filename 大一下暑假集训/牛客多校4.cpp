#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*A LCT*/ //题目不好读，事实上就是带权并查集
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e6+10;
// int fa[N];int high[N];
// int deep[N];
// int find(int x){
//     if(fa[x] != x){
//         int t = find(fa[x]);
//         deep[x] += deep[fa[x]];
//         fa[x] = t;
//     }
//     return fa[x];
// }
// int main(){
//     ios::sync_with_stdio(0);
//     int t;cin >> t;
//     while(t--){
//         int n;cin >> n;
//         for(int i = 1; i <= n; i++){
//             fa[i] = i;
//             high[i] = 0;
//             deep[i] = 0;
//         }
//         for(int i = 1; i < n; i++){
//             int x,y,z;cin >> x >> y >> z;
//             int father = find(x);
//             deep[y] = deep[x] + 1;
//             high[father] = max(high[father],high[y] + deep[y]);
//             fa[y] = find(x);
//             cout << high[z] << " ";
//         }cout << "\n";
//     }
// }

/*H Yet Another Origami Problem*/ //折叠原理
/*2024.7.27*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll gcd(ll a,ll b){
//     return b ? gcd(b,a%b) : a;
// }
// int main(){
//     int t;cin >> t;
//     while(t--){
//         vector<ll> g;
//         int n;cin >> n;
//         for(int i = 1; i <= n; i++){
//             ll a;cin >> a;
//             g.push_back(a);
//         }
//         ll ans = 0;
//         g.erase(unique(g.begin(),g.end()),g.end());
//         if(g.size() <= 1){
//             cout << 0 << "\n";
//             continue;
//         }
//         for(int i = 0; i < g.size() - 1; i++){
//             ans = gcd(ans,g[i+1] - g[i]);
//         }
//         cout << ans << "\n";
//     }
//     return 0;
// }

/*I Friends*/
/*2024.7.26*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// const int N = 1e6 + 10; 
// ll dp[N];//dp[i] 以i结尾的贡献数
// map<PII,bool> g;
// int main(){
//     ios::sync_with_stdio(0);
//     int n,m;cin >> n >> m;
//     for(int i = 0; i < m; i++){
//         int x,y;cin >> x >> y;
//         g[{x,y}] = 1;
//         g[{y,x}] = 1;
//     }
//     dp[0] = 1; 
//     for(int i = 1; i <= n; i++){
//         int len = dp[i-1];
//         dp[i] = 1;
//         for(int j = i-1; j >= i - len; j--){
//             if(g[{i,j}] == 1) dp[i]++;
//             else break;
//         }
//         //cout << i << " " << dp[i] << "\n";
//     }
//     ll ans = 0;
//     for(int i = 1; i <= n; i++){
//         ans += dp[i];
//     }
//     cout << ans << "\n";
//     return 0;
// }

/*G Horse Drinks Water*/
/*2024.7.26*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int main(){
//     int t;cin >> t;
//     while(t--){
//         double x1,y1,x2,y2;
//         cin >> x1 >> y1 >> x2 >> y2;
//         double x11 = -x1,y11 = -y1,x22 = -x2, y22 = -y2;
//         double ans = sqrt((x11 - x2) * (x11 - x2) + (y1 - y2) * (y1 - y2));
//         ans = min(ans, sqrt((x1 - x2) * (x1 - x2) + (y11 - y2) * (y11 - y2)));
//         ans = min(ans, sqrt((x1 - x22) * (x1 - x22) + (y1 - y2) * (y1 - y2)));
//         ans = min(ans, sqrt((x1 - x2) * (x1 - x2) + (y1 - y22) * (y1 - y22)));
//         cout <<fixed << setprecision(9) << ans << "\n";
//     }
//     return 0;
// }

/*C Sort4*/
/*2024.7.26*/ //神奇
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve()
// {
//     int n;
//     cin >> n;
//     int res = 0,cnt = 0;
//     vector<int> v(n + 1);
//     vector<bool> vis(n + 1);
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> v[i];
//         if (v[i] == i)
//             vis[i] = 1;
//     }
//     int sum = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         int pos = i;
//         int len = 0;
//         while (!vis[i]){
//             len++;
//             pos = v[pos];
//             vis[pos] = 1;
//         }
//         if(len == 4 || len == 3) res++;
//         if(len > 4){
//             res += len / 3;
//             if(len % 3 == 2)cnt++;
//         } 
//         if(len == 2) cnt++;
//     }
//     res += ((cnt+1)/2);
//     cout << res << "\n";
// }
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }