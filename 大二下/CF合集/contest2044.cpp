//Codeforces Round 993 (Div. 4)

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

/*E. Insane Problem*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int k,l1,r1,l2,r2;cin >> k >> l1 >> r1 >> l2 >> r2;
//     vector<ll> a;
//     ll sum = k;
//     //cout << "bug1\n";
//     while(sum <= 1e9){
//         a.push_back(sum);
//         sum *= k;
//     }
//     //cout << "bug2\n";
//     ll ans = 0;
//     for(int i = 0; i < a.size(); i++){
//         ll l = (l2 + a[i] - 1) / a[i];
//         ll r = (r2) / a[i];
//        // cout << "! " << l << " " << r << "\n";
//         l = max((ll)l1,l);
//         r = min((ll)r1,r);
//         //cout << "? " << l << " " << r << "\n";
//         if(r < l) continue;
//         ans += r - l + 1;
//     }
//     ans += max(0,min(r1,r2)-max(l1,l2)+1);
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

/*D. Harder Problem*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     vector<int> a(n+1);
//     for(int i = 1; i<= n; i++) cin >> a[i];
//     map<int,bool> mp;
//     vector<int> b;
//     for(int i = 1; i <= n; i++){
//         if(!mp[a[i]]){
//             b.push_back(a[i]);
//             mp[a[i]] = 1;
//         } 
//     }
//     for(int i = 1; i <= n; i++){
//         if(!mp[i]) b.push_back(i);
//     }
//     for(int i = 0; i < n; i++) cout << b[i] << " ";
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

/*C. Hard Problem*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     ll m,a,b,c;cin >> m >> a >> b >> c;
//     ll cnt1 = max(0ll,m-a);
//     ll cnt2 = max(0ll,m-b);
//     ll ans = min(cnt1+cnt2,c) + min(m,a) + min(m,b);
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

/*B. Normal Problem*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     string s;cin >> s;
//     for(int i = 0; i < s.size(); i++){
//         if(s[i] == 'q') s[i] = 'p';
//         else if(s[i] == 'p') s[i] = 'q';
//     }
//     reverse(s.begin(),s.end());
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

/*A. Easy Problem*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     cout << n-1 << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }
