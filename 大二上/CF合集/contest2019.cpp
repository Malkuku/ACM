// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;
//     for(int i = 1; i <= t; i++){
//         solve();
//     }
// }

/*B. All Pairs Segments*/
/*2024.10.8 题解*/ //组合数学--重叠区间
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,q;cin >> n >> q;
//     vector<int> x(n);
//     for(int i = 0; i < n; i++){
//         cin >> x[i];
//     }
//     map<ll,ll> cnt;
//     //一个不与某个点重合的位置左边a个点，右边b个点 ，该位置被axb个区间覆盖
//     //重合 axb - a - b
//     for(int i = 0; i < n; i++){
//         if( i + 1 < n){
//             int num = x[i+1] - x[i] - 1;
//             ll res = 1ll * (i + 1) * (n - i - 1);
//             cnt[res] += num;   
//         }
//         ll res = 1ll * (i + 1) * (n - i - 1) + i;
//         cnt[res] += 1;
//     }
//     while(q--){
//         ll k;cin >> k;
//         cout << cnt[k] << " ";
//     }cout << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     for(int i = 1; i <= t; i++){
//         solve();
//     }
// }

/*A. Max Plus Size*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1010;
// int a[N];
// void solve(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     int max1 = 0;int cnt1 = 0;
//     for(int i = 1; i <= n; i+=2){
//         max1 = max(a[i],max1);
//         cnt1++;
//     }
//     int ans1 = max1 + cnt1;
//     int max2 = 0,cnt2 = 0;
//     for(int i = 2; i <= n; i+=2){
//         max2 = max(a[i],max2);
//         cnt2++;
//     }
//     int ans2 = max2 + cnt2;
//     cout << max(ans1,ans2) << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     for(int i = 1; i <= t; i++){
//         solve();
//     }
// }