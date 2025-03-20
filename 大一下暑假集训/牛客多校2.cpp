#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*H Instructions Substring*/
/*2024.7.22*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>
const int N = 2e5+10;
int n,x,y;
PII sum[N];
map<PII,int> mp;
PII check(char ch){
    if(ch == 'W') return {0,1};
    if(ch == 'S') return {0,-1};
    if(ch == 'A') return {-1,0};
    if(ch == 'D') return {1,0};
}

int main(){
    ios::sync_with_stdio(0);
    string s;
    cin >> n >> x >> y >> s;
    s = " " + s;
    int ans = 0;
 
    for(int i = 1; i <= n; i++){
        PII tmp = check(s[i]);
        sum[i] = {tmp.first+sum[i-1].first,tmp.second+sum[i-1].second};
    }
    for(int i = n; i >= 0; i--){
        if(x == 0 && y == 0 && i == 0) break;
        mp[{sum[i].first, sum[i].second}] = n - i + 1; //先入
        if (mp.count({sum[i].first + x, sum[i].second + y})) ans += mp[{sum[i].first + x, sum[i].second + y}];
    }
    cout << ans << "\n";
    return 0;
}

/*C Red Walking on Grid*/
/*2024.7.19*/ //其实转移方程还是很好想的
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e6+10;
// ll dp[N][3]; //dp[pos][up/down] 
// char g[N][2];
// int main(){
//     ios::sync_with_stdio(0);
//     int n; cin >> n;
//     for(int j = 0; j < 2; j++){
//         for (int i = 1; i <= n; i++){
//             cin >> g[i][j];
//         }
//     }
//     ll ans = 0;
//     for (int i = 1; i <= n; i++){
//         if(g[i][0] == 'R')dp[i][0] = dp[i - 1][0] + 1;
//         if(g[i][1] == 'R')dp[i][1] = dp[i - 1][1] + 1;
//         if(g[i][0] == 'R' && g[i][1] == 'R'){
//             dp[i][0] = max(dp[i][0], dp[i - 1][1] + 2);
//             dp[i][1] = max(dp[i][1], dp[i - 1][0] + 2);
//         }
//         ans = max({ans,dp[i][0],dp[i][1]});
//         //cout << g[i][0] << " " << g[i][1] << "\n";
//         //cout << i << " " << ans << "\n";
//     }
//     ans = max(0ll,ans-1);
//     cout << ans << "\n";
//     return 0;
// }