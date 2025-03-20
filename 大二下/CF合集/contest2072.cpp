//Codeforces Round 1006 (Div. 3)

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

/*F. Goodbye, Banker Life*/
/*2025.3.6*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// void solve(){
//     int n,k;cin >> n >> k;
//     for(int i = 0; i < n; i++){
//         cout << (((n-1)&i) == i ? k : 0) << " \n"[i == n-1]; //条件表达式，i == n-1时换行，" \n"[01]作为了一个数组
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

/*E Do You Love Your Hero and His Two-Hit Multi-Target Attacks?*/
/*2025.3.6 题解*/ //一行一行放就可以了
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// void solve(){
//     int k;cin >> k;
//     int x = 0;int y = 0;
//     int tmp = k;
//     vector<PII> ans;
//     while(tmp){
//         int a = 0;
//         while((a + 1)*a/2 <= tmp) a++;
//         int len = x + a - 1;
//         for( ;x <= len; x++){
//             ans.push_back({x,y});
//         }
//         tmp -= (a-1)*a/2;
//         y++;
//     }
//     cout << ans.size() << "\n";
//     for(auto t : ans) cout << t.first << " " << t.second << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*D For Wizards, the Exam Is Easy, but I Couldn't Handle It*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// struct{
//     int l,r,num;
// }ans;
// void solve(){
//     int n;cin >> n;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++) cin >> a[i];
//     ans = {0,0,0};
//     for(int i = 0; i < a.size(); i++){
//         int tmp = 0;
//         for(int j = i+1; j < a.size(); j++){
//             if(a[i] > a[j]) tmp++;
//             else if(a[i] < a[j]) tmp--;
//             if(tmp > ans.num){
//                 ans.l = i,ans.r = j,ans.num = tmp;
//             }
//         }
//     }
//     cout << ans.l + 1 << " " << ans.r +1 << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*C Creating Keys for StORages Has Become My Main Skill*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// void solve(){
//     int n,x;cin >> n >> x;
//     vector<int> ans(n);int len = 0;
//     int tmp = 0;
//     while(len < n){
//         if((len | tmp) <= x){
//             tmp = len | tmp;
//             ans[len] = len;
//             len++;
//         }
//         else break;
//     }
//     if(len == n && tmp == x){
//         for(auto t : ans) cout << t << " ";
//         cout << "\n";
//     }else{
//         len = 0;tmp = 0;
//         while(len < n){
//             if((len | x) <= x){
//                 tmp = len | tmp;
//                 ans[len] = len;
//                 len++;
//             }
//             else break;
//         }
//         while(len < n){
//             ans[len] = x;
//             len++;
//         }
//         if(tmp < x) ans[n-1] = x;
//         for(auto t : ans) cout << t << " ";
//         cout << "\n";
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

/*B Having Been a Treasurer in the Past, I Help Goblins Deceive */
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// void solve(){
//     int n;cin >> n;
//     string s;cin >> s;
//     map<char,int> mp;
//     for(int i = 0; i < s.size(); i++) mp[s[i]]++;
//     cout << 1ll * mp['_'] * (mp['-'] - (mp['-'] / 2)) * (mp['-'] / 2) << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*A New World, New Me, New Array*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define PII pair<int,int>
// void solve(){
//     int n,k,p;cin >> n >> k >> p;
//     if(k < 0){
//         p = -p;
//         if(n*p > k){
//             cout << -1 << "\n";
//             return;
//         }
//         cout << abs((k+p+1) / p) << "\n";
//     }else{
//         if(n*p < k){
//             cout << -1 << "\n";
//             return;
//         }
//         cout << (k+p-1) / p << "\n";
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