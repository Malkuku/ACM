#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<fstream>
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

void solve(const char* path_in,const char* path_out){
    std::ifstream fin(path_in);
    std::ofstream fout(path_out);

    int n,m,k;fin >> n >> m >> k;
    memset(dp,0,sizeof dp);
    for(int i = 1; i <= n; i++) fin >> w[i];
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
        cnt[i] = 1;
    }
    for(int i = 1; i <= m; i++){
        int x,y;fin >> x >> y;
        if(find(x) != find(y)) fa[find(x)] = y;
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
    fout << ans << "\n";

   fout.close();
   fin.close();
}

void work(int num){
    for(int i = 1; i <= num; i++){
        char path_in[50];
        char path_out[50];
        sprintf(path_in,"test_in/%d.in",i);
        sprintf(path_out,"test_out/%d.out",i);
        solve(path_in,path_out);
        cout << path_out << "\n";
    }
}

int main(){
    work(20);
    return 0;
}
