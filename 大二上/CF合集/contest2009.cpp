// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int _;cin >> _;
//     for(int i = 1; i <= _; i++){
//         solve();
//     }
//     return 0;
// }

/*F. Firefly's Queries*/  
/*2024.10.8*/ //给自己循环写法绕晕了
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+10;
// ll sum[N*2];
// ll a[N*2];
// void solve(){
//     int n,q;cin >> n >> q;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//         a[i+n] = a[i];
//     }
//     for(int i = 1; i <= 2*n; i++){
//         sum[i] = a[i] + sum[i-1];
//     }
//     auto get = [&](ll x){
//         if(x == 0) return 0ll;
//         ll k = (x + n - 1) / n; //偏移量 
//         ll r = x - (k - 1) * n + k - 1; //倒推当前在循环前缀和位置
//         ll ans = (k - 1) * sum[n] + sum[r] - sum[k - 1];
//         return ans;
//     };
//     while(q--){
//         ll l,r;cin >> l >> r;
//         cout << get(r) - get(l - 1) << "\n";
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int _;cin >> _;
//     for(int i = 1; i <= _; i++){
//         solve();
//     }
//     return 0;
// }

/*E. Klee's SUPER DUPER LARGE Array!!!*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     ll n,k;cin >> n >> k;
//     ll l = 1,r = n;
//     ll target = (n*n + 2 * k * n - n) / 2;
//     while(l <= r){
//         ll mid = (l + r) >> 1;
//         if(mid * mid + 2 * k * mid - mid > target) r = mid - 1;
//         else l = mid + 1;
//     }
//     ll ans = min(abs(r*r+2*r*k-r - target),abs(l*l+2*k*l-l - target));
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int _;cin >> _;
//     for(int i = 1; i <= _; i++){
//         solve();
//     }
//     return 0;
// }

/*D. Satyam and Counting*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
//  map<int,bool> mp[2];
// void solve(){
//     int n;cin >> n;
//     mp[0].clear();
//     mp[1].clear();
//     int cnt = 0;
//     for(int i = 1; i <= n; i++){
//         int x,y;cin >> x >> y;
//         if(mp[(y+1)%2].count(x)){
//             cnt++;
//         }
//         mp[y][x] = 1;
//     }
//     ll ans = 0;
//     ans += 1ll * cnt * (n - 2);
//     for(auto t : mp[0]){
//         int x = t.first;
//         if(mp[1].count(x-1) && mp[1].count(x+1)){
//             ans++;
//             //cout << "?1 " << x << "\n";
//         }
//     }
//     for(auto t : mp[1]){
//         int x = t.first;
//         if(mp[0].count(x-1) && mp[0].count(x+1)){
//             ans++;
//             //cout << "?2 " << x << "\n";
//         }
//     }
//     //cout << "? " << cnt << "\n";
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int _;cin >> _;
//     for(int i = 1; i <= _; i++){
//         solve();
//     }
//     return 0;
// }

/*A. Minimize!*/
//#include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int a,b;cin >> a >> b;
//     int ans = 1e9+10;
//     for(int i = a; i <= b; i++){
//         ans = min(ans,i - a + b - i);
//     }
//     cout << ans << "\n";
//     return;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie();cout.tie();
//     int _;cin >> _;
//     for(int i = 1; i <= _; i++){
//         solve();
//     }
//     return 0;
// }

/*B. osu!mania*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// char mp[600][600];
// void solve(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= 4 ;j++){
//             cin >> mp[i][j];
//         }
//     }
//     for(int i = n; i >= 1; i--){
//         for(int j = 1; j <= 4; j++){
//             if(mp[i][j] == '#'){
//                 cout << j << " ";
//             }
//         }
//     }
//     cout << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie();cout.tie();
//     int _;cin >> _;
//     for(int i = 1; i <= _; i++){
//         solve();
//     }
//     return 0;
// }

/*C. The Legend of Freya the Frog*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int x,y,k;
//     cin >> x >> y >> k;
//     int xx = (x + k - 1) / k;
//     int yy = (y + k - 1) / k;
//     // x y x . x
//     // x y . y . y
//     if(xx > yy) cout << xx * 2 - 1 << "\n";
//     else cout << max(xx,yy) * 2 << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie();cout.tie();
//     int _;cin >> _;
//     for(int i = 1; i <= _; i++){
//         solve();
//     }
//     return 0;
// }