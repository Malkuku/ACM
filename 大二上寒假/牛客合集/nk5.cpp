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


/*C 小L的位运算*/
/*2025.2.28*/ //贪心+注意力惊人
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,x,y;cin >> n >> x >> y;
//     ll ans = 0;
//     string a,b,c;cin >> a >> b >> c;
//     int sum[4] = {0};
//     for(int i = 0; i < n; i++){
//         if(c[i] == '1' && a[i] == b[i] && a[i] == '1'){
//             sum[0]++;
//         }else if(c[i] == '1' && a[i] == b[i] && a[i] == '0'){
//             sum[1]++;
//         }else if(c[i] == '0' && a[i] != b[i] && a[i] == '1'){
//             sum[2]++;
//         }else if(c[i] == '0' && a[i] != b[i] && a[i] == '0'){
//             sum[3]++;
//         }
//     }
//     sort(sum,sum+4);
//     if(x*2 <= y){
//         ans = 1ll*(sum[0]+sum[1]+sum[2]+sum[3])*x;
//     }else{
//         if(sum[3] >= sum[0]+sum[1]+sum[2]){
//             bool flag = (sum[0]+sum[1]+sum[2]) % 2;
//             ans = 1ll*(sum[3]-sum[0]+sum[1]+sum[2])*x 
//                 + 1ll*(sum[0]+sum[1]+sum[2])/2*y
//                 + 1ll*flag*x;
//         }else{
//             bool flag = (sum[0]+sum[1]+sum[2]+sum[3]) % 2;
//             ans = 1ll*(sum[0]+sum[1]+sum[2]+sum[3])/2*y
//                 + 1ll*flag*x;
//         }
//     }
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
/*2025.2.28 WA*/ //苦痛DP 
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e6+10;
// ll dp[N][2][3]; //匹配到i; a/b; 0没交换，1拿到0，2拿到1
// void solve(){
//     int n,x,y; cin >> n >> x >> y;
//     string a,b,c;cin >> a >> b >> c;
//     a = " " + a;
//     b = " " + b;
//     c = " " + c;
//     for(int i = 0; i <= n; i++){
//         dp[i][0][0] = dp[i][0][1] = dp[i][0][2] = 1e18;
//         dp[i][1][0] = dp[i][1][1] = dp[i][1][2] = 1e18;
//     }
//     dp[0][0][0] = dp[0][1][0] = 0;
//     for(int i = 1; i <= n; i++){
//         if(c[i] == '1' && a[i] == b[i] && a[i] == '0'){
//             dp[i][0][0] = min({
//                 dp[i][0][0],
//                 dp[i-1][0][0] + x,
//                 dp[i-1][1][0] + x,
//                 dp[i-1][0][2],
//             });
//             dp[i][1][0] = min({
//                 dp[i][1][0],
//                 dp[i-1][0][0] + x,
//                 dp[i-1][1][0] + x,
//                 dp[i-1][1][2],
//             });
//             dp[i][0][1] = min({
//                 dp[i][0][1],
//                 dp[i-1][0][0] + y,
//             });
//             dp[i][1][1] = min({
//                 dp[i][1][1],
//                 dp[i-1][1][0] + y,
//             });
//             dp[i][0][2] = dp[i-1][0][2];
//             dp[i][1][2] = dp[i-1][1][2];
//         }else if(c[i] == '1' && a[i] == b[i] && a[i] == '1'){
//             dp[i][0][0] = min({
//                 dp[i][0][0],
//                 dp[i-1][0][0] + x,
//                 dp[i-1][1][0] + x,
//                 dp[i-1][0][1],
//             });
//             dp[i][1][0] = min({
//                 dp[i][1][0],
//                 dp[i-1][0][0] + x,
//                 dp[i-1][1][0] + x,
//                 dp[i-1][1][1],
//             });
//             dp[i][0][2] = min({
//                 dp[i][0][2],
//                 dp[i-1][0][0] + y,
//             });
//             dp[i][1][2] = min({
//                 dp[i][1][2],
//                 dp[i-1][1][0] + y,
//             });
//             dp[i][0][1] = dp[i-1][0][1];
//             dp[i][1][1] = dp[i-1][1][1];
//         }else if(c[i] == '0' && a[i] != b[i] && a[i] == '0'){ //a-0 b-1
//             dp[i][0][0] = min({
//                 dp[i][0][0],
//                 dp[i-1][0][0] + x,
//                 dp[i-1][1][0] + x,
//                 dp[i-1][0][2],
//             });
//             dp[i][1][0] = min({
//                 dp[i][0][0],
//                 dp[i-1][0][0] + x,
//                 dp[i-1][1][0] + x,
//                 dp[i-1][1][1],
//             });
//             dp[i][0][1] = min({
//                 dp[i][0][1],
//                 dp[i-1][0][0] + y,
//             });
//             dp[i][1][2] = min({
//                 dp[i][1][2],
//                 dp[i-1][1][0] + y,
//             });
//             dp[i][0][2] = dp[i-1][0][2];
//             dp[i][1][1] = dp[i-1][1][1];
//         }else if(c[i] == '0' && a[i] != b[i] && a[i] == '1'){ //a-1 b-0
//             dp[i][0][0] = min({
//                 dp[i][0][0],
//                 dp[i-1][0][0] + x,
//                 dp[i-1][1][0] + x,
//                 dp[i-1][0][1],
//             });
//             dp[i][1][0] = min({
//                 dp[i][0][0],
//                 dp[i-1][0][0] + x,
//                 dp[i-1][1][0] + x,
//                 dp[i-1][1][2],
//             });
//             dp[i][0][2] = min({
//                 dp[i][0][2],
//                 dp[i-1][0][0] + y,
//             });
//             dp[i][1][1] = min({
//                 dp[i][1][1],
//                 dp[i-1][1][0] + y,
//             });
//             dp[i][0][1] = dp[i-1][0][1];
//             dp[i][1][2] = dp[i-1][1][2];
//         }else{
//            dp[i][0][0] = dp[i-1][0][0];
//            dp[i][0][1] = dp[i-1][0][1];
//            dp[i][0][2] = dp[i-1][0][2];
//            dp[i][1][0] = dp[i-1][1][0];
//            dp[i][1][1] = dp[i-1][1][1];
//            dp[i][1][2] = dp[i-1][1][2];
//         }
//         //cout << "? " << n << " " << dp[i][0] << " " << dp[i][1] << "\n";
//     }
//     cout << min(dp[n][0][0],dp[n][1][0]) << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*E 小L的井字棋*/ //rz了
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     char mp[5][5];
//     int res = 0;
//     for(int i = 1; i <= 3; i++){
//         for(int j = 1; j <= 3; j++){
//             cin >> mp[i][j];
//             if(mp[i][j] == 'X') res++;
//         }
//     }
//     if(res == 0 || res == 1 || res == 2){
//         cout << "Yes\n";
//         return;
//     }else{
//         for(int i = 1; i <= 3; i++){
//             int cnt = 0,cha = 0;
//             for(int j = 1; j <= 3; j++){
//                 if(mp[i][j] == 'O') cnt++;
//                 else if(mp[i][j] == 'X') cha++;
//             }
//             if(cnt == 0 && cha > 0){
//                 cout << "Yes\n";
//                 return;
//             }
//         }
//          for(int i = 1; i <= 3; i++){
//             int cnt = 0,cha = 0;
//             for(int j = 1; j <= 3; j++){
//                 if(mp[j][i] == 'O') cnt++;
//                 else if(mp[j][i] == 'X') cha++;
//             }
//             if(cnt == 0 && cha > 0){
//                 cout << "Yes\n";
//                 return;
//             }
//         }
//         int cnt = 0,cha = 0;
//         for(int i = 1,j = 1;i <= 3; i++,j++){
//             if(mp[i][j] == 'O') cnt++;
//             else if(mp[i][j] == 'X') cha++;
//         }
//         if(cnt == 0 && cha > 0){
//             cout << "Yes\n";
//             return;
//         }
//         cnt = 0,cha = 0;
//         for(int i = 1,j = 3;i <= 3; i++,j--){
//             if(mp[i][j] == 'O') cnt++;
//             else if(mp[i][j] == 'X') cha++;
//         }
//         if(cnt == 0 && cha > 0){
//             cout << "Yes\n";
//             return;
//         }
//         cout << "No\n";
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

/*I 小L的数学题*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,m;
//     cin >> n >> m;
//     int num1 = 0;int num2 = 0;
//     if((n == 0 || m == 0) && n != m){
//         cout << "No\n";
//     }
//     else cout << "Yes\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*J 小L的汽车行驶问题*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     string s; cin >> s;
//     ll ans = 0;
//     int num = 0;
//     bool flag = 0;
//     ll yuan = 0;
//     for(int i = 0; i < s.size(); i++){
//         if(flag){
//             num = yuan;
//             flag = 0;
//         } 
//         if(s[i] == '0'){
//             num += 10;
//         }
//         else if(s[i] == '1'){
//             num -= 5;
//             num = max(0,num);
//         }
//         else{
//             flag = 1;
//             yuan = num;
//             num -= 10;
//             num = max(0,num);
//         }
//         ans += num;
//     }
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

/*B 小L出师了*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,t,k;cin >> n >> t >> k;
//     int num = (n-k) / t;
//     cout << min(num,k+1) << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*A 小L的三则运算*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     ll n;cin >> n;
//     char ch;cin >> ch;
//     if(ch == '+'){
//         cout << n-1 << " " << 1 << "\n";
//     }else if(ch == '-'){
//         cout << n + 1 << " " << 1 << "\n";
//     }else{
//         cout << n << " " << 1 << "\n";
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