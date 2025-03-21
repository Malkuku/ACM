// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

///* 区间查询 *///

/*线段树板子*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e6 + 10;
// ll tree[N*4]; //记录线段i的最值或区间值
// ll a[N]; //数组权值
// ll tag[N << 2]; //第i个节点的lazy-tag
// int ls(int p){return p << 1;}; //左 p*2
// int rs(int p){return p << 1 | 1;};//右 p*2 + 1
// void push_up(int p){
//     tree[p] = tree[ls(p)] + tree[rs(p)]; //区间和
//     // tree[p] = min(tree[ls(p)],tree[rs(p)])
// }
// void build(int p,int pl,int pr){ //建树 编号p指向区间[pl,pr]
//     if(pl == pr) {
//         tree[p] = a[pl]; return; //单点修改时，从叶子到根进行操作
//     }
//     int mid = (pl + pr) >> 1;
//     build(ls(p),pl,mid);
//     build(rs(p),mid+1,pr);
//     push_up(p);
// }
// //查询区间和
// int query1(int L,int R,int p,int pl,int pr){
//     if(L <= pl && pr <= R) return tree[p];
//     int mid = (pl + pr) >> 1;
//     int res = 0;
//     if(L <= mid) res += query1(L,R,ls(p),pl,mid);
//     if(R > mid) res+= query1(L,R,rs(p),mid+1,pr);
//     return res;
// }
// //Lazy_Tag --- 用于优化对区间的统一修改
// //tag[i] --- 统一记录对区间的修改 --- 一致性被破坏时，才传递变化值到下一层子区间
// void addtag(ll p,ll pl,ll pr,ll d){
//     tag[p] += d;
//     tree[p] += d * (pr - pl + 1); //计算新树 + d*len
// }
// void push_down(ll p,ll pl,ll pr){ //当统一性破坏时，将addtag传给子区间
//     if(tag[p]){
//         ll mid = (pl + pr) >> 1;
//         addtag(ls(p),pl,mid,tag[p]);
//         addtag(rs(p),mid + 1,pr, tag[p]); 
//         tag[p] = 0;
//     }
// }
// int query2(int L,int R,int p,int pl,int pr){
//     if(L <= pl && pr <= R) return tree[p];
//     push_down(p,pl,pr); //相应地，加上该句话
//     int mid = (pl + pr) >> 1;
//     int res = 0;
//     if(L <= mid) res += query1(L,R,ls(p),pl,mid);
//     if(R > mid) res+= query1(L,R,rs(p),mid+1,pr);
//     return res;
// }
// //更新
// void update(ll L,ll R,ll p,ll pl,ll pr,ll d){
//     if(L <= pl && pr <= R){
//         addtag(p,pl,pr,d); //完全覆盖，打上标记
//         return;
//     }
//     push_down(p,pl,pr);
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) update(L,R,ls(p),pl,mid,d);
//     if(R > mid) update(L,R,rs(p),mid+1,pr,d);
//     push_up(p);
// }
// int main(){  
//     return 0;
// }

/*P3372 【模板】线段树 1*/ //区间修改，区间查询
/*2025.3.7*/ //懒标记法
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// ll tree[N<<2];ll a[N];
// ll tag[N<<2];
// int ls(int p){
//     return p << 1;
// }
// int rs(int p){
//     return p << 1 | 1;
// }
// void push_up(int p){
//     tree[p] = tree[ls(p)] + tree[rs(p)];
// }
// void bulid(int p,int pl,int pr){
//     if(pl == pr) {tree[p] = a[pl];return;}
//     int mid = (pl + pr) >> 1;
//     bulid(ls(p),pl,mid);
//     bulid(rs(p),mid+1,pr);
//     push_up(p);
// }
// void addtag(int p,int pl,int pr,ll d){
//     tag[p] += d;
//     tree[p] += (pr-pl+1) * d;
// }
// void push_down(int p,int pl,int pr){
//     if(tag[p]){
//         int mid = (pl + pr) >> 1;
//         addtag(ls(p),pl,mid,tag[p]);
//         addtag(rs(p),mid+1,pr,tag[p]);
//         tag[p] = 0;
//     }
// }
// void update(int l,int r,int p,int pl,int pr,ll d){
//     if(l <= pl && r >= pr){addtag(p,pl,pr,d);return;}
//     push_down(p,pl,pr);
//     int mid = (pl + pr) >> 1;
//     if(l <= mid)update(l,r,ls(p),pl,mid,d);
//     if(r >= mid+1)update(l,r,rs(p),mid+1,pr,d);
//     push_up(p);
// }
// ll query(int l,int r,int p,int pl,int pr){
//     ll res = 0;
//     if(l <= pl && r >= pr) return tree[p];
//     push_down(p,pl,pr);
//     int mid = (pl + pr) >> 1;
//     if(l <= mid) res += query(l,r,ls(p),pl,mid);
//     if(r >= mid+1) res += query(l,r,rs(p),mid+1,pr);
//     return res; 
// }
// void solve(){
//     int n,m;cin >> n >> m;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
//     bulid(1,1,n);
//     while(m--){
//         int op;cin >> op;   
//         if(op == 1){
//             int x,y;ll k;cin >> x >> y >> k;
//             update(x,y,1,1,n,k);
//         }else{
//             int x,y;cin >> x >> y;
//             cout << query(x,y,1,1,n) << "\n";
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }
/*2024.10.15*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// ll tree[N << 2];
// ll a[N];
// ll tag[N << 2];
// ll ls(ll p) {return p << 1;};
// ll rs(ll p) {return p << 1 | 1;};
// void push_up(ll p){
//     tree[p] = tree[ls(p)] + tree[rs(p)];
// }
// void bulid(ll p,ll pl,ll pr){
//     tag[p] = 0;
//     if(pl == pr){
//         tree[p] = a[pl];
//         return;
//     }
//     ll mid = (pl + pr) >> 1;
//     bulid(ls(p),pl,mid);
//     bulid(rs(p),mid+1,pr);
//     push_up(p);
// }
// void addtag(ll p,ll pl,ll pr,ll d){
//     tag[p] += d;
//     tree[p] += d * (pr - pl + 1);
// }
// void push_down(ll p,ll pl,ll pr){
//     if(tag[p]){
//         ll mid = (pl+pr) >> 1;
//         addtag(ls(p),pl,mid,tag[p]);
//         addtag(rs(p),mid+1,pr,tag[p]);
//         tag[p] = 0;
//     }
// }
// void update(ll L,ll R,ll p,ll pl,ll pr,ll d){
//     if(L <= pl && pr <= R){
//         addtag(p,pl,pr,d);
//         return;
//     }
//     push_down(p,pl,pr);
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) update(L,R,ls(p),pl,mid,d);
//     if(R > mid) update(L,R,rs(p),mid+1,pr,d);
//     push_up(p);
// }
// ll query(ll L,ll R,ll p,ll pl,ll pr){
//     if(L <= pl && pr <= R) return tree[p];
//     push_down(p,pl,pr);
//     ll res = 0;
//     ll mid = (pl + pr) >> 1;
//     //cout << p << " " << res << "\n";
//     if(L <= mid) res += query(L,R,ls(p),pl,mid);
//     if(mid < R) res += query(L,R,rs(p),mid+1,pr);
//     return res;
// }
// int main(){
//     iostream::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     ll n,m;cin >> n >> m;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//      bulid(1,1,n);
//     for(int i = 1; i <= m; i++){
//        // cout << "? \n";
//         int op;cin >> op;
//         if(op == 1){
//             int x,y,k;cin >> x >> y >> k;
//             update(x,y,1,1,n,k);
//         }
//         else{
//             int x,y;cin >> x >> y;
//             cout << query(x,y,1,1,n) << "\n";
//         }
//     }
//     return 0;
// }

/*hdu4614 Vases and Flowers*/ //二分
/*2025.3.13*/
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 5e4+5;
// struct {
//     int sum,add,first,ends;
// }tree[N << 2];
// void build(int p,int pl,int pr){
//     tree[p].add = 0,tree[p].first = pl,tree[p].ends = pr,tree[p].sum = 0;
//     if(pl == pr) return;
//     int mid = (pl + pr) >> 1;
//     build(p<<1,pl,mid);
//     build(p<<1|1,mid+1,pr);
// }
// void push_up(int p){
//     tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
//     if(tree[p << 1].first == -1) tree[p].first = tree[p<<1|1].first;
//     else if(tree[p<<1|1].first == -1) tree[p].first = tree[p<<1].first;
//     else tree[p].first = min(tree[p<<1].first,tree[p<<1|1].first);
//     if(tree[p << 1].ends == -1) tree[p].ends = tree[p<<1|1].ends;
//     else if(tree[p<<1|1].ends == -1) tree[p].ends = tree[p<<1].ends;
//     else tree[p].ends = max(tree[p<<1].ends,tree[p<<1|1].ends);
// }
// void push_down(int p,int pl,int pr){
//     int mid = (pl + pr) >> 1;
//     if(tree[p].add == 1){
//         tree[p << 1].add = tree[p << 1 | 1].add = 1;
//         tree[p << 1].first = tree[p<<1|1].first = -1;
//         tree[p<<1].ends = tree[p<<1|1].ends = -1;
//         tree[p<<1].sum = mid - pl + 1;
//         tree[p<<1|1].sum = pr - mid;
//     }else if(tree[p].add == 2){
//         tree[p << 1].add = tree[p << 1|1].add = 2;
//         tree[p<<1].first = pl,tree[p<<1].ends = mid;
//         tree[p<<1|1].first = mid+1,tree[p<<1|1].ends = pr;
//         tree[p<<1].sum = tree[p<<1|1].sum = 0;
//     }
//     tree[p].add = 0;
// }
// void update(int l,int r,int p,int pl,int pr,int d){
//     if(l <= pl && r >= pr){
//         if(d == 1){
//             tree[p].sum = pr - pl + 1;
//             tree[p].first = tree[p].ends = -1;
//             tree[p].add = 1;
//         }else if(d == 2){
//             tree[p].sum = 0;
//             tree[p].first = pl,tree[p].ends = pr;
//             tree[p].add = 2;
//         }
//         return;
//     }
//     push_down(p,pl,pr);
//     int mid = (pl+pr) >> 1;
//     if(l <= mid) update(l,r,p<<1,pl,mid,d);
//     if(r >= mid+1) update(l,r,p<<1|1,mid+1,pr,d);
//     push_up(p);
// }
// int query(int l,int r,int p,int pl,int pr){
//     if(l <= pl && r >= pr){
//         return tree[p].sum;
//     }
//     push_down(p,pl,pr);
//     int ans = 0;
//     int mid = (pl+pr) >> 1;
//     if(l <= mid) ans += query(l,r,p<<1,pl,mid);
//     if(r >= mid+1) ans += query(l,r,p<<1|1,mid+1,pr);
//     return ans;
// }
// int n,m;
// int find(int a,int sum){
//     int l = a-1,r = n+1;
//     while(l+1 < r){
//         int mid = (l+r) >> 1;
//         int res = query(a,mid,1,1,n);
//         res = mid - a + 1 - res;
//         if(res <= sum) l = mid;
//         else r = mid; 
//         //cout << "? " << res << " " << l << " " << r << "\n"; 
//     }
//     return r-1;
// }
// int queryfr(int l,int r,int p,int pl,int pr){
//     if(l <= pl && r >= pr){
//         return tree[p].first;
//     }
//     push_down(p,pl,pr);
//     int ans = 1e9;
//     int mid = (pl+pr) >> 1;
//     if(l <= mid){
//         int tmp = queryfr(l,r,p<<1,pl,mid);
//         if(tmp != -1) ans = min(tmp,ans);
//     }
//     if(r >= mid+1){
//         int tmp = queryfr(l,r,p<<1|1,mid+1,pr);
//         if(tmp != -1) ans = min(tmp,ans);
//     }
//     return ans;
// }
// int queryed(int l,int r,int p,int pl,int pr){
//     if(l <= pl && r >= pr){
//         return tree[p].ends;
//     }
//     push_down(p,pl,pr);
//     int ans = 0;
//     int mid = (pl+pr) >> 1;
//     if(l <= mid){
//         int tmp = queryed(l,r,p<<1,pl,mid);
//         if(tmp != -1) ans = max(tmp,ans);
//     }
//     if(r >= mid+1){
//         int tmp = queryed(l,r,p<<1|1,mid+1,pr);
//         if(tmp != -1) ans = max(tmp,ans);
//     }
//     return ans;
// }
// void solve(){
//     cin >> n >> m;
//     build(1,1,n);
//     for(int i = 1; i <= m; i++){
//         int op,a,b; cin >> op >> a >> b;
//         if(op == 1){
//             a++;
//             int ends = find(a,b);
//             ends = min(ends,n);
//             //cout << "? " << a << " " << ends << "\n";
//             if(query(a,ends,1,1,n) == ends - a + 1){
//                 cout << "Can not put any one.\n";
//             }else{
//                 int first = queryfr(a,ends,1,1,n);
//                 ends = queryed(first,ends,1,1,n);
//                 update(first,ends,1,1,n,1);
//                 cout << first-1 << " " << ends-1 << "\n";
//             }
//         }else{
//             a++,b++;
//             cout << query(a,b,1,1,n) << "\n";
//             update(a,b,1,1,n,2);
//         }
//     }
//     cout << "\n";
// }
// signed main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }
/*2025.3.12*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 5e4+5;
// struct {
//     int l,r,sum,add,first,ends;
// }tree[N << 2];
// void build(int l,int r,int p){
//     tree[p].add = tree[p].sum = 0;
//     tree[p].first = l,tree[p].ends = r;
//     tree[p].l = l,tree[p].r = r;
//     if(l == r) return;
//     int mid = (l+r) >> 1;
//     build(l,mid,p << 1);
//     build(mid+1,r,p << 1 | 1);
// }
// void push_up(int p){
//     tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
//     if(tree[p << 1].first == -1) tree[p].first = tree[p << 1 | 1].first;
//     else if(tree[p << 1 | 1].first == -1) tree[p].first = tree[p << 1].first;
//     else tree[p].first = min(tree[p << 1].first,tree[p << 1 | 1].first);
//     if(tree[p << 1].ends == -1) tree[p].ends = tree[p << 1 | 1].ends;
//     else if(tree[p << 1 | 1].ends == -1) tree[p].ends = tree[p << 1].ends;
//     else tree[p].ends = max(tree[p << 1].ends,tree[p << 1 | 1].ends);
// }
// void push_down(int p){
//     if(tree[p].add == -1){
//         tree[p << 1].first = -1;
//         tree[p << 1].ends = -1;
//         tree[p << 1].sum = tree[p << 1].r - tree[p << 1].l + 1;
//         tree[p << 1 | 1].first = -1;
//         tree[p << 1 | 1].ends = -1;
//         tree[p << 1 | 1].sum = tree[p << 1 | 1].r - tree[p << 1 | 1].l + 1;
//         tree[p << 1].add = tree[p << 1 | 1].add = tree[p].add;
//     }
//     if(tree[p].add == 1){
//         tree[p << 1].first = tree[p << 1].l;
//         tree[p << 1].ends = tree[p << 1].r;
//         tree[p << 1].sum = 0;
//         tree[p << 1 | 1].first = tree[p << 1 | 1].l;
//         tree[p << 1 | 1].ends = tree[p << 1 | 1].r;
//         tree[p << 1 | 1].sum = 0;
//         tree[p << 1].add = tree[p << 1 | 1].add = tree[p].add;
//     } //add == 0是不往下更新的
//     tree[p].add = 0;
// }
// void update(int l,int r,int p,int d){
//     if(tree[p].l == l && tree[p].r == r){
//         if(d == 1){
//             tree[p].add = 1;
//             tree[p].sum = 0;
//             tree[p].first = l,tree[p].ends = r;
//             return;
//         }else if(d == -1){
//             tree[p].add = -1;
//             tree[p].sum = r - l + 1;
//             tree[p].first = tree[p].ends = -1;
//         }
//         return;
//     }
//     push_down(p);
//     int mid = (tree[p].l + tree[p].r) >> 1;
//     if(mid < l){
//         update(l,r,p << 1 | 1,d);
//     }else if(mid + 1 > r){
//         update(l,r,p << 1,d);
//     }else{
//         update(l,mid,p << 1,d);
//         update(mid+1,r,p << 1 | 1,d);
//     }
//     push_up(p);
// }
// int query(int l,int r,int p){
//     if(tree[p].l == l && tree[p].r == r){
//         return tree[p].sum;
//     }
//     push_down(p);
//     int ans = 0;
//     int mid = (tree[p].l + tree[p].r) >> 1;
//     if(mid < l){
//         ans = query(l,r,p << 1|1);
//     }else if(mid+1 > r){
//         ans = query(l,r,p<<1);
//     }else{
//         ans = query(l,mid,p<<1) + query(mid+1,r,p<<1|1);
//     }
//     return ans;
// }
// int queryfr(int l,int r,int p){
//     if(tree[p].l == l && tree[p].r == r){
//         return tree[p].first;
//     }
//     push_down(p);
//     int mid = (tree[p].l + tree[p].r) >> 1;
//     if(mid < l){
//         return queryfr(l,r,p << 1|1);
//     }else if(mid+1 > r){
//         return queryfr(l,r,p << 1);
//     }else{
//         int ans = queryfr(l,mid,p<<1);
//         if(ans == -1){
//             return queryfr(mid+1,r,p<<1|1);
//         }else{
//             return ans;
//         }
//     }
// }
// int queryed(int l,int r,int p){
//     if(tree[p].l == l && tree[p].r == r){
//         return tree[p].ends;
//     }
//     push_down(p);
//     int mid = (tree[p].l + tree[p].r) >> 1;
//     if(mid < l){
//         return queryed(l,r,p << 1|1);
//     }else if(mid+1 > r){
//         return queryed(l,r,p << 1);
//     }else{
//         int ans = queryed(mid+1,r,p<<1|1);
//         if(ans == -1){
//             return queryed(l,mid,p<<1);
//         }else{
//             return ans;
//         }
//     }
// }
// int n,m;
// int find(int sta,int sum){
//     int l = sta , r = n; // 初始化二分查找的左右边界
//     int ans = n; // 初始化答案为 n
//     while(l <= r) { // 二分查找的循环条件
//         int mid = (l + r) >> 1; // 计算中间位置
//         int gg = query(sta , mid , 1); // 查询区间 [sta, mid] 内的 num 值
//         gg = mid - sta + 1 - gg; // 计算区间 [sta, mid] 内不满足条件的数量
//         if(gg >= sum) { // 如果不满足条件的数量大于等于 sum
//             r = mid - 1; // 更新右边界
//             ans = mid; // 更新答案
//         }
//         else { // 否则
//             l = mid + 1; // 更新左边界
//         }
//     }
//     return ans; // 返回答案
// }
// void solve(){
//     cin >> n >> m;
//     build(1,n,1);
//     for(int i = 1; i <= m; i++){
//         int op,a,f;
//         cin >> op >> a >> f;
//         if(op == 1){
//             a++;
//             //cout << "bug1\n";
//             int res = query(a,n,1);
//             //cout << "bug2\n";
//             res = n - a + 1 - res;
//             if(res == 0){
//                 cout << "Can not put any one.\n";
//             }else{
//                 int sum = min(res,f);
//                 int ed = find(a,sum);
//                 int fr = queryfr(a,ed,1);
//                 //cout << "bug3\n";
//                 update(fr,ed,1,-1);
//                 cout << fr-1 << " " << ed-1 << "\n";
//             }
//         }else{
//             a++,f++;
//             cout << query(a,f,1) << "\n";
//             update(a,f,1,1);
//         }
//     }
//     cout << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }
/*2025.3.8 题解*/
// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <cstdio>
// using namespace std;
// const int M = 5e4 + 10; // 定义线段树的节点数量上限
// struct TnT { // 定义线段树的节点结构
//     int l , r , num , add , first , ends; // 分别表示区间的左右端点、区间内满足条件的数量、懒惰标记、区间内第一个满足条件的位置、区间内最后一个满足条件的位置
// }T[M << 2]; // 定义线段树数组，大小为 M 的四倍
// int n , m; // n 表示总长度，m 表示操作次数
// // 构建线段树
// void build(int l , int r , int p) {
//     int mid = (l + r) >> 1; // 计算当前区间的中点
//     T[p].l = l , T[p].r = r , T[p].add = T[p].num = 0 , T[p].first = l , T[p].ends = r; // 初始化当前节点的信息
//     if(l == r) { // 如果当前区间是一个单点区间
//         return ; // 直接返回
//     }
//     build(l , mid , p << 1); // 递归构建左子树
//     build(mid + 1 , r , (p << 1) | 1); // 递归构建右子树
// }
// // 向上更新节点信息
// void pushup(int p) {
//     T[p].num = T[p << 1].num + T[(p << 1) | 1].num; // 当前节点的 num 值等于左右子节点的 num 值之和
//     if(T[p << 1].first == -1) { // 如果左子节点的 first 值为 -1
//         T[p].first = T[(p << 1) | 1].first; // 当前节点的 first 值等于右子节点的 first 值
//     }
//     else if(T[(p << 1) | 1].first == -1) { // 如果右子节点的 first 值为 -1
//         T[p].first = T[p << 1].first; // 当前节点的 first 值等于左子节点的 first 值
//     }
//     else { // 否则
//         T[p].first = min(T[(p << 1) | 1].first , T[p << 1].first); // 当前节点的 first 值等于左右子节点的 first 值的最小值
//     }
//     if(T[(p << 1) | 1].ends == -1) { // 如果右子节点的 ends 值为 -1
//         T[p].ends = T[(p << 1) | 1].ends; // 当前节点的 ends 值等于右子节点的 ends 值
//     }
//     else if(T[(p << 1) | 1].ends == -1) { // 如果右子节点的 ends 值为 -1（这里应该是左子节点，可能是代码的错误）
//         T[p].ends = T[p << 1].ends; // 当前节点的 ends 值等于左子节点的 ends 值
//     }
//     else { // 否则
//         T[p].ends = max(T[(p << 1) | 1].ends , T[p << 1].ends); // 当前节点的 ends 值等于左右子节点的 ends 值的最大值
//     }
// }
// // 向下更新节点信息
// void pushdown(int p) {
//     if(T[p].add == 1) { // 如果当前节点的懒惰标记为 1
//         T[p << 1].num = T[p << 1].r - T[p << 1].l + 1; // 更新左子节点的 num 值
//         T[p << 1].first = -1; // 更新左子节点的 first 值
//         T[p << 1].ends = -1; // 更新左子节点的 ends 值
//         T[(p << 1) | 1].num = T[(p << 1) | 1].r - T[(p << 1) | 1].l + 1; // 更新右子节点的 num 值
//         T[(p << 1) | 1].first = -1; // 更新右子节点的 first 值
//         T[(p << 1) | 1].ends = -1; // 更新右子节点的 ends 值
//         T[p << 1].add = T[p].add; // 更新左子节点的懒惰标记
//         T[(p << 1) | 1].add = T[p].add; // 更新右子节点的懒惰标记
//     }
//     if(T[p].add == -1) { // 如果当前节点的懒惰标记为 -1
//         T[p << 1].first = T[p << 1].l; // 更新左子节点的 first 值
//         T[p << 1].ends = T[p << 1].r; // 更新左子节点的 ends 值
//         T[p << 1].num = 0; // 更新左子节点的 num 值
//         T[(p << 1) | 1].num = 0; // 更新右子节点的 num 值
//         T[p << 1].add = T[p].add; // 更新左子节点的懒惰标记
//         T[(p << 1) | 1].first = T[(p << 1) | 1].l; // 更新右子节点的 first 值
//         T[(p << 1) | 1].ends = T[(p << 1) | 1].r; // 更新右子节点的 ends 值
//         T[(p << 1) | 1].add = T[p].add; // 更新右子节点的懒惰标记
//     }
//     T[p].add = 0; // 清除当前节点的懒惰标记
// }
// // 查询区间 [l, r] 内的 num 值
// int query(int l , int r , int p) {
//     int mid = (T[p].l + T[p].r) >> 1; // 计算当前区间的中点
//     if(T[p].l == l && T[p].r == r) { // 如果当前区间与查询区间完全匹配
//         return T[p].num; // 直接返回当前节点的 num 值
//     }
//     pushdown(p); // 向下更新节点信息
//     if(mid >= r) { // 如果查询区间在左子树范围内
//         return query(l , r , p << 1); // 递归查询左子树
//     }
//     else if(mid < l) { // 如果查询区间在右子树范围内
//         return query(l , r , (p << 1) | 1); // 递归查询右子树
//     }
//     else { // 否则查询区间跨越左右子树
//         return query(l , mid , p << 1) + query(mid + 1 , r , (p << 1) | 1); // 分别查询左右子树并返回结果之和
//     }
// }
// // 查询区间 [l, r] 内的 first 值
// int queryfr(int l , int r , int p) {
//     int mid = (T[p].l + T[p].r) >> 1; // 计算当前区间的中点
//     if(T[p].l == l && T[p].r == r) { // 如果当前区间与查询区间完全匹配
//         return T[p].first; // 直接返回当前节点的 first 值
//     }
//     pushdown(p); // 向下更新节点信息
//     if(mid >= r) { // 如果查询区间在左子树范围内
//         return queryfr(l , r , p << 1); // 递归查询左子树
//     }
//     else if(mid < l) { // 如果查询区间在右子树范围内
//         return queryfr(l , r , (p << 1) | 1); // 递归查询右子树
//     }
//     else { // 否则查询区间跨越左右子树
//         int ans = queryfr(l , mid , p << 1); // 查询左子树的 first 值
//         if(ans == -1) { // 如果左子树的 first 值为 -1
//             return queryfr(mid + 1 , r , (p << 1) | 1); // 返回右子树的 first 值
//         }
//         else { // 否则
//             return ans; // 返回左子树的 first 值
//         }
//     }
// }
// // 查询区间 [l, r] 内的 ends 值
// int queryed(int l , int r , int p) {
//     int mid = (T[p].l + T[p].l) >> 1; // 计算当前区间的中点（这里应该是 T[p].r，可能是代码的错误）
//     if(T[p].l == l && T[p].r == r) { // 如果当前区间与查询区间完全匹配
//         return T[p].ends; // 直接返回当前节点的 ends 值
//     }
//     pushdown(p); // 向下更新节点信息
//     if(mid >= r) { // 如果查询区间在左子树范围内
//         return queryed(l , r , p << 1); // 递归查询左子树
//     }
//     else if(mid < l) { // 如果查询区间在右子树范围内
//         return queryed(l , r , (p << 1) | 1); // 递归查询右子树
//     }
//     else { // 否则查询区间跨越左右子树
//         int ans = queryed(mid + 1 , r , (p << 1) | 1); // 查询右子树的 ends 值
//         if(ans == -1) { // 如果右子树的 ends 值为 -1
//             return queryed(l , mid , p << 1); // 返回左子树的 ends 值
//         }
//         else { // 否则
//             return ans; // 返回右子树的 ends 值
//         }
//     }
// }
// // 更新区间 [l, r] 的信息
// void updata(int l , int r , int p , int ad) {
//     int mid = (T[p].l + T[p].r) >> 1; // 计算当前区间的中点
//     if(T[p].l == l && T[p].r == r) { // 如果当前区间与更新区间完全匹配
//         if(ad == 1) { // 如果更新操作为 1
//             T[p].add = 1; // 设置当前节点的懒惰标记为 1
//             T[p].num = T[p].r - T[p].l + 1; // 更新当前节点的 num 值
//             T[p].first = -1; // 更新当前节点的 first 值
//             T[p].ends = -1; // 更新当前节点的 ends 值
//             return ; // 直接返回
//         }
//         if(ad == -1) { // 如果更新操作为 -1
//             T[p].add = -1; // 设置当前节点的懒惰标记为 -1
//             T[p].num = 0; // 更新当前节点的 num 值
//             T[p].first = T[p].l; // 更新当前节点的 first 值
//             T[p].ends = T[p].r; // 更新当前节点的 ends 值
//             return ; // 直接返回
//         }
//     }
//     pushdown(p); // 向下更新节点信息
//     if(mid >= r) { // 如果更新区间在左子树范围内
//         updata(l , r , p << 1 , ad); // 递归更新左子树
//     }
//     else if(mid < l) { // 如果更新区间在右子树范围内
//         updata(l , r , (p << 1) | 1 , ad); // 递归更新右子树
//     }
//     else { // 否则更新区间跨越左右子树
//         updata(l , mid , p << 1 , ad); // 更新左子树
//         updata(mid + 1 , r , (p << 1) | 1 , ad); // 更新右子树
//     }
//     pushup(p); // 向上更新节点信息
// }
// // 二分查找满足条件的区间
// int bisearch(int sta , int sum) {
//     int l = sta , r = n; // 初始化二分查找的左右边界
//     int ans = n; // 初始化答案为 n
//     while(l <= r) { // 二分查找的循环条件
//         int mid = (l + r) >> 1; // 计算中间位置
//         int gg = query(sta , mid , 1); // 查询区间 [sta, mid] 内的 num 值
//         gg = mid - sta + 1 - gg; // 计算区间 [sta, mid] 内不满足条件的数量
//         if(gg >= sum) { // 如果不满足条件的数量大于等于 sum
//             r = mid - 1; // 更新右边界
//             ans = mid; // 更新答案
//         }
//         else { // 否则
//             l = mid + 1; // 更新左边界
//         }
//     }
//     return ans; // 返回答案
// }
// int main() {
//     int t; // 测试用例的数量
//     scanf("%d" , &t); // 输入测试用例的数量
//     while(t--) { // 遍历每个测试用例
//         scanf("%d%d" , &n , &m); // 输入总长度 n 和操作次数 m
//         build(1 , n , 1); // 构建线段树
//         for(int i = 1 ; i <= m ; i++) { // 遍历每个操作
//             int k , a , f; // 操作类型、操作区间左端点、操作区间右端点
//             scanf("%d%d%d" , &k , &a , &f); // 输入操作信息
//             if(k == 1) { // 如果操作类型为 1
//                 a++; // 将操作区间左端点加 1
//                 int res = query(a , n , 1); // 查询区间 [a, n] 内的 num 值
//                 res = n - a + 1 - res; // 计算区间 [a, n] 内不满足条件的数量
//                 if(res == 0) { // 如果不满足条件的数量为 0
//                     printf("Can not put any one.\n"); // 输出无法放置
//                     continue; // 跳过当前操作
//                 }
//                 int sum = min(res , f); // 计算需要放置的数量
//                 int ed = bisearch(a , sum); // 二分查找满足条件的区间
//                 int fr = queryfr(a , ed , 1); // 查询区间 [a, ed] 内的 first 值
//                 updata(fr , ed , 1 , 1); // 更新区间 [fr, ed] 的信息
//                 printf("%d %d\n" , fr - 1 , ed - 1); // 输出放置的位置
//             }
//             if(k == 2) { // 如果操作类型为 2
//                 a++ , f++; // 将操作区间左端点和右端点加 1
//                 int res = query(a , f , 1); // 查询区间 [a, f] 内的 num 值
//                 updata(a , f , 1 , -1); // 更新区间 [a, f] 的信息
//                 printf("%d\n" , res); // 输出查询结果
//             }
//         }
//         printf("\n"); // 输出换行符
//     }
//     return 0; // 返回 0
// }

