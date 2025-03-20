//Codeforces Round 991 (Div. 3)

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



/*E. Three Strings*/
/*2025.3.19*/ //easyDP
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e3+10;
// int dp[N][N];
// void solve(){
//     string a,b,c;cin >> a >> b >> c;
//     a = " " + a;
//     b = " " + b;
//     c = " " + c;
//     memset(dp,0x3f,sizeof dp);
//     dp[0][0] = 0;
//     for(int i = 0; i < a.size(); i++){
//         for(int j = 0; j < b.size(); j++){
//             if(i+j == 0)continue;
//             if(i > 0 && a[i] == c[i+j]){
//                 dp[i][j] = min(dp[i][j],dp[i-1][j]);
//             }
//             if(j > 0 && b[j] == c[i+j]){
//                 dp[i][j] = min(dp[i][j],dp[i][j-1]);
//             }
//             if(i > 0)dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
//             if(j > 0)dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
//         }
//     }
//     cout << dp[a.size()-1][b.size()-1] << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*D. Digital string maximization*/
/*2025.3.19*/ //其实就是枚举，只是没敢去写
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     string s;cin >> s;
//     int n = s.size();
//     for(int i = 0; i < n; i++){
//         int pos = min(n-1,i+9);
//         int now = pos;
//         int maxw = 0;
//         for(int j = pos; j >= i; j--){
//             if(s[j] - (j - i) >= maxw){
//                 maxw = s[j] - (j - i);
//                 now = j;
//             }
//         }
//         if(now == i) continue;
//         for(int j = now; j > i; j--){
//             s[j]--;
//             swap(s[j],s[j-1]);
//         }
//     }
//     cout << s << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*C. Uninteresting Number*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void dfs(int x,int num,int res1,int res2,vector<pair<int,int>>& vc){
//     if(num > x) return;
//     if(num == x){
//         vc.push_back({res1,res2});
//         return;
//     }
//     dfs(x,num+2,res1+1,res2,vc);
//     dfs(x,num+6,res1,res2+1,vc);
// }
// void solve(){
//     string s;cin >> s;
//     map<char,int> mp;
//     ll sum = 0;
//     for(int i = 0; i < s.size(); i++){
//         mp[s[i]]++;
//         sum += s[i] - '0';
//     }
//     int cnt = 9 - (sum % 9);
//     //cout << "? " << cnt << " " << sum << " " << mp['2'] << " " << mp['3']<< "\n";
//     if(cnt == 9){
//         cout << "YES\n";
//     }else{
//         for(int i = 0; i <= 3; i++){
//             vector<pair<int,int>> vc;
//             dfs(cnt+i*9,0,0,0,vc);
//             for(int j = 0; j < vc.size(); j++){
//                 if(mp['2'] >= vc[j].first && mp['3'] >= vc[j].second){
//                     cout << "YES\n";
//                     return;
//                 }
//             }
//         }
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

/*B. Transfusion*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     ll sum1 = 0,sum2 = 0;
//     vector<int> a(n+1);
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//         if(i&1) sum1 += a[i];
//         else sum2 += a[i];
//     }
//     int ji = (n+1)/2;
//     int ou = n/2;
//     if(sum1 % ji || sum2 % ou || sum1/ji != sum2/ou){
//         cout << "NO\n";
//     }else cout << "YES\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*A. Line Breaks*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,m;cin >> n >> m;
//     vector<string> arr(n+1);
//     for(int i = 1; i <= n; i++){
//         cin >> arr[i];
//     }
//     int sum = 0;
//     int cnt = 0;
//     for(int i = 1; i <= n; i++){
//         if(sum + arr[i].size() <= m){
//             sum += arr[i].size();
//             cnt++;
//         }else break;
//     }
//     cout << cnt << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }
