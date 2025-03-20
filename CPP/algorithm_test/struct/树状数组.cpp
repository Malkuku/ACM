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


///*区间问题*///

/*板子 tree[]维护与lowbit*/ //单点修改，区间搜索
/*2024.9.19*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1000;
// int lowbit(int x){
//     return ((x) & (-x));
// }
// int tree[N] = {0};
// //单点修改，a[x] = a[x] + d;
// void update(int x,int d){
//     while(x <= N){
//         tree[x] += d;
//         x += lowbit(x); //在最后的二进制位1的位置+1
//     }
// }
// //查询前缀和
// int sum(int x){
//     int ans = 0;
//     while(x > 0){
//         ans += tree[x];
//         x -= lowbit(x); //去掉二进制最后一位1
//     }
//     return ans;
// }
// //以上是树状数组
// int a[11] = {0,4,5,6,7,8,9,10,11,12,13};
// int main(){
//     for(int i = 1; i <= 10; i++) update(i,a[i]);
//     cout << "old: [5,8]=" << sum(8) - sum(4) << endl;
//     update(7,100);
//     cout << "new: [5,8]=" << sum(8) - sum(4) << endl;
//     return 0;   
// }

/*hdu1556 Color the ball 板子 差分数组*/ //区间修改，单点搜索
/*2025.3.1*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int lowbit(int x){
//     return x & (-x);
// }
// const int N = 1e5+10;
// int tree[N];
// int n;
// void update(int x,int d){
//     while(x < N){
//         tree[x] += d;
//         x += lowbit(x);
//     }
// }
// int sum(int x){
//     int ans = 0;
//     while(x > 0){
//         ans += tree[x];
//         x -= lowbit(x);
//     }
//     return ans;
// }
// void solve(){
//     while(1){
//          cin >> n;if(n == 0) return;
//         memset(tree,0,sizeof tree);
//         for(int i = 0; i < n; i++){
//             int a,b; cin >> a >> b;
//             update(a,1);
//             update(b+1,-1);
//         }
//         for(int i = 1; i <= n; i++){
//             cout << sum(i) << " ";
//         }cout << "\n";
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
/*2024.9.19*/
// //差分数组 d[k] -> a[k] = d[1] + d[2] + ... + d[k] 
// //差分为前缀和的逆
// //所以用tree[]维护d[]
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// int tree[N] = { 0 };
// int lowbit(int x){
//     return ((x) & (-x));
// }
// void update(int x,int d){
//     while(x < N){
//         tree[x] += d;
//         x += lowbit(x);
//     }
// }
// int sum(int x){
//     int ans = 0;
//     while(x > 0){
//         ans += tree[x];
//         x -= lowbit(x);
//     }
//     return ans;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     int n;
//     do{
//         cin >> n;
//         memset(tree,0,sizeof tree);
//         for(int i = 0; i < n; i++){
//             int l,r;cin >> l >> r;
//             update(l,1);
//             update(r+1,-1);
//         }
//         for(int i = 1; i <= n; i++){
//             cout << sum(i) << " "; 
//         }cout << "\n";
//     }while(n);
//     return 0;
// }

/*P3372 【模板】线段树 1 二阶树状数组*/ //区间修改+区间搜索
/*2024.9.19 题解*/
// //sum[k] = k*d[1...k] - d*(i-1)[1...k]
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// ll lowbit(ll x){
//     return (x & (-x));
// }
// ll tree1[N],tree2[N];//d与（i-1）d
// void update(ll tree[],ll x,ll d){
//     while(x < N){
//         tree[x] += d;
//         x += lowbit(x);
//     }
// }
// ll sum(ll tree[],ll x){
//     ll ans = 0;
//     while(x > 0){
//         ans += tree[x];
//         x -= lowbit(x);
//     }
//     return ans;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     int n,m;cin >> n >> m;
//     int old = 0;
//     for(int i = 1; i <= n; i++){
//         int x;cin >> x;
//         update(tree1,i,x-old);
//         update(tree2,i,(i-1)*(x-old));
//         old = x;
//     }
//     while(m--){
//         int op,x,y,k;cin >> op;
//         if(op == 1){
//             cin >> x >> y >> k;
//             update(tree1,x,k);
//             update(tree1,y+1,-k);
//             update(tree2,x,(x-1)*k);
//             update(tree2,y+1,y*-k);
//         }
//         else if(op == 2){
//             cin >> x >> y;
//             ll d1 = y*sum(tree1,y) - (x-1)*sum(tree1,x-1);
//             ll d2 = sum(tree2,y) - sum(tree2,x-1);
//             cout << d1 - d2 << "\n";
//         }
//     }
//     return 0;
// }

/*P4514 上帝造题的七分钟 */ //二维区间修改+区间搜索
/*2024.9.19 题解*/ //脑瓜嗡嗡
// //d[i][j] = (i,j-1) + (i-1,j) - (i-1,j-1)
// //a[c][d] = E(c)E(d)d[i][j]
// //(a,b) -> (c,d)
// //sum = E(c)E(d)a[i][j] - E(a)E(d)a[i][j] - E(c)(b)a[i][j] + E(a)E(b)a[i][j];
// //设 E(n,i)E(m,j)E(i,k)E(i,p)d[k][p] = D
// //原式 = (n-i+1)*(m-j+1)D
// //      = (n+1)*(m+1)*D - (m+1)*[D*i] - (n+1)*[D*j] + [D*i*j]
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2050;
// int tree1[N][N],tree2[N][N],tree3[N][N],tree4[N][N];
// int lowbit(int x){
//     return (x & (-x));
// }
// int n,m;
// void update(int x,int y,int d){
//     for(int i = x; i <= n; i += lowbit(i)){
//         for(int j = y; j <= m; j += lowbit(j)){
//             tree1[i][j] += d;
//             tree2[i][j] += x*d;
//             tree3[i][j] += y*d;
//             tree4[i][j] += x*y*d;
//         }
//     }
// }
// int sum(int x,int y){
//     int ans = 0;
//     for(int i = x; i > 0; i -= lowbit(i)){
//         for(int j = y; j > 0; j -= lowbit(j)){
//             ans += 
//             (x+1)*(y+1)*tree1[i][j] - (y+1)*tree2[i][j]
//             -(x+1)*tree3[i][j] + tree4[i][j]; 
//         }
//     }
//     return ans;
//
// int main(){
//     ios::sync_with_stdio(0);
//     char ch;
//     cin >> ch >> n >> m;
//     while(cin >> ch){
//         int a,b,c,d,delta;
//         if(ch == 'L'){
//             cin >> a >> b >> c >> d >> delta;
//             update(a,b,delta);
//             update(a,d+1,-delta);
//             update(c+1,b,-delta);
//             update(c+1,d+1,delta);
//         }
//         else if(ch == 'k'){
//             cin >> a >> b >> c >> d;
//             cout << sum(c,d) - sum(a-1,d) - sum(c,b-1) + sum(a-1,b-1) << '\n';
//         }
//     }
//     return 0;
// }

/*hdu 1754 I hate it*/ //单点修改，区间最值
/*2024.9.20 题解*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+5;
// const int M = 5005;
// int tree[N], a[N];
// int lowbit(int x){
//     return x & (-x);
// }
// void update(int x,int d){
//     while(x < N){
//         tree[x] = d;
//         //遍历子树,以子节点更新自己
//         for(int i = 1; i < lowbit(x); i<<=1){
//             tree[x] = max(tree[x],tree[x-i]);
//         }
//          x += lowbit(x);
//     }
// }
// int query(int L,int R){
//     int ans = 0;
//     while(L <= R){
//         //1.R-L >= lowbit(R)
//         while(R-L >= lowbit(R)){
//             ans = max(ans,tree[R]);
//             R -= lowbit(R);
//         }
//         //2.R-L < lowbit(R)
//         ans = max(ans,a[R]);
//         R--;
//     }
//     return ans;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     int n,m;
//     while(cin >> n >> m){
//         memset(tree,0,sizeof tree);
//         for(int i = 1; i <= n; i++){
//             cin >> a[i];
//             update(i,a[i]);
//         }
//         while(m--){
//             char ch;int x,y;cin >> ch >> x >> y;
//             if(ch == 'Q'){
//                 cout << query(x,y) << "\n";
//             }
//             else if(ch == 'U'){
//                 a[x] = y;
//                 update(x,a[x]);
//             }
//         }
//     }
//     return 0;
// }

/*hdu 4630 No Pain No Game*/ //离线处理区间最值
/*2025.3.1*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 5e4+10;
// int tree[N];
// struct Node{
//     int l,r,pos;
// }node[N];
// int a[N];
// int pre[N];
// int ans[N];
// int n;
// int lowbit(int x){
//     return x & (-x);
// }
// void update(int x,int d){
//     while(x <= n){
//         tree[x] = max(tree[x],d);
//         x += lowbit(x);
//     }
// }
// int query(int x){
//     int ans = 0;
//     while(x > 0){
//         ans = max(tree[x],ans);
//         x -= lowbit(x);
//     }
//     return ans;
// }
// void solve(){
//     cin >> n;
//     memset(tree,0,sizeof tree);
//     memset(pre,0,sizeof pre);
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     int q;cin >> q;
//     for(int i = 1; i <= q; i++){
//         int l,r;cin >> l >> r;
//         node[i] = {l,r,i};
//     }
//     sort(node+1,node+1+q,[](auto x,auto y){
//         return x.l > y.l;
//     });
//     int cnt = 1;
//     for(int i = n; i >= 1; i--){
//         if(cnt > q) break;
//         for(int j = 1; j <= a[i]/j; j++){
//             if(a[i] % j) continue;
//             if(pre[j]){
//                 update(pre[j],j);
//             }
//             pre[j] = i;
//             if(j*j == a[i]) continue;
//             if(pre[a[i]/j]){
//                 update(pre[a[i]/j],a[i]/j);
//             }
//             pre[a[i]/j] = i;
//         }
//         while(cnt <= q && node[cnt].l == i){
//             ans[node[cnt].pos] = query(node[cnt].r);
//             cnt++;
//         }
//     }
//     for(int i = 1; i <= q; i++){
//         cout << ans[i] << "\n";
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
/*2024.9.20 题解*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 5e4+5;
// int n;
// struct{
//     int l,r,pos;
// }q[N];
// int tree[N],pre[N],a[N],ans[N];
// int gcd(int a,int b){
//     return b ? gcd(b,a%b) : a;
// }
// int lowbit(int x){
//     return x & (-x);
// }
// void update(int x,int d){
//     while(x > 0){
//         tree[x] = max(d,tree[x]);
//         x -= lowbit(x);
//     }
// }
// int query(int x){ //因为用了r更新，所以求和向前找
//     int ans = 0;
//      while(x <= n){
//         ans = max(ans,tree[x]);
//         x += lowbit(x);
//     }
//     return ans;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     while(t--){
//         memset(tree,0,sizeof tree);
//         memset(pre,0,sizeof pre);
//         cin >> n;
//         for(int i = 1;i <= n; i++){
//             cin >> a[i];
//         }
//         int qa;cin >> qa;
//         for(int i = 1; i <= qa; i++){
//             int l,r;cin >> l >> r;
//             q[i] = {l,r,i};
//         }
//         sort(q+1,q+1+qa,[](auto x,auto y){
//             return x.r < y.r;
//         });
//         int cnt = 1;
//         for(int i = 1; i <= n; i++){
//             if(cnt > qa)break;
//             for(int j = 1; j <= a[i] / j; j++){ //分解因数，因数已经出现过则说明是是两个数的公因数
//                 if(a[i] % j) continue;
//                 if(pre[j]){
//                     update(pre[j],j);
//                 }
//                 pre[j] = i;
//                 if(a[i] / j == j) continue;
//                 if(pre[a[i]/j]){
//                     update(pre[a[i]/j],a[i]/j);
//                 }
//                 pre[a[i]/j] = i;
//             }
//             while(q[cnt].r == i && cnt <= qa){ //到询问的位置
//                 ans[q[cnt].pos] = query(q[cnt].l);
//                 //cout << ans[q[cnt].pos] << "\n";
//                 cnt++;
//             }
//         }
//         for(int i = 1; i <= qa; i++) cout << ans[i] << "\n";
//     }
//     return 0;
// }


///*偏序问题*///

