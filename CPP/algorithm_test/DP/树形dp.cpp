#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>

/*P2015 二叉苹果树 */ //多叉树dp板子
/*2024.8.5*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// const int N = 200;
// struct Node{
//     int v,w;
// };
// vector<Node> edge[N];
// int dp[N][N]; //以节点i为根的子树上留j条边的最多苹果数量
// int sum[N];
// int n,q;
// void dfs(int u,int fa){
//     for(int i = 0; i < edge[u].size(); i++){
//         int v = edge[u][i].v,w = edge[u][i].w;
//         if(v == fa) continue;
//         dfs(v,u);
//         sum[u] += sum[v] + 1; //子树上的总边数
//         for(int j = min(q,sum[u]); j >= 0; j--){ 
//             for(int k = 0; k <= min(sum[v],j-1); k++){ 
//                 //保留一条边必须保留从根节点到这条边路径上的所有边，那么如果你想从uu的子节点vv的子树上留边的话，也要留下u,vu,v之间的连边
//                 dp[u][j] = max(dp[u][j],dp[u][j-k-1] + dp[v][k] + w); //w是dp[v]产生的
//                 //二叉树时
//                 //dp[u][j] = max(dp[u][j],dfs(u,lson,k) + dfs(u,rson,j-k));
//             }
//         }  
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n >> q;
//     for(int i = 1; i < n; i++){
//         int x,y,w;cin >> x >> y >> w;
//         edge[x].push_back({y,w});
//         edge[y].push_back({x,w});
//     }
//     dfs(1,0);
//     cout << dp[1][q] << "\n";
//     return 0;
// }
/*2024.8.29*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// struct Node{
//     int v,w;
// };
// vector<Node> node[210];
// int dp[210][210] = {0}; //dp[i][j] //i节点保留j条枝
// int n,m;
// int sum[210] = {0};
// void dfs(int now,int fa){
//     for(int i = 0; i < node[now].size(); i++){
//         int v = node[now][i].v,w = node[now][i].w;
//         if(v == fa) continue;
//         dfs(v,now);
//         sum[now] += sum[v]+1;
//         for(int j = min(sum[now],m); j >= 0; j--){
//             for(int k = 0; k <= min(sum[v],j-1); k++){
//                 dp[now][j] = max(dp[now][j],dp[now][j-k-1]+dp[v][k]+w);
//             }
//         }
//     }
// }
// int main(){
//     cin >> n >> m;
//     for(int i = 0; i < n-1; i++){
//         int u,v,w;
//         cin >> u >> v >> w;
//         node[u].push_back({v,w});
//         node[v].push_back({u,w});
//     }
//     dfs(1,0);
//     cout << dp[1][m];
//     return 0;
// }

/*P1273 有线电视网 */
/*2024.8.5*/ //（不懂）
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// vector<PII> node[3010];
// int dp[3010][3010];
// int sum[3010];
// int cost[3010];
// int n,m;
// void dfs(int u){
//     if(u > n-m){
//        dp[u][1] = cost[u];
//        //cout << u <<" "<< cost[u] << "\n";
//        return;
//     }
//     for(int i = 0; i < node[u].size(); i++){    
//         int v = node[u][i].first;
//         int w = node[u][i].second;
//         dfs(v);
//         sum[u] += sum[v] + 1;
//         for(int j = sum[u]; j >= 0; j--){
//             for(int k = 0; k <= j; k++){
//                 if(j-k >= 0)dp[u][j] = max(dp[u][j], dp[u][j-k] + dp[v][k] - w);
//             }
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n>> m;
//     memset(dp,-0x3f,sizeof dp);
//     for(int i = 0; i <= n; i++) dp[i][0] = 0;
//     for(int i = 0; i <= n; i++) dp[0][i] = 0;
//     for(int i = 1; i <= n-m; i++){
//         int t;cin >> t;
//         for(int j = 1; j <= t; j++){
//             int a,c;cin >> a >> c;
//             node[i].push_back({a,c});
//         }
//     }
//     for(int i = n - m + 1; i <= n; i++){
//         cin >> cost[i];
//     }
//     dfs(1);
//     for(int j = m; j >= 0; j--){
//         if(dp[1][j] >= 0){
//             cout << j << "\n";
//             break;
//         }
//     }
//     return 0;
// }

/*P1352 没有上司的舞会*/
/*2024.8.5*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// const int N = 6e3+10;
// int n,dp[N][2];
// vector<int> node[N];
// int fa[N],happy[N];
// void dfs(int father){
//     dp[father][1] = happy[father];
//     for(int i = 0; i < node[father].size(); i++){
//         int v = node[father][i];
//         dfs(v);
//         dp[father][0] += max(dp[v][0],dp[v][1]);
//         dp[father][1] += dp[v][0];
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n;
//     for(int i = 1; i <= n; i++) cin >> happy[i];
//     for(int i = 1; i < n; i++){
//         int x,y; cin >> x >> y;
//         node[y].push_back(x);
//         fa[x] = y;
//     }
//     int father = 1;
//     while(fa[father]) father = fa[father];
//     dfs(father);
//     cout << max(dp[father][0],dp[father][1]) << "\n";
//     return 0;
// }

/*LC 124. 二叉树中的最大路径和*/
/*LC 543. 二叉树的直径*/
/*LC 337. 打家劫舍 III*/ //选与不选