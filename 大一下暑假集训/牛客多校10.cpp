#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*K Doremy's IQ 2*/ //思维 模拟图示
/*2024.8.30*/ //无法理解该写法
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// int a[N];
// int n;
// int sov1(){
//     int pos = n+1; //第一个比0大
//     for(int i = 1; i <= n; i++){
//         if(a[i] > 0){
//             pos = i;
//             break;
//         }
//     }
//     int L = n,R = n,ans = 0;
//     for(int i = 0; i < pos; i++){
//         cout << "\n";
//         //枚举h到L的间隔p，找到极限的L
//         while(L >= i && a[L]+i >= 0){
//             //cout <<"L "<< pos << " " << i << " " << L << " " << a[L] << "\n";
//             L--;
//         } 
//         L = max(L,i);
//         while(R >= pos && n - R < a[R] + i) {
//             //cout <<"R " <<pos << " " << i << " " << R << " " << a[R] << "\n";
//             R--;
//         }
//         ans = max(ans,R-L);
//     }
//     return ans;
// }
// int main(){
//     int t;cin >> t;
//     while(t--){
//         cin >> n;
//         for(int i = 1; i <= n; i++){
//             cin >> a[i];
//         }
//         int ans = sov1();
//         for(int i = 1; i <= n; i++) a[i]*=-1;
//         reverse(a+1,a+n+1);
//         ans = max(ans,sov1());
//         cout << ans << "\n";
//     }
//     return 0;
// }

/*B std::pair*/
/*2024.8.28*/ //模拟二叉树
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// enum Type{
//     INT = 1,
//     DOUBLE = 2,
//     PAIR = 3
// };
// int n,q;
// map<string,int> name;
// struct TwoTree{
//     int t = 0;
//     TwoTree* l;
//     TwoTree* r;
// };
// TwoTree* two_tree[1010];
// TwoTree* getTree(string& s,int& pos){
//     TwoTree* tree = new TwoTree;
//     if(s[pos] == 'i'){
//         pos+=3;
//         tree->t = INT;
//     }
//     else if(s[pos] == 'd'){
//         pos+=6;
//         tree->t = DOUBLE;
//     }
//     else if(s[pos] == 'p'){
//         pos+=5;
//         tree->t = PAIR;
//         tree->l = getTree(s,pos);
//         pos++;
//         tree->r = getTree(s,pos);
//         pos++;
//     }
//     else{
//         cout << "bug2!\n";
//     }
//     return tree;
// }
// void treePrint(TwoTree* ptr){
//     if(ptr->t == INT) cout << "int";
//     else if(ptr->t == DOUBLE) cout << "double";
//     else if(ptr->t == PAIR){
//         cout << "pair<";
//         treePrint(ptr->l);
//         cout << ",";
//         treePrint(ptr->r);
//         cout << ">";
//     }
//     else cout << "bug!\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     cin >> n >> q;
//     for(int i = 0; i < n; i++){
//         string s1,s2;
//         cin >> s1 >> s2;
//         name[s2] = i;
//         int pos = 0;
//         two_tree[i] = getTree(s1,pos);
//     }
//     while(q--){
//         string s;cin >> s;
//         s+='.';
//         int pos = s.find('.');
//         int id = name[s.substr(0,pos) + ';'];
//         TwoTree* ptr = two_tree[id];
//         for(int i = pos+1; i < s.size(); i++){
//             if(s[i] == 'f') {
//                 i+=5;
//                 ptr = ptr->l;
//             }
//             else if(s[i] == 's'){
//                 i+=6;
//                 ptr = ptr->r;
//             }
//         }
//         treePrint(ptr);
//         cout << "\n";
//     }
//     return 0;
// }

