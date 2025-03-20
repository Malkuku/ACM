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

/*J 硝基甲苯之袭*/
/*2025.2.24*/ //位运算，交换型
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e6+10;
// int cnt[N] = { 0 };
// int gcd(int a,int b){
//     return b == 0 ? a : gcd(b,a%b);
// }
// void solve(){
//     int n;cin >> n;
//     vector<int> arr(n);
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//         cnt[arr[i]]++;
//     }
//     ll ans = 0;
//     sort(arr.begin(),arr.end());
//     arr.erase(unique(arr.begin(),arr.end()),arr.end());
//     for(int i = 0; i < arr.size(); i++){
//         for(int j = 1; j <= arr[i]/j; j++){
//             if(arr[i] % j) continue;
//             int b = j ^ arr[i];
//             if(j == gcd(arr[i],b)){
//                 ans += 1ll*cnt[arr[i]] * cnt[b]; 
//                 //cout << "? " << arr[i] << " " << b << "\n";
//             }
//             int x = arr[i] / j;
//             if(j * j != arr[i]){
//                 int c = x ^ arr[i];
//                 if(x == gcd(arr[i],c)){
//                     ans += 1ll*cnt[arr[i]] * cnt[c];
//                     //cout << "? " << arr[i] << " " << c << "\n"; 
//                 }
//             }
//         }
//     }
//     cout << ans/2 << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*E 双生双宿之错*/
/*2025.2.11*/ //对半分，中位数
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// int a[N];
// void solve(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     sort(a + 1, a + 1 + n);
//     int pos = n / 2;
//     int pos1 = (pos+1) / 2;
//     int pos2 = n - pos1 + 1;
//     ll ans = 0;
//     //cout<< "? " << pos1 << " " << pos2 << "\n";
//     //cout <<"? "<< a[pos1] << " " << a[pos2] << "\n";
//     if(a[pos1] != a[pos2]){
//         for(int i = 1; i <= pos; i++){
//             ans += abs(a[pos1] - a[i]);
//         }
//         for(int i = pos+1; i <= n; i++){
//             ans += abs(a[pos2] - a[i]);
//         }
//         cout << ans << "\n";
//     }else{
//         ll ans1 = 0,ans2 = 0;
//         for(int i = 1; i <= pos; i++){
//             ans1 += abs(a[pos1] - 1 - a[i]);
//         }
//         for(int i = pos+1; i <= n; i++){
//             ans1 += abs(a[pos2] - a[i]);
//         }
//         for(int i = 1; i <= pos; i++){
//             ans2 += abs(a[pos1] - a[i]);
//         }
//         for(int i = pos+1; i <= n; i++){
//             ans2 += abs(a[pos2] + 1 - a[i]);
//         }
//         ans = min(ans1,ans2);
//         cout << ans << "\n";
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

/*H 井然有序之窗*/
/*2025.1.26*/ //思维,优先排序
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// #define PII pair<int,int>
// struct node{
//     int first;
//     int second;
//     int pos;
//     bool operator() (const node& a,const node& b) const{
//         return a.second > b.second;
//     }
// };
// int ans[N];
// void solve(){
//     int n;cin >> n;
//     vector<node> vc;
//     for(int i = 0; i < n; i++){
//         int a,b; cin >> a >> b;
//         vc.push_back({a,b,i});
//     }
//     sort(vc.begin(),vc.end(),[](auto x,auto y){
//         if(x.first != y.first) return x.first < y.first;
//         return x.second < y.second;
//     });
//     priority_queue<node,vector<node>,node> pq;
//     int len = 0;
//     for(int i = 1; i <= n; i++){
//         while(len < vc.size() && vc[len].first <= i){
//             pq.push(vc[len]);
//             len++;
//         }
//         bool flag = 0;
//         while(pq.size()){
//             auto t = pq.top();pq.pop();
//             if(t.first <= i && t.second >= i){
//                 ans[t.pos] = i;
//                 flag = 1;
//                 break;
//             }
//         }
//         if(!flag){
//             cout << -1 << "\n";
//             return;
//         }
//     }
//     for(int i = 0; i < n; i++){
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

/*J 硝基甲苯之袭*/