/* P1908 逆序对 */ //将数字作为tree[]下标，需要离散化
/*2024.9.20*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 500010;
// int tree[N];int ra[N];
// int lowbit(int x){
//     return x &(-x);
// }
// void update(int x,int d){
//     while(x < N){
//         tree[x] += d;
//         x += lowbit(x);
//     }
// }
// ll sum(int x){
//     ll ans = 0;
//     while(x > 0){
//         ans += tree[x];
//         x -= lowbit(x);
//     }
//     return ans;
// }
// struct node
// {
//     int value,num;
// }a[N];
// int main(){
//     ios::sync_with_stdio(0);
//     int n;cin >> n;
//     for(int i = 1;i <= n; i++){
//         cin >> a[i].value;
//         a[i].num = i;
//     }
//     sort(a+1,a+1+n,[](auto x,auto y){
//         if(x.value == y.value) return x.num < y.num;
//         return x.value < y.value;
//     });
//     ll ans = 0;
//     for(int i = 1; i <= n; i++) ra[a[i].num] = i; //离散化
//     for(int i = n; i > 0; i--){ //倒叙
//         update(ra[i],1);
//         ans += sum(ra[i]-1);
//     }
//     // for(int i = 1; i <= n; i++){ //正序
//     //     update(ra[i],1);
//     //     ans += i - sum(ra[i]);
//     // }
//     cout << ans << "\n";
//     return 0;
// }

///*综合练习*///

//题单 hdu4456 
// P3586 P3960

/*P4113 [HEOI2012] 采花*/
/*2025.3.7*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e6+10;
// ll tree[N];int a[N];int n,c,m;
// void update(int x,int d){
//     for(int i = x; i <= n; i += i & -i){
//         tree[i] += d;
//     }
// }
// ll sum(int x){
//     ll ans = 0;
//     for(int i = x; i > 0; i -= i & -i){
//         ans += tree[i];
//     }
//     return ans;
// }
// struct Node{
//     int l,r,pos;
// }node[N]; ll ans[N];
// struct {
//     int pos,cnt,pre;
// }st[N];
// void solve(){
//     cin >> n >> c >> m;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     for(int i = 1; i <= m; i++){
//         int l,r;cin >> l >> r;
//         node[i] = {l,r,i};
//     } 
//     sort(node+1,node+1+m,[](auto x,auto y){
//         return x.r < y.r;
//     });
//     int cnt = 1;
//     for(int i = 1; i <= n; i++){
//         if(st[a[i]].pos < i){
//             if(st[a[i]].cnt >= 2){
//                 update(st[a[i]].pre,-1);
//                 update(st[a[i]].pos,1);
//             }else if(st[a[i]].cnt >= 1){
//                 update(st[a[i]].pos,1);
//             }
//             st[a[i]].pre = st[a[i]].pos;
//             st[a[i]].pos = i;
//             st[a[i]].cnt++;
//         }
//         while(cnt <= m && node[cnt].r == i){
//             ans[node[cnt].pos] = sum(node[cnt].r) - sum(node[cnt].l-1);
//             cnt++;
//         }
//     }
//     for(int i = 1; i <= m; i++){
//         cout << ans[i] << "\n";
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

/*P4054 [JSOI2009] 计数问题*/
/*2025.3.7*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll tree[310][310][100];int n,m;
// void update(int x,int y,int c,int d){
//     for(int i = x; i <= n; i += i & -i){
//         for(int j = y; j <= m; j += j & -j){
//             tree[i][j][c] += d;
//         }
//     }
// }
// ll sum(int x,int y,int c){
//     ll ans = 0;
//     for(int i = x; i > 0; i-= i&-i){
//         for(int j = y; j > 0; j-=j&-j){
//             ans += tree[i][j][c];
//         }
//     }
//     return ans;
// }
// int mp[310][310];
// void solve(){
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= m; j++){
//             cin >> mp[i][j];
//             update(i,j,mp[i][j],1);
//         }
//     }
//     int q;cin >> q;
//     while(q--){
//         int op;cin >> op;
//         if(op == 1){
//             int x,y,c;cin >> x >> y >> c;
//             update(x,y,mp[x][y],-1);
//             mp[x][y] = c;
//             update(x,y,mp[x][y],1);
//         }else{
//             int x1,x2,y1,y2,c;cin >> x1 >> x2 >> y1 >> y2 >> c;
//             cout << sum(x2,y2,c) - sum(x1-1,y2,c) - sum(x2,y1-1,c) + sum(x1-1,y1-1,c) << "\n";
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

/*P1972 [SDOI2009] HH的项链*/
/*2025.3.7*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e6+10;
// ll tree[N];int a[N];int n,m;
// void update(int x,int d){
//     for(int i = x; i <= n; i += i & -i){
//         tree[i] += d;
//     }
// }
// ll sum(int x){
//     ll ans = 0;
//     for(int i = x; i > 0; i -= i & -i){
//         ans += tree[i];
//     }
//     return ans;
// }
// struct Node{
//     int l,r,pos;
// }node[N]; ll ans[N];
// int st[N];
// void solve(){
//     cin >> n;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     cin >> m;
//     for(int i = 1; i <= m; i++){
//         int l,r;cin >> l >> r;
//         node[i] = {l,r,i};
//     } 
//     sort(node+1,node+1+m,[](auto x,auto y){
//         return x.r < y.r;
//     });
//     int cnt = 1;
//     for(int i = 1; i <= n; i++){
//         if(st[a[i]] < i){
//             if(st[a[i]]){
//                 update(st[a[i]],-1);
//             }
//             update(i,1);
//             st[a[i]] = i;
//         }
//         while(cnt <= m && node[cnt].r == i){
//             ans[node[cnt].pos] = sum(node[cnt].r) - sum(node[cnt].l-1);
//             cnt++;
//         }
//     }
//     for(int i = 1; i <= m; i++){
//         cout << ans[i] << "\n";
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

/*P3605 [USACO17JAN] Promotion Counting P*/
/*2025.3.7 题解*/ //确实dfs，进之后（加入下属后比自己强的）-进之前（原来比自己强的）
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// int a[N],b[N];
// ll tree[N];
// int n;
// void update(int x,int d){
//     for(int i = x; i <= n; i += i & -i){
//         tree[i] += d;
//     }
// }
// ll sum(int x){
//     ll ans = 0;
//     for(int i = x; i > 0; i -= i & -i){
//         ans += tree[i];
//     }
//     return ans;
// }
// vector<int> vc[N];
// bool st[N];
// ll ans[N];
// void dfs(int fa){
//     st[fa] = 1;
//     ans[fa] -= sum(n) - sum(b[fa]); 
//     for(int i = 0; i < vc[fa].size(); i++){
//         int to = vc[fa][i];
//         if(st[to]) continue;
//         dfs(to);   
//     }
//     ans[fa] += sum(n) - sum(b[fa]);
//     update(b[fa],1);
// }
// void solve(){
//     cin >> n;
//     for(int i = 1; i <= n; i++) cin >> a[i],b[i] = a[i];
//     sort(a+1,a+1+n);
//     for(int i = 1; i <= n; i++) b[i] = lower_bound(a+1,a+1+n,b[i]) - a;
//     for(int i = 2; i <= n; i++){
//         int x;cin >> x;
//         vc[x].push_back(i);
//     }
//     dfs(1);
//     for(int i = 1;i <= n; i++){
//         cout << ans[i] << "\n";
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

