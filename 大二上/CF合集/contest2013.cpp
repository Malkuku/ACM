// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int _ = 1;
//     cin >> _;
//     for(int i = 1; i <= _ ;i++){
//         solve();
//     }
//     return 0;
// }

/*E. Prefix GCD*/
/*2024.9.26 题解*/ //gcd的收敛速度可以是logn
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+5;
// ll a[N];
// ll gcd(ll a,ll b){
//     return b ? gcd(b,a%b) : a;
// }
// void solve(){
//     int n;cin >> n;
//     ll d = 0;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//         d = gcd(d,a[i]);
//     }
//     sort(a+1,a+1+n);
//     ll ans = a[1];
//     int cnt = 1;
//     ll g = a[1];
//     for(int i = 2; i <= n; i++){
//         ll tmp = g;
//         for(int j = i; j <= n; j++){
//             if(tmp > gcd(g,a[j])){
//                 tmp = gcd(g,a[j]);
//                 swap(a[i],a[j]);
//             }
//         }
//         ans += tmp;
//         g = tmp;
//         cnt++;
//         if(tmp <= d) break;
//     }
//     //cout << cnt << " " << d << '\n';
//     ans += d*(n - cnt);
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int _ = 1;
//     cin >> _;
//     for(int i = 1; i <= _ ;i++){
//         solve();
//     }
//     return 0;
// }

/*D. Minimize the Difference*/ //求极差
/*2024.9.26 题解*/ //由单调性而来的二分 
// //二分 最大值的最小值 和 最小值的最大值
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+5;
// ll a[N];int n;
// bool check1(ll x){
//     ll sum = 0;
//     for(int i = 1; i <= n; i++){
//         if(a[i] > x){
//             sum += a[i] - x;
//         }
//         else if(a[i] < x){
//             sum -= min(sum,x - a[i]);
//         }
//     }
//     if(sum > 0) return 0;
//     else return 1;
// }
// bool check2(ll x){
//     ll sum = 0;
//     for(int i = 1; i <= n; i++){
//         if(a[i] < x){
//             sum -= x - a[i];
//             if(sum < 0) return 0;
//         }
//         else if(a[i] > x){
//             sum += a[i] - x;
//         }
//     }
//     return 1;
// }
// void solve(){
//     cin >> n;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     //find max-min
//     ll l = 1,r = 1e18;
//     while(l <= r){
//         ll mid = (l + r) >> 1;
//         if(check1(mid))  r = mid - 1;
//         else l = mid + 1;
//     }
//     ll ans1 = l;
//     //min - max
//     l = 1,r = 1e18;
//     while(l <= r){
//         ll mid = (l + r) >> 1;
//         if(check2(mid)) l = mid + 1;
//         else r = mid - 1;
//     }
//     ll ans2 = r;
//     //cout << ans1 << " " << ans2 << "\n";
//     cout << ans1 - ans2 << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int _ = 1;
//     cin >> _;
//     for(int i = 1; i <= _ ;i++){
//         solve();
//     }
//     return 0;
// }
/*2024.9.26 题解*/ //由数组操作而来的前缀和 //amazing
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+10;
// ll a[N];
// void solve(){
//     int n;
//     cin >> n;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     ll sum = 0;
//     ll maxn = 0,minm = 1e18;
//     for(int i = 1; i <= n; i++){
//         sum += a[i];
//         minm = min((sum / i), minm);
//     }
//     sum = 0;
//     for(int i = n; i >= 1; i--){
//         sum += a[i];
//         maxn = max(((sum + n - i) / (n - i + 1)), maxn); 
//     }
//     cout << maxn - minm << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int _ = 1;
//     cin >> _;
//     for(int i = 1; i <= _ ;i++){
//         solve();
//     }
//     return 0;
// }

/*A. Zhan's Blender*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,x,y;
//     cin >> n >> x >> y;
//     int cnt = min(x,y);
//     cout << (n + cnt - 1) / cnt << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int _ = 1;
//     cin >> _;
//     for(int i = 1; i <= _ ;i++){
//         solve();
//     }
//     return 0;
// }

/*B. Battle for Survive*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+10;
// ll a[N];
// void solve(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     if(n == 1){
//         cout << a[n] << "\n";
//         return;
//     }
//     ll sum = a[n-1];
//     for(int i = 1; i < n-1; i++) sum -= a[i];
//     cout << a[n] - sum << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int _ = 1;
//     cin >> _;
//     for(int i = 1; i <= _ ;i++){
//         solve();
//     }
//     return 0;
// }

/*C. Password Cracking*/ //交互题
/*2024.9.26 题解*/ //模拟过程
// //先向左 -‘0’ -‘1’
// //再向右 -‘1’ -‘0’ --能保证2n次内找到
// //关键是一条路走到底
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// string s[4] = {"00","10","01","11"};
// void solve(){
//     int n;cin >> n;
//     string ans;
//     bool flag = 1;
//     if(n >= 2){
//         for(int i = 0; i < 4; i++){
//             cout << "? " << s[i] << "\n";
//             int x;cin >> x;
//             if(x == 1){
//                 ans = s[i];
//                 break;
//             }
//         }
//     }
//     if(ans.size() == n){
//         cout << "! " << ans << endl;
//         return;
//     }
//     while(flag){
//         if(ans.size() == n){
//             cout << "! " << ans << endl;
//             return;
//         }
//         flag = 0;
//         string tmp = ans + '0';
//         cout << "? " << tmp << endl;
//         int x; cin >> x;
//         if(x == 1){
//             ans = ans + '0';
//             flag = 1;
//             continue;
//         }
//         tmp = ans + '1';
//         cout << "? " << tmp << endl;
//         cin >> x;
//         if(x == 1){
//             ans = ans + '1';
//             flag = 1;
//             continue;
//         }
//     }
//     flag = 1;
//     while(flag){
//         if(ans.size() == n){
//             cout << "! " << ans << endl;
//             return;
//         }
//         flag = 0;
//         string tmp = '0' + ans;
//         cout << "? " << tmp << endl;
//         int x; cin >> x;
//         if(x == 1){
//             ans = '0' + ans;
//             flag = 1;
//             continue;
//         }
//         tmp = '1' + ans;
//         cout << "? " << tmp << endl;
//         cin >> x;
//         if(x == 1){
//             ans =  '1' + ans;
//             flag = 1;
//             continue;
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     //cin.tie(0);
//     //cout.tie(0);
//     int _ = 1;
//     cin >> _;
//     for(int i = 1; i <= _ ;i++){
//         solve();
//     }
//     return 0;
// }