/*F Collinear Exception*/
/*2024.8.18*/ //模拟绘图
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// int n; 
// const int N = 1e6 + 10;
// bool mp[1010][1010];
// PII node[N];
// vector<PII> ans;
// int main(){
//     ios::sync_with_stdio(0);
//     cin >> n;
//     for(int i = 0; i < n*n; i++){
//         int x,y;cin >> x >> y;
//         node[i] = {x,y};
//     }
//     for(int i = 0; i < n*n; i++){
//         int x1 = node[i].first;
//         int y1 = node[i].second;
//         if(mp[x1][y1]) continue;
//         for(int j = 0; j < ans.size(); j++){
//             int x2 = ans[j].first;
//             int y2 = ans[j].second;
//             //cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
//             int dx = x1 - x2;
//             int dy = y1 - y2;
//             if(dx == 0){
//                 for(int k = 1; k <= n; k++) mp[x1][k] = 1;
//             }
//             else if(dy == 0){
//                 for(int k = 1; k <= n; k++) mp[k][y1] = 1;
//             }
//             else{
//                 int g = __gcd(dx,dy);
//                 dx /= g;
//                 dy /= g;
//                 int xx = x1,yy = y1;
//                 //cout << xx << " "<< yy << " " << dx << " " << dy << "\n";
//                 while(1){
//                     mp[xx][yy] = 1;
//                     xx+=dx,yy+=dy;
//                     if(xx <= 0 || xx > n || yy <= 0 || yy > n) break;
//                 }
//                 xx = x1,yy = y1;
//                 while(1){
//                     mp[xx][yy] = 1;
//                     xx-=dx,yy-=dy;
//                     if(xx <= 0 || xx > n || yy <= 0 || yy > n) break;
//                 }
//             }
//         }
//         ans.push_back({x1,y1});
//     }
//     map<PII,bool> st;
//     for(int i = 0; i < ans.size(); i++) st[{ans[i].first,ans[i].second}] = 1;
//     for(int i = 0; i < n*n; i++){
//         if(st[{node[i].first,node[i].second}]) cout << "1";
//         else cout << "0";
//     }cout << "\n";
//     return 0;
// }

/*H All-in at the Pre-flop*/
/*2024.8.18*/ //神秘打表题 -- 转换成线性方程组唯一解问题
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll M = 998244353;
// ll ksm(ll a,ll b){
//     ll res = 1;
//     while(b){
//         if(b&1) res = res*a%M;
//         a = a*a%M;
//         b>>=1;
//     }
//     return res;
// }
// ll sov1(ll a,ll b){
//     return a*ksm(b,M-2) % M;
// }
// int main(){
//     ll a,b; cin >> a >> b;
//     cout << sov1(a,a+b) << " " << sov1(b,a+b) << "\n";
//     return 0;
// }
/*WA*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll M = 998244353;
// ll ksm(ll a, ll b){
//     a %= M,b %= M;
//     ll res = 1;
//     while(b) {
//         if(b & 1)                    
//             res = res * a % M;       
//         a = a * a % M;             
//         b >>= 1;                 
//     }
//     return res;
// }
// ll sov1(ll a,ll b){
//    return a*ksm(b,M-2) % M;
// }
// ll gcd(ll a,ll b){
//     return b ? gcd(b,a%b) : a;
// }
// vector<ll> win;
// ll two[40];
// void init(){
//     two[0] = 1;
//     for(int i = 1; i <= 35; i++){
//         two[i] = two[i-1] * 2;
//     }
// }
// void dfs(ll a,ll b,int step){
//      //cout << a <<" "<< b << " " <<step << "\n";
//     if(step > 30) return;
//     if(a > b){
//         win.push_back(step+1);  
//         dfs(a - b,b + b,step+1); 
//     } 
//     else if(a < b) dfs(a + a,b - a,step+1);
//     else if(a == b) win.push_back(step+1);  
// }
// int main(){
//     init();
//     ll x,y;cin >> x >> y;
//     dfs(x,y,0);
//     ll a = 0,b = 0; //a/b;
//     //cout << win.size() << "\n";
//     if(win.size() == 0) {
//         cout << 0 << " " << 1 << "\n";
//         return 0;
//     }
//     if(two[30]*y < x){
//         cout << 1 << " " << 0 << "\n";
//         return 0;
//     }
//     //cout << win[0] << "\n";
//     sort(win.begin(),win.end(),[](auto x,auto y){return x > y;});
//     b = two[win[0]],a = 1;
//     for(int i = 1; i < win.size(); i++){
//         a += b/two[win[i]];
//     }
//     //cout << a << " " << b << "\n";
//     cout << sov1(a,b) << " " << sov1(b - a,b) << "\n";
// }