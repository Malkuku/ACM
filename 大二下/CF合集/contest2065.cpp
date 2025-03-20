//Codeforces Round 1003 (Div. 4)

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
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

/*F Skibidus and Slay*/


/*E Skibidus and Rizz */
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// void solve(){
//     int n,m,k;cin >> n >> m >> k;
//     bool flag = 0;
//     if(n < m) {
//         flag = 1;
//         swap(n,m);
//     }
//     if(n - m > k || n < k){
//         cout << -1 << "\n";
//         return;
//     }
//     string s;
//     for(int i = 1; i <= k; i++){
//         s += '0';
//     }
//     for(int i = 1; i <= min(n - k,m); i++){
//         s += "10";
//     }
//     if(n - k > m){
//         for(int i = 1; i <= n-k-m; i++){
//             s += '0';
//         }
//     }else{
//         for(int i = 1; i <= m - (n-k); i++){
//             s += '1';
//         }
//     }
//     if(flag) for(int i = 0; i < s.size(); i++) s[i] = s[i] == '0' ? '1' : '0';
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

/*D Skibidus and Sigma*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// const int N = 2e5+10;
// pair<ll,ll> a[N];ll b[N],sum_b[N];
// void solve(){
//     int n,m;cin >> n >> m;
//     for(int i = 1; i <= n; i++){
//         a[i] = {0,0};
//         for(int j = 1; j <= m; j++){
//             int x;cin >> x;
//             b[j] = x;
//         }
//         for(int j = 1; j <= m; j++) sum_b[j] = sum_b[j-1] + b[j];
//         for(int j = 1; j <= m; j++) a[i].first += sum_b[j];
//         a[i].second = sum_b[m];
//     }
//     sort(a+1,a+1+n,[](auto x,auto y){return x.second > y.second;});
//     ll ans = 0;
//     //for(int i = 1; i <= n; i++){
//     //    cout << "? " << a[i].first << " " << a[i].second << "\n";
//     //}
//     for(int i = 1; i <= n; i++){
//         ans += a[i].first + a[i].second*(n-i)*m;
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

/*C2 Skibidus and Fanum Tax (hard version)*/
/*2025.3.4*/ 
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// const int N = 2e5+10;
// ll a[N],b[N],c[N];
// void solve(){
//    int n,m;cin >> n >> m;
//    for(int i = 0; i < n; i++) cin >> a[i];
//    for(int i = 0; i < m; i++) cin >> b[i];
//    sort(b,b+m);
//    a[0] = min(a[0],b[0] - a[0]);
//    auto find = [&](ll x,ll y){
//         int l = -1,r = m;
//         while(l + 1 < r){
//             int mid = (l + r) >> 1;
//             if(b[mid] - x >= y) r = mid;
//             else l = mid;
//         }
//         return r;
//    };
//    for(int i = 1; i < n; i++){
//         if(a[i] >= a[i-1]){ //找最小的b[j] - a[i]满足>=a[i-1]
//             int index = find(a[i],a[i-1]);
//             if(index >= 0 && index < m) a[i] = min(a[i],b[index] - a[i]);
//         }
//         else{ //找最小的b[j] - a[i]满足>=a[i-1]
//             int index = find(a[i],a[i-1]);
//             if(index >= 0 && index < m) a[i] = max(a[i],b[index] - a[i]);
//         }; 
//     }
//     for(int i = 1; i < n; i++) if(a[i-1] > a[i]){
//         cout << "No\n";
//         return;
//     }  
//     cout << "Yes\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*C1 Skibidus and Fanum Tax (easy version) */ //要先理清所有的情况
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// const int N = 2e5+10;
// ll a[N],b[N],c[N];
// void solve(){
//    int n,m;cin >> n >> m;
//    for(int i = 0; i < n; i++) cin >> a[i];
//    for(int i = 0; i < m; i++) cin >> b[i];
//    a[0] = min(a[0],b[0] - a[0]);
//    for(int i = 1; i < n; i++){
//         if(b[0] - a[i] >= a[i-1] && a[i] >= a[i-1]) a[i] = min(a[i],b[0] - a[i]);
//         else if(b[0] - a[i] >= a[i-1] || a[i] >= a[i-1]) a[i] = max(a[i],b[0] - a[i]); 
//     }
//     //for(int i = 0; i < n; i++) cout << a[i] << " " ;
//     //cout << "\n"; 
//     for(int i = 1; i < n; i++) if(a[i-1] > a[i]){
//         cout << "No\n";
//         return;
//     }  
//     cout << "Yes\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*B Skibidus and Ohio */
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// void solve(){
//     string s;cin >> s;
//     for(int i = 0; i < s.size()-1; i++){
//         if(s[i] == s[i+1]) {
//             cout << 1 << "\n";
//             return;
//         }
//     }
//     cout << s.size() << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*A Skibidus and Amog'u*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// void solve(){
//     string s;cin >> s;
//     s.erase(s.size() - 2,2);
//     s += 'i';
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
