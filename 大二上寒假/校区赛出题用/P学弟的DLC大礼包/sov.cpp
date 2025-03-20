#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4+10;
int fa[N];
int dp[N];
int w[N],cnt[N];
int find(int x){
    if(x != fa[x]) return fa[x] = find(fa[x]);
    else return fa[x];
}
void solve(){
    int n,m,k;cin >> n >> m >> k;
    memset(dp,0,sizeof dp);
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
        cnt[i] = 1;
    }
    for(int i = 1; i <= m; i++){
        int x,y;cin >> x >> y;
        if(find(x) != find(y))fa[find(x)] = y;
    }
    for(int i = 1; i <= n; i++){
        if(fa[i] != i){
            w[find(i)] += w[i];
            w[i] = 0;
            cnt[find(i)] += cnt[i];
            cnt[i] = 0;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(fa[i] != i) continue;
        for(int j = k; j >= w[i]; j--){
            dp[j] = max(dp[j],dp[j-w[i]]+cnt[i]);
            ans = max(ans,dp[j]);
        }
    }
    cout << ans << "\n";
}
int main(){
    int t = 1;//cin >> t;
    while(t--){
        solve();
    }
}
