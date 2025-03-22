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

/*Problem A. 乌尔德 Urd*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    vector<ll> vc(1e6);
    vc[0] = 0;vc[1] = 1;
    for(int i = 2; i<=50; i++){
        vc[i] = vc[i-1] + vc[i-2];
    }
    //for(int p = 1;p <= 10; p++){
        for(int m = 1; m <= 10; m++){
            cout << m << "\n";
            for(int i = 1; i <= 50; i++){
                if(i % m == 0)cout << vc[i] << " ";
            }cout << "\n-------------\n";
        }
    //}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;//cin >> t;
    while(t--){
        solve();
    }
}

/*Problem D.*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll dp[2030];
// struct{
//     ll l,r,v;
// }arr[110];
// void solve(){
//     int n,m;cin >> n >> m;
//     for(int i = 1; i <= n; i++){
//         int l,r,v;cin >> v >> l >> r;
//         arr[i] = {l,r,v};
//     }
//     ll anss = 0;
//     auto sov1 = [&](int pos,int hao){
//         memset(dp,0,sizeof dp);
//         int ans = arr[hao].v;
//         for(int i = 1; i <= n; i++){
//             if(i == hao) continue;
//             if(arr[i].l <= pos && arr[i].r >= pos){
//                 ans+=arr[i].v;
//                 continue;
//             }
//             ll cnt = abs(pos - arr[i].l);
//             for(int j = m; j >= cnt; j--){
//                 dp[j] = max(dp[j],dp[j-cnt]+arr[i].v);
//             }
//             cnt = abs(pos - arr[i].r);
//             for(int j = m; j >= cnt; j--){
//                 dp[j] = max(dp[j],dp[j-cnt]+arr[i].v);
//             }
//         }
//         return ans + dp[m];
//     };
//     for(int i = 1; i <= n; i++){
//         anss = max(anss,sov1(arr[i].l,i));
//         anss = max(anss,sov1(arr[i].r,i));
//     }
//     cout << anss << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*Problem C. Anon 也想玩双影奇境*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,m;cin >> n >> m;
//     if(n < m) swap(n,m);
//     int ans = 0;
//     for(int i = 0;i < 30; i++){
//         if((n&1) == (m&1)) ans++;
//         n >>= 1;
//         m >>= 1;
//         if(n <= 0) break;
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

/*Problem E. Cloud Studio 的共享连接*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     string s;cin >> s;
//     string ans;
//     for(int i = 0; i < s.size(); i+=2){
//         int num = (s[i]-'0')*10 + (s[i+1]-'0');
//         char ch = num + 50;
//         ans += ch;
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