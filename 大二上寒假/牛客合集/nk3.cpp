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

/*E 智乃的小球*/
/*2025.2.28*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,k;cin >> n >> k;
//     vector<ll> zuo;
//     vector<ll> you;
//     for(int i = 0; i < n; i++){
//         int p,v;
//         cin >> p >> v;
//         if(v == -1){
//             zuo.push_back(p*2);
//         }else{
//             you.push_back(p*2);
//         }
//     }
//     sort(zuo.begin(),zuo.end());
//     sort(you.begin(),you.end());
//     ll l = -1,r = 2e9+1;
//     while(l + 1 < r){
//         auto check = [&](ll x){
//             ll sum = 0;
//             auto find = [&](ll l,ll r){
//                 return upper_bound(zuo.begin(),zuo.end(),r) - lower_bound(zuo.begin(),zuo.end(),l);
//             };
//             for(auto t : you) sum += find(t,t + 2*x);
//             return sum >= k;
//         };
//         ll mid = (l+r) >> 1;
//         if(check(mid)) r = mid;
//         else l = mid;
//     }
//     if(r >= 2e9) cout << "No\n";
//     else {
//         cout << "Yes\n";
//         cout << fixed << setprecision(6) << r / 2.0 << "\n";
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }
/*2025.2.27 题解*/
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main()
// {
//     int n,k;
//     cin >> n >> k;
//     vector<int> A,B;
//     for(int i=1;i<=n;i++) 
//     {
//         int p,v;
//         cin >> p >> v;
//         p*=2;
//         if(v==1) A.push_back(p);
//         else B.push_back(p);
//     }
//     sort(A.begin(),A.end());
//     sort(B.begin(),B.end());
//     auto check=[&](int t)
//     {
//         auto get=[&](int l,int r)
//         {
//             return upper_bound(B.begin(),B.end(),r)-lower_bound(B.begin(),B.end(),l);
//         };
//         int sum=0;
//         for(auto x:A)
//         {
//             sum+=get(x,x+2*t);
//         }
//         return sum>=k;
//     };
//     int l=-1,r=2e9+1;
//     while(l+1<r){
//         int mid=(l+r)>>1;
//         if(check(mid)) r=mid;
//         else l=mid;
//     }
//     if(!check(r)) puts("No");
//     else 
//     {
//         puts("Yes");
//         printf("%.6lf\n",1.0*r/2);
//     }
//     return 0;
// }
/*2025.2.25*/ //二分答案，转化问题 -- 沟槽的二分，真的沟槽
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// ll zuo[N];
// ll you[N];
// void solve(){
//     int n,k;cin >> n >> k;
//     int len_zuo = 0;
//     int len_you = 0;
//     for(int i = 0; i < n; i++){
//         ll p,v;cin >> p >> v;
//         if(v == -1){
//             zuo[len_zuo++] = p*2;
//         }else{
//             you[len_you++] = p*2;
//         }
//     }
//     sort(zuo,zuo+len_zuo);
//     sort(you,you+len_you);
//     zuo[len_zuo] = 2e9+1;
//     you[len_you] = 2e9+1;
//     //cout << n << "\n";
//     //for(int i = 0; i < len_zuo; i++) cout << zuo[i] << " ";
//     //cout << "\n";
//     //for(int i = 0; i < len_you; i++) cout << you[i] << " ";
//     //cout << "\n";
//     ll l = -1,r = 2e9 + 1;
//     while(l+1 < r){
//         ll mid = (l+r) >> 1;
//         auto find = [&](){
//             ll sum = 0;
//             for(int i = 0; i < len_you; i++){
//                 auto find2 = [&](ll l,ll r,ll x){
//                     while(l+1 < r){
//                         cout << "???? " << l << " " << r << " " << "\n";
//                         ll mid = (l + r) >> 1;
//                         if(zuo[mid] > x) r = mid;
//                         else l = mid; 
//                     }
//                     return r;
//                 };
//                 auto find3 = [&](ll l,ll r,ll x){
//                     while(l+1 < r){
//                         ll mid = (l + r) >> 1;
//                         if(zuo[mid] < x) l = mid;
//                         else r = mid; 
//                     }
//                     return l;
//                 };
//                 ll l = -1,r = len_zuo+1;
//                 ll dix = you[i] + mid*2;
//                 cout << "?? " << l << " " << r << " " << dix << " " << you[i] << "\n";
//                 cout << "???" <<  find2(l,r,dix) << " " << max(0ll,find3(l,r,you[i])) << "\n";
//                 sum += find2(l,r,dix) - max(0ll,find3(l,r,you[i])) - 1;
//             }
//             //cout << "? " << l << " " << r << " " << sum << "\n";
//             if(sum >= k) return true;
//             else return false;
//         };
//         if(find()){
//             r = mid;
//         }else{
//             l = mid;
//         }
//     }
//     if(r <= 2e9){
//         cout << "Yes\n";
//         cout << fixed << setprecision(6) << r / 2.0 << "\n";
//     }else{
//         cout << "No\n";   
//     }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*C 智乃的Notepad(Easy version)*/
/*2025.2.25*/ //按直觉来，就是字典序，想复杂了
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,m;cin >> n >> m;
//     vector<string> arr(n+1);
//     for(int i = 0; i < n; i++) cin >> arr[i];
//     int l,r;cin >> l >> r;
//     sort(arr.begin(),arr.end());
//     auto cmp = [&](string a,string b){
//         int len = min(a.size(),b.size());
//         int cnt = 0;
//         for(int i = 0;i < len; i++){
//             if(a[i] == b[i]) cnt++;
//             else return cnt;
//         }
//         return cnt;
//     };
//     ll sum = arr[0].size();
//     ll cha = 0;
//     int maxn = arr[0].size();
//     for(int i = 1; i < arr.size(); i++){
//         int cnt = cmp(arr[i-1],arr[i]);
//         sum += arr[i].size();
//         cha += cnt;
//         maxn = max(maxn,(int)arr[i].size());
//     }
//     cout << 2*(sum - cha) - maxn << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*L 智乃的三角遍历*/ //大模拟
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     stack<int> st;
//     int pos = 1;
//     int cnt = 1;
//     int res = 0;
//     n++;
//     vector<int> arr;
//     while(res < n-1){
//         for(int i = 1; i <= n - res; i++){
//             st.push(pos);
//             //cout << pos << "\n";
//             arr.push_back(pos);
//             if(i != n - res){
//                 pos += cnt;
//                 cnt++;
//             }
//         }
//         while(st.size()){
//             auto t = st.top();st.pop();
//             if(!st.size()){
//                 break;
//             } 
//             pos = t + 1;
//             cnt--;
//             //cout << t << " " << pos << "\n";
//              arr.push_back(t);
//               arr.push_back(pos);
//         }
//         res++;
//         cnt++;
//     }
//     for(int i = 1; i <= n; i++){
//         //cout << pos << " ";
//          arr.push_back(pos);
//         pos -= cnt;
//         cnt--;
//     }
//     arr.erase(unique(arr.begin(),arr.end()),arr.end());
//     for(auto t : arr) cout << t << " ";
//     cout << "\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*M 智乃的牛题*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     string s;cin >> s;
//     map<char,int> mp;
//     for(auto t : s){
//         mp[t]++;
//     }
//     if(mp['n'] >= 1
//         && mp['o'] >= 2
//         && mp['w'] >= 1
//         && mp['c'] >= 1
//         && mp['d'] >= 1
//         && mp['e'] >= 1
//         && mp['r'] >= 1){
//             cout << "happy new year\n";
//         }else{
//             cout << "I AK IOI\n";
//         }
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*A 智乃的博弈游戏*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n;cin >> n;
//     if(n & 1) cout << "Yes\n";
//     else cout << "No\n";
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*F 智乃的捉迷藏*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
//     int n,a,b,c;cin >> n >> a >> b >> c;
//     if(n*2 >= a + b + c && a + b + c >= n){
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
