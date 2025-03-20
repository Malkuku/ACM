// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }

/*C. Lazy Narek*/
/*2024.9.27*/ //动归--字符串匹配
// //dp[i][j] //第i个数，结尾是j的数量
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// string ss = "narek";
// const int N = 1e3+10;
// int dp[N][10]; //相当于跑五遍s
// pair<int,int> find(string s,int now){ //这个处理是我想不到的
//     int ans = 0;
//     for(int i = 0; i < s.size(); i++){
//         if(ss.find(s[i]) != -1) ans--;
//         if(s[i] == ss[now]){
//             now++;
//             if(now == 5){
//                 ans += 10;
//                 now = 0;
//             }
//         }
//     }
//     return {ans,now};
// }
// void solve(){
//     int n,m;
//     cin >> n >> m;
//     memset(dp,-0x3f,sizeof dp);
//     dp[0][0] = 0;
//     for(int i = 1; i <= n; i++){
//         string s;cin >> s;
//         for(int j = 0; j < 5; j++){
//             dp[i][j] = max(dp[i][j],dp[i-1][j]);
//             pair<int,int> t = find(s,j);
//             dp[i][t.second] = max(dp[i][t.second],dp[i-1][j] + t.first);
//             //cout << dp[i][t.second] << " " << t.first << " " << t.second << "\n";
//         }
//     }
//    int ans = 0;
//    for(int i = 0; i < 5; i++) ans = max(ans,dp[n][i]);
//    cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }

/*B2. The Strict Teacher (Hard Version)*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+10;
// int tea[N];
// void solve(){
//     int n,m,q;cin >> n >> m >> q;
//     for(int i = 1; i <= m; i++){
//         cin >> tea[i];
//     }
//     sort(tea+1,tea+1+m);
//     while(q--){
//         int x;cin >> x;
//         int l = 1,r = m;
//         while(l <= r){
//             int mid = (l+r) >> 1;
//             if(tea[mid] > x) r = mid - 1;
//             else l = mid + 1;
//         }
//         //r x l
//         //cout << l << " ? " << r <<  "\n";
//         if(r <= 0){
//             cout << tea[l] - 1 << "\n";
//             continue;
//         }
//         else if(l > m){
//             cout << n - tea[r] << "\n";
//             continue;
//         }
//         else{
//             ll mid = ( 0ll+ tea[l] + tea[r]) >> 1;
//             ll ans = min(mid - tea[r], tea[l] - mid);
//             cout << ans << '\n';
//             continue;
//         }
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }


/*B1. The Strict Teacher (Easy Version)*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,m,q;cin >> n >> m >> q;
//     int m1,m2;cin >> m1 >> m2;
//     int pos; cin >> pos;
//     if(pos < m1 && pos < m2){
//         cout << min(m1,m2) - 1 << "\n";
//         return;
//     }
//     else if(pos > m1 && pos > m2){
//         cout << n - max(m1,m2) << "\n";
//         return;
//     }
//     else if(pos > min(m1,m2) && pos < max(m1,m2)){
//         int mid = (m1 + m2) / 2;
//         int ans = min(mid - min(m1,m2) , max(m1,m2) - mid);
//         cout << ans << "\n";
//         return ;
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }


/*A. Simple Palindrome*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// char arr[] = {'a','e','i','o','u'};
// void solve(){
//     int n;cin >> n;
//     int cnt = n - 5;
//     string ans;
//     int num[5] = { 0 };
//     for(int i = 0; i < n; i++){
//         num[i % 5]++;
//         cnt--;
//     }
//     for(int i = 0;i < 5; i++){
//         for(int j = 0; j < num[i % 5]; j++){
//             ans += arr[i % 5];
//         }
//     }
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }