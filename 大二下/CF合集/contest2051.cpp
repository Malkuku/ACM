//Codeforces Round 995 (Div. 3)

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

/*E. Best Price*/
/*2025.3.11 题解*/ //其实还是二分，想少了几步
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,k;cin >> n >> k;
//     vector<int> a(n+1);
//     vector<int> b(n+1);
//     vector<int> c(2*n+1);
//     for(int i = 1;i <= n; i++) {
//         cin >> a[i];
//         c[i] = a[i];
//     }
//     for(int i = 1; i <= n; i++){
//         cin >> b[i];
//         c[i+n] = b[i];
//     }
//     sort(a.begin()+1,a.end());
//     sort(b.begin()+1,b.end());
//     sort(c.begin()+1,c.end());
//     ll ans = 0;
//     for(int i = 1; i <= 2*n; i++){
//         int buy = n - (lower_bound(b.begin()+1,b.end(),c[i]) - b.begin() - 1);
//         int good = n - (lower_bound(a.begin()+1,a.end(),c[i]) - a.begin() - 1);
//         int bad = buy - good;
//         if(bad <= k){
//             ans = max(ans,1ll*c[i]*buy);
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

/*D. Counting Pairs*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;ll x,y;cin >> n >> x >> y;
//     vector<ll> a(n+1);
//     ll sum = 0;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//         sum += a[i];
//     }
//     sort(a.begin()+1,a.end());
//     ll ans = 0;
//     for(int i = 1; i <= n; i++){
//         auto find1 = [&](){
//             int l = i,r = n+1;
//             while(l + 1 < r){
//                 int mid = (l+r) >> 1;
//                 if(a[mid] <= sum-x-a[i]) l = mid;
//                 else r = mid;
//             }
//             return r;
//         };
//         auto find2 = [&](){
//             int l = i,r = n + 1;
//             while(l + 1 < r){
//                 int mid = (l+r) >> 1;
//                 if(a[mid] >= sum-y-a[i]) r = mid;
//                 else l = mid;
//             }
//             return l;
//         };
//         //cout << "? " << i << " " << sum-x-a[i] << " " << sum - y - a[i] 
//         //<< " " << find1() << " " << find2() << "\n";
//         ans += find1() - find2() - 1;
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

/*C. Preparing for the Exam*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,m,k;cin >> n >> m >> k;
//     vector<int> a(m+1);
//     for(int i = 1; i <= m; i++) cin >> a[i];
//     vector<int> b(k+1);
//     for(int i = 1; i <= k; i++) cin >> b[i];
//     map<int,bool> mp1;
//     for(int i = 1; i <= k; i++){
//         mp1[b[i]] = 1;
//     }
//     map<int,bool> mp2;
//     for(int i = 1; i <= n; i++){
//         if(!mp1[i]) mp2[i] = 1;
//     }
//     for(int i = 1; i <= m; i++){
//         if(mp2[a[i]] && k >= n-1) cout<<"1";
//         else if(k >= n) cout << "1";
//         else cout << "0";
//     }cout << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*B. Journey*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,a,b,c;
//     cin >> n >> a >> b >> c;
//     ll sum = (a + b + c);
//     ll cnt = n / sum * 3;
//     ll tmp = n % sum;
//     int res = 0;
//     while(tmp > 0){
//         if(res == 0) tmp -= a;
//         if(res == 1) tmp -= b;
//         if(res == 2) tmp -= c;
//         res++;
//         res %= 3;
//         cnt++;
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

/*A Preparing for the Olympiad*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     vector<int> a(n+1);
//     vector<int> b(n+1);
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
//     for(int i = 1; i <= n; i++){
//         cin >> b[i];
//     }
//     vector<int> c(n+1);
//     for(int i = 1; i < n; i++){
//         c[i] = a[i] - b[i+1];
//     }
//     c[n] = a[n];
//     ll sum = 0;
//     for(int i = 1; i <= n; i++){
//         if(c[i] > 0) sum += c[i];
//     }
//     cout << sum << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }