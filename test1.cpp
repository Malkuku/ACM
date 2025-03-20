/*2025.3.15 题解*/ 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e4+10;
struct{
    int num,pre,suf;   
}tr[N<<2];
void push_up(int p,int len){
    tr[p].pre = tr[p<<1].pre;
    tr[p].suf = tr[p<<1|1].suf;
    if(tr[p<<1].pre == len - len/2) tr[p].pre = tr[p<<1].pre + tr[p<<1|1].pre;
    if(tr[p<<1|1].suf == len/2) tr[p].suf = tr[p<<1].suf + tr[p<<1|1].suf;
}
void build(int p,int pl,int pr){
    if(pl == pr){
        tr[p].num = tr[p].pre = tr[p].suf = 1;
        return;
    }
    int mid = (pl + pr) >> 1;
    build(p<<1,pl,mid);
    build(p<<1|1,mid+1,pr);
    push_up(p,pr - pl + 1);
}
void update(int x,int c,int p,int pl,int pr){
    if(pl == pr){
        tr[p].num = tr[p].pre = tr[p].suf = c;
        return;
    }
    int mid = (pl + pr) >> 1;
    if(x <= mid) update(x,c,p<<1,pl,mid);
    else update(x,c,p<<1|1,mid+1,pr);
    push_up(p,pr - pl + 1);
}
int query(int x,int p,int pl,int pr){
    if(pl == pr) return tr[p].num;
    int mid = (pl + pr) >> 1;
    if(x <= mid){
        if(x + tr[p<<1].suf > mid) return tr[p<<1].suf + tr[p<<1|1].pre;
        else return query(x,p<<1,pl,mid);
    }else{
        if(mid + tr[p<<1|1].pre >= x) return tr[p<<1|1].pre + tr[p<<1].suf;
        else return query(x,p<<1|1,mid+1,pr);
    }
}
int n,m;
void solve(){
    build(1,1,n);
    stack<int> st;
    for(int i = 1; i <= m; i++){
        char ch;cin >> ch;
        if(ch == 'D'){
            int x;cin >> x;
            update(x,0,1,1,n);
            st.push(x);
        }else if(ch == 'Q'){
            int x;cin >> x;
            cout << query(x,1,1,n) << "\n";
        }else{
            if(!st.size()) continue;
            auto t = st.top();
            st.pop();
            update(t,1,1,1,n);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;//cin >> t;
    while(cin >> n >> m){
        solve();
    }
}