//Codeforces Round 1009 (Div. 3)

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

/*C. XOR and Triangle*/
/*2025.3.19 题解*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int x; cin >> x;
//     int cnt = 0;
//     for(int i = x; i > 0; i >>= 1){
//         cnt++;
//     }cnt--;
//     int y = (1 << cnt) - 1;
//     int z = x^y;
//     if(y + x > z && y + z > x && x + z > y && y > 0 && z > 0){
//         cout << y << "\n";
//     }else{
//         cout << -1 << "\n";
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

/*B. The Third Side*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     ll sum = 0;
//     for(int i = 0; i < n; i++){
//         int x;cin >> x;
//         sum += x;
//     }
//     cout << sum - n + 1 << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*A. Draw a Square*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int l,r,d,u;cin >> l >> r >> d >> u;
//     if(l == r && r == d && d == u){
//         cout << "Yes\n";
//     }else{
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