/*poj2528 Mayor's posters*/ //离散化
/*2025.3.13*/
// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<map>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// struct {
//     int add,tag;
// }tree[N << 2];
// map<int,bool> mp;
// pair<int,int> a[N];
// void build(int p,int pl,int pr){
//     tree[p].add = tree[p].tag = 0;
//     if(pl == pr) return;
//     int mid = (pl + pr) >> 1;
//     build(p<<1,pl,mid);
//     build(p<<1|1,mid+1,pr);
// }
// void push_down(int p,int pl,int pr){
//     if(tree[p].add){
//         tree[p<<1].add = tree[p<<1|1].add = tree[p].add;
//         tree[p].add = 0; 
//     }
// }
// void update(int l,int r,int p,int pl,int pr,int d){
//     if(l <= pl && r >= pr){
//         tree[p].add = d;
//         return;
//     }
//     push_down(p,pl,pr);
//     int mid = (pl+pr)>>1;
//     if(l <= mid) update(l,r,p<<1,pl,mid,d);
//     if(r >= mid+1) update(l,r,p<<1|1,mid+1,pr,d);
// }
// void query(int l,int r,int p,int pl,int pr){
//     if(l <= pl && r >= pr && tree[p].add){
//         mp[tree[p].add] = 1;
//         return;
//     }
//     if(pl == pr) return;
//     push_down(p,pl,pr);
//     int mid = (pl+pr)>>1;
//     if(l <= mid) query(l,r,p<<1,pl,mid);
//     if(r >= mid+1) query(l,r,p<<1|1,mid+1,pr);
// }
// void solve(){
//     int n;cin >> n;
//     vector<int> arr;
//     mp.clear();
//     for(int i = 1; i <= n; i++){
//         int l,r;cin >> l >> r;
//         a[i] = {l,r};
//         arr.push_back(l);
//         arr.push_back(r);
//     }
//     sort(arr.begin(),arr.end());
//     arr.erase(unique(arr.begin(),arr.end()),arr.end());
//     int len = arr.size();
//     for(int i = 1; i < len; i++){
//         if(arr[i] - arr[i-1] > 1) arr.push_back(arr[i-1]+1);
//     }
//     sort(arr.begin(),arr.end());
//     len = arr.size();
//     build(1,1,len);
//     for(int i = 1; i <= n; i++){
//         int l = lower_bound(arr.begin(),arr.end(),a[i].first) - arr.begin();
//         int r = lower_bound(arr.begin(),arr.end(),a[i].second) - arr.begin();
//         update(l+1,r+1,1,1,len,i);
//     }
//     query(1,len,1,1,len);
//     cout << mp.size() << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }


///* 区间最值 *///

/*hdu5306 Gorgeous Sequence*/ //区间最值模板
/*2025.3.15*/ //疑似被卡常
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int n,m;
// const int N = 1e6+5;
// struct {
//     ll l,r,sum,ma,se,cnt;
//     ll lz1,lz2;
// }tr[N << 2];
// void push_up(int p){
//     tr[p].sum = tr[p<<1].sum + tr[p<<1|1].sum;
//     tr[p].ma = max(tr[p<<1].ma,tr[p<<1|1].ma);
//     if(tr[p<<1].ma == tr[p<<1|1].ma){
//         tr[p].cnt = tr[p<<1].cnt+tr[p<<1|1].cnt;
//         tr[p].se = max(tr[p<<1].se,tr[p<<1|1].se);
//     }else{
//         tr[p].se = max({
//             tr[p<<1].se,
//             tr[p<<1|1].se,
//             min(tr[p<<1].ma,tr[p<<1|1].ma),
//         });
//         tr[p].cnt = tr[p<<1].ma > tr[p<<1|1].ma
//                 ? tr[p<<1].cnt : tr[p<<1|1].cnt;
//     }
// }
// int a[N];
// void build(int p,int pl,int pr){
//     tr[p].l = pl,tr[p].r = pr;
//     if(pl == pr){
//         tr[p].sum = tr[p].ma = a[pl];
//         tr[p].se = -1,tr[p].cnt = 1;
//         return;
//     }
//     int mid = (pl+pr) >> 1;
//     build(p<<1,pl,mid);
//     build(p<<1|1,mid+1,pr);
//     push_up(p);
// }
// void addtag(int p,int lz1,int lz2){
//     tr[p].sum += tr[p].cnt*lz1 + (tr[p].r - tr[p].l+1-tr[p].cnt)*lz2;
//     tr[p].ma += lz1;
//     if(tr[p].se != -1)tr[p].se += lz2;
//     tr[p].lz1 += lz1;
//     tr[p].lz2 += lz2;
// }
// void push_down(int p) {
//     if (tr[p].ma < tr[p<<1].ma) {
//         tr[p<<1].sum -= tr[p<<1].cnt * (tr[p<<1].ma - tr[p].ma);
//         tr[p<<1].ma = tr[p].ma;
//     }
//     if (tr[p].ma < tr[p<<1|1].ma) {
//         tr[p<<1|1].sum -= tr[p<<1|1].cnt * (tr[p<<1|1].ma - tr[p].ma);
//         tr[p<<1|1].ma = tr[p].ma;
//     }
// }
// void update(int l, int r, int p, int pl, int pr, int d) {
//     if (tr[p].ma <= d) return;
//     if (l <= pl && r >= pr && d > tr[p].se) {
//         tr[p].sum -= tr[p].cnt * (tr[p].ma - d);
//         tr[p].ma = d;
//         return;
//     }
//     push_down(p);
//     int mid = (pl + pr) >> 1;
//     if (l <= mid) update(l, r, p<<1, pl, mid, d);
//     if (r >= mid + 1) update(l, r, p<<1|1, mid + 1, pr, d);
//     push_up(p);
// }
// ll queryMax(int l, int r, int p, int pl, int pr) {
//     if (l <= pl && r >= pr) return tr[p].ma;
//     push_down(p);
//     int mid = (pl + pr) >> 1;
//     ll ans = 0;
//     if (l <= mid) ans = max(ans, queryMax(l, r, p<<1, pl, mid));
//     if (r >= mid + 1) ans = max(ans, queryMax(l, r, p<<1|1, mid + 1, pr));
//     return ans;
// }
// ll querySum(int l, int r, int p, int pl, int pr) {
//     if (l <= pl && r >= pr) return tr[p].sum;
//     push_down(p);
//     int mid = (pl + pr) >> 1;
//     ll ans = 0;
//     if (l <= mid) ans += querySum(l, r, p<<1, pl, mid);
//     if (r >= mid + 1) ans += querySum(l, r, p<<1|1, mid + 1, pr);
//     return ans;
// }
// void solve(){
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     build(1,1,n);
//     for(int i = 1; i <= m; i++){
//         int op,x,y;cin >> op >> x >> y;
//         if(op == 0){
//             int d;cin >> d;
//             update(x,y,1,1,n,d);
//         }else if(op == 1){
//             cout << queryMax(x,y,1,1,n) << "\n";
//         }else if(op == 2){
//             cout << querySum(x,y,1,1,n) << "\n";
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }
/*2025.3.13 题解*/ //通过次小值对子树剪枝
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e6+5;
// struct {
//     ll sum,ma,se,num; //区间和，最大值，严格次大值，最大值数量
// }tree[N << 2];
// void push_up(int p){
//     tree[p].sum = tree[p<<1].sum + tree[p<<1|1].sum;
//     tree[p].ma = max(tree[p<<1].ma,tree[p<<1|1].ma);
//     if(tree[p<<1].ma == tree[p<<1|1].ma){
//         tree[p].se = max(tree[p<<1].se,tree[p<<1|1].se);
//         tree[p].num = tree[p<<1].num + tree[p<<1|1].num;
//     }else{
//         tree[p].se = max({tree[p<<1].se,
//                         tree[p<<1|1].se,
//                         min(tree[p<<1].ma,tree[p<<1|1].ma)});
//         tree[p].num = tree[p<<1].ma > tree[p<<1|1].ma 
//                     ? tree[p<<1].num : tree[p<<1|1].num;
//     }
// }
// int a[N];
// void build(int p,int pl,int pr){
//     if(pl == pr){
//         tree[p].ma = tree[p].sum = a[pl];
//         tree[p].se = -1,tree[p].num = 1;
//         return;
//     }
//     int mid = (pl+pr) >> 1;
//     build(p<<1,pl,mid);
//     build(p<<1|1,mid+1,pr);
//     push_up(p);
// }
// void push_down(int p){
//     if(tree[p].ma < tree[p<<1].ma){
//         tree[p<<1].sum -= tree[p<<1].num*(tree[p<<1].ma - tree[p].ma);
//         tree[p<<1].ma = tree[p].ma;
//     }
//     if(tree[p].ma < tree[p<<1|1].ma){
//         tree[p<<1|1].sum -= tree[p<<1|1].num*(tree[p<<1|1].ma - tree[p].ma);
//         tree[p<<1|1].ma = tree[p].ma;
//     }
// }
// void update(int l,int r,int p,int pl,int pr,int d){
//     if(tree[p].ma <= d) return;
//     if(l <= pl && r >= pr && d > tree[p].se){ //不会影响次小值 
//         tree[p].sum -= tree[p].num*(tree[p].ma - d);
//         tree[p].ma = d;
//         return;
//     }
//     push_down(p);
//     int mid = (pl+pr) >> 1;
//     if(l<=mid) update(l,r,p<<1,pl,mid,d);
//     if(r>=mid+1) update(l,r,p<<1|1,mid+1,pr,d);
//     push_up(p);
// }
// ll queryMax(int l,int r,int p,int pl,int pr){
//     if(l <= pl && r >= pr){
//         return tree[p].ma;
//     }
//     push_down(p);
//     int mid = (pl + pr) >> 1;
//     ll ans = 0;
//     if(l <= mid) ans = max(ans,queryMax(l,r,p<<1,pl,mid));
//     if(r >= mid+1) ans = max(ans,queryMax(l,r,p<<1|1,mid+1,pr));
//     return ans; 
// }
// ll querySum(int l,int r,int p,int pl,int pr){
//     if(l <= pl && r >= pr){
//         return tree[p].sum;
//     }
//     push_down(p);
//     int mid = (pl+pr)>>1;
//     ll ans = 0;
//     if(l <= mid) ans += querySum(l,r,p<<1,pl,mid);
//     if(r >= mid+1) ans += querySum(l,r,p<<1|1,mid+1,pr);
//     return ans;
// }
// void solve(){
//     int n,m;cin >> n >> m;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     build(1,1,n);
//     for(int i = 1; i <= m; i++){
//         int op,x,y;cin >> op >> x >> y;
//         if(op == 0){
//             int d;cin >> d;
//             update(x,y,1,1,n,d);
//         }else if(op == 1){
//             cout << queryMax(x,y,1,1,n) << "\n";
//         }else{
//             cout << querySum(x,y,1,1,n) << "\n";
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*p6242 【模板】线段树 3（区间最值操作、区间历史最值）*/ //区间历史最值
/*2025.3.14 题解*/ //对addtag拆分以保证his更新逻辑正确
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 5e5+10;
// struct {
//     int l,r;
//     ll ma,se,num,sum,his;
//     ll lz1,lz2,lz3,lz4;
//     void clear(){lz1 = lz2 = lz3 = lz4 = 0;} 
//     //lz1最大值增量，lz2历史最大值增量，lz3非最大值增量，lz4历史非最大值增量
// }tr[N<<2];
// void push_up(int p){
//     tr[p].sum = tr[p<<1].sum + tr[p<<1|1].sum;
//     tr[p].ma = max(tr[p<<1].ma,tr[p<<1|1].ma);
//     tr[p].his = max(tr[p<<1].his,tr[p<<1|1].his);
//     if(tr[p<<1].ma == tr[p<<1|1].ma){
//         tr[p].se = max(tr[p<<1].se,tr[p<<1|1].se);
//         tr[p].num = tr[p<<1].num + tr[p<<1|1].num;
//     }else{
//         tr[p].se = max({
//             tr[p<<1].se,
//             tr[p<<1|1].se,
//             min(tr[p<<1].ma,tr[p<<1|1].ma),
//         });
//         tr[p].num = tr[p<<1].ma > tr[p<<1 | 1].ma 
//                 ? tr[p<<1].num : tr[p<<1|1].num;
//     } 
// }
// int a[N];
// void build(int p,int pl,int pr){
//     tr[p].l = pl,tr[p].r = pr;
//     if(pl == pr){
//         tr[p].ma = tr[p].sum = tr[p].his = a[pl];
//         tr[p].num = 1,tr[p].se = -1e9;
//         tr[p].clear();
//         return;
//     }
//     int mid = (pl+pr) >> 1;
//     build(p<<1,pl,mid);
//     build(p<<1|1,mid+1,pr);
//     push_up(p);
// }
// void updateLz(int p,int l1,int l2,int l3,int l4){
//     tr[p].sum += (l1*tr[p].num + l3*(tr[p].r - tr[p].l + 1 - tr[p].num));
//     tr[p].his = max(tr[p].his,tr[p].ma+l2);
//     tr[p].ma += l1;
//     if(tr[p].se != -1e9) tr[p].se += l3;
//     tr[p].lz2 = max(tr[p].lz2,tr[p].lz1+l2);
//     tr[p].lz1 += l1;
//     tr[p].lz4 = max(tr[p].lz4,tr[p].lz3+l4);
//     tr[p].lz3 += l3;
// }
// void push_down(int p){
//     ll maxn = max(tr[p<<1].ma,tr[p<<1|1].ma);
//     if(tr[p<<1].ma == maxn) updateLz(p<<1,tr[p].lz1,tr[p].lz2,tr[p].lz3,tr[p].lz4);
//     else updateLz(p<<1,tr[p].lz3,tr[p].lz4,tr[p].lz3,tr[p].lz4);
//     if(tr[p<<1|1].ma == maxn) updateLz(p<<1|1,tr[p].lz1,tr[p].lz2,tr[p].lz3,tr[p].lz4);
//     else updateLz(p<<1|1,tr[p].lz3,tr[p].lz4,tr[p].lz3,tr[p].lz4);
//     tr[p].clear();
// }
// void updateMin(int l,int r,int p,ll d){
//     if(tr[p].l > r || tr[p].r < l || tr[p].ma <= d) return;
//     if(l <= tr[p].l && r >= tr[p].r && tr[p].se < d){
//         updateLz(p,d - tr[p].ma,d - tr[p].ma,0,0);
//         return;
//     }
//     push_down(p);
//     updateMin(l,r,p<<1,d);
//     updateMin(l,r,p<<1|1,d);
//     push_up(p);
// }
// void updateAdd(int l,int r,int p,ll d){
//     if(tr[p].l > r || tr[p].r < l) return;
//     if(l <= tr[p].l && r >= tr[p].r){
//         updateLz(p,d,d,d,d);
//         return;
//     }
//     push_down(p);
//     updateAdd(l,r,p<<1,d);
//     updateAdd(l,r,p<<1|1,d);
//     push_up(p);
// }
// ll querySum(int l,int r,int p,int pl,int pr){
//     if(l <= pl && r >= pr){
//         return tr[p].sum;
//     }
//     push_down(p);
//     ll ans = 0;
//     int mid = (pl + pr) >> 1;
//     if(l <= mid) ans += querySum(l,r,p<<1,pl,mid);
//     if(r >= mid + 1) ans += querySum(l,r,p<<1|1,mid+1,pr);
//     return ans;
// }
// ll queryMaxA(int l,int r,int p,int pl,int pr){
//     if(l <= pl && r >= pr){
//         return tr[p].ma;
//     }
//     push_down(p);
//     ll ans = -1e18;
//     int mid = (pl + pr) >> 1;
//     if(l <= mid) ans = max(ans,queryMaxA(l,r,p<<1,pl,mid));
//     if(r >= mid + 1) ans = max(ans,queryMaxA(l,r,p<<1|1,mid+1,pr));
//     return ans;
// }
// ll queryMaxB(int l,int r,int p,int pl,int pr){
//     if(l <= pl && r >= pr){
//         return tr[p].his;
//     }
//     push_down(p);
//     ll ans = -1e18;
//     int mid = (pl + pr) >> 1;
//     if(l <= mid) ans = max(ans,queryMaxB(l,r,p<<1,pl,mid));
//     if(r >= mid + 1) ans = max(ans,queryMaxB(l,r,p<<1|1,mid+1,pr));
//     return ans;
// }
// void solve(){
//     int n,m;cin >> n >> m;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     build(1,1,n);
//     for(int i = 1; i <= m; i++){
//         int op,l,r;cin >> op >> l >> r;
//         if(op == 1){
//             int k;cin >> k;
//             updateAdd(l,r,1,k);
//         }else if(op == 2){
//             int v;cin >> v;
//             updateMin(l,r,1,v);
//         }else if(op == 3){
//             cout << querySum(l,r,1,1,n) << "\n";
//         }else if(op == 4){
//             cout << queryMaxA(l,r,1,1,n) << "\n";
//         }else if(op == 5){
//             cout << queryMaxB(l,r,1,1,n) << "\n";
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }


///* 区间合并 *///

/*hdu1540 Tunnel Warfare*/ //单点修改
/*2025.3.20*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 5e4+10;
// struct{
//     int pre,suf,num;
// }tr[N<<2];
// void push_up(int p,int len){
//     //cout << "bug1\n";
//     tr[p].pre = tr[p<<1].pre;
//     tr[p].suf = tr[p<<1|1].suf;
//     if(tr[p<<1].pre == len - len/2){
//         tr[p].pre = tr[p<<1].pre + tr[p<<1|1].pre;
//     }
//     if(tr[p<<1|1].suf == len/2){
//         tr[p].suf = tr[p<<1].suf + tr[p<<1|1].suf;
//     }
//     //cout << "?bug1\n";
// }
// void build(int p,int pl,int pr){
//         //cout << "bug2\n";
//     if(pl == pr){
//         tr[p].num = tr[p].pre = tr[p].suf = 1;
//         return;
//     }
//     int mid = (pl + pr) >> 1;
//     build(p<<1,pl,mid);
//     build(p<<1|1,mid+1,pr);
//     push_up(p,pr-pl+1);
// }
// void update(int x,int c,int p,int pl,int pr){
//        // cout << "bug3\n";
//     if(pl == pr){
//         tr[p].num = tr[p].pre = tr[p].suf = c;
//         return;
//     }
//     int mid = (pl+pr)>>1;
//     if(x <= mid) update(x,c,p<<1,pl,mid);
//     else update(x,c,p<<1|1,mid+1,pr);
//     push_up(p,pr-pl+1);
// }
// int query(int x,int p,int pl,int pr){
//       //  cout << "bug4\n";
//     if(pl == pr) return tr[p].num;
//     int mid = (pl+pr)>>1;
//     if(x <= mid){
//         if(x + tr[p<<1].suf > mid){
//             return tr[p<<1].suf + tr[p<<1|1].pre;
//         }else{
//             return query(x,p<<1,pl,mid);
//         }
//     }else{
//         if(x - tr[p<<1|1].pre < mid + 1){
//             return tr[p<<1|1].pre + tr[p<<1].suf;
//         }else{
//             return query(x,p<<1|1,mid+1,pr);
//         }
//     }
//     return 0;
// }
// int n,m;
// void solve(){
//     build(1,1,n);
//     stack<int> st;
//     while(m--){
//         char ch;cin >> ch;
//         if(ch == 'D'){
//             int x;cin >> x;
//             st.push(x);
//             update(x,0,1,1,n);
//         }else if(ch == 'Q'){
//             int x;cin  >> x;
//             cout << query(x,1,1,n) << "\n";
//         }else{
//             if(!st.size()) continue;
//             auto x = st.top();st.pop();
//             update(x,1,1,1,n);
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(cin >> n >> m){
//         solve();
//     }
// }
/*2025.3.15 题解*/ 
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 5e4+10;
// struct{
//     int num,pre,suf;   
// }tr[N<<2];
// void push_up(int p,int len){
//     tr[p].pre = tr[p<<1].pre;
//     tr[p].suf = tr[p<<1|1].suf;
//     if(tr[p<<1].pre == len - len/2) tr[p].pre = tr[p<<1].pre + tr[p<<1|1].pre;
//     if(tr[p<<1|1].suf == len/2) tr[p].suf = tr[p<<1].suf + tr[p<<1|1].suf;
// }
// void build(int p,int pl,int pr){
//     if(pl == pr){
//         tr[p].num = tr[p].pre = tr[p].suf = 1;
//         return;
//     }
//     int mid = (pl + pr) >> 1;
//     build(p<<1,pl,mid);
//     build(p<<1|1,mid+1,pr);
//     push_up(p,pr - pl + 1);
// }
// void update(int x,int c,int p,int pl,int pr){
//     if(pl == pr){
//         tr[p].num = tr[p].pre = tr[p].suf = c;
//         return;
//     }
//     int mid = (pl + pr) >> 1;
//     if(x <= mid) update(x,c,p<<1,pl,mid);
//     else update(x,c,p<<1|1,mid+1,pr);
//     push_up(p,pr - pl + 1);
// }
// int query(int x,int p,int pl,int pr){
//     if(pl == pr) return tr[p].num;
//     int mid = (pl + pr) >> 1;
//     if(x <= mid){
//         if(x + tr[p<<1].suf > mid) return tr[p<<1].suf + tr[p<<1|1].pre;
//         else return query(x,p<<1,pl,mid);
//     }else{
//         if(mid + tr[p<<1|1].pre >= x) return tr[p<<1|1].pre + tr[p<<1].suf;
//         else return query(x,p<<1|1,mid+1,pr);
//     }
// }
// int n,m;
// void solve(){
//     build(1,1,n);
//     stack<int> st;
//     for(int i = 1; i <= m; i++){
//         char ch;cin >> ch;
//         if(ch == 'D'){
//             int x;cin >> x;
//             update(x,0,1,1,n);
//             st.push(x);
//         }else if(ch == 'Q'){
//             int x;cin >> x;
//             cout << query(x,1,1,n) << "\n";
//         }else{
//             if(!st.size()) continue;
//             auto t = st.top();
//             st.pop();
//             update(t,1,1,1,n);
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(cin >> n >> m){
//         solve();
//     }
// }

/*poj3367 Hotel*/ //区间修改
/*2025.3.20*/
// #include<iostream>
// #include<cstring>
// using namespace std;
// #define ll long long
// const int N = 4e5+10;
// struct{
//     int pre,suf,num,add;
// }tr[N<<2];
// void push_up(int p,int len){
//     tr[p].pre = tr[p<<1].pre;
//     tr[p].suf = tr[p<<1|1].suf;
//     if(tr[p<<1].pre == len - len/2){
//         tr[p].pre += tr[p<<1|1].pre;
//     }
//     if(tr[p<<1|1].suf == len/2){
//         tr[p].suf += tr[p<<1].suf;
//     }
//     tr[p].num = max(tr[p].pre,tr[p].suf);
// }
// void build(int p,int pl,int pr){
//     if(pl == pr){
//         tr[p].num = tr[p].pre = tr[p].suf = 1;
//         tr[p].add = 0;
//         return;
//     }
//     int mid = (pl+pr) >> 1;
//     build(p<<1,pl,mid);
//     build(p<<1|1,mid+1,pr);
//     push_up(p,pr-pl+1);
// }
// void addtag(int p,int len){
//     if(tr[p].add == -1){
//         tr[p].pre = tr[p].suf = tr[p].num = 0;
//     }else if(tr[p].add == 1){
//         tr[p].pre = tr[p].suf = tr[p].num = len;
//     }
// }
// void push_down(int p,int pl,int pr){
//     if(tr[p].add){
//         tr[p<<1].add = tr[p<<1|1].add = tr[p].add;
//         tr[p].add = 0;
//         int mid = (pl+pr) >> 1;
//         addtag(p<<1,mid-pl+1);
//         addtag(p<<1|1,pr-mid);
//     }
// }
// void update(int l,int r,int c,int p,int pl,int pr){
//     if(l <= pl && r >= pr){
//         tr[p].add = c;
//         addtag(p,pr-pl+1);
//         return;
//     }
//     push_down(p,pl,pr);
//     int mid = (pl + pr) >> 1;
//     if(l <= mid) update(l,r,c,p<<1,pl,mid);
//     if(r >= mid+1) update(l,r,c,p<<1|1,mid+1,pr);
//     push_up(p,pr-pl+1);
// }
// int query(int p,int len,int pl,int pr){
//     if(pl == pr){
//         return pl;
//     }
//     //if(tr[p].num == len){
//     //    return pl;
//     //}
//     push_down(p,pl,pr);
//     int mid = (pl+pr) >> 1;
//     if(tr[p].num >= len){
//         if(tr[p<<1].num >= len) return query(p<<1,len,pl,mid);
//         if(tr[p<<1].suf + tr[p<<1|1].pre >= len){
//             return mid - tr[p<<1].suf + 1;
//         }
//         if(tr[p<<1|1].num >= len) return query(p<<1|1,len,mid+1,pr);
//     }
//     else return 0;
// }
// void solve(){
//     int n,m;cin >> n >> m;
//     build(1,1,n);
//     while(m--){
//         int op;cin >> op;
//         if(op == 1){
//             int d;cin >> d;
//             int ans = query(1,d,1,n);
//             cout << ans << "\n";
//             if(ans){
//                 update(ans,ans+d-1,-1,1,1,n);
//             }
//         }else if(op == 2){
//             int x,d;cin >> x >> d;
//             int r = max(x+d-1,n);
//             update(x,r,1,1,1,n);
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }
/*2025.3.18 题解*/
// #include<cstdio>
// #include<cstring>
// #include<iostream>
// using namespace std;
// #define ll long long
// const int N = 50010;
// struct{
//     int l,r,resl,resr,resm,flag;
// }tr[N<<2];
// int n,m;
// void build(int l,int r,int index){
//     tr[index].l = l;
//     tr[index].r = r;
//     tr[index].resl = tr[index].resr = tr[index].resm = r-l+1;
//     tr[index].flag = -1;
//     if(l == r) return;
//     int mid = (l+r) >> 1;
//     build(l,mid,index << 1);
//     build(mid+1,r,index << 1|1);
// }
// void addtag(int index){
//     if(!tr[index].flag){
//         tr[index].resl = tr[index].resr = tr[index].resm = tr[index].r - tr[index].l+1;
//     }else{
//         tr[index].resl = tr[index].resr = tr[index].resm = 0;
//     }
// }
// void push_down(int index){
//     if(tr[index].r == tr[index].l || tr[index].flag == -1) return;
//     tr[index << 1].flag = tr[index<<1|1].flag = tr[index].flag;
//     tr[index].flag = -1;
//     addtag(index<<1);
//     addtag(index<<1|1);
// }
// void push_up(int index){
//     tr[index].resm=max(tr[index<<1].resr+tr[index<<1|1].resl,max(tr[index<<1].resm,tr[index<<1|1].resm));
//     tr[index].resl = tr[index<<1].resm == tr[index<<1].r - tr[index<<1].l+1
//                 ? tr[index<<1].resm + tr[index<<1|1].resl
//                 : tr[index<<1].resl;
//     tr[index].resr = tr[index<<1|1].resm == tr[index<<1|1].r - tr[index<<1|1].l+1
//                 ? tr[index<<1].resr + tr[index<<1|1].resm
//                 : tr[index<<1|1].resr;
// }
// void update(int l,int r,int val,int index){
//     push_down(index);
//     if(tr[index].l == l && tr[index].r == r){
//         tr[index].flag = val;
//         addtag(index);
//         return;
//     }
//     int mid = (tr[index].l + tr[index].r) >> 1;
//     if(r <= mid){
//         update(l,r,val,index<<1);
//     }else if(l > mid){
//         update(l,r,val,index<<1|1);
//     }else{
//         update(l,mid,val,index<<1);
//         update(mid+1,r,val,index<<1|1);
//     }
//     push_up(index);
// }
// int search(int val,int index){
//     if(tr[index].l == tr[index].r){
//         return tr[index].l;
//     }
//     push_down(index);
//     if(tr[index<<1].resm >= val){ //优先找左边
//         return search(val,index<<1);
//     }
//     if(tr[index<<1].resr+tr[index<<1|1].resl >= val){ //跨区间
//         return tr[index<<1].r - tr[index<<1].resr + 1;
//     }
//     if(tr[index<<1|1].resm >= val){ //最后找右边
//         return search(val,index<<1|1);
//     }
//     return 0;
// }
// void solve(){
//     cin >> n >> m;
//     build(1,n,1);
//     while(m--){
//         int op;cin >> op;
//         if(op == 1){
//             int a;cin >> a;
//             int ans = search(a,1);
//             cout << ans << "\n";
//             if(ans == 0) continue;
//             update(ans,ans+a-1,1,1);
//         }else{
//             int a,b;
//             cin >> a >> b;
//             update(a,a+b-1,0,1);
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*hdu3397 Sequence operation*/
/*2025.3.21 题解*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+10;
struct{
    int pre1,suf1,len1,sum;
    int pre0,suf0,len0;
    int same,rev;
}tr[N<<2];
int a[N];
void push_up(int p,int len){
    tr[p].sum = tr[p<<1].sum + tr[p<<1|1].sum;
    tr[p].suf0 = tr[p<<1].suf0;tr[p].suf1 = tr[p<<1].suf1;
    tr[p].pre0 = tr[p<<1|1].pre0;tr[p].pre1 = tr[p<<1|1].pre1;
    if(tr[p<<1].suf0 == len-len/2) tr[p].suf0 += tr[p<<1|1].suf0;
    if(tr[p<<1].suf1 == len-len/2) tr[p].suf1 += tr[p<<1|1].suf1;
    if(tr[p<<1|1].pre0 == len/2) tr[p].pre0 += tr[p<<1].pre0;
    if(tr[p<<1|1].pre1 == len/2) tr[p].pre1 += tr[p<<1].pre1;
    tr[p].len0 = max(max(tr[p<<1].len0,tr[p<<1|1].len0),tr[p<<1].pre0+tr[p<<1|1].suf0);
    tr[p].len1 = max(max(tr[p<<1].len1,tr[p<<1|1].len1),tr[p<<1].pre1+tr[p<<1|1].suf1);
}
void swa(int len,int p){
    tr[p].sum = len - tr[p].sum;
    swap(tr[p].pre0,tr[p].pre1);
    swap(tr[p].suf0,tr[p].suf1);    
    swap(tr[p].len0,tr[p].len1);
}

void push_down(int p,int pl,int pr){
    int mid = (pl + pr) >> 1;
    if(tr[p].same != -1){
        tr[p<<1].rev = tr[p<<1|1].rev = 0;
        tr[p<<1].same  = tr[p<<1|1].same = tr[p].same;
        if(tr[p].same){
            tr[]
        }
    }
}

void build(int p,int pl,int pr){
    tr[p].clear();
    if(pl == pr){
        tr[p].len = tr[p].suf = tr[p].pre = tr[p].num = a[pl];
        tr[p].pre0 = tr[p].suf0 = tr[p].num0 = tr[p].len0 = 1^a[pl];
        return;
    }
    int mid = (pl + pr) >> 1;
    build(p<<1,pl,mid);
    build(p<<1|1,mid+1,pr);
    push_up(p,pr-pl+1);
}
void addtag(int p,int len){
    if(tr[p].add3){
        swap(tr[p].add1,tr[p].add2);
        swap(tr[p].len,tr[p].len0);
        swap(tr[p].num,tr[p].num0);
        swap(tr[p].pre0,tr[p].pre);
        swap(tr[p].suf0,tr[p].suf);
    }
    if(tr[p].add1){
        tr[p].num = tr[p].len = tr[p].pre = tr[p].suf = 0;
        tr[p].num0 = tr[p].len0 = tr[p].pre0 = tr[p].suf0 = len;
    }
    if(tr[p].add2){
        tr[p].num = tr[p].len = tr[p].pre = tr[p].suf = len;
        tr[p].num0 = tr[p].len0 = tr[p].pre0 = tr[p].suf0 = 0;
    }
}
void push_down(int p,int pl,int pr){
    
}
void update(int l,int r,int d,int p,int pl,int pr){
    if(l <= pl && r >= pr){
        if(d == 3) tr[p].add3^=1,swap(tr[p].add1,tr[p].add2);
        if(d == 1) tr[p].clear(),tr[p].add1 = 1;
        if(d == 2) tr[p].clear(),tr[p].add2 = 1;
        addtag(p,pr-pl+1);
        return;
    }
    push_down(p,pl,pr);
    int mid = (pl + pr) >> 1;
    if(l <= mid) update(l,r,d,p<<1,pl,mid);
    if(r >= mid+1) update(l,r,d,p<<1|1,mid+1,pr);
    push_up(p,pr-pl+1);
}
int query_num(int l,int r,int p,int pl,int pr){
    if(l <= pl && r >= pr){
        return tr[p].num;
    }
    int ans = 0;
    push_down(p,pl,pr);
    int mid = (pl + pr) >> 1;
    if(l <= mid) ans += query_num(l,r,p<<1,pl,mid);
    if(r >= mid + 1) ans += query_num(l,r,p<<1|1,mid+1,pr);
    return ans;
}
int query_len(int l,int r,int p,int pl,int pr){
    if(l <= pl && r >= pr){
        return tr[p].len;
    }
    int ans = 0;
    push_down(p,pl,pr);
    int mid = (pl + pr) >> 1;
    if(l <= mid) ans = max(ans,query_len(l,r,p<<1,pl,mid));
    if(r >= mid + 1) ans = max(ans,query_len(l,r,p<<1|1,mid+1,pr));
    return ans;
}
void solve(){
    int n,m;cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1,1,n);
    for(int i = 1; i <= m; i++){
        int op,l,r;cin >> op >> l >> r;
        l++,r++;
        if(op == 0){
            update(l,r,1,1,1,n);
        }else if(op == 1){
            update(l,r,2,1,1,n);
        }else if(op == 2){
            update(l,r,3,1,1,n);
        }else if(op == 3){
            cout << query_num(l,r,1,1,n) << "\n";
        }else if(op == 4){
            cout << query_len(l,r,1,1,n) << "\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;cin >> t;
    while(t--){
        solve();
    }
}
/*2025.3.20 WA*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// struct{
//     int pre,suf,len,num,add1,add2,add3; //记录1
//     int pre0,suf0,len0,num0;
//     void clear(){add1 = add2 = add3 = 0;};
// }tr[N<<2];
// int a[N];
// void push_up(int p,int len){
//     tr[p].pre = tr[p<<1].pre;
//     tr[p].suf = tr[p<<1|1].suf;
//     tr[p].pre0 = tr[p<<1].pre0;
//     tr[p].suf0 = tr[p<<1|1].suf0;
//     if(tr[p].pre == len - len/2){
//         tr[p].pre += tr[p<<1|1].pre;
//     }
//     if(tr[p].suf == len/2){
//         tr[p].suf += tr[p<<1].suf;
//     }
//     if(tr[p].pre0 == len - len/2){
//         tr[p].pre0 += tr[p<<1|1].pre0;
//     }
//     if(tr[p].suf0 == len/2){
//         tr[p].suf0 += tr[p<<1].suf0;
//     }
//     tr[p].num = tr[p<<1].num + tr[p<<1|1].num;
//     tr[p].num0 = tr[p<<1].num0 + tr[p<<1|1].num0;
//     tr[p].len = max(max(tr[p<<1].len,tr[p<<1|1].len),tr[p<<1].suf+tr[p<<1|1].pre);
//     tr[p].len0 = max(max(tr[p<<1].len0,tr[p<<1|1].len0),tr[p<<1].suf0+tr[p<<1|1].pre0);
// }
// void build(int p,int pl,int pr){
//     tr[p].clear();
//     if(pl == pr){
//         tr[p].len = tr[p].suf = tr[p].pre = tr[p].num = a[pl];
//         tr[p].pre0 = tr[p].suf0 = tr[p].num0 = tr[p].len0 = 1^a[pl];
//         return;
//     }
//     int mid = (pl + pr) >> 1;
//     build(p<<1,pl,mid);
//     build(p<<1|1,mid+1,pr);
//     push_up(p,pr-pl+1);
// }
// void addtag(int p,int len){
//     if(tr[p].add3){
//         swap(tr[p].add1,tr[p].add2);
//         swap(tr[p].len,tr[p].len0);
//         swap(tr[p].num,tr[p].num0);
//         swap(tr[p].pre0,tr[p].pre);
//         swap(tr[p].suf0,tr[p].suf);
//     }
//     if(tr[p].add1){
//         tr[p].num = tr[p].len = tr[p].pre = tr[p].suf = 0;
//         tr[p].num0 = tr[p].len0 = tr[p].pre0 = tr[p].suf0 = len;
//     }
//     if(tr[p].add2){
//         tr[p].num = tr[p].len = tr[p].pre = tr[p].suf = len;
//         tr[p].num0 = tr[p].len0 = tr[p].pre0 = tr[p].suf0 = 0;
//     }
// }
// void push_down(int p,int pl,int pr){
//     if(tr[p].add1){
//         tr[p<<1].clear(),tr[p<<1|1].clear();
//         tr[p<<1].add1 = tr[p<<1|1].add1 = tr[p].add1;
//     }
//     if(tr[p].add2){
//         tr[p<<1].clear(),tr[p<<1|1].clear();
//         tr[p<<1].add2 = tr[p<<1|1].add1 = tr[p].add2;
//     }
//     if(tr[p].add3){
//         if(tr[p<<1].add1 || tr[p<<1].add2){
//              swap(tr[p<<1].add1,tr[p<<1].add2);
//         }else{
//             tr[p<<1].add3 ^= 1;
//         }
//         if(tr[p<<1|1].add1 || tr[p<<1|1].add2){
//             swap(tr[p<<1|1].add1,tr[p<<1|1].add2);
//         }else{
//             tr[p<<1|1].add3 ^= 1;
//         }
//     }
//     int mid = (pl + pr) >> 1;
//     addtag(p<<1,mid - pl + 1);
//     addtag(p<<1|1,pr - mid);
//     tr[p].clear();
// }
// void update(int l,int r,int d,int p,int pl,int pr){
//     if(l <= pl && r >= pr){
//         if(d == 3) tr[p].add3^=1,swap(tr[p].add1,tr[p].add2);
//         if(d == 1) tr[p].clear(),tr[p].add1 = 1;
//         if(d == 2) tr[p].clear(),tr[p].add2 = 1;
//         addtag(p,pr-pl+1);
//         return;
//     }
//     push_down(p,pl,pr);
//     int mid = (pl + pr) >> 1;
//     if(l <= mid) update(l,r,d,p<<1,pl,mid);
//     if(r >= mid+1) update(l,r,d,p<<1|1,mid+1,pr);
//     push_up(p,pr-pl+1);
// }
// int query_num(int l,int r,int p,int pl,int pr){
//     if(l <= pl && r >= pr){
//         return tr[p].num;
//     }
//     int ans = 0;
//     push_down(p,pl,pr);
//     int mid = (pl + pr) >> 1;
//     if(l <= mid) ans += query_num(l,r,p<<1,pl,mid);
//     if(r >= mid + 1) ans += query_num(l,r,p<<1|1,mid+1,pr);
//     return ans;
// }
// int query_len(int l,int r,int p,int pl,int pr){
//     if(l <= pl && r >= pr){
//         return tr[p].len;
//     }
//     int ans = 0;
//     push_down(p,pl,pr);
//     int mid = (pl + pr) >> 1;
//     if(l <= mid) ans = max(ans,query_len(l,r,p<<1,pl,mid));
//     if(r >= mid + 1) ans = max(ans,query_len(l,r,p<<1|1,mid+1,pr));
//     return ans;
// }
// void solve(){
//     int n,m;cin >> n >> m;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
//     build(1,1,n);
//     for(int i = 1; i <= m; i++){
//         int op,l,r;cin >> op >> l >> r;
//         l++,r++;
//         if(op == 0){
//             update(l,r,1,1,1,n);
//         }else if(op == 1){
//             update(l,r,2,1,1,n);
//         }else if(op == 2){
//             update(l,r,3,1,1,n);
//         }else if(op == 3){
//             cout << query_num(l,r,1,1,n) << "\n";
//         }else if(op == 4){
//             cout << query_len(l,r,1,1,n) << "\n";
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

///* 综合练习 *///

/*hdu4578 Transformation*/ //很复杂，建议更熟悉线段树再写

/*hdu4027 Can you answer these queries?*/ //懒标记做特殊用
/*2025.3.7*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define int long long
// const int N = 1e5 + 10;
// ll tree[N << 2];ll a[N];
// int n,m;
// int ls(int p){return p << 1;}
// int rs(int p){return p << 1 | 1;}
// void push_up(int p){
//     ////cout << "bug5\n";
//     tree[p] = tree[ls(p)] + tree[rs(p)];
// }
// void bulid(int p,int pl,int pr){
//     ////cout << "bug4\n";
//     if(pl == pr) {tree[p] = a[pl]; return;}
//     int mid = (pl + pr) >> 1;
//     bulid(ls(p),pl,mid);
//     bulid(rs(p),mid+1,pr);
//     push_up(p);
// }
// ll query(int l,int r,int p,int pl,int pr){
//     ////cout << "bug1\n";
//     if(l <= pl && r >= pr) return tree[p];
//     ll ans = 0;
//     int mid = (pl + pr) >> 1;
//     if(l <= mid) ans += query(l,r,ls(p),pl,mid);
//     if(r >= mid+1) ans += query(l,r,rs(p),mid + 1,pr);
//     return ans;
// }
// void update(int l,int r,int p,int pl,int pr){
//     ////cout << "bug2\n";
//     if(query(pl,pr,p,pl,pr) == pr - pl + 1) return;
//     if(pl == pr){tree[p] = sqrt(tree[p]); return;}
//     int mid = (pl + pr) >> 1;
//     if(l <= mid) update(l,r,ls(p),pl,mid);
//     if(r >= mid+1) update(l,r,rs(p),mid+1,pr);
//     push_up(p);
// }
// void solve(){
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     bulid(1,1,n);
//     cin >> m;
//     while(m--){
//         int op,x,y;cin >> op >> x >> y;
//         int l = min(x,y);
//             int r = max(x,y);
//         if(op == 0){
//             update(l,r,1,1,n);
//         }else{
//             cout << query(l,r,1,1,n) << "\n";
//         }
//     }
// }
// signed main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(cin >> n){
//         cout << "Case #"<< t <<":\n";
//         t++; 
//         solve();
//     }
// }
/*2024.10.17*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5 + 10;
// ll tree[N << 2];
// ll a[N];
// int n;
// ll ls(ll p){return p << 1;};
// ll rs(ll p){return p << 1 | 1;};
// void push_up(ll p){
//     tree[p] = tree[ls(p)] + tree[rs(p)];
// }
// void build(ll p,ll pl,ll pr){
//     if(pl == pr){
//         tree[p] = a[pl];
//         return;
//     }
//     ll mid = (pl + pr) >> 1;
//     build(ls(p),pl,mid);
//     build(rs(p),mid+1,pr);
//     push_up(p);
// }
// ll query(ll L,ll R,ll p,ll pl,ll pr){
//     if(L <= pl && pr <= R){
//         return tree[p];
//     }
//     ll res = 0;
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) res += query(L,R,ls(p),pl,mid);
//     if(R > mid) res += query(L,R,rs(p),mid+1,pr);
//     return res;
// }
// void update(ll L,ll R,ll p,ll pl,ll pr){
//     if(query(pl,pr,p,pl,pr) == pr - pl + 1){
//         return;
//     }
//     if(pl == pr){
//         tree[p] = sqrt(tree[p]);
//         return;
//     }
//     ll mid = (pl + pr) >> 1;
//     if(L <= mid) update(L,R,ls(p),pl,mid);
//     if(R > mid) update(L,R,rs(p),mid+1,pr);
//     push_up(p);
// }
// void solve(){
//     for(int i = 1; i<= n; i++) cin >> a[i];
//     int m;cin >> m;
//     build(1,1,n);
//     while(m--){
//         int ch;cin >> ch;
//         if(ch == 0){ //改区间
//             ll l,r;cin >> l >> r;
//             ll x = min(l,r);
//             ll y = max(l,r);
//             update(x,y,1,1,n);
//         }
//         else{
//              ll l,r;cin >> l >> r;
//             ll x = min(l,r);
//             ll y = max(l,r);
//             cout << query(x,y,1,1,n) << "\n";
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     int len = 0;
//     while(cin >> n){
//        len++;
//        cout << "Case #" << len << ":\n";
//        solve();
//     }
// }


