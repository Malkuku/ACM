/*hdu 1542*/ //矩形面积和
/*2025.3.23 题解*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+3;
int tag[N];double length[N],xx[N]; //用线段树维护length
struct ScanLine{ //扫描线
    double y;
    double right_x,left_x;
    int inout;
}line[N];
void push_up(int p,int pl,int pr){
    if(tag[p]) length[p] = xx[pr] - xx[pl]; //这里的区间是[左闭右开)
    else if(pl + 1 == pr) length[p] = 0;
    else length[p] = length[p<<1] + length[p<<1|1];
}
void update(int l,int r,int io,int p,int pl,int pr){
    if(l <= pl && r >= pr){
        tag[p] += io;
        push_up(p,pl,pr);
        return;
    }
    if(pl+1 == pr) return;
    int mid = (pl + pr) >> 1;
    if(l <= mid) update(l,r,io,p<<1,pl,mid);
    if(r >= mid+1) update(l,r,io,p<<1|1,mid,pr); //注意是mid
    push_up(p,pl,pr); 
}
int n;int t = 0;
void solve(){
    cin >> n;t++;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        double x1,x2,y1,y2;cin >> x1 >> y1 >> x2 >> y2;
        line[++cnt] = {y1,x2,x1,1};
        xx[cnt] = x1;
        line[++cnt] = {y2,x2,x1,-1};
        xx[cnt] = x2;
    }
    sort(xx+1,xx+1+cnt);
    sort(line+1,line+1+cnt,[](auto a,auto b)){
        return a.y < b.y;
    }
    int num = unique(xx+1,xx+cnt+1) - (xx+1);

    memset(tag,0,sizeof tag);
    memset(length,0,sizeof length);
    double ans = 0;
    for(int i = 1;i <= cnt;i++){
        ans += length[1]*(line[i].y-line[i-1].y);
        int l = lower_bound(xx+1,xx+num+1,line[i].left_x) - xx; //离散化后的相对位置
        int r = lower_bound(xx+1,xx+num+1,line[i].right_x) - xx;
        update(l,r,line[i].inout,1,1,num);
    }
    cout << "Test case # " << t << " " << fixed << setprecision(2) << ans << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;//cin >> t;
    while(t--){
        solve();
    }
}