/*M 数值膨胀之美*/ //快速查询区间的最大/最小值
/*2025.2.11 WA*/ //ST表
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// struct Node{
//     int num;
//     int pos;
// };
// const int N = 1e5 + 10;
// int min_st[N][30];
// int max_st[N][30];
// int L2[N];
// int a[N];
// Node b[N];
// void init(){
//     L2[1] = 0;
//     for(int i = 2; i <= 30; i++){
//         L2[i] = L2[i/2] + 1;
//     }
// }
// void build(int n){
//     for(int i = 0; i < n; i++){
//         min_st[i][0] = a[i];
//         max_st[i][0] = a[i];
//     } 
//     for(int j = 1; j < 30; j++){
//         for(int k = 0; k + (1 << j) <= n; k++){
//             min_st[k][j] = min(min_st[k][j-1],min_st[k + (1 << (j-1))][j-1]);
//             max_st[k][j] = max(max_st[k][j-1],max_st[k + (1 << (j-1))][j-1]);
//         }
//     }
// }
// int find_min(int l,int r){
//     if(r < l) return 1e9+1;
//     int k = L2[r-l+1];
//     return min(min_st[l][k],min_st[r - (1<<k)+1][k]);
// }
// int find_max(int l,int r){
//     if(r < l) return 0;
//     int k = L2[r-l+1];
//     return max(max_st[l][k],max_st[r-(1<<k)+1][k]);
// }
// void solve(){
//     int n;cin >> n;
//     int min_num = 1e9+1;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//         b[i] = {a[i],i};
//         min_num = min(a[i],min_num);
//     }
//     build(n);
//     int ans = 1e9+1; 
//     int l = n-1,r = 0;
//     int index = 0;
//     sort(b,b+n,[](auto x,auto y){
//         if(x.num != y.num){
//             return x.num < y.num;
//         }
//         else return x.pos < y.pos;
//     });
//     for(int index = 0; index < n; index++){
//         if(r-l+1 == index){
//             l = min(l,b[index].pos);
//             r = max(r,b[index].pos);
//             int now_max = max({find_max(l,r)*2,find_max(0,l-1),find_max(r+1,n-1)});
//             int now_min = min({find_min(l,r)*2,find_min(0,l-1),find_min(r+1,n-1)});
//             ans = min(ans,now_max - now_min);
//         }
//     }
//     ans = min(ans,(find_max(0,n-1) - find_min(0,n-1)) * 2);
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     init();
//     while(t--){
//         solve();
//     }
// }
/*2025.2.11 题解*/ //利用特性
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// int n;int a[N];
// pair<int,int> b[N];
// void solve(){
//     cin >> n;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//         b[i] = {a[i],i};
//     }
//     sort(b,b+n);
//     int l = n - 1,r = 0;
//     ll ans = 1e10;
//     for(int i = 0; i < n-1; i++){
//         l = min(l,b[i].second);
//         r = max(r,b[i].second);
//         if(r-l+1 == i+1){
//             ans = min(ans,(ll)max(b[n-1].first,2*b[i].first)-min(2*b[0].first,b[i+1].first));
//         }
//         //cout << "? " << ans << "\n";
//     }
//     ans = min(ans,1ll*2*(b[n-1].first-b[0].first));
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

/*G 井然有序之衡*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// map<pair<ll,int>,bool> pai;
// int a[N];
// bool st[N];
// void init(){
//     ll sum = 0;
//     for(int i = 1; i <= N; i++){
//         sum += i;
//         pai[{sum,i}] = 1;
//     }
// }
// void solve(){
//     int n;cin >> n;
//     ll sum = 0;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//         sum += a[i];
//     }
//     if(!pai[{sum,n}]){
//         cout << -1 << "\n";
//         return;
//     }
//     sort(a,a+n);
//     ll ans = 0;
//     for(int i = 0; i < n; i++){
//         ans += abs(a[i] - (i+1));
//     }
//     cout << ans / 2 << '\n';
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     init();
//     while(t--){
//         solve();
//     }
// }

/*B 一气贯通之刃*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5 + 10;
// int in[N];
// void solve(){
//     int n;cin >> n;
//     for(int i = 0; i <= n; i++) in[i] = 0;
//     for(int i = 1; i < n; i++){
//         int x,y;cin >> x >> y;
//         in[x]++;
//         in[y]++;
//     }
//     vector<int> vc;
//     for(int i = 1; i <= n; i++){
//         if(in[i] >= 3){
//             cout << -1 << "\n";
//             return;
//         }
//         if(in[i] == 1) vc.push_back(i);
//     }
//     if(vc.size() != 2){
//         cout << -1 << "\n";
//         return;
//     }
//     cout << vc[0] << " " << vc[1] << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*D 双生双宿之决*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// int a[N];
// void solve(){
//     int n;cin >> n;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     if(n & 1){
//         cout << "No\n";
//         return;
//     }
//     map<int,int> mp;
//     for(int i = 0; i < n; i++){
//         mp[a[i]]++;
//     }
//     if(mp.size() != 2){
//         cout << "No\n";
//         return;
//     }
//     vector<int> vc;
//     for(auto t : mp){
//         vc.push_back(t.first);
//     }
//     if(mp[vc[0]] != mp[vc[1]]) {
//         cout << "No\n";
//         return;
//     }
//     cout << "Yes\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*A 茕茕孑立之影*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// int a[N];
// void solve(){
//     int n;cin >> n;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     for(int i = 0; i < n; i++){
//         if(a[i] == 1) {
//             cout << -1 << "\n";
//             return;
//         }
//     }
//     cout << 1000000993 << "\n";
// }
// int main(){
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }