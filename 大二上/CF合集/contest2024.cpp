// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }

/*D. Skipping*/ //很有意思的题目（精）
/*2024.10.22 题解*/ //优先队列优化dp
// //核心：定义dp[i]为到达i点的最少代价,ans = pre[i] - dp[i]
// //确保了ans在每一点获得最大概率可能性
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<ll,int>
// const int N = 4e5+10;
// ll a[N],b[N];
// ll dp[N];
// void solve(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++) dp[i] = LONG_LONG_MAX / 2; //这里尽量不要用memset
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     for(int i = 1; i <= n; i++) cin >> b[i];
//     priority_queue<PII> q;
//     dp[1] = 0;
//     q.push({-a[1],b[1]}); //通过负数模拟小根堆
//     for(int i = 2; i <= n; i++){
//         while(q.size() && q.top().second < i) q.pop();
//         if(!q.size()) break; //保证当前可以到达i点
//         dp[i] = -q.top().first; //最小代价
//         if(b[i] > i) q.push({-(dp[i]+a[i]),b[i]});
//     }
//     ll ans = 0,sum = 0;
//     for(int i = 1; i <= n; i++){
//         sum += a[i];
//         ans = max(ans,sum - dp[i]);
//     }
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }
/*2024.10.22 题解*/ //最短路--核心思路与dp一致，查找dp[i]的方法不同
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 4e5+10;
// struct Node{
//     ll to;
//     ll w;
// };
// ll dis[N]; //到达i点的最短路
// vector<Node> node[N];
// ll a[N],b[N];
// void bfs(){
//     priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
//     q.push({0,1});
//     while(q.size()){
//         auto pos = q.top().second;
//         auto cost = q.top().first;
//         q.pop();
//         for(int i = 0; i < node[pos].size(); i++){
//             auto w = node[pos][i].w;
//             auto to = node[pos][i].to;
//             if(dis[to] <= w + dis[pos]) continue;
//             dis[to] = w + dis[pos];
//             q.push({dis[to],to});
//         }
//     }
// }
// void solve(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++) dis[i] = LONG_LONG_MAX / 2;
//     for(int i = 1; i <= n; i++) node[i].clear();
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     for(int i = 1; i <= n; i++) cin >> b[i];
//     for(int i = 1; i <= n; i++){
//         if(i > 1)node[i].push_back({i-1,0});
//         if(b[i] > i)node[i].push_back({b[i],a[i]});
//     }
//     dis[1] = 0;
//     bfs();
//     ll sum = 0,ans = 0;
//     for(int i = 1; i <= n; i++){
//         sum += a[i];
//         ans = max(ans,sum - dis[i]);
//     }
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }

/*C. Concatenation of Arrays*/ //另一种贪心-样例有提示
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// struct node{
//     int a,b;
//     int pos;
//     ll sum;
//     int xu;
// }arr[N];
// struct simple{
//     int a;
//     int pos;
// };
// void solve(){
//     int n;cin >> n;
//     map<int,vector<int>> mp;
//     for(int i = 0; i < n; i++){
//         int a,b;cin >> a >> b;
//         arr[i] = {a,b,i,0,(a > b)};
//     }
//     sort(arr,arr+n,[](auto x,auto y){
//         int a1 = min(x.a,x.b);
//         int a2 = min(y.a,y.b);
//         int b1 = max(x.a,x.b);
//         int b2 = max(y.a,y.b);
//         if(a1 == a2) return b1 < b2;
//         return a1 < a2;
//     });
//     for(int i = 0; i < n; i++){
//         cout << arr[i].a << " " << arr[i].b << " ";
//     }cout << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }

/*B. Buying Lemonade*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+10;
// ll a[N];
// void solve(){
//     int n,k;cin >> n >> k;
//     ll sum = 0;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     sort(a,a+n);
//     ll res = 0;
//     ll ans = 0;
//     ll cha = 0;
//     for(int i = 0; i < n; i++){
//         ll tmp = (a[i] - cha) * (n - i);
//         if(tmp + ans >= k){
//             ans = k;
//             break;
//         }
//         else{
//             ans += tmp;
//             cha = a[i];
//             res++;
//         }
//     }
//     cout << ans + res << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }

/*A. Profitable Interest Rate*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     ll a,b;cin >> a >> b;
//     if(a >= b){
//         cout << a << "\n";
//     }
//     else{
//         //a-x + 2x = b;
//         //a + x = b;
//         //x = b - a
//         ll x = b - a;
//         if(x <= a){
//             cout << a - x << "\n";
//         }
//         else{
//             cout << 0 << "\n";
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }
