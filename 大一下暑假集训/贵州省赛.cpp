#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*问题 I: 寻找宝藏数 */
/*2024.7.18*/ //WA
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll dp[1010][12][12][12][2][2]; //dp[pos][i][j][k][lead][limit]
// int n;
// int num[1010];
// const int N = 1e4+10;
// bool vis[N];
// int primes[N];
// map<int,bool> mp;
// void getPrimes(){
//     int cnt = 0;
//     cout << "?4\n";
//     for(int i = 2; i < N; i++){
//         if(!vis[i]) primes[cnt++] = i;
//         for(int j = 0; primes[j] < N / i; j++){
//             vis[primes[j]*i] = 1;
//             if(i % primes[j] == 0) break;
//         }
//     }
//     for(int i = 0; i < cnt; i++) mp[primes[i]] = 1;
// }
// const int MOD = 1e9 + 7;
// void init(){
//     cout << "?2" << "\n";
//     getPrimes();
//     cout << "?3\n";
//     for(int i = 0; i < 10; i++){
//         for(int j = 0; j < 10; j++){
//             for(int k = 0; k < 10; k++){
//                 for(int z = 0; z < 10; z++){
//                     ll shu = z + k * 10 + j * 100 + i * 1000;
//                     if(mp[shu] == 0) {
//                         if (dp[4][i][j][k][!i][0] == -1)
//                             dp[4][i][j][k][!i][0]++;
//                         dp[4][i][j][k][!i][0]++;
//                     }
//                 }
//                 //cout << "! " << dp[4][i][j][k][!i][0] << "\n";
//             }
//         }
//     }
// }
// ll dfs(int pos,int p1,int p2,int p3,bool lead,bool limit){
//    // cout << "?1 " << "\n";
//     ll ans = 0;
//     if(!pos) return dp[pos][p1][p2][p3][lead][limit];
//     if(dp[pos][p1][p2][p3][lead][limit] != -1) 
//         return dp[pos][p1][p2][p3][lead][limit]; 
//     int up = limit ? num[pos] : 9;
//     for(int i = 0; i <= up; i++){
//         ll shu = i + p1*10 + p2*100 +p3*1000;
//         if(mp[shu] == 0) ans += dfs(pos-1,i,p1,p2,lead && i == 0,limit && i == up) % MOD;
//     }
//     dp[pos][p1][p2][p3][lead][limit] = ans % MOD;
//     cout << "! "<< pos << " " << dp[pos][p1][p2][p3][lead][limit] << "\n";
//     return ans % MOD;
// }
// ll solve(int len){
//     memset(dp,-1,sizeof dp);
//     init();
//     ll ans = dfs(len+1,0,0,0,1,0) % MOD;
//     return ans;
// }
// int main(){
//     cin >> n;
//     cout << solve(n) << "\n";
//     return 0;
// }
/*2024.7.18*/ //dp递推
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int n;
// const int N = 1010;
// const int MOD = 1e9+7;
// ll dp[N][12][12][12];
// bool vis[10010];
// int primes[10010];
// map<int,bool> mp;
// void getPrimes(){
//     int cnt = 0;
//     memset(primes,-1,sizeof primes);
//     for(int i = 2; i <= 10010; i++){
//         if(!vis[i]) primes[cnt++] = i;
//         for(int j = 0; primes[j] <= 10010/i; j++){
//             vis[primes[j]*i] = 1;
//             if(i % primes[j] == 0) break;
//         }
//     }
//     for(int i = 0; i < cnt; i++){
//         mp[primes[i]] = 1;
//     }
// }
// void init(){
//     for(int i = 1; i < 10; i++){
//         for(int j = 0; j < 10; j++){
//             for(int k = 0; k < 10; k++){
//                 for(int z = 0; z < 10; z++){
//                     int shu = i * 1000 + j * 100 + k * 10 + z;
//                     if(mp[shu] == 0)dp[4][i][j][k]++;
//                 }
//             }
//         }
//     }
// }
// int main(){
//     cin >> n;
//     getPrimes();
//     init();  
//     for(int i = 5; i <= n; i++){
//         for(int j = 1; j < 10; j++){
//             for(int k = 1; k < 10; k++){
//                 for(int z = 0; z < 10; z++){
//                     for(int l = 0; l < 10; l++){
//                         int shu = j * 1000 + k * 100 + z * 10 + l;
//                         if (mp[shu] == 0) {
//                             dp[i][j][k][z] += dp[i - 1][k][z][l];
//                             dp[i][j][k][z] %= MOD;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     ll ans = 0;
//     for (int i = 1; i < 10; i++)
//     {
//         for (int j = 0; j < 10; j++)
//         {
//             for (int k = 0; k < 10; k++)
//             {
//                 ans += dp[n][i][j][k];
//                 ans %= MOD;
//             }
//         }
//     }
//     cout << ans << "\n";
//     return 0;
// }