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


/*D Tokitsukaze and Concatenate‌ Palindrome*/
/*2025.2.28*/ //模拟 -- 细节-最小值
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,m;cin >> n >> m;
//     string a,b;cin >> a >> b;
//     a = " " + a;
//     b = " " + b;
//     if(n < m) swap(a,b),swap(n,m);
//     bool flag = (n+m) % 2;
//     int pos = (n-m + 1) / 2 + m;
//     ll size = n-m;
//     map<char,int> mp1,mp2;
//     for(int i = 1; i <= n; i++) mp1[a[i]]++;
//     for(int i = 1; i <= m; i++) mp2[b[i]]++;
//     for(int i = 0; i < 26; i++){
//         int tmp = min(mp1['a'+i],mp2['a'+i]);
//         mp1['a'+i] -= tmp;
//         mp2['a'+i] -= tmp;
//     }
//     ll balance = 0;
//     for(auto t : mp1){
//         balance += (t.second / 2)*2;
//     }
//     ll res = 0;
//     for(auto t : mp2) res += t.second;
//     //cout << "? " << res << " " << flag << " " << balance << " " << size << "\n";
//     cout << max(0ll,(ll)res + max(0ll,(size - flag - balance)/2)) << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*C Tokitsukaze and Balance String (hard)*/
/*2025.2.28*/ //注意力惊人
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     string s;cin >> s;
//     int res = 0;
//     int mod = 1e9+7;
//     if(s.size() == 1){
//         if(s[0] == '?') cout << 2 << "\n";
//         else cout << 1 << "\n";
//         return;
//     }
//     for(int i = 1; i < s.size()-1; i++) if(s[i] == '?') res++;
//     ll ans = 0;
//     if(s[0] == s[s.size()-1] && s[0] != '?') ans = s.size()-2;
//     else if(s[0] != s[s.size()-1] && s[0] != '?' && s[s.size()-1] != '?') ans = 2;
//     else if(s[0] == s[s.size()-1] && s[0] == '?') ans = 2*(s.size());
//     else if(s[0] != s[s.size()-1] && (s[0] == '?' || s[s.size()-1] == '?')) ans = s.size();
//     while(res>0){
//         res--;
//         ans*=2;
//         ans %= mod;
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

