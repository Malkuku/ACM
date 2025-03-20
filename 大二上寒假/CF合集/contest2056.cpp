// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
// }
// int main(){
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*A. Shape Perimeter*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 300;
int mp[N][N];
bool st[N][N];
int ans = 0;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    while(q.size()){
        auto t = q.front();q.pop();
        for(int i = 0; i < 4; i++){
            int xx = t.first + dx[i];
            int yy = t.second + dy[i];
            if(xx < 0 || xx >= N || yy < 0 || yy >= N) continue;
            if(st[xx][yy]) continue;
            if(!mp[xx][yy]){
                st[xx][yy] = 1;
                ans++;
                continue;
            }
            q.push({xx,yy});
            st[xx][yy] = 1;
        }
    }
}
void solve(){
    int n,m; cin >> n >> m;
    ans = 0;
    memset(mp,0,sizeof mp);
    memset(st,0,sizeof st);
    vector<pair<int,int>> vc;
    for(int i = 1; i <= n; i++){
        int x,y;cin >> x >> y;
        vc.push_back({x,y});
        for(int j = x; j <= x+m; j++){
            for(int k = y; k <= y+m; k++){
                mp[j][k] = 1;
            }
        }
    }
    for(int i = 0; i < vc.size(); i++){
        if(st[vc[i].first][vc[i].second]) continue;
        else bfs(vc[i].first,vc[i].second);
    }
    cout << ans << '\n';
}
int main(){
    int t = 1;cin >> t;
    while(t--){
        solve();
    }
}