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

/*I 小鸡的排列构造的checker*/
/*2025.3.1 题解*/ //树状数组离线查询
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e5+10;
void solve(){
    int n,m;cin >> n >> m;
    vector<int> p(n+1), pos(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        pos[p[i]] = i;
    }
    vector<vector<int>> q(n+1);
    vector<int> l(m),r(m),c(m),ans(m);
    for(int i = 0; i < m; i++){
        cin >> l[i] >> r[i] >> c[i];
        q[p[c[i]]].push_back(i);
    }
    vector<int> tree(n+1);
    auto lowbit = [&](int x){
        return x & (-x);
    };
    auto update = [&](int x){
        while(x <= n){
            tree[x]++;
            x += lowbit(x);
        }
    };
    auto sum = [&](int x){
        int ans = 0;
        while(x > 0){
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    };
    for(int i = 1; i <= n; i++){
        for(int j : q[i]) ans[j] = sum(r[j]) - sum(l[j] - 1) + l[j];
        update(pos[i]);
    }
    for(int i : ans) cout << i << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;cin >> t;
    while(t--){
        solve();
    }
}

/*J 铁刀磨成针*/
/*2025.3.1*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,x,y;cin >> n >> x >> y;
//     ll ans = 0;
//     for(int i = 1; i <= min(n,y); i++){
//         auto dc = [&](ll n,ll a){
//             return 1ll*n*(a+max(0ll,a-n+1))/2;
//         };
//         ll tmp = (min(n,y) - i) * (x+i) + dc(min(x+i,n-min(n,y)+1),x+i);
//         ans = max(ans,tmp);
//     }
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*C 数列之和*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ull unsigned long long
// const int N = 63;
// ull a[N];
// ull sum[N];
// void init(){
//     a[1] = 1;
//     a[2] = 1;
//     for(int i = 3; i < N; i++){
//         a[i] = 2*a[i-1] + 1;
//     }
//     for(int i = 1; i < N; i++){
//         sum[i] = sum[i-1] + a[i];
//     }
// }
// void solve(){
//     ull k;cin >> k;
//     int l = -1,r = N+1;
//     while(l+1 < r){
//         int mid = (l+r) >> 1;
//         if(sum[mid] < k) l = mid;
//         else r = mid; 
//     }
//     cout << k * 2 + l * 2 << "\n"; 
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     init();
//     while(t--){
//         solve();
//     }
// }

/*L 变鸡器*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+10;
// bool dfs(int len,int sum,vector<int>& arr){
//     bool flag = 0;
//     if(len == arr.size()){
//         if(sum == 0) return 1;
//         else return 0;
//     }
//     flag = dfs(len+1,abs(sum-arr[len]),arr) || dfs(len+1,sum+arr[len],arr); 
//     return flag;
// }
// void solve(){
//     int n;cin >> n;
//     string s;cin >> s;
//     int cnt = 0;
//     string cmp = "CHICKEN";
//     map<char,int> mp;
//     for(int i = 0; i < n; i++){
//         mp[s[i]]++;
//         if(cnt < cmp.size() && s[i] == cmp[cnt]) cnt++;
//     }
//     if(cnt < cmp.size()){
//         cout << "NO\n";
//         return;
//     }
//     for(int i = 0; i < cmp.size(); i++) mp[cmp[i]]--;
//     int maxn = 0;
//     int len = 0;
//     for(auto t : mp){
//         len += t.second;
//         maxn = max(maxn,t.second);
//     } 
//     if(maxn <= len / 2 && len % 2 == 0){
//         cout << "YES\n";
//     }else{
//         cout << "NO\n";
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

/*K 鸡翻题*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int x,y;cin >> x >> y;
//     if((y-1-2*x) % 4 == 0){
//         cout << "YES\n";
//     }else{
//         cout << "NO\n";
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

/*A 复制鸡*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     vector<int> b(n);
//     for(int i = 0; i < n; i++){
//         cin >> b[i];
//     }
//     b.erase(unique(b.begin(),b.end()),b.end());
//     cout << b.size() << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }
