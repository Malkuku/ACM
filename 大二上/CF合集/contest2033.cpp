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


/*F. Kosuke's Sloth*/
/*2024.10.29  题解*/ //fib% 原理 -- 可打表猜结论
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// ll fib[N];
// const int mod = 1e9+7;
// void solve(){
//     ll n,k;cin >> n >> k;
//     fib[1] = 1,fib[2] = 1;
//     int cnt = 3;
//     while(1){
//         fib[cnt%N] = (fib[(cnt-1) % N] + fib[(cnt-2) % N]) % k;
//         if(!fib[cnt%N]) break;
//         cnt++;
//     }
//     if(k == 1) cnt = 1;
//     cout << (cnt * (n % mod) ) % mod << "\n";
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

/*E. Sakurako, Kosuke, and the Permutation*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e6+10;
// bool st[N];
// int a[N];
// void solve(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     for(int i = 1; i <= n; i++) st[i] = 0;
//     int ans = 0;
//     for(int i = 1; i <= n; i++){
//         int pos = a[i];
//         int len = 0;
//         if(st[a[i]]) continue;
//         while(pos != i){
//             st[pos] = 1;
//             pos = a[pos];
//             len++;
//         }
//         st[pos] = 1;
//         ans += len / 2;
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


/*D. Kousuke's Assignment*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// const int N = 1e5+10;
// int a[N];
// ll sum[N];
// void solve(){
//     int n;cin >> n;
//     map<ll,vector<int>> mp;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
//     for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
//     mp[0].push_back(0);
//     for(int i = 1; i <= n; i++){
//         mp[sum[i]].push_back(i);
//     }
//     vector<PII> arr;
//     for(auto t : mp){
//         if(t.second.size() < 2) continue;
//         for(int i = 0; i+1 < t.second.size(); i+=2){
//             arr.push_back({t.second[i]+1,t.second[i+1]});
//         }
//     }
//     sort(arr.begin(),arr.end());
//     int ans = 0;
//     priority_queue<PII,vector<PII>,greater<PII>> q;
//     for(int i = 0; i < arr.size(); i++){
//         if(q.size()){
//             int l = q.top().second,r = q.top().first;
//             if(r < arr[i].first){
//                 ans++;
//                 while(q.size())q.pop();
//             }
//         }
//         q.push({arr[i].second,arr[i].first});
//     }
//     if(q.size()) ans++;
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
/*2024.10.29 AI--更好的贪心*/
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int, int>
// const int N = 1e5 + 10;
// int a[N];
// ll sum[N];
// void solve() {
//     int n;
//     cin >> n;
//     map<ll, int> mp;
//     for (int i = 1; i <= n; i++) {
//         cin >> a[i];
//     }
//     // 计算前缀和
//     for (int i = 1; i <= n; i++) {
//         sum[i] = sum[i - 1] + a[i];
//     }
//     vector<PII> arr;
//     mp[0] = 0;
//     // 构造所有“beautiful”区间
//     for (int i = 1; i <= n; i++) {
//         if (mp.count(sum[i])) {
//             arr.push_back({mp[sum[i]] + 1, i});
//         }
//         mp[sum[i]] = i;
//     }
//     // 按区间的结束位置排序
//     sort(arr.begin(), arr.end(), [](PII a, PII b) { return a.second < b.second; });
//     int ans = 0;
//     int last_end = 0;
//     // 贪心选择不重叠区间
//     for (const auto& interval : arr) {
//         if (interval.first > last_end) {
//             ans++;
//             last_end = interval.second;
//         }
//     }
//     cout << ans << "\n";
// }
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }


/*C. Sakurako's Field Trip*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+10;
// ll dp[N][2];
// ll arr[N],a[N],b[N];
// void solve(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++) cin >> arr[i];
//     ll ans = 0;
//     int pos = (n+1) / 2;
//     if(n & 1){
//         if(arr[pos-1] == arr[pos]) ans++;
//         if(arr[pos+1] == arr[pos]) ans++;
//         for(int i = pos - 1; i >= 1; i--){
//             a[pos - i] = arr[i];
//         }
//         for(int i = pos + 1; i <= n; i++){
//             b[i-pos] = arr[i];
//         }
//     }
//     else{
//         if(arr[pos] == arr[pos+1]) ans++;
//         for(int i = pos; i >= 1; i--){
//             a[pos - i + 1] = arr[i];
//         }
//         for(int i = pos + 1; i <= n; i++){
//             b[i-pos] = arr[i];
//         }
//     }   
//     //6/2 - > 3
//     //5/2 -> 3
//     dp[0][0] = 0;
//     dp[0][1] = 0;
//     //2 1 2
//     //2 1 1
//     //for(int i = 1; i <= n/2; i++) cout << a[i] << " ";
//     //cout << "\n";
//     //for(int i = 1; i <= n/2; i++) cout << b[i] << " ";
//     //cout << "\n";
//     for(int i = 1; i <= n/2; i++){
//         dp[i][0] = 1e16;
//         dp[i][1] = 1e16;
//         if(a[i] == a[i-1] && b[i] == b[i-1]){ //两段各自有贡献
//             dp[i][0] = min(dp[i-1][0] + 2,dp[i][0]);
//             dp[i][1] = min(dp[i-1][1] + 2,dp[i][1]);
//         }
//         else if(a[i] == a[i-1] || b[i] == b[i-1]){
//             dp[i][0] = min(dp[i-1][0] + 1,dp[i][0]);
//             dp[i][1] = min(dp[i-1][1] + 1,dp[i][1]);
//         }
//         else{
//             dp[i][0] = min(dp[i-1][0],dp[i][0]);
//             dp[i][1] = min(dp[i-1][1],dp[i][1]);
//         }
//         if(a[i] == b[i-1] && b[i] == a[i-1]){
//             dp[i][0] = min(dp[i-1][1] + 2,dp[i][0]);
//             dp[i][1] = min(dp[i-1][0] + 2,dp[i][1]);
//         }
//         else if(a[i] == b[i-1] || b[i] == a[i-1]){
//             dp[i][0] = min(dp[i-1][1] + 1,dp[i][0]);
//             dp[i][1] = min(dp[i-1][0] + 1,dp[i][1]);
//         }
//         else{
//             dp[i][0] = min(dp[i-1][1],dp[i][0]);
//             dp[i][1] = min(dp[i-1][0],dp[i][1]);
//         }
//         //cout << "? " << i << " " << dp[i][0] << " " << dp[i][1] << "\n";
//     }
//     ans += min(dp[n/2][0],dp[n/2][1]);
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


/*B. Sakurako and Water*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int g[510][510];
// void solve(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= n; j++){
//             cin >> g[i][j];
//         }
//     }
//     vector<int> ans;
//     for(int i = 1; i <= n; i++){
//         int x = i, y = 1;
//         int maxcnt = 0;
//         while(x <= n && y <= n){
//             if(g[x][y] < 0) maxcnt = min(maxcnt,g[x][y]);
//             x++,y++;
//         }
//         if(maxcnt < 0) ans.push_back(maxcnt);
//     }
//     for(int j = 2; j <= n; j++){
//         int x = 1, y = j;
//         int maxcnt = 0;
//         while(x <= n && y <= n){
//             if(g[x][y] < 0) maxcnt = min(maxcnt,g[x][y]);
//             x++,y++;
//         }
//         if(maxcnt < 0) ans.push_back(maxcnt);
//     }
//     int sum = 0;
//     for(auto t: ans){
//         sum -= t;
//     }
//     cout << sum << "\n";
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


/*A. Sakurako and Kosuke*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     int turn = 0;
//     int pos = 0;
//     while(-n <= turn && turn <= n){
//         if(turn % 2 == 0){
//             pos = 2*(-turn) - 1;
//         }
//         else{
//             pos = 2*turn - 1;
//         }
//         turn++;
//     }
//     if(turn & 1) cout << "Sakurako\n";
//     else cout << "Kosuke\n";
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
