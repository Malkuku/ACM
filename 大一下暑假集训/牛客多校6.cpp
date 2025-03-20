#include<bits/stdc++.h>
using namespace std;
#define ll long long 

/*A Cake*/ //博弈论(精)
/*2024.8.9 题解1 直接dp*/
// //1 - G,0 - O,dp[i] //到该点位置最大的0前缀占比
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+10;
// struct Node{
//     int v,w;
// };
// int n;
// vector<Node> node[N];
// double dp[N];
// void dfs(int pos,int fa,int cnt,int num){
//     if(num)dp[pos] = max(dp[fa],1.0*cnt/num); //维护走到该点的最大前缀占比，递推到叶子节点
//     for(int i = 0; i < node[pos].size(); i++){
//         if(fa == node[pos][i].v) continue;
//         dfs(node[pos][i].v,pos,cnt + (node[pos][i].w == 0),num+1);
//     }
//     //跳过叶子
//     if(node[pos].size() == 1 && fa != -1){
//         return;
//     }
//     if(num%2 == 0){ //G选择-希望0尽可能小
//         dp[pos] = 1e9;
//     }
//     else dp[pos] = -1;
//     for(int i = 0; i < node[pos].size(); i++){
//         if(fa == node[pos][i].v) continue;
//         if(num%2 == 0) dp[pos] = min(dp[pos],dp[node[pos][i].v]);
//         else dp[pos] = max(dp[pos],dp[node[pos][i].v]);
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     int t;cin >> t;
//     while(t--){
//         cin >> n;
//         dp[1] = 0;//初始化
//         for(int i = 1; i <= n; i++) node[i].clear();
//         for(int i = 1; i < n; i++){
//             int x,y,k;cin >> x >> y >> k;
//             node[x].push_back({y,k});
//             node[y].push_back({x,k});
//         }
//         dfs(1,-1,0,0);
//         cout << fixed << setprecision(12) << 1-dp[1] << "\n";
//     }
// }