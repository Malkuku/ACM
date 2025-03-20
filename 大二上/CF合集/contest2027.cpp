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

/*C. Add Zeros*/
/*2024.11.2*/ //TLE：未知
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 3e5+10;
// ll a[N];
// void solve(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//         a[i] += i - 1;
//     }
//     map<ll,bool> st;
//     map<ll,vector<pair<ll,ll>>> mp;
//     ll ans = 0;
//     for(int i = 2; i <= n; i++){
//         mp[a[i]].push_back({a[i]+i-1,i-1});
//     }
//     queue<pair<ll,ll>> q;
//     st[n] = 1;
//     for(int i = 0; i < mp[n].size(); i++){
//         q.push({mp[n][i].first,mp[n][i].second});
//     }
//     while(q.size()){
//         auto t = q.front();
//         q.pop();
//         ans = max(ans,t.second);
//         st[t.first] = 1;
//         int len = mp[t.first].size();
//         for(int i = 0; i < len; i++){
//             //cout << "? " << t.first << "\n";
//             ll pos = mp[t.first][i].first;
//             ll cost = mp[t.first][i].second;
//             if(st[pos]) continue;
//             q.push({pos,cost+t.second});
//         }
//     }
//     ans += n;
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
/*2024.11.4*/ //题解：省去queue的时间复杂度
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans = 0;
map<ll,bool> st;
map<ll,vector<ll>> mp;
void dfs(ll x){
    if(st[x]) return;
    st[x] = 1;
    ans = max(ans,x);
    for(auto& xx : mp[x]){
        if(st[xx + x - 1] == 0) dfs(xx + x -1);
    }
}
void solve(){
    int n;cin >> n;
    st.clear();
    mp.clear();
    for(int i = 1; i <= n; i++){
        ll x;cin >> x;
        mp[x + i - 1].push_back(i);
    }
    ans = 0;
    dfs(n);
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    for(int _  = 1; _ <= t; _++){
        solve();
    }
    return 0;
}



/*B. Stalin Sort*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2010;
// int a[N];
// void solve(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];  
//     }
//     int ans = 1e9+10;
//     for(int i = 1; i <= n; i++){
//         int nex = 0,las = 0;
//         for(int j = i+1; j <= n; j++){
//             if(a[i] < a[j]) nex++;
//         }
//         ans = min(ans,nex+i-1);
//         ///cout << "? " << ans << " "<<i << "\n";
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

/*A. Rectangle Arrangement*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// int g[110][110];
// int st[110][110];
// int dx[] = {0,1,0,-1};
// int dy[] = {1,0,-1,0};
// int ans;
// void bfs(int x,int y){
//     queue<PII> q;
//     q.push({x,y});
//     ans = 0;
//     st[x][y] = 1;
//     while(q.size()){
//         auto t = q.front();
//         q.pop();
//         for(int i = 0;  i < 4; i++){
//             int xx = t.first + dx[i];
//             int yy = t.second + dy[i];
//             if(xx < 0 || yy < 0 || xx >= 110 || yy >= 110) continue;
//             if(st[xx][yy]) continue;
//             if(g[xx][yy] == 0){
//                 ans++;
//                 continue;
//             }
//             st[xx][yy] = 1;
//             q.push({xx,yy});
//         }
//     }
// }
// void solve(){
//     int n;cin >> n;
//     memset(g,0,sizeof g);
//     memset(st,0,sizeof st);
//     for(int i = 0; i < n; i++){
//         int w,h;cin >> w >> h;
//         for(int k = 1; k <= w; k++){
//             for(int p = 1; p <= h; p++){
//                 g[k][p] = 1;
//             }
//         }
//     }
//     bfs(1,1);
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
