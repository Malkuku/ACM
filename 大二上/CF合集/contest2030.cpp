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

/*D. QED's Favorite Permutation*/
// //! L|R
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+10;
// int a[N];
// int pre[N],nex[N]; //以i结尾的最大值，以i开头的最小值
// void solve(){
//     int n,q;cin >> n >> q;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     } 
//     pre[0] = a[0];
//     for(int i = 1; i < n; i++) pre[i] = max(a[i],pre[i-1]);
//     nex[n-1] = a[n-1];
//     for(int i = n-2; i >= 0; i--) nex[i] = min(a[i],nex[i+1]);
//     string s;cin >> s;
//     set<int> target;
//     for(int i = 0; i < s.size()-1; i++){
//         if(s[i] == 'L' && s[i+1] == 'R' && (pre[i] > i + 1 || nex[i+1] < i + 2)){
//             target.insert(i);
//         }
//     }
//     while(q--){
//         int pos;cin >> pos;
//         s[pos-1] = s[pos-1] == 'R' ? 'L' : 'R';
//         if(target.count(pos-1)) {
//             target.erase(pos-1);
//         }
//         if(target.count(pos-2)) {
//             target.erase(pos-2);
//         } 
//         if(pos-1 < s.size()-1 && pos-1 >= 0 && s[pos-1] == 'L' && s[pos] == 'R' && (pre[pos-1] > pos-1 + 1 || nex[pos] < pos-1 + 2)) target.insert(pos-1);
//         else if(pos-2 < s.size()-1 && pos-2 >= 0 && s[pos-2] == 'L' && s[pos-1] == 'R'&& (pre[pos-2] > pos-2 + 1 || nex[pos-1] < pos-2 + 2)) target.insert(pos-2);
//         if(target.size()) cout << "NO\n";
//         else cout << "YES\n";
//     }
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

/*C. A TRUE Battle*/ //注意审题
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     string s;cin >> s;
//     if(s[0] == '1' || s[n-1] == '1'){
//         cout << "Yes\n";
//         return;
//     }
//     for(int i = 1; i + 1< n; i++){
//         if(s[i] == '1' && s[i+1] == '1'){
//             cout << "Yes\n";
//             return;
//         }
//     }
//     cout << "No\n";
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

/*B. Minimise Oneness*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     string s = "010";
//     if(n == 1) cout << "0\n";
//     else if(n == 2) cout << "01\n";
//     else if(n == 3) cout << "010\n";
//     else{
//         for(int i = 4; i <= n; i++){
//             s += '0';
//         }
//         cout << s << "\n";
//     }
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

/*A. A Gift From Orangutan*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int a[1010];
// void solve(){
//     int n;cin >> n;
//     for(int i = 1; i <= n; i++)cin >> a[i];
//     sort(a+1,a+1+n);
//     swap(a[1],a[2]);
//     swap(a[1],a[n]);
//     int sum = 0;
//     int b = a[1];
//     int c = a[1];
//     for(int i = 1; i <= n; i++){
//         b = min(a[i],b);
//         c = max(a[i],c);
//         sum += c - b;
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
