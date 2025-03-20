#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1010][1010][2]; 
ll sum[1010];
struct Node{
    ll x, w, v;
}node[1010];

void solve(){
    int n,k;cin >> n;
    for(int i = 1; i <= n; i++){
        int x,w,v;cin >> x >> w >> v;
        node[i] = {x,w,v};
    }
    memset(dp,0x3f,sizeof dp);
    node[n+1] = {0,0,0};
    sort(node+1,node+n+2,[](auto a,auto b){return a.x < b.x;});
    ll ans = 0; int l,r;
    sum[0] = 0; 
    for(int i = 1; i <= n+1; i++){
        sum[i] = sum[i-1] + node[i].v;
        ans += node[i].w;
        if(node[i].x == 0){
            l = r = i;
            dp[l][r][0] = 0; dp[l][r][1] = 0;
        }
    }
    auto get_cnt = [&](int l,int r){
        if(r < l) return 0ll;
        return sum[r] - sum[l-1];
    };
    for(int i = l; i >= 1; i--){
        for(int j = r; j <= n+1; j++){
            if(i == j) continue;
            ll cnt = get_cnt(1,i-1) + get_cnt(j+1,n+1);
            dp[i][j][0] = min({
                dp[i][j][0],
                dp[i+1][j][0] + (node[i+1].x - node[i].x)*(node[i].v + cnt),
                dp[i+1][j][1] + (node[j].x - node[i].x)*(node[i].v + cnt)
            });
            dp[i][j][1] = min({
                dp[i][j][1],
                dp[i][j-1][1] + (node[j].x - node[j-1].x)*(node[j].v + cnt),
                dp[i][j-1][0] + (node[j].x - node[i].x)*(node[j].v + cnt)
            });
            //cout << "? " << dp[i][j][0] << " " << dp[i][j][1] << "\n";
        }
    }
    //cout << min({dp[1][n+1][0],dp[1][n+1][1]}) << "\n";
    cout << ans - min({dp[1][n+1][0],dp[1][n+1][1]}) << "\n";
}
int main(){
    int t = 1;//cin >> t;
    while(t--){
        solve();
    }
}
