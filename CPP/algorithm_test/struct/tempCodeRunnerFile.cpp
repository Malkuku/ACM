
/*poj 3321 Apple Tree*/
/*2025.3.2 题解 精*/ //dfs序+改单点，查区间
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define ll long long
#define PII pair<int,int>
const int N = 1e5+10;
vector<int> node[N];
int lowbit(int x){
    return x & (-x);
}
int tree[N];int n;
void update(int x,int d){
    for(int i = x; i <= n; i+=lowbit(i)){
        tree[i] += d;
    }
}
int sum(int x){
    int ans = 0;
    for(int i = x; i > 0; i -= lowbit(i)){
        ans += tree[i];
    }
    return ans;
}
PII ro[N];bool st[N];bool stt[N];int cnt = 0;
void dfs(int fa){
    ro[fa].first = ++cnt;
    st[fa] = 1;
    for(int i = 0; i < node[fa].size(); i++){
        int to = node[fa][i];
        if(!st[to])  dfs(to);
    }
    ro[fa].second = cnt;
}
void solve(){
    cin >> n;
    for(int i = 1; i <= n-1; i++){
        int u,v;cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    dfs(1);
    int m;cin >> m;
    for(int i = 0; i < m; i++){
        char op;cin >> op;
        if(op == 'C'){
            int x;cin >> x;
            if(stt[x]){
                update(ro[x].first,1);
            }else{
                update(ro[x].first,-1);
            }
            stt[x]=!stt[x];
        }else{
            int x;cin >> x;
            cout << sum(ro[x].second) - sum(ro[x].first-1)  + ro[x].second - ro[x].first+1<< "\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;//cin >> t;
    while(t--){
        solve();
    }
}