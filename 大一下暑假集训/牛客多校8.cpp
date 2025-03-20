#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*A Haitang and Game*/ //求一个数组能产生的gcd数字的总数
/*2024.8.12*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+3;
// int gcd(int a,int b){
//     return b ? gcd(b,a%b) : a;
// }
// bool a[N];
// int main(){
//    int t;cin >> t;
//    while(t--){
//         int n;cin >> n;
//         memset(a,0,sizeof a);
//         for(int i = 0; i < n; i++){
//             int x;cin >> x;
//             a[x] = 1;
//         }
//         int ans = 0;
//         for(int i = 1; i <= N; i++){
//             int g = 0;
//             for(int j = i; j <= N; j+=i){
//                 if(a[j]){
//                     g = gcd(g,j);
//                 }
//             }
//             if(g == i) ans++;
//         }
//         if((ans-n)%2) cout << "dXqwq\n";
//         else cout << "Haitang\n";
//    }
// }

/*E Haitang and Math*/
/*2024.8.14*/ //将因数分解优化为质因数分解
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll n;
// const int N = 1e6+10;
// int primes[N];
// bool st_primes[N];
// int primes_len = 0;
// unordered_map<ll,int> mp;
// void init(){ // 获取质数表
//     for(int i = 2; i <= N; i++){
//         if(!st_primes[i]){
//             primes[++primes_len] = i;
//         }
//         for(int j = 1; primes[j] <= N/i; j++){
//             st_primes[primes[j] * i] = 1;
//             if(i % primes[j] == 0) break;
//         } 
//     }
// }
// vector<pair<ll,int>> st_g[115];
// ll g[115]; int len_g = 0;
// int ans = 0;
// bool check(int x,ll now){
//     ll tmp = now;
//     ll sum = 0;
//     while(tmp){
//         sum += tmp % 10;
//         tmp /= 10;
//     }
//     if(n % now == sum) return 1;
//     else return 0;
// }
// void dfs(int x,ll now,int step){
//     if(step == st_g[x].size()){
//         if(mp[now]) return;
//         mp[now] = 1;
//         if(check(x, now)){
//             ans++;
//         } 
//         return;
//     }
//     dfs(x,now,step+1);
//     for(int i = 1; i <= st_g[x][step].second; i++) now*=st_g[x][step].first,dfs(x,now,step+1);
// }
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     int t;cin >> t;
//     init();
//     while(t--){
//         ans = 0,len_g = 0;
//         cin >> n;
//         mp.clear();
//         ll l=max(n-109,1ll),r=n,size=r-l+1;
//         for(int i = 1; i <= size; i++){
//             g[i] = n-i+1;
//             st_g[i].clear();
//         }
//         //cout << i << " " << len_g << "\n";
//         for(int i = 1; i <= primes_len; i++){
//             int x = n%primes[i]+1;
//             if(x > size) continue;
//             for(int j = x; j <= size; j += primes[i]){
//                 if(g[j] % primes[i] == 0){
//                     int cnt = 0;
//                     while(g[j] % primes[i] == 0) {
//                         g[j] /= primes[i];
//                         cnt++;
//                     }
//                     //cout << g[i] << " " << primes[j] << " "<< cnt << "\n";
//                     st_g[j].push_back({primes[i],cnt});
//                 }
//             }
//         }
//         for(int i = 1; i <= size; i++){
//              if(g[i] > 1) st_g[i].push_back({g[i],1}); //它是比1e6大的质数
//         }
//     //cout << i << " " << len_g << "\n";
//         //cout << "???\n";
//         for(int i = 1; i <= size; i++){
//             //cout << i<< "\n";
//             dfs(i,1,0);
//         }
//         cout << ans << "\n";
//     } 
//     return 0;
// }