/*P1966 [NOIP 2013 提高组] 火柴排队*/
/*2025.3.6*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// struct Node{
//     int x,pos;
// };
// void solve(){
//     int n;cin >> n;
//     vector<Node> a(n+1);
//     vector<Node> b(n+1);
//     for(int i = 1; i <= n; i++){
//         int x;cin >> x;
//         a[i] = {x,i};
//     }
//     for(int i = 1; i <= n; i++){
//         int x;cin >> x;
//         b[i] = {x,i};
//     }
//     sort(a.begin()+1,a.end(),[](auto a,auto b){
//         if(a.x != b.x) return a.x < b.x;
//         return a.pos < b.pos;
//     });
//     sort(b.begin()+1,b.end(),[](auto a,auto b){
//         if(a.x != b.x) return a.x < b.x;
//         return a.pos < b.pos;
//     });
//     for(int i = 1; i <= n; i++){
//         b[i].x = a[i].pos;
//     }
//     sort(b.begin()+1,b.end(),[](auto a,auto b){
//         return a.pos < b.pos;
//     });
//     vector<ll> tree(n+1);
//     const int mod = 1e8 - 3;
//     auto update = [&](int x,int d){
//         for(int i = x; i <= n; i+=i&-i){
//             tree[i] += d;
//         }
//     };
//     auto sum = [&](int x){
//         ll ans = 0;
//         for(int i = x; i > 0; i -= i& -i){
//             ans += tree[i];
//             ans %= mod;
//         }
//         return ans;
//     };
//     ll ans = 0;
//     for(int i = n; i >= 1; i--){
//         ans += sum(b[i].x);
//         ans %= mod;
//         update(b[i].x,1);
//     }
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*P4479 [BJWC2018] 第k大斜率*/
/*2025.3.6 题解 精 */ //二分答案+二维偏序对
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define int long long
// struct Node{
//     int x,y,pos;
// };
// void solve(){
//     int n,k;cin >> n >> k;
//     vector<Node> node(n+1);
//     for(int i = 1; i <= n; i++){
//         int x,y;cin >> x >> y;
//         node[i] = {x,y,i};
//     } 
//     sort(node.begin()+1,node.end(),[](auto a,auto b){
//             if(a.x != b.x) return a.x < b.x;
//             return a.y > b.y;
//     });
//     //二分斜率
//     ll l = -1e9,r = 1e9;
//     while(l + 1 < r){
//         ll mid = (l+r) >> 1;
//         //统计(y1-y2)/(x1-x2) > mid 的个数 -》 y1 - mid*x1 > y2 - mid*x2
//         //同时需要满足x1 > x2
//         auto check = [&](ll mid){
//             vector<ll> tree(n+1);
//             auto update = [&](int x,int d){
//                 for(int i = x; i <= n; i += i & -i){
//                     tree[i] += d;
//                 }
//             };
//             auto sum = [&](int x){
//                 ll ans = 0;
//                 for(int i = x; i > 0; i -= i & -i){
//                     ans += tree[i];
//                 }
//                 return ans;
//             };
//             vector<ll> b(n+1);
//             vector<ll> c(n+1);
//             for(int i = 1; i <= n; i++) c[i] = b[i] = node[i].y - mid*node[i].x;
//             sort(c.begin()+1,c.end());
//             c.erase(unique(c.begin(),c.end()),c.end());
//             for(int i = 1; i <= n; i++){
//                 b[i] = lower_bound(c.begin()+1,c.end(),b[i]) - c.begin();
//             }
//             ll cnt = 0;
//             for(int i = 1; i <= n; i++){
//                 cnt += sum(b[i]);
//                 update(b[i],1);
//             }
//             return cnt; 
//         };
//         if(check(mid) < k) r = mid;
//         else l = mid;
//     } 
//     cout << l << "\n";
// }
// signed main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*P1774 最接近神的人*/
/*2025.3.6*/ //逆序对
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     vector<ll> tree(n+1);
//     vector<pair<int,int>> a(n+1);
//     vector<int> arr(n+1);
//     for(int i = 1; i <= n; i++){
//         int x;cin >> x;
//         a[i] = {x,i};
//     }
//     sort(a.begin()+1,a.end(),[](auto x,auto y){
//         if(x.first != y.first) return x.first < y.first;
//         else return x.second < y.second;
//     });
//     for(int i = 1; i <= n; i++){
//         arr[a[i].second] = i;
//     }
//     auto update = [&](int x,int d){
//         for(int i = x; i <= n; i += i&-i){
//             tree[i] += d;
//         }
//     };
//     auto sum = [&](int x){
//         ll ans = 0;
//         for(int i = x; i > 0; i -= i & -i){
//             ans += tree[i];
//         }
//         return ans;
//     };
//     //for(int i = 1; i <= n; i++) cout << arr[i] << " ";
//     ll ans = 0;
//     for(int i = n; i >= 1; i--){
//         ans += sum(arr[i]);
//         update(arr[i],1);
//     }
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*P3368 【模板】树状数组 2*/
/*2025.3.6*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,m;cin >> n >> m;
//     vector<ll> tree(n+1);
//     vector<int> a(n+1);
//     auto update = [&](int x,int d){
//         for(int i = x; i <= n; i += i&-i){
//             tree[i] += d;
//         }
//     };
//     auto sum = [&](int x){
//         ll ans = 0;
//         for(int i = x; i > 0; i -= i&-i){
//             ans += tree[i];
//         }
//         return ans;
//     };
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//         update(i,a[i]);
//         update(i+1,-a[i]);
//     }
//     for(int i = 1; i <= m; i++){
//         int op;cin >> op;
//         if(op == 1){
//             int l,r,k;cin >> l >> r >> k;
//             update(l,k);update(r+1,-k);
//         }else{
//             int x;cin >> x;
//             cout << sum(x) << "\n";
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

/*P3374 【模板】树状数组 1*/
/*2025.3.6*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 5e5+10;
// void solve(){
//     int n,m;cin >> n >> m;
//     vector<ll> tree(n+1);
//     vector<int> a(n+1);
//     auto update = [&](int x,int d){
//         for(int i = x; i <= n; i+=i&-i){
//             tree[i] += d;
//         }
//     };
//     auto sum = [&](int x){
//         ll ans = 0;
//         for(int i = x;i > 0; i -= i&-i){
//             ans += tree[i];
//         }
//         return ans;
//     };
//     for(int i = 1;i <= n; i++){
//         cin >> a[i];
//         update(i,a[i]);
//     }
//     for(int i = 1; i <= m; i++){
//         int op,x,y;cin >> op >> x >> y;
//         if(op == 1){
//             update(x,y);
//         }else{
//             cout << sum(y) - sum(x-1) << "\n";
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

/*hdu 5057 Argestes and Sequence*/
/*2025.3.5 题解*/ //离线，把分10次，分别处理每一位
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int n,m;
// const int N = 1e5+10;
// struct Node{
//     int l,r,d,p,pos; 
// };
// struct Change{
//     int d;string s;int pos;
// };
// void solve(){
//     cin >> n >> m;
//     vector<string> a(n+1);
//     vector<int> ans(m+1);
//     vector<Node> node; //原位置，操作
//     vector<Change> change; 
//     auto add = [&](string s){
//         reverse(s.begin(),s.end());
//         while(s.size() < 10){
//             s += '0';
//         }
//         return s;
//     };
//     for(int i = 1; i <= n; i++){
//         string s;cin >> s;
//         a[i] = add(s);
//     }
//     for(int i = 1; i <= m; i++){
//         char ch;cin >> ch;
//         if(ch == 'Q'){
//             int l,r,d,p;cin >> l >> r >> d >> p;
//             node.push_back({l,r,d-1,p,i});
//         }else{
//             int pos;string s;cin >> pos >> s;
//             s = add(s);
//             change.push_back({pos,s,i});
//         }
//     } 
//     sort(node.begin(),node.end(),[&](auto x,auto y){
//         return x.d < y.d;
//     });
//     for(int i = 0; i <= 9; i++){
//         vector<vector<int>> tree(n+1, vector<int>(10));
//         auto sum = [&](int x,int num){
//             int ans = 0;
//             for(int i = x; i > 0; i-=i&-i){
//                 ans += tree[i][num];
//             }
//             return ans;
//         };
//         auto update = [&](int x,int num,int d){
//             for(int i = x; i <= n; i+=i&-i){
//                 //cout << "? " << i << " " << pos << " " << num << "\n";
//                 tree[i][num] += d;
//             }   
//             //cout << "bug1\n";
//         };
//         for(int j = 1; j <= n; j++){
//             update(j,a[j][i] - '0',1);
//             //cout << "?? " << a[j] << " " << a[j][i] << "\n";
//         } 
//         int cnt = 0;int res = 0;       
//         //for(int k = 0; k <= 9; k++){
//         //    for(int j = 1; j <= n; j++) {
//         //        cout << tree[j][k] << " ";
//         //    }cout << "\n";
//         //}
//         while(res < node.size() && i >= node[res].d){
//             if(i > node[res].d){
//                 res++;
//                 continue;
//             }
//             //cout << "? " << i << " " << res << "\n";
//             while(cnt < change.size() && node[res].pos > change[cnt].pos){
//                  //cout << "bug3\n";
//                 update(change[cnt].d,a[change[cnt].d][i] - '0',-1);
//                 update(change[cnt].d,change[cnt].s[i] - '0',1);
//                 cnt++;
//             }
//             //cout << "bug1\n";
//             //cout << res << "\n";
//             //cout << node[res].pos << "\n";
//             //cout << node[res].r << "\n";
//             //cout << node[res].p << "\n";
//             //cout << node[res].l << "\n";
//             ans[node[res].pos] = sum(node[res].r,node[res].p) - sum(node[res].l-1,node[res].p);
//             //cout << "? " << i << " "<< node[res].l << " " << node[res].r << " " << 
//                 //node[res].d << " " << node[res].p << "\n";
//             //cout << "? " << ans[node[res].pos] << "\n";
//             res++;
//             //cout << "bug2\n";
//         }
//     }
//     sort(node.begin(),node.end(),[](auto x,auto y){
//         return x.pos < y.pos;
//     });
//     for(int i = 0; i < node.size(); i++){
//         cout << ans[node[i].pos] << '\n';
//     }
// }
// int main(){
//     //ios::sync_with_stdio(0);
//     //cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }
/*2025.3.5 题解 MLE*/ //在线做法，通过signed short 把 int 分块，天才！//没过，但思路还是天才的 
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int n,m;
// const int N = 1e5+10;
// void solve(){
//     cin >> n >> m;
//     vector<vector<vector<char>>> tree(n+1, vector<vector<char>>(10, vector<char>(10)));
//     vector<vector<vector<short>>> yu(n+1, vector<vector<short>>(10,vector<short>(10)));
//     int mod = (1 << 16) - 1;
//     auto sum = [&](int x,int pos,int num){
//         int ans = 0;
//         for(int i = x; i > 0; i-=i&-i){
//             ans += tree[i][pos][num]*mod + yu[i][pos][num];
//         }
//         return ans;
//     };
//     auto update = [&](int x,int pos,int num,int d){
//         for(int i = x; i <= n; i+=i&-i){
//             //cout << "? " << i << " " << pos << " " << num << "\n";
//             tree[i][pos][num] += d;
//             yu[i][pos][num] += d;
//             tree[i][pos][num] /= mod;
//             yu[i][pos][num] %= mod;
//         }   
//         //cout << "bug1\n";
//     };
//     vector<string> a(n+1);
//     auto add = [&](string s){
//         reverse(s.begin(),s.end());
//         while(s.size() < 10){
//             s += '0';
//         }
//         return s;
//     };
//     for(int i = 1; i <= n; i++){
//         string s;cin >> s;
//         a[i] = add(s);
//         for(int j = 0; j < a[i].size(); j++){
//             update(i,j,a[i][j]-'0',1);
//         }
//     }
//     for(int i = 1; i <= m; i++){
//         char ch;cin >> ch;
//         if(ch == 'Q'){
//             int l,r,d,p;cin >> l >> r >> d >> p;
//             cout << sum(r,d-1,p) - sum(l-1,d-1,p) << "\n";
//         }else{
//             int pos;string s;cin >> pos >> s;
//             s = add(s);
//             //cout << "? " << s << " " << a[pos] << "\n";
//             for(int j = 0; j < s.size(); j++){
//                 //cout << "?\n";
//                 //cout << s[j] - '0' << " " << a[pos][j] - '0' << " " << pos << "\n";
//                 if(s[j] != a[pos][j]){
//                     update(pos,j,s[j]-'0',1);
//                     update(pos,j,a[pos][j]-'0',-1);
//                 }
//             }
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

