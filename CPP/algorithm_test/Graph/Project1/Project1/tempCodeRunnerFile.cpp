#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int, int>
int n, m;
const int N = 1e5 + 10;
const int M = 5e5 + 10;
int fi[N];
int head[M<<2];
int cnt = 0;
struct {
    int x, y, z;
}e[M<<2];
struct{
    int next,v,w;
} node[M << 2];
int depth[N];
int fa[N][30];
int find(int x){
    return fi[x] == x ? x : fi[x] = find(fi[x]);
}
void init1(){
    for (int i = 1; i <= n; i++)
        fi[i] = i;
}
void add(int u,int v,int w){
    cnt++;
    node[cnt].v = v;
    node[cnt].w = w;
    node[cnt].next = head[u];
    head[u] = cnt;
}
void kruskal(){
    init1();
    sort(e + 1, e + 1 + m, [](auto x, auto y) {    
        return x.z > y.z; 
    });
    for (int i = 1; i <= m; i++){
        int x = find(e[i].x);
        int y = find(e[i].y);
        if(x != y){
            fi[x] = y;
            add(e[i].x, e[i].y, e[i].z);
            add(e[i].y, e[i].x, e[i].z);
        }
    }
}
int lg[N];
int val[N][30];
void getlg(){
    for (int i = 1; i <= n; i++){
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    }
}
void dfs(int s,int f,int w){
    fa[s][0] = f;
    val[s][0] = w;
    depth[s] = depth[f] + 1;
    for (int i = 1; i <= lg[depth[s]]; i++){
        val[s][i] = min(val[s][i-1], val[fa[s][i - 1]][i - 1]);
        fa[s][i] = fa[fa[s][i - 1]][i - 1];
    }
    for (int i = head[s]; i; i = node[i].next){
        int pos = node[i].v;
        if(pos != f)
            dfs(pos, s, node[i].w);
    }
}

int search(int x,int y){
    int ans = 0x3f3f3f3f;
    if(depth[x] < depth[y])
        swap(x, y);
    while(depth[x] > depth[y]){
        ans = min(ans, val[x][lg[depth[x] - depth[y]] - 1]);
        x = fa[x][lg[depth[x] - depth[y]] - 1];
    }
    if(x == y)
        return ans;
    for (int k = lg[depth[x]] - 1; k >= 0; k--){
        if(fa[x][k] != fa[y][k]){
            ans = min(ans, val[x][k]);
            ans = min(ans, val[y][k]);
            x = fa[x][k];
            y = fa[y][k];
        }
    }
    ans = min({ans,val[x][0],val[y][0]});
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        e[i] = {x, y, z};
    }
    kruskal();
    getlg();
    int q;
    cin >> q;
    while(q--){
        //cout << "#cnt " << cnt << "\n";
        int x, y;
        cin >> x >> y;
        if(find(x) != find(y)){
            cout << -1 << "\n";
            continue;
        }
        dfs(1, 0, 0);
        int ans = search(x, y);
        cout << ans << "\n";
    }
    return 0;
}
