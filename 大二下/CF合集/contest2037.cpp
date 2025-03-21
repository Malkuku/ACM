//Codeforces Round 988 (Div. 3)

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

/**/

/*D. Sharky Surfing*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,m,L;cin >> n >> m >> L;
//     vector<pair<int,int>> arr;
//     for(int i = 1; i <= n; i++){
//         int x,y;cin >> x >> y;
//         arr.push_back({x,y-x+1});
//     }
//     vector<pair<int,int>> power;
//     for(int i = 1; i <= m; i++){
//         int x,y;cin >> x >> y;
//         power.push_back({x,y});
//     }
//     int len = 0;
//     ll v = 1;
//     priority_queue<int> q;
//     int ans = 0;
//     for(int i = 0; i < arr.size(); i++){
//         while(len < power.size() && power[len].first < arr[i].first){
//             //cout << "? " << power[len].first << " " << power[len].second << " " << len << "\n";
//             q.push(power[len].second);
//             len++;
//         }
//         while(q.size() && v <= arr[i].second){
//             v += q.top();q.pop();
//             ans++;
//         }
//         if(v <= arr[i].second){
//             cout << -1 << "\n";
//             return;
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

/*C. Superultra's Favorite Permutation*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     vector<int> a;
//     if(n < 5){
//         cout << -1 << "\n"; 
//         return;
//     } 
//     for(int i = 1; i <= n; i+=2){
//         a.push_back(i);
//     }
//     for(int i = 2; i <= n; i+=2){
//         a.push_back(i);
//     }
//     int pos = (n-1)/2;
//     swap(a[2],a[pos]);
//     swap(a[pos+1],a[pos+2]);
//     for(auto t : a)cout << t << " ";
//     cout << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*B. Intercepted Inputs*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     map<int,int> mp;
//     for(int i = 0; i < n; i++){
//         int x;cin >> x;
//         mp[x]++;
//     }
//     int len = n - 2;
//     for(auto t : mp){
//         if(len % t.first == 0){
//             if(mp[len/t.first]){
//                 if(len/t.first != t.first){
//                     cout << t.first << " " << len/t.first << "\n";
//                     return;
//                 }else{
//                     if(t.second >= 2){
//                         cout << t.first << " " << t.first << "\n";
//                         return;
//                     }
//                 }
//             }
//         }
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

/*A. Twice*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     map<int,int> mp;
//     for(int i = 0; i < n;i++){
//         int x;cin >> x;
//         mp[x]++;
//     }
//     int ans = 0;
//     for(auto t : mp){
//         ans += t.second/2;
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