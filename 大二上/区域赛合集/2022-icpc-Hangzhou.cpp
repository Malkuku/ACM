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

/*C. No Bug No Game*/
/*2024.11.3 题解*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3010;
int dp[N][N][2];// 1取过部分
int n,k;
int w[15];
void solve(){
    memset(dp,-0x3f,sizeof dp);
    cin >> n >> k;
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++){
        int p;cin >> p;
        for(int j = 1; j <= p; j++){
            cin >> w[j];
        }

        for(int j = k-1;j >= 0; j--){
            dp[i][j][0] = dp[i-1][j][0];
            dp[i][j][1] = dp[i-1][j][1];

            if(j+p <= k){
                dp[i][j+p][0] = max(dp[i][j+p][0],dp[i-1][j][0]+w[p]);
                dp[i][j+p][1] = max(dp[i][j+p][1],dp[i-1][j][1]+w[p]);
            }
            //更新部分体积
            for(int q = 1; (q<p)&&(q+j<=k);q++){
                dp[i][j+q][1] = max(dp[i][j+q][1],dp[i-1][j][0]+w[q]);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n;i++){
        for(int j = 0; j <= k; j++){
            ans = max(ans,dp[i][j][0]);
        }
        ans = max(ans,dp[i][k][1]);
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;//cin >> t;
    for(int _  = 1; _ <= t; _++){
        solve();
    }
    return 0;
}

/*A. Modulo Ruins the Legend*/
/*2024.11.3 题解 */ //exgcd++(精)
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+10;
// int a[N];
// ll gcd(ll a,ll b){
//     return b ? gcd(b,a%b) : a;
// }
// //exgcd -- 求出ax+by = __gcd(a,b) 的特解x,y
// ll exgcd(ll a,ll b,ll& x,ll& y){
//     if(b == 0){x = 1;y = 0;return a;}
//     int gcd = exgcd(b,a%b,y,x);
//     y -= (a/b) * x;
//     return gcd;
// }
// void solve(){
//     int n,m;cin >> n >> m;
//     ll sum = 0;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//         sum += a[i];
//     }
//     ll gcd1 = gcd(n,1ll*(n+1)*n/2);
//     ll gcd2 = gcd(gcd1,m);
//     ll ans = sum % gcd2;
//     ll k,y1;
//     ll gcdd = exgcd(gcd1,m,k,y1);
//     k = (k*((ans-sum)/gcd2 % m) % m);
//     ll s,d;
//     ll w = exgcd(n,1ll*(n+1)*n/2,s,d);
//     s = ((s*k)%m+m)%m;
//     d = ((d*k)%m+m)%m; //这个才是k*gcd()下的解
//     cout << ans << "\n";
//     cout << s << " " << d << "\n";
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
