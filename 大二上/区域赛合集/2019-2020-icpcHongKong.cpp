// gym/561727

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

/*G. Game Design*/ //构造二叉树+数学
/*2024.10.29 题解*/ 
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// int cnt,c[N],fa[N];
// int cal(int n){
//     int res = 0;
//     while(n){
//         n/=2;
//         res++;
//     }
//     return res;
// }
// void dfs(int u,int sum){
//     if(sum == 1){
//         cnt = u;
//         c[u] = 1;
//         return;
//     }
//     //左子树
//     fa[u+2] = u+1;
//     fa[u+1] = u;
//     c[u + 2] = c[u + 1] = 1;
//     //处理右子树
//     if(sum % 2 == 0){
//         c[u] = 1e9;
//         fa[u+3] = u;
//         dfs(u+3,sum/2);
//     }
//     else{
//         c[u] = cal(sum); //sum的二进制位数
//         fa[u + 3] = u;
//         dfs(u + 3,sum/2);
//     }
// }
// void solve(){
//     int sum;cin >> sum;
//     if(sum == 1){
//         cout << 2 << "\n";
//         cout << 1 << "\n";
//         cout << 1 << " " << (int)1e9 << endl;
//         return;
//     }
//     dfs(1,sum);
//     cout << cnt << endl;
//     for(int u = 2;  u <= cnt; u++){
//         cout << fa[u] << " ";
//     }cout << "\n";
//     for(int u = 1; u <= cnt; u++){
//         cout << c[u] << " ";
//     }cout << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }
