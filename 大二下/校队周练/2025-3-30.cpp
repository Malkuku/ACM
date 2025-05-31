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

/*E GDUT = 1*/
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
void solve(){
    map<char,ll> mp;
    string s;cin >> s;
    s+='+';
    ll x;cin >> x;
    string tmp = "";
    map<char,bool> flag;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+'){
            int cnt = 0;
            for(int j = tmp.size()-1; j >= 0; j--){
                cnt++;
                if(cnt >= 18) flag[tmp[j]] = 1;
                if(!flag[tmp[j]]){
                    //cout <<  "! " << tmp[j] << "\n";
                    mp[tmp[j]] += pow(10,cnt-1);
                }
                if(mp[tmp[j]] > 1e18){
                    flag[tmp[j]] = 1;
                }
            }
            tmp = "";
        }
        else{
            tmp += s[i];
        }
    }
    //cout << "? " << mp['G'] << " " << mp['D'] << " " << mp['U'] << " " << mp['T'] << "\n";
    //cout << "? " << flag['G'] << " " << flag['D'] << " " << flag['U'] << " " << flag['T'] << "\n";
    for(int i = 0; i <= (flag['G'] ? 0 : 9); i++){
        ll ans = mp['G']*i;
        if(ans > x) break;
        for(int j = 0; j <= (flag['D'] ? 0 : 9); j++){
            ans += mp['D']*j;
            if(ans > x) break;
            for(int k = 0;k <= (flag['U'] ? 0 : 9); k++){
                ans += mp['U']*k;
                if(ans > x) break;
                for(int p = 0; p <= (flag['T'] ? 0 : 9); p++){
                    //cout << i << " " << j << " " << k << " " << p << '\n';
                    ans += mp['T']*p;
                    if(ans == x){
                        cout << "YES\n";
                        cout << i << " " << j << " " << k << " " << p << '\n';
                        return;
                    }
                    if(ans > x) break;
                    ans -= mp['T']*p;
                }
                ans -= mp['U']*k;
            }
            ans -= mp['D']*j;
        }
        ans -= mp['G']*i;
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;cin >> t;
    while(t--){
        solve();
    }
}

/*I 好想成为人类啊*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long 
// #define PII pair<int,int>
// void solve(){
//     int n,m;cin >> n >> m;
//     string s,t;cin >> s >> t;
//     int ans = 0;
//     for(int i = 0; i < s.size(); i++){
//         if(i + t.size() > s.size()) break;
//         string tmp = s.substr(i,t.size());
//         cout << "? " << tmp << "\n";
//         if(tmp == t){
//             ans++;
//             i = i+t.size();
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

/*G Jump Sort*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 5e5+10;
// int cnt = 0;
// ll primes[N];
// bool isprime[N];
// void init(){
//     for(int i = 2; i < N; i++){
//         if(!isprime[i]) primes[cnt++] = i;
//         for (int j = 0; primes[j] <= N / i; j++) { //枚举质数
//     		isprime[primes[j] * i] = 1;
//             if (i % primes[j] == 0) break; //这个数的最小质因子
//         }
//     }
// }
// void solve(){
//     int n;cin >> n;
//     vector<int> a(n+1);
//     for(int i = 1;i <= n; i++){
//         cin >> a[i];
//     }
//     unordered_map<int,int> mp;
//     int res = 0;
//     for(int i = 1; i <= n; i++){
//         int x = abs(a[i] - i);
//         if(x == 0){
//             res++;
//             continue;
//         }
//         auto fj = [&](int x){
//             for(int i = 1; i * i <= x ; i++){
//                 if(x % i == 0){
//                     if(x/i == i) mp[i]++;
//                     else mp[i]++,mp[x/i]++;
//                 }
//             }
//         };
//         fj(x);
//     }
//     int ans = 0;
//     for(int i = 1; i <= n; i++){
//         if(mp[i] + res == n) ans++;
//     }
//     cout << ans << '\n';
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t = 1;//cin >> t;
//     //init();
//     while(t--){
//         solve();
//     }
// }

/*H 可爱串串*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 2e5+10;
// ll pre1[N],pre0[N],dst1[N],dst0[N];
// void solve(){
//     int n;cin >> n;
//     string s;cin >> s;
//     s = " " + s;
//     for(int i = 1; i <= n; i++){
//         dst1[i] = dst1[i-1] + (s[i] == '1');
//         dst0[i] = dst0[i-1] + (s[i] == '0');
//     }
//     pre1[n+1] = 0,pre0[n+1] = 0;
//     for(int i = n; i >= 1; i--){
//         pre1[i] = pre1[i+1] + (s[i] == '1');
//         pre0[i] = pre0[i+1] + (s[i] == '0');
//     }
//     ll ans = -1e18;
//     for(int i = 1; i <= n-1; i++){
//         ll dst = (dst1[i] - dst0[i]);
//         ll pre = (pre1[i+1] - pre0[i+1]);
//         //cout << "? "<< i << " " << dst << " " << pre << "\n";
//         ans = max(ans,dst*pre);
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