/*hdu 5869 Different GCD Subarray Query*/
/*2025.3.4 题解*/ //gcd 离线查区间 //处理是不断更新值向右靠 //一个值不断GCD最多有log（n）种
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// int tree[N];
// int a[N],ans[N];int n,m;
// struct Node{
//     int l,r,pos;
// }node[N];
// bool cmp(Node x,Node y){
//     if(x.r != y.r) return x.r < y.r;
//     return x.l > y.l;
// }
// void update(int x,int d){
//     for(int i = x; i > 0; i -= i & -i){
//         tree[i] += d;
//     }
// }
// int sum(int x){
//     int ans = 0;
//     for(int i = x; i <= n; i+= i & -i){
//         ans += tree[i];
//     }
//     return ans;
// }
// int book[N*10];
// void solve(){
//     cin >> m;
//     memset(tree,0,sizeof tree);
//     memset(book,0,sizeof book);
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     for(int i = 1; i <= m; i++){
//         int l,r;cin >> l >> r;
//         node[i] = {l,r,i};
//     }
//     sort(node+1,node+1+m,cmp);
//     int cnt = 1;
//     for(int i = 1; i <= n; i++){
//         if(cnt > m) break;
//         int x = a[i];
//         for(int j = i; j >= 1; j--){
//             if(book[x] < j){
//                 if(book[x]){
//                     update(book[x],-1);
//                 }
//                 book[x] = j;
//                 update(book[x],1);
//             }
//             if(x == 1 || j == 1) break;
//             x = __gcd(x,a[j-1]);
//         }
//         //for(int i = 1; i <= n; i++){
//         //    cout << tree[i] << " ";
//         //}cout << "\n";
//         while(cnt <= m && node[cnt].r == i){
//             ans[node[cnt].pos] = sum(node[cnt].l);
//             cnt++;
//         }
//     }
//     for(int i = 1; i <= m; i++){
//         cout << ans[i] << "\n";
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(cin >> n){
//         solve();
//     }
// }

/*hdu 1541 Stars*/
/*2025.3.3*/ //sb题目，有多组输入你不写？？？？？
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// const int N = 1e5+10;
// int n;int tree[N];
// struct {
//     int x,y,pos;
// }ax[N];
// int ans[N];
// void update(int x,int d){
//     for(int i = x; i < N; i += i & -i){
//         tree[i] += d;
//     }
// }
// int sum(int x){
//     int ans = 0;
//     for(int i = x; i > 0; i -= i & -i){
//         ans += tree[i];
//     }
//     return ans;
// }
// void solve(){
//     while(cin >> n){
//          memset(tree,0,sizeof tree);
//          memset(ans,0,sizeof ans);
//         for(int i = 1; i <= n; i++){
//             int x,y;cin >> x >> y;
//             x++,y++;
//             ax[i] = {x,y,i};
//         }
//         sort(ax+1,ax+1+n,[&](auto a,auto b){
//             if(a.x != b.x) return a.x < b.x;
//             return a.y < b.y;
//         });
//         for(int i = 1; i <= n; i++){
//             ans[sum(ax[i].pos)]++;
//             update(ax[i].pos,1);
//         }
//         for(int i = 0; i < n; i++){
//             cout << ans[i] << "\n";
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

/*poj 3368 Frequent values*/ // RMQ问题变体 -- 区间众数
/*2025.3.3 题解 精*/ 
// #include<iostream>
// #include<algorithm>
// #include<cstring>
// #include<map>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// int a[N];map<int,int> mp;
// int dp[N];
// int tree[N];
// struct Node{
//     int l,r,pos;
// }node[N];
// int n,m;int ans[N];
// bool cmp(Node x,Node y){
//     if(x.r != y.r) return x.r < y.r;
//     return x.l > y.l;
// }
// void update(int x,int d){
//     for(int i = x; i > 0; i -= i & -i){
//         tree[i] = max(tree[i],d);
//     }
// }
// int query(int x){
//     int ans = 0;
//     for(int i = x; i <= n; i += i & -i){
//         ans = max(tree[i],ans);
//     }
//     return ans;
// }
// void solve(){
//     cin >> m;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//         tree[i] = 0;
//     } 
//     mp.clear();
//     for(int i = 1; i <= m; i++){
//         int l,r;cin >> l >> r;
//         node[i] = {l,r,i};
//     }
//     sort(node+1,node+1+m,cmp);
//     int cnt = 1;
//     for(int i = 1; i <= n; i++){
//         mp[a[i]]++;
//         dp[i] = mp[a[i]];
//     }
//     for(int i = 1; i <= n; i++){
//         if(cnt > m) break;
//         //cout <<"! " << i << " " << maxn << "\n";
//         update(i,dp[i]);
//         while(cnt <= m && node[cnt].r == i){
//             int tmp = node[cnt].l;
//             int res = 0;
//             while(dp[tmp] != 1 && tmp <= node[cnt].r) tmp++,res++;
//             ans[node[cnt].pos] = max(res,query(tmp));
//            // cout << node[cnt].l << " " << node[cnt].r<< " " << res << " " << tmp << " " << query(tmp) << "\n";
//             cnt++;
//         }
//     }
//     for(int i = 1; i <= m; i++) cout << ans[i] << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(cin >> n && n){
//         solve();
//     }
// }

/*poj 3264 Balanced Lineup*/ //离线查区间最值
/*2025.3.3*/
// #include<iostream>
// #include<algorithm>
// #include<cstring>
// using namespace std;
// #define ll long long
// const int N = 2e5+10;
// int tree1[N],tree2[N];
// int n,m;
// struct Node{
//     int l,r,pos;
// }node[N];
// int a[N]; int ans[N];
// bool cmp(Node x,Node y){
//     if(x.r != y.r) return x.r < y.r;
//     return x.l > y.l;
// }
// int lowbit(int x){
//     return x & (-x);
// }
// void update(int x,int d,bool flag){ //0-min 1-max
//     for(int i = x; i > 0; i -= lowbit(i)){
//         if(flag) tree1[i] = max(tree1[i],d);
//         else tree2[i] = min(tree2[i],d);
//     }
// }
// int query(int x,bool flag){
//     if(flag){
//         int ans = 0;
//         for(int i = x; i <= n; i += lowbit(i)){
//             ans = max(ans,tree1[i]);
//         }
//         return ans;
//     }else{
//         int ans = 2e9;
//         for(int i = x; i <= n; i += lowbit(i)){
//             ans = min(ans,tree2[i]);
//         }
//         return ans;
//     }
// }
// void solve(){
//     memset(tree1,0,sizeof tree1);
//     memset(tree2,0x3f,sizeof tree2);
//     cin >> n >> m;
//     for(int i = 1;i <= n; i++) {
//         cin >> a[i];
//     }
//     for(int i = 1; i <= m; i++){
//         int l,r;cin >> l >> r;
//         node[i] = {l,r,i};
//     }
//     sort(node+1,node+1+m,cmp);
//     int cnt = 1;
//     for(int i = 1; i <= n; i++){
//         if(cnt > m) break;
//         update(i,a[i],0);
//         update(i,a[i],1);
//         while(cnt <= m && node[cnt].r == i){
//             ans[node[cnt].pos] = query(node[cnt].l,1) - query(node[cnt].l,0);
//             //cout << "? " << node[cnt].l << " " << node[cnt].r << " " << ans[node[cnt].pos] << "\n";
//             cnt++;
//         }
//     }
//     for(int i = 1; i <= m; i++) cout << ans[i] << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*poj 3321 Apple Tree*/
/*2025.3.2 题解 精 TLE*/ //dfs序+改单点，查区间 //vector[N] 导致了 TLE
// #include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <math.h>
// #include <vector>
// #include <queue>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// const int N = 1e5+10;
// //vector<int> node[N];
// typedef vector<int>q;
// vector<q>node(N);
// int lowbit(int x){
//     return x & (-x);
// }
// int tree[N];int n;PII ro[N];bool st[N];bool stt[N];int cnt = 0;
// void update(int x,int d){
//     for(int i = x; i <= n; i+=lowbit(i)){
//         tree[i] += d;
//     }
// }
// int sum(int x){
//     int ans = 0;
//     for(int i = x; i > 0; i -= lowbit(i)){
//         ans += tree[i];
//     }
//     return ans;
// }
// void dfs(int fa){
//     ro[fa].first = ++cnt;
//     st[fa] = 1;
//     for(int i = 0; i < node[fa].size(); i++){
//         int to = node[fa][i];
//         if(!st[to])  dfs(to);
//     }
//     ro[fa].second = cnt;
// }
// int main()
// {
//     while(scanf("%d",&n)==1)//m初始值
//     {
//         memset(st, 0, sizeof(st));
//         //memset(c, 0, sizeof(c));
//         for (int i = 0; i <= n; i++) node[i].clear();
//         for(int i = 1; i < n; i++)
//         {
//             int a,b;
//             scanf("%d%d", &a, &b);
//             node[a].push_back(b);
//             node[b].push_back(a);
//         }
//         for(int i = 1; i <= n; i ++)
//             update(i,1);
//         cnt = 0;
//         dfs(1);
//         int m;
//         scanf("%d",&m);
//         while(m--)
//         {
//             char ch;
//             int x;
//             scanf(" %c %d",&ch,&x);
//             if(ch=='C')
//             {
//                 if(stt[x])
//                 {
//                     update(ro[x].first, 1);
//                     stt[x] = false;
//                 }
//                 else
//                 {
//                     update(ro[x].first, -1);
//                     stt[x] = true;
//                 }
//             }
//             else
//             {
//                 printf("%d\n",sum(ro[x].second)-sum(ro[x].first-1));
//             }
//         }
//     }
//     return 0;
// }

/*poj 1195 Mobile phones*/ //二维 改单点，查区间
/*2025.3.2*/
// #include<iostream>
// using namespace std;
// #define ll long long
// int lowbit(int x){
//     return x & (-x);
// }
// const int N = 1050;
// int tree[N][N];int n;
// void update(int x,int y,int d){
//     for(int i = x; i <= n; i+=lowbit(i)){
//         for(int j = y; j <= n; j+=lowbit(j)){
//             tree[i][j] += d;
//         }
//     }
// }
// int sum(int x,int y){
//     int ans = 0;
//     for(int i = x; i > 0; i -= lowbit(i)){
//         for(int j = y; j > 0; j -= lowbit(j)){
//             ans += tree[i][j];
//         }
//     }
//     return ans;
// }
// void solve(){
//     while(1){
//         int op;cin >> op;
//         if(op == 0){
//             cin >> n;
//         }else if(op == 1){
//             int x,y,d;cin >> x >> y >> d;
//             update(x+1,y+1,d);
//         }else if(op == 2){
//             int l,b,r,t;cin >> l >> b >> r >> t;
//             l++,b++,r++,t++;
//             cout << sum(r,t) - sum(r,b-1) - sum(l-1,t) + sum(l-1,b-1) << "\n";
//         }else if(op == 3){
//             break;
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

/*poj 2481 Cows*/
/*2025.3.2*/ //基本上涉及区间都是离线处理
// #include<iostream>
// #include<algorithm>
// #include<cstring>
// using namespace std;
// #define ll long long
// int n;
// const int N = 1e5+10;
// int tree[N];
// int ans[N];
// struct Node{
//     int x,y,pos;
// }node[N];
// int lowbit(int x){
//     return x & (-x);
// }
// void update(int x,int d){
//     while(x < N){
//         tree[x] += d;
//         x += lowbit(x);
//     }
// }
// int sum(int x){
//     int ans = 0;
//     while(x > 0){
//         ans += tree[x];
//         x -= lowbit(x);
//     }
//     return ans;
// }
// bool cmp(Node a,Node b){
//     if(a.y != b.y) return a.y > b.y;
//     return a.x < b.x;
// }
// void solve(){
//     memset(tree,0,sizeof tree);
//     for(int i = 1; i <= n; i++) {
//         int x,y;cin >> x >> y;
//         x++;y++;
//         node[i] = {x,y,i};
//     }
//     sort(node+1,node+1+n,cmp);
//     for(int i = 1; i <= n; i++){
//         if(node[i-1].x == node[i].x && node[i-1].y == node[i].y){
//             ans[node[i].pos] = ans[node[i-1].pos];
//         }
//         else ans[node[i].pos] = sum(node[i].x);
//         update(node[i].x,1);
//     }
//     for(int i = 1;i <= n; i++) cout << ans[i] << " ";
//     cout << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t){
//         cin >> n;
//         if(!n) break;
//         solve();
//     }
// }

/*poj 2299 Ultra-QuickSort*/ //快排计数 -- 逆序对
/*2025.3.2*/
// #include<iostream>
// #include<algorithm>
// using namespace std;
// #define ll long long
// const int N  =5e5+10;
// int n;
// void solve(){
//     vector<pair<int,int>> a(n+1);
//     for(int i = 1; i <= n; i++) {
//         int x;cin >> x;
//         a[i] = {x,i};
//     }
//     sort(a.begin()+1,a.end(),[&](auto x,auto y){
//         if(x.first == y.first) return x.second < y.second;
//         else return x.first < y.first;
//     });
//     vector<int> rank(n+1);
//     for(int i = 1; i <= n; i++){
//         rank[a[i].second] = i; 
//     }
//     vector<int> tree(n+1);
//     auto lowbit = [&](int x){
//         return x & (-x);
//     };
//     auto update = [&](int x,int d){
//         while(x <= n){
//             tree[x] += d;
//             x += lowbit(x);
//         }
//     };
//     auto sum = [&](int x){
//         int ans = 0;
//         while(x > 0){
//             ans += tree[x];
//             x -= lowbit(x);
//         }
//         return ans;
//     };
//     ll ans = 0;
//     for(int i = n; i >= 1; i--){
//         ans += sum(rank[i]);
//         update(rank[i],1);
//     }
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     while(1){
//         cin >> n;
//         if(!n) break;
//         solve();
//     }
// }
