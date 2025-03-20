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

/*D. Iris and Game on the Tree*/
/*2024.10.8 题解*/ //规律 + 博弈论
//先找到01串的规律
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// int in[N];
// void solve(){
//     memset(in,0,sizeof in);
//     int n;cin >> n;
//     for(int i = 1; i <= n - 1; i++){
//         int u,v;cin >> u >> v;
//         in[u]++;
//         in[v]++;
//     }
//     string s;cin >> s;
//     s = " " + s;
//     int cnt1 = 0, cnt2 = 0;
//     int cnt3 = 0;
//     int cnt4 = 0,cnt5 = 0;
//     bool isroot = s[1] == '?' ? 1 : 0;
//     for(int i = 2; i < s.size(); i++){
//         if(in[i] == 1 && s[i] == '?'){
//             cnt1++;
//         }
//         else if(s[i] == '?') cnt2++;
//         else if(!isroot && in[i] == 1 && s[1] != s[i]) cnt3++;
//         else if(isroot && in[i] == 1){
//             if(s[i] == '1') cnt4++;
//             else if(s[i] == '0') cnt5++;
//         }
//     }
//     if(!isroot){
//         int ans = (cnt1+1)/2 + cnt3;
//         cout << ans << "\n";
//     }
//     else{
//         //A先手 
//         int ans1 = max(cnt4,cnt5) + cnt1 / 2;
//         //d先手
//         int ans2 = min(cnt4,cnt5) + (cnt1 + 1) / 2;
//         int ans = ans1;
//         //考虑交换先手
//         if(ans2 > ans1) {
//             if(cnt2 & 1) ans = ans2;
//             else ans = ans1;
//         }
//         cout << ans << "\n";
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

/*C. Dora and C++*/
/*2024.10.8 题解*/ //极差最小化（精）
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// ll c[N];
// ll gcd(ll a,ll b){
//     return b ? gcd(b,a%b) : a;
// }
// void solve(){
//     ll n,a,b; cin >> n >> a >> b;
//     int ff = gcd(a,b);
//     for(int i = 1; i <= n; i++){
//         cin >> c[i];
//         c[i] %= ff; //将数组的数移动到一个标准数附近
//     }
//     sort(c + 1,c+1+n);
//     ll ans = c[n] - c[1];
//     for(int i = 1; i < n; i++){
//         ans = min(ans,c[i] + ff - c[i+1]); //此时c[i]+ff 为最大 ，c[i+1]为最小
//     }
//     cout << ans << "\n";
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


/*B. Index and Maximum Value*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// ll a[N];
// void solve(){
//     int n;cin >> n;
//     int q;cin >> q;
//     ll ans = 0;
//     for(int i = 1; i <= n; i++){
//         ll x; cin >> x;
//         ans = max(x,ans);
//     }   
//     for(int i = 1; i <= q; i++){
//         char ch;int l,r;
//         cin >> ch >> l >> r;
//         if(ch == '+'){
//            if(l <= ans && r >= ans) ans++;
//         }
//         else if(ch == '-'){
//             if(l <= ans && r >= ans) ans--;
//         }
//         a[i] = ans;
//     }
//     for(int i = 1; i <= q; i++){
//         cout << a[i] << " ";
//     }cout << "\n";
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


/*A. Dora's Set*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int x,y;cin >> x >> y;
//     int len = y - x + 1;
//     int ans = 0;
//     if(len < 3){
//         cout << 0 << "\n";
//         return;
//     }
//     if(x & 1){
//         ans += 1;
//         len -= 3;
//     }
//     cout << ans + len / 4 << "\n";
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
