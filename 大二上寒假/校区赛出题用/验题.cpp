//A, C, F, G, H

// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void solve(){
// }
// int main(){
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*QED2413F  激戰！Roselia V.S. RAISE A SUILEN !!!!!*/
/*2025.2.18*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sum[1010][1010];
struct Node{
    ll a,b,c,d;
    ll s;
}node[1010];
ll f[1010][1010];


void solve(){

}
int main(){
    int t = 1;cin >> t;
    while(t--){
        solve();
    }
}

/*QED2413H  帮Mortis回复神经网络*/
/*2025.2.18*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// double a[110],w[110][110],v[110],b[110],c,h[110];
// void solve(){
//     int n,m;cin >> n >> m;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     for(int i = 0; i < m; i++){
//         for(int j = 0; j < n; j++){
//             cin >> w[i][j];
//         }cin >> b[i];
//     } 
//     for(int i = 0; i < m; i++) cin >> v[i];
//     cin >> c;
//     for(int i = 0; i < m; i++){
//         double tmp = 0;
//         for(int j = 0; j < n; j++){
//             tmp += w[i][j] * a[j];
//         }
//         h[i] = max(0.0,tmp + b[i]);
//     }
//     double tmp = 0;
//     for(int i = 0; i < m; i++){
//         tmp += v[i] * h[i];
//     }
//     cout << fixed << setprecision(6) <<  max(0.0,tmp + c) << "\n";
// }
// int main(){
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*QED2413C  聊天框战神*/
/*2025.2.18*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int dp[2010][2010]; //i结尾，j结尾相同
// void solve(){
//     int c1,c2,c3;cin >> c1 >> c2 >> c3; //改，插，删
//     string s1,s2;cin >> s1 >> s2;
//     memset(dp,0x3f,sizeof dp);
//     s1 = " " + s1;
//     s2 = " " + s2;
//     for(int i = 0; i < s2.size(); i++){
//         dp[0][i] = i;
//     }
//     for(int i = 0; i < s1.size(); i++){
//         dp[i][0] = i;
//     }
//     for(int i = 1; i < s1.size(); i++){
//         for(int j = 1; j < s2.size(); j++){
//             if(s1[i] == s2[j]){
//                 dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
//             }
//             else{
//                 dp[i][j] = min({
//                     dp[i][j],
//                     dp[i-1][j-1] + c1,
//                     dp[i][j-1] + c2,
//                     dp[i-1][j] + c3,
//                 });
//             }
//         }
//     }
//     cout << dp[s1.size()-1][s2.size()-1] << "\n";
// }
// int main(){
//     int t = 1;//cin >> t;
//     while(t--){
//         solve();
//     }
// }

/*QED2413A  ANonON0n0NO*/
/*2025.2.18*/
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e3 + 10;
// void solve(){
//     int n,m;cin >> n >> m;
//     string s1,s2;cin >> s1 >> s2;
//     int ans = 0,anss = 0;
//     int sum1[2] = {0},sum2[2] = {0};
//     for(int i = 0; i < s1.size(); i++){
//         if(s1[i] == 'N') sum1[0]++;
//         else if(s1[i] == 'n') sum1[1]++;
//         else if(s1[i] == 'O' || s1[i] == '0') ans += sum1[0] + sum1[1];
//         else if(s1[i] == 'o') ans += sum1[1];
//     }
//     for(int i = 0; i < s2.size(); i++){
//         if(s2[i] == 'N') sum2[0]++;
//         else if(s2[i] == 'n') sum2[1]++;
//         else if(s2[i] == 'O' || s2[i] == '0') anss += sum2[0] + sum2[1];
//         else if(s2[i] == 'o') anss += sum2[1];
//     }
//     if(anss == ans)cout << "YE5\n";
//     else cout << "N0\n";
// }
// int main(){
//     int t = 1;cin >> t;
//     while(t--){
//         solve();
//     }
// }
