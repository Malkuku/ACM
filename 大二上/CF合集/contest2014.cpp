// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long

// void solve(){

// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int _ = 0;
//     cin >> _;
//     for(int i = 1; i <= _; i++){
//         solve();
//     }
//     return 0;
// }

/*A Robin Helps */
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 55;
// int a[N];
// void solve(){
//     int sum = 0;
//     int n,k;cin >> n >> k;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     int cnt = 0;
//     for(int i = 0; i < n; i++){
//         if(a[i] >= k) sum+=a[i];
//         else if(sum > 0 && a[i] == 0){
//             sum--;
//             cnt++;
//         }
//     }
//     cout << cnt << '\n';
// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int _ = 0;
//     cin >> _;
//     for(int i = 1; i <= _; i++){
//         solve();
//     }
//     return 0;
// }

/*B. Robin Hood and the Major Oak*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e6+10;
// ll kms(ll a,ll b){
//     ll ans = 1;
//     while(b){
//         if(b&1){
//             ans *= a;
//         }
//         a *= a;
//         b >>= 1;
//     }
//     return ans;
// }
// // 5 4 3 2 1
// // 6 5 4 3
// //
// // 4 3 2 1
// void solve(){
//     ll n,k;
//     cin >> n >> k;
//     ll ans = (n + n - k + 1) * k / 2;
//     if(ans & 1) cout << "No\n";
//     else cout << "Yes\n";
// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int _ = 0;
//     cin >> _;
//     for(int i = 1; i <= _; i++){
//         solve();
//     }
//     return 0;
// }


/*C. Robin Hood in Town*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+10;
// ll a[N];
// void solve(){
//     int n;cin >> n;
//     ll sum = 0;
//     for(int i = 1; i <= n; i++) {
//         cin >> a[i];
//         sum += a[i];
//     }
//     sort(a+1,a+1+n);
//     int half = n / 2 + 1;
//     if(half >= n){
//         cout << -1 << "\n";
//         return;
//     }
//     //cout <<"? "<< a[half] << " " << sum / (n*2) << "\n";
//     if(sum % (n*2)){
//         if(a[half] <= sum / (n*2)){
//             cout << 0 << "\n";
//             return;
//         }
//         else{
//             cout << a[half]*n*2 - sum + 1 << "\n";
//             return;
//         }
//     }
//     //(sum+x) / n > a[half];
//     else{
//         if(a[half] < sum / (n*2)){
//             cout << 0 << "\n";
//             return;
//         }
//         else{
//             cout << a[half]*n*2 - sum + 1 << "\n";
//             return;
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int _ = 0;
//     cin >> _;
//     for(int i = 1; i <= _; i++){
//         solve();
//     }
//     return 0;
// }


/*D. Robert Hood and Mrs Hood*/ //区间重叠问题
/*2024.9.25 题解*/
// //用set模拟
// //L[]存左端点，R[]存右端点
// // 每次长为d的左区间
// //1-n 尺取更新
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// vector<int> L[N],R[N];
// void solve(){
//     int n,d,k;cin >> n >> d >> k;
//     for(int i = 1; i <= n; i++) L[i].clear(),R[i].clear();
//     for(int i = 1;i <= k; i++){
//         int l,r;cin >> l >> r;
//         L[l].push_back(i);R[r].push_back(i);
//     }
//     set<int> st;
//     for(int i = 1; i <= d; i++){
//        for(int t : L[i]) st.insert(t);
//     }
//     int ans1 = st.size(),ans2 = st.size(); int ip1 = 1,ip2 =  1;
//     int pos = 1;
//     while(pos + d <= n){
//         for(int t : L[pos+d]) st.insert(t);
//         for(int t : R[pos]) st.erase(t);
//         if(ans1 < st.size()){
//             ans1 = st.size();
//             ip1 = pos + 1;
//         }
//         if(ans2 > st.size()){
//             ans2 = st.size();
//             ip2 = pos + 1;
//         }
//         pos++;
//     }
//     cout << ip1 << " " << ip2 << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int _ = 0;
//     cin >> _;
//     for(int i = 1; i <= _; i++){
//         solve();
//     }
//     return 0;
// }


/*E. Rendez-vous de Marian et Robin*/
//双起点 -- 可以优化成单起点吗？ -》 跑俩遍取最小焦点即可
//路径 -- 寻找离起点最近的马？ 马应该怎么选？-》 用分层图解决
/*2024.10.1 题解*/ //分层图
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>
const int N = 2e5 + 10;

void solve(){
    int n,m,h;cin >> n >> m >> h;
    for(int i = 1; i <= h; i++) cin >> ma[i];
    for(int i = 1; i <= n; i++) {
        go[i].clear();
    }
    for(int i = 1; i <= m; i++){
        int u,v,w;cin >> u >> v >> w;
        go[v].push_back({u,w});
        go[u].push_back({v,w});
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int _ = 0;
    cin >> _;
    for(int i = 1; i <= _; i++){
        solve();
    }
    return 0;
}
