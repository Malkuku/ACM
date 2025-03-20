#include<bits/stdc++.h>
using namespace std; 
#define ll long long

/*F. Sakurako's Box*/
/*2024.9.12*/
// #include<bits/stdc++.h>
// using namespace std; 
// #define ll long long
// const int N = 2e5+10;
// int mod = 1e9 + 7;
// ll arr[N];
// ll sum[N];
// ll kms(ll a,ll b){
//     ll ans = 1;
//     a %= mod;
//     while(b){
//         if(b&1) ans = (ans*a)%mod;
//         a = (a*a)%mod;
//         b >>= 1;
//     }
//     return ans;
// }
// int main(){
//     ios::sync_with_stdio(0);
//     int t;cin >> t;
//     while(t--){
//         int n;cin >> n;
//         for(int i = 1; i <= n; i++){
//             cin >> arr[i];
//             arr[i] %= mod;
//             sum[i] = sum[i-1] + arr[i];
//             sum[i] %= mod;
//         }
//         ll b = (1ll*n*(n-1)/2) % mod;
//         ll a = 0;
//         for(int i = 1; i <= n; i++){
//             a = (a + ((arr[i] % mod)*((sum[n]-sum[i]+mod)%mod))%mod)%mod;
//         }
//         //cout << a << " " << b << "\n";
//         ll ans = ((a%mod) * (kms(b,mod-2)%mod))%mod;
//         cout << ans << '\n';
//     }
//     return 0;
// }

/*D. Sakurako's Hobby*/
/*2024.9.12*/
// #include<bits/stdc++.h>
// using namespace std; 
// #define ll long long
// const int N = 2e5+5;
// int a[N];
// int b[N];
// bool st[N];
// int ans[N];
// int main(){
//     ios::sync_with_stdio(0);
//     int t;cin >> t;
//     while(t--){
//         memset(st,0,sizeof st);
//         int n;cin >> n;
//         for(int i = 1; i <= n; i++){
//             cin >> a[i];
//         }
//         string s;cin >> s;
//         for(int i = 1; i <= n; i++){
//             if(s[i-1] == '0') b[i] = 1;
//             else b[i] = 0;
//         }
//         for(int i = 1; i <= n; i++){
//             if(st[i]) continue;
//             vector<int> arr;
//             int pos = i;
//             int tmp = a[i];
//             arr.push_back(i);
//             st[i] = 1;
//             int sum = b[i];
//             while(pos != tmp){
//                 arr.push_back(tmp);
//                 st[tmp] = 1;
//                 sum+=b[tmp];
//                 tmp = a[tmp];
//             }
//             for(auto t : arr){
//                 ans[t] = sum;
//             }
//         }
//         for(int i = 1; i <= n; i++){
//             cout << ans[i] << " ";
//         }cout << "\n";
//     }
//     return 0;
// }

/*C. Longest Good Array*/
/*2024.9.12*/
// #include<bits/stdc++.h>
// using namespace std; 
// #define ll long long
// const int N = 1e6+10;
// ll sum[N];
// int main(){
//     sum[0] = 0;
//     int cnt = 1;
//     for(int i = 1; i < N; i++){
//         sum[i] = sum[i-1] + i;
//        // if(i < 100)cout << sum[i] << "\n";
//     }
//     int t;cin >> t;
//     while(t--){
//         ll l,r;cin >> l >> r;
//         for(int i = 1; i < N; i++){
//             if(sum[i] >= r - l + 1){
//                 cout << i << "\n";
//                 break;
//             }
//         }
//     }
//     return 0;
// }

/*B Square or Not */
/*2024.9.12*/
// #include<bits/stdc++.h>
// using namespace std; 
// #define ll long long
// int check(int x){
//     for(int i = 1; i <= 10000; i++){
//         if(x == i*i) return i;
//         else if(x < i*i) return -1;
//     }
//     return -1;
// }
// int main(){
//     int t;cin >> t;
//     while(t--){
//         int n;cin >> n;
//         string s; cin >> s;
//         int cnt = check(n);
//         if(cnt == -1){
//             cout << "No\n";
//         }
//         else{
//             bool flag = 1;
//             for(int i = 0; i < cnt; i++){
//                 for(int j = 0; j < cnt; j++){
//                     int pos = i*cnt + j;
//                     if(i == 0 || i == cnt - 1){
//                         if(s[pos] != '1') {
//                             flag = 0;
//                             break;
//                         }
//                     }
//                     else{
//                         if(j == 0 || j == cnt-1){
//                             if(s[pos] != '1'){
//                                 flag = 0;
//                                 break;
//                             }
//                         }
//                         else{
//                             if(s[pos] != '0'){
//                                 flag = 0;
//                                 break;
//                             }
//                         }
//                     }
//                 }
//             }
//             if(flag) cout << "Yes\n";
//             else cout << "No\n";
//         }
//     }
//     return 0;
// }

/*A. Sakurako's Exam*/
/*2024.9.12*/
// #include<bits/stdc++.h>
// using namespace std; 
// int main(){
//     int t;cin >> t;
//     while(t--){
//         int a,b;
//         cin >> a >> b;
//         if(a & 1) cout << "No\n";
//         else if(b & 1 && a == 0) cout << "No\n";
//         else cout << "Yes\n";
//     }
//     return 0;
// }

/*E Alternating String */
/*2024.9.11*/
// int ssum[(int)2e5+5][27][2]; // 0ji 1ou
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     while(t--){
//         int n;cin >> n;
//         string s;cin >> s;
//         s = " " + s;
//         int sum = n;
//         for(int i = 1; i <= n; i++){
//             for(int j = 0; j < 27; j++){
//                 if(s[i] - 'a' == j){
//                     ssum[i][j][i%2] = ssum[i-1][j][i%2] + 1;
//                 }
//                 else ssum[i][j][i%2] = ssum[i-1][j][i%2];
//                 ssum[i][j][(i+1)%2] = ssum[i-1][j][(i+1)%2];
//             }
//         }
//         if(n%2 == 0){
//             int maxji = 0,maxou = 0;
//             for(int i = 0; i < 27; i++){
//                 maxji = max(maxji,ssum[n][i][0]);
//                 maxou = max(maxou,ssum[n][i][1]);
//             }
//             cout << sum - maxji - maxou << "\n";
//         }
//         else{
//             int ans = 0x3f3f3f3f;
//             for(int i = 1; i <= n; i++){
//                 int ji = 0,ou = 0;
//                 for(int j = 0; j < 27; j++){
//                     ji = max(ji,ssum[i-1][j][0] + ssum[n][j][1] - ssum[i][j][1]);
//                     ou = max(ou,ssum[i-1][j][1] + ssum[n][j][0] - ssum[i][j][0]);
//                 }
//                 ans = min(ans,sum - ou - ji);
//             }
//             cout << ans << "\n";
//         }
//     }
//     return 0;
// }