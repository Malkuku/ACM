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

/*D. Attribute Checks*/
/**/
/*2024.10.19 题解1*/ //双指针+dp
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e6 + 10;
// int a[N];
// void solve(){
//     int n,m;cin >> n >> m;
//     for(int i = 0; i < n; i++) cin >> a[i];
//     //f[i] : s用i个技能点,t用s-i个技能点
//     vector<int> f(m+1),g(m+1);
//     //通过数前缀和
//     vector<int>s(m+1),t(m+1);
//     //当前的record个数 //双指针
//     int x = 0;
//     int l = 0;
//     while(l < n && a[l] != 0) l++;
//     while(l < n){
//         //找到下一个0
//         int r = l + 1;
//         while(r < n && a[r] != 0){
//             if(a[r] > 0) t[a[r]]++;
//             else s[-a[r]]++;
//             r++;
//         }
//         for(int i = 1; i <= m; i++){
//             s[i] += s[i-1];
//             t[i] += t[i-1];
//         }
//         //枚举s用的技能点数
//         for(int i = 0; i <= x+1; i++){
//             //给T加点
//             g[i] = f[i]; //i不变
//             //给S加点
//             if(i > 0) g[i] = max(g[i],f[i-1]); //i从i-1转移
//             //计算当前应该给谁加点
//         }
//         x++;
//         //加上新增的pass
//         for(int i = 0; i <= x; i++){
//             f[i] = g[i] + s[i] + t[x - i];//枚举点数
//         }
//         for(int i = 0; i <= m; i++) s[i] = t[i] = 0;
//         l = r;
//     }
//     int ans = 0;
//     for(int i = 0; i <= m; i++) ans = max(ans,f[i]);
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }

/*C. New Game*/
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 2e5+10;
// int a[N];
// struct node{
//     int x;
//     int num;
// };
// void solve(){
//     int n,k;cin >> n >> k;
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     sort(a + 1,a + 1 + n);
//     int len = -1;
//     int pos = -1;
//     vector<node> arr;
//     for(int i = 1; i <= n; i++){
//         if(pos != a[i]){
//             arr.push_back({a[i],1});
//             len++;
//             pos = a[i];
//         }
//         else{
//             arr[len].num++;
//         }
//     }
//     //for(int i = 0; i < arr.size(); i++){
//     //    cout << "? " << arr[i].x << " " << arr[i].num << "\n";
//     //}
//     int l = 0;
//     int ans = 0;
//     int sum = 0;
//     for(int r = 0; r < arr.size(); r++){
//         sum += arr[r].num;
//         int len = r - l;
//         if(arr[r].x - len != arr[l].x){
//             l = r;
//             sum = arr[r].num;
//         }
//         len = r - l;
//         if(len+1 > k){
//             sum -= arr[l].num;
//             l++;
//         }
//         ans = max(ans,sum);
//         //cout <<"? " << r << " " << sum << "\n";
//     }
//     cout << ans << "\n";
// }
// signed main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }

/*B. Binomial Coefficients, Kind Of*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int mod = 1e9+7;
// const int N = 1e5+10;
// ll a[N],b[N];
// ll kms(ll a, ll b){
//     ll ans = 1;
//     while(b){
//         if(b & 1){
//             ans = (ans * a) % mod;
//         }
//         a = (a*a) % mod;
//         b >>= 1;
//     }
//     return ans;
// }
// void solve(){
//     int n;cin >> n;
//     ll maxa = 0,maxb = 0;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
//     for(int i = 1; i <= n; i++){
//         cin >> b[i];
//     }
//     for(int i = 1; i <= n; i++){
//         ll sum = kms(2,b[i]);
//         cout << sum << "\n";
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     for(int _  = 1; _ <= t; _++){
//         solve();
//     }
//     return 0;
// }

/*A. Two Screens*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     string s1,s2;cin >> s1 >> s2;
//     int len = 0;
//     for(int i = 0; i < s1.size(); i++){
//         if(s1[i] == s2[i]) len++;
//         else break;
//     }
//     if(len > 0) len--;
//     cout << s1.size() + s2.size() - len << "\n";
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