/*B Tokitsukaze and Balance String (easy)*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void dfs(string s,int index,vector<string>& arr){
//     if(index == s.size()){
//         arr.push_back(s);
//         return;
//     }
//     if(s[index] == '?'){
//         s[index] = '1';
//         dfs(s,index+1,arr);
//         s[index] = '0';
//         dfs(s,index+1,arr);
//     }else dfs(s,index+1,arr);
// }
// void solve(){
//     int n;cin >> n;
//     string s; cin >> s;
//     vector<string> arr;
//     dfs(s,0,arr);
//     int ans = 0;
//     //for(auto t: arr) cout << t << "\n";
//     for(int i = 0; i < arr.size(); i++){
//         int ly = 0,yl = 0;
//         for(int j = 0; j < arr[i].size()-1; j++){
//             if(arr[i][j] == '0' && arr[i][j+1] == '1') ly++;
//             if(arr[i][j] == '1' && arr[i][j+1] == '0') yl++;
//         }
//         for(int j = 0; j < arr[i].size(); j++){
//             if(j == 0){
//                 int cnt_ly = 0,cnt_yl = 0;
//                 string tmp = arr[i].substr(j,2);
//                 if(tmp == "11"){
//                     cnt_ly++;
//                 }else if(tmp == "10"){
//                     cnt_yl--;
//                 }else if(tmp == "01"){
//                     cnt_ly--;
//                 }else if(tmp == "00"){
//                     cnt_yl++;
//                 }
//                 if(ly + cnt_ly == yl + cnt_yl) ans++;
//             }else if(j == arr[i].size()-1){
//                int cnt_ly = 0,cnt_yl = 0;
//                 string tmp = arr[i].substr(j-1,2);
//                 if(tmp == "11"){
//                     cnt_yl++;
//                 }else if(tmp == "10"){
//                     cnt_yl--;
//                 }else if(tmp == "01"){
//                     cnt_ly--;
//                 }else if(tmp == "00"){
//                     cnt_ly++;
//                 }
//                 if(ly + cnt_ly == yl + cnt_yl) ans++;
//             }else{
//                 int cnt_ly = 0,cnt_yl = 0;
//                 string tmp = arr[i].substr(j-1,3);
//                 if(tmp == "111"){
//                     cnt_ly++;
//                     cnt_yl++;
//                 }else if(tmp == "110"){
//                     cnt_yl++;
//                     cnt_yl--;  
//                 }else if(tmp == "101"){
//                     cnt_yl--;
//                     cnt_ly--;
//                 }else if(tmp == "100"){
//                     cnt_yl--;
//                     cnt_yl++;
//                 }else if(tmp == "000"){
//                     cnt_ly++;
//                     cnt_yl++;
//                 }else if(tmp == "001"){
//                     cnt_ly++;
//                     cnt_ly--;
//                 }else if(tmp == "010"){
//                     cnt_yl--;
//                     cnt_ly--;
//                 }else if(tmp == "011"){
//                     cnt_ly--;
//                     cnt_ly++;
//                 }
//                 if(ly + cnt_ly == yl + cnt_yl) ans++;
//             }
//         }
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

/*E Tokitsukaze and Dragon's Breath*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e3+10;
// int mp[N][N];
// ll zuo[N][N];
// ll you[N][N];
// void solve(){
//     int n,m;cin >> n >> m;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++) cin >> mp[i][j];
//     }
//     for(int i = 0; i < n; i++){
//         int x = i,y = 0;
//         vector<pair<int,int>> arr;
//         ll sum = 0;
//         while(x < n && x >= 0 && y < m && y >= 0){
//             arr.push_back({x,y});
//             sum += mp[x][y];
//             x--;y++;
//         }
//         for(auto t : arr) zuo[t.first][t.second] = sum;
//     }
//     for(int j = 1; j < m; j++){
//         int x = n-1,y = j;
//         vector<pair<int,int>> arr;
//         ll sum = 0;
//         while(x < n && x >= 0 && y < m && y >= 0){
//             arr.push_back({x,y});
//             sum += mp[x][y];
//             x--;y++;
//         }
//         for(auto t : arr) zuo[t.first][t.second] = sum;
//     }
//     for(int i = 0; i < n; i++){
//         int x = i,y = 0;
//         vector<pair<int,int>> arr;
//         ll sum = 0;
//         while(x < n && x >= 0 && y < m && y >= 0){
//             arr.push_back({x,y});
//             sum += mp[x][y];
//             x++;y++;
//         }
//         for(auto t : arr) you[t.first][t.second] = sum;
//     }
//     for(int j = 1; j < m; j++){
//         int x = 0,y = j;
//         vector<pair<int,int>> arr;
//         ll sum = 0;
//         while(x < n && x >= 0 && y < m && y >= 0){
//             arr.push_back({x,y});
//             sum += mp[x][y];
//             x++;y++;
//         }
//         for(auto t : arr) you[t.first][t.second] = sum;
//     }
//     ll ans = 0;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             ans = max(ans,zuo[i][j] + you[i][j] - mp[i][j]);
//         }
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

/*I Tokitsukaze and Pajama Party*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     string s; cin >> s;
//     string cmp = "uwawauwa";
//     int sum = s[0] == 'u';
//     ll ans = 0;
//     for(int i = 1; i < s.size()-1; i++){
//         if(s.substr(i+1,cmp.size()) == cmp){
//             ans += sum;
//         }
//         if(s[i] == 'u') sum++;
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

/*K Tokitsukaze and Shawarma*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int x,y,z;cin >> x >> y >> z;
//     int a,b,c;cin >> a >> b >> c;
//     cout << max({a*x,b*y,c*z});
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }
