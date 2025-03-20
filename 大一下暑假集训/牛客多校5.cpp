#include<bits/stdc++.h>
using namespace std;
#define ll long long 

/*H 入*/
/*2024.8.9*/ //也是时间复杂度
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long 
// int dp[45];
// bool st[45];
// vector<int> node[45]; 
// int ans = 0;
// void dfs(int pos,int f,int cnt){
//     ans = max(ans,cnt);
//     for(int i = 0; i < node[pos].size(); i++){
//         int v  = node[pos][i];
//         if(st[v] || f == i) continue;
//         for(int j = 0; j < node[pos].size(); j++) st[node[pos][j]]--; //注意这里不是简单的0，1，而是进多少就要退多少
//         dfs(v,pos,cnt+1);
//        for(int j = 0; j < node[pos].size(); j++) st[node[pos][j]]++;
//     }
// }
// int main(){
//     int n,m;
//     cin >> n >> m;
//     for(int i = 0; i < m; i++){
//         int u,v;cin >> u >> v;
//         node[u].push_back(v);
//         node[v].push_back(u);
//     }
//     for(int i = 1; i <= n; i++){
//         st[i] = 1;
//         dfs(i,-1,0);
//         st[i] = 0;
//     }
//     cout << ans << "\n";
// }

/*L 知*/
/*2024.8.9*/ //时间复杂度是允许暴力的
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long 
// int main(){
//     ios::sync_with_stdio(0);
//     int t;cin >> t;
//     const int mod = 998244353;
//     int a[110];
//     while(t--){
//         int n;cin >> n;
//         for(int i = 0; i < n; i++) cin >> a[i];
//         while(1){
//             bool flag = 1;
//             for(int i = 1; i < n; i++){
//                 if(a[i] > a[i-1]){
//                     int t = a[i] - a[i-1] + 1;
//                     a[i] -= t/2;
//                     a[i-1] += t/2;
//                     flag = 0;
//                 }
//             }
//             if(flag) break;
//         }
//         ll ans = 1;
//         for(int i = 0; i < n; i++){
//             ans = (ans * a[i]) % mod;
//         }
//         cout << ans << "\n";
//     }
//     return 0;
// }